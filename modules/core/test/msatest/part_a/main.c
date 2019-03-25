#include <stdio.h>
#include <time.h>
#include "msa_macro.h"

#define __PACKED_1 __attribute__((packed, aligned(2))) 
#define __PACKED __attribute__((packed)) 

static v16i8 g_v16i8Data = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15};
static v16u8 g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
static v16u8 g_v16u8Data1 = {255, 254, 253, 252, 251, 250, 249, 248, 128, 127, 126, 125, 124, 123, 122, 121};
static v8u16 g_v8u16Data = {0, 1, 2, 3, 4, 5, 6, 7};
static v8u16 g_v8i16Data =  {0xff00, 0x00ff, 0xaa00, 0x00aa, 0x5500, 0x0055, 0x0, 0xffff};
static v8u16 g_v8i16Data1 = {0x00ff, 0xff00, 0x00aa, 0xaa00, 0x0055, 0x5500, 0xffff, 0xffff};
static v4u32 g_v4u32Data = {0, 1, 2, 3};
static v4f32 g_v4f32Data = {-0.001, 1.001, -2.002, 3.003};
static v4f32 g_v4f32Data1 = {0.01, -1.01, 2.02, -3.03};
static v2f32 g_v2f32Data1 = {-0.001, 1.001};
static v2f32 g_v2f32Data2 = {-2.002, 3.003};
static v2f64 g_v2f64Data = {-0.0011111111, 1.0011111111};
static v2f64 g_v2f64Data1 = {0.00222222, 1.00222222};
static v1f64 g_v1f64Data1 = {-0.0011111111};
static v1f64 g_v1f64Data2 = {1.0011111111};
static v8i8_b g_v8i8Data1 = {0, -1, 2, -3, 4, -5, 6, -7};
static v8i8_b g_v8i8Data2 = {8, -9, 10, -11, 12, -13, 14, -15};
static v8u8_b g_v8u8Data1 = {128, 127, 126, 125, 124, 123, 122, 121};
static v8u8_b g_v8u8Data2 = {255, 254, 253, 252, 251, 250, 249, 248};
/*
i32 __builtin_msa_copy_s_w (v4i32, imm0_3) 
 */

void getLaneTstFunc()
{
	short i=0;

	////test integer
	printf("\n =================getLaneTstFunc=====================================================================\n");
	printf("input: 	g_v16i8Data = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15}\n");
	printf("output: __builtin_msa_copy_s_b(g_v16i8Data, i)={");
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 0));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 1));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 2));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 3));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 4));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 5));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 6));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 7));
	printf("%d,  ", __builtin_msa_copy_s_b(g_v16i8Data, 8));
	printf("\b\b\b}\n\n");
	
	////test float
	float f32Data[4];
	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}\n");
	printf("output: _msa_copy_s_w(g_v4f32Data, i)={");
	for(i=0; i<4; i++) {
#if defined DB_vf32_0
		f32Data[i] = __builtin_msa_copy_s_w(g_v4f32Data, i);
#elif defined DB_vf32_1
#else
		f32Data[i] = msa_getq_lane_f32(g_v4f32Data, i);
#endif
		printf("%f,  ", f32Data[i]);
	}
	printf("\b\b\b}\n\n");
}

void combineTstFunc()
{
	short i=0;

	////test integer
	printf("\n =================combineTstFunc=====================================================================\n");
	printf("input: 	g_v8i8Data1 = {0, -1, 2, -3, 4, -5, 6, -7}, g_v8i8Data2 = {8, -9, 10, -11, 12, -13, 14, -15}\n");
	printf("output: msa_vcombine_s8(g_v8i8Data1, g_v8i8Data2)={");
	v16i8 c = msa_combine_s8(g_v8i8Data1, g_v8i8Data2);
	for(i=0; i<16; i++) {
		printf("%d,  ", c[i]);
	}
	printf("\b\b\b}\n\n");
	
	////test float
	printf("input: 	g_v2f32Data1 = {-0.001, 1.001}, g_v2f32Data2 = {-2.002, 3.003}\n");
	printf("output: msa_vcombine_f32(g_v2f32Data1, g_v2f32Data2)={");
	v4f32 cc = msa_combine_f32(g_v2f32Data1, g_v2f32Data2);
	for(i=0; i<4; i++) {
		printf("%f,  ", cc[i]);
	}
	printf("\b\b\b}\n\n");
}

void getLowTstFunc()
{
	short i=0;

	////test integer
	printf("\n =================getLowTstFunc=====================================================================\n");
	printf("input: 	g_v16i8Data = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15}\n");
	printf("output: v8i8 c = msa_get_low_s8(g_v16i8Data)={");
	v8i8 c = msa_get_low_s8(g_v16i8Data);
	for(i=0; i<8; i++) {
		printf("%d,  ", c[i]);
	}
	printf("\b\b\b}\n\n");
	
	////test float
	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}\n");
	printf("output: v2f32 cc = msa_get_low_f32(g_v4f32Data)={");
	v2f32 cc = msa_get_low_f32(g_v4f32Data);
	for(i=0; i<2; i++) {
		printf("%f,  ", cc[i]);
	}
	printf("\b\b\b}\n\n");
	
	////test double
	printf("input: g_v2f64Data = {-0.0011111111, 1.0011111111}\n");
	printf("output: v1f64 ccc = msa_get_low_f64(g_v4f64Data)={");
	v1f64 ccc = msa_get_low_f64(g_v2f64Data);
	for(i=0; i<1; i++) {
		printf("%.10f,  ", ccc[i]);
	}
	printf("\b\b\b}\n\n");
}

void getHighTstFunc()
{
	short i=0;

	////test integer
	printf("\n =================getHighTstFunc=====================================================================\n");
	printf("input: 	g_v16i8Data = {0, -1, 2, -3, 4, -5, 6, -7, 8, -9, 10, -11, 12, -13, 14, -15}\n");
	printf("output: v8i8 c = msa_get_high_s8(g_v16i8Data)={");
	v8i8 c = msa_get_high_s8(g_v16i8Data);
	for(i=0; i<8; i++) {
		printf("%d,  ", c[i]);
	}
	printf("\b\b\b}\n\n");
	
	////test float
	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}\n");
	printf("output: msa_get_high_f32(g_v4f32Data)={");
	v2f32 cc = msa_get_high_f32(g_v4f32Data);
	for(i=0; i<2; i++) {
		printf("%f,  ", cc[i]);
	}
	printf("\b\b\b}\n\n");
	
	////test double
	printf("input: g_v2f64Data = {-0.0011111111, 1.0011111111}\n");
	printf("output: v1f64 ccc = msa_get_high_f64(g_v2f64Data)={");
	v1f64 ccc = msa_get_high_f64(g_v2f64Data);
	for(i=0; i<1; i++) {
		printf("%.10f,  ", ccc[i]);
	}
	printf("\b\b\b}\n\n");
}

void multiplicationTstFunc()
{
	short i=0;

	////test msa_mulq_lane_f32
	printf("\n =================multiplicationTstFunc=====================================================================\n");
	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v2f32Data1 = {-0.001, 1.001}\n");
	printf("output: c = msa_mulq_lane_f32(g_v4f32Data, g_v2f32Data1, 0)={");
	v4f32 c = msa_mulq_lane_f32(g_v4f32Data, g_v2f32Data1, 0);
	for(i=0; i<4; i++) {
		printf("%f,  ", c[i]);
	}
	printf("\b\b\b}\n\n");
	
	////test msa_mulaq_lane_f32
	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v2f32Data1 = {-0.001, 1.001}\n");
	printf("output: c = msa_mulaq_lane_f32(g_v4f32Data, g_v4f32Data, g_v2f32Data1, 1)={");
	v4f32 cc = msa_mlaq_lane_f32(g_v4f32Data, g_v4f32Data, g_v2f32Data1, 1);
	for(i=0; i<4; i++) {
		printf("%f,  ", cc[i]);
	}
	printf("\b\b\b}\n\n");
}

void vsumTstFunc()
{
	////test integer
	printf("\n =================vsumTstFunc=====================================================================\n");
	printf("input: 	g_v4u32Data = {0, 1, 2, 3}\n");
	printf("output: uint32_t c = msa_sum_u32(g_v4u32Data)={");
	uint32_t c = msa_sum_u32(g_v4u32Data);
	printf("%d,  ", c);
	printf("\b\b\b}\n\n");
	
	////test float
	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}\n");
	printf("output: float cc = msa_sum_f32(g_v4f32Data)={");
	float cc = msa_sum_f32(g_v4f32Data);
	printf("%f,  ", cc);
	printf("\b\b\b}\n\n");
}

void paddlpTstFunc()
{
	short i=0;

	////test v16u8
	printf("\n =================paddlpTstFunc=====================================================================\n");
	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}\n");
	printf("output: v8u16 c = msa_paddlq_u8(g_v16u8Data)={");
	v8u16 c = msa_paddlq_u8(g_v16u8Data);
	for(i=0; i<8; i++) {
		printf("%d,  ", c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	g_v8u16Data = {0, 1, 2, 3, 4, 5, 6, 7}\n");
	printf("output: v4u32 c = msa_paddlq_u16(g_v8u16Data)={");
	v4u32 cc = msa_paddlq_u16(g_v8u16Data);
	for(i=0; i<4; i++) {
		printf("%d,  ", cc[i]);
	}
	printf("\b\b\b}\n\n");
	
	printf("input: 	g_v4u32Data = {0, 1, 2, 3}\n");
	printf("output: v2u64 c = msa_paddlq_u32(g_v4u32Data)={");
	v2u64 ccc = msa_paddlq_u32(g_v4u32Data);
	for(i=0; i<2; i++) {
		printf("%d,  ", ccc[i]);
	}
	printf("\b\b\b}\n\n");
}

__extension__ extern __inline v8u16
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_paddlq_u8_tt (v16u8 __a)
{
  v8u16 result = {(uint16_t)(__a[0] + __a[1]), (uint16_t)(__a[2] + __a[3]), (uint16_t)(__a[4] + __a[5]), (uint16_t)(__a[6] + __a[7]),
                  (uint16_t)(__a[8] + __a[9]), (uint16_t)(__a[10] + __a[11]), (uint16_t)(__a[12] + __a[13]), (uint16_t)(__a[14] + __a[15])};
  return result;
}
__extension__ extern __inline v16i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_replicate_tt(signed char scalar) {
  v16i8 v ={ scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar, scalar };
  return v;
}
__extension__ extern __inline v16i8
__attribute__ ((__always_inline__, __gnu_inline__, __artificial__))
msa_replicate(signed char scalar)
{ return __builtin_msa_fill_b(scalar); }
void perfValidTstFunc()
{
	clock_t start, end;
	float f32Data[4];
	int i = 0;
	
	printf("\n =================perfCompareTstFunc=====================================================================\n");
	printf("\n ==assign VS __builtin_msa_fill_b+__builtin_msa_dotp_u_h==========================\n");
	start = clock();
	msa_paddlq_u8_tt(g_v16u8Data);
	end = clock();
	printf("Running msa_paddlq_u8_tt(g_v16u8Data), escapedTimeUs=%d\n", (end-start));
	
	start = clock();
	msa_paddlq_u8(g_v16u8Data);
	end = clock();
	printf("Running msa_paddlq_u8(g_v16u8Data), escapedTimeUs=%d\n", (end-start));
	
	printf("\n ==assign VS __builtin_msa_fill_b=======================================\n");
	v16i8 u16i8data;
	start = clock();
	u16i8data = msa_replicate_tt(-2);
	end = clock();
	printf("Running u16i8data = msa_replicate_tt(-2), escapedTimeUs=%d\n", (end-start));
	
	start = clock();
	u16i8data = msa_replicate(-2);
	end = clock();
	printf("Running u16i8data = msa_replicate(-2), escapedTimeUs=%d\n", (end-start));


  printf("\n ==msa_getq_lane_f32 inline VS define=======================================\n");
  printf("input:  g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}\n");
  start = clock();
  f32Data[0] = msa_getq_lane_f32(g_v4f32Data, 0);
  f32Data[1] = msa_getq_lane_f32(g_v4f32Data, 1);
	end = clock();
	printf("Running msa_getq_lane_f32(g_v4f32Data, 0)), escapedTimeUs=%d\n", (end-start));
  start = clock();
  f32Data[2] = ((float)g_v4f32Data[LANE_IMM0_3(2)]);
  f32Data[3] = ((float)g_v4f32Data[LANE_IMM0_3(3)]);
  end = clock();
  printf("Running ((float)g_v4f32Data[LANE_IMM0_3(2)]), escapedTimeUs=%d\n", (end-start));
  printf("output: msa_getq_lane_f32(g_v4f32Data, i)={");
  for(i=0; i<4; i++) {
    printf("%f,  ", f32Data[i]);
  }
  printf("\b\b\b}\n\n");
}

void addvSubvTstFunc()
{
	short i=0;
	v16u8 b = (v16u8)__builtin_msa_fill_b(128);

	////v16i8 __builtin_msa_addv_b (v16i8, v16i8)
	////test v16u8
	printf("\n =================addvSubvTstFunc=====================================================================\n");
	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, b = (v16u8)__builtin_msa_fill_b(128)\n");
	printf("output: (v16u8)__builtin_msa_addv_b(g_v16u8Data, b)={");
	v16u8 c = (v16u8)__builtin_msa_addv_b((v16i8)g_v16u8Data, (v16i8)b);
	for(i=0; i<16; i++) {
		printf("%d,  ", c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}, b = (v16u8)__builtin_msa_fill_b(128)\n");
	printf("output: (v16u8)__builtin_msa_subv_b(g_v16u8Data, b)={");
	v16u8 cc = (v16u8)__builtin_msa_subv_b((v16i8)g_v16u8Data, (v16i8)b);
	for(i=0; i<16; i++) {
		printf("%d,  ", cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: (v16u8)__builtin_msa_subv_b(b,g_v16u8Data)={");
	cc = (v16u8)__builtin_msa_subv_b((v16i8)b, (v16i8)g_v16u8Data);
	for(i=0; i<16; i++) {
		printf("%d,  ", cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: (v16i8)__builtin_msa_subv_b(b,g_v16u8Data)={");
	v16i8 ccc = __builtin_msa_subv_b((v16i8)b, (v16i8)g_v16u8Data);
	for(i=0; i<16; i++) {
		printf("%d,  ", ccc[i]);
	}
	printf("\b\b\b}\n\n");
}

void longMulTstFunc()
{
	short i=0;
	v8i8 b = {-2, -2, -2, -2, -2, -2, -2, -2};

	////v8i16 __builtin_msa_mulv_h (v8i16, v8i16)
	////test v8u16 < v8u8 * v8u8
	printf("\n =================longMulTstFunc=====================================================================\n");
	printf("input: 	g_v8u8Data1 = {128, 127, 126, 125, 124, 123, 122, 121},g_v8u8Data2 = {255, 254, 253, 252, 251, 250, 249, 248}\n");
	printf("output: msa_mull_u8(g_v8u8Data1, g_v8u8Data1)={");
	v8u16 c = msa_mull_u8(g_v8u8Data1, g_v8u8Data1);
	for(i=0; i<8; i++) {
		printf("%d,  ", c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: msa_mull_u8(g_v8u8Data2, g_v8u8Data2)={");
	c = msa_mull_u8(g_v8u8Data2, g_v8u8Data2);
	for(i=0; i<8; i++) {
		printf("%d,  ", c[i]);
	}
	printf("\b\b\b}\n\n");

	////test v8i16 < v8i8 * v8i8
	printf("input: 	g_v8i8Data1 = {0, -1, 2, -3, 4, -5, 6, -7},g_v8i8Data2 = {8, -9, 10, -11, 12, -13, 14, -15}, b = __builtin_msa_fill_b(-2)\n");
	printf("output: msa_mull_s8(g_v8i8Data1, g_v8i8Data1)={");
	v8i16 cc = msa_mull_s8(g_v8i8Data1, g_v8i8Data1);
	for(i=0; i<8; i++) {
		printf("%d,  ", cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: msa_mull_s8(g_v8i8Data2, b)={");
	cc = msa_mull_s8(g_v8i8Data2, b);
	for(i=0; i<8; i++) {
		printf("%d,  ", cc[i]);
	}
	printf("\b\b\b}\n\n");
}

void divTstFunc()
{
	short i=0;

	////test msa_mulq_lane_f32
	printf("\n =================divTstFunc=====================================================================\n");
	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v4f32Data1 = {0.01, -1.01, 2.02, -3.03}\n");
	printf("output: c = msa_mulq_lane_f32(g_v4f32Data, g_v2f32Data1, 0)={");
	v4f32 c = __builtin_msa_fdiv_w(g_v4f32Data, g_v4f32Data1);
	for(i=0; i<4; i++) {
		printf("%f,  ", c[i]);
	}
	printf("\b\b\b}\n\n");
	
	////test msa_mulaq_lane_f32
	printf("input: 	g_v2f64Data = {-0.0011111111, 1.0011111111}, g_v2f64Data1 = {0.00222222, 1.00222222}\n");
	printf("output: c = __builtin_msa_fdiv_d(g_v2f64Data, g_v2f64Data1)={");
	v2f64 cc = __builtin_msa_fdiv_d(g_v2f64Data, g_v2f64Data1);
	for(i=0; i<2; i++) {
		printf("%.10f,  ", cc[i]);
	}
	printf("\b\b\b}\n\n");
}

void andOrTstFunc()
{
	short i=0;

	////test v16u8
	printf("\n =================andOrTstFunc=====================================================================\n");
	printf("input: 	g_v8i16Data =  {0xff00, 0x00ff, 0xaa00, 0x00aa, 0x5500, 0x0055, 0x0, 0xffff}\n");
	printf("input: 	g_v8i16Data1 = {0x00ff, 0xff00, 0x00aa, 0xaa00, 0x0055, 0x5500, 0xffff, 0xffff}\n");
	printf("output: msa_andq_u8((v16u8)g_v8i16Data, (v16u8)g_v8i16Data1)={");
	v16u8 c = msa_andq_u8((v16u8)g_v8i16Data, (v16u8)g_v8i16Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", c[i]);
	}
	printf("\b\b\b}\n");

	printf("output: msa_andq_s8((v16i8)g_v8i16Data, (v16i8)g_v8i16Data1)={");
	v16i8 cc = msa_andq_s8((v16i8)g_v8i16Data, (v16i8)g_v8i16Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)cc[i]);
	}
	printf("\b\b\b}\n");

	printf("input: 	g_v8i16Data =  {0xff00, 0x00ff, 0xaa00, 0x00aa, 0x5500, 0x0055, 0x0, 0xffff}\n");
	printf("input: 	g_v8i16Data1 = {0x00ff, 0xff00, 0x00aa, 0xaa00, 0x0055, 0x5500, 0xffff, 0xffff}\n");
	printf("output: msa_orrq_u8((v16u8)g_v8i16Data, (v16u8)g_v8i16Data1)={");
	v16u8 ccc = msa_orrq_u8((v16u8)g_v8i16Data, (v16u8)g_v8i16Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", ccc[i]);
	}
	printf("\b\b\b}\n");

	printf("output: msa_orrq_s8((v16i8)g_v8i16Data, (v16i8)g_v8i16Data1)={");
	v16i8 cccc = msa_orrq_s8((v16i8)g_v8i16Data, (v16i8)g_v8i16Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)cccc[i]);
	}
	printf("\b\b\b}\n\n");
}

void eorMvnTstFunc()
{
	short i=0;

	////test v16u8
	printf("\n =================eorMvnTstFunc=====================================================================\n");
	printf("input: 	g_v8i16Data =  {0xff00, 0x00ff, 0xaa00, 0x00aa, 0x5500, 0x0055, 0x0, 0xffff}\n");
	printf("input: 	g_v8i16Data1 = {0x00ff, 0xff00, 0x00aa, 0xaa00, 0x0055, 0x5500, 0xffff, 0xffff}\n");
	printf("output: msa_eorq_u8((v16u8)g_v8i16Data, (v16u8)g_v8i16Data1)={");
	v16u8 c = msa_eorq_u8((v16u8)g_v8i16Data, (v16u8)g_v8i16Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", c[i]);
	}
	printf("\b\b\b}\n");

	printf("output: msa_eorq_s8((v16i8)g_v8i16Data, (v16i8)g_v8i16Data1)={");
	v16i8 cc = msa_eorq_s8((v16i8)g_v8i16Data, (v16i8)g_v8i16Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)cc[i]);
	}
	printf("\b\b\b}\n");

	printf("input: 	g_v8i16Data =  {0xff00, 0x00ff, 0xaa00, 0x00aa, 0x5500, 0x0055, 0x0, 0xffff}\n");
	printf("input: 	g_v8i16Data1 = {0x00ff, 0xff00, 0x00aa, 0xaa00, 0x0055, 0x5500, 0xffff, 0xffff}\n");
	printf("output: msa_mvnq_u8((v16u8)g_v8i16Data)={");
	v16u8 ccc = msa_mvnq_u8((v16u8)g_v8i16Data);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", ccc[i]);
	}
	printf("\b\b\b}\n");

	printf("output: msa_mvnq_u16((v8u16)g_v8i16Data1)={");
	v8u16 cccc = msa_mvnq_u16((v8u16)g_v8i16Data1);
	for(i=0; i<8; i++) {
		printf("0x%04x,  ", (uint16_t)cccc[i]);
	}
	printf("\b\b\b}\n\n");
}

void compareTstFunc()
{
	short i=0;

	////test msa_ceqq
	printf("\n =================compareTstFunc=====================================================================\n");
	printf("====test msa_ceqq=====\n");
	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}\n");
	printf("input: 	g_v16u8Data1 = {255, 254, 253, 252, 251, 250, 249, 248, 128, 127, 126, 125, 124, 123, 122, 121}\n");
	printf("output: c = msa_ceqq_u8(g_v16u8Data, g_v16u8Data)={");
	v16u8 c = msa_ceqq_u8(g_v16u8Data, g_v16u8Data);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: c = msa_ceqq_u8(g_v16u8Data, g_v16u8Data1)={");
	c = msa_ceqq_u8(g_v16u8Data, g_v16u8Data1);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v4f32Data1 = {0.01, -1.01, 2.02, -3.03}\n");
	printf("output: cc = msa_ceqq_f32(g_v4f32Data, g_v4f32Data)={");
	v4u32 cc = msa_ceqq_f32(g_v4f32Data, g_v4f32Data);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: cc = msa_ceqq_f32(g_v4f32Data, g_v4f32Data1)={");
	cc = msa_ceqq_f32(g_v4f32Data, g_v4f32Data1);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n\n");

  ////test msa_cltq
	printf("====test msa_cltq=====\n");
	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}\n");
	printf("input: 	g_v16u8Data1 = {255, 254, 253, 252, 251, 250, 249, 248, 128, 127, 126, 125, 124, 123, 122, 121}\n");
	printf("output: c = msa_cltq_u8(g_v16u8Data, g_v16u8Data)={");
	c = msa_cltq_u8(g_v16u8Data, g_v16u8Data);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: c = msa_cltq_u8(g_v16u8Data, g_v16u8Data1)={");
	c = msa_cltq_u8(g_v16u8Data, g_v16u8Data1);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v4f32Data1 = {0.01, -1.01, 2.02, -3.03}\n");
	printf("output: cc = msa_cltq_f32(g_v4f32Data, g_v4f32Data)={");
	cc = msa_cltq_f32(g_v4f32Data, g_v4f32Data);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: cc = msa_cltq_f32(g_v4f32Data, g_v4f32Data1)={");
	cc = msa_cltq_f32(g_v4f32Data, g_v4f32Data1);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n\n");

  ////test msa_cgtq
	printf("====test msa_cgtq=====\n");
	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}\n");
	printf("input: 	g_v16u8Data1 = {255, 254, 253, 252, 251, 250, 249, 248, 128, 127, 126, 125, 124, 123, 122, 121}\n");
	printf("output: c = msa_cgtq_u8(g_v16u8Data, g_v16u8Data)={");
	c = msa_cgtq_u8(g_v16u8Data, g_v16u8Data);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: c = msa_cgtq_u8(g_v16u8Data, g_v16u8Data1)={");
	c = msa_cgtq_u8(g_v16u8Data, g_v16u8Data1);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v4f32Data1 = {0.01, -1.01, 2.02, -3.03}\n");
	printf("output: cc = msa_cgtq_f32(g_v4f32Data, g_v4f32Data)={");
	cc = msa_cgtq_f32(g_v4f32Data, g_v4f32Data);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: cc = msa_cgtq_f32(g_v4f32Data, g_v4f32Data1)={");
	cc = msa_cgtq_f32(g_v4f32Data, g_v4f32Data1);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n\n");

  ////test msa_cleq
	printf("====test msa_cleq=====\n");
	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}\n");
	printf("input: 	g_v16u8Data1 = {255, 254, 253, 252, 251, 250, 249, 248, 128, 127, 126, 125, 124, 123, 122, 121}\n");
	printf("output: c = msa_cleq_u8(g_v16u8Data, g_v16u8Data)={");
	c = msa_cleq_u8(g_v16u8Data, g_v16u8Data);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: c = msa_cleq_u8(g_v16u8Data, g_v16u8Data1)={");
	c = msa_cleq_u8(g_v16u8Data, g_v16u8Data1);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v4f32Data1 = {0.01, -1.01, 2.02, -3.03}\n");
	printf("output: cc = msa_cleq_f32(g_v4f32Data, g_v4f32Data)={");
	cc = msa_cleq_f32(g_v4f32Data, g_v4f32Data);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: cc = msa_cleq_f32(g_v4f32Data, g_v4f32Data1)={");
	cc = msa_cleq_f32(g_v4f32Data, g_v4f32Data1);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n\n");

  ////test msa_cgeq
	printf("====test msa_cgeq=====\n");
	printf("input: 	g_v16u8Data = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}\n");
	printf("input: 	g_v16u8Data1 = {255, 254, 253, 252, 251, 250, 249, 248, 128, 127, 126, 125, 124, 123, 122, 121}\n");
	printf("output: c = msa_cgeq_u8(g_v16u8Data, g_v16u8Data)={");
	c = msa_cgeq_u8(g_v16u8Data, g_v16u8Data);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: c = msa_cgeq_u8(g_v16u8Data, g_v16u8Data1)={");
	c = msa_cgeq_u8(g_v16u8Data, g_v16u8Data1);
	for(i=0; i<16; i++) {
		printf("0x%x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	g_v4f32Data = {-0.001, 1.001, -2.002, 3.003}, g_v4f32Data1 = {0.01, -1.01, 2.02, -3.03}\n");
	printf("output: cc = msa_cgeq_f32(g_v4f32Data, g_v4f32Data)={");
	cc = msa_cgeq_f32(g_v4f32Data, g_v4f32Data);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n");
	printf("output: cc = msa_cgeq_f32(g_v4f32Data, g_v4f32Data1)={");
	cc = msa_cgeq_f32(g_v4f32Data, g_v4f32Data1);
	for(i=0; i<4; i++) {
		printf("0x%x,  ", (uint32_t)cc[i]);
	}
	printf("\b\b\b}\n\n");
}

void bitshiftTstFunc()
{
	short i=0;
  static v16u8 v16u8Data =  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a};
  static v16i8 v16i8Data =  {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a};
  static v16u8 v16u8Data1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7};
  static v16i8 v16i8Data1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7};

	////test msa_shlq_u8 & msa_shrq_u8
	printf("\n==================bitshiftTstFunc=====================================================================\n");
	printf("====test msa_shlq_u8 & msa_shrq_u8=====\n");
	printf("input: 	v16u8Data = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a}\n");
	printf("input: 	v16u8Data1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7}\n");
	printf("output: c = msa_shlq_u8(v16u8Data, v16i8Data1)={");
	v16u8 c = msa_shlq_u8(v16u8Data, v16i8Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: c = msa_shrq_u8(v16u8Data, v16i8Data1)={");
	c = msa_shrq_u8(v16u8Data, v16i8Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	v16i8Data = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a}\n");
	printf("input: 	v16u8Data1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7}\n");
	printf("output: cc = msa_shlq_s8(v16i8Data, v16i8Data1)={");
	v16i8 cc = msa_shlq_s8(v16i8Data, v16i8Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (int8_t)cc[i]&0xff);
	}
	printf("\b\b\b}\n");
	printf("output: cc = msa_shrq_s8(v16i8Data, v16i8Data1)={");
	cc = msa_shrq_s8(v16i8Data, v16i8Data1);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (int8_t)cc[i]&0xff);
	}
	printf("\b\b\b}\n\n");

	////test msa_shlq_n_u8 & msa_shrq_n_u8
	printf("====test msa_shlq_n_u8 & msa_shrq_n_u8=====\n");
	printf("input: 	v16u8Data = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a}\n");
	printf("output: c = msa_shlq_n_u8(v16u8Data, 4)={");
	c = msa_shlq_n_u8(v16u8Data, 4);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n");
	printf("output: c = msa_shrq_n_u8(v16u8Data, 4)={");
	c = msa_shrq_n_u8(v16u8Data, 4);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	v16i8Data = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a}\n");
	printf("output: cc = msa_shlq_n_s8(v16i8Data, 4)={");
	cc = msa_shlq_n_s8(v16i8Data, 4);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (int8_t)cc[i]&0xff);
	}
	printf("\b\b\b}\n");
	printf("output: cc = msa_shrq_n_s8(v16i8Data, 4)={");
	cc = msa_shrq_n_s8(v16i8Data, 4);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (int8_t)cc[i]&0xff);
	}
	printf("\b\b\b}\n\n");

	////test msa_rshrq_n_u8
	printf("====test msa_rshrq_n_u8=====\n");
	printf("input: 	v16u8Data = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a}\n");
	printf("output: c = msa_rshrq_n_u8(v16u8Data, 4)={");
	c = msa_rshrq_n_u8(v16u8Data, 4);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (uint8_t)c[i]);
	}
	printf("\b\b\b}\n\n");

	printf("input: 	v16i8Data = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a, 0x0a}\n");
	printf("output: cc = msa_rshrq_n_s8(v16i8Data, 4)={");
	cc = msa_rshrq_n_s8(v16i8Data, 4);
	for(i=0; i<16; i++) {
		printf("0x%02x,  ", (int8_t)cc[i]&0xff);
	}
	printf("\b\b\b}\n\n");

}

int main(int argc, char **argv)
{
	getLaneTstFunc();
	combineTstFunc();
	getLowTstFunc();
	getHighTstFunc();
	multiplicationTstFunc();
	vsumTstFunc();
	paddlpTstFunc();
	perfValidTstFunc();
	addvSubvTstFunc();
	longMulTstFunc();
	divTstFunc();
	andOrTstFunc();
	eorMvnTstFunc();
	compareTstFunc();
	bitshiftTstFunc();
}
