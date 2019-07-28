/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: SIL_Arduino_types.h
 *
 * Code generated for Simulink model 'SIL_Arduino'.
 *
 * Model version                  : 1.48
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Jul 27 23:50:12 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SIL_Arduino_types_h_
#define RTW_HEADER_SIL_Arduino_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Custom Type definition for MATLABSystem: '<S3>/Analog Input' */
#include "MW_SVD.h"
#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
} codertarget_arduinobase_block_T;

#endif                                 /*typedef_codertarget_arduinobase_block_T*/

#ifndef typedef_cell_SIL_Arduino_T
#define typedef_cell_SIL_Arduino_T

typedef struct {
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
} cell_SIL_Arduino_T;

#endif                                 /*typedef_cell_SIL_Arduino_T*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct {
  cell_SIL_Arduino_T AvailablePwmPinNames;
} codertarget_arduinobase_inter_T;

#endif                                 /*typedef_codertarget_arduinobase_inter_T*/

#ifndef typedef_codertarget_arduinobase_int_g_T
#define typedef_codertarget_arduinobase_int_g_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_arduinobase_inter_T Hw;
  MW_Handle_Type MW_ANALOGIN_HANDLE;
  real_T SampleTime;
} codertarget_arduinobase_int_g_T;

#endif                                 /*typedef_codertarget_arduinobase_int_g_T*/

/* Parameters (default storage) */
typedef struct P_SIL_Arduino_T_ P_SIL_Arduino_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_SIL_Arduino_T RT_MODEL_SIL_Arduino_T;

#endif                                 /* RTW_HEADER_SIL_Arduino_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
