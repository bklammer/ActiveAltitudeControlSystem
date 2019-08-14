/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: SIL_Arduino.c
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

#include "SIL_Arduino.h"
#include "SIL_Arduino_private.h"
#include "SIL_Arduino_dt.h"

/* Block signals (default storage) */
B_SIL_Arduino_T SIL_Arduino_B;

/* Continuous states */
X_SIL_Arduino_T SIL_Arduino_X;

/* Block states (default storage) */
DW_SIL_Arduino_T SIL_Arduino_DW;

/* Real-time model */
RT_MODEL_SIL_Arduino_T SIL_Arduino_M_;
RT_MODEL_SIL_Arduino_T *const SIL_Arduino_M = &SIL_Arduino_M_;

/* Forward declaration for local functions */
static void matlabCodegenHandle_matlabCod_g(codertarget_arduinobase_block_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_g_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void SIL_Arduino_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(SIL_Arduino_M, 2));
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (SIL_Arduino_M->Timing.TaskCounters.TID[1] == 0) {
    SIL_Arduino_M->Timing.RateInteraction.TID1_2 =
      (SIL_Arduino_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (SIL_Arduino_M->Timing.TaskCounters.TID[2])++;
  if ((SIL_Arduino_M->Timing.TaskCounters.TID[2]) > 9) {/* Sample time: [0.05s, 0.0s] */
    SIL_Arduino_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  SIL_Arduino_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SIL_Arduino_step0();
  SIL_Arduino_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SIL_Arduino_step0();
  SIL_Arduino_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

static void matlabCodegenHandle_matlabCod_g(codertarget_arduinobase_block_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(codertarget_arduinobase_int_g_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

/* Model step function for TID0 */
void SIL_Arduino_step0(void)           /* Sample time: [0.0s, 0.0s] */
{
  int16_T ii;
  int16_T b_ii;
  real_T v;
  real_T e;
  real_T f;
  real_T rtb_CurrentTime;
  uint8_T tmp;
  real_T x_tmp;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&SIL_Arduino_M->solverInfo,
                          ((SIL_Arduino_M->Timing.clockTick0+1)*
      SIL_Arduino_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SIL_Arduino_M)) {
    SIL_Arduino_M->Timing.t[0] = rtsiGetT(&SIL_Arduino_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
    /* Constant: '<S4>/Initial Conditions' */
    SIL_Arduino_B.InitialConditions[0] = SIL_Arduino_P.InitialConditions_Value[0];
    SIL_Arduino_B.InitialConditions[1] = SIL_Arduino_P.InitialConditions_Value[1];
  }

  /* Integrator: '<S4>/Integrator' */
  if (SIL_Arduino_DW.Integrator_IWORK != 0) {
    SIL_Arduino_X.Integrator_CSTATE[0] = SIL_Arduino_B.InitialConditions[0];
    SIL_Arduino_X.Integrator_CSTATE[1] = SIL_Arduino_B.InitialConditions[1];
  }

  /* Clock: '<S4>/Clock' */
  rtb_CurrentTime = SIL_Arduino_M->Timing.t[0];

  /* RateTransition: '<S4>/TmpRTBAtMATLAB FunctionInport3' */
  if (rtmIsMajorTimeStep(SIL_Arduino_M) &&
      SIL_Arduino_M->Timing.RateInteraction.TID1_2) {
    SIL_Arduino_B.TmpRTBAtMATLABFunctionInport3 =
      SIL_Arduino_DW.TmpRTBAtMATLABFunctionInport3_B;
  }

  /* End of RateTransition: '<S4>/TmpRTBAtMATLAB FunctionInport3' */

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant4'
   *  Integrator: '<S4>/Integrator'
   */
  if (rtb_CurrentTime <= SIL_Arduino_P.INTAB1[0]) {
    rtb_CurrentTime = SIL_Arduino_P.INTAB1[318];
    SIL_Arduino_B.Mi = SIL_Arduino_P.INTAB1[636];
  } else if (rtb_CurrentTime < SIL_Arduino_P.INTAB1[317]) {
    ii = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 317)) {
      ii = b_ii;
      if (rtb_CurrentTime <= SIL_Arduino_P.INTAB1[b_ii + 1]) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    }

    SIL_Arduino_B.Mi = (rtb_CurrentTime - SIL_Arduino_P.INTAB1[ii]) /
      (SIL_Arduino_P.INTAB1[ii + 1] - SIL_Arduino_P.INTAB1[ii]);
    rtb_CurrentTime = SIL_Arduino_B.Mi * (SIL_Arduino_P.INTAB1[ii + 319] -
      SIL_Arduino_P.INTAB1[318 + ii]);
    SIL_Arduino_B.Mi *= SIL_Arduino_P.INTAB1[ii + 637] - SIL_Arduino_P.INTAB1
      [636 + ii];
  } else {
    rtb_CurrentTime = SIL_Arduino_P.INTAB1[635];
    SIL_Arduino_B.Mi = SIL_Arduino_P.INTAB1[953];
  }

  if ((SIL_Arduino_X.Integrator_CSTATE[0] < SIL_Arduino_P.INTAB4[110]) &&
      (SIL_Arduino_X.Integrator_CSTATE[0] >= SIL_Arduino_P.INTAB4[0])) {
    ii = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 110)) {
      ii = b_ii;
      if (SIL_Arduino_X.Integrator_CSTATE[0] <= SIL_Arduino_P.INTAB1[b_ii + 1])
      {
        exitg1 = true;
      } else {
        b_ii++;
      }
    }

    SIL_Arduino_B.temp = (SIL_Arduino_X.Integrator_CSTATE[0] -
                          SIL_Arduino_P.INTAB4[ii]) / (SIL_Arduino_P.INTAB4[ii +
      1] - SIL_Arduino_P.INTAB4[ii]) * (SIL_Arduino_P.INTAB4[ii + 445] -
      SIL_Arduino_P.INTAB4[444 + ii]);
  } else {
    SIL_Arduino_B.temp = (0.00299 * SIL_Arduino_X.Integrator_CSTATE[0] + -131.21)
      + 273.15;
    SIL_Arduino_B.temp *= rt_powd_snf(SIL_Arduino_B.temp / 216.6, -11.388) *
      0.002488 / 287.0;
  }

  SIL_Arduino_B.Vz = SIL_Arduino_X.Integrator_CSTATE[1] / SIL_Arduino_B.Mi;
  SIL_Arduino_B.Mi *= 3.987300564E+14 / ((6.3781E+6 +
    SIL_Arduino_X.Integrator_CSTATE[0]) * (6.3781E+6 +
    SIL_Arduino_X.Integrator_CSTATE[0]));
  SIL_Arduino_B.zd[0] = SIL_Arduino_B.Vz;
  if (rtb_CurrentTime <= SIL_Arduino_B.Mi) {
    if (SIL_Arduino_X.Integrator_CSTATE[0] < 0.1) {
      SIL_Arduino_B.zd[1] = 0.0;
    } else {
      SIL_Arduino_B.zd[1] = (rtb_CurrentTime -
        SIL_Arduino_B.TmpRTBAtMATLABFunctionInport3 * 0.5 * SIL_Arduino_B.temp *
        (SIL_Arduino_B.Vz * SIL_Arduino_B.Vz) * 0.010751315458748) -
        SIL_Arduino_B.Mi;
    }
  } else {
    SIL_Arduino_B.zd[1] = (rtb_CurrentTime -
      SIL_Arduino_B.TmpRTBAtMATLABFunctionInport3 * 0.5 * SIL_Arduino_B.temp *
      (SIL_Arduino_B.Vz * SIL_Arduino_B.Vz) * 0.010751315458748) -
      SIL_Arduino_B.Mi;
  }

  SIL_Arduino_B.sensor_data[0] = SIL_Arduino_B.TmpRTBAtMATLABFunctionInport3 *
    0.010751315458748;
  SIL_Arduino_B.sensor_data[1] = SIL_Arduino_B.Vz;
  SIL_Arduino_B.sensor_data[2] = SIL_Arduino_X.Integrator_CSTATE[0];
  SIL_Arduino_B.sensor_data[3] = SIL_Arduino_B.temp;
  SIL_Arduino_B.sensor_data[4] = rtb_CurrentTime;

  /* End of MATLAB Function: '<S4>/MATLAB Function' */
  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S1>/Constant5'
   */
  rtb_CurrentTime = SIL_Arduino_B.sensor_data[0];
  SIL_Arduino_B.Mi = SIL_Arduino_P.Constant5_Value / SIL_Arduino_B.sensor_data[3];
  SIL_Arduino_B.temp = 19.62 / (SIL_Arduino_B.sensor_data[1] *
    SIL_Arduino_B.sensor_data[1]);
  SIL_Arduino_B.Vz = SIL_Arduino_P.Constant1_Value - SIL_Arduino_B.sensor_data[2];
  x_tmp = -SIL_Arduino_B.temp * SIL_Arduino_B.Vz;
  x_tmp *= exp(x_tmp);
  SIL_Arduino_B.w = -2.0;
  v = (rtMinusInf);
  ii = 0;
  while ((fabs(SIL_Arduino_B.w - v) / fabs(SIL_Arduino_B.w) > 1.0E-6) && (ii <
          1000)) {
    v = SIL_Arduino_B.w;
    e = exp(SIL_Arduino_B.w);
    f = SIL_Arduino_B.w * e - x_tmp;
    SIL_Arduino_B.w -= f / ((SIL_Arduino_B.w + 1.0) * e - (SIL_Arduino_B.w + 2.0)
      * f / (2.0 * SIL_Arduino_B.w + 2.0));
    ii++;
  }

  SIL_Arduino_B.Mi = (-SIL_Arduino_B.Mi * SIL_Arduino_B.w - SIL_Arduino_B.Mi *
                      SIL_Arduino_B.temp * SIL_Arduino_B.Vz) / SIL_Arduino_B.Vz;
  if (!rtIsNaN(SIL_Arduino_B.Mi)) {
    rtb_CurrentTime = SIL_Arduino_B.Mi;
  }

  if (SIL_Arduino_B.sensor_data[2] > SIL_Arduino_P.Constant1_Value) {
    rtb_CurrentTime = 1.0;
  }

  /* End of MATLAB Function: '<S1>/MATLAB Function' */

  /* Product: '<S1>/Multiply' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Ma 0.7'
   *  Constant: '<S1>/Proportional Gain'
   *  RelationalOperator: '<S1>/If going  slow enough'
   *  RelationalOperator: '<S1>/If no thrust'
   *  Sum: '<S1>/Sum'
   */
  SIL_Arduino_B.ControlSignaluntisofstepperangl = (rtb_CurrentTime -
    SIL_Arduino_B.sensor_data[0]) * SIL_Arduino_P.ProportionalGain_Value *
    (real_T)(SIL_Arduino_B.sensor_data[4] < SIL_Arduino_P.Constant_Value) *
    (real_T)(SIL_Arduino_B.sensor_data[1] < SIL_Arduino_P.Ma07_Value);

  /* RateTransition: '<S7>/TmpRTBAtNANDInport2' incorporates:
   *  RateTransition: '<S7>/TmpRTBAtORInport2'
   */
  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
    if (SIL_Arduino_M->Timing.RateInteraction.TID1_2) {
      SIL_Arduino_B.TmpRTBAtNANDInport2 =
        SIL_Arduino_DW.TmpRTBAtNANDInport2_Buffer0;
      SIL_Arduino_B.TmpRTBAtORInport2 = SIL_Arduino_DW.TmpRTBAtORInport2_Buffer0;
    }
  }

  /* End of RateTransition: '<S7>/TmpRTBAtNANDInport2' */

  /* Product: '<S6>/Multiply1' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  rtb_CurrentTime = SIL_Arduino_B.ControlSignaluntisofstepperangl *
    SIL_Arduino_P.Constant1_Value_o;

  /* RelationalOperator: '<S6>/GreaterThan1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  SIL_Arduino_B.DirectionSignal = (rtb_CurrentTime >
    SIL_Arduino_P.Constant_Value_k);

  /* Abs: '<S6>/Abs' */
  rtb_CurrentTime = fabs(rtb_CurrentTime);
  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
    /* DiscretePulseGenerator: '<S6>/Step Frequency' */
    SIL_Arduino_B.Howfasttostep = (SIL_Arduino_DW.clockTickCounter <
      SIL_Arduino_P.StepFrequency_Duty) && (SIL_Arduino_DW.clockTickCounter >=
      0L) ? SIL_Arduino_P.StepFrequency_Amp : 0.0;
    if (SIL_Arduino_DW.clockTickCounter >= SIL_Arduino_P.StepFrequency_Period -
        1.0) {
      SIL_Arduino_DW.clockTickCounter = 0L;
    } else {
      SIL_Arduino_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S6>/Step Frequency' */
  }

  /* Product: '<S7>/Multiply' incorporates:
   *  Constant: '<S6>/Step Size'
   *  Logic: '<S7>/AND2'
   *  Logic: '<S7>/NAND'
   *  Logic: '<S7>/OR'
   *  Product: '<S6>/Multiply'
   *  RelationalOperator: '<S6>/GreaterThan'
   */
  SIL_Arduino_B.Multiply = (real_T)(((!SIL_Arduino_B.DirectionSignal) ||
    (!SIL_Arduino_B.TmpRTBAtNANDInport2)) && (SIL_Arduino_B.DirectionSignal ||
    SIL_Arduino_B.TmpRTBAtORInport2)) * ((real_T)(rtb_CurrentTime >
    SIL_Arduino_P.StepSize_Value) * SIL_Arduino_B.Howfasttostep);
  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
  }

  /* DataTypeConversion: '<S8>/Data Type Conversion' */
  if (SIL_Arduino_B.Multiply < 256.0) {
    if (SIL_Arduino_B.Multiply >= 0.0) {
      tmp = (uint8_T)SIL_Arduino_B.Multiply;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S8>/Data Type Conversion' */

  /* MATLABSystem: '<S8>/Digital Output' */
  writeDigitalPin(2, tmp);

  /* MATLABSystem: '<S9>/Digital Output' incorporates:
   *  DataTypeConversion: '<S9>/Data Type Conversion'
   */
  writeDigitalPin(4, (uint8_T)SIL_Arduino_B.DirectionSignal);

  /* Stop: '<S4>/Stop Simulation' incorporates:
   *  Constant: '<S4>/Constant5'
   *  RelationalOperator: '<S4>/Relational Operator'
   */
  if (rtmIsMajorTimeStep(SIL_Arduino_M) && (SIL_Arduino_B.zd[0] <=
       SIL_Arduino_P.Constant5_Value_k)) {
    rtmSetStopRequested(SIL_Arduino_M, 1);
  }

  /* End of Stop: '<S4>/Stop Simulation' */
  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
    /* Update for Integrator: '<S4>/Integrator' */
    SIL_Arduino_DW.Integrator_IWORK = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(3);
    rtExtModeUpload(1, (real_T)SIL_Arduino_M->Timing.t[0]);
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SIL_Arduino_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(SIL_Arduino_M)!=-1) &&
          !((rtmGetTFinal(SIL_Arduino_M)-((SIL_Arduino_M->Timing.clockTick1) *
             0.005)) > ((SIL_Arduino_M->Timing.clockTick1) * 0.005) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(SIL_Arduino_M, "Simulation finished");
      }

      if (rtmGetStopRequested(SIL_Arduino_M)) {
        rtmSetErrorStatus(SIL_Arduino_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&SIL_Arduino_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++SIL_Arduino_M->Timing.clockTick0;
    SIL_Arduino_M->Timing.t[0] = rtsiGetSolverStopTime
      (&SIL_Arduino_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.005, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    SIL_Arduino_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SIL_Arduino_derivatives(void)
{
  XDot_SIL_Arduino_T *_rtXdot;
  _rtXdot = ((XDot_SIL_Arduino_T *) SIL_Arduino_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = SIL_Arduino_B.zd[0];
  _rtXdot->Integrator_CSTATE[1] = SIL_Arduino_B.zd[1];
}

/* Model step function for TID2 */
void SIL_Arduino_step2(void)           /* Sample time: [0.05s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_GreaterThan;
  boolean_T rtb_LessThan;

  /* MATLABSystem: '<S3>/Analog Input' */
  if (SIL_Arduino_DW.obj.SampleTime != SIL_Arduino_P.AnalogInput_SampleTime) {
    SIL_Arduino_DW.obj.SampleTime = SIL_Arduino_P.AnalogInput_SampleTime;
  }

  MW_AnalogIn_Start(SIL_Arduino_DW.obj.MW_ANALOGIN_HANDLE);
  MW_AnalogInSingle_ReadResult(SIL_Arduino_DW.obj.MW_ANALOGIN_HANDLE,
    &SIL_Arduino_B.RotaryPositionSensor, 3);

  /* End of MATLABSystem: '<S3>/Analog Input' */

  /* Product: '<S10>/Multiply1' incorporates:
   *  Constant: '<S3>/ '
   *  Constant: '<S3>/  '
   *  Constant: '<S3>/   '
   *  Product: '<S10>/Divide'
   *  Sum: '<S10>/Subtract'
   *  Sum: '<S10>/Subtract1'
   */
  SIL_Arduino_B.FlapAngle = ((real_T)SIL_Arduino_B.RotaryPositionSensor -
    SIL_Arduino_P._Value) / (SIL_Arduino_P._Value_b - SIL_Arduino_P._Value) *
    SIL_Arduino_P._Value_j;

  /* RelationalOperator: '<S7>/GreaterThan' incorporates:
   *  Constant: '<S2>/Angle of Air Brake Flaps when Fully Open (degrees)'
   *  Constant: '<S7>/Constant'
   *  Sum: '<S7>/Subtract'
   */
  rtb_GreaterThan = (SIL_Arduino_B.FlapAngle >
                     SIL_Arduino_P.AngleofAirBrakeFlapswhenFullyOp -
                     SIL_Arduino_P.Constant_Value_l);

  /* RelationalOperator: '<S7>/Less Than' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  rtb_LessThan = (SIL_Arduino_B.FlapAngle > SIL_Arduino_P.Constant1_Value_j);

  /* MATLAB Function: '<S4>/Flap Angle to Drag Coefficient' */
  SIL_Arduino_B.Cd = ((SIL_Arduino_B.FlapAngle * SIL_Arduino_B.FlapAngle *
                       -3.953E-7 + 8.737E-5 * SIL_Arduino_B.FlapAngle) +
                      4.547E-5) * 1.1 / 0.010751315458748 + 0.4;

  /* Update for RateTransition: '<S4>/TmpRTBAtMATLAB FunctionInport3' */
  SIL_Arduino_DW.TmpRTBAtMATLABFunctionInport3_B = SIL_Arduino_B.Cd;

  /* Update for RateTransition: '<S7>/TmpRTBAtNANDInport2' */
  SIL_Arduino_DW.TmpRTBAtNANDInport2_Buffer0 = rtb_GreaterThan;

  /* Update for RateTransition: '<S7>/TmpRTBAtORInport2' */
  SIL_Arduino_DW.TmpRTBAtORInport2_Buffer0 = rtb_LessThan;
  rtExtModeUpload(2, (real_T)((SIL_Arduino_M->Timing.clockTick2) * 0.05));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.05, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  SIL_Arduino_M->Timing.clockTick2++;
}

/* Model initialize function */
void SIL_Arduino_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SIL_Arduino_M, 0,
                sizeof(RT_MODEL_SIL_Arduino_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SIL_Arduino_M->solverInfo,
                          &SIL_Arduino_M->Timing.simTimeStep);
    rtsiSetTPtr(&SIL_Arduino_M->solverInfo, &rtmGetTPtr(SIL_Arduino_M));
    rtsiSetStepSizePtr(&SIL_Arduino_M->solverInfo,
                       &SIL_Arduino_M->Timing.stepSize0);
    rtsiSetdXPtr(&SIL_Arduino_M->solverInfo, &SIL_Arduino_M->derivs);
    rtsiSetContStatesPtr(&SIL_Arduino_M->solverInfo, (real_T **)
                         &SIL_Arduino_M->contStates);
    rtsiSetNumContStatesPtr(&SIL_Arduino_M->solverInfo,
      &SIL_Arduino_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SIL_Arduino_M->solverInfo,
      &SIL_Arduino_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&SIL_Arduino_M->solverInfo,
      &SIL_Arduino_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&SIL_Arduino_M->solverInfo,
      &SIL_Arduino_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SIL_Arduino_M->solverInfo, (&rtmGetErrorStatus
      (SIL_Arduino_M)));
    rtsiSetRTModelPtr(&SIL_Arduino_M->solverInfo, SIL_Arduino_M);
  }

  rtsiSetSimTimeStep(&SIL_Arduino_M->solverInfo, MAJOR_TIME_STEP);
  SIL_Arduino_M->intgData.y = SIL_Arduino_M->odeY;
  SIL_Arduino_M->intgData.f[0] = SIL_Arduino_M->odeF[0];
  SIL_Arduino_M->intgData.f[1] = SIL_Arduino_M->odeF[1];
  SIL_Arduino_M->intgData.f[2] = SIL_Arduino_M->odeF[2];
  SIL_Arduino_M->contStates = ((X_SIL_Arduino_T *) &SIL_Arduino_X);
  rtsiSetSolverData(&SIL_Arduino_M->solverInfo, (void *)&SIL_Arduino_M->intgData);
  rtsiSetSolverName(&SIL_Arduino_M->solverInfo,"ode3");
  rtmSetTPtr(SIL_Arduino_M, &SIL_Arduino_M->Timing.tArray[0]);
  rtmSetTFinal(SIL_Arduino_M, 30.0);
  SIL_Arduino_M->Timing.stepSize0 = 0.005;
  rtmSetFirstInitCond(SIL_Arduino_M, 1);

  /* External mode info */
  SIL_Arduino_M->Sizes.checksums[0] = (1773523283U);
  SIL_Arduino_M->Sizes.checksums[1] = (1771735041U);
  SIL_Arduino_M->Sizes.checksums[2] = (2860520602U);
  SIL_Arduino_M->Sizes.checksums[3] = (526453331U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    SIL_Arduino_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SIL_Arduino_M->extModeInfo,
      &SIL_Arduino_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SIL_Arduino_M->extModeInfo,
                        SIL_Arduino_M->Sizes.checksums);
    rteiSetTPtr(SIL_Arduino_M->extModeInfo, rtmGetTPtr(SIL_Arduino_M));
  }

  /* block I/O */
  (void) memset(((void *) &SIL_Arduino_B), 0,
                sizeof(B_SIL_Arduino_T));

  /* states (continuous) */
  {
    (void) memset((void *)&SIL_Arduino_X, 0,
                  sizeof(X_SIL_Arduino_T));
  }

  /* states (dwork) */
  (void) memset((void *)&SIL_Arduino_DW, 0,
                sizeof(DW_SIL_Arduino_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SIL_Arduino_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_arduinobase_int_g_T *obj;
    MW_AnalogIn_TriggerSource_Type trigger_val;

    /* Start for Constant: '<S4>/Initial Conditions' */
    SIL_Arduino_B.InitialConditions[0] = SIL_Arduino_P.InitialConditions_Value[0];
    SIL_Arduino_B.InitialConditions[1] = SIL_Arduino_P.InitialConditions_Value[1];

    /* Start for RateTransition: '<S4>/TmpRTBAtMATLAB FunctionInport3' */
    SIL_Arduino_B.TmpRTBAtMATLABFunctionInport3 =
      SIL_Arduino_P.TmpRTBAtMATLABFunctionInport3_I;

    /* Start for RateTransition: '<S7>/TmpRTBAtNANDInport2' */
    SIL_Arduino_B.TmpRTBAtNANDInport2 =
      SIL_Arduino_P.TmpRTBAtNANDInport2_InitialCond;

    /* Start for RateTransition: '<S7>/TmpRTBAtORInport2' */
    SIL_Arduino_B.TmpRTBAtORInport2 =
      SIL_Arduino_P.TmpRTBAtORInport2_InitialCondit;

    /* Start for DiscretePulseGenerator: '<S6>/Step Frequency' */
    SIL_Arduino_DW.clockTickCounter = 0L;

    /* Start for MATLABSystem: '<S8>/Digital Output' */
    SIL_Arduino_DW.obj_k.matlabCodegenIsDeleted = true;
    SIL_Arduino_DW.obj_k.isInitialized = 0L;
    SIL_Arduino_DW.obj_k.matlabCodegenIsDeleted = false;
    SIL_Arduino_DW.obj_k.isSetupComplete = false;
    SIL_Arduino_DW.obj_k.isInitialized = 1L;
    digitalIOSetup(2, true);
    SIL_Arduino_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Digital Output' */
    SIL_Arduino_DW.obj_j.matlabCodegenIsDeleted = true;
    SIL_Arduino_DW.obj_j.isInitialized = 0L;
    SIL_Arduino_DW.obj_j.matlabCodegenIsDeleted = false;
    SIL_Arduino_DW.obj_j.isSetupComplete = false;
    SIL_Arduino_DW.obj_j.isInitialized = 1L;
    digitalIOSetup(4, true);
    SIL_Arduino_DW.obj_j.isSetupComplete = true;

    /* Start for MATLABSystem: '<S3>/Analog Input' */
    SIL_Arduino_DW.obj.matlabCodegenIsDeleted = true;
    obj = &SIL_Arduino_DW.obj;
    SIL_Arduino_DW.obj.isInitialized = 0L;
    obj->Hw.AvailablePwmPinNames.f1 = '2';
    obj->Hw.AvailablePwmPinNames.f2 = '3';
    obj->Hw.AvailablePwmPinNames.f3 = '4';
    obj->Hw.AvailablePwmPinNames.f4 = '5';
    obj->Hw.AvailablePwmPinNames.f5 = '6';
    obj->Hw.AvailablePwmPinNames.f6 = '7';
    obj->Hw.AvailablePwmPinNames.f7 = '8';
    obj->Hw.AvailablePwmPinNames.f8 = '9';
    obj->Hw.AvailablePwmPinNames.f9[0] = '1';
    obj->Hw.AvailablePwmPinNames.f9[1] = '0';
    obj->Hw.AvailablePwmPinNames.f10[0] = '1';
    obj->Hw.AvailablePwmPinNames.f10[1] = '1';
    obj->Hw.AvailablePwmPinNames.f11[0] = '1';
    obj->Hw.AvailablePwmPinNames.f11[1] = '2';
    obj->Hw.AvailablePwmPinNames.f12[0] = '1';
    obj->Hw.AvailablePwmPinNames.f12[1] = '3';
    SIL_Arduino_DW.obj.matlabCodegenIsDeleted = false;
    SIL_Arduino_DW.obj.SampleTime = SIL_Arduino_P.AnalogInput_SampleTime;
    obj = &SIL_Arduino_DW.obj;
    SIL_Arduino_DW.obj.isSetupComplete = false;
    SIL_Arduino_DW.obj.isInitialized = 1L;
    obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(4UL);
    trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
    MW_AnalogIn_SetTriggerSource(SIL_Arduino_DW.obj.MW_ANALOGIN_HANDLE,
      trigger_val, 0UL);
    SIL_Arduino_DW.obj.isSetupComplete = true;

    /* InitializeConditions for Integrator: '<S4>/Integrator' */
    if (rtmIsFirstInitCond(SIL_Arduino_M)) {
      SIL_Arduino_X.Integrator_CSTATE[0] = 0.0;
      SIL_Arduino_X.Integrator_CSTATE[1] = 0.0;
    }

    SIL_Arduino_DW.Integrator_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S4>/Integrator' */

    /* InitializeConditions for RateTransition: '<S4>/TmpRTBAtMATLAB FunctionInport3' */
    SIL_Arduino_DW.TmpRTBAtMATLABFunctionInport3_B =
      SIL_Arduino_P.TmpRTBAtMATLABFunctionInport3_I;

    /* InitializeConditions for RateTransition: '<S7>/TmpRTBAtNANDInport2' */
    SIL_Arduino_DW.TmpRTBAtNANDInport2_Buffer0 =
      SIL_Arduino_P.TmpRTBAtNANDInport2_InitialCond;

    /* InitializeConditions for RateTransition: '<S7>/TmpRTBAtORInport2' */
    SIL_Arduino_DW.TmpRTBAtORInport2_Buffer0 =
      SIL_Arduino_P.TmpRTBAtORInport2_InitialCondit;
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(SIL_Arduino_M)) {
    rtmSetFirstInitCond(SIL_Arduino_M, 0);
  }
}

/* Model terminate function */
void SIL_Arduino_terminate(void)
{
  /* Terminate for MATLABSystem: '<S8>/Digital Output' */
  matlabCodegenHandle_matlabCod_g(&SIL_Arduino_DW.obj_k);

  /* Terminate for MATLABSystem: '<S9>/Digital Output' */
  matlabCodegenHandle_matlabCod_g(&SIL_Arduino_DW.obj_j);

  /* Terminate for MATLABSystem: '<S3>/Analog Input' */
  matlabCodegenHandle_matlabCodeg(&SIL_Arduino_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
