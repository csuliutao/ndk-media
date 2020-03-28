//
// Created by Administrator on 2020/3/27.
//

#include "JNIEnvHelper.h"

bool JNIEnvHelper::attachEnv(JNIEnv *env, int threaType) {
    if (threaType != 0) {
        if (globalVm->AttachCurrentThread(&env, NULL) != JNI_OK) {
            return false;
        }
    } else {
        *env = *globalEnv;
    }
    return true;
}

void JNIEnvHelper::detachEnv() {
    globalVm->DetachCurrentThread();
}

void JNIEnvHelper::init(JavaVM *javaVm, JNIEnv *env) {
    helper->globalVm = globalVm;
    helper->globalEnv = env;
}

JNIEnvHelper *JNIEnvHelper::get() {
    if (helper == NULL) {
        helper = new JNIEnvHelper();
    }
    return helper;
}
