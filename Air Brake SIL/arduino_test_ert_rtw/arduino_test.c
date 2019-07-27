/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: arduino_test.c
 *
 * Code generated for Simulink model 'arduino_test'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Fri Jul 26 18:42:08 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "arduino_test.h"
#include "arduino_test_private.h"

/* Real-time model */
RT_MODEL_arduino_test_T arduino_test_M_;
RT_MODEL_arduino_test_T *const arduino_test_M = &arduino_test_M_;

/* Model step function */
void arduino_test_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void arduino_test_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(arduino_test_M, (NULL));
}

/* Model terminate function */
void arduino_test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
