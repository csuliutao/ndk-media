#include "AudioPlayer.h"

AudioPlayer::~AudioPlayer() {
}

void AudioPlayer::prepare(jobject listener) {
    JNIEnv* temp;
    if (JNIEnvHelper::get()->attachEnv(&temp, JNIEnvHelper::MAIN)) {
        jclass clz = temp->GetObjectClass(listener);
        jmethodID m_id = temp->GetMethodID(clz, "onSucess", "()V");
        temp->CallVoidMethod(listener, m_id);
    }
}

AudioPlayer::AudioPlayer() {
}
