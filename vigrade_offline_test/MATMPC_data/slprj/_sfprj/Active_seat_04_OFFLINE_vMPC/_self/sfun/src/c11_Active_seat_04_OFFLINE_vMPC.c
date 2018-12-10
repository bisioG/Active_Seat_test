/* Include files */

#include "Active_seat_04_OFFLINE_vMPC_sfun.h"
#include "c11_Active_seat_04_OFFLINE_vMPC.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Active_seat_04_OFFLINE_vMPC_sfun_debug_macros.h"
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
static const char * c11_debug_family_names[8] = { "nargin", "nargout",
  "offset_lat_sup", "ay", "gain_lat_sup", "gain", "NLGain", "p_out_lat_sup_sx" };

/* Function Declarations */
static void initialize_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void initialize_params_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void enable_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void disable_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void set_sim_state_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_st);
static void finalize_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void sf_gateway_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void mdl_start_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void initSimStructsc11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_b_p_out_lat_sup_sx, const char_T *c11_identifier);
static real_T c11_b_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_error(SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct
                      *chartInstance);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_c_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_d_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_b_is_active_c11_Active_seat_04_OFFLINE_vMPC, const char_T
   *c11_identifier);
static uint8_T c11_e_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc11_Active_seat_04_OFFLINE_vMPC(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_is_active_c11_Active_seat_04_OFFLINE_vMPC = 0U;
}

static void initialize_params_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  const mxArray *c11_c_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(2, 1), false);
  c11_hoistedGlobal = *chartInstance->c11_p_out_lat_sup_sx;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal =
    chartInstance->c11_is_active_c11_Active_seat_04_OFFLINE_vMPC;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_st)
{
  const mxArray *c11_u;
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  *chartInstance->c11_p_out_lat_sup_sx = c11_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("p_out_lat_sup_sx", c11_u, 0)), "p_out_lat_sup_sx");
  chartInstance->c11_is_active_c11_Active_seat_04_OFFLINE_vMPC =
    c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "is_active_c11_Active_seat_04_OFFLINE_vMPC", c11_u, 1)),
    "is_active_c11_Active_seat_04_OFFLINE_vMPC");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_Active_seat_04_OFFLINE_vMPC(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  real_T c11_hoistedGlobal;
  real_T c11_b_hoistedGlobal;
  real_T c11_c_hoistedGlobal;
  real_T c11_d_hoistedGlobal;
  real_T c11_e_hoistedGlobal;
  real_T c11_b_offset_lat_sup;
  real_T c11_b_ay;
  real_T c11_b_gain_lat_sup;
  real_T c11_b_gain;
  real_T c11_b_NLGain;
  uint32_T c11_debug_family_var_map[8];
  real_T c11_nargin = 5.0;
  real_T c11_nargout = 1.0;
  real_T c11_b_p_out_lat_sup_sx;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_y;
  real_T c11_a;
  real_T c11_b;
  real_T c11_b_a;
  real_T c11_b_b;
  real_T c11_c_a;
  real_T c11_c_b;
  real_T c11_f_x;
  real_T c11_b_y;
  real_T c11_d_a;
  real_T c11_d_b;
  real_T c11_c;
  real_T c11_e_a;
  real_T c11_e_b;
  boolean_T c11_p;
  real_T c11_g_x;
  boolean_T c11_f_b;
  real_T c11_h_x;
  real_T c11_i_x;
  boolean_T c11_b0;
  boolean_T c11_b_p;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_NLGain, 4U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_gain, 3U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_gain_lat_sup, 2U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_ay, 1U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_offset_lat_sup, 0U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
  chartInstance->c11_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  c11_hoistedGlobal = *chartInstance->c11_offset_lat_sup;
  c11_b_hoistedGlobal = *chartInstance->c11_ay;
  c11_c_hoistedGlobal = *chartInstance->c11_gain_lat_sup;
  c11_d_hoistedGlobal = *chartInstance->c11_gain;
  c11_e_hoistedGlobal = *chartInstance->c11_NLGain;
  c11_b_offset_lat_sup = c11_hoistedGlobal;
  c11_b_ay = c11_b_hoistedGlobal;
  c11_b_gain_lat_sup = c11_c_hoistedGlobal;
  c11_b_gain = c11_d_hoistedGlobal;
  c11_b_NLGain = c11_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 0U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 1U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_offset_lat_sup, 2U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_ay, 3U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_gain_lat_sup, 4U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_gain, 5U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_b_NLGain, 6U, c11_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_p_out_lat_sup_sx, 7U,
    c11_sf_marshallOut, c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  c11_x = c11_b_ay;
  c11_b_x = c11_x;
  c11_b_x = muDoubleScalarSign(c11_b_x);
  c11_c_x = c11_b_ay;
  c11_d_x = c11_c_x;
  c11_e_x = c11_d_x;
  c11_y = muDoubleScalarAbs(c11_e_x);
  c11_a = c11_y;
  c11_b = c11_b_NLGain;
  c11_b_a = c11_a;
  c11_b_b = c11_b;
  c11_c_a = c11_b_a;
  c11_c_b = c11_b_b;
  c11_f_x = c11_c_a;
  c11_b_y = c11_c_b;
  c11_d_a = c11_f_x;
  c11_d_b = c11_b_y;
  c11_c = muDoubleScalarPower(c11_d_a, c11_d_b);
  c11_e_a = c11_c_a;
  c11_e_b = c11_c_b;
  c11_p = false;
  if (c11_e_a < 0.0) {
    c11_g_x = c11_e_b;
    c11_f_b = muDoubleScalarIsNaN(c11_g_x);
    if (c11_f_b) {
      c11_b0 = true;
    } else {
      c11_h_x = c11_e_b;
      c11_i_x = c11_h_x;
      c11_i_x = muDoubleScalarFloor(c11_i_x);
      if (c11_i_x == c11_e_b) {
        c11_b0 = true;
      } else {
        c11_b0 = false;
      }
    }

    c11_b_p = !c11_b0;
    c11_p = c11_b_p;
  }

  if (c11_p) {
    c11_error(chartInstance);
  }

  c11_b_p_out_lat_sup_sx = c11_b_offset_lat_sup + c11_b_gain * c11_b_x * c11_c *
    c11_b_gain_lat_sup;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -5);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c11_p_out_lat_sup_sx = c11_b_p_out_lat_sup_sx;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c11_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Active_seat_04_OFFLINE_vMPCMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_p_out_lat_sup_sx, 5U, 1U, 0U,
                        chartInstance->c11_sfEvent, false);
}

static void mdl_start_c11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc11_Active_seat_04_OFFLINE_vMPC
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)(c11_machineNumber);
  (void)(c11_chartNumber);
  (void)(c11_instanceNumber);
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_b_p_out_lat_sup_sx, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = (const char *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_p_out_lat_sup_sx), &c11_thisId);
  sf_mex_destroy(&c11_b_p_out_lat_sup_sx);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d0, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_p_out_lat_sup_sx;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)
    chartInstanceVoid;
  c11_b_p_out_lat_sup_sx = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = (const char *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_p_out_lat_sup_sx), &c11_thisId);
  sf_mex_destroy(&c11_b_p_out_lat_sup_sx);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray
  *sf_c11_Active_seat_04_OFFLINE_vMPC_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c11_nameCaptureInfo;
}

static void c11_error(SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct
                      *chartInstance)
{
  const mxArray *c11_y = NULL;
  static char_T c11_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  (void)chartInstance;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_cv0, 10, 0U, 1U, 0U, 2, 1, 31),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c11_y));
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)
    chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_c_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i0, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)
    chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = (const char *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_d_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_b_is_active_c11_Active_seat_04_OFFLINE_vMPC, const char_T
   *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = (const char *)c11_identifier;
  c11_thisId.fParent = NULL;
  c11_thisId.bParentIsCell = false;
  c11_y = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_Active_seat_04_OFFLINE_vMPC), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_Active_seat_04_OFFLINE_vMPC);
  return c11_y;
}

static uint8_T c11_e_emlrt_marshallIn
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance, const mxArray
   *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance)
{
  chartInstance->c11_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c11_offset_lat_sup = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c11_ay = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_p_out_lat_sup_sx = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_gain_lat_sup = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c11_gain = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c11_NLGain = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
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

void sf_c11_Active_seat_04_OFFLINE_vMPC_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3237879533U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1466809101U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1834872468U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(720037816U);
}

mxArray* sf_c11_Active_seat_04_OFFLINE_vMPC_get_post_codegen_info(void);
mxArray *sf_c11_Active_seat_04_OFFLINE_vMPC_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TWn6n6Zcnihb4f77H2fSKH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c11_Active_seat_04_OFFLINE_vMPC_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_Active_seat_04_OFFLINE_vMPC_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_Active_seat_04_OFFLINE_vMPC_jit_fallback_info(void)
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

mxArray *sf_c11_Active_seat_04_OFFLINE_vMPC_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c11_Active_seat_04_OFFLINE_vMPC_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c11_Active_seat_04_OFFLINE_vMPC(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"p_out_lat_sup_sx\",},{M[8],M[0],T\"is_active_c11_Active_seat_04_OFFLINE_vMPC\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Active_seat_04_OFFLINE_vMPC_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance =
      (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Active_seat_04_OFFLINE_vMPCMachineNumber_,
           11,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_Active_seat_04_OFFLINE_vMPCMachineNumber_,chartInstance->chartNumber,
           chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _Active_seat_04_OFFLINE_vMPCMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Active_seat_04_OFFLINE_vMPCMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"offset_lat_sup");
          _SFD_SET_DATA_PROPS(1,1,1,0,"ay");
          _SFD_SET_DATA_PROPS(2,1,1,0,"gain_lat_sup");
          _SFD_SET_DATA_PROPS(3,1,1,0,"gain");
          _SFD_SET_DATA_PROPS(4,1,1,0,"NLGain");
          _SFD_SET_DATA_PROPS(5,2,0,1,"p_out_lat_sup_sx");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,178);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Active_seat_04_OFFLINE_vMPCMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance =
      (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c11_offset_lat_sup);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c11_ay);
        _SFD_SET_DATA_VALUE_PTR(5U, (void *)chartInstance->c11_p_out_lat_sup_sx);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c11_gain_lat_sup);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c11_gain);
        _SFD_SET_DATA_VALUE_PTR(4U, (void *)chartInstance->c11_NLGain);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sZyHZ4zsG1SqGM7fVwfM2f";
}

static void sf_opaque_initialize_c11_Active_seat_04_OFFLINE_vMPC(void
  *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*) chartInstanceVar);
  initialize_c11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c11_Active_seat_04_OFFLINE_vMPC(void
  *chartInstanceVar)
{
  enable_c11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_Active_seat_04_OFFLINE_vMPC(void
  *chartInstanceVar)
{
  disable_c11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c11_Active_seat_04_OFFLINE_vMPC(void
  *chartInstanceVar)
{
  sf_gateway_c11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c11_Active_seat_04_OFFLINE_vMPC
  (SimStruct* S)
{
  return get_sim_state_c11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)
     sf_get_chart_instance_ptr(S));    /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c11_Active_seat_04_OFFLINE_vMPC(SimStruct* S,
  const mxArray *st)
{
  set_sim_state_c11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*)sf_get_chart_instance_ptr
     (S), st);
}

static void sf_opaque_terminate_c11_Active_seat_04_OFFLINE_vMPC(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*)
                    chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Active_seat_04_OFFLINE_vMPC_optimization_info();
    }

    finalize_c11_Active_seat_04_OFFLINE_vMPC
      ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc11_Active_seat_04_OFFLINE_vMPC
    ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Active_seat_04_OFFLINE_vMPC(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c11_Active_seat_04_OFFLINE_vMPC
      ((SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct*)
       sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c11_Active_seat_04_OFFLINE_vMPC(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Active_seat_04_OFFLINE_vMPC_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 11);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(660841792U));
  ssSetChecksum1(S,(1212212499U));
  ssSetChecksum2(S,(105916985U));
  ssSetChecksum3(S,(4093060941U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Active_seat_04_OFFLINE_vMPC(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_Active_seat_04_OFFLINE_vMPC(SimStruct *S)
{
  SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *chartInstance;
  chartInstance = (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct *)utMalloc
    (sizeof(SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof
         (SFc11_Active_seat_04_OFFLINE_vMPCInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Active_seat_04_OFFLINE_vMPC;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Active_seat_04_OFFLINE_vMPC;
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
  mdl_start_c11_Active_seat_04_OFFLINE_vMPC(chartInstance);
}

void c11_Active_seat_04_OFFLINE_vMPC_method_dispatcher(SimStruct *S, int_T
  method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Active_seat_04_OFFLINE_vMPC(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Active_seat_04_OFFLINE_vMPC(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Active_seat_04_OFFLINE_vMPC(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Active_seat_04_OFFLINE_vMPC_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
