//
// Created by Administrator on 2020/3/28.
//

#ifndef NDK_MEDIA_FFMEGDECODER_H
#define NDK_MEDIA_FFMEGDECODER_H
extern "C" {
#include "../include/libavcodec/avcodec.h"
};

class FfmegDecoder {
public:
    FfmegDecoder();
    ~FfmegDecoder();
};


#endif //NDK_MEDIA_FFMEGDECODER_H
