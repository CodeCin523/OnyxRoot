#ifndef __ONXRT_MEM_HH__
#define __ONXRT_MEM_HH__

#include "onxrt_def.hh"

namespace onxrt {
    enum class MEM_Allocators : fast_u8 {
        ECS = 0,

        count = 1
    };

    template <MEM_Allocators MEM_Allocator>
    class MEM_Alloc {
    public:
        using Size = u8;

    private:

    public:
        static constexpr Size byteToSize(size_t b) {
#ifdef __GNUC__
            return b == 0? 0 : 63 - __builtin_clzll(b);
#else
            Size s = 0;

            if (b & 0xFFFFFFFF00000000ULL) { b >>= 32; s += 32; }
            if (b & 0xFFFF0000ULL) { b >>= 16; s += 16; }
            if (b & 0xFF00U) { b >>= 8; s += 8; }
            if (b & 0xF0U) { b >>= 4; s += 4; }
            if (b & 0x0CU) { b >>= 2; s += 2; }
            if (b & 0x02U) { b += 1; }
            
            return s;
#endif
        }
        static constexpr size_t sizeToByte(Size s) {
            return 1 << s;
        }

        static void *alloc(size_t b) {
            return alloc(byteToSize(b));
        }
        static void *alloc(Size s) {

        }
        static void free(void *alloc) {

        }

        // void optimize() {
        //     
        // }
    };
};

#endif