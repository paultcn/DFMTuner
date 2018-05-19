/*
 * Copyright (c) 2003, 2007-14 Matteo Frigo
 * Copyright (c) 2003, 2007-14 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Sun Oct 29 08:17:09 EDT 2017 */

#include "dft/codelet-dft.h"

#if defined(ARCH_PREFERS_FMA) || defined(ISA_EXTENSION_PREFERS_FMA)

/* Generated by: ../../../genfft/gen_twiddle_c.native -fma -simd -compact -variables 4 -pipeline-latency 8 -n 10 -name t2fv_10 -include dft/simd/t2f.h */

/*
 * This function contains 51 FP additions, 40 FP multiplications,
 * (or, 33 additions, 22 multiplications, 18 fused multiply/add),
 * 32 stack variables, 4 constants, and 20 memory accesses
 */
#include "dft/simd/t2f.h"

static void t2fv_10(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 18)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 18), MAKE_VOLATILE_STRIDE(10, rs)) {
	       V T4, TA, Tk, Tp, Tq, TE, TF, TG, T9, Te, Tf, TB, TC, TD, T1;
	       V T3, T2;
	       T1 = LD(&(x[0]), ms, &(x[0]));
	       T2 = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
	       T3 = BYTWJ(&(W[TWVL * 8]), T2);
	       T4 = VSUB(T1, T3);
	       TA = VADD(T1, T3);
	       {
		    V Th, To, Tj, Tm;
		    {
			 V Tg, Tn, Ti, Tl;
			 Tg = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 Th = BYTWJ(&(W[TWVL * 6]), Tg);
			 Tn = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 To = BYTWJ(&(W[0]), Tn);
			 Ti = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tj = BYTWJ(&(W[TWVL * 16]), Ti);
			 Tl = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Tm = BYTWJ(&(W[TWVL * 10]), Tl);
		    }
		    Tk = VSUB(Th, Tj);
		    Tp = VSUB(Tm, To);
		    Tq = VADD(Tk, Tp);
		    TE = VADD(Th, Tj);
		    TF = VADD(Tm, To);
		    TG = VADD(TE, TF);
	       }
	       {
		    V T6, Td, T8, Tb;
		    {
			 V T5, Tc, T7, Ta;
			 T5 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 T6 = BYTWJ(&(W[TWVL * 2]), T5);
			 Tc = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 Td = BYTWJ(&(W[TWVL * 4]), Tc);
			 T7 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 T8 = BYTWJ(&(W[TWVL * 12]), T7);
			 Ta = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 Tb = BYTWJ(&(W[TWVL * 14]), Ta);
		    }
		    T9 = VSUB(T6, T8);
		    Te = VSUB(Tb, Td);
		    Tf = VADD(T9, Te);
		    TB = VADD(T6, T8);
		    TC = VADD(Tb, Td);
		    TD = VADD(TB, TC);
	       }
	       {
		    V Tt, Tr, Ts, Tx, Tz, Tv, Tw, Ty, Tu;
		    Tt = VSUB(Tf, Tq);
		    Tr = VADD(Tf, Tq);
		    Ts = VFNMS(LDK(KP250000000), Tr, T4);
		    Tv = VSUB(T9, Te);
		    Tw = VSUB(Tk, Tp);
		    Tx = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), Tw, Tv));
		    Tz = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), Tv, Tw));
		    ST(&(x[WS(rs, 5)]), VADD(T4, Tr), ms, &(x[WS(rs, 1)]));
		    Ty = VFNMS(LDK(KP559016994), Tt, Ts);
		    ST(&(x[WS(rs, 3)]), VFNMSI(Tz, Ty), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 7)]), VFMAI(Tz, Ty), ms, &(x[WS(rs, 1)]));
		    Tu = VFMA(LDK(KP559016994), Tt, Ts);
		    ST(&(x[WS(rs, 1)]), VFNMSI(Tx, Tu), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 9)]), VFMAI(Tx, Tu), ms, &(x[WS(rs, 1)]));
	       }
	       {
		    V TJ, TH, TI, TN, TP, TL, TM, TO, TK;
		    TJ = VSUB(TD, TG);
		    TH = VADD(TD, TG);
		    TI = VFNMS(LDK(KP250000000), TH, TA);
		    TL = VSUB(TE, TF);
		    TM = VSUB(TB, TC);
		    TN = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), TM, TL));
		    TP = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), TL, TM));
		    ST(&(x[0]), VADD(TA, TH), ms, &(x[0]));
		    TO = VFMA(LDK(KP559016994), TJ, TI);
		    ST(&(x[WS(rs, 4)]), VFMAI(TP, TO), ms, &(x[0]));
		    ST(&(x[WS(rs, 6)]), VFNMSI(TP, TO), ms, &(x[0]));
		    TK = VFNMS(LDK(KP559016994), TJ, TI);
		    ST(&(x[WS(rs, 2)]), VFMAI(TN, TK), ms, &(x[0]));
		    ST(&(x[WS(rs, 8)]), VFNMSI(TN, TK), ms, &(x[0]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 10, XSIMD_STRING("t2fv_10"), twinstr, &GENUS, {33, 22, 18, 0}, 0, 0, 0 };

void XSIMD(codelet_t2fv_10) (planner *p) {
     X(kdft_dit_register) (p, t2fv_10, &desc);
}
#else

/* Generated by: ../../../genfft/gen_twiddle_c.native -simd -compact -variables 4 -pipeline-latency 8 -n 10 -name t2fv_10 -include dft/simd/t2f.h */

/*
 * This function contains 51 FP additions, 30 FP multiplications,
 * (or, 45 additions, 24 multiplications, 6 fused multiply/add),
 * 32 stack variables, 4 constants, and 20 memory accesses
 */
#include "dft/simd/t2f.h"

static void t2fv_10(R *ri, R *ii, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     {
	  INT m;
	  R *x;
	  x = ri;
	  for (m = mb, W = W + (mb * ((TWVL / VL) * 18)); m < me; m = m + VL, x = x + (VL * ms), W = W + (TWVL * 18), MAKE_VOLATILE_STRIDE(10, rs)) {
	       V Tr, TH, Tg, Tl, Tm, TA, TB, TJ, T5, Ta, Tb, TD, TE, TI, To;
	       V Tq, Tp;
	       To = LD(&(x[0]), ms, &(x[0]));
	       Tp = LD(&(x[WS(rs, 5)]), ms, &(x[WS(rs, 1)]));
	       Tq = BYTWJ(&(W[TWVL * 8]), Tp);
	       Tr = VSUB(To, Tq);
	       TH = VADD(To, Tq);
	       {
		    V Td, Tk, Tf, Ti;
		    {
			 V Tc, Tj, Te, Th;
			 Tc = LD(&(x[WS(rs, 4)]), ms, &(x[0]));
			 Td = BYTWJ(&(W[TWVL * 6]), Tc);
			 Tj = LD(&(x[WS(rs, 1)]), ms, &(x[WS(rs, 1)]));
			 Tk = BYTWJ(&(W[0]), Tj);
			 Te = LD(&(x[WS(rs, 9)]), ms, &(x[WS(rs, 1)]));
			 Tf = BYTWJ(&(W[TWVL * 16]), Te);
			 Th = LD(&(x[WS(rs, 6)]), ms, &(x[0]));
			 Ti = BYTWJ(&(W[TWVL * 10]), Th);
		    }
		    Tg = VSUB(Td, Tf);
		    Tl = VSUB(Ti, Tk);
		    Tm = VADD(Tg, Tl);
		    TA = VADD(Td, Tf);
		    TB = VADD(Ti, Tk);
		    TJ = VADD(TA, TB);
	       }
	       {
		    V T2, T9, T4, T7;
		    {
			 V T1, T8, T3, T6;
			 T1 = LD(&(x[WS(rs, 2)]), ms, &(x[0]));
			 T2 = BYTWJ(&(W[TWVL * 2]), T1);
			 T8 = LD(&(x[WS(rs, 3)]), ms, &(x[WS(rs, 1)]));
			 T9 = BYTWJ(&(W[TWVL * 4]), T8);
			 T3 = LD(&(x[WS(rs, 7)]), ms, &(x[WS(rs, 1)]));
			 T4 = BYTWJ(&(W[TWVL * 12]), T3);
			 T6 = LD(&(x[WS(rs, 8)]), ms, &(x[0]));
			 T7 = BYTWJ(&(W[TWVL * 14]), T6);
		    }
		    T5 = VSUB(T2, T4);
		    Ta = VSUB(T7, T9);
		    Tb = VADD(T5, Ta);
		    TD = VADD(T2, T4);
		    TE = VADD(T7, T9);
		    TI = VADD(TD, TE);
	       }
	       {
		    V Tn, Ts, Tt, Tx, Tz, Tv, Tw, Ty, Tu;
		    Tn = VMUL(LDK(KP559016994), VSUB(Tb, Tm));
		    Ts = VADD(Tb, Tm);
		    Tt = VFNMS(LDK(KP250000000), Ts, Tr);
		    Tv = VSUB(T5, Ta);
		    Tw = VSUB(Tg, Tl);
		    Tx = VBYI(VFMA(LDK(KP951056516), Tv, VMUL(LDK(KP587785252), Tw)));
		    Tz = VBYI(VFNMS(LDK(KP587785252), Tv, VMUL(LDK(KP951056516), Tw)));
		    ST(&(x[WS(rs, 5)]), VADD(Tr, Ts), ms, &(x[WS(rs, 1)]));
		    Ty = VSUB(Tt, Tn);
		    ST(&(x[WS(rs, 3)]), VSUB(Ty, Tz), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 7)]), VADD(Tz, Ty), ms, &(x[WS(rs, 1)]));
		    Tu = VADD(Tn, Tt);
		    ST(&(x[WS(rs, 1)]), VSUB(Tu, Tx), ms, &(x[WS(rs, 1)]));
		    ST(&(x[WS(rs, 9)]), VADD(Tx, Tu), ms, &(x[WS(rs, 1)]));
	       }
	       {
		    V TM, TK, TL, TG, TO, TC, TF, TP, TN;
		    TM = VMUL(LDK(KP559016994), VSUB(TI, TJ));
		    TK = VADD(TI, TJ);
		    TL = VFNMS(LDK(KP250000000), TK, TH);
		    TC = VSUB(TA, TB);
		    TF = VSUB(TD, TE);
		    TG = VBYI(VFNMS(LDK(KP587785252), TF, VMUL(LDK(KP951056516), TC)));
		    TO = VBYI(VFMA(LDK(KP951056516), TF, VMUL(LDK(KP587785252), TC)));
		    ST(&(x[0]), VADD(TH, TK), ms, &(x[0]));
		    TP = VADD(TM, TL);
		    ST(&(x[WS(rs, 4)]), VADD(TO, TP), ms, &(x[0]));
		    ST(&(x[WS(rs, 6)]), VSUB(TP, TO), ms, &(x[0]));
		    TN = VSUB(TL, TM);
		    ST(&(x[WS(rs, 2)]), VADD(TG, TN), ms, &(x[0]));
		    ST(&(x[WS(rs, 8)]), VSUB(TN, TG), ms, &(x[0]));
	       }
	  }
     }
     VLEAVE();
}

static const tw_instr twinstr[] = {
     VTW(0, 1),
     VTW(0, 2),
     VTW(0, 3),
     VTW(0, 4),
     VTW(0, 5),
     VTW(0, 6),
     VTW(0, 7),
     VTW(0, 8),
     VTW(0, 9),
     {TW_NEXT, VL, 0}
};

static const ct_desc desc = { 10, XSIMD_STRING("t2fv_10"), twinstr, &GENUS, {45, 24, 6, 0}, 0, 0, 0 };

void XSIMD(codelet_t2fv_10) (planner *p) {
     X(kdft_dit_register) (p, t2fv_10, &desc);
}
#endif
