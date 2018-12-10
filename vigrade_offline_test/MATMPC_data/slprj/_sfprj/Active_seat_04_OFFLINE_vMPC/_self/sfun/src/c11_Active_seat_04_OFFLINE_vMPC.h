#ifndef __c11_Active_seat_04_OFFLINE_vMPC_h__
#define __c11_Active_seat_04_OFFLINE_vMPC_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct
#define typedef_SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_Active_seat_04_OFFLINE_vMPC;
  void *c11_fEmlrtCtx;
  real_T *c11_offset_lat_sup;
  real_T *c11_ay;
  real_T *c11_p_out_lat_sup_sx;
  real_T *c11_gain_lat_sup;
  real_T *c11_gain;
  real_T *c11_NLGain;
} SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct;

#endif                                 /*typedef_SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c11_Active_seat_04_OFFLINE_vMPC_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c11_Active_seat_04_OFFLINE_vMPC_get_check_sum(mxArray *plhs[]);
extern void c11_Active_seat_04_OFFLINE_vMPC_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
