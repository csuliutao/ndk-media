#include <jni.h>
#include <string>
#include "AudioPlayer.h"
#include "Factory.h"
#include <NativeLog.h>

extern "C" {
#include <unistd.h>
}
/**
 * 默认情况下,ndk加载动态库，对应一个c/cpp文件，库名字即为文件名字；系统也会依据此查找JNI_OnLoad；或者相对签名的native方法（名字也要符合）
 * 1、被动态库主文件（假设库名相同的文件）引用的文件，才会正确识别头文件，否则爆红
 * 2、没有返回值，编译并不会报错
 */

Factory<int> factory(10);
pthread_t produce,consume;

void *consumeP(void *data) {
    int index = 1000;
    sleep(20);
    while (index > 0) {
        sleep(1);
        factory.consume();
        index--;
    }
    pthread_exit(&consume);
}

void *produceP(void *data) {
    int index = 1000;
    while (index > 0) {
        sleep(2);
        factory.produce(4);
        index--;
    }
    pthread_exit(&produce);
}
JNIEXPORT void JNICALL prepareAudio(JNIEnv *env, jobject obj, jlong optr, jobject listener) {
    AudioPlayer* player = (AudioPlayer* ) optr;
    player->prepare(env, listener);
}

JNIEXPORT jlong JNICALL initAudio(JNIEnv *env, jobject obj) {
    pthread_create(&produce, NULL, produceP, NULL);
    pthread_create(&consume, NULL, consumeP, NULL);
    AudioPlayer player;
    return (jlong) &player;
}

JNINativeMethod audioPlayer[] = {
        {"native_prepaer", "(JLcsu/tliu/ndk/media/OnPrepaerListener;)V",(void *) prepareAudio},
        {"native_init", "()J", (void*) initAudio}
};


void regesiterMethod(JNIEnv *env) {
    env->RegisterNatives(env->FindClass("csu/tliu/ndk/media/FfmpegAudioPlayer"), audioPlayer,
                         sizeof(audioPlayer) / sizeof(audioPlayer[0]));
};

JNIEXPORT int JNICALL JNI_OnLoad(JavaVM * javaVM, void* reserved) {
    JNIEnv* localEnv;
    if (javaVM->GetEnv((void **) &localEnv, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_FALSE;
    }
    regesiterMethod(localEnv);
    JNIEnvHelper::get()->init(javaVM, localEnv);
    return JNI_VERSION_1_6;
}