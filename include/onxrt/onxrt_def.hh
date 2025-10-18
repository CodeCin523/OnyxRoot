#ifndef __ONXRT_DEF_HH__
#define __ONXRT_DEF_HH__

#include <cstdint>
#include <limits>
#include <stddef.h>

#ifdef _WIN64
#define onxrt_OS_WIN
#elifdef __unix__
#define onxrt_OS_UNIX
#endif

namespace onxrt {
// TYPES
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

    template <typename handler>
    class tHandler {
    protected:
        static u32 s_handlerInstanceCount;
        
        static void handlerInitialize();
        static void handlerTerminate();

    public:
        // static handler &getHandler();
    };

// CONSTANTS
    constexpr i8  i8_MIN  = std::numeric_limits<i8>::min();
    constexpr i8  i8_MAX  = std::numeric_limits<i8>::max();
    constexpr u8  u8_MIN  = std::numeric_limits<u8>::min();
    constexpr u8  u8_MAX  = std::numeric_limits<u8>::max();

    constexpr i16 i16_MIN = std::numeric_limits<i16>::min();
    constexpr i16 i16_MAX = std::numeric_limits<i16>::max();
    constexpr u16 u16_MIN = std::numeric_limits<u16>::min();
    constexpr u16 u16_MAX = std::numeric_limits<u16>::max();

    constexpr i32 i32_MIN = std::numeric_limits<i32>::min();
    constexpr i32 i32_MAX = std::numeric_limits<i32>::max();
    constexpr u32 u32_MIN = std::numeric_limits<u32>::min();
    constexpr u32 u32_MAX = std::numeric_limits<u32>::max();

    constexpr i64 i64_MIN = std::numeric_limits<i64>::min();
    constexpr i64 i64_MAX = std::numeric_limits<i64>::max();
    constexpr u64 u64_MIN = std::numeric_limits<u64>::min();
    constexpr u64 u64_MAX = std::numeric_limits<u64>::max();
};

#endif