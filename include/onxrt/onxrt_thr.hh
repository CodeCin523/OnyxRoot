#ifndef __ONXRT_THR_HH__
#define __ONXRT_THR_HH__

#include "onxrt_def.hh"
namespace onxrt {
    class THR_PoolHandler : public tHandler<THR_PoolHandler> {
    public:
        using ThId = i32;
        using ThFunc = void (*)();

        static ThId subscribe(const ThFunc _f);
        static bool release(const ThId _i);

        THR_PoolHandler();
        ~THR_PoolHandler();
    };
}

#endif