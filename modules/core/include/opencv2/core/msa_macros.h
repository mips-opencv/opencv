#ifndef OPENCV_CORE_HAL_MSA_MACROS_H
#define OPENCV_CORE_HAL_MSA_MACROS_H

#include "msa.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* define 64 bits vector types */
typedef signed char v8i8 __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned char v8u8 __attribute__ ((vector_size(8), aligned(8)));
typedef short v4i16 __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned short v4u16 __attribute__ ((vector_size(8), aligned(8)));
typedef int v2i32 __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned int v2u32 __attribute__ ((vector_size(8), aligned(8)));
typedef long long v1i64 __attribute__ ((vector_size(8), aligned(8)));
typedef unsigned long long v1u64 __attribute__ ((vector_size(8), aligned(8)));
typedef float v2f32 __attribute__ ((vector_size(8), aligned(8)));
typedef double v1f64 __attribute__ ((vector_size(8), aligned(8)));


/* ld1: load values from the memory and return a doubleword vector */
#define msa_ld1_f32(__a) ((v2f32) ((v1f64){*((double*)__a)}))
#define msa_ld1_f64(__a) ((v1f64) {*((double*)__a)})
#define msa_ld1_s8(__a) ((v8i8) ((v1i64){*((int64_t*)__a)}))
#define msa_ld1_s16(__a) ((v4i16) ((v1i64){*((int64_t*)__a)}))
#define msa_ld1_s32(__a) ((v2i32) ((v1i64){*((int64_t*)__a)}))
#define msa_ld1_s64(__a) ((v1i64) {*((int64_t*)__a)})
#define msa_ld1_u8(__a) ((v8u8) ((v1u64){*((uint64_t*)__a)}))
#define msa_ld1_u16(__a) ((v4u16) ((v1u64){*((uint64_t*)__a)}))
#define msa_ld1_u32(__a) ((v2u32) ((v1u64){*((uint64_t*)__a)}))
#define msa_ld1_u64(__a) ((v1u64) {*((uint64_t*)__a)})

/* ld1q: load values from the memory and return a quadword vector */
#define msa_ld1q_f32(__a) ((v4f32){((float*)__a)[0],((float*)__a)[1],((float*)__a)[2],((float*)__a)[3]})
#define msa_ld1q_f64(__a) ((v2f64){((double*)__a)[0], ((double*)__a)[1]})
#define msa_ld1q_s8(__a) ((v16i8) __msa_ld_b(__a,0))
#define msa_ld1q_s16(__a) ((v8i16) __msa_ld_h(__a,0))
#define msa_ld1q_s32(__a) ((v4i32) __msa_ld_w(__a,0))
#define msa_ld1q_s64(__a) ((v2i64) __msa_ld_d(__a,0))
#define msa_ld1q_u8(__a) ((v16u8) __msa_ld_b(__a,0))
#define msa_ld1q_u16(__a) ((v8u16) __msa_ld_h (__a, 0))
#define msa_ld1q_u32(__a) ((v4u32) __msa_ld_w(__a,0))
#define msa_ld1q_u64(__a) ((v2u64) __msa_ld_d(__a,0))

/* duplicate elements for 64-bit doubleword vectors */
#define msa_dup_n_f32(__a) ((v2f32) {__a, __a})
#define msa_dup_n_f64(__a) ((v1f64) {__a})
#define msa_dup_n_s8(__a) ((v8i8) {__a, __a, __a, __a, __a, __a, __a, __a})
#define msa_dup_n_s16(__a) ((v4i16) {__a, __a, __a, __a})
#define msa_dup_n_s32(__a) ((v2i32) {__a, __a})
#define msa_dup_n_s64(__a) ((v1i64) {__a})
#define msa_dup_n_u8(__a) ((v8u8) {__a, __a, __a, __a, __a, __a, __a, __a})
#define msa_dup_n_u16(__a) ((v4u16) {__a, __a, __a, __a})
#define msa_dup_n_u32(__a) ((v2u32) {__a, __a})
#define msa_dup_n_u64(__a) ((v1u64) {__a})

/* duplicate elements for 128-bit quadword vectors */
#define msa_dupq_lane_s8(__a, __b) ((v16i8)__msa_splat_b (__a, __b))
#define msa_dupq_lane_s16(__a, __b) ((v8i16)__msa_splat_h (__a, __b))
#define msa_dupq_lane_s32(__a,__b) ((v4i32)__msa_splat_w (__a, __b))
#define msa_dupq_lane_u8(__a, __b) ((v16u8)__msa_splat_b ((v16i8) __a, __b))
#define msa_dupq_lane_u16(__a, __b) ((v8u16)__msa_splat_h ((v8i16) __a, __b))
#define msa_dupq_lane_u32(__a, __b) ((v4u32)__msa_splat_w ((v4i32) __a, __b))
#define msa_dupq_lane_s64(__a, __b) ((v2i64) __msa_splat_d (__a, __b))
#define msa_dupq_lane_u64(__a, __b) ((v2u64)__msa_splat_d ((v2i64) __a, __b))
#define msa_dupq_n_s8(__a) ((v16i8)__msa_fill_b ((int32_t) __a))
#define msa_dupq_n_s16(__a) ((v8i16)__msa_fill_h ((int32_t) __a))
#define msa_dupq_n_s32(__a) ((v4i32)__msa_fill_w ((int32_t) __a))
#define msa_dupq_n_u8(__a) ((v16u8)__msa_fill_b ((int32_t) __a))
#define msa_dupq_n_u16(__a) ((v8u16)__msa_fill_h ((int32_t) __a))
#define msa_dupq_n_u32(__a) ((v4u32)__msa_fill_w ((int32_t) __a))
#define msa_dupq_n_s64(__a) ((v2i64)__msa_fill_d ((int64_t) __a))
#define msa_dupq_n_u64(__a) ((v2u64)__msa_fill_d ((int64_t) __a))
#define msa_dupq_n_f32(__a) ((v4f32) {__a, __a, __a, __a})
#define msa_dupq_n_f64(__a) ((v2f64) {__a, __a})

/* store vector elments to memory address */
__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_s8 (int8_t * __a, v8i8 __b)
{
  uint8_t i = 0;
  for(i=0; i<8; i++)
  	__a[i] = __b[i];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_s16 (int16_t * __a, v4i16 __b)
{
  uint8_t i = 0;
  for(i=0; i<4; i++)
  	__a[i] = __b[i];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_s32 (int32_t * __a, v2i32 __b)
{
  __a[0] = __b[0];
  __a[1] = __b[1];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_s64 (int64_t * __a, v1i64 __b)
{
  *__a = __b[0];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_f32 (float * __a, v2f32 __b)
{
  __a[0] = __b[0];
  __a[1] = __b[1];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_u8 (uint8_t * __a, v8u8 __b)
{
  uint8_t i = 0;
  for(i=0; i<8; i++)
    __a[i] = __b[i];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_u16 (uint16_t * __a, v4u16 __b)
{
  uint8_t i = 0;
  for(i=0; i<4; i++)
    __a[i] = __b[i];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_u32 (uint32_t * __a, v2u32 __b)
{
  __a[0] = __b[0];
  __a[1] = __b[1];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_u64 (uint64_t * __a, v1u64 __b)
{
  *__a = __b[0];
}

__extension__ extern __inline void
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_f64 (double *__a, v1f64 __b)
{
  *__a = __b[0];
}

#define msa_st1q_s8(__a, __b) (__msa_st_b (__b, __a, 0))
#define msa_st1q_s16(__a, __b) (__msa_st_h (__b, __a, 0))
#define msa_st1q_s32(__a, __b) (__msa_st_w (__b, __a, 0))
#define msa_st1q_s64(__a, __b) (__msa_st_d (__b, __a, 0))

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_f32 (float * __a, v4f32 __b)
{
  uint8_t i = 0;
  for(i=0; i<4; i++)
    __a[i] = __b[i];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_u8 (uint8_t * __a, v16u8 __b)
{
  __msa_st_b ((v16i8)__b, __a, 0);
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_u16 (uint16_t * __a, v8u16 __b)
{
  __msa_st_h ((v8i16)__b, __a, 0);
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_u32 (uint32_t * __a, v4u32 __b)
{
  __msa_st_w ((v4i32)__b, __a, 0);
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_u64 (uint64_t * __a, v2u64 __b)
{
  __msa_st_d ((v2i64)__b, __a, 0);
}

__extension__ extern __inline void
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_f64 (double *a, v2f64 b)
{
  a[0] = b[0];
  a[1] = b[1];
}


__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_s8 (int8_t * __a, v8i8 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_s16 (int16_t * __a, v4i16 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_s32 (int32_t * __a, v2i32 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_f32 (float * __a, v2f32 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_u8 (uint8_t * __a, v8i8 __b, const int __c)
{
 *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_u16 (uint16_t * __a, v4u16 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_u32 (uint32_t * __a, v2u32 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_s64 (int64_t * __a, v1i64 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1_lane_u64 (uint64_t * __a, v1u64 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_s8 (int8_t * __a, v16i8 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_s16 (int16_t * __a, v8i16 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_s32 (int32_t * __a, v4i32 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_f32 (float * __a, v4f32 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_u8 (uint8_t * __a, v16u8 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_u16 (uint16_t * __a, v8u16 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_u32 (uint32_t * __a, v4u32 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_s64 (int64_t * __a, v2i64 __b, const int __c)
{
  *__a = __b[__c];
}

__extension__ extern __inline void
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_st1q_lane_u64 (uint64_t * __a, v2u64 __b, const int __c)
{
  *__a = __b[__c];
}

/* move */
__extension__ extern __inline v8i8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movn_s16 (v8i16 __a)
{
  return (v8i8){(int8_t)__msa_copy_s_h(__a,0),
                (int8_t)__msa_copy_s_h(__a,1),
                (int8_t)__msa_copy_s_h(__a,2),
                (int8_t)__msa_copy_s_h(__a,3),
                (int8_t)__msa_copy_s_h(__a,4),
                (int8_t)__msa_copy_s_h(__a,5),
                (int8_t)__msa_copy_s_h(__a,6),
                (int8_t)__msa_copy_s_h(__a,7)};
}

__extension__ extern __inline v4i16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movn_s32 (v4i32 __a)
{
  return (v4i16){(int16_t)__msa_copy_s_w(__a,0),
                 (int16_t)__msa_copy_s_w(__a,1),
                 (int16_t)__msa_copy_s_w(__a,2),
                 (int16_t)__msa_copy_s_w(__a,3)};
}

__extension__ extern __inline v2i32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movn_s64 (v2i64 __a)
{
  return (v2i32){(int32_t)__msa_copy_s_d(__a,0),
                 (int32_t)__msa_copy_s_d(__a,1)};
}

__extension__ extern __inline v8u8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movn_u16 (v8u16 __a)
{
  return (v8u8){(uint8_t)__msa_copy_u_h((v8i16)__a,0),
                (uint8_t)__msa_copy_u_h((v8i16)__a,1),
                (uint8_t)__msa_copy_u_h((v8i16)__a,2),
                (uint8_t)__msa_copy_u_h((v8i16)__a,3),
                (uint8_t)__msa_copy_u_h((v8i16)__a,4),
                (uint8_t)__msa_copy_u_h((v8i16)__a,5),
                (uint8_t)__msa_copy_u_h((v8i16)__a,6),
                (uint8_t)__msa_copy_u_h((v8i16)__a,7)};
}

__extension__ extern __inline v4u16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movn_u32 (v4u32 __a)
{
  return (v4u16){(uint16_t)__msa_copy_u_w((v4i32)__a,0),
                 (uint16_t)__msa_copy_u_w((v4i32)__a,1),
                 (uint16_t)__msa_copy_u_w((v4i32)__a,2),
                 (uint16_t)__msa_copy_u_w((v4i32)__a,3)};
}

__extension__ extern __inline v2u32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movn_u64 (v2u64 __a)
{
  return (v2u32){(uint32_t)__msa_copy_u_d((v2i64)__a,0),
                 (uint32_t)__msa_copy_u_d((v2i64)__a,1)};
}

__extension__ extern __inline v8i8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovn_s16 (v8i16 __a)
{
  v8i16 __b = __msa_sat_s_h(__a,7);
  return (v8i8){(int8_t)__msa_copy_s_h(__b,0),
                (int8_t)__msa_copy_s_h(__b,1),
                (int8_t)__msa_copy_s_h(__b,2),
                (int8_t)__msa_copy_s_h(__b,3),
                (int8_t)__msa_copy_s_h(__b,4),
                (int8_t)__msa_copy_s_h(__b,5),
                (int8_t)__msa_copy_s_h(__b,6),
                (int8_t)__msa_copy_s_h(__b,7)};
}

__extension__ extern __inline v4i16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovn_s32 (v4i32 __a)
{
  v4i32 __b = __msa_sat_s_w(__a,15);
  return (v4i16){(int16_t)__msa_copy_s_w(__b,0),
                 (int16_t)__msa_copy_s_w(__b,1),
                 (int16_t)__msa_copy_s_w(__b,2),
                 (int16_t)__msa_copy_s_w(__b,3)};
}

__extension__ extern __inline v2i32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovn_s64 (v2i64 __a)
{
  v2i64 __b = __msa_sat_s_d(__a,31);
  return (v2i32){(int32_t)__msa_copy_s_d(__b,0),
                 (int32_t)__msa_copy_s_d(__b,1)};
}

__extension__ extern __inline v8u8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovn_u16 (v8u16 __a)
{
  v8u16 __b = __msa_sat_u_h(__a,7);
  return (v8u8){(uint8_t)__msa_copy_u_h((v8i16)__b,0),
                (uint8_t)__msa_copy_u_h((v8i16)__b,1),
                (uint8_t)__msa_copy_u_h((v8i16)__b,2),
                (uint8_t)__msa_copy_u_h((v8i16)__b,3),
                (uint8_t)__msa_copy_u_h((v8i16)__b,4),
                (uint8_t)__msa_copy_u_h((v8i16)__b,5),
                (uint8_t)__msa_copy_u_h((v8i16)__b,6),
                (uint8_t)__msa_copy_u_h((v8i16)__b,7)};
}

__extension__ extern __inline v4u16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovn_u32 (v4u32 __a)
{
  v4u32 __b = __msa_sat_u_w(__a,15);
  return (v4u16){(uint16_t)__msa_copy_u_w((v4i32)__b,0),
                 (uint16_t)__msa_copy_u_w((v4i32)__b,1),
                 (uint16_t)__msa_copy_u_w((v4i32)__b,2),
                 (uint16_t)__msa_copy_u_w((v4i32)__b,3)};
}

__extension__ extern __inline v2u32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovn_u64 (v2u64 __a)
{
  v2u64 __b = __msa_sat_u_d(__a,31);
  return (v2u32){(uint32_t)__msa_copy_u_d((v2i64)__b ,0),
                 (uint32_t)__msa_copy_u_d((v2i64)__b ,1)};
}

__extension__ extern __inline v8u8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovun_s16 (v8i16 __a)
{
  v8u16 vec_t,vec_d;

  vec_t = (v8u16) __msa_max_s_h(__msa_fill_h(0), __a);
  vec_d = __msa_sat_u_h(vec_t, 7);
  return (v8u8){(uint8_t)__msa_copy_u_h((v8i16)vec_d, 0),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 1),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 2),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 3),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 4),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 5),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 6),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 7)};
}

__extension__ extern __inline v4u16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovun_s32 (v4i32 __a)
{
  v4u32 vec_t,vec_d;

  vec_t = (v4u32) __msa_max_s_w(__msa_fill_w(0), __a);
  vec_d = __msa_sat_u_w(vec_t, 15);
  return (v4u16){(uint16_t)__msa_copy_u_w((v4i32)vec_d, 0),
                 (uint16_t)__msa_copy_u_w((v4i32)vec_d, 1),
                 (uint16_t)__msa_copy_u_w((v4i32)vec_d, 2),
                 (uint16_t)__msa_copy_u_w((v4i32)vec_d, 3)};
}

__extension__ extern __inline v2u32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_qmovun_s64 (v2i64 __a)
{
  v2u64 vec_t,vec_d;
  vec_t = (v2u64) __msa_max_s_d(__msa_fill_d(0), __a);
  vec_d = __msa_sat_u_d(vec_t, 31);
  return (v2u32){(uint32_t)__msa_copy_u_d((v2i64)vec_d, 0),
                 (uint32_t)__msa_copy_u_d((v2i64)vec_d, 1)};
}

__extension__ extern __inline v8i16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movl_s8 (v8i8 __a)
{
  return (v8i16) {(int16_t)__a[0],(int16_t)__a[1],
                  (int16_t)__a[2],(int16_t)__a[3],
                  (int16_t)__a[4],(int16_t)__a[5],
                  (int16_t)__a[6],(int16_t)__a[7]};
}

__extension__ extern __inline v4i32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movl_s16 (v4i16 __a)
{
  return (v4i32) {(int32_t)__a[0],(int32_t)__a[1],
                  (int32_t)__a[2],(int32_t)__a[3]};
}

__extension__ extern __inline v2i64
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movl_s32 (v2i32 __a)
{
  return (v2i64){(int64_t)__a[0],(int64_t)__a[1]};
}

__extension__ extern __inline v8u16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movl_u8 (v8u8 __a)
{
  return (v8u16) {(uint16_t)__a[0],(uint16_t)__a[1],
                  (uint16_t)__a[2],(uint16_t)__a[3],
                  (uint16_t)__a[4],(uint16_t)__a[5],
                  (uint16_t)__a[6],(uint16_t)__a[7]};
}

__extension__ extern __inline v4u32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movl_u16 (v4u16 __a)
{
  return (v4u32) {(uint32_t)__a[0],(uint32_t)__a[1],
                  (uint32_t)__a[2],(uint32_t)__a[3]};
}

__extension__ extern __inline v2u64
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_movl_u32 (v2u32 __a)
{
  return (v2u64) {(uint64_t)__a[0],(uint64_t)__a[1]};
}

/* create a vector */
#define msa_create_s8(__a) ((v8i8)((uint64_t)__a))
#define msa_create_s16(__a) ((v4i16)((uint64_t)__a))
#define msa_create_s32(__a) ((v2i32)((uint64_t)__a))
#define msa_create_s64(__a) ((v1i64)((uint64_t)__a))
#define msa_create_f32(__a) ((v2f32)((uint64_t)__a))
#define msa_create_f64(__a) ((v1f64) ((uint64_t)__a))
#define msa_create_u8(__a) ((v8u8)((uint64_t)__a))
#define msa_create_u16(__a) ((v4u16)((uint64_t)__a))
#define msa_create_u32(__a) ((v2u32)((uint64_t)__a))
#define msa_create_u64(__a) ((v1u64)((uint64_t)__a))

/* qrshrn */
__extension__ extern __inline v8i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrn_n_s16 (v8i16 __a, const int __b)
{  
  v8i16 vq;
  vq = __msa_sat_s_h(__msa_srari_h(__a,__b),7);
  return (v8i8){(int8_t)__msa_copy_s_h(vq,0),
                (int8_t)__msa_copy_s_h(vq,1),
                (int8_t)__msa_copy_s_h(vq,2),
                (int8_t)__msa_copy_s_h(vq,3),
                (int8_t)__msa_copy_s_h(vq,4),
                (int8_t)__msa_copy_s_h(vq,5),
                (int8_t)__msa_copy_s_h(vq,6),
                (int8_t)__msa_copy_s_h(vq,7)};
}

__extension__ extern __inline v4i16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrn_n_s32 (v4i32 __a, const int __b)
{
  v4i32 vq;
  vq = __msa_sat_s_w(__msa_srari_w(__a,__b),15);
  return (v4i16){(int16_t)__msa_copy_s_w(vq,0),
                 (int16_t)__msa_copy_s_w(vq,1),
                 (int16_t)__msa_copy_s_w(vq,2),
                 (int16_t)__msa_copy_s_w(vq,3)};  
}

__extension__ extern __inline v2i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrn_n_s64 (v2i64 __a, const int __b)
{
  v2i64 vq;
  vq = __msa_sat_s_d(__msa_srari_d(__a,__b),31);
  return (v2i32){(int32_t)__msa_copy_s_d(vq,0),
                 (int32_t)__msa_copy_s_d(vq,1)};
}

__extension__ extern __inline v8u8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrn_n_u16 (v8u16 __a, const int __b)
{
  v8u16 vq;
  vq = __msa_sat_u_h((v8u16)__msa_srlri_h((v8i16)__a,__b),7);
  return (v8u8){(uint8_t)__msa_copy_u_h((v8i16)vq,0),
                (uint8_t)__msa_copy_u_h((v8i16)vq,1),
                (uint8_t)__msa_copy_u_h((v8i16)vq,2),
                (uint8_t)__msa_copy_u_h((v8i16)vq,3),
                (uint8_t)__msa_copy_u_h((v8i16)vq,4),
                (uint8_t)__msa_copy_u_h((v8i16)vq,5),
                (uint8_t)__msa_copy_u_h((v8i16)vq,6),
                (uint8_t)__msa_copy_u_h((v8i16)vq,7)};
}

__extension__ extern __inline v4u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrn_n_u32 (v4u32 __a, const int __b)
{
  v4u32 vq;
  vq = __msa_sat_u_w((v4u32)__msa_srlri_w((v4i32)__a,__b),15);
  return (v4u16){(uint16_t)__msa_copy_u_w((v4i32)vq,0),
                 (uint16_t)__msa_copy_u_w((v4i32)vq,1),
                 (uint16_t)__msa_copy_u_w((v4i32)vq,2),
                 (uint16_t)__msa_copy_u_w((v4i32)vq,3)};
}

__extension__ extern __inline v2u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrn_n_u64 (v2u64 __a, const int __b)
{
  v2u64 vq;
  vq = __msa_sat_u_d((v2u64)__msa_srlri_d((v2i64)__a,__b),31);
  return (v2u32){(uint32_t)__msa_copy_u_d((v2i64)vq,0),
                 (uint32_t)__msa_copy_u_d((v2i64)vq,1)};
}

/* qrshrun */
__extension__ extern __inline v8u8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrun_n_s16 (v8i16 __a, const int __b)
{
  v8u16 vec_t,vec_d;

  vec_t = (v8u16) __msa_max_s_h(__msa_fill_h(0), __a);
  vec_d = __msa_sat_u_h((v8u16)__msa_srlri_h((v8i16)vec_t,__b), 7);
  return (v8u8){(uint8_t)__msa_copy_u_h((v8i16)vec_d, 0),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 1),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 2),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 3),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 4),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 5),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 6),
                (uint8_t)__msa_copy_u_h((v8i16)vec_d, 7)};
}

__extension__ extern __inline v4u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrun_n_s32 (v4i32 __a, const int __b)
{
  v4u32 vec_t,vec_d;

  vec_t = (v4u32) __msa_max_s_w(__msa_fill_w(0), __a);
  vec_d = __msa_sat_u_w((v4u32)__msa_srlri_w((v4i32)vec_t,__b), 15);
  return (v4u16){(uint16_t)__msa_copy_u_w((v4i32)vec_d, 0),
                 (uint16_t)__msa_copy_u_w((v4i32)vec_d, 1),
                 (uint16_t)__msa_copy_u_w((v4i32)vec_d, 2),
                 (uint16_t)__msa_copy_u_w((v4i32)vec_d, 3)};
}

__extension__ extern __inline v2u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_qrshrun_n_s64 (v2i64 __a, const int __b)
{
  v2u64 vec_t,vec_d;

  vec_t = (v2u64) __msa_max_s_d(__msa_fill_d(0), __a);
  vec_d = __msa_sat_u_d((v2u64)__msa_srlri_d((v2i64)vec_t,__b), 31);
  return (v2u32){(uint32_t)__msa_copy_u_d((v2i64)vec_d, 0),
                 (uint32_t)__msa_copy_u_d((v2i64)vec_d, 1)};
}

/* shrn */
__extension__ extern __inline v8i8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_shrn_n_s16 (v8i16 __a, const int __b)
{
  v8i16 vq;
  vq = __msa_srai_h(__a,__b);
  return (v8i8){(int8_t)__msa_copy_s_h(vq,0),
                (int8_t)__msa_copy_s_h(vq,1),
                (int8_t)__msa_copy_s_h(vq,2),
                (int8_t)__msa_copy_s_h(vq,3),
                (int8_t)__msa_copy_s_h(vq,4),
                (int8_t)__msa_copy_s_h(vq,5),
                (int8_t)__msa_copy_s_h(vq,6),
                (int8_t)__msa_copy_s_h(vq,7)};
}

__extension__ extern __inline v4i16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_shrn_n_s32(v4i32 __a, const int __b)
{
  v4i32 vq;
  vq = __msa_srai_w(__a,__b);
  return (v4i16){(int16_t)__msa_copy_s_w(vq,0),
                 (int16_t)__msa_copy_s_w(vq,1),
                 (int16_t)__msa_copy_s_w(vq,2),
                 (int16_t)__msa_copy_s_w(vq,3)};
}

__extension__ extern __inline v2i32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_shrn_n_s64 (v2i64 __a, const int __b)
{
  v2i64 vq;
  vq = __msa_srai_d(__a,__b);
  return (v2i32){(int32_t)__msa_copy_s_d(vq,0),
                 (int32_t)__msa_copy_s_d(vq,1)};
}

__extension__ extern __inline v8u8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_shrn_n_u16 (v8u16 __a, const int __b)
{
  v8i16 vq;
  vq = __msa_srli_h((v8i16)__a,__b);
  return (v8u8){(uint8_t)__msa_copy_u_h(vq,0),
                (uint8_t)__msa_copy_u_h(vq,1),
                (uint8_t)__msa_copy_u_h(vq,2),
                (uint8_t)__msa_copy_u_h(vq,3),
                (uint8_t)__msa_copy_u_h(vq,4),
                (uint8_t)__msa_copy_u_h(vq,5),
                (uint8_t)__msa_copy_u_h(vq,6),
                (uint8_t)__msa_copy_u_h(vq,7)};
}

__extension__ extern __inline v4u16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_shrn_n_u32 (v4u32 __a, const int __b)
{
  v4i32 vq;
  vq = __msa_srli_w((v4i32)__a,__b);
  return (v4u16){(uint16_t)__msa_copy_u_w(vq,0),
                 (uint16_t)__msa_copy_u_w(vq,1),
                 (uint16_t)__msa_copy_u_w(vq,2),
                 (uint16_t)__msa_copy_u_w(vq,3)};
}

__extension__ extern __inline v2u32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_shrn_n_u64 (v2u64 __a, const int __b)
{
  v2i64 vq;
  vq = __msa_srli_d((v2i64)__a,__b);
  return (v2u32){(uint32_t)__msa_copy_u_d(vq,0),
                 (uint32_t)__msa_copy_u_d(vq,1)};
}

/* rshrn */
__extension__ extern __inline v8i8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_rshrn_n_s16 (v8i16 __a, const int __b)
{
  v8i16 vq;
  vq = __msa_srari_h(__a,__b);
  return (v8i8){(int8_t)__msa_copy_s_h(vq,0),
                (int8_t)__msa_copy_s_h(vq,1),
                (int8_t)__msa_copy_s_h(vq,2),
                (int8_t)__msa_copy_s_h(vq,3),
                (int8_t)__msa_copy_s_h(vq,4),
                (int8_t)__msa_copy_s_h(vq,5),
                (int8_t)__msa_copy_s_h(vq,6),
                (int8_t)__msa_copy_s_h(vq,7)};
}

__extension__ extern __inline v4i16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_rshrn_n_s32 (v4i32 __a, const int __b)
{
	v4i32 vq;
	vq = __msa_srari_w(__a,__b);
	return (v4i16){(int16_t)__msa_copy_s_w(vq,0),
                       (int16_t)__msa_copy_s_w(vq,1),
                       (int16_t)__msa_copy_s_w(vq,2),
                       (int16_t)__msa_copy_s_w(vq,3)};
}

__extension__ extern __inline v2i32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_rshrn_n_s64 (v2i64 __a, const int __b)
{
	v2i64 vq;
	vq = __msa_srari_d(__a,__b);
	return (v2i32){(int32_t)__msa_copy_s_d(vq,0),
                       (int32_t)__msa_copy_s_d(vq,1)};
}

__extension__ extern __inline v8u8
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_rshrn_n_u16 (v8u16 __a, const int __b)
{
  v8i16 vq;
  vq = __msa_srlri_h((v8i16)__a,__b);
  return (v8u8){(uint8_t)__msa_copy_u_h(vq,0),
                (uint8_t)__msa_copy_u_h(vq,1),
                (uint8_t)__msa_copy_u_h(vq,2),
                (uint8_t)__msa_copy_u_h(vq,3),
                (uint8_t)__msa_copy_u_h(vq,4),
                (uint8_t)__msa_copy_u_h(vq,5),
                (uint8_t)__msa_copy_u_h(vq,6),
                (uint8_t)__msa_copy_u_h(vq,7)};
}

__extension__ extern __inline v4u16
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_rshrn_n_u32 (v4u32 __a, const int __b)
{
  v4i32 vq;
  vq = __msa_srlri_w((v4i32)__a,__b);
  return (v4u16){(uint16_t)__msa_copy_u_w(vq,0),
                 (uint16_t)__msa_copy_u_w(vq,1),
                 (uint16_t)__msa_copy_u_w(vq,2),
                 (uint16_t)__msa_copy_u_w(vq,3)};
}

__extension__ extern __inline v2u32
__attribute__  ((__always_inline__, __gnu_inline__, __artificial__))
msa_rshrn_n_u64 (v2u64 __a, const int __b)
{
  v2i64 vq;
  vq = __msa_srlri_d((v2i64)__a,__b);
  return (v2u32){(uint32_t)__msa_copy_u_d(vq,0),
                 (uint32_t)__msa_copy_u_d(vq,1)};
}

/* Vector and vector minimum.*/
#define msa_minq_f32(__a, __b) (__msa_fmin_w (__a, __b))
#define msa_minq_f64(__a, __b) (__msa_fmin_d (__a, __b))
#define msa_minq_s8(__a, __b) (__msa_min_s_b(__a, __b))
#define msa_minq_s16(__a, __b) (__msa_min_s_h (__a, __b))
#define msa_minq_s32(__a, __b) (__msa_min_s_w (__a, __b))
#define msa_minq_u8(__a, __b) ((v16u8) __msa_min_u_b (__a, __b))
#define msa_minq_u16(__a, __b) ((v8u16) __msa_min_u_h (__a, __b))
#define msa_minq_u32(__a, __b) ((v4u32) __msa_min_u_w (__a, __b))

/* Vector and vector maximum.*/
#define msa_maxq_f32(__a, __b) (__msa_fmax_w (__a, __b))
#define msa_maxq_f64(__a, __b) (__msa_fmax_d (__a, __b))
#define msa_maxq_s8(__a, __b) (__msa_max_s_b (__a, __b))
#define msa_maxq_s16(__a, __b) (__msa_max_s_h (__a, __b))
#define msa_maxq_s32(__a, __b) (__msa_max_s_w (__a, __b))
#define msa_maxq_u8(__a, __b) ((v16u8) __msa_max_u_b (__a, __b))
#define msa_maxq_u16(__a, __b) ((v8u16) __msa_max_u_h (__a, __b))
#define msa_maxq_u32(__a, __b) ((v4u32) __msa_max_u_w (__a, __b))

/* pair min  */
__extension__ extern __inline v8i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmin_s8 (v8i8 a, v8i8 b)
{
  return (v8i8){
  	a[0]<a[1]? a[0]:a[1],
  	a[2]<a[3]? a[2]:a[3],
  	a[4]<a[5]? a[4]:a[5],
  	a[6]<a[7]? a[6]:a[7],
  	b[0]<b[1]? b[0]:b[1],
  	b[2]<b[3]? b[2]:b[3],
  	b[4]<b[5]? b[4]:b[5],
  	b[6]<b[7]? b[6]:b[7]
  };
}

__extension__ extern __inline v4i16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmin_s16 (v4i16 a, v4i16 b)
{
  return (v4i16){
    a[0]<a[1]? a[0]:a[1],
    a[2]<a[3]? a[2]:a[3],
    b[0]<b[1]? b[0]:b[1],
    b[2]<b[3]? b[2]:b[3]
  };
}

__extension__ extern __inline v2i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmin_s32 (v2i32 a, v2i32 b)
{
  return (v2i32){
    a[0]<a[1]? a[0]:a[1],
    b[0]<a[1]? b[0]:b[1]
  };
}

__extension__ extern __inline v8u8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
vmsa_pmin_u8 (v8u8 a, v8u8 b)
{
  return (v8u8){
    a[0]<a[1]? a[0]:a[1],
    a[2]<a[3]? a[2]:a[3],
    a[4]<a[5]? a[4]:a[5],
    a[6]<a[7]? a[6]:a[7],
    b[0]<b[1]? b[0]:b[1],
    b[2]<b[3]? b[2]:b[3],
    b[4]<b[5]? b[4]:b[5],
    b[6]<b[7]? b[6]:b[7]
  };
}

__extension__ extern __inline v4u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmin_u16 (v4u16 a, v4u16 b)
{
  return (v4u16){
    a[0]<a[1]? a[0]:a[1],
    a[2]<a[3]? a[2]:a[3],
    b[0]<b[1]? b[0]:b[1],
    b[2]<b[3]? b[2]:b[3]
  };
}

__extension__ extern __inline v2u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmin_u32 (v2u32 a, v2u32 b)
{
  return (v2u32){
    a[0]<a[1]? a[0]:a[1],
    b[0]<a[1]? b[0]:b[1]
  };
}

__extension__ extern __inline v2f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmin_f32 (v2f32 a, v2f32 b)
{
  return (v2f32){
    a[0]<a[1]? a[0]:a[1],
    b[0]<a[1]? b[0]:b[1]
  };
}

/* pair max */
__extension__ extern __inline v8i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmax_s8 (v8i8 a, v8i8 b)
{
  return (v8i8){
  	a[0]>a[1]? a[0]:a[1],
  	a[2]>a[3]? a[2]:a[3],
  	a[4]>a[5]? a[4]:a[5],
  	a[6]>a[7]? a[6]:a[7],
  	b[0]>b[1]? b[0]:b[1],
  	b[2]>b[3]? b[2]:b[3],
  	b[4]>b[5]? b[4]:b[5],
  	b[6]>b[7]? b[6]:b[7]
  };
}

__extension__ extern __inline v4i16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmax_s16 (v4i16 a, v4i16 b)
{
  return (v4i16){
    a[0]>a[1]? a[0]:a[1],
    a[2]>a[3]? a[2]:a[3],
    b[0]>b[1]? b[0]:b[1],
    b[2]>b[3]? b[2]:b[3]
  };
}

__extension__ extern __inline v2i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmax_s32 (v2i32 a, v2i32 b)
{
  return (v2i32){
    a[0]>a[1]? a[0]:a[1],
    b[0]>b[1]? b[0]:b[1]
  };
}

__extension__ extern __inline v8u8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
vmsa_pmax_u8 (v8u8 a, v8u8 b)
{
  return (v8u8){
    a[0]>a[1]? a[0]:a[1],
    a[2]>a[3]? a[2]:a[3],
    a[4]>a[5]? a[4]:a[5],
    a[6]>a[7]? a[6]:a[7],
    b[0]>b[1]? b[0]:b[1],
    b[2]>b[3]? b[2]:b[3],
    b[4]>b[5]? b[4]:b[5],
    b[6]>b[7]? b[6]:b[7]
  };
}

__extension__ extern __inline v4u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmax_u16 (v4u16 a, v4u16 b)
{
  return (v4u16){
    a[0]>a[1]? a[0]:a[1],
    a[2]>a[3]? a[2]:a[3],
    b[0]>b[1]? b[0]:b[1],
    b[2]>b[3]? b[2]:b[3]
  };
}

__extension__ extern __inline v2u32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmax_u32 (v2u32 a, v2u32 b)
{
  return (v2u32){
    a[0]>a[1]? a[0]:a[1],
    b[0]>b[1]? b[0]:b[1]
  };
}

__extension__ extern __inline v2f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_pmax_f32 (v2f32 a, v2f32 b)
{
  return (v2f32){
    a[0]>a[1]? a[0]:a[1],
    b[0]>b[1]? b[0]:b[1]
  };
}

/* vector type reinterpretion */
#define MSA_TPV_REINTERPRET(_Tpv, Vec)  ((_Tpv)Vec)

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
#define msa_getq_lane_f32(__a, __b)      ((float)__a[LANE_IMM0_3(__b)])
#define msa_getq_lane_f64(__a, __b)      ((double)__a[LANE_IMM0_1(__b)])
#define msa_get_lane_u8(__a, __b)        ((uint8_t)__a[LANE_IMM0_7(__b)])
#define msa_get_lane_s8(__a, __b)        ((int8_t)__a[LANE_IMM0_7(__b)])
#define msa_get_lane_u16(__a, __b)       ((uint16_t)__a[LANE_IMM0_3(__b)])
#define msa_get_lane_s16(__a, __b)       ((int16_t)__a[LANE_IMM0_3(__b)])
#define msa_get_lane_u32(__a, __b)       ((uint32_t)__a[LANE_IMM0_1(__b)])
#define msa_get_lane_s32(__a, __b)       ((int32_t)__a[LANE_IMM0_1(__b)])
#define msa_get_lane_f32(__a, __b)       ((float)__a[LANE_IMM0_3(__b)])
#define msa_getq_lane_u8(a, imm0_15)     __builtin_msa_copy_u_b((v16i8)a, imm0_15)
#define msa_getq_lane_s8                 __builtin_msa_copy_s_b
#define msa_getq_lane_u16(a, imm0_7)     __builtin_msa_copy_u_h((v8i16)a, imm0_7)
#define msa_getq_lane_s16                __builtin_msa_copy_s_h
#define msa_getq_lane_u32(a, imm0_3)     __builtin_msa_copy_u_w((v4i32)a, imm0_3)
#define msa_getq_lane_s32                __builtin_msa_copy_s_w
#if (__mips == 64)
#define msa_getq_lane_u64(a, imm0_1)     __builtin_msa_copy_u_d((v2i64)a, imm0_1)
#define msa_getq_lane_s64                __builtin_msa_copy_s_d
#else
#define msa_getq_lane_u64(a, imm0_1)     ((uint64_t)__a[LANE_IMM0_1(imm0_1)])
#define msa_getq_lane_s64(a, imm0_1)     ((int64_t)__a[LANE_IMM0_1(imm0_1)])
#endif

/* combine */
#define __COMBINE_64_64(__TYPE, a, b) ((__TYPE)((v2u64){((v1u64)a)[0], ((v1u64)b)[0]}))

/* v16i8 msa_combine_s8 (v8i8 __a, v8i8 __b) */
#define msa_combine_s8(__a, __b)  __COMBINE_64_64(v16i8, __a, __b)

/* v8i16 msa_combine_s16(v4i16 __a, v4i16 __b) */
#define msa_combine_s16(__a, __b)  __COMBINE_64_64(v8i16, __a, __b)

/* v4i32 msa_combine_s32(v2i32 __a, v2i32 __b) */
#define msa_combine_s32(__a, __b)  __COMBINE_64_64(v4i32, __a, __b)

/* v2i64 msa_combine_s64(v1i64 __a, v1i64 __b) */
#define msa_combine_s64(__a, __b)  __COMBINE_64_64(v2i64, __a, __b)

/* v4f32 msa_combine_f32(v2f32 __a, v2f32 __b) */
#define msa_combine_f32(__a, __b)  __COMBINE_64_64(v4f32, __a, __b)

/* v16u8 msa_combine_u8(v8u8 __a, v8u8 __b) */
#define msa_combine_u8(__a, __b)  __COMBINE_64_64(v16u8, __a, __b)

/* v8u16 msa_combine_u16(v4u16 __a, v4u16 __b) */
#define msa_combine_u16(__a, __b)  __COMBINE_64_64(v8u16, __a, __b)

/* v4u32 msa_combine_u32(v2u32 __a, v2u32 __b) */
#define msa_combine_u32(__a, __b)  __COMBINE_64_64(v4u32, __a, __b)

/* v2u64 msa_combine_u64(v1u64 __a, v1u64 __b) */
#define msa_combine_u64(__a, __b)  __COMBINE_64_64(v2u64, __a, __b)

/* v2f64 msa_combine_f64(v1f64 __a, v1f64 __b) */
#define msa_combine_f64(__a, __b)  __COMBINE_64_64(v2f64, __a, __b)

/* get_low, get_high */
#define __GET_LOW(__TYPE, a)   ((__TYPE)((v1u64)(__builtin_msa_copy_u_d((v2i64)a, 0))))

#define __GET_HIGH(__TYPE, a)  ((__TYPE)((v1u64)(__builtin_msa_copy_u_d((v2i64)a, 1))))

/* v8i8 msa_get_low_s8(v16i8 __a) */
#define msa_get_low_s8(__a)  __GET_LOW(v8i8, __a)

/* v4i16 msa_get_low_s16(v8i16 __a) */
#define msa_get_low_s16(__a)  __GET_LOW(v4i16, __a)

/* v2i32 msa_get_low_s32(v4i32 __a) */
#define msa_get_low_s32(__a)  __GET_LOW(v2i32, __a)

/* v1i64 msa_get_low_s64(v2i64 __a) */
#define msa_get_low_s64(__a)  __GET_LOW(v1i64, __a)

/* v8u8 msa_get_low_u8(v16u8 __a) */
#define msa_get_low_u8(__a)  __GET_LOW(v8u8, __a)

/* v4u16 msa_get_low_u16(v8u16 __a) */
#define msa_get_low_u16(__a)  __GET_LOW(v4u16, __a)

/* v2u32 msa_get_low_u32(v4u32 __a) */
#define msa_get_low_u32(__a)  __GET_LOW(v2u32, __a)

/* v1u64 msa_get_low_u64(v2u64 __a) */
#define msa_get_low_u64(__a)  __GET_LOW(v1u64, __a)

/* v2f32 msa_get_low_f32(v4f32 __a) */
#define msa_get_low_f32(__a)  __GET_LOW(v2f32, __a)

/* v1f64 msa_get_low_f64(v2f64 __a) */
#define msa_get_low_f64(__a)  __GET_LOW(v1f64, __a)

/* v8i8 msa_get_high_s8(v16i8 __a) */
#define msa_get_high_s8(__a)  __GET_HIGH(v8i8, __a)

/* v4i16 msa_get_high_s16(v8i16 __a) */
#define msa_get_high_s16(__a)  __GET_HIGH(v4i16, __a)

/* v2i32 msa_get_high_s32(v4i32 __a) */
#define msa_get_high_s32(__a)  __GET_HIGH(v2i32, __a)

/* v1i64 msa_get_high_s64(v2i64 __a) */
#define msa_get_high_s64(__a)  __GET_HIGH(v1i64, __a)

/* v8u8 msa_get_high_u8(v16u8 __a) */
#define msa_get_high_u8(__a)  __GET_HIGH(v8u8, __a)

/* v4u16 msa_get_high_u16(v8u16 __a) */
#define msa_get_high_u16(__a)  __GET_HIGH(v4u16, __a)

/* v2u32 msa_get_high_u32(v4u32 __a) */
#define msa_get_high_u32(__a)  __GET_HIGH(v2u32, __a)

/* v1u64 msa_get_high_u64(v2u64 __a) */
#define msa_get_high_u64(__a)  __GET_HIGH(v1u64, __a)

/* v2f32 msa_get_high_f32(v4f32 __a) */
#define msa_get_high_f32(__a)  __GET_HIGH(v2f32, __a)

/* v1f64 msa_get_high_f64(v2f64 __a) */
#define msa_get_high_f64(__a)  __GET_HIGH(v1f64, __a)

/* ri = ai * b[lane] */
/* v4f32 msa_mulq_lane_f32(v4f32 __a, v2f32 __b, const int __lane) */
#define msa_mulq_lane_f32(__a, __b, __lane)  (__a * msa_get_lane_f32 (__b, __lane))

/* ri = ai + bi * c[lane] */
/* v4f32 msa_mlaq_lane_f32(v4f32 __a, v4f32 __b, v2f32 __c, const int __lane) */
#define msa_mlaq_lane_f32(__a, __b, __c, __lane)  (__a + (__b * msa_get_lane_f32 (__c, __lane)))

/* uint16_t msa_sum_u16(v8u16 __a)*/
#define msa_sum_u16(__a)                         \
({                                               \
  v4u32 _b;                                      \
  v2u64 _c;                                      \
  _b = __builtin_msa_hadd_u_w(__a, __a);         \
  _c = __builtin_msa_hadd_u_d(_b, _b);           \
  (uint16_t)(_c[0] + _c[1]);                     \
})

/* int16_t msa_sum_s16(v8i16 __a) */
#define msa_sum_s16(__a)                        \
({                                              \
  v4i32 _b;                                     \
  v2i64 _c;                                     \
  _b = __builtin_msa_hadd_s_w(__a, __a);        \
  _c = __builtin_msa_hadd_s_d(_b, _b);          \
  (int16_t)(_c[0] + _c[1]);                     \
})


/* uint32_t msa_sum_u32(v4u32 __a)*/
#define msa_sum_u32(__a)                       \
({                                             \
  v2u64 _b;                                    \
  _b = __builtin_msa_hadd_u_d(__a, __a);       \
  (uint32_t)(_b[0] + _b[1]);                   \
})

/* int32_t  msa_sum_s32(v4i32 __a)*/
#define msa_sum_s32(__a)                       \
({                                             \
  v2i64 _b;                                    \
  _b = __builtin_msa_hadd_s_d(__a, __a);       \
  (int32_t)(_b[0] + _b[1]);                    \
})

/* float msa_sum_f32(v4f32 __a)*/
#define msa_sum_f32(__a)  (__a[0] + __a[1] + __a[2] + __a[3])

/* v8u16 msa_paddlq_u8(v16u8 __a) */
#define msa_paddlq_u8(__a)  (__builtin_msa_hadd_u_h(__a, __a))

/* v8i16 msa_paddlq_s8(v16i8 __a) */
#define msa_paddlq_s8(__a)  (__builtin_msa_hadd_s_h(__a, __a))

/* v4u32 msa_paddlq_u16 (v8u16 __a)*/
#define msa_paddlq_u16(__a)  (__builtin_msa_hadd_u_w(__a, __a))

/* v4i32 msa_paddlq_s16 (v8i16 __a)*/
#define msa_paddlq_s16(__a)  (__builtin_msa_hadd_s_w(__a, __a))

/* v2u64 msa_paddlq_u32(v4u32 __a) */
#define msa_paddlq_u32(__a)  (__builtin_msa_hadd_u_d(__a, __a))

/* v2i64 msa_paddlq_s32(v4i32 __a) */
#define msa_paddlq_s32(__a)  (__builtin_msa_hadd_s_d(__a, __a))

#define V8U8_2_V8U16(x)   {(uint16_t)x[0], (uint16_t)x[1], (uint16_t)x[2], (uint16_t)x[3], \
                            (uint16_t)x[4], (uint16_t)x[5], (uint16_t)x[6], (uint16_t)x[7]}
#define V8I8_2_V8I16(x)   {(int16_t)x[0], (int16_t)x[1], (int16_t)x[2], (int16_t)x[3], \
                            (int16_t)x[4], (int16_t)x[5], (int16_t)x[6], (int16_t)x[7]}
#define V4U16_2_V4U32(x)  {(uint32_t)x[0], (uint32_t)x[1], (uint32_t)x[2], (uint32_t)x[3]}
#define V4I16_2_V4I32(x)  {(int32_t)x[0], (int32_t)x[1], (int32_t)x[2], (int32_t)x[3]}
#define V2U32_2_V2U64(x)  {(uint64_t)x[0], (uint64_t)x[1]}

/* v8u16 msa_mull_u8(v8u8 __a, v8u8 __b) */
#define msa_mull_u8(__a, __b)  ((v8u16)__builtin_msa_mulv_h((v8i16)V8U8_2_V8U16(__a), (v8i16)V8U8_2_V8U16(__b)))

/* v8i16 msa_mull_s8(v8i8 __a, v8i8 __b)*/
#define msa_mull_s8(__a, __b)  __builtin_msa_mulv_h((v8i16)V8I8_2_V8I16(__a), (v8i16)V8I8_2_V8I16(__b))

/* v4u32 msa_mull_u16(v4u16 __a, v4u16 __b) */
#define msa_mull_u16(__a, __b)  ((v4u32)__builtin_msa_mulv_w((v4i32)V4U16_2_V4U32(__a), (v4i32)V4U16_2_V4U32(__b)))

/* v4i32 msa_mull_s16(v4i16 __a, v4i16 __b) */
#define msa_mull_s16(__a, __b)  (__builtin_msa_mulv_w((v4i32)V4I16_2_V4I32(__a), (v4i32)V4I16_2_V4I32(__b)))

/* v2u64 msa_mull_u32(v2u32 __a, v2u32 __b) */
#define msa_mull_u32(__a, __b)  ((v2u64)__builtin_msa_mulv_d((v2i64)V2U32_2_V2U64(__a), (v2i64)V2U32_2_V2U64(__b)))

/* bitwise and: __builtin_msa_and_v */
#define msa_andq_u8(__a, __b)  ((v16u8)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))
#define msa_andq_s8(__a, __b)  ((v16i8)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))
#define msa_andq_u16(__a, __b) ((v8u16)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))
#define msa_andq_s16(__a, __b) ((v8i16)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))
#define msa_andq_u32(__a, __b) ((v4u32)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))
#define msa_andq_s32(__a, __b) ((v4i32)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))
#define msa_andq_u64(__a, __b) ((v2u64)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))
#define msa_andq_s64(__a, __b) ((v2i64)__builtin_msa_and_v((v16u8)__a, (v16u8)__b))

/* bitwise or: __builtin_msa_or_v */
#define msa_orrq_u8(__a, __b)  ((v16u8)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))
#define msa_orrq_s8(__a, __b)  ((v16i8)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))
#define msa_orrq_u16(__a, __b) ((v8u16)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))
#define msa_orrq_s16(__a, __b) ((v8i16)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))
#define msa_orrq_u32(__a, __b) ((v4u32)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))
#define msa_orrq_s32(__a, __b) ((v4i32)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))
#define msa_orrq_u64(__a, __b) ((v2u64)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))
#define msa_orrq_s64(__a, __b) ((v2i64)__builtin_msa_or_v((v16u8)__a, (v16u8)__b))

/* bitwise xor: __builtin_msa_xor_v */
#define msa_eorq_u8(__a, __b)  ((v16u8)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))
#define msa_eorq_s8(__a, __b)  ((v16i8)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))
#define msa_eorq_u16(__a, __b) ((v8u16)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))
#define msa_eorq_s16(__a, __b) ((v8i16)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))
#define msa_eorq_u32(__a, __b) ((v4u32)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))
#define msa_eorq_s32(__a, __b) ((v4i32)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))
#define msa_eorq_u64(__a, __b) ((v2u64)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))
#define msa_eorq_s64(__a, __b) ((v2i64)__builtin_msa_xor_v((v16u8)__a, (v16u8)__b))

/* bitwise not: v16u8 __builtin_msa_xori_b (v16u8, 0xff) */
#define msa_mvnq_u8(__a)  ((v16u8)__builtin_msa_xori_b((v16u8)__a, 0xFF))
#define msa_mvnq_s8(__a)  ((v16i8)__builtin_msa_xori_b((v16u8)__a, 0xFF))
#define msa_mvnq_u16(__a) ((v8u16)__builtin_msa_xori_b((v16u8)__a, 0xFF))
#define msa_mvnq_s16(__a) ((v8i16)__builtin_msa_xori_b((v16u8)__a, 0xFF))
#define msa_mvnq_u32(__a) ((v4u32)__builtin_msa_xori_b((v16u8)__a, 0xFF))
#define msa_mvnq_s32(__a) ((v4i32)__builtin_msa_xori_b((v16u8)__a, 0xFF))
#define msa_mvnq_u64(__a) ((v2u64)__builtin_msa_xori_b((v16u8)__a, 0xFF))
#define msa_mvnq_s64(__a) ((v2i64)__builtin_msa_xori_b((v16u8)__a, 0xFF))

/* compare equal: ceq -> ri = ai == bi ? 1...1:0...0 */
#define msa_ceqq_u8(__a, __b)  ((v16u8)__builtin_msa_ceq_b((v16i8)__a, (v16i8)__b))
#define msa_ceqq_s8(__a, __b)  ((v16u8)__builtin_msa_ceq_b((v16i8)__a, (v16i8)__b))
#define msa_ceqq_u16(__a, __b) ((v8u16)__builtin_msa_ceq_h((v8i16)__a, (v8i16)__b))
#define msa_ceqq_s16(__a, __b) ((v8u16)__builtin_msa_ceq_h((v8i16)__a, (v8i16)__b))
#define msa_ceqq_u32(__a, __b) ((v4u32)__builtin_msa_ceq_w((v4i32)__a, (v4i32)__b))
#define msa_ceqq_s32(__a, __b) ((v4u32)__builtin_msa_ceq_w((v4i32)__a, (v4i32)__b))
#define msa_ceqq_f32(__a, __b) ((v4u32)__builtin_msa_fceq_w((v4f32)__a, (v4f32)__b))
#define msa_ceqq_u64(__a, __b) ((v2u64)__builtin_msa_ceq_d((v2i64)__a, (v2i64)__b))
#define msa_ceqq_s64(__a, __b) ((v2u64)__builtin_msa_ceq_d((v2i64)__a, (v2i64)__b))
#define msa_ceqq_f64(__a, __b) ((v2u64)__builtin_msa_fceq_d((v2f64)__a, (v2f64)__b))

/* Compare less-than: clt -> ri = ai < bi ? 1...1:0...0 */
#define msa_cltq_u8(__a, __b)  ((v16u8)__builtin_msa_clt_u_b((v16u8)__a, (v16u8)__b))
#define msa_cltq_s8(__a, __b)  ((v16u8)__builtin_msa_clt_s_b((v16i8)__a, (v16i8)__b))
#define msa_cltq_u16(__a, __b) ((v8u16)__builtin_msa_clt_u_h((v8u16)__a, (v8u16)__b))
#define msa_cltq_s16(__a, __b) ((v8u16)__builtin_msa_clt_s_h((v8i16)__a, (v8i16)__b))
#define msa_cltq_u32(__a, __b) ((v4u32)__builtin_msa_clt_u_w((v4u32)__a, (v4u32)__b))
#define msa_cltq_s32(__a, __b) ((v4u32)__builtin_msa_clt_s_w((v4i32)__a, (v4i32)__b))
#define msa_cltq_f32(__a, __b) ((v4u32)__builtin_msa_fclt_w((v4f32)__a, (v4f32)__b))
#define msa_cltq_u64(__a, __b) ((v2u64)__builtin_msa_clt_u_d((v2u64)__a, (v2u64)__b))
#define msa_cltq_s64(__a, __b) ((v2u64)__builtin_msa_clt_s_d((v2i64)__a, (v2i64)__b))
#define msa_cltq_f64(__a, __b) ((v2u64)__builtin_msa_fclt_d((v2f64)__a, (v2f64)__b))

/* compare greater-than: cgt -> ri = ai > bi ? 1...1:0...0 */
#define msa_cgtq_u8(__a, __b)  ((v16u8)__builtin_msa_clt_u_b((v16u8)__b, (v16u8)__a))
#define msa_cgtq_s8(__a, __b)  ((v16u8)__builtin_msa_clt_s_b((v16i8)__b, (v16i8)__a))
#define msa_cgtq_u16(__a, __b) ((v8u16)__builtin_msa_clt_u_h((v8u16)__b, (v8u16)__a))
#define msa_cgtq_s16(__a, __b) ((v8u16)__builtin_msa_clt_s_h((v8i16)__b, (v8i16)__a))
#define msa_cgtq_u32(__a, __b) ((v4u32)__builtin_msa_clt_u_w((v4u32)__b, (v4u32)__a))
#define msa_cgtq_s32(__a, __b) ((v4u32)__builtin_msa_clt_s_w((v4i32)__b, (v4i32)__a))
#define msa_cgtq_f32(__a, __b) ((v4u32)__builtin_msa_fclt_w((v4f32)__b, (v4f32)__a))
#define msa_cgtq_u64(__a, __b) ((v2u64)__builtin_msa_clt_u_d((v2u64)__b, (v2u64)__a))
#define msa_cgtq_s64(__a, __b) ((v2u64)__builtin_msa_clt_s_d((v2i64)__b, (v2i64)__a))
#define msa_cgtq_f64(__a, __b) ((v2u64)__builtin_msa_fclt_d((v2f64)__b, (v2f64)__a))

/* compare less-equal: cle -> ri = ai <= bi ? 1...1:0...0 */
#define msa_cleq_u8(__a, __b)  ((v16u8)__builtin_msa_cle_u_b((v16u8)__a, (v16u8)__b))
#define msa_cleq_s8(__a, __b)  ((v16u8)__builtin_msa_cle_s_b((v16i8)__a, (v16i8)__b))
#define msa_cleq_u16(__a, __b) ((v8u16)__builtin_msa_cle_u_h((v8u16)__a, (v8u16)__b))
#define msa_cleq_s16(__a, __b) ((v8u16)__builtin_msa_cle_s_h((v8i16)__a, (v8i16)__b))
#define msa_cleq_u32(__a, __b) ((v4u32)__builtin_msa_cle_u_w((v4u32)__a, (v4u32)__b))
#define msa_cleq_s32(__a, __b) ((v4u32)__builtin_msa_cle_s_w((v4i32)__a, (v4i32)__b))
#define msa_cleq_f32(__a, __b) ((v4u32)__builtin_msa_fcle_w((v4f32)__a, (v4f32)__b))
#define msa_cleq_u64(__a, __b) ((v2u64)__builtin_msa_cle_u_d((v2u64)__a, (v2u64)__b))
#define msa_cleq_s64(__a, __b) ((v2u64)__builtin_msa_cle_s_d((v2i64)__a, (v2i64)__b))
#define msa_cleq_f64(__a, __b) ((v2u64)__builtin_msa_fcle_d((v2f64)__a, (v2f64)__b))

/* compare greater-equal: cge -> ri = ai >= bi ? 1...1:0...0 */
#define msa_cgeq_u8(__a, __b)  ((v16u8)__builtin_msa_cle_u_b((v16u8)__b, (v16u8)__a))
#define msa_cgeq_s8(__a, __b)  ((v16u8)__builtin_msa_cle_s_b((v16i8)__b, (v16i8)__a))
#define msa_cgeq_u16(__a, __b) ((v8u16)__builtin_msa_cle_u_h((v8u16)__b, (v8u16)__a))
#define msa_cgeq_s16(__a, __b) ((v8u16)__builtin_msa_cle_s_h((v8i16)__b, (v8i16)__a))
#define msa_cgeq_u32(__a, __b) ((v4u32)__builtin_msa_cle_u_w((v4u32)__b, (v4u32)__a))
#define msa_cgeq_s32(__a, __b) ((v4u32)__builtin_msa_cle_s_w((v4i32)__b, (v4i32)__a))
#define msa_cgeq_f32(__a, __b) ((v4u32)__builtin_msa_fcle_w((v4f32)__b, (v4f32)__a))
#define msa_cgeq_u64(__a, __b) ((v2u64)__builtin_msa_cle_u_d((v2u64)__b, (v2u64)__a))
#define msa_cgeq_s64(__a, __b) ((v2u64)__builtin_msa_cle_s_d((v2i64)__b, (v2i64)__a))
#define msa_cgeq_f64(__a, __b) ((v2u64)__builtin_msa_fcle_d((v2f64)__b, (v2f64)__a))

/* Shift Left Logical: shl -> ri = ai << bi;  */
#define msa_shlq_u8(__a, __b)  ((v16u8)__builtin_msa_sll_b((v16i8)__a, (v16i8)__b))
#define msa_shlq_s8(__a, __b)  ((v16i8)__builtin_msa_sll_b((v16i8)__a, (v16i8)__b))
#define msa_shlq_u16(__a, __b) ((v8u16)__builtin_msa_sll_h((v8i16)__a, (v8i16)__b))
#define msa_shlq_s16(__a, __b) ((v8i16)__builtin_msa_sll_h((v8i16)__a, (v8i16)__b))
#define msa_shlq_u32(__a, __b) ((v4u32)__builtin_msa_sll_w((v4i32)__a, (v4i32)__b))
#define msa_shlq_s32(__a, __b) ((v4i32)__builtin_msa_sll_w((v4i32)__a, (v4i32)__b))
#define msa_shlq_u64(__a, __b) ((v2u64)__builtin_msa_sll_d((v2i64)__a, (v2i64)__b))
#define msa_shlq_s64(__a, __b) ((v2i64)__builtin_msa_sll_d((v2i64)__a, (v2i64)__b))

/* Immediate Shift Left Logical: shl -> ri = ai << imm;  */
#define msa_shlq_n_u8(__a, __imm) ((v16u8)__builtin_msa_slli_b((v16i8)__a, __imm))
#define msa_shlq_n_s8(__a, __imm) ((v16i8)__builtin_msa_slli_b((v16i8)__a, __imm))
#define msa_shlq_n_u16(__a, __imm) ((v8u16)__builtin_msa_slli_h((v8i16)__a, __imm))
#define msa_shlq_n_s16(__a, __imm) ((v8i16)__builtin_msa_slli_h((v8i16)__a, __imm))
#define msa_shlq_n_u32(__a, __imm) ((v4u32)__builtin_msa_slli_w((v4i32)__a, __imm))
#define msa_shlq_n_s32(__a, __imm) ((v4i32)__builtin_msa_slli_w((v4i32)__a, __imm))
#define msa_shlq_n_u64(__a, __imm) ((v2u64)__builtin_msa_slli_d((v2i64)__a, __imm))
#define msa_shlq_n_s64(__a, __imm) ((v2i64)__builtin_msa_slli_d((v2i64)__a, __imm))

/* shift right: shrq -> ri = ai >> bi;  */
#define msa_shrq_u8(__a, __b)  ((v16u8)__builtin_msa_srl_b((v16i8)__a, (v16i8)__b))
#define msa_shrq_s8(__a, __b)  ((v16i8)__builtin_msa_sra_b((v16i8)__a, (v16i8)__b))
#define msa_shrq_u16(__a, __b) ((v8u16)__builtin_msa_srl_h((v8i16)__a, (v8i16)__b))
#define msa_shrq_s16(__a, __b) ((v8i16)__builtin_msa_sra_h((v8i16)__a, (v8i16)__b))
#define msa_shrq_u32(__a, __b) ((v4u32)__builtin_msa_srl_w((v4i32)__a, (v4i32)__b))
#define msa_shrq_s32(__a, __b) ((v4i32)__builtin_msa_sra_w((v4i32)__a, (v4i32)__b))
#define msa_shrq_u64(__a, __b) ((v2u64)__builtin_msa_srl_d((v2i64)__a, (v2i64)__b))
#define msa_shrq_s64(__a, __b) ((v2i64)__builtin_msa_sra_d((v2i64)__a, (v2i64)__b))

/* Immediate Shift Right: shr -> ri = ai >> imm;  */
#define msa_shrq_n_u8(__a, __imm) ((v16u8)__builtin_msa_srli_b((v16i8)__a, __imm))
#define msa_shrq_n_s8(__a, __imm) ((v16i8)__builtin_msa_srai_b((v16i8)__a, __imm))
#define msa_shrq_n_u16(__a, __imm) ((v8u16)__builtin_msa_srli_h((v8i16)__a, __imm))
#define msa_shrq_n_s16(__a, __imm) ((v8i16)__builtin_msa_srai_h((v8i16)__a, __imm))
#define msa_shrq_n_u32(__a, __imm) ((v4u32)__builtin_msa_srli_w((v4i32)__a, __imm))
#define msa_shrq_n_s32(__a, __imm) ((v4i32)__builtin_msa_srai_w((v4i32)__a, __imm))
#define msa_shrq_n_u64(__a, __imm) ((v2u64)__builtin_msa_srli_d((v2i64)__a, __imm))
#define msa_shrq_n_s64(__a, __imm) ((v2i64)__builtin_msa_srai_d((v2i64)__a, __imm))

/* Immediate Shift Right Rounded: shr -> ri = ai >> (rounded)imm;  */
#define msa_rshrq_n_u8(__a, __imm) ((v16u8)__builtin_msa_srlri_b((v16i8)__a, __imm))
#define msa_rshrq_n_s8(__a, __imm) ((v16i8)__builtin_msa_srari_b((v16i8)__a, __imm))
#define msa_rshrq_n_u16(__a, __imm) ((v8u16)__builtin_msa_srlri_h((v8i16)__a, __imm))
#define msa_rshrq_n_s16(__a, __imm) ((v8i16)__builtin_msa_srari_h((v8i16)__a, __imm))
#define msa_rshrq_n_u32(__a, __imm) ((v4u32)__builtin_msa_srlri_w((v4i32)__a, __imm))
#define msa_rshrq_n_s32(__a, __imm) ((v4i32)__builtin_msa_srari_w((v4i32)__a, __imm))
#define msa_rshrq_n_u64(__a, __imm) ((v2u64)__builtin_msa_srlri_d((v2i64)__a, __imm))
#define msa_rshrq_n_s64(__a, __imm) ((v2i64)__builtin_msa_srari_d((v2i64)__a, __imm))

/* rename the msa builtin func to unify the name style for intrin_msa.hpp */
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
#define msa_mulq_s8(a, b)     ((v16i8)__builtin_msa_mulv_b((v16i8)a, (v16i8)b))
#define msa_mulq_u16(a, b)    ((v8u16)__builtin_msa_mulv_h((v8i16)a, (v8i16)b))
#define msa_mulq_s16(a, b)    ((v8i16)__builtin_msa_mulv_h((v8i16)a, (v8i16)b))
#define msa_mulq_u32(a, b)    ((v4u32)__builtin_msa_mulv_w((v4i32)a, (v4i32)b))
#define msa_mulq_s32(a, b)    ((v4i32)__builtin_msa_mulv_w((v4i32)a, (v4i32)b))
#define msa_mulq_u64(a, b)    ((v2u64)__builtin_msa_mulv_d((v2i64)a, (v2i64)b))
#define msa_mulq_s64(a, b)    ((v2i64)__builtin_msa_mulv_d((v2i64)a, (v2i64)b))
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
#define msa_dpadd_s_h         __builtin_msa_dpadd_s_h
#define msa_dpadd_s_w         __builtin_msa_dpadd_s_w
#define msa_dpadd_s_d         __builtin_msa_dpadd_s_d
#define msa_dpadd_u_h         __builtin_msa_dpadd_u_h
#define msa_dpadd_u_w         __builtin_msa_dpadd_u_w
#define msa_dpadd_u_d         __builtin_msa_dpadd_u_d

#define ILVRL_B2(RTYPE, in0, in1, low, hi) do {       \
      low = (RTYPE)__msa_ilvr_b((v16i8)in0, (v16i8)in1);  \
      hi  = (RTYPE)__msa_ilvl_b((v16i8)in0, (v16i8)in1);  \
    } while (0)
#define ILVRL_B2_UB(...) ILVRL_B2(v16u8, __VA_ARGS__)
#define ILVRL_B2_SB(...) ILVRL_B2(v16i8, __VA_ARGS__)
#define ILVRL_B2_UH(...) ILVRL_B2(v8u16, __VA_ARGS__)
#define ILVRL_B2_SH(...) ILVRL_B2(v8i16, __VA_ARGS__)
#define ILVRL_B2_SW(...) ILVRL_B2(v4i32, __VA_ARGS__)

#define ILVRL_H2(RTYPE, in0, in1, low, hi) do {       \
      low = (RTYPE)__msa_ilvr_h((v8i16)in0, (v8i16)in1);  \
      hi  = (RTYPE)__msa_ilvl_h((v8i16)in0, (v8i16)in1);  \
    } while (0)
#define ILVRL_H2_UB(...) ILVRL_H2(v16u8, __VA_ARGS__)
#define ILVRL_H2_SB(...) ILVRL_H2(v16i8, __VA_ARGS__)
#define ILVRL_H2_UH(...) ILVRL_H2(v8u16, __VA_ARGS__)
#define ILVRL_H2_SH(...) ILVRL_H2(v8i16, __VA_ARGS__)
#define ILVRL_H2_SW(...) ILVRL_H2(v4i32, __VA_ARGS__)
#define ILVRL_H2_UW(...) ILVRL_H2(v4u32, __VA_ARGS__)

#define ILVRL_W2(RTYPE, in0, in1, low, hi) do {       \
      low = (RTYPE)__msa_ilvr_w((v4i32)in0, (v4i32)in1);  \
      hi  = (RTYPE)__msa_ilvl_w((v4i32)in0, (v4i32)in1);  \
    } while (0)
#define ILVRL_W2_UB(...) ILVRL_W2(v16u8, __VA_ARGS__)
#define ILVRL_W2_SH(...) ILVRL_W2(v8i16, __VA_ARGS__)
#define ILVRL_W2_SW(...) ILVRL_W2(v4i32, __VA_ARGS__)
#define ILVRL_W2_UW(...) ILVRL_W2(v4u32, __VA_ARGS__)

/* absq, qabsq (r = |a|;) */
#define msa_absq_s8(a)        __builtin_msa_add_a_b(a, __builtin_msa_fill_b(0))
#define msa_absq_s16(a)       __builtin_msa_add_a_h(a, __builtin_msa_fill_h(0))
#define msa_absq_s32(a)       __builtin_msa_add_a_w(a, __builtin_msa_fill_w(0))
#define msa_absq_s64(a)       __builtin_msa_add_a_d(a, __builtin_msa_fill_d(0))
#define msa_absq_f32(a)       ((v4f32)__builtin_msa_bclri_w((v4u32)a, 31))
#define msa_absq_f64(a)       ((v2f64)__builtin_msa_bclri_d((v2u64)a, 63))
#define msa_qabsq_s8(a)       __builtin_msa_adds_a_b(a, __builtin_msa_fill_b(0))
#define msa_qabsq_s16(a)      __builtin_msa_adds_a_h(a, __builtin_msa_fill_h(0))
#define msa_qabsq_s32(a)      __builtin_msa_adds_a_w(a, __builtin_msa_fill_w(0))
#define msa_qabsq_s64(a)      __builtin_msa_adds_a_d(a, __builtin_msa_fill_d(0))

/* abdq, qabdq (r = |a - b|;) */
#define msa_abdq_u8           __builtin_msa_asub_u_b
#define msa_abdq_s8           __builtin_msa_asub_s_b
#define msa_abdq_u16          __builtin_msa_asub_u_h
#define msa_abdq_s16          __builtin_msa_asub_s_h
#define msa_abdq_u32          __builtin_msa_asub_u_w
#define msa_abdq_s32          __builtin_msa_asub_s_w
#define msa_abdq_u64          __builtin_msa_asub_u_d
#define msa_abdq_s64          __builtin_msa_asub_s_d
#define msa_abdq_f32(a, b)    msa_absq_f32(__builtin_msa_fsub_w(a, b))
#define msa_abdq_f64(a, b)    msa_absq_f64(__builtin_msa_fsub_d(a, b))
#define msa_qabdq_s8(a, b)    msa_qabsq_s8(__builtin_msa_subs_s_b(a, b))
#define msa_qabdq_s16(a, b)   msa_qabsq_s16(__builtin_msa_subs_s_h(a, b))
#define msa_qabdq_s32(a, b)   msa_qabsq_s32(__builtin_msa_subs_s_w(a, b))
#define msa_qabdq_s64(a, b)   msa_qabsq_s64(__builtin_msa_subs_s_d(a, b))

/* sqrtq, rsqrtq */
#define msa_sqrtq_f32         __builtin_msa_fsqrt_w
#define msa_sqrtq_f64         __builtin_msa_fsqrt_d
#define msa_rsqrtq_f32        __builtin_msa_frsqrt_w
#define msa_rsqrtq_f64        __builtin_msa_frsqrt_d

/* mlaq (r = a * b + c;(gcc) --> r = a + b * c;(asm)) */
#if 0
#define msa_mlaq_s32          __builtin_msa_maddv_w
#define msa_mlaq_s64          __builtin_msa_maddv_d
#define msa_mlaq_f32          __builtin_msa_fmadd_w
#define msa_mlaq_f64          __builtin_msa_fmadd_d
#else
__extension__ extern __inline v4i32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mlaq_s32(v4i32 __a, v4i32 __b, v4i32 __c)
{
  asm volatile("maddv.w %w[__a], %w[__b], %w[__c]\n"
               // Outputs
               : [__a] "+f"(__a)
               // Inputs
               : [__b] "f"(__b), [__c] "f"(__c));
  return __a;
}

__extension__ extern __inline v2i64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mlaq_s64(v2i64 __a, v2i64 __b, v2i64 __c)
{
  asm volatile("maddv.d %w[__a], %w[__b], %w[__c]\n"
               // Outputs
               : [__a] "+f"(__a)
               // Inputs
               : [__b] "f"(__b), [__c] "f"(__c));
  return __a;
}

__extension__ extern __inline v4f32
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mlaq_f32(v4f32 __a, v4f32 __b, v4f32 __c)
{
  asm volatile("fmadd.w %w[__a], %w[__b], %w[__c]\n"
               // Outputs
               : [__a] "+f"(__a)
               // Inputs
               : [__b] "f"(__b), [__c] "f"(__c));
  return __a;
}

__extension__ extern __inline v2f64
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_mlaq_f64(v2f64 __a, v2f64 __b, v2f64 __c)
{
  asm volatile("fmadd.d %w[__a], %w[__b], %w[__c]\n"
               // Outputs
               : [__a] "+f"(__a)
               // Inputs
               : [__b] "f"(__b), [__c] "f"(__c));
  return __a;
}
#endif

/* cntq */
#define msa_cntq_s8           __builtin_msa_pcnt_b
#define msa_cntq_s16          __builtin_msa_pcnt_h
#define msa_cntq_s32          __builtin_msa_pcnt_w
#define msa_cntq_s64          __builtin_msa_pcnt_d

/* bslq (a: mask; r = b(if a == 0); r = c(if a == 1);) */
#define msa_bslq_u8           __builtin_msa_bsel_v

/* ilvrq, ilvlq (For EL only, ilvrq: b0, a0, b1, a1; ilvlq: b2, a2, b3, a3;) */
#define msa_ilvrq_s8          __builtin_msa_ilvr_b
#define msa_ilvrq_s16         __builtin_msa_ilvr_h
#define msa_ilvrq_s32         __builtin_msa_ilvr_w
#define msa_ilvrq_s64         __builtin_msa_ilvr_d
#define msa_ilvlq_s8          __builtin_msa_ilvl_b
#define msa_ilvlq_s16         __builtin_msa_ilvl_h
#define msa_ilvlq_s32         __builtin_msa_ilvl_w
#define msa_ilvlq_s64         __builtin_msa_ilvl_d

/* ilvevq, ilvodq (ilvevq: b0, a0, b2, a2; ilvodq: b1, a1, b3, a3; ) */
#define msa_ilvevq_s8         __builtin_msa_ilvev_b
#define msa_ilvevq_s16        __builtin_msa_ilvev_h
#define msa_ilvevq_s32        __builtin_msa_ilvev_w
#define msa_ilvevq_s64        __builtin_msa_ilvev_d
#define msa_ilvodq_s8         __builtin_msa_ilvod_b
#define msa_ilvodq_s16        __builtin_msa_ilvod_h
#define msa_ilvodq_s32        __builtin_msa_ilvod_w
#define msa_ilvodq_s64        __builtin_msa_ilvod_d

/* extq (r = (a || b); a concatenation b and get elements from index c) */
#if 0
#ifdef _MIPSEB
#define msa_extq_s8(a, b, c)  __builtin_msa_vshf_b((v16i8){16-c, 17-c, 18-c, 19-c, 20-c, 21-c, 22-c, 23-c, 24-c, 25-c, 26-c, 27-c, 28-c, 29-c, 30-c, 31-c}, a, b)
#define msa_extq_s16(a, b, c) __builtin_msa_vshf_h((v8i16){8-c, 9-c, 10-c, 11-c, 12-c, 13-c, 14-c, 15-c}, a, b)
#define msa_extq_s32(a, b, c) __builtin_msa_vshf_w((v4i32){4-c, 5-c, 6-c, 7-c}, a, b)
#define msa_extq_s64(a, b, c) __builtin_msa_vshf_d((v2i64){2-c, 3-c}, a, b)
#else
#define msa_extq_s8(a, b, c)  __builtin_msa_vshf_b((v16i8){c, c+1, c+2, c+3, c+4, c+5, c+6, c+7, c+8, c+9, c+10, c+11, c+12, c+13, c+14, c+15}, b, a)
#define msa_extq_s16(a, b, c) __builtin_msa_vshf_h((v8i16){c, c+1, c+2, c+3, c+4, c+5, c+6, c+7}, b, a)
#define msa_extq_s32(a, b, c) __builtin_msa_vshf_w((v4i32){c, c+1, c+2, c+3}, b, a)
#define msa_extq_s64(a, b, c) __builtin_msa_vshf_d((v2i64){c, c+1}, b, a)
#endif /* _MIPSEB */
#else
#ifdef _MIPSEB
#define msa_extq_s8(a, b, c)  __builtin_msa_vshf_b(__builtin_msa_subv_b((v16i8)((v2i64){0x1716151413121110, 0x1F1E1D1C1B1A1918}), __builtin_msa_fill_b(c)), a, b)
#define msa_extq_s16(a, b, c) __builtin_msa_vshf_h(__builtin_msa_subv_h((v8i16)((v2i64){0x000B000A00090008, 0x000F000E000D000C}), __builtin_msa_fill_h(c)), a, b)
#define msa_extq_s32(a, b, c) __builtin_msa_vshf_w(__builtin_msa_subv_w((v4i32)((v2i64){0x0000000500000004, 0x0000000700000006}), __builtin_msa_fill_w(c)), a, b)
#define msa_extq_s64(a, b, c) __builtin_msa_vshf_d(__builtin_msa_subv_d((v2i64){0x0000000000000002, 0x0000000000000003}, __builtin_msa_fill_d(c)), a, b)
#else
#define msa_extq_s8(a, b, c)  __builtin_msa_vshf_b(__builtin_msa_addv_b((v16i8)((v2i64){0x0706050403020100, 0x0F0E0D0C0B0A0908}), __builtin_msa_fill_b(c)), b, a)
#define msa_extq_s16(a, b, c) __builtin_msa_vshf_h(__builtin_msa_addv_h((v8i16)((v2i64){0x0003000200010000, 0x0007000600050004}), __builtin_msa_fill_h(c)), b, a)
#define msa_extq_s32(a, b, c) __builtin_msa_vshf_w(__builtin_msa_addv_w((v4i32)((v2i64){0x0000000100000000, 0x0000000300000002}), __builtin_msa_fill_w(c)), b, a)
#define msa_extq_s64(a, b, c) __builtin_msa_vshf_d(__builtin_msa_addv_d((v2i64){0x0000000000000000, 0x0000000000000001}, __builtin_msa_fill_d(c)), b, a)
#endif /* _MIPSEB */
#endif

/* cvttruncq, cvttintq, cvtrintq */
#define msa_cvttruncq_u32_f32 __builtin_msa_ftrunc_u_w
#define msa_cvttruncq_s32_f32 __builtin_msa_ftrunc_s_w
#define msa_cvttruncq_u64_f64 __builtin_msa_ftrunc_u_d
#define msa_cvttruncq_s64_f64 __builtin_msa_ftrunc_s_d
#define msa_cvttintq_u32_f32  __builtin_msa_ftint_u_w
#define msa_cvttintq_s32_f32  __builtin_msa_ftint_s_w
#define msa_cvttintq_u64_f64  __builtin_msa_ftint_u_d
#define msa_cvttintq_s64_f64  __builtin_msa_ftint_s_d
#define msa_cvtrintq_f32      __builtin_msa_frint_w
#define msa_cvtrintq_f64      __builtin_msa_frint_d

/* cvtfintq, cvtfq */
#define msa_cvtfintq_f32_u32  __builtin_msa_ffint_u_w
#define msa_cvtfintq_f32_s32  __builtin_msa_ffint_s_w
#define msa_cvtfintq_f64_u64  __builtin_msa_ffint_u_d
#define msa_cvtfintq_f64_s64  __builtin_msa_ffint_s_d
#define msa_cvtfq_f32_f64     __builtin_msa_fexdo_w
#define msa_cvtflq_f64_f32    __builtin_msa_fexupr_d
#define msa_cvtfhq_f64_f32    __builtin_msa_fexupl_d

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* OPENCV_CORE_MSA_MACROS_H */
