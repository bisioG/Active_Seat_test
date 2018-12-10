/* Include files */

#include "Active_seat_04_OFFLINE_sfun.h"
#include "c7_Active_seat_04_OFFLINE.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Active_seat_04_OFFLINE_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c7_debug_family_names[17] = { "nargin", "nargout", "ay_in",
  "az_in", "filter_pars", "ay_out", "az_out", "az_state", "ay_state", "Az", "Bz",
  "Cz", "Dz", "Ay", "By", "Cy", "Dy" };

static const char * c7_b_debug_family_names[19] = { "B0", "B2", "B1", "A0", "A1",
  "A2", "a0", "a1", "b1", "a0c", "a1c", "nargin", "nargout", "wc", "Ts", "A",
  "B", "C", "D" };

/* Function Declarations */
static void initialize_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void initialize_params_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void enable_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void disable_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void c7_update_debugger_state_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void set_sim_state_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance, const mxArray
   *c7_st);
static void finalize_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void sf_gateway_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void mdl_start_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void initSimStructsc7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_b_Dy, const char_T *c7_identifier, boolean_T
  *c7_svPtr);
static real_T c7_b_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  boolean_T *c7_svPtr);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static real_T c7_c_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_b_az_out, const char_T *c7_identifier);
static real_T c7_d_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_e_emlrt_marshallIn
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance, const mxArray *c7_u,
   const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_butter1_lp(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, real_T c7_wc, real_T c7_Ts, real_T *c7_A, real_T *c7_B, real_T
  *c7_C, real_T *c7_D);
static void c7_error(SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_f_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static uint8_T c7_g_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Active_seat_04_OFFLINE, const
  char_T *c7_identifier);
static uint8_T c7_h_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void init_dsm_address_info(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc7_Active_seat_04_OFFLINE(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c7_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_az_state_not_empty = false;
  chartInstance->c7_ay_state_not_empty = false;
  chartInstance->c7_Az_not_empty = false;
  chartInstance->c7_Bz_not_empty = false;
  chartInstance->c7_Cz_not_empty = false;
  chartInstance->c7_Dz_not_empty = false;
  chartInstance->c7_Ay_not_empty = false;
  chartInstance->c7_By_not_empty = false;
  chartInstance->c7_Cy_not_empty = false;
  chartInstance->c7_Dy_not_empty = false;
  chartInstance->c7_is_active_c7_Active_seat_04_OFFLINE = 0U;
}

static void initialize_params_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  const mxArray *c7_m0 = NULL;
  static const char * c7_fieldNames[4] = { "fcx", "fcy", "fcz", "Ts" };

  const mxArray *c7_mxField;
  c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_r0;
  c7_m0 = sf_mex_get_sfun_param(chartInstance->S, 0, 1);
  sf_mex_check_bus_parameter(c7_m0, 4, c7_fieldNames,
    "struct_rC8GFswl8k7lVjTnIPhqnB");
  c7_mxField = sf_mex_getfield(c7_m0, "fcx", "filter_pars", 0);
  sf_mex_import_named("filter_pars", sf_mex_dup(c7_mxField), &c7_r0.fcx, 1, 0,
                      0U, 0, 0U, 0);
  c7_mxField = sf_mex_getfield(c7_m0, "fcy", "filter_pars", 0);
  sf_mex_import_named("filter_pars", sf_mex_dup(c7_mxField), &c7_r0.fcy, 1, 0,
                      0U, 0, 0U, 0);
  c7_mxField = sf_mex_getfield(c7_m0, "fcz", "filter_pars", 0);
  sf_mex_import_named("filter_pars", sf_mex_dup(c7_mxField), &c7_r0.fcz, 1, 0,
                      0U, 0, 0U, 0);
  c7_mxField = sf_mex_getfield(c7_m0, "Ts", "filter_pars", 0);
  sf_mex_import_named("filter_pars", sf_mex_dup(c7_mxField), &c7_r0.Ts, 1, 0, 0U,
                      0, 0U, 0);
  sf_mex_destroy(&c7_m0);
  chartInstance->c7_filter_pars = c7_r0;
}

static void enable_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  const mxArray *c7_b_y = NULL;
  real_T c7_b_hoistedGlobal;
  const mxArray *c7_c_y = NULL;
  real_T c7_c_hoistedGlobal;
  const mxArray *c7_d_y = NULL;
  real_T c7_d_hoistedGlobal;
  const mxArray *c7_e_y = NULL;
  real_T c7_e_hoistedGlobal;
  const mxArray *c7_f_y = NULL;
  real_T c7_f_hoistedGlobal;
  const mxArray *c7_g_y = NULL;
  real_T c7_g_hoistedGlobal;
  const mxArray *c7_h_y = NULL;
  real_T c7_h_hoistedGlobal;
  const mxArray *c7_i_y = NULL;
  real_T c7_i_hoistedGlobal;
  const mxArray *c7_j_y = NULL;
  real_T c7_j_hoistedGlobal;
  const mxArray *c7_k_y = NULL;
  real_T c7_k_hoistedGlobal;
  const mxArray *c7_l_y = NULL;
  real_T c7_l_hoistedGlobal;
  const mxArray *c7_m_y = NULL;
  uint8_T c7_m_hoistedGlobal;
  const mxArray *c7_n_y = NULL;
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(13, 1), false);
  c7_hoistedGlobal = *chartInstance->c7_ay_out;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *chartInstance->c7_az_out;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = chartInstance->c7_Ay;
  c7_d_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_d_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = chartInstance->c7_Az;
  c7_e_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_e_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_e_hoistedGlobal = chartInstance->c7_By;
  c7_f_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_f_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_f_hoistedGlobal = chartInstance->c7_Bz;
  c7_g_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_g_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_g_hoistedGlobal = chartInstance->c7_Cy;
  c7_h_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_h_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 6, c7_h_y);
  c7_h_hoistedGlobal = chartInstance->c7_Cz;
  c7_i_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_i_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_i_y, sf_mex_create("y", &c7_h_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 7, c7_i_y);
  c7_i_hoistedGlobal = chartInstance->c7_Dy;
  c7_j_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_j_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_j_y, sf_mex_create("y", &c7_i_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 8, c7_j_y);
  c7_j_hoistedGlobal = chartInstance->c7_Dz;
  c7_k_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_k_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_k_y, sf_mex_create("y", &c7_j_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 9, c7_k_y);
  c7_k_hoistedGlobal = chartInstance->c7_ay_state;
  c7_l_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_l_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_l_y, sf_mex_create("y", &c7_k_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 10, c7_l_y);
  c7_l_hoistedGlobal = chartInstance->c7_az_state;
  c7_m_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_m_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0),
                  false);
  } else {
    sf_mex_assign(&c7_m_y, sf_mex_create("y", &c7_l_hoistedGlobal, 0, 0U, 0U, 0U,
      0), false);
  }

  sf_mex_setcell(c7_y, 11, c7_m_y);
  c7_m_hoistedGlobal = chartInstance->c7_is_active_c7_Active_seat_04_OFFLINE;
  c7_n_y = NULL;
  sf_mex_assign(&c7_n_y, sf_mex_create("y", &c7_m_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c7_y, 12, c7_n_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance, const mxArray
   *c7_st)
{
  const mxArray *c7_u;
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  *chartInstance->c7_ay_out = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ay_out", c7_u, 0)), "ay_out");
  *chartInstance->c7_az_out = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("az_out", c7_u, 1)), "az_out");
  chartInstance->c7_Ay = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Ay", c7_u, 2)), "Ay", &chartInstance->c7_Ay_not_empty);
  chartInstance->c7_Az = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Az", c7_u, 3)), "Az", &chartInstance->c7_Az_not_empty);
  chartInstance->c7_By = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("By", c7_u, 4)), "By", &chartInstance->c7_By_not_empty);
  chartInstance->c7_Bz = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Bz", c7_u, 5)), "Bz", &chartInstance->c7_Bz_not_empty);
  chartInstance->c7_Cy = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Cy", c7_u, 6)), "Cy", &chartInstance->c7_Cy_not_empty);
  chartInstance->c7_Cz = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Cz", c7_u, 7)), "Cz", &chartInstance->c7_Cz_not_empty);
  chartInstance->c7_Dy = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Dy", c7_u, 8)), "Dy", &chartInstance->c7_Dy_not_empty);
  chartInstance->c7_Dz = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("Dz", c7_u, 9)), "Dz", &chartInstance->c7_Dz_not_empty);
  chartInstance->c7_ay_state = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("ay_state", c7_u, 10)), "ay_state",
    &chartInstance->c7_ay_state_not_empty);
  chartInstance->c7_az_state = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("az_state", c7_u, 11)), "az_state",
    &chartInstance->c7_az_state_not_empty);
  chartInstance->c7_is_active_c7_Active_seat_04_OFFLINE = c7_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(
       "is_active_c7_Active_seat_04_OFFLINE", c7_u, 12)),
     "is_active_c7_Active_seat_04_OFFLINE");
  sf_mex_destroy(&c7_u);
  c7_update_debugger_state_c7_Active_seat_04_OFFLINE(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void finalize_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  real_T c7_hoistedGlobal;
  real_T c7_b_hoistedGlobal;
  real_T c7_b_ay_in;
  real_T c7_b_az_in;
  c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_b_filter_pars;
  uint32_T c7_debug_family_var_map[17];
  real_T c7_nargin = 3.0;
  real_T c7_nargout = 2.0;
  real_T c7_b_ay_out;
  real_T c7_b_az_out;
  real_T c7_b_Az;
  real_T c7_b_Bz;
  real_T c7_b_Cz;
  real_T c7_b_Dz;
  real_T c7_b_Ay;
  real_T c7_b_By;
  real_T c7_b_Cy;
  real_T c7_b_Dy;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_az_in, 1U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_ay_in, 0U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  c7_hoistedGlobal = *chartInstance->c7_ay_in;
  c7_b_hoistedGlobal = *chartInstance->c7_az_in;
  c7_b_ay_in = c7_hoistedGlobal;
  c7_b_az_in = c7_b_hoistedGlobal;
  c7_b_filter_pars = chartInstance->c7_filter_pars;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c7_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_ay_in, 2U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c7_b_az_in, 3U, c7_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_filter_pars, 4U,
    c7_c_sf_marshallOut, c7_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_ay_out, 5U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_az_out, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_az_state, 7U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_ay_state, 8U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Az, 9U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Bz, 10U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Cz, 11U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Dz, 12U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Ay, 13U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_By, 14U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Cy, 15U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&chartInstance->c7_Dy, 16U,
    c7_sf_marshallOut, c7_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 14);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 15);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 16);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 18);
  if (CV_EML_IF(0, 1, 0, !chartInstance->c7_az_state_not_empty)) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 19);
    chartInstance->c7_az_state = 0.0;
    chartInstance->c7_az_state_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 20);
    chartInstance->c7_ay_state = 0.0;
    chartInstance->c7_ay_state_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 21);
    c7_butter1_lp(chartInstance, 6.2831853071795862 * c7_b_filter_pars.fcz,
                  c7_b_filter_pars.Ts, &c7_b_Az, &c7_b_Bz, &c7_b_Cz, &c7_b_Dz);
    chartInstance->c7_Az = c7_b_Az;
    chartInstance->c7_Az_not_empty = true;
    chartInstance->c7_Bz = c7_b_Bz;
    chartInstance->c7_Bz_not_empty = true;
    chartInstance->c7_Cz = c7_b_Cz;
    chartInstance->c7_Cz_not_empty = true;
    chartInstance->c7_Dz = c7_b_Dz;
    chartInstance->c7_Dz_not_empty = true;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 22);
    c7_butter1_lp(chartInstance, 6.2831853071795862 * c7_b_filter_pars.fcy,
                  c7_b_filter_pars.Ts, &c7_b_Ay, &c7_b_By, &c7_b_Cy, &c7_b_Dy);
    chartInstance->c7_Ay = c7_b_Ay;
    chartInstance->c7_Ay_not_empty = true;
    chartInstance->c7_By = c7_b_By;
    chartInstance->c7_By_not_empty = true;
    chartInstance->c7_Cy = c7_b_Cy;
    chartInstance->c7_Cy_not_empty = true;
    chartInstance->c7_Dy = c7_b_Dy;
    chartInstance->c7_Dy_not_empty = true;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 25);
  chartInstance->c7_az_state = chartInstance->c7_Az * chartInstance->c7_az_state
    + chartInstance->c7_Bz * c7_b_az_in;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 26);
  c7_b_az_out = chartInstance->c7_Cz * chartInstance->c7_az_state +
    chartInstance->c7_Dz * c7_b_az_in;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 27);
  chartInstance->c7_ay_state = chartInstance->c7_Ay * chartInstance->c7_ay_state
    + chartInstance->c7_By * c7_b_ay_in;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 28);
  c7_b_ay_out = chartInstance->c7_Cy * chartInstance->c7_ay_state +
    chartInstance->c7_Dy * c7_b_ay_in;
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c7_ay_out = c7_b_ay_out;
  *chartInstance->c7_az_out = c7_b_az_out;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Active_seat_04_OFFLINEMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_ay_out, 2U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c7_az_out, 3U, 1U, 0U,
                        chartInstance->c7_sfEvent, false);
}

static void mdl_start_c7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc7_Active_seat_04_OFFLINE
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)(c7_machineNumber);
  (void)(c7_chartNumber);
  (void)(c7_instanceNumber);
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  if (!chartInstance->c7_Dy_not_empty) {
    sf_mex_assign(&c7_y, sf_mex_create("y", NULL, 0, 0U, 1U, 0U, 2, 0, 0), false);
  } else {
    sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  }

  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_b_Dy, const char_T *c7_identifier, boolean_T
  *c7_svPtr)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = (const char *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Dy), &c7_thisId,
    c7_svPtr);
  sf_mex_destroy(&c7_b_Dy);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId,
  boolean_T *c7_svPtr)
{
  real_T c7_y;
  real_T c7_d0;
  (void)chartInstance;
  if (mxIsEmpty(c7_u)) {
    *c7_svPtr = false;
  } else {
    *c7_svPtr = true;
    sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
    c7_y = c7_d0;
  }

  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_Dy;
  const char_T *c7_identifier;
  boolean_T *c7_svPtr;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_b_Dy = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_svPtr = &chartInstance->c7_Dy_not_empty;
  c7_thisId.fIdentifier = (const char *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_Dy), &c7_thisId,
    c7_svPtr);
  sf_mex_destroy(&c7_b_Dy);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_c_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_b_az_out, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = (const char *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_az_out),
    &c7_thisId);
  sf_mex_destroy(&c7_b_az_out);
  return c7_y;
}

static real_T c7_d_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d1;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d1, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_az_out;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_b_az_out = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = (const char *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_az_out),
    &c7_thisId);
  sf_mex_destroy(&c7_b_az_out);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_u;
  const mxArray *c7_y = NULL;
  real_T c7_b_u;
  const mxArray *c7_b_y = NULL;
  real_T c7_c_u;
  const mxArray *c7_c_y = NULL;
  real_T c7_d_u;
  const mxArray *c7_d_y = NULL;
  real_T c7_e_u;
  const mxArray *c7_e_y = NULL;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(c7_struct_rC8GFswl8k7lVjTnIPhqnB *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c7_b_u = c7_u.fcx;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_b_y, "fcx", "fcx", 0);
  c7_c_u = c7_u.fcy;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_c_y, "fcy", "fcy", 0);
  c7_d_u = c7_u.fcz;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_d_y, "fcz", "fcz", 0);
  c7_e_u = c7_u.Ts;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c7_y, c7_e_y, "Ts", "Ts", 0);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_e_emlrt_marshallIn
  (SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance, const mxArray *c7_u,
   const emlrtMsgIdentifier *c7_parentId)
{
  c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_y;
  emlrtMsgIdentifier c7_thisId;
  static const char * c7_fieldNames[4] = { "fcx", "fcy", "fcz", "Ts" };

  c7_thisId.fParent = c7_parentId;
  c7_thisId.bParentIsCell = false;
  sf_mex_check_struct(c7_parentId, c7_u, 4, c7_fieldNames, 0U, NULL);
  c7_thisId.fIdentifier = "fcx";
  c7_y.fcx = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "fcx", "fcx", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "fcy";
  c7_y.fcy = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "fcy", "fcy", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "fcz";
  c7_y.fcz = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c7_u, "fcz", "fcz", 0)), &c7_thisId);
  c7_thisId.fIdentifier = "Ts";
  c7_y.Ts = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c7_u,
    "Ts", "Ts", 0)), &c7_thisId);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_filter_pars;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  c7_struct_rC8GFswl8k7lVjTnIPhqnB c7_y;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_b_filter_pars = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = (const char *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_filter_pars),
    &c7_thisId);
  sf_mex_destroy(&c7_b_filter_pars);
  *(c7_struct_rC8GFswl8k7lVjTnIPhqnB *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_Active_seat_04_OFFLINE_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static void c7_butter1_lp(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, real_T c7_wc, real_T c7_Ts, real_T *c7_A, real_T *c7_B, real_T
  *c7_C, real_T *c7_D)
{
  uint32_T c7_debug_family_var_map[19];
  real_T c7_B0;
  real_T c7_B2;
  real_T c7_B1;
  real_T c7_A0;
  real_T c7_A1;
  real_T c7_A2;
  real_T c7_a0;
  real_T c7_a1;
  real_T c7_b1;
  real_T c7_a0c;
  real_T c7_a1c;
  real_T c7_nargin = 2.0;
  real_T c7_nargout = 4.0;
  real_T c7_b_A;
  real_T c7_x;
  real_T c7_b_x;
  real_T c7_y;
  real_T c7_c_x;
  real_T c7_d_x;
  real_T c7_b_B;
  real_T c7_b_y;
  real_T c7_c_y;
  real_T c7_a;
  real_T c7_b_a;
  real_T c7_c_a;
  real_T c7_e_x;
  real_T c7_d_a;
  real_T c7_c;
  boolean_T c7_p;
  real_T c7_c_A;
  real_T c7_c_B;
  real_T c7_f_x;
  real_T c7_d_y;
  real_T c7_g_x;
  real_T c7_e_y;
  real_T c7_d_A;
  real_T c7_d_B;
  real_T c7_h_x;
  real_T c7_f_y;
  real_T c7_i_x;
  real_T c7_g_y;
  real_T c7_e_A;
  real_T c7_e_B;
  real_T c7_j_x;
  real_T c7_h_y;
  real_T c7_k_x;
  real_T c7_i_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c7_b_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_B0, 0U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_B2, 1U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_B1, 2U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_A0, 3U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_A1, 4U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_A2, 5U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_a0, 6U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_a1, 7U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b1, 8U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_a0c, 9U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_a1c, 10U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 11U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 12U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_wc, 13U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_Ts, 14U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_A, 15U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_B, 16U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_C, 17U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c7_D, 18U, c7_b_sf_marshallOut,
    c7_b_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 33);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c7_wc, 0.0, -1, 0U, c7_wc
        == 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 34);
    *c7_A = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 35);
    *c7_B = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 36);
    *c7_C = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 37);
    *c7_D = 0.0;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 39);
    c7_B0 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 40);
    c7_B2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 41);
    c7_B1 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 42);
    c7_A0 = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 43);
    c7_A1 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 44);
    c7_A2 = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 45);
    c7_b_A = c7_wc;
    c7_x = c7_b_A;
    c7_b_x = c7_x;
    c7_y = c7_b_x / 2.0;
    c7_c_x = c7_y * c7_Ts;
    c7_d_x = c7_c_x;
    c7_d_x = muDoubleScalarTan(c7_d_x);
    c7_b_B = c7_d_x;
    c7_b_y = c7_b_B;
    c7_c_y = c7_b_y;
    *c7_C = 1.0 / c7_c_y;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 46);
    c7_a = *c7_C;
    c7_b_a = c7_a;
    c7_c_a = c7_b_a;
    c7_e_x = c7_c_a;
    c7_d_a = c7_e_x;
    c7_c = c7_d_a * c7_d_a;
    c7_p = false;
    if (c7_p) {
      c7_error(chartInstance);
    }

    *c7_A = (c7_B0 + c7_B1 * *c7_C) + c7_B2 * c7_c;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 47);
    c7_c_A = c7_A0 + c7_A1 * *c7_C;
    c7_c_B = *c7_A;
    c7_f_x = c7_c_A;
    c7_d_y = c7_c_B;
    c7_g_x = c7_f_x;
    c7_e_y = c7_d_y;
    c7_a0 = c7_g_x / c7_e_y;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 48);
    c7_d_A = c7_A0 + c7_A1 * *c7_C;
    c7_d_B = *c7_A;
    c7_h_x = c7_d_A;
    c7_f_y = c7_d_B;
    c7_i_x = c7_h_x;
    c7_g_y = c7_f_y;
    c7_a1 = c7_i_x / c7_g_y;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 49);
    c7_e_A = c7_B0 - c7_B1 * *c7_C;
    c7_e_B = *c7_A;
    c7_j_x = c7_e_A;
    c7_h_y = c7_e_B;
    c7_k_x = c7_j_x;
    c7_i_y = c7_h_y;
    c7_b1 = c7_k_x / c7_i_y;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 51);
    c7_a0c = c7_a0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 52);
    c7_a1c = c7_a1 - c7_b1 * c7_a0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 54);
    *c7_A = -c7_b1;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 55);
    *c7_B = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 56);
    *c7_C = c7_a1c;
    _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, 57);
    *c7_D = c7_a0c;
  }

  _SFD_EML_CALL(0U, chartInstance->c7_sfEvent, -57);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c7_error(SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance)
{
  const mxArray *c7_y = NULL;
  static char_T c7_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", c7_cv0, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c7_y));
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_f_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i0, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = (const char *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static uint8_T c7_g_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_b_is_active_c7_Active_seat_04_OFFLINE, const
  char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = (const char *)c7_identifier;
  c7_thisId.fParent = NULL;
  c7_thisId.bParentIsCell = false;
  c7_y = c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_is_active_c7_Active_seat_04_OFFLINE), &c7_thisId);
  sf_mex_destroy(&c7_b_is_active_c7_Active_seat_04_OFFLINE);
  return c7_y;
}

static uint8_T c7_h_emlrt_marshallIn(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void init_dsm_address_info(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc7_Active_seat_04_OFFLINEInstanceStruct
  *chartInstance)
{
  chartInstance->c7_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c7_ay_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_ay_in = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c7_az_in = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c7_az_out = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c7_Active_seat_04_OFFLINE_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(358145332U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2582244205U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(341791713U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3029698199U);
}

mxArray* sf_c7_Active_seat_04_OFFLINE_get_post_codegen_info(void);
mxArray *sf_c7_Active_seat_04_OFFLINE_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("aozjo2Wqm0KT7tYkSEvfAF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c7_Active_seat_04_OFFLINE_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_Active_seat_04_OFFLINE_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_Active_seat_04_OFFLINE_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("pre");
  mxArray *fallbackReason = mxCreateString("hasBreakpoints");
  mxArray *hiddenFallbackType = mxCreateString("none");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c7_Active_seat_04_OFFLINE_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c7_Active_seat_04_OFFLINE_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c7_Active_seat_04_OFFLINE(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[9],T\"ay_out\",},{M[1],M[5],T\"az_out\",},{M[4],M[0],T\"Ay\",S'l','i','p'{{M1x2[578 580],M[0],}}},{M[4],M[0],T\"Az\",S'l','i','p'{{M1x2[523 525],M[0],}}},{M[4],M[0],T\"By\",S'l','i','p'{{M1x2[581 583],M[0],}}},{M[4],M[0],T\"Bz\",S'l','i','p'{{M1x2[526 528],M[0],}}},{M[4],M[0],T\"Cy\",S'l','i','p'{{M1x2[584 586],M[0],}}},{M[4],M[0],T\"Cz\",S'l','i','p'{{M1x2[529 531],M[0],}}},{M[4],M[0],T\"Dy\",S'l','i','p'{{M1x2[587 589],M[0],}}},{M[4],M[0],T\"Dz\",S'l','i','p'{{M1x2[532 534],M[0],}}}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[4],M[0],T\"ay_state\",S'l','i','p'{{M1x2[477 485],M[0],}}},{M[4],M[0],T\"az_state\",S'l','i','p'{{M1x2[468 476],M[0],}}},{M[8],M[0],T\"is_active_c7_Active_seat_04_OFFLINE\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 13, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_Active_seat_04_OFFLINE_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance =
      (SFc7_Active_seat_04_OFFLINEInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Active_seat_04_OFFLINEMachineNumber_,
           7,
           1,
           1,
           0,
           5,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Active_seat_04_OFFLINEMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Active_seat_04_OFFLINEMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Active_seat_04_OFFLINEMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"ay_in");
          _SFD_SET_DATA_PROPS(1,1,1,0,"az_in");
          _SFD_SET_DATA_PROPS(2,2,0,1,"ay_out");
          _SFD_SET_DATA_PROPS(3,2,0,1,"az_out");
          _SFD_SET_DATA_PROPS(4,10,0,0,"filter_pars");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,2,0,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",10,-1,961);
        _SFD_CV_INIT_EML_FCN(0,1,"butter1_lp",961,-1,1469);
        _SFD_CV_INIT_EML_IF(0,1,0,622,642,-1,822);
        _SFD_CV_INIT_EML_IF(0,1,1,1098,1106,1159,1469);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,1101,1106,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_b_sf_marshallOut,(MexInFcnForType)c7_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_c_sf_marshallOut,(MexInFcnForType)c7_c_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Active_seat_04_OFFLINEMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance =
      (SFc7_Active_seat_04_OFFLINEInstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c7_ay_out);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c7_ay_in);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c7_az_in);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c7_az_out);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)&chartInstance->c7_filter_pars);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "snZGKM38c8HsylshIxQm9mB";
}

static void sf_opaque_initialize_c7_Active_seat_04_OFFLINE(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_Active_seat_04_OFFLINEInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_Active_seat_04_OFFLINE
    ((SFc7_Active_seat_04_OFFLINEInstanceStruct*) chartInstanceVar);
  initialize_c7_Active_seat_04_OFFLINE
    ((SFc7_Active_seat_04_OFFLINEInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c7_Active_seat_04_OFFLINE(void *chartInstanceVar)
{
  enable_c7_Active_seat_04_OFFLINE((SFc7_Active_seat_04_OFFLINEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c7_Active_seat_04_OFFLINE(void *chartInstanceVar)
{
  disable_c7_Active_seat_04_OFFLINE((SFc7_Active_seat_04_OFFLINEInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_Active_seat_04_OFFLINE(void *chartInstanceVar)
{
  sf_gateway_c7_Active_seat_04_OFFLINE
    ((SFc7_Active_seat_04_OFFLINEInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c7_Active_seat_04_OFFLINE
  (SimStruct* S)
{
  return get_sim_state_c7_Active_seat_04_OFFLINE
    ((SFc7_Active_seat_04_OFFLINEInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c7_Active_seat_04_OFFLINE(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c7_Active_seat_04_OFFLINE
    ((SFc7_Active_seat_04_OFFLINEInstanceStruct*)sf_get_chart_instance_ptr(S),
     st);
}

static void sf_opaque_terminate_c7_Active_seat_04_OFFLINE(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_Active_seat_04_OFFLINEInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Active_seat_04_OFFLINE_optimization_info();
    }

    finalize_c7_Active_seat_04_OFFLINE
      ((SFc7_Active_seat_04_OFFLINEInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc7_Active_seat_04_OFFLINE
    ((SFc7_Active_seat_04_OFFLINEInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_Active_seat_04_OFFLINE(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c7_Active_seat_04_OFFLINE
      ((SFc7_Active_seat_04_OFFLINEInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c7_Active_seat_04_OFFLINE(SimStruct *S)
{
  /* Actual parameters from chart:
     filter_pars
   */
  const char_T *rtParamNames[] = { "filter_pars" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0],
    sf_get_param_data_type_id(S,0));

  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Active_seat_04_OFFLINE_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 7);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(48081739U));
  ssSetChecksum1(S,(1517737538U));
  ssSetChecksum2(S,(2071056163U));
  ssSetChecksum3(S,(2722127921U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_Active_seat_04_OFFLINE(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c7_Active_seat_04_OFFLINE(SimStruct *S)
{
  SFc7_Active_seat_04_OFFLINEInstanceStruct *chartInstance;
  chartInstance = (SFc7_Active_seat_04_OFFLINEInstanceStruct *)utMalloc(sizeof
    (SFc7_Active_seat_04_OFFLINEInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc7_Active_seat_04_OFFLINEInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c7_Active_seat_04_OFFLINE;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c7_Active_seat_04_OFFLINE(chartInstance);
}

void c7_Active_seat_04_OFFLINE_method_dispatcher(SimStruct *S, int_T method,
  void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_Active_seat_04_OFFLINE(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_Active_seat_04_OFFLINE(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_Active_seat_04_OFFLINE(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_Active_seat_04_OFFLINE_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
