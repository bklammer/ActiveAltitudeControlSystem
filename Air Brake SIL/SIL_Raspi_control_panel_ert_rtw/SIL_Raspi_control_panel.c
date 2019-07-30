/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: SIL_Raspi_control_panel.c
 *
 * Code generated for Simulink model 'SIL_Raspi_control_panel'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jul 29 13:33:01 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SIL_Raspi_control_panel.h"
#include "SIL_Raspi_control_panel_private.h"
#include "SIL_Raspi_control_panel_dt.h"

/* Block signals (default storage) */
B_SIL_Raspi_control_panel_T SIL_Raspi_control_panel_B;

/* Continuous states */
X_SIL_Raspi_control_panel_T SIL_Raspi_control_panel_X;

/* Block states (default storage) */
DW_SIL_Raspi_control_panel_T SIL_Raspi_control_panel_DW;

/* Real-time model */
RT_MODEL_SIL_Raspi_control_pa_T SIL_Raspi_control_panel_M_;
RT_MODEL_SIL_Raspi_control_pa_T *const SIL_Raspi_control_panel_M =
  &SIL_Raspi_control_panel_M_;

/* Forward declaration for local functions */
static void SIL_Raspi_SystemCore_release_lx(const
  codertarget_linux_blocks_Digi_T *obj);
static void SIL_Raspi__SystemCore_delete_lx(const
  codertarget_linux_blocks_Digi_T *obj);
static void matlabCodegenHandle_matlabCo_lx(codertarget_linux_blocks_Digi_T *obj);
static void SIL_Raspi__SystemCore_release_l(const
  codertarget_linux_blocks_Digi_T *obj);
static void SIL_Raspi_c_SystemCore_delete_l(const
  codertarget_linux_blocks_Digi_T *obj);
static void matlabCodegenHandle_matlabCod_l(codertarget_linux_blocks_Digi_T *obj);
static void SIL_Raspi_co_SystemCore_release(const
  codertarget_raspi_internal_I2_T *obj);
static void SIL_Raspi_con_SystemCore_delete(const
  codertarget_raspi_internal_I2_T *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_I2_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to "remember" which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void SIL_Raspi_control_panel_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[2] = ((boolean_T)rtmStepTask(SIL_Raspi_control_panel_M, 2));
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
  if (SIL_Raspi_control_panel_M->Timing.TaskCounters.TID[1] == 0) {
    SIL_Raspi_control_panel_M->Timing.RateInteraction.TID1_2 =
      (SIL_Raspi_control_panel_M->Timing.TaskCounters.TID[2] == 0);
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (SIL_Raspi_control_panel_M->Timing.TaskCounters.TID[2])++;
  if ((SIL_Raspi_control_panel_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.005s, 0.0s] */
    SIL_Raspi_control_panel_M->Timing.TaskCounters.TID[2] = 0;
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
  SIL_Raspi_control_panel_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SIL_Raspi_control_panel_step0();
  SIL_Raspi_control_panel_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SIL_Raspi_control_panel_step0();
  SIL_Raspi_control_panel_derivatives();

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

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void SIL_Raspi_SystemCore_release_lx(const
  codertarget_linux_blocks_Digi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(20U);
  }
}

static void SIL_Raspi__SystemCore_delete_lx(const
  codertarget_linux_blocks_Digi_T *obj)
{
  SIL_Raspi_SystemCore_release_lx(obj);
}

static void matlabCodegenHandle_matlabCo_lx(codertarget_linux_blocks_Digi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SIL_Raspi__SystemCore_delete_lx(obj);
  }
}

static void SIL_Raspi__SystemCore_release_l(const
  codertarget_linux_blocks_Digi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(21U);
  }
}

static void SIL_Raspi_c_SystemCore_delete_l(const
  codertarget_linux_blocks_Digi_T *obj)
{
  SIL_Raspi__SystemCore_release_l(obj);
}

static void matlabCodegenHandle_matlabCod_l(codertarget_linux_blocks_Digi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SIL_Raspi_c_SystemCore_delete_l(obj);
  }
}

static void SIL_Raspi_co_SystemCore_release(const
  codertarget_raspi_internal_I2_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void SIL_Raspi_con_SystemCore_delete(const
  codertarget_raspi_internal_I2_T *obj)
{
  SIL_Raspi_co_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_I2_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    SIL_Raspi_con_SystemCore_delete(obj);
  }
}

/* Model step function for TID0 */
void SIL_Raspi_control_panel_step0(void) /* Sample time: [0.0s, 0.0s] */
{
  int32_T ii;
  int32_T b_ii;
  real_T e;
  real_T f;
  real_T rtb_CurrentTime;
  uint8_T tmp;
  real_T x_tmp;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&SIL_Raspi_control_panel_M->solverInfo,
                          ((SIL_Raspi_control_panel_M->Timing.clockTick0+1)*
      SIL_Raspi_control_panel_M->Timing.stepSize0));

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SIL_Raspi_control_panel_M)) {
    SIL_Raspi_control_panel_M->Timing.t[0] = rtsiGetT
      (&SIL_Raspi_control_panel_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M)) {
    /* Constant: '<S5>/Initial Conditions' */
    SIL_Raspi_control_panel_B.InitialConditions[0] =
      SIL_Raspi_control_panel_P.InitialConditions_Value[0];
    SIL_Raspi_control_panel_B.InitialConditions[1] =
      SIL_Raspi_control_panel_P.InitialConditions_Value[1];
  }

  /* Integrator: '<S5>/Integrator' */
  if (SIL_Raspi_control_panel_DW.Integrator_IWORK != 0) {
    SIL_Raspi_control_panel_X.Integrator_CSTATE[0] =
      SIL_Raspi_control_panel_B.InitialConditions[0];
    SIL_Raspi_control_panel_X.Integrator_CSTATE[1] =
      SIL_Raspi_control_panel_B.InitialConditions[1];
  }

  /* Clock: '<S5>/Clock' */
  rtb_CurrentTime = SIL_Raspi_control_panel_M->Timing.t[0];

  /* RateTransition: '<S5>/TmpRTBAtMATLAB FunctionInport3' */
  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M) &&
      SIL_Raspi_control_panel_M->Timing.RateInteraction.TID1_2) {
    SIL_Raspi_control_panel_B.TmpRTBAtMATLABFunctionInport3 =
      SIL_Raspi_control_panel_DW.TmpRTBAtMATLABFunctionInport3_B;
  }

  /* End of RateTransition: '<S5>/TmpRTBAtMATLAB FunctionInport3' */

  /* MATLAB Function: '<S5>/MATLAB Function' incorporates:
   *  Constant: '<S5>/Constant2'
   *  Constant: '<S5>/Constant4'
   *  Integrator: '<S5>/Integrator'
   */
  if (rtb_CurrentTime <= SIL_Raspi_control_panel_P.INTAB1[0]) {
    SIL_Raspi_control_panel_B.Ti = SIL_Raspi_control_panel_P.INTAB1[318];
    rtb_CurrentTime = SIL_Raspi_control_panel_P.INTAB1[636];
  } else if (rtb_CurrentTime < SIL_Raspi_control_panel_P.INTAB1[317]) {
    ii = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 317)) {
      ii = b_ii;
      if (rtb_CurrentTime <= SIL_Raspi_control_panel_P.INTAB1[b_ii + 1]) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    }

    SIL_Raspi_control_panel_B.Ti = SIL_Raspi_control_panel_P.INTAB1[ii + 319];
    rtb_CurrentTime = (rtb_CurrentTime - SIL_Raspi_control_panel_P.INTAB1[ii]) /
      (SIL_Raspi_control_panel_P.INTAB1[ii + 1] -
       SIL_Raspi_control_panel_P.INTAB1[ii]);
    SIL_Raspi_control_panel_B.Ti += rtb_CurrentTime *
      (SIL_Raspi_control_panel_B.Ti - SIL_Raspi_control_panel_P.INTAB1[318 + ii]);
    SIL_Raspi_control_panel_B.temp = SIL_Raspi_control_panel_P.INTAB1[ii + 637];
    rtb_CurrentTime = rtb_CurrentTime * (SIL_Raspi_control_panel_B.temp -
      SIL_Raspi_control_panel_P.INTAB1[636 + ii]) +
      SIL_Raspi_control_panel_B.temp;
  } else {
    SIL_Raspi_control_panel_B.Ti = SIL_Raspi_control_panel_P.INTAB1[635];
    rtb_CurrentTime = SIL_Raspi_control_panel_P.INTAB1[953];
  }

  if ((SIL_Raspi_control_panel_X.Integrator_CSTATE[0] <
       SIL_Raspi_control_panel_P.INTAB4[110]) &&
      (SIL_Raspi_control_panel_X.Integrator_CSTATE[0] >=
       SIL_Raspi_control_panel_P.INTAB4[0])) {
    ii = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 110)) {
      ii = b_ii;
      if (SIL_Raspi_control_panel_X.Integrator_CSTATE[0] <=
          SIL_Raspi_control_panel_P.INTAB4[b_ii + 1]) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    }

    SIL_Raspi_control_panel_B.temp = SIL_Raspi_control_panel_P.INTAB4[ii + 445];
    SIL_Raspi_control_panel_B.temp +=
      (SIL_Raspi_control_panel_X.Integrator_CSTATE[0] -
       SIL_Raspi_control_panel_P.INTAB4[ii]) /
      (SIL_Raspi_control_panel_P.INTAB4[ii + 1] -
       SIL_Raspi_control_panel_P.INTAB4[ii]) * (SIL_Raspi_control_panel_B.temp -
      SIL_Raspi_control_panel_P.INTAB4[444 + ii]);
  } else {
    SIL_Raspi_control_panel_B.temp = (0.00299 *
      SIL_Raspi_control_panel_X.Integrator_CSTATE[0] + -131.21) + 273.15;
    SIL_Raspi_control_panel_B.temp *= rt_powd_snf(SIL_Raspi_control_panel_B.temp
      / 216.6, -11.388) * 0.002488 / 287.0;
  }

  SIL_Raspi_control_panel_B.Vz = SIL_Raspi_control_panel_X.Integrator_CSTATE[1] /
    rtb_CurrentTime;
  rtb_CurrentTime *= 3.987300564E+14 / ((6.3781E+6 +
    SIL_Raspi_control_panel_X.Integrator_CSTATE[0]) * (6.3781E+6 +
    SIL_Raspi_control_panel_X.Integrator_CSTATE[0]));
  SIL_Raspi_control_panel_B.zd[0] = SIL_Raspi_control_panel_B.Vz;
  if (SIL_Raspi_control_panel_B.Ti <= rtb_CurrentTime) {
    if (SIL_Raspi_control_panel_X.Integrator_CSTATE[0] < 0.1) {
      SIL_Raspi_control_panel_B.zd[1] = 0.0;
    } else {
      SIL_Raspi_control_panel_B.zd[1] = (SIL_Raspi_control_panel_B.Ti -
        SIL_Raspi_control_panel_B.TmpRTBAtMATLABFunctionInport3 * 0.5 *
        SIL_Raspi_control_panel_B.temp * (SIL_Raspi_control_panel_B.Vz *
        SIL_Raspi_control_panel_B.Vz) * 0.010751315458748) - rtb_CurrentTime;
    }
  } else {
    SIL_Raspi_control_panel_B.zd[1] = (SIL_Raspi_control_panel_B.Ti -
      SIL_Raspi_control_panel_B.TmpRTBAtMATLABFunctionInport3 * 0.5 *
      SIL_Raspi_control_panel_B.temp * (SIL_Raspi_control_panel_B.Vz *
      SIL_Raspi_control_panel_B.Vz) * 0.010751315458748) - rtb_CurrentTime;
  }

  SIL_Raspi_control_panel_B.sensor_data[0] =
    SIL_Raspi_control_panel_B.TmpRTBAtMATLABFunctionInport3 * 0.010751315458748;
  SIL_Raspi_control_panel_B.sensor_data[1] = SIL_Raspi_control_panel_B.Vz;
  SIL_Raspi_control_panel_B.sensor_data[2] =
    SIL_Raspi_control_panel_X.Integrator_CSTATE[0];
  SIL_Raspi_control_panel_B.sensor_data[3] = SIL_Raspi_control_panel_B.temp;
  SIL_Raspi_control_panel_B.sensor_data[4] = SIL_Raspi_control_panel_B.Ti;

  /* End of MATLAB Function: '<S5>/MATLAB Function' */

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<S1>/Target Altitude (m) '
   *  Constant: '<S2>/Constant5'
   */
  SIL_Raspi_control_panel_B.Ti = SIL_Raspi_control_panel_B.sensor_data[0];
  rtb_CurrentTime = SIL_Raspi_control_panel_P.Constant5_Value /
    (SIL_Raspi_control_panel_B.sensor_data[3] * 0.9);
  SIL_Raspi_control_panel_B.temp = 19.62 /
    (SIL_Raspi_control_panel_B.sensor_data[1] *
     SIL_Raspi_control_panel_B.sensor_data[1]);
  SIL_Raspi_control_panel_B.Vz = SIL_Raspi_control_panel_P.TargetAltitudem_Value
    - SIL_Raspi_control_panel_B.sensor_data[2];
  x_tmp = -SIL_Raspi_control_panel_B.temp * SIL_Raspi_control_panel_B.Vz;
  x_tmp *= exp(x_tmp);
  SIL_Raspi_control_panel_B.w = -2.0;
  SIL_Raspi_control_panel_B.v = (rtMinusInf);
  ii = 0;
  while ((fabs(SIL_Raspi_control_panel_B.w - SIL_Raspi_control_panel_B.v) / fabs
          (SIL_Raspi_control_panel_B.w) > 1.0E-6) && (ii < 1000)) {
    SIL_Raspi_control_panel_B.v = SIL_Raspi_control_panel_B.w;
    e = exp(SIL_Raspi_control_panel_B.w);
    f = SIL_Raspi_control_panel_B.w * e - x_tmp;
    SIL_Raspi_control_panel_B.w -= f / ((SIL_Raspi_control_panel_B.w + 1.0) * e
      - (SIL_Raspi_control_panel_B.w + 2.0) * f / (2.0 *
      SIL_Raspi_control_panel_B.w + 2.0));
    ii++;
  }

  rtb_CurrentTime = (-rtb_CurrentTime * SIL_Raspi_control_panel_B.w -
                     rtb_CurrentTime * SIL_Raspi_control_panel_B.temp *
                     SIL_Raspi_control_panel_B.Vz) /
    SIL_Raspi_control_panel_B.Vz;
  if (!rtIsNaN(rtb_CurrentTime)) {
    SIL_Raspi_control_panel_B.Ti = rtb_CurrentTime;
  }

  if (SIL_Raspi_control_panel_B.sensor_data[2] >
      SIL_Raspi_control_panel_P.TargetAltitudem_Value) {
    SIL_Raspi_control_panel_B.Ti = 1.0;
  }

  /* End of MATLAB Function: '<S2>/MATLAB Function' */

  /* Product: '<S2>/Multiply' incorporates:
   *  Constant: '<S2>/Constant'
   *  Constant: '<S2>/Ma 0.7'
   *  Constant: '<S2>/Proportional Gain'
   *  RelationalOperator: '<S2>/If going  slow enough'
   *  RelationalOperator: '<S2>/If no thrust'
   *  Sum: '<S2>/Sum'
   */
  SIL_Raspi_control_panel_B.ControlSignaluntisofstepperangl =
    (SIL_Raspi_control_panel_B.Ti - SIL_Raspi_control_panel_B.sensor_data[0]) *
    SIL_Raspi_control_panel_P.ProportionalGain_Value * (real_T)
    (SIL_Raspi_control_panel_B.sensor_data[4] <
     SIL_Raspi_control_panel_P.Constant_Value) * (real_T)
    (SIL_Raspi_control_panel_B.sensor_data[1] <
     SIL_Raspi_control_panel_P.Ma07_Value);

  /* RateTransition: '<S1>/Flap Angle1' incorporates:
   *  RateTransition: '<S8>/TmpRTBAtNANDInport2'
   *  RateTransition: '<S8>/TmpRTBAtORInport2'
   */
  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M)) {
    if (SIL_Raspi_control_panel_M->Timing.RateInteraction.TID1_2) {
      SIL_Raspi_control_panel_B.FlapAngledeg =
        SIL_Raspi_control_panel_DW.FlapAngle1_Buffer0;
    }

    if (SIL_Raspi_control_panel_M->Timing.RateInteraction.TID1_2) {
      SIL_Raspi_control_panel_B.TmpRTBAtNANDInport2 =
        SIL_Raspi_control_panel_DW.TmpRTBAtNANDInport2_Buffer0;
      SIL_Raspi_control_panel_B.TmpRTBAtORInport2 =
        SIL_Raspi_control_panel_DW.TmpRTBAtORInport2_Buffer0;
    }

    /* DiscretePulseGenerator: '<S7>/Step Frequency' */
    SIL_Raspi_control_panel_B.Howfasttostep =
      (SIL_Raspi_control_panel_DW.clockTickCounter <
       SIL_Raspi_control_panel_P.StepFrequency_Duty) &&
      (SIL_Raspi_control_panel_DW.clockTickCounter >= 0) ?
      SIL_Raspi_control_panel_P.StepFrequency_Amp : 0.0;
    if (SIL_Raspi_control_panel_DW.clockTickCounter >=
        SIL_Raspi_control_panel_P.StepFrequency_Period - 1.0) {
      SIL_Raspi_control_panel_DW.clockTickCounter = 0;
    } else {
      SIL_Raspi_control_panel_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S7>/Step Frequency' */
  }

  /* End of RateTransition: '<S1>/Flap Angle1' */

  /* RelationalOperator: '<S7>/GreaterThan1' incorporates:
   *  Constant: '<S7>/Constant'
   */
  SIL_Raspi_control_panel_B.DirectionSignal =
    (SIL_Raspi_control_panel_B.ControlSignaluntisofstepperangl >
     SIL_Raspi_control_panel_P.Constant_Value_m);

  /* Product: '<S8>/Multiply' incorporates:
   *  Abs: '<S7>/Abs'
   *  Constant: '<S7>/Step Size'
   *  Logic: '<S8>/AND2'
   *  Logic: '<S8>/NAND'
   *  Logic: '<S8>/OR'
   *  Product: '<S7>/Multiply'
   *  RelationalOperator: '<S7>/GreaterThan'
   */
  SIL_Raspi_control_panel_B.Multiply = (real_T)
    (((!SIL_Raspi_control_panel_B.DirectionSignal) ||
      (!SIL_Raspi_control_panel_B.TmpRTBAtNANDInport2)) &&
     (SIL_Raspi_control_panel_B.DirectionSignal ||
      SIL_Raspi_control_panel_B.TmpRTBAtORInport2)) * ((real_T)(fabs
    (SIL_Raspi_control_panel_B.ControlSignaluntisofstepperangl) >
    SIL_Raspi_control_panel_P.StepSize_Value) *
    SIL_Raspi_control_panel_B.Howfasttostep);
  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M)) {
  }

  /* MATLABSystem: '<S10>/Digital Write' */
  SIL_Raspi_control_panel_B.Ti = rt_roundd_snf
    (SIL_Raspi_control_panel_B.Multiply);
  if (SIL_Raspi_control_panel_B.Ti < 256.0) {
    if (SIL_Raspi_control_panel_B.Ti >= 0.0) {
      tmp = (uint8_T)SIL_Raspi_control_panel_B.Ti;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  MW_gpioWrite(20U, tmp);

  /* End of MATLABSystem: '<S10>/Digital Write' */

  /* MATLABSystem: '<S9>/Digital Write' */
  MW_gpioWrite(21U, (uint8_T)SIL_Raspi_control_panel_B.DirectionSignal);

  /* Stop: '<S5>/Stop Simulation' incorporates:
   *  Constant: '<S5>/Constant5'
   *  RelationalOperator: '<S5>/Relational Operator'
   */
  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M) &&
      (SIL_Raspi_control_panel_B.zd[0] <=
       SIL_Raspi_control_panel_P.Constant5_Value_k)) {
    rtmSetStopRequested(SIL_Raspi_control_panel_M, 1);
  }

  /* End of Stop: '<S5>/Stop Simulation' */
  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M)) {
    /* Update for Integrator: '<S5>/Integrator' */
    SIL_Raspi_control_panel_DW.Integrator_IWORK = 0;

    /* External mode */
    rtExtModeUploadCheckTrigger(3);
    rtExtModeUpload(1, (real_T)SIL_Raspi_control_panel_M->Timing.t[0]);
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SIL_Raspi_control_panel_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(SIL_Raspi_control_panel_M)!=-1) &&
          !((rtmGetTFinal(SIL_Raspi_control_panel_M)-
             ((SIL_Raspi_control_panel_M->Timing.clockTick1) * 0.0025)) >
            ((SIL_Raspi_control_panel_M->Timing.clockTick1) * 0.0025) *
            (DBL_EPSILON))) {
        rtmSetErrorStatus(SIL_Raspi_control_panel_M, "Simulation finished");
      }

      if (rtmGetStopRequested(SIL_Raspi_control_panel_M)) {
        rtmSetErrorStatus(SIL_Raspi_control_panel_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&SIL_Raspi_control_panel_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++SIL_Raspi_control_panel_M->Timing.clockTick0;
    SIL_Raspi_control_panel_M->Timing.t[0] = rtsiGetSolverStopTime
      (&SIL_Raspi_control_panel_M->solverInfo);

    /* Update absolute time */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.0025, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    SIL_Raspi_control_panel_M->Timing.clockTick1++;
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SIL_Raspi_control_panel_derivatives(void)
{
  XDot_SIL_Raspi_control_panel_T *_rtXdot;
  _rtXdot = ((XDot_SIL_Raspi_control_panel_T *)
             SIL_Raspi_control_panel_M->derivs);

  /* Derivatives for Integrator: '<S5>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = SIL_Raspi_control_panel_B.zd[0];
  _rtXdot->Integrator_CSTATE[1] = SIL_Raspi_control_panel_B.zd[1];
}

/* Model step function for TID2 */
void SIL_Raspi_control_panel_step2(void) /* Sample time: [0.005s, 0.0s] */
{
  /* local block i/o variables */
  boolean_T rtb_GreaterThan;
  boolean_T rtb_LessThan;
  int16_T b_output;
  uint8_T status;
  uint8_T output_raw[2];
  uint8_T b_x[2];

  /* MATLABSystem: '<S4>/I2C Master Read' */
  if (SIL_Raspi_control_panel_DW.obj.SampleTime !=
      SIL_Raspi_control_panel_P.I2CMasterRead_SampleTime) {
    SIL_Raspi_control_panel_DW.obj.SampleTime =
      SIL_Raspi_control_panel_P.I2CMasterRead_SampleTime;
  }

  status = 0U;
  status = MW_I2C_MasterWrite(SIL_Raspi_control_panel_DW.obj.MW_I2C_HANDLE, 72U,
    &status, 1U, true, false);
  if (0 == status) {
    MW_I2C_MasterRead(SIL_Raspi_control_panel_DW.obj.MW_I2C_HANDLE, 72U,
                      output_raw, 2U, false, true);
    memcpy((void *)&b_output, (void *)&output_raw[0], (uint32_T)((size_t)1 *
            sizeof(int16_T)));
    memcpy((void *)&output_raw[0], (void *)&b_output, (uint32_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = output_raw[1];
    b_x[1] = output_raw[0];
    memcpy((void *)&SIL_Raspi_control_panel_B.RotaryPositionSensor, (void *)
           &b_x[0], (uint32_T)((size_t)1 * sizeof(int16_T)));
  } else {
    SIL_Raspi_control_panel_B.RotaryPositionSensor = 0;
  }

  /* End of MATLABSystem: '<S4>/I2C Master Read' */

  /* Product: '<S11>/Multiply1' incorporates:
   *  Constant: '<S4>/ '
   *  Constant: '<S4>/  '
   *  Constant: '<S4>/   '
   *  DataTypeConversion: '<S4>/Cast To Double'
   *  Product: '<S11>/Divide'
   *  Sum: '<S11>/Subtract'
   *  Sum: '<S11>/Subtract1'
   */
  SIL_Raspi_control_panel_B.FlapAngle = ((real_T)
    SIL_Raspi_control_panel_B.RotaryPositionSensor -
    SIL_Raspi_control_panel_P._Value) / (SIL_Raspi_control_panel_P._Value_d -
    SIL_Raspi_control_panel_P._Value) * SIL_Raspi_control_panel_P._Value_k;

  /* RelationalOperator: '<S8>/GreaterThan' incorporates:
   *  Constant: '<S3>/Angle of Air Brake Flaps when Fully Open (degrees)'
   *  Constant: '<S8>/Constant'
   *  Sum: '<S8>/Subtract'
   */
  rtb_GreaterThan = (SIL_Raspi_control_panel_B.FlapAngle >
                     SIL_Raspi_control_panel_P.AngleofAirBrakeFlapswhenFullyOp -
                     SIL_Raspi_control_panel_P.Constant_Value_f);

  /* RelationalOperator: '<S8>/Less Than' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  rtb_LessThan = (SIL_Raspi_control_panel_B.FlapAngle >
                  SIL_Raspi_control_panel_P.Constant1_Value);

  /* MATLAB Function: '<S5>/Flap Angle to Drag Coefficient' */
  SIL_Raspi_control_panel_B.Cd = ((SIL_Raspi_control_panel_B.FlapAngle *
    SIL_Raspi_control_panel_B.FlapAngle * -3.953E-7 + 8.737E-5 *
    SIL_Raspi_control_panel_B.FlapAngle) + 4.547E-5) * 1.1 / 0.010751315458748 +
    0.4;

  /* Update for RateTransition: '<S5>/TmpRTBAtMATLAB FunctionInport3' */
  SIL_Raspi_control_panel_DW.TmpRTBAtMATLABFunctionInport3_B =
    SIL_Raspi_control_panel_B.Cd;

  /* Update for RateTransition: '<S1>/Flap Angle1' */
  SIL_Raspi_control_panel_DW.FlapAngle1_Buffer0 =
    SIL_Raspi_control_panel_B.FlapAngle;

  /* Update for RateTransition: '<S8>/TmpRTBAtNANDInport2' */
  SIL_Raspi_control_panel_DW.TmpRTBAtNANDInport2_Buffer0 = rtb_GreaterThan;

  /* Update for RateTransition: '<S8>/TmpRTBAtORInport2' */
  SIL_Raspi_control_panel_DW.TmpRTBAtORInport2_Buffer0 = rtb_LessThan;
  rtExtModeUpload(2, (real_T)((SIL_Raspi_control_panel_M->Timing.clockTick2) *
    0.005));

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.005, which is the step size
   * of the task. Size of "clockTick2" ensures timer will not overflow during the
   * application lifespan selected.
   */
  SIL_Raspi_control_panel_M->Timing.clockTick2++;
}

/* Model step wrapper function for compatibility with a static main program */
void SIL_Raspi_control_panel_step(int_T tid)
{
  switch (tid) {
   case 0 :
    SIL_Raspi_control_panel_step0();
    break;

   case 2 :
    SIL_Raspi_control_panel_step2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void SIL_Raspi_control_panel_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SIL_Raspi_control_panel_M, 0,
                sizeof(RT_MODEL_SIL_Raspi_control_pa_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SIL_Raspi_control_panel_M->solverInfo,
                          &SIL_Raspi_control_panel_M->Timing.simTimeStep);
    rtsiSetTPtr(&SIL_Raspi_control_panel_M->solverInfo, &rtmGetTPtr
                (SIL_Raspi_control_panel_M));
    rtsiSetStepSizePtr(&SIL_Raspi_control_panel_M->solverInfo,
                       &SIL_Raspi_control_panel_M->Timing.stepSize0);
    rtsiSetdXPtr(&SIL_Raspi_control_panel_M->solverInfo,
                 &SIL_Raspi_control_panel_M->derivs);
    rtsiSetContStatesPtr(&SIL_Raspi_control_panel_M->solverInfo, (real_T **)
                         &SIL_Raspi_control_panel_M->contStates);
    rtsiSetNumContStatesPtr(&SIL_Raspi_control_panel_M->solverInfo,
      &SIL_Raspi_control_panel_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SIL_Raspi_control_panel_M->solverInfo,
      &SIL_Raspi_control_panel_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&SIL_Raspi_control_panel_M->solverInfo,
      &SIL_Raspi_control_panel_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&SIL_Raspi_control_panel_M->solverInfo,
      &SIL_Raspi_control_panel_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SIL_Raspi_control_panel_M->solverInfo,
                          (&rtmGetErrorStatus(SIL_Raspi_control_panel_M)));
    rtsiSetRTModelPtr(&SIL_Raspi_control_panel_M->solverInfo,
                      SIL_Raspi_control_panel_M);
  }

  rtsiSetSimTimeStep(&SIL_Raspi_control_panel_M->solverInfo, MAJOR_TIME_STEP);
  SIL_Raspi_control_panel_M->intgData.y = SIL_Raspi_control_panel_M->odeY;
  SIL_Raspi_control_panel_M->intgData.f[0] = SIL_Raspi_control_panel_M->odeF[0];
  SIL_Raspi_control_panel_M->intgData.f[1] = SIL_Raspi_control_panel_M->odeF[1];
  SIL_Raspi_control_panel_M->intgData.f[2] = SIL_Raspi_control_panel_M->odeF[2];
  SIL_Raspi_control_panel_M->contStates = ((X_SIL_Raspi_control_panel_T *)
    &SIL_Raspi_control_panel_X);
  rtsiSetSolverData(&SIL_Raspi_control_panel_M->solverInfo, (void *)
                    &SIL_Raspi_control_panel_M->intgData);
  rtsiSetSolverName(&SIL_Raspi_control_panel_M->solverInfo,"ode3");
  rtmSetTPtr(SIL_Raspi_control_panel_M,
             &SIL_Raspi_control_panel_M->Timing.tArray[0]);
  rtmSetTFinal(SIL_Raspi_control_panel_M, 30.0);
  SIL_Raspi_control_panel_M->Timing.stepSize0 = 0.0025;
  rtmSetFirstInitCond(SIL_Raspi_control_panel_M, 1);

  /* External mode info */
  SIL_Raspi_control_panel_M->Sizes.checksums[0] = (2677622246U);
  SIL_Raspi_control_panel_M->Sizes.checksums[1] = (1744609380U);
  SIL_Raspi_control_panel_M->Sizes.checksums[2] = (2237376769U);
  SIL_Raspi_control_panel_M->Sizes.checksums[3] = (4034046813U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[7];
    SIL_Raspi_control_panel_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SIL_Raspi_control_panel_M->extModeInfo,
      &SIL_Raspi_control_panel_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SIL_Raspi_control_panel_M->extModeInfo,
                        SIL_Raspi_control_panel_M->Sizes.checksums);
    rteiSetTPtr(SIL_Raspi_control_panel_M->extModeInfo, rtmGetTPtr
                (SIL_Raspi_control_panel_M));
  }

  /* block I/O */
  (void) memset(((void *) &SIL_Raspi_control_panel_B), 0,
                sizeof(B_SIL_Raspi_control_panel_T));

  /* states (continuous) */
  {
    (void) memset((void *)&SIL_Raspi_control_panel_X, 0,
                  sizeof(X_SIL_Raspi_control_panel_T));
  }

  /* states (dwork) */
  (void) memset((void *)&SIL_Raspi_control_panel_DW, 0,
                sizeof(DW_SIL_Raspi_control_panel_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SIL_Raspi_control_panel_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    codertarget_raspi_internal_I2_T *obj;
    uint32_T i2cname;

    /* Start for Constant: '<S5>/Initial Conditions' */
    SIL_Raspi_control_panel_B.InitialConditions[0] =
      SIL_Raspi_control_panel_P.InitialConditions_Value[0];
    SIL_Raspi_control_panel_B.InitialConditions[1] =
      SIL_Raspi_control_panel_P.InitialConditions_Value[1];

    /* Start for RateTransition: '<S5>/TmpRTBAtMATLAB FunctionInport3' */
    SIL_Raspi_control_panel_B.TmpRTBAtMATLABFunctionInport3 =
      SIL_Raspi_control_panel_P.TmpRTBAtMATLABFunctionInport3_I;

    /* Start for RateTransition: '<S1>/Flap Angle1' */
    SIL_Raspi_control_panel_B.FlapAngledeg =
      SIL_Raspi_control_panel_P.FlapAngle1_InitialCondition;

    /* Start for RateTransition: '<S8>/TmpRTBAtNANDInport2' */
    SIL_Raspi_control_panel_B.TmpRTBAtNANDInport2 =
      SIL_Raspi_control_panel_P.TmpRTBAtNANDInport2_InitialCond;

    /* Start for RateTransition: '<S8>/TmpRTBAtORInport2' */
    SIL_Raspi_control_panel_B.TmpRTBAtORInport2 =
      SIL_Raspi_control_panel_P.TmpRTBAtORInport2_InitialCondit;

    /* Start for DiscretePulseGenerator: '<S7>/Step Frequency' */
    SIL_Raspi_control_panel_DW.clockTickCounter = 0;

    /* Start for MATLABSystem: '<S10>/Digital Write' */
    SIL_Raspi_control_panel_DW.obj_k.matlabCodegenIsDeleted = true;
    SIL_Raspi_control_panel_DW.obj_k.isInitialized = 0;
    SIL_Raspi_control_panel_DW.obj_k.matlabCodegenIsDeleted = false;
    SIL_Raspi_control_panel_DW.obj_k.isSetupComplete = false;
    SIL_Raspi_control_panel_DW.obj_k.isInitialized = 1;
    MW_gpioInit(20U, true);
    SIL_Raspi_control_panel_DW.obj_k.isSetupComplete = true;

    /* Start for MATLABSystem: '<S9>/Digital Write' */
    SIL_Raspi_control_panel_DW.obj_f.matlabCodegenIsDeleted = true;
    SIL_Raspi_control_panel_DW.obj_f.isInitialized = 0;
    SIL_Raspi_control_panel_DW.obj_f.matlabCodegenIsDeleted = false;
    SIL_Raspi_control_panel_DW.obj_f.isSetupComplete = false;
    SIL_Raspi_control_panel_DW.obj_f.isInitialized = 1;
    MW_gpioInit(21U, true);
    SIL_Raspi_control_panel_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/I2C Master Read' */
    SIL_Raspi_control_panel_DW.obj.matlabCodegenIsDeleted = true;
    SIL_Raspi_control_panel_DW.obj.isInitialized = 0;
    SIL_Raspi_control_panel_DW.obj.matlabCodegenIsDeleted = false;
    SIL_Raspi_control_panel_DW.obj.SampleTime =
      SIL_Raspi_control_panel_P.I2CMasterRead_SampleTime;
    obj = &SIL_Raspi_control_panel_DW.obj;
    SIL_Raspi_control_panel_DW.obj.isSetupComplete = false;
    SIL_Raspi_control_panel_DW.obj.isInitialized = 1;
    i2cname = 1;
    obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    SIL_Raspi_control_panel_DW.obj.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(SIL_Raspi_control_panel_DW.obj.MW_I2C_HANDLE,
                       SIL_Raspi_control_panel_DW.obj.BusSpeed);
    SIL_Raspi_control_panel_DW.obj.isSetupComplete = true;

    /* InitializeConditions for Integrator: '<S5>/Integrator' */
    if (rtmIsFirstInitCond(SIL_Raspi_control_panel_M)) {
      SIL_Raspi_control_panel_X.Integrator_CSTATE[0] = 0.0;
      SIL_Raspi_control_panel_X.Integrator_CSTATE[1] = 0.0;
    }

    SIL_Raspi_control_panel_DW.Integrator_IWORK = 1;

    /* End of InitializeConditions for Integrator: '<S5>/Integrator' */

    /* InitializeConditions for RateTransition: '<S5>/TmpRTBAtMATLAB FunctionInport3' */
    SIL_Raspi_control_panel_DW.TmpRTBAtMATLABFunctionInport3_B =
      SIL_Raspi_control_panel_P.TmpRTBAtMATLABFunctionInport3_I;

    /* InitializeConditions for RateTransition: '<S1>/Flap Angle1' */
    SIL_Raspi_control_panel_DW.FlapAngle1_Buffer0 =
      SIL_Raspi_control_panel_P.FlapAngle1_InitialCondition;

    /* InitializeConditions for RateTransition: '<S8>/TmpRTBAtNANDInport2' */
    SIL_Raspi_control_panel_DW.TmpRTBAtNANDInport2_Buffer0 =
      SIL_Raspi_control_panel_P.TmpRTBAtNANDInport2_InitialCond;

    /* InitializeConditions for RateTransition: '<S8>/TmpRTBAtORInport2' */
    SIL_Raspi_control_panel_DW.TmpRTBAtORInport2_Buffer0 =
      SIL_Raspi_control_panel_P.TmpRTBAtORInport2_InitialCondit;
  }

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(SIL_Raspi_control_panel_M)) {
    rtmSetFirstInitCond(SIL_Raspi_control_panel_M, 0);
  }
}

/* Model terminate function */
void SIL_Raspi_control_panel_terminate(void)
{
  /* Terminate for MATLABSystem: '<S10>/Digital Write' */
  matlabCodegenHandle_matlabCo_lx(&SIL_Raspi_control_panel_DW.obj_k);

  /* Terminate for MATLABSystem: '<S9>/Digital Write' */
  matlabCodegenHandle_matlabCod_l(&SIL_Raspi_control_panel_DW.obj_f);

  /* Terminate for MATLABSystem: '<S4>/I2C Master Read' */
  matlabCodegenHandle_matlabCodeg(&SIL_Raspi_control_panel_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
