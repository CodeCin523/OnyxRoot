// instead of using different system, should I just go with the cpp interface?
#include <onxrt/onxrt_thr.hh>

#if __has_include(<pthread.h>)
#include <pthread.h>
#define onxrt_pTHR
#endif

namespace onxrt {
struct THR_PoolHandler::ThWork {
    ThFunc func;
#ifdef onxrt_pTHR
    
#endif
};

// static ThWork *subscribe(const ThFunc _f);
// static bool release(const ThWork *_w);

THR_PoolHandler::ThWork *THR_PoolHandler::subscribe(const ThFunc _f) {

}
bool THR_PoolHandler::release(const ThWork *_w) {

}


template<>
u32 tHandler<THR_PoolHandler>::s_handlerInstanceCount = 0;
template<>
void tHandler<THR_PoolHandler>::handlerInitialize() {

}
template<>
void tHandler<THR_PoolHandler>::handlerTerminate() {

}

THR_PoolHandler::THR_PoolHandler() {
    if(s_handlerInstanceCount == 0)
        handlerInitialize();
    ++s_handlerInstanceCount;
}
THR_PoolHandler::~THR_PoolHandler() {
    --s_handlerInstanceCount;
    if(s_handlerInstanceCount == 0)
        handlerTerminate();
}
};