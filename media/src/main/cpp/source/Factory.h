//
// Created by Administrator on 2020/3/28.
//

#ifndef NDK_MEDIA_FACTORY_H
#define NDK_MEDIA_FACTORY_H

extern "C" {
#include <pthread.h>
};

#include <deque>
#include "NativeLog.h"

using namespace std;
const static char* TAG = "consume-produce";

template<typename T>
class Factory {
private:
    deque<T> data;
    int maxNum = 10;
    pthread_mutex_t p_mutex;
    pthread_cond_t p_cond;
public:
    void produce(T item) {
        pthread_mutex_lock(&p_mutex);
        if (data.size() >= maxNum) {
            LOG_DEBUG(TAG, "%s","product is full!");
            pthread_cond_wait(&p_cond, &p_mutex);
        }
        LOG_DEBUG(TAG, "%s %d","produce and size =" , data.size());
        data.push_back(item);
        pthread_cond_signal(&p_cond);
        pthread_mutex_unlock(&p_mutex);
    };
    T consume() {
        pthread_mutex_lock(&p_mutex);
        if (data.size() <= 0) {
            LOG_DEBUG(TAG, "%s","product is empty!");
            pthread_cond_wait(&p_cond, &p_mutex);
        }
        LOG_DEBUG(TAG, "%s %d","consume left num =" , data.size());
        T result = data.front();
        data.pop_front();
        pthread_cond_signal(&p_cond);
        pthread_mutex_unlock(&p_mutex);
        return result;
    };
    void clear() {
        data.clear();
    };

    Factory(int maxNum) {
        this->maxNum = maxNum;
        pthread_mutex_init(&p_mutex, NULL);
        pthread_cond_init(&p_cond, NULL);
    }
    ~Factory() {
        pthread_cond_destroy(&p_cond);
        pthread_mutex_destroy(&p_mutex);
    };
};

#endif //NDK_MEDIA_FACTORY_H
