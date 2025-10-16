// instead of using different system, should I just go with the cpp interface?
#include <onxrt/onxrt_thr.hh>

#ifdef onxrt_OS_WIN
#elifdef onxrt_OS_UNIX
#include <pthread.h>
#endif

namespace onxrt {
struct THR_PoolHandler::ThWork {
#ifdef onxrt_OS_WIN
#elifdef onxrt_OS_UNIX
    pthread_mutex_t         mtx;
#endif
    THR_PoolHandler::ThFunc func;
    THR_PoolHandler::ThId   id;
};

THR_PoolHandler::ThWork *THR_PoolHandler::s_pWork = nullptr;
u32 THR_PoolHandler::s_workCount = 0;
u32 THR_PoolHandler::s_threadCount = 0;

#ifdef onxrt_OS_WIN
#elifdef onxrt_OS_UNIX
static pthread_t *THR_PoolHandler_pThread = nullptr;
#endif


THR_PoolHandler::ThId THR_PoolHandler::subscribe(const ThFunc _f) {

}
bool THR_PoolHandler::release(const ThId _i) {

}


template<>
u32 tHandler<THR_PoolHandler>::s_handInstanceCount = 0;
template<>
void tHandler<THR_PoolHandler>::handInitialize() {

}
template<>
void tHandler<THR_PoolHandler>::handTerminate() {

}

THR_PoolHandler::THR_PoolHandler() {
    if(s_handInstanceCount == 0)
        handInitialize();
    ++s_handInstanceCount;
}
THR_PoolHandler::~THR_PoolHandler() {
    --s_handInstanceCount;
    if(s_handInstanceCount == 0)
        handTerminate();
}
};