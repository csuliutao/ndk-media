//
// Created by Administrator on 2020/3/28.
//

#ifndef NDK_MEDIA_NATIVELOG_H
#define NDK_MEDIA_NATIVELOG_H
#include <android/log.h>

#define LOG_DEBUG(TAG, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__);
#define LOG_INFO(TAG, ...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__);
#define LOG_WARN(TAG, ...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__);
#define LOG_ERRO(TAG, ...) __android_log_print(ANDROID_LOG_ERRO, TAG, __VA_ARGS__);
#endif //NDK_MEDIA_NATIVELOG_H
