#ifndef __ONXRT_DEF_HH__
#define __ONXRT_DEF_HH__

#include <cstdint>
#include <stddef.h>

namespace onxrt {
    using i8        = int8_t;       // 8
    using u8        = uint8_t;
    using i16       = int16_t;      // 16
    using u16       = uint16_t;
    using i32       = int32_t;      // 32
    using u32       = uint32_t;
    using i64       = int64_t;      // 64
    using u64       = uint64_t;

    using fast_i8   = int_fast8_t;  // 8
    using fast_u8   = uint_fast8_t; 
    using fast_i16  = int_fast16_t; // 16
    using fast_u16  = uint_fast16_t;
    using fast_i32  = int_fast32_t; // 32
    using fast_u32  = uint_fast32_t;
    using fast_i64  = int_fast64_t; // 64
    using fast_u64  = uint_fast64_t;
};

#endif