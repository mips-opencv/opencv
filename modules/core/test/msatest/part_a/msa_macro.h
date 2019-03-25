#ifndef __MSA_WYG_H
#define __MSA_WYG_H

#include <stdint.h>
#include "msa.h"

/*define 64 bits vector types */
typedef signed char v8i8 __attribute__ ((vector_size(8), aligned(8)));
typedef signed char v8i8_b __attribute__ ((vector_size(8), aligned(1)));
typedef unsigned char v8u8 __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned char v8u8_b __attribute__ ((vector_size(8), aligned(1)));
typedef short v4i16 __attribute__ ((vector_size(8), aligned(8)));
typedef short v4i16_h __attribute__ ((vector_size(8), aligned(2)));
typedef unsigned short v4u16 __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned short v4u16_h __attribute__ ((vector_size(8), aligned(2)));
typedef int v2i32 __attribute__ ((vector_size(8), aligned(8)));
typedef int v2i32_w __attribute__ ((vector_size(8), aligned(4)));
typedef unsigned int v2u32 __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned int v2u32_w __attribute__ ((vector_size(8), aligned(4)));
typedef long long v1i64 __attribute__ ((vector_size(8), aligned(8)));
//typedef long long v1i64_d __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned long long v1u64 __attribute__ ((vector_size(8), aligned(8)));
//typedef unsigned long long v1u64_d __attribute__ ((vector_size(8), aligned(8)));
typedef float v2f32 __attribute__ ((vector_size(8), aligned(8)));
typedef float v2f32_w __attribute__ ((vector_size(8), aligned(4)));
typedef double v1f64 __attribute__ ((vector_size(8), aligned(8)));
//typedef double v1f64_d __attribute__ ((vector_size(8), aligned(8)));

#ifdef _MIPSEB
#define LANE_IMM0_1(x)  (0b1 - (x & 0b1))
#define LANE_IMM0_3(x)  (0b11 - (x & 0b11))
#define LANE_IMM0_7(x)  (0b111 - (x & 0b111))
#define LANE_IMM0_15(x) (0b1111 - (x & 0b1111))
#else
#define LANE_IMM0_1(x)  (x & 0b1)
#define LANE_IMM0_3(x)  (x & 0b11)
#define LANE_IMM0_7(x)  (x & 0b111)
#define LANE_IMM0_15(x) (x & 0b1111)
#endif

#if WYG
__extension__ extern __inline float
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_getq_lane_f32 (v4f32 __a, const int __b)
{
	return __a[LANE_IMM0_3(__b)];
}

#define msa_getq_lane_f32(__a, __b) ((float)__a[LANE_IMM0_3(__b)])

__extension__ extern __inline double
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_getq_lane_f64 (v2f64 __a, const int __b)
{
	return __a[LANE_IMM0_1(__b)];
}

__extension__ extern __inline uint8_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_lane_u8 (v8u8 __a, const int __b)
{
  return __a[LANE_IMM0_7(__b)];
}

__extension__ extern __inline int8_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_lane_s8 (v8i8 __a, const int __b)
{
  return __a[LANE_IMM0_7(__b)];
}

__extension__ extern __inline uint16_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_lane_u16 (v4u16 __a, const int __b)
{
	return __a[LANE_IMM0_3(__b)];
}

__extension__ extern __inline int16_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_lane_s16 (v4i16 __a, const int __b)
{
	return __a[LANE_IMM0_3(__b)];
}

__extension__ extern __inline uint32_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_lane_u32 (v2u32 __a, const int __b)
{
	return __a[LANE_IMM0_1(__b)];
}

__extension__ extern __inline int32_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_lane_s32 (v2i32 __a, const int __b)
{
	return __a[LANE_IMM0_1(__b)];
}

__extension__ extern __inline float
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_lane_f32 (v2f32 __a, const int __b)
{
	return __a[LANE_IMM0_1(__b)];
}
#else
#define msa_getq_lane_f32(__a, __b) ((float)__a[LANE_IMM0_3(__b)])
#define msa_getq_lane_f64(__a, __b) ((double)__a[LANE_IMM0_1(__b)])
#define msa_get_lane_u8(__a, __b) ((uint8_t)__a[LANE_IMM0_7(__b)])
#define msa_get_lane_s8(__a, __b) ((int8_t)__a[LANE_IMM0_7(__b)])
#define msa_get_lane_u16(__a, __b) ((uint16_t)__a[LANE_IMM0_3(__b)])
#define msa_get_lane_s16(__a, __b) ((int16_t)__a[LANE_IMM0_3(__b)])
#define msa_get_lane_u32(__a, __b) ((uint32_t)__a[LANE_IMM0_1(__b)])
#define msa_get_lane_s32(__a, __b) ((int32_t)__a[LANE_IMM0_1(__b)])
#define msa_get_lane_f32(__a, __b) ((float)__a[LANE_IMM0_3(__b)])
#endif

/* combine */
#define __COMBINE_64_64(__TYPE, a, b) \
  v2u64 c = {((v1u64)a)[0], ((v1u64)b)[0]};  \
  return (__TYPE)(c);
  
__extension__ extern __inline v16i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_s8 (v8i8 __a, v8i8 __b)
{
  __COMBINE_64_64(v16i8, __a, __b);
}

__extension__ extern __inline v8i16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_s16 (v4i16 __a, v4i16 __b)
{
  __COMBINE_64_64(v8i16, __a, __b);
}

__extension__ extern __inline v4i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_s32 (v2i32 __a, v2i32 __b)
{
  __COMBINE_64_64(v4i32, __a, __b);
}

__extension__ extern __inline v2i64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_s64 (v1i64 __a, v1i64 __b)
{
  __COMBINE_64_64(v2i64, __a, __b);
}

__extension__ extern __inline v4f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_f32 (v2f32 __a, v2f32 __b)
{
  __COMBINE_64_64(v4f32, __a, __b);
}

__extension__ extern __inline v16u8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_u8 (v8u8 __a, v8u8 __b)
{
  __COMBINE_64_64(v16u8, __a, __b);
}

__extension__ extern __inline v8u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_u16 (v4u16 __a, v4u16 __b)
{
  __COMBINE_64_64(v8u16, __a, __b);
}

__extension__ extern __inline v4u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_u32 (v2u32 __a, v2u32 __b)
{
  __COMBINE_64_64(v4u32, __a, __b);
}

__extension__ extern __inline v2u64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_u64 (v1u64 __a, v1u64 __b)
{
  __COMBINE_64_64(v2u64, __a, __b);
}

__extension__ extern __inline v2f64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_combine_f64 (v1f64 __a, v1f64 __b)
{
  __COMBINE_64_64(v2f64, __a, __b);
}

/* get_low, get_high */
#define __GET_LOW(__TYPE, a) \
  v1u64 lo = (v1u64)(__builtin_msa_copy_u_d((v2i64)a, 0));  \
  return (__TYPE)(lo);
  
#define __GET_HIGH(__TYPE, a) \
  v1u64 hi = (v1u64)(__builtin_msa_copy_u_d((v2i64)a, 1));  \
  return (__TYPE)(hi);

__extension__ extern __inline v8i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_s8 (v16i8 __a)
{
  __GET_LOW (v8i8, __a);
}

__extension__ extern __inline v4i16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_s16 (v8i16 __a)
{
  __GET_LOW (v4i16, __a);
}

__extension__ extern __inline v2i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_s32 (v4i32 __a)
{
  __GET_LOW (v2i32, __a);
}

__extension__ extern __inline v1i64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_s64 (v2i64 __a)
{
  __GET_LOW (v1i64, __a);
}

__extension__ extern __inline v8u8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_u8 (v16u8 __a)
{
  __GET_LOW (v8u8, __a);
}

__extension__ extern __inline v4u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_u16 (v8u16 __a)
{
  __GET_LOW (v4u16, __a);
}

__extension__ extern __inline v2u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_u32 (v4u32 __a)
{
  __GET_LOW (v2u32, __a);
}

__extension__ extern __inline v1u64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_u64 (v2u64 __a)
{
  __GET_LOW (v1u64, __a);
}

__extension__ extern __inline v2f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_f32 (v4f32 __a)
{
  __GET_LOW (v2f32, __a);
}

__extension__ extern __inline v1f64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_low_f64 (v2f64 __a)
{
  __GET_LOW (v1f64, __a);
}

__extension__ extern __inline v8i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_s8 (v16i8 __a)
{
  __GET_HIGH (v8i8, __a);
}

__extension__ extern __inline v4i16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_s16 (v8i16 __a)
{
  __GET_HIGH (v4i16, __a);
}

__extension__ extern __inline v2i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_s32 (v4i32 __a)
{
  __GET_HIGH (v2i32, __a);
}

__extension__ extern __inline v1i64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_s64 (v2i64 __a)
{
  __GET_HIGH (v1i64, __a);
}

__extension__ extern __inline v8u8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_u8 (v16u8 __a)
{
  __GET_HIGH (v8u8, __a);
}

__extension__ extern __inline v4u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_u16 (v8u16 __a)
{
  __GET_HIGH (v4u16, __a);
}

__extension__ extern __inline v2u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_u32 (v4u32 __a)
{
  __GET_HIGH (v2u32, __a);
}

__extension__ extern __inline v1u64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_u64 (v2u64 __a)
{
  __GET_HIGH (v1u64, __a);
}

__extension__ extern __inline v2f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_f32 (v4f32 __a)
{
  __GET_HIGH (v2f32, __a);
}

__extension__ extern __inline v1f64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_get_high_f64 (v2f64 __a)
{
  __GET_HIGH (v1f64, __a);
}

/* ri = ai * b[lane] */
__extension__ extern __inline v4f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mulq_lane_f32 (v4f32 __a, v2f32 __b, const int __lane)
{
  return __a * msa_get_lane_f32 (__b, __lane);
}

/* ri = ai + bi * c[lane] */
__extension__ extern __inline v4f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mlaq_lane_f32 (v4f32 __a, v4f32 __b, v2f32 __c, const int __lane)
{
  return (__a + (__b * msa_get_lane_f32 (__c, __lane)));
}

__extension__ extern __inline uint16_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_sum_u16(v8u16 __a)
{
    return (__a[0] + __a[1] + __a[2] + __a[3] + __a[4] + __a[5] + __a[6] + __a[7]);
}

__extension__ extern __inline int16_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_sum_s16(v8i16 __a)
{
    return (__a[0] + __a[1] + __a[2] + __a[3]  + __a[4] + __a[5] + __a[6] + __a[7]);
}

__extension__ extern __inline uint32_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_sum_u32(v4u32 __a)
{
    return (__a[0] + __a[1] + __a[2] + __a[3]);
}

__extension__ extern __inline int32_t
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_sum_s32(v4i32 __a)
{
    return (__a[0] + __a[1] + __a[2] + __a[3]);
}

__extension__ extern __inline float
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_sum_f32(v4f32 __a)
{
    return (__a[0] + __a[1] + __a[2] + __a[3]);
}

__extension__ extern __inline v8u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_paddlq_u8 (v16u8 __a)
{
#if 0
  v8u16 result = {(uint16_t)(__a[0] + __a[1]), (uint16_t)(__a[2] + __a[3]), (uint16_t)(__a[4] + __a[5]), (uint16_t)(__a[6] + __a[7]),
                  (uint16_t)(__a[8] + __a[9]), (uint16_t)(__a[10] + __a[11]), (uint16_t)(__a[12] + __a[13]), (uint16_t)(__a[14] + __a[15])};
  return result;
#else
  v16u8 b = (v16u8)__builtin_msa_fill_b(1);
  return __builtin_msa_dotp_u_h(__a, b);
#endif
}

__extension__ extern __inline v4u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_paddlq_u16 (v8u16 __a)
{
  v8u16 b = (v8u16)__builtin_msa_fill_h(1);
  return __builtin_msa_dotp_u_w(__a, b);
}

__extension__ extern __inline v2u64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_paddlq_u32 (v4u32 __a)
{
  v2u64 result = {(uint64_t)(__a[0] + __a[1]), (uint16_t)(__a[2] + __a[3])};
  return result;
}

#define V8U8_2_V8U16(x) {(uint16_t)x[0], (uint16_t)x[1], (uint16_t)x[2], (uint16_t)x[3], \
                          (uint16_t)x[4], (uint16_t)x[5], (uint16_t)x[6], (uint16_t)x[7]}
#define V8I8_2_V8I16(x) {(int16_t)x[0], (int16_t)x[1], (int16_t)x[2], (int16_t)x[3], \
                          (int16_t)x[4], (int16_t)x[5], (int16_t)x[6], (int16_t)x[7]}
#define V4U16_2_V4U32(x) {(uint32_t)x[0], (uint32_t)x[1], (uint32_t)x[2], (uint32_t)x[3]}
#define V4I16_2_V4I32(x) {(int32_t)x[0], (int32_t)x[1], (int32_t)x[2], (int32_t)x[3]}
#define V2U32_2_V2U64(x) {(uint64_t)x[0], (uint64_t)x[1]}

__extension__ extern __inline v8u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mull_u8 (v8u8 __a, v8u8 __b)
{
#if 0
  v8u16 result;
  asm volatile ("mulv.h %w[result].8h, %w[a].8b, %w[b].8b"
  //asm volatile ("mulv.b %w[result], %w[__a], %w[__b]"
           : [result]"=f"(result)
           : [__a]"f"(__a), [__b]"f"(__b)
           : /* No clobbers */);
  return result;
#else
  return (v8u16)__builtin_msa_mulv_h((v8i16)V8U8_2_V8U16(__a), (v8i16)V8U8_2_V8U16(__b));
#endif
}

__extension__ extern __inline v8i16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mull_s8 (v8i8 __a, v8i8 __b)
{
  return __builtin_msa_mulv_h((v8i16)V8I8_2_V8I16(__a), (v8i16)V8I8_2_V8I16(__b));
}

__extension__ extern __inline v4u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mull_u16 (v4u16 __a, v4u16 __b)
{
  return (v4u32)__builtin_msa_mulv_w((v4i32)V4U16_2_V4U32(__a), (v4i32)V4U16_2_V4U32(__b));
}

__extension__ extern __inline v4i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mull_s16 (v4i16 __a, v4i16 __b)
{
  return __builtin_msa_mulv_w((v4i32)V4I16_2_V4I32(__a), (v4i32)V4I16_2_V4I32(__b));
}

__extension__ extern __inline v2u64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mull_u32 (v2u32 __a, v2u32 __b)
{
  return (v2u64)__builtin_msa_mulv_d((v2i64)V2U32_2_V2U64(__a), (v2i64)V2U32_2_V2U64(__b));
}

/* bitwise and: __builtin_msa_and_v */
#define MSA_ANDV_EXPAND(suffix, type) \
__extension__ extern __inline type         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_andq_##suffix (type __a, type __b) \
{ \
  return (type)__builtin_msa_and_v((v16u8)__a, (v16u8)__b); \
}
MSA_ANDV_EXPAND(u8, v16u8)
MSA_ANDV_EXPAND(s8, v16i8)
MSA_ANDV_EXPAND(u16, v8u16)
MSA_ANDV_EXPAND(s16, v8i16)
MSA_ANDV_EXPAND(u32, v4u32)
MSA_ANDV_EXPAND(s32, v4i32)
MSA_ANDV_EXPAND(u64, v2u64)
MSA_ANDV_EXPAND(s64, v2i64)

/* bitwise or: __builtin_msa_or_v */
#define MSA_ORV_EXPAND(suffix, type) \
__extension__ extern __inline type         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_orrq_##suffix (type __a, type __b) \
{ \
  return (type)__builtin_msa_or_v((v16u8)__a, (v16u8)__b); \
}
MSA_ORV_EXPAND(u8, v16u8)
MSA_ORV_EXPAND(s8, v16i8)
MSA_ORV_EXPAND(u16, v8u16)
MSA_ORV_EXPAND(s16, v8i16)
MSA_ORV_EXPAND(u32, v4u32)
MSA_ORV_EXPAND(s32, v4i32)
MSA_ORV_EXPAND(u64, v2u64)
MSA_ORV_EXPAND(s64, v2i64)

/* bitwise xor: __builtin_msa_xor_v */
#define MSA_XORV_EXPAND(suffix, type) \
__extension__ extern __inline type         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_eorq_##suffix (type __a, type __b) \
{ \
  return (type)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b); \
}
MSA_XORV_EXPAND(u8, v16u8)
MSA_XORV_EXPAND(s8, v16i8)
MSA_XORV_EXPAND(u16, v8u16)
MSA_XORV_EXPAND(s16, v8i16)
MSA_XORV_EXPAND(u32, v4u32)
MSA_XORV_EXPAND(s32, v4i32)
MSA_XORV_EXPAND(u64, v2u64)
MSA_XORV_EXPAND(s64, v2i64)

/* bitwise not: v16u8 __builtin_msa_xori_b (v16u8, 0xff) */
#define MSA_BITWISENOT_EXPAND(suffix, type) \
__extension__ extern __inline type         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_mvnq_##suffix (type __a) \
{ \
  return (type)__builtin_msa_xori_b((v16u8)__a, 0xff); \
}
MSA_BITWISENOT_EXPAND(u8, v16u8)
MSA_BITWISENOT_EXPAND(s8, v16i8)
MSA_BITWISENOT_EXPAND(u16, v8u16)
MSA_BITWISENOT_EXPAND(s16, v8i16)
MSA_BITWISENOT_EXPAND(u32, v4u32)
MSA_BITWISENOT_EXPAND(s32, v4i32)
MSA_BITWISENOT_EXPAND(u64, v2u64)
MSA_BITWISENOT_EXPAND(s64, v2i64)

/* compare equal: vcgt -> ri = ai == bi ? 1...1:0...0 */
#define MSA_CEQQ_IMPL(suffix1, suffix2, rettype, casttype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_ceqq_##suffix1 (type __a, type __b) \
{ \
  return (rettype)__builtin_msa_##suffix2((casttype)__a, (casttype)__b); \
}
MSA_CEQQ_IMPL(u8, ceq_b, v16u8, v16i8, v16u8)
MSA_CEQQ_IMPL(s8, ceq_b, v16u8, v16i8, v16i8)
MSA_CEQQ_IMPL(u16, ceq_h, v8u16, v8i16, v8u16)
MSA_CEQQ_IMPL(s16, ceq_h, v8u16, v8i16, v8i16)
MSA_CEQQ_IMPL(u32, ceq_w, v4u32, v4i32, v4u32)
MSA_CEQQ_IMPL(s32, ceq_w, v4u32, v4i32, v4i32)
MSA_CEQQ_IMPL(f32, fceq_w, v4u32, v4f32, v4f32)
MSA_CEQQ_IMPL(u64, ceq_d, v2u64, v2i64, v2u64)
MSA_CEQQ_IMPL(s64, ceq_d, v2u64, v2i64, v2i64)
MSA_CEQQ_IMPL(f64, fceq_d, v2u64, v2f64, v2f64)

/* Compare less-than: vclt -> ri = ai < bi ? 1...1:0...0 */
#define MSA_CLTQ_IMPL(suffix1, suffix2, rettype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_cltq_##suffix1 (type __a, type __b) \
{ \
  return (rettype)__builtin_msa_##suffix2(__a, __b); \
}
MSA_CLTQ_IMPL(u8, clt_u_b, v16u8, v16u8)
MSA_CLTQ_IMPL(s8, clt_s_b, v16u8, v16i8)
MSA_CLTQ_IMPL(u16, clt_u_h, v8u16, v8u16)
MSA_CLTQ_IMPL(s16, clt_s_h, v8u16, v8i16)
MSA_CLTQ_IMPL(u32, clt_u_w, v4u32, v4u32)
MSA_CLTQ_IMPL(s32, clt_s_w, v4u32, v4i32)
MSA_CLTQ_IMPL(f32, fclt_w, v4u32, v4f32)
MSA_CLTQ_IMPL(u64, clt_u_d, v2u64, v2u64)
MSA_CLTQ_IMPL(s64, clt_s_d, v2u64, v2i64)
MSA_CLTQ_IMPL(f64, fclt_d, v2u64, v2f64)

/* compare greater-than: vcgt -> ri = ai > bi ? 1...1:0...0 */
#define MSA_CGTQ_IMPL(suffix1, suffix2, rettype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_cgtq_##suffix1 (type __a, type __b) \
{ \
  return (rettype)__builtin_msa_##suffix2(__b, __a); \
}
MSA_CGTQ_IMPL(u8, clt_u_b, v16u8, v16u8)
MSA_CGTQ_IMPL(s8, clt_s_b, v16u8, v16i8)
MSA_CGTQ_IMPL(u16, clt_u_h, v8u16, v8u16)
MSA_CGTQ_IMPL(s16, clt_s_h, v8u16, v8i16)
MSA_CGTQ_IMPL(u32, clt_u_w, v4u32, v4u32)
MSA_CGTQ_IMPL(s32, clt_s_w, v4u32, v4i32)
MSA_CGTQ_IMPL(f32, fclt_w, v4u32, v4f32)
MSA_CGTQ_IMPL(u64, clt_u_d, v2u64, v2u64)
MSA_CGTQ_IMPL(s64, clt_s_d, v2u64, v2i64)
MSA_CGTQ_IMPL(f64, fclt_d, v2u64, v2f64)

/* compare less-equal: cge -> ri = ai >= bi ? 1...1:0...0 */
#define MSA_CLEQ_IMPL(suffix1, suffix2, rettype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_cleq_##suffix1 (type __a, type __b) \
{ \
  return (rettype)__builtin_msa_##suffix2(__a, __b); \
}
MSA_CLEQ_IMPL(u8, cle_u_b, v16u8, v16u8)
MSA_CLEQ_IMPL(s8, cle_s_b, v16u8, v16i8)
MSA_CLEQ_IMPL(u16, cle_u_h, v8u16, v8u16)
MSA_CLEQ_IMPL(s16, cle_s_h, v8u16, v8i16)
MSA_CLEQ_IMPL(u32, cle_u_w, v4u32, v4u32)
MSA_CLEQ_IMPL(s32, cle_s_w, v4u32, v4i32)
MSA_CLEQ_IMPL(f32, fcle_w, v4u32, v4f32)
MSA_CLEQ_IMPL(u64, cle_u_d, v2u64, v2u64)
MSA_CLEQ_IMPL(s64, cle_s_d, v2u64, v2i64)
MSA_CLEQ_IMPL(f64, fcle_d, v2u64, v2f64)

/* compare greater-equal: cge -> ri = ai >= bi ? 1...1:0...0 */
#define MSA_CGEQ_IMPL(suffix1, suffix2, rettype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_cgeq_##suffix1 (type __a, type __b) \
{ \
  return (rettype)__builtin_msa_##suffix2(__b, __a); \
}
MSA_CGEQ_IMPL(u8, cle_u_b, v16u8, v16u8)
MSA_CGEQ_IMPL(s8, cle_s_b, v16u8, v16i8)
MSA_CGEQ_IMPL(u16, cle_u_h, v8u16, v8u16)
MSA_CGEQ_IMPL(s16, cle_s_h, v8u16, v8i16)
MSA_CGEQ_IMPL(u32, cle_u_w, v4u32, v4u32)
MSA_CGEQ_IMPL(s32, cle_s_w, v4u32, v4i32)
MSA_CGEQ_IMPL(f32, fcle_w, v4u32, v4f32)
MSA_CGEQ_IMPL(u64, cle_u_d, v2u64, v2u64)
MSA_CGEQ_IMPL(s64, cle_s_d, v2u64, v2i64)
MSA_CGEQ_IMPL(f64, fcle_d, v2u64, v2f64)

/* Shift Right Logical: shl -> ri = ai << bi;  */
#define MSA_SHLQ_IMPL(suffix1, suffix2, rettype, casttype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_shlq_##suffix1 (type __a, casttype __b) \
{ \
  return (rettype)__builtin_msa_##suffix2((casttype)__a, (casttype)__b); \
}
MSA_SHLQ_IMPL(u8, sll_b, v16u8, v16i8, v16u8)
MSA_SHLQ_IMPL(s8, sll_b, v16i8, v16i8, v16i8)
MSA_SHLQ_IMPL(u16, sll_h, v8u16, v8i16, v8u16)
MSA_SHLQ_IMPL(s16, sll_h, v8i16, v8i16, v8i16)
MSA_SHLQ_IMPL(u32, sll_w, v4u32, v4i32, v4u32)
MSA_SHLQ_IMPL(s32, sll_w, v4i32, v4i32, v4i32)
MSA_SHLQ_IMPL(u64, sll_d, v2u64, v2i64, v2u64)
MSA_SHLQ_IMPL(s64, sll_d, v2i64, v2i64, v2i64)

/* Immediate Shift Right Logical: shl -> ri = ai << imm;  */
#if 0
#define MSA_SHLQ_N_IMPL(suffix1, suffix2, rettype, casttype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_shlq_n_##suffix1 (type __a, const int __imm) \
{ \
  return (rettype)__builtin_msa_##suffix2((casttype)__a, __imm); \
}
MSA_SHLQ_N_IMPL(u8, slli_b, v16u8, v16i8, v16u8)
MSA_SHLQ_N_IMPL(s8, slli_b, v16i8, v16i8, v16i8)
MSA_SHLQ_N_IMPL(u16, slli_h, v8u16, v8i16, v8u16)
MSA_SHLQ_N_IMPL(s16, slli_h, v8i16, v8i16, v8i16)
MSA_SHLQ_N_IMPL(u32, slli_w, v4u32, v4i32, v4u32)
MSA_SHLQ_N_IMPL(s32, slli_w, v4i32, v4i32, v4i32)
MSA_SHLQ_N_IMPL(u64, slli_d, v2u64, v2i64, v2u64)
MSA_SHLQ_N_IMPL(s64, slli_d, v2i64, v2i64, v2i64)
#else
#define msa_shlq_n_u8(__a, __imm) ((v16u8)__builtin_msa_slli_b((v16i8)__a, __imm))
#define msa_shlq_n_s8(__a, __imm) ((v16i8)__builtin_msa_slli_b((v16i8)__a, __imm))
#define msa_shlq_n_u16(__a, __imm) ((v8u16)__builtin_msa_slli_h((v8i16)__a, __imm))
#define msa_shlq_n_s16(__a, __imm) ((v8i16)__builtin_msa_slli_h((v8i16)__a, __imm))
#define msa_shlq_n_u32(__a, __imm) ((v4u32)__builtin_msa_slli_w((v4i32)__a, __imm))
#define msa_shlq_n_s32(__a, __imm) ((v4i32)__builtin_msa_slli_w((v4i32)__a, __imm))
#define msa_shlq_n_u64(__a, __imm) ((v2u64)__builtin_msa_slli_d((v2i64)__a, __imm))
#define msa_shlq_n_s64(__a, __imm) ((v2i64)__builtin_msa_slli_d((v2i64)__a, __imm))
#endif

/* shift right logical: shl -> ri = ai >> bi;  */
#define MSA_SHRQ_IMPL(suffix1, suffix2, rettype, casttype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_shrq_##suffix1 (type __a, casttype __b) \
{ \
  return (rettype)__builtin_msa_##suffix2((casttype)__a, (casttype)__b); \
}
MSA_SHRQ_IMPL(u8, srl_b, v16u8, v16i8, v16u8)
MSA_SHRQ_IMPL(s8, srl_b, v16i8, v16i8, v16i8)
MSA_SHRQ_IMPL(u16, srl_h, v8u16, v8i16, v8u16)
MSA_SHRQ_IMPL(s16, srl_h, v8i16, v8i16, v8i16)
MSA_SHRQ_IMPL(u32, srl_w, v4u32, v4i32, v4u32)
MSA_SHRQ_IMPL(s32, srl_w, v4i32, v4i32, v4i32)
MSA_SHRQ_IMPL(u64, srl_d, v2u64, v2i64, v2u64)
MSA_SHRQ_IMPL(s64, srl_d, v2i64, v2i64, v2i64)

/* Immediate Shift Right Logical: shl -> ri = ai >> imm;  */
#if 0
#define MSA_SHRQ_N_IMPL(suffix1, suffix2, rettype, casttype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_shrq_n_##suffix1 (type __a, const int __imm) \
{ \
  return (rettype)__builtin_msa_##suffix2((casttype)__a, __imm); \
}
MSA_SHRQ_N_IMPL(u8, srli_b, v16u8, v16i8, v16u8)
MSA_SHRQ_N_IMPL(s8, srli_b, v16i8, v16i8, v16i8)
MSA_SHRQ_N_IMPL(u16, srli_h, v8u16, v8i16, v8u16)
MSA_SHRQ_N_IMPL(s16, srli_h, v8i16, v8i16, v8i16)
MSA_SHRQ_N_IMPL(u32, srli_w, v4u32, v4i32, v4u32)
MSA_SHRQ_N_IMPL(s32, srli_w, v4i32, v4i32, v4i32)
MSA_SHRQ_N_IMPL(u64, srli_d, v2u64, v2i64, v2u64)
MSA_SHRQ_N_IMPL(s64, srli_d, v2i64, v2i64, v2i64)
#else
#if 1
#define msa_shrq_n_u8(__a, __imm) ((v16u8)__builtin_msa_srli_b((v16i8)__a, __imm))
#define msa_shrq_n_s8(__a, __imm) ((v16i8)__builtin_msa_srli_b((v16i8)__a, __imm))
#define msa_shrq_n_u16(__a, __imm) ((v8u16)__builtin_msa_srli_h((v8i16)__a, __imm))
#define msa_shrq_n_s16(__a, __imm) ((v8i16)__builtin_msa_srli_h((v8i16)__a, __imm))
#define msa_shrq_n_u32(__a, __imm) ((v4u32)__builtin_msa_srli_w((v4i32)__a, __imm))
#define msa_shrq_n_s32(__a, __imm) ((v4i32)__builtin_msa_srli_w((v4i32)__a, __imm))
#define msa_shrq_n_u64(__a, __imm) ((v2u64)__builtin_msa_srli_d((v2i64)__a, __imm))
#define msa_shrq_n_s64(__a, __imm) ((v2i64)__builtin_msa_srli_d((v2i64)__a, __imm))
#else
#define msa_shrq_n_u8    __builtin_msa_srli_b
#define msa_shrq_n_s8    __builtin_msa_srli_b
#define msa_shrq_n_u16   __builtin_msa_srli_h
#define msa_shrq_n_s16   __builtin_msa_srli_h
#define msa_shrq_n_u32   __builtin_msa_srli_w
#define msa_shrq_n_s32   __builtin_msa_srli_w
#define msa_shrq_n_u64   __builtin_msa_srli_d
#define msa_shrq_n_s64   __builtin_msa_srli_d
#endif
#endif

/* Immediate Shift Right Logical Rounded: shl -> ri = ai >> (rounded)imm;  */
#if 0
#define MSA_RSHRQ_N_IMPL(suffix1, suffix2, rettype, casttype, type) \
__extension__ extern __inline rettype         \
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__)) \
msa_rshrq_n_##suffix1 (type __a, const int __imm) \
{ \
  return (rettype)__builtin_msa_##suffix2((casttype)__a, __imm); \
}
MSA_RSHRQ_N_IMPL(u8, srlri_b, v16u8, v16i8, v16u8)
MSA_RSHRQ_N_IMPL(s8, srlri_b, v16i8, v16i8, v16i8)
MSA_RSHRQ_N_IMPL(u16, srlri_h, v8u16, v8i16, v8u16)
MSA_RSHRQ_N_IMPL(s16, srlri_h, v8i16, v8i16, v8i16)
MSA_RSHRQ_N_IMPL(u32, srlri_w, v4u32, v4i32, v4u32)
MSA_RSHRQ_N_IMPL(s32, srlri_w, v4i32, v4i32, v4i32)
MSA_RSHRQ_N_IMPL(u64, srlri_d, v2u64, v2i64, v2u64)
MSA_RSHRQ_N_IMPL(s64, srlri_d, v2i64, v2i64, v2i64)
#else
#define msa_rshrq_n_u8(__a, __imm) ((v16u8)__builtin_msa_srlri_b((v16i8)__a, __imm))
#define msa_rshrq_n_s8(__a, __imm) ((v16i8)__builtin_msa_srlri_b((v16i8)__a, __imm))
#define msa_rshrq_n_u16(__a, __imm) ((v8u16)__builtin_msa_srlri_h((v8i16)__a, __imm))
#define msa_rshrq_n_s16(__a, __imm) ((v8i16)__builtin_msa_srlri_h((v8i16)__a, __imm))
#define msa_rshrq_n_u32(__a, __imm) ((v4u32)__builtin_msa_srlri_w((v4i32)__a, __imm))
#define msa_rshrq_n_s32(__a, __imm) ((v4i32)__builtin_msa_srlri_w((v4i32)__a, __imm))
#define msa_rshrq_n_u64(__a, __imm) ((v2u64)__builtin_msa_srlri_d((v2i64)__a, __imm))
#define msa_rshrq_n_s64(__a, __imm) ((v2i64)__builtin_msa_srlri_d((v2i64)__a, __imm))
#endif

/* rename the msa builtin func to unify the name style for intrin_msa.hpp */
#if 1
#define msa_getq_lane_u8(a, imm0_15)      __builtin_msa_copy_u_b((v16i8)a, imm0_15)
#define msa_getq_lane_s8      __builtin_msa_copy_s_b
#define msa_getq_lane_u16(a, imm0_7)     __builtin_msa_copy_u_h((v8i16)a, imm0_7)
#define msa_getq_lane_s16     __builtin_msa_copy_s_h
#define msa_getq_lane_u32(a, imm0_3)     __builtin_msa_copy_u_w((v4i32)a, imm0_3)
#define msa_getq_lane_s32     __builtin_msa_copy_s_w
#define msa_getq_lane_u64(a, imm0_1)     __builtin_msa_copy_u_d((v2i64)a, imm0_1)
#define msa_getq_lane_s64     __builtin_msa_copy_s_d
#endif
#define msa_qaddq_u8          __builtin_msa_adds_u_b
#define msa_qaddq_s8          __builtin_msa_adds_s_b
#define msa_qaddq_u16         __builtin_msa_adds_u_h
#define msa_qaddq_s16         __builtin_msa_adds_s_h
#define msa_qaddq_u32         __builtin_msa_adds_u_w
#define msa_qaddq_s32         __builtin_msa_adds_s_w
#define msa_qaddq_u64         __builtin_msa_adds_u_d
#define msa_qaddq_s64         __builtin_msa_adds_s_d
#define msa_addq_u8(a, b)     ((v16u8)__builtin_msa_addv_b((v16i8)a, (v16i8)b))
#define msa_addq_s8           __builtin_msa_addv_b
#define msa_addq_u16(a, b)    ((v8u16)__builtin_msa_addv_h((v8i16)a, (v8i16)b))
#define msa_addq_s16          __builtin_msa_addv_h
#define msa_addq_u32(a, b)    ((v4u32)__builtin_msa_addv_w((v4i32)a, (v4i32)b))
#define msa_addq_s32          __builtin_msa_addv_w
#define msa_addq_f32          __builtin_msa_fadd_w
#define msa_addq_u64(a, b)    ((v2u64)__builtin_msa_addv_d((v2i64)a, (v2i64)b))
#define msa_addq_s64          __builtin_msa_addv_d
#define msa_addq_f64          __builtin_msa_fadd_d
#define msa_qsubq_u8          __builtin_msa_subs_u_b
#define msa_qsubq_s8          __builtin_msa_subs_s_b
#define msa_qsubq_u16         __builtin_msa_subs_u_h
#define msa_qsubq_s16         __builtin_msa_subs_s_h
#define msa_subq_u8(a, b)     ((v16u8)__builtin_msa_subv_b((v16i8)a, (v16i8)b))
#define msa_subq_s8           __builtin_msa_subv_b
#define msa_subq_u16(a, b)    ((v8u16)__builtin_msa_subv_h((v8i16)a, (v8i16)b))
#define msa_subq_s16          __builtin_msa_subv_h
#define msa_subq_u32(a, b)    ((v4u32)__builtin_msa_subv_w((v4i32)a, (v4i32)b))
#define msa_subq_s32          __builtin_msa_subv_w
#define msa_subq_f32          __builtin_msa_fsub_w
#define msa_subq_u64(a, b)    ((v2u64)__builtin_msa_subv_d((v2i64)a, (v2i64)b))
#define msa_subq_s64          __builtin_msa_subv_d
#define msa_subq_f64          __builtin_msa_fsub_d
#define msa_mulq_u8(a, b)     ((v16u8)__builtin_msa_mulv_b((v16i8)a, (v16i8)b))
#define msa_mulq_s8           __builtin_msa_mulv_b
#define msa_mulq_u16(a, b)    ((v8u16)__builtin_msa_mulv_h((v8i16)a, (v8i16)b))
#define msa_mulq_s16          __builtin_msa_mulv_h
#define msa_mulq_u32(a, b)    ((v4u32)__builtin_msa_mulv_w((v4i32)a, (v4i32)b))
#define msa_mulq_s32          __builtin_msa_mulv_w
#define msa_mulq_f32          __builtin_msa_fmul_w
#define msa_mulq_f64          __builtin_msa_fmul_d
#define msa_divq_f32          __builtin_msa_fdiv_w
#define msa_divq_f64          __builtin_msa_fdiv_d
#define msa_dotp_s_h          __builtin_msa_dotp_s_h
#define msa_dotp_s_w          __builtin_msa_dotp_s_w
#define msa_dotp_s_d          __builtin_msa_dotp_s_d
#define msa_dotp_u_h          __builtin_msa_dotp_u_h
#define msa_dotp_u_w          __builtin_msa_dotp_u_w
#define msa_dotp_u_d          __builtin_msa_dotp_u_d

/* absq, qabsq (r = |a|;) */


#endif
