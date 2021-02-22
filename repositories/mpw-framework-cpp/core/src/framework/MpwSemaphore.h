#ifndef DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SEMAPHORE_H
#define DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SEMAPHORE_H

#include <mutex>
#include <memory>

namespace framework {

/// \brief RAII based lock object
class SemaphoreLock
{
private:

    std::mutex& mutex;

public:
    SemaphoreLock(std::mutex& mutex)
        : mutex(mutex)
    {
        mutex.lock();
    }
    ~SemaphoreLock()
    {
        mutex.unlock();
    }
};

/// \brief Semaphore implementation which reuses same underlying mutex when copying the object.
class Semaphore {

public:

    Semaphore();

    SemaphoreLock lock();

    void acquire();
    void release();

    bool isLocked();

private:

    std::shared_ptr<std::mutex> mutex;
};

}

#endif //DE_UNISTUTTGART_ISTE_SQA_MPW_FRAMEWORK__CPP_SEMAPHORE_H
