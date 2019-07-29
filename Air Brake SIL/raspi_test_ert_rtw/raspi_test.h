/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: raspi_test.h
 *
 * Code generated for Simulink model 'raspi_test'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jul 28 23:29:40 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_raspi_test_h_
#define RTW_HEADER_raspi_test_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef raspi_test_COMMON_INCLUDES_
# define raspi_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_gpio.h"
#endif                                 /* raspi_test_COMMON_INCLUDES_ */

#include "raspi_test_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T STEP;                         /* '<Root>/STEP' */
} B_raspi_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_linux_blocks_Digi_T obj; /* '<S2>/Digital Write' */
  codertarget_linux_blocks_Digi_T obj_f;/* '<S1>/Digital Write' */
  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  int32_T clockTickCounter;            /* '<Root>/STEP' */
} DW_raspi_test_T;

/* Parameters (default storage) */
struct P_raspi_test_T_ {
  real_T DIR_Value;                    /* Expression: 1
                                        * Referenced by: '<Root>/DIR'
                                        */
  real_T STEP_Amp;                     /* Expression: 1
                                        * Referenced by: '<Root>/STEP'
                                        */
  real_T STEP_Period;                  /* Computed Parameter: STEP_Period
                                        * Referenced by: '<Root>/STEP'
                                        */
  real_T STEP_Duty;                    /* Computed Parameter: STEP_Duty
                                        * Referenced by: '<Root>/STEP'
                                        */
  real_T STEP_PhaseDelay;              /* Expression: 0
                                        * Referenced by: '<Root>/STEP'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_raspi_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_raspi_test_T raspi_test_P;

/* Block signals (default storage) */
extern B_raspi_test_T raspi_test_B;

/* Block states (default storage) */
extern DW_raspi_test_T raspi_test_DW;

/* Model entry point functions */
extern void raspi_test_initialize(void);
extern void raspi_test_step(void);
extern void raspi_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_raspi_test_T *const raspi_test_M;

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
 * '<Root>' : 'raspi_test'
 * '<S1>'   : 'raspi_test/GPIO Write'
 * '<S2>'   : 'raspi_test/GPIO Write1'
 * '<S3>'   : 'raspi_test/Rotary Position Sensor Transfer Function'
 */
#endif                                 /* RTW_HEADER_raspi_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
