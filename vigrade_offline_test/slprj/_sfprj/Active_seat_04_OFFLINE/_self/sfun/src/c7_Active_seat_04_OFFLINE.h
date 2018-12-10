#ifndef __c7_Active_seat_04_OFFLINE_h__
#define __c7_Active_seat_04_OFFLINE_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_struct_rC8GFswl8k7lVjTnIPhqnB_tag
#define struct_struct_rC8GFswl8k7lVjTnIPhqnB_tag

struct struct_rC8GFswl8k7lVjTnIPhqnB_tag
{
  real_T fcx;
  real_T fcy;
  real_T fcz;
  real_T Ts;
};

#endif                                 /*struct_struct_rC8GFswl8k7lVjTnIPhqnB_tag*/

#ifndef typedef_c7_struct_rC8GFswl8k7lVjTnIPhqnB
#define typedef_c7_struct_rC8GFswl8k7lVjTnIPhqnB

typedef struct struct_rC8GFswl8k7lVjTnIPhqnB_tag
  c7_struct_rC8GFswl8k7lVjTnIPhqnB;

#endif                                 /*typedef_c7_struct_rC8GFswl8k7lVjTnIPhqnB*/

#ifndef typedef_SFc7_Active_seat_04_OFFLINEInstanceStruct
#define typedef_SFc7_Active_seat_04_OFFLINEInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_Active_seat_04_OFFLINE;
  c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_filter_pars;
  real_T c7_az_state;
  boolean_T c7_az_state_not_empty;
  real_T c7_ay_state;
  boolean_T c7_ay_state_not_empty;
  real_T c7_Az;
  boolean_T c7_Az_not_empty;
  real_T c7_Bz;
  boolean_T c7_Bz_not_empty;
  real_T c7_Cz;
  boolean_T c7_Cz_not_empty;
  real_T c7_Dz;
  boolean_T c7_Dz_not_empty;
  real_T c7_Ay;
  boolean_T c7_Ay_not_empty;
  real_T c7_By;
  boolean_T c7_By_not_empty;
  real_T c7_Cy;
  boolean_T c7_Cy_not_empty;
  real_T c7_Dy;
  boolean_T c7_Dy_not_empty;
  void *c7_fEmlrtCtx;
  real_T *c7_ay_out;
  real_T *c7_ay_in;
  real_T *c7_az_in;
  real_T *c7_az_out;
} SFc7_Active_seat_04_OFFLINEInstanceStruct;

#endif                                 /*typedef_SFc7_Active_seat_04_OFFLINEInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c7_Active_seat_04_OFFLINE_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_Active_seat_04_OFFLINE_get_check_sum(mxArray *plhs[]);
extern void c7_Active_seat_04_OFFLINE_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
