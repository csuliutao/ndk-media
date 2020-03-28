//
// Created by Administrator on 2020/3/27.
//

#ifndef NDK_MEDIA_JNIENVHELPER_H
#define NDK_MEDIA_JNIENVHELPER_H

#include <jni.h>
class JNIEnvHelper {
private:
    JavaVM* globalVm = NULL;
    JNIEnv* globalEnv = NULL;
    JNIEnvHelper() {};
public:
    static const int MAIN = 0;
    static const int OTHER = 1;

    static JNIEnvHelper* get();
    void init(JavaVM* javaVm, JNIEnv *env);
    bool attachEnv(JNIEnv* env, int threaType);
    void detachEnv();
};

static JNIEnvHelper* helper = NULL;
#endif //NDK_MEDIA_JNIENVHELPER_H
