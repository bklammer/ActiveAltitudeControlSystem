/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: SIL_Raspi_control_panel.h
 *
 * Code generated for Simulink model 'SIL_Raspi_control_panel'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jul 28 23:38:10 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SIL_Raspi_control_panel_h_
#define RTW_HEADER_SIL_Raspi_control_panel_h_
#include <math.h>
#include <string.h>
#include <float.h>
#include <stddef.h>
#ifndef SIL_Raspi_control_panel_COMMON_INCLUDES_
# define SIL_Raspi_control_panel_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#include "MW_gpio.h"
#endif                                 /* SIL_Raspi_control_panel_COMMON_INCLUDES_ */

#include "SIL_Raspi_control_panel_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rt_zcfcn.h"

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
  real_T InitialConditions[2];         /* '<S5>/Initial Conditions' */
  real_T TmpRTBAtMATLABFunctionInport3;/* '<S5>/Flap Angle to Drag Coefficient' */
  real_T ControlSignaluntisofstepperangl;/* '<S2>/Multiply' */
  real_T Howfasttostep;                /* '<S7>/Step Frequency' */
  real_T Multiply;                     /* '<S8>/Multiply' */
  real_T FlapAngle;                    /* '<S11>/Multiply1' */
  real_T zd[2];                        /* '<S5>/MATLAB Function' */
  real_T sensor_data[5];               /* '<S5>/MATLAB Function' */
  real_T Cd;                           /* '<S5>/Flap Angle to Drag Coefficient' */
  real_T Ti;
  real_T temp;
  real_T Vz;
  real_T w;
  real_T v;
  int16_T RotaryPositionSensor;        /* '<S4>/I2C Master Read' */
  boolean_T DirectionSignal;           /* '<S7>/GreaterThan1' */
  boolean_T TmpRTBAtNANDInport2;       /* '<S8>/GreaterThan' */
  boolean_T TmpRTBAtORInport2;         /* '<S8>/Less Than' */
} B_SIL_Raspi_control_panel_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_raspi_internal_I2_T obj; /* '<S4>/I2C Master Read' */
  codertarget_linux_blocks_Digi_T obj_k;/* '<S10>/Digital Write' */
  codertarget_linux_blocks_Digi_T obj_f;/* '<S9>/Digital Write' */
  real_T UnitDelay_DSTATE;             /* '<S12>/Unit Delay' */
  real_T TmpRTBAtMATLABFunctionInport3_B;/* synthesized block */
  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<S2>/Scope' */

  struct {
    void *LoggedData;
  } ControlSignal_PWORK;               /* '<S1>/Control Signal' */

  struct {
    void *LoggedData[2];
  } StepperSignals_PWORK;              /* '<S1>/Stepper Signals' */

  struct {
    void *LoggedData;
  } FlapAngle_PWORK;                   /* '<S1>/Flap Angle' */

  struct {
    void *LoggedData;
  } Scope_PWORK_g;                     /* '<S4>/Scope' */

  int32_T clockTickCounter;            /* '<S7>/Step Frequency' */
  int_T Integrator_IWORK;              /* '<S5>/Integrator' */
  int8_T StepCounter_SubsysRanBC;      /* '<S4>/Step Counter' */
  boolean_T TmpRTBAtNANDInport2_Buffer0;/* synthesized block */
  boolean_T TmpRTBAtORInport2_Buffer0; /* synthesized block */
} DW_SIL_Raspi_control_panel_T;

/* Continuous states (default storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S5>/Integrator' */
} X_SIL_Raspi_control_panel_T;

/* State derivatives (default storage) */
typedef struct {
  real_T Integrator_CSTATE[2];         /* '<S5>/Integrator' */
} XDot_SIL_Raspi_control_panel_T;

/* State disabled  */
typedef struct {
  boolean_T Integrator_CSTATE[2];      /* '<S5>/Integrator' */
} XDis_SIL_Raspi_control_panel_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState StepCounter_Trig_ZCE;     /* '<S4>/Step Counter' */
} PrevZCX_SIL_Raspi_control_pan_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_SIL_Raspi_control_panel_T_ {
  real_T INTAB1[3498];                 /* Variable: INTAB1
                                        * Referenced by: '<S5>/Constant2'
                                        */
  real_T INTAB3[2];                    /* Variable: INTAB3
                                        * Referenced by: '<S5>/Constant3'
                                        */
  real_T INTAB4[666];                  /* Variable: INTAB4
                                        * Referenced by: '<S5>/Constant4'
                                        */
  real_T I2CMasterRead_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<S4>/I2C Master Read'
                                        */
  real_T StepCount_Y0;                 /* Expression: 0
                                        * Referenced by: '<S12>/Step Count'
                                        */
  real_T Constant1_Value;              /* Expression: -0.5
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S12>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S12>/Unit Delay'
                                        */
  real_T InitialConditions_Value[2];   /* Expression: [0 0]
                                        * Referenced by: '<S5>/Initial Conditions'
                                        */
  real_T TmpRTBAtMATLABFunctionInport3_I;/* Expression: 0
                                          * Referenced by: synthesized block
                                          */
  real_T Constant_Value_a;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T ProportionalGain_Value;       /* Expression: 6523
                                        * Referenced by: '<S2>/Proportional Gain'
                                        */
  real_T TargetAltitudem_Value;        /* Expression: 2950
                                        * Referenced by: '<S1>/Target Altitude (m) '
                                        */
  real_T Constant5_Value;              /* Expression: 15.72
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Ma07_Value;                   /* Expression: 240
                                        * Referenced by: '<S2>/Ma 0.7'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T StepSize_Value;               /* Expression: 0.1125
                                        * Referenced by: '<S7>/Step Size'
                                        */
  real_T StepFrequency_Amp;            /* Expression: 1
                                        * Referenced by: '<S7>/Step Frequency'
                                        */
  real_T StepFrequency_Period;         /* Computed Parameter: StepFrequency_Period
                                        * Referenced by: '<S7>/Step Frequency'
                                        */
  real_T StepFrequency_Duty;           /* Computed Parameter: StepFrequency_Duty
                                        * Referenced by: '<S7>/Step Frequency'
                                        */
  real_T StepFrequency_PhaseDelay;     /* Expression: 0
                                        * Referenced by: '<S7>/Step Frequency'
                                        */
  real_T Constant5_Value_k;            /* Expression: -0.01
                                        * Referenced by: '<S5>/Constant5'
                                        */
  real_T _Value;                       /* Expression: 2.962e4
                                        * Referenced by: '<S4>/ '
                                        */
  real_T _Value_d;                     /* Expression: 1.87e4
                                        * Referenced by: '<S4>/   '
                                        */
  real_T _Value_k;                     /* Expression: 77
                                        * Referenced by: '<S4>/  '
                                        */
  real_T AngleofAirBrakeFlapswhenFullyOp;/* Expression: 77
                                          * Referenced by: '<S3>/Angle of Air Brake Flaps when Fully Open (degrees)'
                                          */
  real_T Constant_Value_f;             /* Expression: 5
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 5
                                        * Referenced by: '<S8>/Constant1'
                                        */
  boolean_T TmpRTBAtNANDInport2_InitialCond;/* Computed Parameter: TmpRTBAtNANDInport2_InitialCond
                                             * Referenced by: synthesized block
                                             */
  boolean_T TmpRTBAtORInport2_InitialCondit;/* Computed Parameter: TmpRTBAtORInport2_InitialCondit
                                             * Referenced by: synthesized block
                                             */
};

/* Real-time Model Data Structure */
struct tag_RTM_SIL_Raspi_control_pan_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_SIL_Raspi_control_panel_T *contStates;
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
extern P_SIL_Raspi_control_panel_T SIL_Raspi_control_panel_P;

/* Block signals (default storage) */
extern B_SIL_Raspi_control_panel_T SIL_Raspi_control_panel_B;

/* Continuous states (default storage) */
extern X_SIL_Raspi_control_panel_T SIL_Raspi_control_panel_X;

/* Block states (default storage) */
extern DW_SIL_Raspi_control_panel_T SIL_Raspi_control_panel_DW;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_SIL_Raspi_control_pan_T SIL_Raspi_control_panel_PrevZCX;

/* External function called from main */
extern void SIL_Raspi_control_panel_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void SIL_Raspi_control_panel_SetEventsForThisBaseStep(boolean_T
  *eventFlags);
extern void SIL_Raspi_control_panel_initialize(void);
extern void SIL_Raspi_control_panel_step0(void);
extern void SIL_Raspi_control_panel_step(int_T tid);
extern void SIL_Raspi_control_panel_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SIL_Raspi_control_pa_T *const SIL_Raspi_control_panel_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Memory' : Unused code path elimination
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
 * '<Root>' : 'SIL_Raspi_control_panel'
 * '<S1>'   : 'SIL_Raspi_control_panel/Simulink Model'
 * '<S2>'   : 'SIL_Raspi_control_panel/Simulink Model/Controller'
 * '<S3>'   : 'SIL_Raspi_control_panel/Simulink Model/Motor Controller'
 * '<S4>'   : 'SIL_Raspi_control_panel/Simulink Model/Motor and Gearbox Transfer Function'
 * '<S5>'   : 'SIL_Raspi_control_panel/Simulink Model/Rocket Dynamics'
 * '<S6>'   : 'SIL_Raspi_control_panel/Simulink Model/Controller/MATLAB Function'
 * '<S7>'   : 'SIL_Raspi_control_panel/Simulink Model/Motor Controller/Motor Signal Converter'
 * '<S8>'   : 'SIL_Raspi_control_panel/Simulink Model/Motor Controller/Rotary Sensor Fail Safe'
 * '<S9>'   : 'SIL_Raspi_control_panel/Simulink Model/Motor and Gearbox Transfer Function/GPIO DIR'
 * '<S10>'  : 'SIL_Raspi_control_panel/Simulink Model/Motor and Gearbox Transfer Function/GPIO STEP'
 * '<S11>'  : 'SIL_Raspi_control_panel/Simulink Model/Motor and Gearbox Transfer Function/Rotary Position Sensor Transfer Function'
 * '<S12>'  : 'SIL_Raspi_control_panel/Simulink Model/Motor and Gearbox Transfer Function/Step Counter'
 * '<S13>'  : 'SIL_Raspi_control_panel/Simulink Model/Motor and Gearbox Transfer Function/Steps to Angle'
 * '<S14>'  : 'SIL_Raspi_control_panel/Simulink Model/Rocket Dynamics/Flap Angle to Drag Coefficient'
 * '<S15>'  : 'SIL_Raspi_control_panel/Simulink Model/Rocket Dynamics/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_SIL_Raspi_control_panel_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
