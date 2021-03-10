#include "MpwSemaphore.h"

namespace framework {

Semaphore::Semaphore()
        : mutex(std::make_shared<std::mutex>()) {

}

SemaphoreLock Semaphore::lock() {
    return SemaphoreLock(*mutex);
}

void Semaphore::acquire() {
    mutex->lock();
}

void Semaphore::release() {
    mutex->unlock();
}

bool Semaphore::isLocked() {
    if (mutex->try_lock()) {
        // could aquire lock, so it isn't locked -> unlock it again to reconstruct previous state
        mutex->unlock();
        return false;
    }
    return true;
}

}
