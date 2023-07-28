/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include <stdlib.h>
#include <stdio.h>
#include "cint_bas.h"
#include "cart2sph.h"
#include "g1e.h"
#include "g1e_grids.h"
#include "g2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "c2f.h"
/* <NABLA i|RINV |R j> */
void CINTgout1e_int1e_iprinvr(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
G2E_R_J(g1, g0, envs->i_l+1, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+0, envs->j_l, 0, 0);
double s[9];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 9; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g3[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g2[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g2[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g1[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g0[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g0[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g1[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g0[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g0[ix+i] * g0[iy+i] * g3[iz+i];
}
if (gout_empty) {
gout[n*9+0] = + s[0];
gout[n*9+1] = + s[1];
gout[n*9+2] = + s[2];
gout[n*9+3] = + s[3];
gout[n*9+4] = + s[4];
gout[n*9+5] = + s[5];
gout[n*9+6] = + s[6];
gout[n*9+7] = + s[7];
gout[n*9+8] = + s[8];
} else {
gout[n*9+0] += + s[0];
gout[n*9+1] += + s[1];
gout[n*9+2] += + s[2];
gout[n*9+3] += + s[3];
gout[n*9+4] += + s[4];
gout[n*9+5] += + s[5];
gout[n*9+6] += + s[6];
gout[n*9+7] += + s[7];
gout[n*9+8] += + s[8];
}}}
void int1e_iprinvr_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_iprinvr_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_iprinvr;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_iprinvr_cart
CACHE_SIZE_T int1e_iprinvr_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_iprinvr;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_iprinvr_sph
CACHE_SIZE_T int1e_iprinvr_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 1, 0, 0, 2, 1, 0, 9};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_iprinvr;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_iprinvr_spinor
ALL_CINT1E(int1e_iprinvr)
ALL_CINT1E_FORTRAN_(int1e_iprinvr)