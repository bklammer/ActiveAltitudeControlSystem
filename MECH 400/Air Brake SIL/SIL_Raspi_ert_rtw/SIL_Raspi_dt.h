/*
 * SIL_Raspi_dt.h
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "SIL_Raspi".
 *
 * Model version              : 1.53
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Sun Jul 28 20:26:52 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&SIL_Raspi_B.InitialConditions[0]), 0, 0, 16 },

  { (char_T *)(&SIL_Raspi_B.DirectionSignal), 8, 0, 3 }
  ,

  { (char_T *)(&SIL_Raspi_DW.UnitDelay_DSTATE), 0, 0, 2 },

  { (char_T *)(&SIL_Raspi_DW.Scope_PWORK.LoggedData[0]), 11, 0, 7 },

  { (char_T *)(&SIL_Raspi_DW.clockTickCounter), 6, 0, 1 },

  { (char_T *)(&SIL_Raspi_DW.Integrator_IWORK), 10, 0, 1 },

  { (char_T *)(&SIL_Raspi_DW.StepCounter_SubsysRanBC), 2, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&SIL_Raspi_P.INTAB1[0]), 0, 0, 4188 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] SIL_Raspi_dt.h */
