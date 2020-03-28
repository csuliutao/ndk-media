#ifndef NDK_MEDIA_AUDIOPLAYER_H
#define NDK_MEDIA_AUDIOPLAYER_H

#include <jni.h>
#include "JNIEnvHelper.h"

class AudioPlayer {
public:
public:
    AudioPlayer();
    ~AudioPlayer();
    void prepare(jobject listener);
};


#endif
