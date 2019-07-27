/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: arduino_test.h
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

#ifndef RTW_HEADER_arduino_test_h_
#define RTW_HEADER_arduino_test_h_
#include <stddef.h>
#ifndef arduino_test_COMMON_INCLUDES_
# define arduino_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* arduino_test_COMMON_INCLUDES_ */

#include "arduino_test_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Real-time Model Data Structure */
struct tag_RTM_arduino_test_T {
  const char_T *errorStatus;
};

/* Model entry point functions */
extern void arduino_test_initialize(void);
extern void arduino_test_step(void);
extern void arduino_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_arduino_test_T *const arduino_test_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Abs' : Unused code path elimination
 * Block '<Root>/Constant' : Unused code path elimination
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/GreaterThan' : Unused code path elimination
 * Block '<Root>/Multiply' : Unused code path elimination
 * Block '<Root>/Pulse Generator' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'arduino_test'
 * '<S1>'   : 'arduino_test/Digital Output'
 */
#endif                                 /* RTW_HEADER_arduino_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
