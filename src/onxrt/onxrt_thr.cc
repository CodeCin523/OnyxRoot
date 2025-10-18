// instead of using different system, should I just go with the cpp interface?
#include <onxrt/onxrt_thr.hh>

#if __has_include(<pthread.h>)
    #include <pthread.h>
    #define THR_POSIX
#endif

#include <stdlib.h>


namespace onxrt {
struct THR_PoolHandler::ThWork {
    ThFunc func;
#ifdef THR_POSIX
    pthread_mutex_t mtx;
#endif
};

static THR_PoolHandler::ThWork *pWork = nullptr;
#ifdef THR_POSIX
static pthread_t *pThread = nullptr;
#endif

u32 THR_PoolHandler::s_workCount = 0;
u32 THR_PoolHandler::s_threadCount = 0;


static void *thr_routine(void *arg) {

    return nullptr;
}

THR_PoolHandler::ThWork *THR_PoolHandler::subscribe(const ThFunc _f) {
    if(_f == nullptr)
        return nullptr;
    
    u32 i = 0;
    for(; i < s_workCount; ++i) {
#ifdef THR_POSIX
        if(pWork[i].func == nullptr) continue;
        if(pthread_mutex_trylock(&pWork[i].mtx) != 0) continue;

        pWork[i].func = _f;
        pthread_mutex_unlock(&pWork[i].mtx);
        break;
#endif
    }

    return i == s_workCount? nullptr : &pWork[i];
}
bool THR_PoolHandler::release(const ThWork *_w) {
    if(_w == nullptr) return false;
    if(_w - pWork > s_workCount) return false;

    while(_w->func != nullptr);

    return true;
}


template<>
u32 tHandler<THR_PoolHandler>::s_handlerInstanceCount = 0;
template<>
void tHandler<THR_PoolHandler>::handlerInitialize() {
    // Calculate the sizes.
#ifdef THR_POSIX
    const size_t sizeThread = THR_PoolHandler::s_threadCount * sizeof(pthread_t);
    const size_t sizeWork = THR_PoolHandler::s_workCount * sizeof(THR_PoolHandler::ThWork);
#endif

    // Allocate the memory.
    void *temp = malloc(sizeThread + sizeWork);
    if(temp == nullptr)
        return; // DO SOMETHING MORE, A HOLE HANDLER FAILED BECAUSE OF MEMORY

    // Divide the allocated memory.
#ifdef THR_POSIX
    pThread = (pthread_t *)temp;
#endif
    pWork = (THR_PoolHandler::ThWork *)( (size_t)temp + sizeThread );

    // Start threads and works.
#ifdef THR_POSIX
    for(int i = 0; i < THR_PoolHandler::s_threadCount; ++i) {
        if(pthread_create(&pThread[i], nullptr, thr_routine, nullptr) != 0)
            return; // DO SOMETING MORE, A HOLE HANDLER FAILED
    }
    for(int i = 0; i < THR_PoolHandler::s_workCount;++i) {
        if(pthread_mutex_init(&pWork[i].mtx, 0) != 0)
            return; // DO SOMETHING MORE, A HOLE HANDLER FAILED
    }
#endif
}
template<>
void tHandler<THR_PoolHandler>::handlerTerminate() {
    if(pThread == nullptr) return;

    pThread = nullptr;
    pWork = nullptr;
}

THR_PoolHandler::THR_PoolHandler() {
    if(s_handlerInstanceCount++ == 0) {
        s_threadCount = 4;
        s_workCount = 64;
        handlerInitialize();
    }
}
THR_PoolHandler::THR_PoolHandler(u32 threadCount, u32 workCount) {
    if(s_handlerInstanceCount++ == 0) {
        s_threadCount = threadCount;
        s_workCount = workCount;
        handlerInitialize();
    }
}
THR_PoolHandler::~THR_PoolHandler() {
    if(--s_handlerInstanceCount == 0)
        handlerTerminate();
}
};