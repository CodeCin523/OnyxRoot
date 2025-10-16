#ifndef __ONXRT_THR_HH__
#define __ONXRT_THR_HH__

#include "onxrt_def.hh"
namespace onxrt {
    class THR_PoolHandler : public tHandler<THR_PoolHandler> {
        friend class tHandler;
    public:
        using ThId = i32;
        using ThFunc = void (*)(ThId);
        struct ThWork;

        static ThId subscribe(const ThFunc _f);
        static bool release(const ThId _i);

        THR_PoolHandler();
        THR_PoolHandler(u32 threadCount, u32 workCount);
        ~THR_PoolHandler();

    protected:
        static ThWork *s_pWork;
        static u32 s_workCount;
        static u32 s_threadCount;
    };
}

#endif