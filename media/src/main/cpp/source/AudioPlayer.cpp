#include "AudioPlayer.h"

AudioPlayer::~AudioPlayer() {
}

void AudioPlayer::prepare(JNIEnv *env, jobject listener) {
    if (JNIEnvHelper::get()->attachEnv(env, JNIEnvHelper::MAIN)) {
        jclass clz = env->GetObjectClass(listener);
        jmethodID m_id = env->GetMethodID(clz, "onSucess", "()V");
        env->CallVoidMethod(listener, m_id);
    }
}

AudioPlayer::AudioPlayer() {
}
