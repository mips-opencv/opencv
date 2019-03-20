/*M///////////////////////////////////////////////////////////////////////////////////////
//
//  IMPORTANT: READ BEFORE DOWNLOADING, COPYING, INSTALLING OR USING.
//
//  By downloading, copying, installing or using the software you agree to this license.
//  If you do not agree to this license, do not download, install,
//  copy or use the software.
//
//
//                          License Agreement
//                For Open Source Computer Vision Library
//
// Copyright (C) 2000-2008, Intel Corporation, all rights reserved.
// Copyright (C) 2009, Willow Garage Inc., all rights reserved.
// Copyright (C) 2013, OpenCV Foundation, all rights reserved.
// Copyright (C) 2015, Itseez Inc., all rights reserved.
// Third party copyrights are property of their respective owners.
//
// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:
//
//   * Redistribution's of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//
//   * Redistribution's in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//
//   * The name of the copyright holders may not be used to endorse or promote products
//     derived from this software without specific prior written permission.
//
// This software is provided by the copyright holders and contributors "as is" and
// any express or implied warranties, including, but not limited to, the implied
// warranties of merchantability and fitness for a particular purpose are disclaimed.
// In no event shall the Intel Corporation or contributors be liable for any direct,
// indirect, incidental, special, exemplary, or consequential damages
// (including, but not limited to, procurement of substitute goods or services;
// loss of use, data, or profits; or business interruption) however caused
// and on any theory of liability, whether in contract, strict liability,
// or tort (including negligence or otherwise) arising in any way out of
// the use of this software, even if advised of the possibility of such damage.
//
//M*/

#ifndef OPENCV_HAL_INTRIN_MSA_HPP
#define OPENCV_HAL_INTRIN_MSA_HPP

#include <algorithm>
#include "opencv2/core/utility.hpp"
#include "opencv2/core/hal/msa_macros.h"

namespace cv
{

//! @cond IGNORED
CV_CPU_OPTIMIZATION_HAL_NAMESPACE_BEGIN

#define CV_SIMD128 1
#define CV_SIMD128_64F 1

#if CV_SIMD128_64F
#define OPENCV_HAL_IMPL_MSA_REINTERPRET(_Tpv, suffix) \
template <typename T> static inline \
_Tpv msa_reinterpretq_##suffix##_f64(T a) { return (_Tpv) a; } \
template <typename T> static inline \
v2f64 msa_reinterpretq_f64_##suffix(T a) { return (v2f64) a; }
OPENCV_HAL_IMPL_MSA_REINTERPRET(v16u8, u8)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v16i8, s8)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v8u16, u16)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v8i16, s16)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v4u32, u32)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v4i32, s32)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v2u64, u64)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v2i64, s64)
OPENCV_HAL_IMPL_MSA_REINTERPRET(v4f32, f32)
#endif

struct v_uint8x16
{
    typedef uchar lane_type;
    enum { nlanes = 16 };

    v_uint8x16() {}
    explicit v_uint8x16(v16u8 v) : val(v) {}
    v_uint8x16(uchar v0, uchar v1, uchar v2, uchar v3, uchar v4, uchar v5, uchar v6, uchar v7,
               uchar v8, uchar v9, uchar v10, uchar v11, uchar v12, uchar v13, uchar v14, uchar v15)
    {
        uchar v[] = {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15};
        val = msa_ld1q_u8(v);
    }
    uchar get0() const
    {
        return msa_getq_lane_u8(val, 0);
    }

    v16u8 val;
};

struct v_int8x16
{
    typedef schar lane_type;
    enum { nlanes = 16 };

    v_int8x16() {}
    explicit v_int8x16(v16i8 v) : val(v) {}
    v_int8x16(schar v0, schar v1, schar v2, schar v3, schar v4, schar v5, schar v6, schar v7,
               schar v8, schar v9, schar v10, schar v11, schar v12, schar v13, schar v14, schar v15)
    {
        schar v[] = {v0, v1, v2, v3, v4, v5, v6, v7, v8, v9, v10, v11, v12, v13, v14, v15};
        val = msa_ld1q_s8(v);
    }
    schar get0() const
    {
        return msa_getq_lane_s8(val, 0);
    }

    v16i8 val;
};

struct v_uint16x8
{
    typedef ushort lane_type;
    enum { nlanes = 8 };

    v_uint16x8() {}
    explicit v_uint16x8(v8u16 v) : val(v) {}
    v_uint16x8(ushort v0, ushort v1, ushort v2, ushort v3, ushort v4, ushort v5, ushort v6, ushort v7)
    {
        ushort v[] = {v0, v1, v2, v3, v4, v5, v6, v7};
        val = msa_ld1q_u16(v);
    }
    ushort get0() const
    {
        return msa_getq_lane_u16(val, 0);
    }

    v8u16 val;
};

struct v_int16x8
{
    typedef short lane_type;
    enum { nlanes = 8 };

    v_int16x8() {}
    explicit v_int16x8(v8i16 v) : val(v) {}
    v_int16x8(short v0, short v1, short v2, short v3, short v4, short v5, short v6, short v7)
    {
        short v[] = {v0, v1, v2, v3, v4, v5, v6, v7};
        val = msa_ld1q_s16(v);
    }
    short get0() const
    {
        return msa_getq_lane_s16(val, 0);
    }

    v8i16 val;
};

struct v_uint32x4
{
    typedef unsigned int lane_type;
    enum { nlanes = 4 };

    v_uint32x4() {}
    explicit v_uint32x4(v4u32 v) : val(v) {}
    v_uint32x4(unsigned int v0, unsigned int v1, unsigned int v2, unsigned int v3)
    {
        unsigned int v[] = {v0, v1, v2, v3};
        val = msa_ld1q_u32(v);
    }
    unsigned int get0() const
    {
        return msa_getq_lane_u32(val, 0);
    }

    v4u32 val;
};

struct v_int32x4
{
    typedef int lane_type;
    enum { nlanes = 4 };

    v_int32x4() {}
    explicit v_int32x4(v4i32 v) : val(v) {}
    v_int32x4(int v0, int v1, int v2, int v3)
    {
        int v[] = {v0, v1, v2, v3};
        val = msa_ld1q_s32(v);
    }
    int get0() const
    {
        return msa_getq_lane_s32(val, 0);
    }
    v4i32 val;
};

struct v_float32x4
{
    typedef float lane_type;
    enum { nlanes = 4 };

    v_float32x4() {}
    explicit v_float32x4(v4f32 v) : val(v) {}
    v_float32x4(float v0, float v1, float v2, float v3)
    {
        float v[] = {v0, v1, v2, v3};
        val = msa_ld1q_f32(v);
    }
    float get0() const
    {
        return msa_getq_lane_f32(val, 0);
    }
    v4f32 val;
};

struct v_uint64x2
{
    typedef uint64 lane_type;
    enum { nlanes = 2 };

    v_uint64x2() {}
    explicit v_uint64x2(v2u64 v) : val(v) {}
    v_uint64x2(uint64 v0, uint64 v1)
    {
        uint64 v[] = {v0, v1};
        val = msa_ld1q_u64(v);
    }
    uint64 get0() const
    {
        return msa_getq_lane_u64(val, 0);
    }
    v2u64 val;
};

struct v_int64x2
{
    typedef int64 lane_type;
    enum { nlanes = 2 };

    v_int64x2() {}
    explicit v_int64x2(v2i64 v) : val(v) {}
    v_int64x2(int64 v0, int64 v1)
    {
        int64 v[] = {v0, v1};
        val = msa_ld1q_s64(v);
    }
    int64 get0() const
    {
        return msa_getq_lane_s64(val, 0);
    }
    v2i64 val;
};

struct v_float64x2
{
    typedef double lane_type;
    enum { nlanes = 2 };

    v_float64x2() {}
    explicit v_float64x2(v2f64 v) : val(v) {}
    v_float64x2(double v0, double v1)
    {
        double v[] = {v0, v1};
        val = msa_ld1q_f64(v);
    }
    double get0() const
    {
        return msa_getq_lane_f64(val, 0);
    }
    v2f64 val;
};

#define OPENCV_HAL_IMPL_MSA_INIT(_Tpv, _Tpv2, _Tp, suffix) \
inline v_##_Tpv v_setzero_##suffix() { return v_##_Tpv(msa_dupq_n_##suffix((_Tp)0)); } \
inline v_##_Tpv v_setall_##suffix(_Tp v) { return v_##_Tpv(msa_dupq_n_##suffix(v)); } \
inline _Tpv2 msa_reinterpretq_##suffix##_##suffix(_Tpv2 v) { return v; } \
inline v_uint8x16 v_reinterpret_as_u8(const v_##_Tpv& v) { return v_uint8x16(msa_reinterpretq_u8_##suffix(v.val)); } \
inline v_int8x16 v_reinterpret_as_s8(const v_##_Tpv& v) { return v_int8x16(msa_reinterpretq_s8_##suffix(v.val)); } \
inline v_uint16x8 v_reinterpret_as_u16(const v_##_Tpv& v) { return v_uint16x8(msa_reinterpretq_u16_##suffix(v.val)); } \
inline v_int16x8 v_reinterpret_as_s16(const v_##_Tpv& v) { return v_int16x8(msa_reinterpretq_s16_##suffix(v.val)); } \
inline v_uint32x4 v_reinterpret_as_u32(const v_##_Tpv& v) { return v_uint32x4(msa_reinterpretq_u32_##suffix(v.val)); } \
inline v_int32x4 v_reinterpret_as_s32(const v_##_Tpv& v) { return v_int32x4(msa_reinterpretq_s32_##suffix(v.val)); } \
inline v_uint64x2 v_reinterpret_as_u64(const v_##_Tpv& v) { return v_uint64x2(msa_reinterpretq_u64_##suffix(v.val)); } \
inline v_int64x2 v_reinterpret_as_s64(const v_##_Tpv& v) { return v_int64x2(msa_reinterpretq_s64_##suffix(v.val)); } \
inline v_float32x4 v_reinterpret_as_f32(const v_##_Tpv& v) { return v_float32x4(msa_reinterpretq_f32_##suffix(v.val)); }

OPENCV_HAL_IMPL_MSA_INIT(uint8x16, v16u8, uchar, u8)
OPENCV_HAL_IMPL_MSA_INIT(int8x16, v16i8, schar, s8)
OPENCV_HAL_IMPL_MSA_INIT(uint16x8, v8u16, ushort, u16)
OPENCV_HAL_IMPL_MSA_INIT(int16x8, v8i16, short, s16)
OPENCV_HAL_IMPL_MSA_INIT(uint32x4, v4u32, unsigned int, u32)
OPENCV_HAL_IMPL_MSA_INIT(int32x4, v4i32, int, s32)
OPENCV_HAL_IMPL_MSA_INIT(uint64x2, v2u64, uint64, u64)
OPENCV_HAL_IMPL_MSA_INIT(int64x2, v2i64, int64, s64)
OPENCV_HAL_IMPL_MSA_INIT(float32x4, v4f32, float, f32)
#if CV_SIMD128_64F
#define OPENCV_HAL_IMPL_MSA_INIT_64(_Tpv, suffix) \
inline v_float64x2 v_reinterpret_as_f64(const v_##_Tpv& v) { return v_float64x2(msa_reinterpretq_f64_##suffix(v.val)); }
OPENCV_HAL_IMPL_MSA_INIT(float64x2, v2f64, double, f64)
OPENCV_HAL_IMPL_MSA_INIT_64(uint8x16, u8)
OPENCV_HAL_IMPL_MSA_INIT_64(int8x16, s8)
OPENCV_HAL_IMPL_MSA_INIT_64(uint16x8, u16)
OPENCV_HAL_IMPL_MSA_INIT_64(int16x8, s16)
OPENCV_HAL_IMPL_MSA_INIT_64(uint32x4, u32)
OPENCV_HAL_IMPL_MSA_INIT_64(int32x4, s32)
OPENCV_HAL_IMPL_MSA_INIT_64(uint64x2, u64)
OPENCV_HAL_IMPL_MSA_INIT_64(int64x2, s64)
OPENCV_HAL_IMPL_MSA_INIT_64(float32x4, f32)
OPENCV_HAL_IMPL_MSA_INIT_64(float64x2, f64)
#endif

#define OPENCV_HAL_IMPL_MSA_PACK(_Tpvec, _Tp, hreg, suffix, _Tpwvec, pack, mov, rshr) \
inline _Tpvec v_##pack(const _Tpwvec& a, const _Tpwvec& b) \
{ \
    hreg a1 = mov(a.val), b1 = mov(b.val); \
    return _Tpvec(msa_combine_##suffix(a1, b1)); \
} \
inline void v_##pack##_store(_Tp* ptr, const _Tpwvec& a) \
{ \
    hreg a1 = mov(a.val); \
    msa_st1_##suffix(ptr, a1); \
} \
template<int n> inline \
_Tpvec v_rshr_##pack(const _Tpwvec& a, const _Tpwvec& b) \
{ \
    hreg a1 = rshr(a.val, n); \
    hreg b1 = rshr(b.val, n); \
    return _Tpvec(msa_combine_##suffix(a1, b1)); \
} \
template<int n> inline \
void v_rshr_##pack##_store(_Tp* ptr, const _Tpwvec& a) \
{ \
    hreg a1 = rshr(a.val, n); \
    msa_st1_##suffix(ptr, a1); \
}

OPENCV_HAL_IMPL_MSA_PACK(v_uint8x16, uchar, v8u8, u8, v_uint16x8, pack, msa_qmovn_u16, msa_qrshrn_n_u16)
OPENCV_HAL_IMPL_MSA_PACK(v_int8x16, schar, v8i8, s8, v_int16x8, pack, msa_qmovn_s16, msa_qrshrn_n_s16)
OPENCV_HAL_IMPL_MSA_PACK(v_uint16x8, ushort, v4u16, u16, v_uint32x4, pack, msa_qmovn_u32, msa_qrshrn_n_u32)
OPENCV_HAL_IMPL_MSA_PACK(v_int16x8, short, v4i16, s16, v_int32x4, pack, msa_qmovn_s32, msa_qrshrn_n_s32)
OPENCV_HAL_IMPL_MSA_PACK(v_uint32x4, unsigned, v2u32, u32, v_uint64x2, pack, msa_movn_u64, msa_rshrn_n_u64)
OPENCV_HAL_IMPL_MSA_PACK(v_int32x4, int, v2i32, s32, v_int64x2, pack, msa_movn_s64, msa_rshrn_n_s64)

OPENCV_HAL_IMPL_MSA_PACK(v_uint8x16, uchar, v8u8, u8, v_int16x8, pack_u, msa_qmovun_s16, msa_qrshrun_n_s16)
OPENCV_HAL_IMPL_MSA_PACK(v_uint16x8, ushort, v4u16, u16, v_int32x4, pack_u, msa_qmovun_s32, msa_qrshrun_n_s32)

// pack boolean
inline v_uint8x16 v_pack_b(const v_uint16x8& a, const v_uint16x8& b)
{
    v16u8 ab = msa_combine_u8(msa_movn_u16(a.val), msa_movn_u16(b.val));
    return v_uint8x16(ab);
}

inline v_uint8x16 v_pack_b(const v_uint32x4& a, const v_uint32x4& b,
                           const v_uint32x4& c, const v_uint32x4& d)
{
    v8u16 nab = msa_combine_u16(msa_movn_u32(a.val), msa_movn_u32(b.val));
    v8u16 ncd = msa_combine_u16(msa_movn_u32(c.val), msa_movn_u32(d.val));
    return v_uint8x16(msa_combine_u8(msa_movn_u16(nab), msa_movn_u16(ncd)));
}

inline v_uint8x16 v_pack_b(const v_uint64x2& a, const v_uint64x2& b, const v_uint64x2& c,
                           const v_uint64x2& d, const v_uint64x2& e, const v_uint64x2& f,
                           const v_uint64x2& g, const v_uint64x2& h)
{
    v4u32 ab = msa_combine_u32(msa_movn_u64(a.val), msa_movn_u64(b.val));
    v4u32 cd = msa_combine_u32(msa_movn_u64(c.val), msa_movn_u64(d.val));
    v4u32 ef = msa_combine_u32(msa_movn_u64(e.val), msa_movn_u64(f.val));
    v4u32 gh = msa_combine_u32(msa_movn_u64(g.val), msa_movn_u64(h.val));

    v8u16 abcd = msa_combine_u16(msa_movn_u32(ab), msa_movn_u32(cd));
    v8u16 efgh = msa_combine_u16(msa_movn_u32(ef), msa_movn_u32(gh));
    return v_uint8x16(msa_combine_u8(msa_movn_u16(abcd), msa_movn_u16(efgh)));
}

inline v_float32x4 v_matmul(const v_float32x4& v, const v_float32x4& m0,
                            const v_float32x4& m1, const v_float32x4& m2,
                            const v_float32x4& m3)
{
    v2f32 vl = msa_get_low_f32(v.val), vh = msa_get_high_f32(v.val);
    v4f32 res = msa_mulq_lane_f32(m0.val, vl, 0);
    res = msa_mlaq_lane_f32(res, m1.val, vl, 1);
    res = msa_mlaq_lane_f32(res, m2.val, vh, 0);
    res = msa_mlaq_lane_f32(res, m3.val, vh, 1);
    return v_float32x4(res);
}

inline v_float32x4 v_matmuladd(const v_float32x4& v, const v_float32x4& m0,
                               const v_float32x4& m1, const v_float32x4& m2,
                               const v_float32x4& a)
{
    v2f32 vl = msa_get_low_f32(v.val), vh = msa_get_high_f32(v.val);
    v4f32 res = msa_mulq_lane_f32(m0.val, vl, 0);
    res = msa_mlaq_lane_f32(res, m1.val, vl, 1);
    res = msa_mlaq_lane_f32(res, m2.val, vh, 0);
    res = msa_addq_f32(res, a.val);
    return v_float32x4(res);
}

#define OPENCV_HAL_IMPL_MSA_BIN_OP(bin_op, _Tpvec, intrin) \
inline _Tpvec operator bin_op (const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec(intrin(a.val, b.val)); \
} \
inline _Tpvec& operator bin_op##= (_Tpvec& a, const _Tpvec& b) \
{ \
    a.val = intrin(a.val, b.val); \
    return a; \
}

OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_uint8x16, msa_qaddq_u8)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_uint8x16, msa_qsubq_u8)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_int8x16, msa_qaddq_s8)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_int8x16, msa_qsubq_s8)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_uint16x8, msa_qaddq_u16)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_uint16x8, msa_qsubq_u16)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_int16x8, msa_qaddq_s16)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_int16x8, msa_qsubq_s16)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_int32x4, msa_addq_s32)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_int32x4, msa_subq_s32)
OPENCV_HAL_IMPL_MSA_BIN_OP(*, v_int32x4, msa_mulq_s32)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_uint32x4, msa_addq_u32)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_uint32x4, msa_subq_u32)
OPENCV_HAL_IMPL_MSA_BIN_OP(*, v_uint32x4, msa_mulq_u32)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_float32x4, msa_addq_f32)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_float32x4, msa_subq_f32)
OPENCV_HAL_IMPL_MSA_BIN_OP(*, v_float32x4, msa_mulq_f32)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_int64x2, msa_addq_s64)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_int64x2, msa_subq_s64)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_uint64x2, msa_addq_u64)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_uint64x2, msa_subq_u64)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_BIN_OP(/, v_float32x4, msa_divq_f32)
OPENCV_HAL_IMPL_MSA_BIN_OP(+, v_float64x2, msa_addq_f64)
OPENCV_HAL_IMPL_MSA_BIN_OP(-, v_float64x2, msa_subq_f64)
OPENCV_HAL_IMPL_MSA_BIN_OP(*, v_float64x2, msa_mulq_f64)
OPENCV_HAL_IMPL_MSA_BIN_OP(/, v_float64x2, msa_divq_f64)
#else
inline v_float32x4 operator / (const v_float32x4& a, const v_float32x4& b)
{
    v4f32_t reciprocal = msa_recpeq_f32(b.val);
    reciprocal = msa_mulq_f32(msa_recpsq_f32(b.val, reciprocal), reciprocal);
    reciprocal = msa_mulq_f32(msa_recpsq_f32(b.val, reciprocal), reciprocal);
    return v_float32x4(msa_mulq_f32(a.val, reciprocal));
}
inline v_float32x4& operator /= (v_float32x4& a, const v_float32x4& b)
{
    v4f32_t reciprocal = msa_recpeq_f32(b.val);
    reciprocal = msa_mulq_f32(msa_recpsq_f32(b.val, reciprocal), reciprocal);
    reciprocal = msa_mulq_f32(msa_recpsq_f32(b.val, reciprocal), reciprocal);
    a.val = msa_mulq_f32(a.val, reciprocal);
    return a;
}
#endif

// saturating multiply 8-bit, 16-bit
#define OPENCV_HAL_IMPL_MSA_MUL_SAT(_Tpvec, _Tpwvec)            \
    inline _Tpvec operator * (const _Tpvec& a, const _Tpvec& b)  \
    {                                                            \
        _Tpwvec c, d;                                            \
        v_mul_expand(a, b, c, d);                                \
        return v_pack(c, d);                                     \
    }                                                            \
    inline _Tpvec& operator *= (_Tpvec& a, const _Tpvec& b)      \
    { a = a * b; return a; }

OPENCV_HAL_IMPL_MSA_MUL_SAT(v_int8x16,  v_int16x8)
OPENCV_HAL_IMPL_MSA_MUL_SAT(v_uint8x16, v_uint16x8)
OPENCV_HAL_IMPL_MSA_MUL_SAT(v_int16x8,  v_int32x4)
OPENCV_HAL_IMPL_MSA_MUL_SAT(v_uint16x8, v_uint32x4)

//  Multiply and expand
inline void v_mul_expand(const v_int8x16& a, const v_int8x16& b,
                         v_int16x8& c, v_int16x8& d)
{
    c.val = msa_mull_s8(msa_get_low_s8(a.val), msa_get_low_s8(b.val));
    d.val = msa_mull_s8(msa_get_high_s8(a.val), msa_get_high_s8(b.val));
}

inline void v_mul_expand(const v_uint8x16& a, const v_uint8x16& b,
                         v_uint16x8& c, v_uint16x8& d)
{
    c.val = msa_mull_u8(msa_get_low_u8(a.val), msa_get_low_u8(b.val));
    d.val = msa_mull_u8(msa_get_high_u8(a.val), msa_get_high_u8(b.val));
}

inline void v_mul_expand(const v_int16x8& a, const v_int16x8& b,
                         v_int32x4& c, v_int32x4& d)
{
    c.val = msa_mull_s16(msa_get_low_s16(a.val), msa_get_low_s16(b.val));
    d.val = msa_mull_s16(msa_get_high_s16(a.val), msa_get_high_s16(b.val));
}

inline void v_mul_expand(const v_uint16x8& a, const v_uint16x8& b,
                         v_uint32x4& c, v_uint32x4& d)
{
    c.val = msa_mull_u16(msa_get_low_u16(a.val), msa_get_low_u16(b.val));
    d.val = msa_mull_u16(msa_get_high_u16(a.val), msa_get_high_u16(b.val));
}

inline void v_mul_expand(const v_uint32x4& a, const v_uint32x4& b,
                         v_uint64x2& c, v_uint64x2& d)
{
    c.val = msa_mull_u32(msa_get_low_u32(a.val), msa_get_low_u32(b.val));
    d.val = msa_mull_u32(msa_get_high_u32(a.val), msa_get_high_u32(b.val));
}

inline v_int16x8 v_mul_hi(const v_int16x8& a, const v_int16x8& b)
{
    return v_int16x8(msa_combine_s16(
                                  msa_shrn_n_s32(msa_mull_s16( msa_get_low_s16(a.val),  msa_get_low_s16(b.val)), 16),
                                  msa_shrn_n_s32(msa_mull_s16(msa_get_high_s16(a.val), msa_get_high_s16(b.val)), 16)
                                 ));
}
inline v_uint16x8 v_mul_hi(const v_uint16x8& a, const v_uint16x8& b)
{
    return v_uint16x8(msa_combine_u16(
                                   msa_shrn_n_u32(msa_mull_u16( msa_get_low_u16(a.val),  msa_get_low_u16(b.val)), 16),
                                   msa_shrn_n_u32(msa_mull_u16(msa_get_high_u16(a.val), msa_get_high_u16(b.val)), 16)
                                  ));
}

inline v_int32x4 v_dotprod(const v_int16x8& a, const v_int16x8& b)
{
    //v4i32_t c = msa_mull_s16(msa_get_low_s16(a.val), msa_get_low_s16(b.val));
    //v4i32_t d = msa_mull_s16(msa_get_high_s16(a.val), msa_get_high_s16(b.val));
    //v4i32x2_t cd = msa_uzpq_s32(c, d);
    //return v_int32x4(msa_addq_s32(cd.val[0], cd.val[1]));
    return v_int32x4(msa_dotp_s_w(a.val, b.val));
}

inline v_int32x4 v_dotprod(const v_int16x8& a, const v_int16x8& b, const v_int32x4& c)
{
    v_int32x4 s = v_dotprod(a, b);
    return v_int32x4(msa_addq_s32(s.val , c.val));
}

#define OPENCV_HAL_IMPL_MSA_LOGIC_OP(_Tpvec, suffix) \
    OPENCV_HAL_IMPL_MSA_BIN_OP(&, _Tpvec, msa_andq_##suffix) \
    OPENCV_HAL_IMPL_MSA_BIN_OP(|, _Tpvec, msa_orrq_##suffix) \
    OPENCV_HAL_IMPL_MSA_BIN_OP(^, _Tpvec, msa_eorq_##suffix) \
    inline _Tpvec operator ~ (const _Tpvec& a) \
    { \
        return _Tpvec(msa_reinterpretq_##suffix##_u8(msa_mvnq_u8(msa_reinterpretq_u8_##suffix(a.val)))); \
    }

OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_uint8x16, u8)
OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_int8x16, s8)
OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_uint16x8, u16)
OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_int16x8, s16)
OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_uint32x4, u32)
OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_int32x4, s32)
OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_uint64x2, u64)
OPENCV_HAL_IMPL_MSA_LOGIC_OP(v_int64x2, s64)

#define OPENCV_HAL_IMPL_MSA_FLT_BIT_OP(bin_op, intrin) \
inline v_float32x4 operator bin_op (const v_float32x4& a, const v_float32x4& b) \
{ \
    return v_float32x4(msa_reinterpretq_f32_s32(intrin(msa_reinterpretq_s32_f32(a.val), msa_reinterpretq_s32_f32(b.val)))); \
} \
inline v_float32x4& operator bin_op##= (v_float32x4& a, const v_float32x4& b) \
{ \
    a.val = msa_reinterpretq_f32_s32(intrin(msa_reinterpretq_s32_f32(a.val), msa_reinterpretq_s32_f32(b.val))); \
    return a; \
}

OPENCV_HAL_IMPL_MSA_FLT_BIT_OP(&, msa_andq_s32)
OPENCV_HAL_IMPL_MSA_FLT_BIT_OP(|, msa_orrq_s32)
OPENCV_HAL_IMPL_MSA_FLT_BIT_OP(^, msa_eorq_s32)

inline v_float32x4 operator ~ (const v_float32x4& a)
{
    return v_float32x4(msa_reinterpretq_f32_s32(msa_mvnq_s32(msa_reinterpretq_s32_f32(a.val))));
}

/* v_abs */
#define OPENCV_HAL_IMPL_MSA_ABS(_Tpuvec, _Tpsvec, usuffix, ssuffix) \
inline _Tpuvec v_abs(const _Tpsvec& a) \
{ \
    return v_reinterpret_as_##usuffix(_Tpsvec(msa_absq_##ssuffix(a.val))); \
}

OPENCV_HAL_IMPL_MSA_ABS(v_uint8x16, v_int8x16, u8, s8)
OPENCV_HAL_IMPL_MSA_ABS(v_uint16x8, v_int16x8, u16, s16)
OPENCV_HAL_IMPL_MSA_ABS(v_uint32x4, v_int32x4, u32, s32)

/* v_abs(float), v_sqrt, v_invsqrt */
#define OPENCV_HAL_IMPL_MSA_BASIC_FUNC(_Tpvec, func, intrin) \
inline _Tpvec func(const _Tpvec& a) \
{ \
    return _Tpvec(intrin(a.val)); \
}

OPENCV_HAL_IMPL_MSA_BASIC_FUNC(v_float32x4, v_abs, msa_absq_f32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_BASIC_FUNC(v_float64x2, v_abs, msa_absq_f64)
OPENCV_HAL_IMPL_MSA_BASIC_FUNC(v_float32x4, v_sqrt, msa_sqrtq_f32)
OPENCV_HAL_IMPL_MSA_BASIC_FUNC(v_float32x4, v_invsqrt, msa_rsqrtq_f32)
OPENCV_HAL_IMPL_MSA_BASIC_FUNC(v_float64x2, v_sqrt, msa_sqrtq_f64)
OPENCV_HAL_IMPL_MSA_BASIC_FUNC(v_float64x2, v_invsqrt, msa_rsqrtq_f64)
#endif

#if CV_SIMD128_64F
#define OPENCV_HAL_IMPL_MSA_DBL_BIT_OP(bin_op, intrin) \
inline v_float64x2 operator bin_op (const v_float64x2& a, const v_float64x2& b) \
{ \
    return v_float64x2(msa_reinterpretq_f64_s64(intrin(msa_reinterpretq_s64_f64(a.val), msa_reinterpretq_s64_f64(b.val)))); \
} \
inline v_float64x2& operator bin_op##= (v_float64x2& a, const v_float64x2& b) \
{ \
    a.val = msa_reinterpretq_f64_s64(intrin(msa_reinterpretq_s64_f64(a.val), msa_reinterpretq_s64_f64(b.val))); \
    return a; \
}

OPENCV_HAL_IMPL_MSA_DBL_BIT_OP(&, msa_andq_s64)
OPENCV_HAL_IMPL_MSA_DBL_BIT_OP(|, msa_orrq_s64)
OPENCV_HAL_IMPL_MSA_DBL_BIT_OP(^, msa_eorq_s64)

inline v_float64x2 operator ~ (const v_float64x2& a)
{
    return v_float64x2(msa_reinterpretq_f64_s32(msa_mvnq_s32(msa_reinterpretq_s32_f64(a.val))));
}
#endif

// TODO: exp, log, sin, cos

#define OPENCV_HAL_IMPL_MSA_BIN_FUNC(_Tpvec, func, intrin) \
inline _Tpvec func(const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec(intrin(a.val, b.val)); \
}

OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint8x16, v_min, msa_minq_u8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint8x16, v_max, msa_maxq_u8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int8x16, v_min, msa_minq_s8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int8x16, v_max, msa_maxq_s8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint16x8, v_min, msa_minq_u16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint16x8, v_max, msa_maxq_u16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int16x8, v_min, msa_minq_s16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int16x8, v_max, msa_maxq_s16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint32x4, v_min, msa_minq_u32)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint32x4, v_max, msa_maxq_u32)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int32x4, v_min, msa_minq_s32)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int32x4, v_max, msa_maxq_s32)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_float32x4, v_min, msa_minq_f32)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_float32x4, v_max, msa_maxq_f32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_float64x2, v_min, msa_minq_f64)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_float64x2, v_max, msa_maxq_f64)
#endif

#define OPENCV_HAL_IMPL_MSA_INT_CMP_OP(_Tpvec, cast, suffix, not_suffix) \
inline _Tpvec operator == (const _Tpvec& a, const _Tpvec& b) \
{ return _Tpvec(cast(msa_ceqq_##suffix(a.val, b.val))); } \
inline _Tpvec operator != (const _Tpvec& a, const _Tpvec& b) \
{ return _Tpvec(cast(msa_mvnq_##not_suffix(msa_ceqq_##suffix(a.val, b.val)))); } \
inline _Tpvec operator < (const _Tpvec& a, const _Tpvec& b) \
{ return _Tpvec(cast(msa_cltq_##suffix(a.val, b.val))); } \
inline _Tpvec operator > (const _Tpvec& a, const _Tpvec& b) \
{ return _Tpvec(cast(msa_cgtq_##suffix(a.val, b.val))); } \
inline _Tpvec operator <= (const _Tpvec& a, const _Tpvec& b) \
{ return _Tpvec(cast(msa_cleq_##suffix(a.val, b.val))); } \
inline _Tpvec operator >= (const _Tpvec& a, const _Tpvec& b) \
{ return _Tpvec(cast(msa_cgeq_##suffix(a.val, b.val))); }

OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_uint8x16, OPENCV_HAL_NOP, u8, u8)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_int8x16, msa_reinterpretq_s8_u8, s8, u8)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_uint16x8, OPENCV_HAL_NOP, u16, u16)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_int16x8, msa_reinterpretq_s16_u16, s16, u16)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_uint32x4, OPENCV_HAL_NOP, u32, u32)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_int32x4, msa_reinterpretq_s32_u32, s32, u32)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_float32x4, msa_reinterpretq_f32_u32, f32, u32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_uint64x2, OPENCV_HAL_NOP, u64, u64)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_int64x2, msa_reinterpretq_s64_u64, s64, u64)
OPENCV_HAL_IMPL_MSA_INT_CMP_OP(v_float64x2, msa_reinterpretq_f64_u64, f64, u64)
#endif

inline v_float32x4 v_not_nan(const v_float32x4& a)
{ return v_float32x4(msa_reinterpretq_f32_u32(msa_ceqq_f32(a.val, a.val))); }
#if CV_SIMD128_64F
inline v_float64x2 v_not_nan(const v_float64x2& a)
{ return v_float64x2(msa_reinterpretq_f64_u64(msa_ceqq_f64(a.val, a.val))); }
#endif

OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint8x16, v_add_wrap, msa_addq_u8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int8x16, v_add_wrap, msa_addq_s8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint16x8, v_add_wrap, msa_addq_u16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int16x8, v_add_wrap, msa_addq_s16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint8x16, v_sub_wrap, msa_subq_u8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int8x16, v_sub_wrap, msa_subq_s8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint16x8, v_sub_wrap, msa_subq_u16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int16x8, v_sub_wrap, msa_subq_s16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint8x16, v_mul_wrap, msa_mulq_u8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int8x16, v_mul_wrap, msa_mulq_s8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint16x8, v_mul_wrap, msa_mulq_u16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int16x8, v_mul_wrap, msa_mulq_s16)

OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint8x16, v_absdiff, msa_abdq_u8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint16x8, v_absdiff, msa_abdq_u16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_uint32x4, v_absdiff, msa_abdq_u32)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_float32x4, v_absdiff, msa_abdq_f32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_float64x2, v_absdiff, msa_abdq_f64)
#endif

/** Saturating absolute difference **/
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int8x16, v_absdiffs, msa_qabdq_s8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC(v_int16x8, v_absdiffs, msa_qabdq_s16)

#define OPENCV_HAL_IMPL_MSA_BIN_FUNC2(_Tpvec, _Tpvec2, cast, func, intrin) \
inline _Tpvec2 func(const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec2(cast(intrin(a.val, b.val))); \
}

OPENCV_HAL_IMPL_MSA_BIN_FUNC2(v_int8x16, v_uint8x16, msa_reinterpretq_u8_s8, v_absdiff, msa_abdq_s8)
OPENCV_HAL_IMPL_MSA_BIN_FUNC2(v_int16x8, v_uint16x8, msa_reinterpretq_u16_s16, v_absdiff, msa_abdq_s16)
OPENCV_HAL_IMPL_MSA_BIN_FUNC2(v_int32x4, v_uint32x4, msa_reinterpretq_u32_s32, v_absdiff, msa_abdq_s32)

/* v_magnitude, v_sqr_magnitude, v_fma, v_muladd */
#if 0 /* For GCC */
inline v_float32x4 v_magnitude(const v_float32x4& a, const v_float32x4& b)
{
    v_float32x4 x(msa_mlaq_f32(b.val, b.val, msa_mulq_f32(a.val, a.val)));
    return v_sqrt(x);
}

inline v_float32x4 v_sqr_magnitude(const v_float32x4& a, const v_float32x4& b)
{
    return v_float32x4(msa_mlaq_f32(b.val, b.val, msa_mulq_f32(a.val, a.val)));
}

inline v_float32x4 v_fma(const v_float32x4& a, const v_float32x4& b, const v_float32x4& c)
{
    return v_float32x4(msa_mlaq_f32(a.val, b.val, c.val));
}

inline v_int32x4 v_fma(const v_int32x4& a, const v_int32x4& b, const v_int32x4& c)
{
    return v_int32x4(msa_mlaq_s32(a.val, b.val, c.val));
}
#else /* For ASM */
inline v_float32x4 v_magnitude(const v_float32x4& a, const v_float32x4& b)
{
    v_float32x4 x(msa_mlaq_f32(msa_mulq_f32(a.val, a.val), b.val, b.val));
    return v_sqrt(x);
}

inline v_float32x4 v_sqr_magnitude(const v_float32x4& a, const v_float32x4& b)
{
    return v_float32x4(msa_mlaq_f32(msa_mulq_f32(a.val, a.val), b.val, b.val));
}

inline v_float32x4 v_fma(const v_float32x4& a, const v_float32x4& b, const v_float32x4& c)
{
    return v_float32x4(msa_mlaq_f32(c.val, a.val, b.val));
}

inline v_int32x4 v_fma(const v_int32x4& a, const v_int32x4& b, const v_int32x4& c)
{
    return v_int32x4(msa_mlaq_s32(c.val, a.val, b.val));
}
#endif /* 0 */

inline v_float32x4 v_muladd(const v_float32x4& a, const v_float32x4& b, const v_float32x4& c)
{
    return v_fma(a, b, c);
}

inline v_int32x4 v_muladd(const v_int32x4& a, const v_int32x4& b, const v_int32x4& c)
{
    return v_fma(a, b, c);
}

#if CV_SIMD128_64F
#if 0 /* For GCC */
inline v_float64x2 v_magnitude(const v_float64x2& a, const v_float64x2& b)
{
    v_float64x2 x(msa_mlaq_f64(b.val, b.val, msa_mulq_f64(a.val, a.val)));
    return v_sqrt(x);
}

inline v_float64x2 v_sqr_magnitude(const v_float64x2& a, const v_float64x2& b)
{
    return v_float64x2(msa_mlaq_f64(b.val, b.val, msa_mulq_f64(a.val, a.val)));
}

inline v_float64x2 v_fma(const v_float64x2& a, const v_float64x2& b, const v_float64x2& c)
{
    return v_float64x2(msa_mlaq_f64(a.val, b.val, c.val));
}
#else /* For ASM */
inline v_float64x2 v_magnitude(const v_float64x2& a, const v_float64x2& b)
{
    v_float64x2 x(msa_mlaq_f64(msa_mulq_f64(a.val, a.val), b.val, b.val));
    return v_sqrt(x);
}

inline v_float64x2 v_sqr_magnitude(const v_float64x2& a, const v_float64x2& b)
{
    return v_float64x2(msa_mlaq_f64(msa_mulq_f64(a.val, a.val), b.val, b.val));
}

inline v_float64x2 v_fma(const v_float64x2& a, const v_float64x2& b, const v_float64x2& c)
{
    return v_float64x2(msa_mlaq_f64(c.val, a.val, b.val));
}
#endif /* 0 */

inline v_float64x2 v_muladd(const v_float64x2& a, const v_float64x2& b, const v_float64x2& c)
{
    return v_fma(a, b, c);
}
#endif

// trade efficiency for convenience
#define OPENCV_HAL_IMPL_MSA_SHIFT_OP(_Tpvec, suffix, _Tps, ssuffix) \
inline _Tpvec operator << (const _Tpvec& a, int n) \
{ return _Tpvec(msa_shlq_##suffix(a.val, msa_dupq_n_##ssuffix((_Tps)n))); } \
inline _Tpvec operator >> (const _Tpvec& a, int n) \
{ return _Tpvec(msa_shrq_##suffix(a.val, msa_dupq_n_##ssuffix((_Tps)n))); } \
template<int n> inline _Tpvec v_shl(const _Tpvec& a) \
{ return _Tpvec(msa_shlq_n_##suffix(a.val, n)); } \
template<int n> inline _Tpvec v_shr(const _Tpvec& a) \
{ return _Tpvec(msa_shrq_n_##suffix(a.val, n)); } \
template<int n> inline _Tpvec v_rshr(const _Tpvec& a) \
{ return _Tpvec(msa_rshrq_n_##suffix(a.val, n)); }

OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_uint8x16, u8, schar, s8)
OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_int8x16, s8, schar, s8)
OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_uint16x8, u16, short, s16)
OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_int16x8, s16, short, s16)
OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_uint32x4, u32, int, s32)
OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_int32x4, s32, int, s32)
OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_uint64x2, u64, int64, s64)
OPENCV_HAL_IMPL_MSA_SHIFT_OP(v_int64x2, s64, int64, s64)

/* v_rotate_right, v_rotate_left */
#define OPENCV_HAL_IMPL_MSA_ROTATE_OP(_Tpvec, suffix, ssuffix) \
template<int n> inline _Tpvec v_rotate_right(const _Tpvec& a) \
{ \
    return _Tpvec(msa_reinterpretq_##suffix##_##ssuffix(msa_extq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a.val), msa_dupq_n_##ssuffix(0), n))); \
} \
template<int n> inline _Tpvec v_rotate_left(const _Tpvec& a) \
{ \
    return _Tpvec(msa_reinterpretq_##suffix##_##ssuffix(msa_extq_##ssuffix(msa_dupq_n_##ssuffix(0), msa_reinterpretq_##ssuffix##_##suffix(a.val), _Tpvec::nlanes - n))); \
} \
template<> inline _Tpvec v_rotate_left<0>(const _Tpvec& a) \
{ \
    return a; \
} \
template<int n> inline _Tpvec v_rotate_right(const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec(msa_reinterpretq_##suffix##_##ssuffix(msa_extq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a.val), msa_reinterpretq_##ssuffix##_##suffix(b.val), n))); \
} \
template<int n> inline _Tpvec v_rotate_left(const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec(msa_reinterpretq_##suffix##_##ssuffix(msa_extq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a.val), msa_reinterpretq_##ssuffix##_##suffix(b.val), _Tpvec::nlanes - n))); \
} \
template<> inline _Tpvec v_rotate_left<0>(const _Tpvec& a, const _Tpvec& b) \
{ \
    CV_UNUSED(b); \
    return a; \
}

OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_uint8x16, u8, s8)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_int8x16, s8, s8)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_uint16x8, u16, s16)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_int16x8, s16, s16)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_uint32x4, u32, s32)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_int32x4, s32, s32)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_float32x4, f32, s32)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_uint64x2, u64, s64)
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_int64x2, s64, s64)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_ROTATE_OP(v_float64x2, f64, s64)
#endif

#define OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(_Tpvec, _Tp, suffix) \
inline _Tpvec v_load(const _Tp* ptr) \
{ return _Tpvec(msa_ld1q_##suffix(ptr)); } \
inline _Tpvec v_load_aligned(const _Tp* ptr) \
{ return _Tpvec(msa_ld1q_##suffix(ptr)); } \
inline _Tpvec v_load_low(const _Tp* ptr) \
{ return _Tpvec(msa_combine_##suffix(msa_ld1_##suffix(ptr), msa_dup_n_##suffix((_Tp)0))); } \
inline _Tpvec v_load_halves(const _Tp* ptr0, const _Tp* ptr1) \
{ return _Tpvec(msa_combine_##suffix(msa_ld1_##suffix(ptr0), msa_ld1_##suffix(ptr1))); } \
inline void v_store(_Tp* ptr, const _Tpvec& a) \
{ msa_st1q_##suffix(ptr, a.val); } \
inline void v_store_aligned(_Tp* ptr, const _Tpvec& a) \
{ msa_st1q_##suffix(ptr, a.val); } \
inline void v_store_aligned_nocache(_Tp* ptr, const _Tpvec& a) \
{ msa_st1q_##suffix(ptr, a.val); } \
inline void v_store(_Tp* ptr, const _Tpvec& a, hal::StoreMode /*mode*/) \
{ msa_st1q_##suffix(ptr, a.val); } \
inline void v_store_low(_Tp* ptr, const _Tpvec& a) \
{ msa_st1_##suffix(ptr, msa_get_low_##suffix(a.val)); } \
inline void v_store_high(_Tp* ptr, const _Tpvec& a) \
{ msa_st1_##suffix(ptr, msa_get_high_##suffix(a.val)); }

OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_uint8x16, uchar, u8)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_int8x16, schar, s8)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_uint16x8, ushort, u16)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_int16x8, short, s16)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_uint32x4, unsigned, u32)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_int32x4, int, s32)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_uint64x2, uint64, u64)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_int64x2, int64, s64)
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_float32x4, float, f32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_LOADSTORE_OP(v_float64x2, double, f64)
#endif

#define OPENCV_HAL_IMPL_MSA_REDUCE_OP_8(_Tpvec, _Tpnvec, scalartype, func, vectorfunc, suffix) \
inline scalartype v_reduce_##func(const _Tpvec& a) \
{ \
    _Tpnvec a0 = msa_p##vectorfunc##_##suffix(msa_get_low_##suffix(a.val), msa_get_high_##suffix(a.val)); \
    a0 = msa_p##vectorfunc##_##suffix(a0, a0); \
    return (scalartype)msa_get_lane_##suffix(msa_p##vectorfunc##_##suffix(a0, a0),0); \
}

//OPENCV_HAL_IMPL_MSA_REDUCE_OP_8(v_uint16x8, v4u16, unsigned short, sum, add, u16)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_8(v_uint16x8, v4u16, unsigned short, max, max, u16)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_8(v_uint16x8, v4u16, unsigned short, min, min, u16)
//OPENCV_HAL_IMPL_MSA_REDUCE_OP_8(v_int16x8, v4i16, short, sum, add, s16)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_8(v_int16x8, v4i16, short, max, max, s16)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_8(v_int16x8, v4i16, short, min, min, s16)

#define OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(_Tpvec, _Tpnvec, scalartype, func, vectorfunc, suffix) \
inline scalartype v_reduce_##func(const _Tpvec& a) \
{ \
    _Tpnvec a0 = msa_p##vectorfunc##_##suffix(msa_get_low_##suffix(a.val), msa_get_high_##suffix(a.val)); \
    return (scalartype)msa_get_lane_##suffix(msa_p##vectorfunc##_##suffix(a0, msa_get_high_##suffix(a.val)),0); \
}

//OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_uint32x4, v2u32, unsigned, sum, add, u32)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_uint32x4, v2u32, unsigned, max, max, u32)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_uint32x4, v2u32, unsigned, min, min, u32)
//OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_int32x4, v2i32, int, sum, add, s32)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_int32x4, v2i32, int, max, max, s32)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_int32x4, v2i32, int, min, min, s32)
//OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_float32x4, v2f32, float, sum, add, f32)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_float32x4, v2f32, float, max, max, f32)
OPENCV_HAL_IMPL_MSA_REDUCE_OP_4(v_float32x4, v2f32, float, min, min, f32)

#define OPENCV_HAL_IMPL_MSA_REDUCE_SUM(_Tpvec, scalartype, suffix) \
inline scalartype v_reduce_##func(const _Tpvec& a) \
{ \
    return (scalartype)msa_sum_##suffix(a.val); \
}
OPENCV_HAL_IMPL_MSA_REDUCE_SUM(v_uint16x8, unsigned short, u16)
OPENCV_HAL_IMPL_MSA_REDUCE_SUM(v_int16x8, short, s16)
OPENCV_HAL_IMPL_MSA_REDUCE_SUM(v_uint32x4, unsigned, u32)
OPENCV_HAL_IMPL_MSA_REDUCE_SUM(v_int32x4, int, s32)
OPENCV_HAL_IMPL_MSA_REDUCE_SUM(v_float32x4, float, f32)

#if CV_SIMD128_64F
inline double v_reduce_sum(const v_float64x2& a)
{
    return msa_getq_lane_f64(a.val, 0) + msa_getq_lane_f64(a.val, 1);
}
#endif

/* v_reduce_sum4, v_reduce_sad */
inline v_float32x4 v_reduce_sum4(const v_float32x4& a, const v_float32x4& b,
                                 const v_float32x4& c, const v_float32x4& d)
{
    v4f32 ab0 = msa_reinterpretq_f32_s32(msa_ilvevq_s32(msa_reinterpretq_s32_f32(b.val), msa_reinterpretq_s32_f32(a.val)));
    v4f32 ab1 = msa_reinterpretq_f32_s32(msa_ilvodq_s32(msa_reinterpretq_s32_f32(b.val), msa_reinterpretq_s32_f32(a.val)));
    v4f32 cd0 = msa_reinterpretq_f32_s32(msa_ilvevq_s32(msa_reinterpretq_s32_f32(d.val), msa_reinterpretq_s32_f32(c.val)));
    v4f32 cd1 = msa_reinterpretq_f32_s32(msa_ilvodq_s32(msa_reinterpretq_s32_f32(d.val), msa_reinterpretq_s32_f32(c.val)));

    v4f32 u0 = msa_addq_f32(ab0, ab1); // a0+a1 b0+b1 a2+a3 b2+b3
    v4f32 u1 = msa_addq_f32(cd0, cd1); // c0+c1 d0+d1 c2+c3 d2+d3

    v4f32 v0 = msa_combine_f32(msa_get_low_f32(u0), msa_get_low_f32(u1));
    v4f32 v1 = msa_combine_f32(msa_get_high_f32(u0), msa_get_high_f32(u1));

    return v_float32x4(msa_addq_f32(v0, v1));
}

inline unsigned v_reduce_sad(const v_uint8x16& a, const v_uint8x16& b)
{
    v4u32 t0 = msa_paddlq_u16(msa_paddlq_u8(msa_abdq_u8(a.val, b.val)));
    return msa_sum_u32(t0);
}
inline unsigned v_reduce_sad(const v_int8x16& a, const v_int8x16& b)
{
    v4u32 t0 = msa_paddlq_u16(msa_paddlq_u8(msa_reinterpretq_u8_s8(msa_abdq_s8(a.val, b.val))));
    return msa_sum_u32(t0);
}
inline unsigned v_reduce_sad(const v_uint16x8& a, const v_uint16x8& b)
{
    v4u32 t0 = msa_paddlq_u16(msa_abdq_u16(a.val, b.val));
    return msa_sum_u32(t0);
}
inline unsigned v_reduce_sad(const v_int16x8& a, const v_int16x8& b)
{
    v4u32 t0 = msa_paddlq_u16(msa_reinterpretq_u16_s16(msa_abdq_s16(a.val, b.val)));
    return msa_sum_u32(t0);
}
inline unsigned v_reduce_sad(const v_uint32x4& a, const v_uint32x4& b)
{
    v4u32 t0 = msa_abdq_u32(a.val, b.val);
    return msa_sum_u32(t0);
}
inline unsigned v_reduce_sad(const v_int32x4& a, const v_int32x4& b)
{
    v4u32 t0 = msa_reinterpretq_u32_s32(msa_abdq_s32(a.val, b.val));
    return msa_sum_u32(t0);
}
inline float v_reduce_sad(const v_float32x4& a, const v_float32x4& b)
{
    v4f32 t0 = msa_abdq_f32(a.val, b.val);
    return msa_sum_f32(t0);
}

/* v_popcount */
#define OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE8(_Tpvec, cast) \
inline v_uint32x4 v_popcount(const _Tpvec& a) \
{ \
    v16u8 t = msa_reinterpretq_u8_s8(msa_cntq_s8(cast(a.val))); \
    v8u16 t0 = msa_paddlq_u8(t);  /* 16 -> 8 */ \
    v4u32 t1 = msa_paddlq_u16(t0); /* 8 -> 4 */ \
    return v_uint32x4(t1); \
}

OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE8(v_uint8x16, msa_reinterpretq_s8_u8)
OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE8(v_int8x16, OPENCV_HAL_NOP)

#define OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE16(_Tpvec, cast) \
inline v_uint32x4 v_popcount(const _Tpvec& a) \
{ \
    v8u16 t = msa_reinterpretq_u16_s16(msa_cntq_s16(cast(a.val))); \
    v4u32 t1 = msa_paddlq_u16(t); /* 8 -> 4 */ \
    return v_uint32x4(t1); \
}

OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE16(v_uint16x8, msa_reinterpretq_s16_u16)
OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE16(v_int16x8, OPENCV_HAL_NOP)

#define OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE32(_Tpvec, cast) \
inline v_uint32x4 v_popcount(const _Tpvec& a) \
{ \
    return v_uint32x4(msa_reinterpretq_u32_s32(msa_cntq_s32(cast(a.val)))); \
}

OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE32(v_uint32x4, msa_reinterpretq_s32_u32)
OPENCV_HAL_IMPL_MSA_POPCOUNT_SIZE32(v_int32x4, OPENCV_HAL_NOP)

inline int v_signmask(const v_uint8x16& a)
{
    v8i8 m0 = msa_create_s8(CV_BIG_UINT(0x0706050403020100));
    v16u8 v0 = msa_shlq_u8(msa_shrq_n_u8(a.val, 7), msa_combine_s8(m0, m0));
    v2u64 v1 = msa_paddlq_u32(msa_paddlq_u16(msa_paddlq_u8(v0)));
    return (int)msa_getq_lane_u64(v1, 0) + ((int)msa_getq_lane_u64(v1, 1) << 8);
}
inline int v_signmask(const v_int8x16& a)
{ return v_signmask(v_reinterpret_as_u8(a)); }

inline int v_signmask(const v_uint16x8& a)
{
    v4i16 m0 = msa_create_s16(CV_BIG_UINT(0x0003000200010000));
    v8u16 v0 = msa_shlq_u16(msa_shrq_n_u16(a.val, 15), msa_combine_s16(m0, m0));
    v2u64 v1 = msa_paddlq_u32(msa_paddlq_u16(v0));
    return (int)msa_getq_lane_u64(v1, 0) + ((int)msa_getq_lane_u64(v1, 1) << 4);
}
inline int v_signmask(const v_int16x8& a)
{ return v_signmask(v_reinterpret_as_u16(a)); }

inline int v_signmask(const v_uint32x4& a)
{
    v2i32 m0 = msa_create_s32(CV_BIG_UINT(0x0000000100000000));
    v4u32 v0 = msa_shlq_u32(msa_shrq_n_u32(a.val, 31), msa_combine_s32(m0, m0));
    v2u64 v1 = msa_paddlq_u32(v0);
    return (int)msa_getq_lane_u64(v1, 0) + ((int)msa_getq_lane_u64(v1, 1) << 2);
}
inline int v_signmask(const v_int32x4& a)
{ return v_signmask(v_reinterpret_as_u32(a)); }
inline int v_signmask(const v_float32x4& a)
{ return v_signmask(v_reinterpret_as_u32(a)); }
#if CV_SIMD128_64F
inline int v_signmask(const v_uint64x2& a)
{
    v1i64 m0 = msa_dup_n_s64(0);
    v2u64 v0 = msa_shlq_u64(msa_shrq_n_u64(a.val, 63), msa_combine_s64(m0, m0));
    return (int)msa_getq_lane_u64(v0, 0) + ((int)msa_getq_lane_u64(v0, 1) << 1);
}
inline int v_signmask(const v_float64x2& a)
{ return v_signmask(v_reinterpret_as_u64(a)); }
#endif

#define OPENCV_HAL_IMPL_MSA_CHECK_ALLANY(_Tpvec, _Tpvec2, suffix, shift) \
inline bool v_check_all(const v_##_Tpvec& a) \
{ \
    _Tpvec2 v0 = msa_shrq_n_##suffix(msa_mvnq_##suffix(a.val), shift); \
    v2u64 v1 = msa_reinterpretq_u64_##suffix(v0); \
    return (msa_getq_lane_u64(v1, 0) | msa_getq_lane_u64(v1, 1)) == 0; \
} \
inline bool v_check_any(const v_##_Tpvec& a) \
{ \
    _Tpvec2 v0 = msa_shrq_n_##suffix(a.val, shift); \
    v2u64 v1 = msa_reinterpretq_u64_##suffix(v0); \
    return (msa_getq_lane_u64(v1, 0) | msa_getq_lane_u64(v1, 1)) != 0; \
}

OPENCV_HAL_IMPL_MSA_CHECK_ALLANY(uint8x16, v16u8, u8, 7)
OPENCV_HAL_IMPL_MSA_CHECK_ALLANY(uint16x8, v8u16, u16, 15)
OPENCV_HAL_IMPL_MSA_CHECK_ALLANY(uint32x4, v4u32, u32, 31)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_CHECK_ALLANY(uint64x2, v2u64, u64, 63)
#endif

inline bool v_check_all(const v_int8x16& a)
{ return v_check_all(v_reinterpret_as_u8(a)); }
inline bool v_check_all(const v_int16x8& a)
{ return v_check_all(v_reinterpret_as_u16(a)); }
inline bool v_check_all(const v_int32x4& a)
{ return v_check_all(v_reinterpret_as_u32(a)); }
inline bool v_check_all(const v_float32x4& a)
{ return v_check_all(v_reinterpret_as_u32(a)); }

inline bool v_check_any(const v_int8x16& a)
{ return v_check_any(v_reinterpret_as_u8(a)); }
inline bool v_check_any(const v_int16x8& a)
{ return v_check_any(v_reinterpret_as_u16(a)); }
inline bool v_check_any(const v_int32x4& a)
{ return v_check_any(v_reinterpret_as_u32(a)); }
inline bool v_check_any(const v_float32x4& a)
{ return v_check_any(v_reinterpret_as_u32(a)); }

#if CV_SIMD128_64F
inline bool v_check_all(const v_int64x2& a)
{ return v_check_all(v_reinterpret_as_u64(a)); }
inline bool v_check_all(const v_float64x2& a)
{ return v_check_all(v_reinterpret_as_u64(a)); }
inline bool v_check_any(const v_int64x2& a)
{ return v_check_any(v_reinterpret_as_u64(a)); }
inline bool v_check_any(const v_float64x2& a)
{ return v_check_any(v_reinterpret_as_u64(a)); }
#endif

/* v_select */
#define OPENCV_HAL_IMPL_MSA_SELECT(_Tpvec, suffix, usuffix) \
inline _Tpvec v_select(const _Tpvec& mask, const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec((msa_reinterpretq_##suffix##_##usuffix)(msa_bslq_u8(msa_reinterpretq_##usuffix##_##suffix(mask.val), msa_reinterpretq_##usuffix##_##suffix(b.val), msa_reinterpretq_##usuffix##_##suffix(a.val)))); \
}

OPENCV_HAL_IMPL_MSA_SELECT(v_uint8x16, u8, u8)
OPENCV_HAL_IMPL_MSA_SELECT(v_int8x16, s8, u8)
OPENCV_HAL_IMPL_MSA_SELECT(v_uint16x8, u16, u8)
OPENCV_HAL_IMPL_MSA_SELECT(v_int16x8, s16, u8)
OPENCV_HAL_IMPL_MSA_SELECT(v_uint32x4, u32, u8)
OPENCV_HAL_IMPL_MSA_SELECT(v_int32x4, s32, u8)
OPENCV_HAL_IMPL_MSA_SELECT(v_float32x4, f32, u8)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_SELECT(v_float64x2, f64, u8)
#endif

#define OPENCV_HAL_IMPL_MSA_EXPAND(_Tpvec, _Tpwvec, _Tp, suffix) \
inline void v_expand(const _Tpvec& a, _Tpwvec& b0, _Tpwvec& b1) \
{ \
    b0.val = msa_movl_##suffix(msa_get_low_##suffix(a.val)); \
    b1.val = msa_movl_##suffix(msa_get_high_##suffix(a.val)); \
} \
inline _Tpwvec v_expand_low(const _Tpvec& a) \
{ \
    return _Tpwvec(msa_movl_##suffix(msa_get_low_##suffix(a.val))); \
} \
inline _Tpwvec v_expand_high(const _Tpvec& a) \
{ \
    return _Tpwvec(msa_movl_##suffix(msa_get_high_##suffix(a.val))); \
} \
inline _Tpwvec v_load_expand(const _Tp* ptr) \
{ \
    return _Tpwvec(msa_movl_##suffix(msa_ld1_##suffix(ptr))); \
}

OPENCV_HAL_IMPL_MSA_EXPAND(v_uint8x16, v_uint16x8, uchar, u8)
OPENCV_HAL_IMPL_MSA_EXPAND(v_int8x16, v_int16x8, schar, s8)
OPENCV_HAL_IMPL_MSA_EXPAND(v_uint16x8, v_uint32x4, ushort, u16)
OPENCV_HAL_IMPL_MSA_EXPAND(v_int16x8, v_int32x4, short, s16)
OPENCV_HAL_IMPL_MSA_EXPAND(v_uint32x4, v_uint64x2, uint, u32)
OPENCV_HAL_IMPL_MSA_EXPAND(v_int32x4, v_int64x2, int, s32)

inline v_uint32x4 v_load_expand_q(const uchar* ptr)
{
    v8u8 v0 = msa_create_u8(*(unsigned*)ptr);
    v4u16 v1 = msa_get_low_u16(msa_movl_u8(v0));
    return v_uint32x4(msa_movl_u16(v1));
}

inline v_int32x4 v_load_expand_q(const schar* ptr)
{
    v8i8 v0 = msa_create_s8(*(unsigned*)ptr);
    v4i16 v1 = msa_get_low_s16(msa_movl_s8(v0));
    return v_int32x4(msa_movl_s16(v1));
}

/* v_zip, v_combine_low, v_combine_high, v_recombine */
#define OPENCV_HAL_IMPL_MSA_UNPACKS(_Tpvec, suffix, ssuffix) \
inline void v_zip(const _Tpvec& a0, const _Tpvec& a1, _Tpvec& b0, _Tpvec& b1) \
{ \
    b0.val = msa_reinterpretq_##suffix##_##ssuffix(msa_ilvrq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a1.val), msa_reinterpretq_##ssuffix##_##suffix(a0.val))); \
    b1.val = msa_reinterpretq_##suffix##_##ssuffix(msa_ilvlq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a1.val), msa_reinterpretq_##ssuffix##_##suffix(a0.val))); \
} \
inline _Tpvec v_combine_low(const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec(msa_combine_##suffix(msa_get_low_##suffix(a.val), msa_get_low_##suffix(b.val))); \
} \
inline _Tpvec v_combine_high(const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec(msa_combine_##suffix(msa_get_high_##suffix(a.val), msa_get_high_##suffix(b.val))); \
} \
inline void v_recombine(const _Tpvec& a, const _Tpvec& b, _Tpvec& c, _Tpvec& d) \
{ \
    c.val = msa_combine_##suffix(msa_get_low_##suffix(a.val), msa_get_low_##suffix(b.val)); \
    d.val = msa_combine_##suffix(msa_get_high_##suffix(a.val), msa_get_high_##suffix(b.val)); \
}

OPENCV_HAL_IMPL_MSA_UNPACKS(v_uint8x16, u8, s8)
OPENCV_HAL_IMPL_MSA_UNPACKS(v_int8x16, s8, s8)
OPENCV_HAL_IMPL_MSA_UNPACKS(v_uint16x8, u16, s16)
OPENCV_HAL_IMPL_MSA_UNPACKS(v_int16x8, s16, s16)
OPENCV_HAL_IMPL_MSA_UNPACKS(v_uint32x4, u32, s32)
OPENCV_HAL_IMPL_MSA_UNPACKS(v_int32x4, s32, s32)
OPENCV_HAL_IMPL_MSA_UNPACKS(v_float32x4, f32, s32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_UNPACKS(v_float64x2, f64, s64)
#endif

/* v_extract */
#define OPENCV_HAL_IMPL_MSA_EXTRACT(_Tpvec, suffix, ssuffix) \
template <int s> \
inline _Tpvec v_extract(const _Tpvec& a, const _Tpvec& b) \
{ \
    return _Tpvec(msa_reinterpretq_##suffix##_##ssuffix(msa_extq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a.val), msa_reinterpretq_##ssuffix##_##suffix(b.val), s))); \
}

OPENCV_HAL_IMPL_MSA_EXTRACT(v_uint8x16, u8, s8)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_int8x16, s8, s8)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_uint16x8, u16, s16)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_int16x8, s16, s16)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_uint32x4, u32, s32)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_int32x4, s32, s32)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_uint64x2, u64, s64)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_int64x2, s64, s64)
OPENCV_HAL_IMPL_MSA_EXTRACT(v_float32x4, f32, s32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_EXTRACT(v_float64x2, f64, s64)
#endif

/* v_round, v_floor, v_ceil, v_trunc */
inline v_int32x4 v_round(const v_float32x4& a)
{
    return v_int32x4(msa_cvttintq_s32_f32(a.val));
}

inline v_int32x4 v_floor(const v_float32x4& a)
{
    v4i32 a1 = msa_cvttintq_s32_f32(a.val);
    return v_int32x4(msa_addq_s32(a1, msa_reinterpretq_s32_u32(msa_cgtq_f32(msa_cvtfintq_f32_s32(a1), a.val))));
}

inline v_int32x4 v_ceil(const v_float32x4& a)
{
    v4i32 a1 = msa_cvttintq_s32_f32(a.val);
    return v_int32x4(msa_subq_s32(a1, msa_reinterpretq_s32_u32(msa_cgtq_f32(a.val, msa_cvtfintq_f32_s32(a1)))));
}

inline v_int32x4 v_trunc(const v_float32x4& a)
{
    return v_int32x4(msa_cvttruncq_s32_f32(a.val));
}

#if CV_SIMD128_64F
inline v_int32x4 v_round(const v_float64x2& a)
{
    return v_int32x4(msa_combine_s32(msa_movn_s64(msa_cvttintq_s64_f64(a.val)), msa_dup_n_s32(0)));
    //return v_int32x4(msa_cvttintq_s32_f32(msa_cvtfq_f32_f64(a.val, msa_dupq_n_f64(0.0f))));
}

inline v_int32x4 v_round(const v_float64x2& a, const v_float64x2& b)
{
    return v_int32x4(msa_combine_s32(msa_movn_s64(msa_cvttintq_s64_f64(a.val)), msa_movn_s64(msa_cvttintq_s64_f64(b.val))));
    //return v_int32x4(msa_cvttintq_s32_f32(msa_cvtfq_f32_f64(a.val, b.val)));
}

inline v_int32x4 v_floor(const v_float64x2& a)
{
    v2f64 a1 = msa_cvtrintq_f64(a.val);
    return v_int32x4(msa_combine_s32(msa_movn_s64(msa_addq_s64(msa_cvttruncq_s64_f64(a1), msa_reinterpretq_s64_u64(msa_cgtq_f64(a1, a.val)))), msa_dup_n_s32(0)));
    //v4f32 a1 = msa_cvtrintq_f32(msa_cvtfq_f32_f64(a.val, msa_dupq_n_f64(0.0f)));
    //return v_int32x4(msa_addq_s32(msa_cvttruncq_s32_f32(a1), msa_reinterpretq_s32_u32(msa_cgtq_f32(a1, a.val))));
}

inline v_int32x4 v_ceil(const v_float64x2& a)
{
    v2f64 a1 = msa_cvtrintq_f64(a.val);
    return v_int32x4(msa_combine_s32(msa_movn_s64(msa_subq_s64(msa_cvttruncq_s64_f64(a1), msa_reinterpretq_s64_u64(msa_cgtq_f64(a.val, a1)))), msa_dup_n_s32(0)));
    //v4f32 a1 = msa_cvtrintq_f32(msa_cvtfq_f32_f64(a.val, msa_dupq_n_f64(0.0f)));
    //return v_int32x4(msa_subq_s32(msa_cvttruncq_s32_f32(a1), msa_reinterpretq_s32_u32(msa_cgtq_f32(a.val, a1))));
}

inline v_int32x4 v_trunc(const v_float64x2& a)
{
    return v_int32x4(msa_combine_s32(msa_movn_s64(msa_cvttruncq_s64_f64(a.val)), msa_dup_n_s32(0)));
    //return v_int32x4(msa_cvttruncq_s32_f32(msa_cvtfq_f32_f64(a.val, msa_dupq_n_f64(0.0f))));
}
#endif

/* v_transpose4x4 */
#define OPENCV_HAL_IMPL_MSA_TRANSPOSE4x4(_Tpvec, _Tpvec2, suffix, ssuffix) \
inline void v_transpose4x4(const _Tpvec& a0, const _Tpvec& a1, \
                         const _Tpvec& a2, const _Tpvec& a3, \
                         _Tpvec& b0, _Tpvec& b1, \
                         _Tpvec& b2, _Tpvec& b3) \
{ \
    /* m00 m01 m02 m03 */ \
    /* m10 m11 m12 m13 */ \
    /* m20 m21 m22 m23 */ \
    /* m30 m31 m32 m33 */ \
    _Tpvec2 t00 = msa_reinterpretq_##suffix##_##ssuffix(msa_ilvevq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a1.val), msa_reinterpretq_##ssuffix##_##suffix(a0.val))); \
    _Tpvec2 t01 = msa_reinterpretq_##suffix##_##ssuffix(msa_ilvodq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a1.val), msa_reinterpretq_##ssuffix##_##suffix(a0.val))); \
    _Tpvec2 t10 = msa_reinterpretq_##suffix##_##ssuffix(msa_ilvevq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a3.val), msa_reinterpretq_##ssuffix##_##suffix(a2.val))); \
    _Tpvec2 t11 = msa_reinterpretq_##suffix##_##ssuffix(msa_ilvodq_##ssuffix(msa_reinterpretq_##ssuffix##_##suffix(a3.val), msa_reinterpretq_##ssuffix##_##suffix(a2.val))); \
    /* m00 m10 m02 m12 */ \
    /* m01 m11 m03 m13 */ \
    /* m20 m30 m22 m32 */ \
    /* m21 m31 m23 m33 */ \
    b0.val = msa_combine_##suffix(msa_get_low_##suffix(t00), msa_get_low_##suffix(t10)); \
    b1.val = msa_combine_##suffix(msa_get_low_##suffix(t01), msa_get_low_##suffix(t11)); \
    b2.val = msa_combine_##suffix(msa_get_high_##suffix(t00), msa_get_high_##suffix(t10)); \
    b3.val = msa_combine_##suffix(msa_get_high_##suffix(t01), msa_get_high_##suffix(t11)); \
}

OPENCV_HAL_IMPL_MSA_TRANSPOSE4x4(v_uint32x4, v4u32, u32, s32)
OPENCV_HAL_IMPL_MSA_TRANSPOSE4x4(v_int32x4, v4i32, s32, s32)
OPENCV_HAL_IMPL_MSA_TRANSPOSE4x4(v_float32x4, v4f32, f32, s32)

#define OPENCV_HAL_IMPL_MSA_INTERLEAVED(_Tpvec, _Tp, suffix) \
inline void v_load_deinterleave(const _Tp* ptr, v_##_Tpvec& a, v_##_Tpvec& b) \
{ \
    _Tpvec##x2_t v = msa_ld2q_##suffix(ptr); \
    a.val = v.val[0]; \
    b.val = v.val[1]; \
} \
inline void v_load_deinterleave(const _Tp* ptr, v_##_Tpvec& a, v_##_Tpvec& b, v_##_Tpvec& c) \
{ \
    _Tpvec##x3_t v = msa_ld3q_##suffix(ptr); \
    a.val = v.val[0]; \
    b.val = v.val[1]; \
    c.val = v.val[2]; \
} \
inline void v_load_deinterleave(const _Tp* ptr, v_##_Tpvec& a, v_##_Tpvec& b, \
                                v_##_Tpvec& c, v_##_Tpvec& d) \
{ \
    _Tpvec##x4_t v = msa_ld4q_##suffix(ptr); \
    a.val = v.val[0]; \
    b.val = v.val[1]; \
    c.val = v.val[2]; \
    d.val = v.val[3]; \
} \
inline void v_store_interleave( _Tp* ptr, const v_##_Tpvec& a, const v_##_Tpvec& b, \
                                hal::StoreMode /*mode*/=hal::STORE_UNALIGNED) \
{ \
    _Tpvec##x2_t v; \
    v.val[0] = a.val; \
    v.val[1] = b.val; \
    msa_st2q_##suffix(ptr, v); \
} \
inline void v_store_interleave( _Tp* ptr, const v_##_Tpvec& a, const v_##_Tpvec& b, \
                                const v_##_Tpvec& c, hal::StoreMode /*mode*/=hal::STORE_UNALIGNED) \
{ \
    _Tpvec##x3_t v; \
    v.val[0] = a.val; \
    v.val[1] = b.val; \
    v.val[2] = c.val; \
    msa_st3q_##suffix(ptr, v); \
} \
inline void v_store_interleave( _Tp* ptr, const v_##_Tpvec& a, const v_##_Tpvec& b, \
                                const v_##_Tpvec& c, const v_##_Tpvec& d, \
                                hal::StoreMode /*mode*/=hal::STORE_UNALIGNED ) \
{ \
    _Tpvec##x4_t v; \
    v.val[0] = a.val; \
    v.val[1] = b.val; \
    v.val[2] = c.val; \
    v.val[3] = d.val; \
    msa_st4q_##suffix(ptr, v); \
}

#define OPENCV_HAL_IMPL_MSA_INTERLEAVED_INT64(tp, suffix) \
inline void v_load_deinterleave( const tp* ptr, v_##tp##x2& a, v_##tp##x2& b ) \
{ \
    tp##x1_t a0 = msa_ld1_##suffix(ptr); \
    tp##x1_t b0 = msa_ld1_##suffix(ptr + 1); \
    tp##x1_t a1 = msa_ld1_##suffix(ptr + 2); \
    tp##x1_t b1 = msa_ld1_##suffix(ptr + 3); \
    a = v_##tp##x2(msa_combine_##suffix(a0, a1)); \
    b = v_##tp##x2(msa_combine_##suffix(b0, b1)); \
} \
 \
inline void v_load_deinterleave( const tp* ptr, v_##tp##x2& a, \
                                 v_##tp##x2& b, v_##tp##x2& c ) \
{ \
    tp##x1_t a0 = msa_ld1_##suffix(ptr); \
    tp##x1_t b0 = msa_ld1_##suffix(ptr + 1); \
    tp##x1_t c0 = msa_ld1_##suffix(ptr + 2); \
    tp##x1_t a1 = msa_ld1_##suffix(ptr + 3); \
    tp##x1_t b1 = msa_ld1_##suffix(ptr + 4); \
    tp##x1_t c1 = msa_ld1_##suffix(ptr + 5); \
    a = v_##tp##x2(msa_combine_##suffix(a0, a1)); \
    b = v_##tp##x2(msa_combine_##suffix(b0, b1)); \
    c = v_##tp##x2(msa_combine_##suffix(c0, c1)); \
} \
 \
inline void v_load_deinterleave( const tp* ptr, v_##tp##x2& a, v_##tp##x2& b, \
                                 v_##tp##x2& c, v_##tp##x2& d ) \
{ \
    tp##x1_t a0 = msa_ld1_##suffix(ptr); \
    tp##x1_t b0 = msa_ld1_##suffix(ptr + 1); \
    tp##x1_t c0 = msa_ld1_##suffix(ptr + 2); \
    tp##x1_t d0 = msa_ld1_##suffix(ptr + 3); \
    tp##x1_t a1 = msa_ld1_##suffix(ptr + 4); \
    tp##x1_t b1 = msa_ld1_##suffix(ptr + 5); \
    tp##x1_t c1 = msa_ld1_##suffix(ptr + 6); \
    tp##x1_t d1 = msa_ld1_##suffix(ptr + 7); \
    a = v_##tp##x2(msa_combine_##suffix(a0, a1)); \
    b = v_##tp##x2(msa_combine_##suffix(b0, b1)); \
    c = v_##tp##x2(msa_combine_##suffix(c0, c1)); \
    d = v_##tp##x2(msa_combine_##suffix(d0, d1)); \
} \
 \
inline void v_store_interleave( tp* ptr, const v_##tp##x2& a, const v_##tp##x2& b, \
                                hal::StoreMode /*mode*/=hal::STORE_UNALIGNED) \
{ \
    msa_st1_##suffix(ptr, msa_get_low_##suffix(a.val)); \
    msa_st1_##suffix(ptr + 1, msa_get_low_##suffix(b.val)); \
    msa_st1_##suffix(ptr + 2, msa_get_high_##suffix(a.val)); \
    msa_st1_##suffix(ptr + 3, msa_get_high_##suffix(b.val)); \
} \
 \
inline void v_store_interleave( tp* ptr, const v_##tp##x2& a, \
                                const v_##tp##x2& b, const v_##tp##x2& c, \
                                hal::StoreMode /*mode*/=hal::STORE_UNALIGNED) \
{ \
    msa_st1_##suffix(ptr, msa_get_low_##suffix(a.val)); \
    msa_st1_##suffix(ptr + 1, msa_get_low_##suffix(b.val)); \
    msa_st1_##suffix(ptr + 2, msa_get_low_##suffix(c.val)); \
    msa_st1_##suffix(ptr + 3, msa_get_high_##suffix(a.val)); \
    msa_st1_##suffix(ptr + 4, msa_get_high_##suffix(b.val)); \
    msa_st1_##suffix(ptr + 5, msa_get_high_##suffix(c.val)); \
} \
 \
inline void v_store_interleave( tp* ptr, const v_##tp##x2& a, const v_##tp##x2& b, \
                                const v_##tp##x2& c, const v_##tp##x2& d, \
                                hal::StoreMode /*mode*/=hal::STORE_UNALIGNED) \
{ \
    msa_st1_##suffix(ptr, msa_get_low_##suffix(a.val)); \
    msa_st1_##suffix(ptr + 1, msa_get_low_##suffix(b.val)); \
    msa_st1_##suffix(ptr + 2, msa_get_low_##suffix(c.val)); \
    msa_st1_##suffix(ptr + 3, msa_get_low_##suffix(d.val)); \
    msa_st1_##suffix(ptr + 4, msa_get_high_##suffix(a.val)); \
    msa_st1_##suffix(ptr + 5, msa_get_high_##suffix(b.val)); \
    msa_st1_##suffix(ptr + 6, msa_get_high_##suffix(c.val)); \
    msa_st1_##suffix(ptr + 7, msa_get_high_##suffix(d.val)); \
}

OPENCV_HAL_IMPL_MSA_INTERLEAVED(v16u8, uchar, u8)
OPENCV_HAL_IMPL_MSA_INTERLEAVED(v16i8, schar, s8)
OPENCV_HAL_IMPL_MSA_INTERLEAVED(v8u16, ushort, u16)
OPENCV_HAL_IMPL_MSA_INTERLEAVED(v8i16, short, s16)
OPENCV_HAL_IMPL_MSA_INTERLEAVED(v4u32, unsigned, u32)
OPENCV_HAL_IMPL_MSA_INTERLEAVED(v4i32, int, s32)
OPENCV_HAL_IMPL_MSA_INTERLEAVED(v4f32, float, f32)
#if CV_SIMD128_64F
OPENCV_HAL_IMPL_MSA_INTERLEAVED(v2f64, double, f64)
#endif

OPENCV_HAL_IMPL_MSA_INTERLEAVED_INT64(int64, s64)
OPENCV_HAL_IMPL_MSA_INTERLEAVED_INT64(uint64, u64)

/* v_cvt_f32, v_cvt_f64, v_cvt_f64_high */
inline v_float32x4 v_cvt_f32(const v_int32x4& a)
{
    return v_float32x4(msa_cvtfintq_f32_s32(a.val));
}

#if CV_SIMD128_64F
inline v_float32x4 v_cvt_f32(const v_float64x2& a)
{
    return v_float32x4(msa_cvtfq_f32_f64(a.val, msa_dupq_n_f64(0.0f)));
}

inline v_float32x4 v_cvt_f32(const v_float64x2& a, const v_float64x2& b)
{
    return v_float32x4(msa_cvtfq_f32_f64(a.val, b.val));
}

inline v_float64x2 v_cvt_f64(const v_int32x4& a)
{
    return v_float64x2(msa_cvtflq_f64_f32(msa_cvtfintq_f32_s32(a.val)));
}

inline v_float64x2 v_cvt_f64_high(const v_int32x4& a)
{
    return v_float64x2(msa_cvtfhq_f64_f32(msa_cvtfintq_f32_s32(a.val)));
}

inline v_float64x2 v_cvt_f64(const v_float32x4& a)
{
    return v_float64x2(msa_cvtflq_f64_f32(a.val));
}

inline v_float64x2 v_cvt_f64_high(const v_float32x4& a)
{
    return v_float64x2(msa_cvtfhq_f64_f32(a.val));
}
#endif

////////////// Lookup table access ////////////////////

inline v_int32x4 v_lut(const int* tab, const v_int32x4& idxvec)
{
    int CV_DECL_ALIGNED(32) elems[4] =
    {
        tab[msa_getq_lane_s32(idxvec.val, 0)],
        tab[msa_getq_lane_s32(idxvec.val, 1)],
        tab[msa_getq_lane_s32(idxvec.val, 2)],
        tab[msa_getq_lane_s32(idxvec.val, 3)]
    };
    return v_int32x4(msa_ld1q_s32(elems));
}

inline v_float32x4 v_lut(const float* tab, const v_int32x4& idxvec)
{
    float CV_DECL_ALIGNED(32) elems[4] =
    {
        tab[msa_getq_lane_s32(idxvec.val, 0)],
        tab[msa_getq_lane_s32(idxvec.val, 1)],
        tab[msa_getq_lane_s32(idxvec.val, 2)],
        tab[msa_getq_lane_s32(idxvec.val, 3)]
    };
    return v_float32x4(msa_ld1q_f32(elems));
}

inline void v_lut_deinterleave(const float* tab, const v_int32x4& idxvec, v_float32x4& x, v_float32x4& y)
{
    /*int CV_DECL_ALIGNED(32) idx[4];
    v_store(idx, idxvec);

    v4f32_t xy02 = vcombine_f32(vld1_f32(tab + idx[0]), vld1_f32(tab + idx[2]));
    v4f32_t xy13 = vcombine_f32(vld1_f32(tab + idx[1]), vld1_f32(tab + idx[3]));

    v4f32x2_t xxyy = vuzpq_f32(xy02, xy13);
    x = v_float32x4(xxyy.val[0]);
    y = v_float32x4(xxyy.val[1]);*/
    int CV_DECL_ALIGNED(32) idx[4];
    v_store_aligned(idx, idxvec);

    x = v_float32x4(tab[idx[0]], tab[idx[1]], tab[idx[2]], tab[idx[3]]);
    y = v_float32x4(tab[idx[0]+1], tab[idx[1]+1], tab[idx[2]+1], tab[idx[3]+1]);
}

#if CV_SIMD128_64F
inline v_float64x2 v_lut(const double* tab, const v_int32x4& idxvec)
{
    double CV_DECL_ALIGNED(32) elems[2] =
    {
        tab[msa_getq_lane_s32(idxvec.val, 0)],
        tab[msa_getq_lane_s32(idxvec.val, 1)],
    };
    return v_float64x2(msa_ld1q_f64(elems));
}

inline void v_lut_deinterleave(const double* tab, const v_int32x4& idxvec, v_float64x2& x, v_float64x2& y)
{
    int CV_DECL_ALIGNED(32) idx[4];
    v_store_aligned(idx, idxvec);

    x = v_float64x2(tab[idx[0]], tab[idx[1]]);
    y = v_float64x2(tab[idx[0]+1], tab[idx[1]+1]);
}
#endif

////// FP16 suport ///////
#if CV_FP16
inline v_float32x4 v_load_expand(const float16_t* ptr)
{
    v4f16 v =
    #ifndef msa_ld1_f16
        (v4f16)msa_ld1_s16((const short*)ptr);
    #else
        msa_ld1_f16((const __fp16*)ptr);
    #endif
    return v_float32x4(msa_cvt_f32_f16(v));
}

inline void v_pack_store(float16_t* ptr, const v_float32x4& v)
{
    v4f16 hv = msa_cvt_f16_f32(v.val);

    #ifndef msa_st1_f16
        msa_st1_s16((short*)ptr, (int16x4_t)hv);
    #else
        msa_st1_f16((__fp16*)ptr, hv);
    #endif
}
#else
inline v_float32x4 v_load_expand(const float16_t* ptr)
{
    const int N = 4;
    float buf[N];
    for( int i = 0; i < N; i++ ) buf[i] = (float)ptr[i];
    return v_load(buf);
}

inline void v_pack_store(float16_t* ptr, const v_float32x4& v)
{
    const int N = 4;
    float buf[N];
    v_store(buf, v);
    for( int i = 0; i < N; i++ ) ptr[i] = float16_t(buf[i]);
}
#endif

inline void v_cleanup() {}

//! @name Check SIMD support
//! @{
//! @brief Check CPU capability of SIMD operation
static inline bool hasSIMD128()
{
    return (CV_CPU_HAS_SUPPORT_MSA) ? true : false;
}

//! @}

CV_CPU_OPTIMIZATION_HAL_NAMESPACE_END

//! @endcond

}

#endif


