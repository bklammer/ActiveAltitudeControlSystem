/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: raspi_test_types.h
 *
 * Code generated for Simulink model 'raspi_test'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jul 29 09:08:07 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_raspi_test_types_h_
#define RTW_HEADER_raspi_test_types_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Custom Type definition for MATLABSystem: '<Root>/I2C Master Read' */
#include "MW_SVD.h"
#include <stddef.h>
#ifndef typedef_codertarget_raspi_internal_Ha_T
#define typedef_codertarget_raspi_internal_Ha_T

typedef struct {
  int32_T __dummy;
} codertarget_raspi_internal_Ha_T;

#endif                                 /*typedef_codertarget_raspi_internal_Ha_T*/

#ifndef typedef_codertarget_raspi_internal_I2_T
#define typedef_codertarget_raspi_internal_I2_T

typedef struct {
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  codertarget_raspi_internal_Ha_T Hw;
  uint32_T BusSpeed;
  MW_Handle_Type MW_I2C_HANDLE;
  real_T SampleTime;
} codertarget_raspi_internal_I2_T;

#endif                                 /*typedef_codertarget_raspi_internal_I2_T*/

/* Parameters (default storage) */
typedef struct P_raspi_test_T_ P_raspi_test_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_raspi_test_T RT_MODEL_raspi_test_T;

#endif                                 /* RTW_HEADER_raspi_test_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
