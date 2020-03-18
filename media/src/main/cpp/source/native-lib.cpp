#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_csu_tliu_ndk_media_Test_get(JNIEnv *env, jclass type) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}