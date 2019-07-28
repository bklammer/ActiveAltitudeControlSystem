/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: SIL_Arduino.h
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

#ifndef RTW_HEADER_SIL_Arduino_h_
#define RTW_HEADER_SIL_Arduino_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef SIL_Arduino_COMMON_INCLUDES_
# define SIL_Arduino_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_AnalogIn.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* SIL_Arduino_COMMON_INCLUDES_ */

#include "SIL_Arduino_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T InitialConditions[2];         /* '<S4>/Initial Conditions' */
  real_T TmpRTBAtMATLABFunctionInport3;/* '<S4>/Flap Angle to Drag Coefficient' */
  real_T ControlSignaluntisofstepperangl;/* '<S1>/Multiply' */
  real_T Howfasttostep;                /* '<S6>/Step Frequency' */
  real_T Multiply;                     /* '<S7>/Multiply' */
  real_T FlapAngle;                    /* '<S10>/Multiply1' */
  real_T zd[2];                        /* '<S4>/MATLAB Function' */
  real_T sensor_data[5];               /* '<S4>/MATLAB Function' */
  real_T Cd;                           /* '<S4>/Flap Angle to Drag Coefficient' */
  real_T Mi;
  real_T temp;
  real_T Vz;
  real_T w;
  uint16_T RotaryPositionSensor;       /* '<S3>/Analog Input' */
  boolean_T DirectionSignal;           /* '<S6>/GreaterThan1' */
  boolean_T TmpRTBAtNANDInport2;       /* '<S7>/GreaterThan' */
  boolean_T TmpRTBAtORInport2;         /* '<S7>/Less Than' */
} B_SIL_Arduino_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_g_T obj; /* '<S3>/Analog Input' */
  codertarget_arduinobase_block_T obj_j;/* '<S9>/Digital Output' */
  codertarget_arduinobase_block_T obj_k;/* '<S8>/Digital Output' */
  real_T TmpRTBAtMATLABFunctionInport3_B;/* synthesized block */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData;
  } ControlSignal_PWORK;               /* '<Root>/Control Signal' */

  struct {
    void *LoggedData[2];
  } StepperSignals_PWORK;              /* '<Root>/Stepper Signals' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK_f;                     /* '<S3>/Scope' */

  int32_T clockTickCounter;            /* '<S6>/Step Frequency' */
  int_T Integrator_IWORK;              /* '<S4>/Integrator' */
  boolean_T TmpRTBAtNANDInport2_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtORInport2_Buffer0; /* synthesized block */
} DW_SIL_Arduino_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S4>/Integrator' */
} X_SIL_Arduino_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S4>/Integrator' */
} XDot_SIL_Arduino_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[2];      /* '<S4>/Integrator' */
} XDis_SIL_Arduino_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_SIL_Arduino_T_ {
  real_T INTAB1[3498];                 /* Variable: INTAB1
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T INTAB3[2];                    /* Variable: INTAB3
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T INTAB4[666];                  /* Variable: INTAB4
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T AnalogInput_SampleTime;       /* Expression: 0.05
                                        * Referenced by: '<S3>/Analog Input'
                                        */
  real_T InitialConditions_Value[2];   /* Expression: [0 0]
                                        * Referenced by: '<S4>/Initial Conditions'
                                        */
  real_T TmpRTBAtMATLABFunctionInport3_I;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T ProportionalGain_Value;       /* Expression: 89556
                                        * Referenced by: '<S1>/Proportional Gain'
                                        */
  real_T Constant1_Value;              /* Expression: 2950
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant5_Value;              /* Expression: 13
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Ma07_Value;                   /* Expression: 240
                                        * Referenced by: '<S1>/Ma 0.7'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T StepSize_Value;               /* Expression: 1.8
                                        * Referenced by: '<S6>/Step Size'
                                        */
  real_T StepFrequency_Amp;            /* Expression: 1
                                        * Referenced by: '<S6>/Step Frequency'
                                        */
  real_T StepFrequency_Period;         /* Computed Parameter: StepFrequency_Period
                                        * Referenced by: '<S6>/Step Frequency'
                                        */
  real_T StepFrequency_Duty;           /* Computed Parameter: StepFrequency_Duty
                                        * Referenced by: '<S6>/Step Frequency'
                                        */
  real_T StepFrequency_PhaseDelay;     /* Expression: 0
                                        * Referenced by: '<S6>/Step Frequency'
                                        */
  real_T Constant5_Value_k;            /* Expression: -0.01
                                        * Referenced by: '<S4>/Constant5'
                                        */
  real_T _Value;                       /* Expression: 579
                                        * Referenced by: '<S3>/ '
                                        */
  real_T _Value_b;                     /* Expression: 356
                                        * Referenced by: '<S3>/   '
                                        */
  real_T _Value_j;                     /* Expression: 77
                                        * Referenced by: '<S3>/  '
                                        */
  real_T AngleofAirBrakeFlapswhenFullyOp;/* Expression: 77
                                          * Referenced by: '<S2>/Angle of Air Brake Flaps when Fully Open (degrees)'
                                          */
  real_T Constant_Value_l;             /* Expression: 5
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T Constant1_Value_j;            /* Expression: 5
                                        * Referenced by: '<S7>/Constant1'
                                        */
  boolean_T TmpRTBAtNANDInport2_InitialCond;/* Computed Parameter: TmpRTBAtNANDInport2_InitialCond
                                             * Referenced by: synthesized block
                                             */
  boolean_T TmpRTBAtORInport2_InitialCondit;/* Computed Parameter: TmpRTBAtORInport2_InitialCondit
                                             * Referenced by: synthesized block
                                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_SIL_Arduino_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_SIL_Arduino_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[2];
  real_T odeF[3][2];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    boolean_T firstInitCondFlag;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
    } RateInteraction;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_SIL_Arduino_T SIL_Arduino_P;

/* Block signals (default storage) */
extern B_SIL_Arduino_T SIL_Arduino_B;

/* Continuous states (default storage) */
extern X_SIL_Arduino_T SIL_Arduino_X;

/* Block states (default storage) */
extern DW_SIL_Arduino_T SIL_Arduino_DW;

/* External function called from main */
extern void SIL_Arduino_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void SIL_Arduino_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void SIL_Arduino_initialize(void);
extern void SIL_Arduino_step0(void);
extern void SIL_Arduino_step2(void);
extern void SIL_Arduino_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SIL_Arduino_T *const SIL_Arduino_M;

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
 * '<Root>' : 'SIL_Arduino'
 * '<S1>'   : 'SIL_Arduino/Controller'
 * '<S2>'   : 'SIL_Arduino/Motor Controller'
 * '<S3>'   : 'SIL_Arduino/Motor and Gearbox Transfer Function'
 * '<S4>'   : 'SIL_Arduino/Rocket Dynamics'
 * '<S5>'   : 'SIL_Arduino/Controller/MATLAB Function'
 * '<S6>'   : 'SIL_Arduino/Motor Controller/Motor Signal Converter'
 * '<S7>'   : 'SIL_Arduino/Motor Controller/Rotary Sensor Fail Safe'
 * '<S8>'   : 'SIL_Arduino/Motor and Gearbox Transfer Function/Digital Output'
 * '<S9>'   : 'SIL_Arduino/Motor and Gearbox Transfer Function/Digital Output1'
 * '<S10>'  : 'SIL_Arduino/Motor and Gearbox Transfer Function/Rotary Position Sensor Transfer Function'
 * '<S11>'  : 'SIL_Arduino/Motor and Gearbox Transfer Function/Step Counter'
 * '<S12>'  : 'SIL_Arduino/Motor and Gearbox Transfer Function/Steps to Angle'
 * '<S13>'  : 'SIL_Arduino/Rocket Dynamics/Flap Angle to Drag Coefficient'
 * '<S14>'  : 'SIL_Arduino/Rocket Dynamics/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_SIL_Arduino_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
