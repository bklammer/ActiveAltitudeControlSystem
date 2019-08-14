/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: SIL_Raspi.c
 *
 * Code generated for Simulink model 'SIL_Raspi'.
 *
 * Model version                  : 1.53
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jul 28 20:26:52 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SIL_Raspi.h"
#include "SIL_Raspi_private.h"
#include "SIL_Raspi_dt.h"

/* Block signals (default storage) */
B_SIL_Raspi_T SIL_Raspi_B;

/* Continuous states */
X_SIL_Raspi_T SIL_Raspi_X;

/* Block states (default storage) */
DW_SIL_Raspi_T SIL_Raspi_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_SIL_Raspi_T SIL_Raspi_PrevZCX;

/* Real-time model */
RT_MODEL_SIL_Raspi_T SIL_Raspi_M_;
RT_MODEL_SIL_Raspi_T *const SIL_Raspi_M = &SIL_Raspi_M_;

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
  SIL_Raspi_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  SIL_Raspi_step();
  SIL_Raspi_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  SIL_Raspi_step();
  SIL_Raspi_derivatives();

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

/* Model step function */
void SIL_Raspi_step(void)
{
  int32_T ii;
  int32_T b_ii;
  real_T e;
  real_T f;
  ZCEventType zcEvent;
  real_T rtb_CurrentTime;
  real_T x_tmp;
  boolean_T exitg1;
  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&SIL_Raspi_M->solverInfo,
                          ((SIL_Raspi_M->Timing.clockTick0+1)*
      SIL_Raspi_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(SIL_Raspi_M)) {
    SIL_Raspi_M->Timing.t[0] = rtsiGetT(&SIL_Raspi_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(SIL_Raspi_DW.StepCounter_SubsysRanBC);
  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
    /* Constant: '<S4>/Initial Conditions' */
    SIL_Raspi_B.InitialConditions[0] = SIL_Raspi_P.InitialConditions_Value[0];
    SIL_Raspi_B.InitialConditions[1] = SIL_Raspi_P.InitialConditions_Value[1];
  }

  /* Integrator: '<S4>/Integrator' */
  if (SIL_Raspi_DW.Integrator_IWORK != 0) {
    SIL_Raspi_X.Integrator_CSTATE[0] = SIL_Raspi_B.InitialConditions[0];
    SIL_Raspi_X.Integrator_CSTATE[1] = SIL_Raspi_B.InitialConditions[1];
  }

  /* Clock: '<S4>/Clock' */
  rtb_CurrentTime = SIL_Raspi_M->Timing.t[0];
  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
    /* Memory: '<S3>/Memory' */
    SIL_Raspi_B.Memory = SIL_Raspi_DW.Memory_PreviousInput;

    /* MATLAB Function: '<S4>/Flap Angle to Drag Coefficient' */
    SIL_Raspi_B.Cd = ((SIL_Raspi_B.Memory * SIL_Raspi_B.Memory * -3.953E-7 +
                       8.737E-5 * SIL_Raspi_B.Memory) + 4.547E-5) * 1.1 /
      0.010751315458748 + 0.4;
  }

  /* MATLAB Function: '<S4>/MATLAB Function' incorporates:
   *  Constant: '<S4>/Constant2'
   *  Constant: '<S4>/Constant4'
   *  Integrator: '<S4>/Integrator'
   */
  if (rtb_CurrentTime <= SIL_Raspi_P.INTAB1[0]) {
    SIL_Raspi_B.Ti = SIL_Raspi_P.INTAB1[318];
    rtb_CurrentTime = SIL_Raspi_P.INTAB1[636];
  } else if (rtb_CurrentTime < SIL_Raspi_P.INTAB1[317]) {
    ii = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 317)) {
      ii = b_ii;
      if (rtb_CurrentTime <= SIL_Raspi_P.INTAB1[b_ii + 1]) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    }

    SIL_Raspi_B.Ti = SIL_Raspi_P.INTAB1[ii + 319];
    rtb_CurrentTime = (rtb_CurrentTime - SIL_Raspi_P.INTAB1[ii]) /
      (SIL_Raspi_P.INTAB1[ii + 1] - SIL_Raspi_P.INTAB1[ii]);
    SIL_Raspi_B.Ti += rtb_CurrentTime * (SIL_Raspi_B.Ti - SIL_Raspi_P.INTAB1[318
      + ii]);
    SIL_Raspi_B.temp = SIL_Raspi_P.INTAB1[ii + 637];
    rtb_CurrentTime = rtb_CurrentTime * (SIL_Raspi_B.temp - SIL_Raspi_P.INTAB1
      [636 + ii]) + SIL_Raspi_B.temp;
  } else {
    SIL_Raspi_B.Ti = SIL_Raspi_P.INTAB1[635];
    rtb_CurrentTime = SIL_Raspi_P.INTAB1[953];
  }

  if ((SIL_Raspi_X.Integrator_CSTATE[0] < SIL_Raspi_P.INTAB4[110]) &&
      (SIL_Raspi_X.Integrator_CSTATE[0] >= SIL_Raspi_P.INTAB4[0])) {
    ii = 0;
    b_ii = 0;
    exitg1 = false;
    while ((!exitg1) && (b_ii < 110)) {
      ii = b_ii;
      if (SIL_Raspi_X.Integrator_CSTATE[0] <= SIL_Raspi_P.INTAB4[b_ii + 1]) {
        exitg1 = true;
      } else {
        b_ii++;
      }
    }

    SIL_Raspi_B.temp = SIL_Raspi_P.INTAB4[ii + 445];
    SIL_Raspi_B.temp += (SIL_Raspi_X.Integrator_CSTATE[0] -
                         SIL_Raspi_P.INTAB4[ii]) / (SIL_Raspi_P.INTAB4[ii + 1] -
      SIL_Raspi_P.INTAB4[ii]) * (SIL_Raspi_B.temp - SIL_Raspi_P.INTAB4[444 + ii]);
  } else {
    SIL_Raspi_B.temp = (0.00299 * SIL_Raspi_X.Integrator_CSTATE[0] + -131.21) +
      273.15;
    SIL_Raspi_B.temp *= rt_powd_snf(SIL_Raspi_B.temp / 216.6, -11.388) *
      0.002488 / 287.0;
  }

  SIL_Raspi_B.Vz = SIL_Raspi_X.Integrator_CSTATE[1] / rtb_CurrentTime;
  rtb_CurrentTime *= 3.987300564E+14 / ((6.3781E+6 +
    SIL_Raspi_X.Integrator_CSTATE[0]) * (6.3781E+6 +
    SIL_Raspi_X.Integrator_CSTATE[0]));
  SIL_Raspi_B.zd[0] = SIL_Raspi_B.Vz;
  if (SIL_Raspi_B.Ti <= rtb_CurrentTime) {
    if (SIL_Raspi_X.Integrator_CSTATE[0] < 0.1) {
      SIL_Raspi_B.zd[1] = 0.0;
    } else {
      SIL_Raspi_B.zd[1] = (SIL_Raspi_B.Ti - SIL_Raspi_B.Cd * 0.5 *
                           SIL_Raspi_B.temp * (SIL_Raspi_B.Vz * SIL_Raspi_B.Vz) *
                           0.010751315458748) - rtb_CurrentTime;
    }
  } else {
    SIL_Raspi_B.zd[1] = (SIL_Raspi_B.Ti - SIL_Raspi_B.Cd * 0.5 *
                         SIL_Raspi_B.temp * (SIL_Raspi_B.Vz * SIL_Raspi_B.Vz) *
                         0.010751315458748) - rtb_CurrentTime;
  }

  SIL_Raspi_B.sensor_data[0] = SIL_Raspi_B.Cd * 0.010751315458748;
  SIL_Raspi_B.sensor_data[1] = SIL_Raspi_B.Vz;
  SIL_Raspi_B.sensor_data[2] = SIL_Raspi_X.Integrator_CSTATE[0];
  SIL_Raspi_B.sensor_data[3] = SIL_Raspi_B.temp;
  SIL_Raspi_B.sensor_data[4] = SIL_Raspi_B.Ti;

  /* End of MATLAB Function: '<S4>/MATLAB Function' */
  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
  }

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S1>/Constant5'
   */
  SIL_Raspi_B.Ti = SIL_Raspi_B.sensor_data[0];
  rtb_CurrentTime = SIL_Raspi_P.Constant5_Value / SIL_Raspi_B.sensor_data[3];
  SIL_Raspi_B.temp = 19.62 / (SIL_Raspi_B.sensor_data[1] *
    SIL_Raspi_B.sensor_data[1]);
  SIL_Raspi_B.Vz = SIL_Raspi_P.Constant1_Value_m - SIL_Raspi_B.sensor_data[2];
  x_tmp = -SIL_Raspi_B.temp * SIL_Raspi_B.Vz;
  x_tmp *= exp(x_tmp);
  SIL_Raspi_B.w = -2.0;
  SIL_Raspi_B.v = (rtMinusInf);
  ii = 0;
  while ((fabs(SIL_Raspi_B.w - SIL_Raspi_B.v) / fabs(SIL_Raspi_B.w) > 1.0E-6) &&
         (ii < 1000)) {
    SIL_Raspi_B.v = SIL_Raspi_B.w;
    e = exp(SIL_Raspi_B.w);
    f = SIL_Raspi_B.w * e - x_tmp;
    SIL_Raspi_B.w -= f / ((SIL_Raspi_B.w + 1.0) * e - (SIL_Raspi_B.w + 2.0) * f /
                          (2.0 * SIL_Raspi_B.w + 2.0));
    ii++;
  }

  rtb_CurrentTime = (-rtb_CurrentTime * SIL_Raspi_B.w - rtb_CurrentTime *
                     SIL_Raspi_B.temp * SIL_Raspi_B.Vz) / SIL_Raspi_B.Vz;
  if (!rtIsNaN(rtb_CurrentTime)) {
    SIL_Raspi_B.Ti = rtb_CurrentTime;
  }

  if (SIL_Raspi_B.sensor_data[2] > SIL_Raspi_P.Constant1_Value_m) {
    SIL_Raspi_B.Ti = 1.0;
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
  SIL_Raspi_B.ControlSignaluntisofstepperangl = (SIL_Raspi_B.Ti -
    SIL_Raspi_B.sensor_data[0]) * SIL_Raspi_P.ProportionalGain_Value * (real_T)
    (SIL_Raspi_B.sensor_data[4] < SIL_Raspi_P.Constant_Value_o) * (real_T)
    (SIL_Raspi_B.sensor_data[1] < SIL_Raspi_P.Ma07_Value);
  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
    /* RelationalOperator: '<S7>/GreaterThan' incorporates:
     *  Constant: '<S2>/Angle of Air Brake Flaps when Fully Open (degrees)'
     *  Constant: '<S7>/Constant'
     *  Sum: '<S7>/Subtract'
     */
    SIL_Raspi_B.GreaterThan = (SIL_Raspi_B.Memory >
      SIL_Raspi_P.AngleofAirBrakeFlapswhenFullyOp - SIL_Raspi_P.Constant_Value_l);

    /* RelationalOperator: '<S7>/Less Than' incorporates:
     *  Constant: '<S7>/Constant1'
     */
    SIL_Raspi_B.LessThan = (SIL_Raspi_B.Memory > SIL_Raspi_P.Constant1_Value_j);

    /* DiscretePulseGenerator: '<S6>/Step Frequency' */
    SIL_Raspi_B.Howfasttostep = (SIL_Raspi_DW.clockTickCounter <
      SIL_Raspi_P.StepFrequency_Duty) && (SIL_Raspi_DW.clockTickCounter >= 0) ?
      SIL_Raspi_P.StepFrequency_Amp : 0.0;
    if (SIL_Raspi_DW.clockTickCounter >= SIL_Raspi_P.StepFrequency_Period - 1.0)
    {
      SIL_Raspi_DW.clockTickCounter = 0;
    } else {
      SIL_Raspi_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<S6>/Step Frequency' */
  }

  /* RelationalOperator: '<S6>/GreaterThan1' incorporates:
   *  Constant: '<S6>/Constant'
   */
  SIL_Raspi_B.DirectionSignal = (SIL_Raspi_B.ControlSignaluntisofstepperangl >
    SIL_Raspi_P.Constant_Value_k);

  /* Product: '<S7>/Multiply' incorporates:
   *  Abs: '<S6>/Abs'
   *  Constant: '<S6>/Step Size'
   *  Logic: '<S7>/AND2'
   *  Logic: '<S7>/NAND'
   *  Logic: '<S7>/OR'
   *  Product: '<S6>/Multiply'
   *  RelationalOperator: '<S6>/GreaterThan'
   */
  SIL_Raspi_B.Multiply = (real_T)(((!SIL_Raspi_B.DirectionSignal) ||
    (!SIL_Raspi_B.GreaterThan)) && (SIL_Raspi_B.DirectionSignal ||
    SIL_Raspi_B.LessThan)) * ((real_T)(fabs
    (SIL_Raspi_B.ControlSignaluntisofstepperangl) > SIL_Raspi_P.StepSize_Value) *
    SIL_Raspi_B.Howfasttostep);
  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
    /* Outputs for Triggered SubSystem: '<S3>/Step Counter' incorporates:
     *  TriggerPort: '<S11>/Trigger'
     */
    if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
      zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                         &SIL_Raspi_PrevZCX.StepCounter_Trig_ZCE,
                         (SIL_Raspi_B.Multiply));
      if (zcEvent != NO_ZCEVENT) {
        /* UnitDelay: '<S11>/Unit Delay' */
        SIL_Raspi_B.UnitDelay = SIL_Raspi_DW.UnitDelay_DSTATE;

        /* Sum: '<S11>/Sum' incorporates:
         *  Constant: '<S11>/Constant'
         *  Constant: '<S11>/Constant1'
         *  Product: '<S11>/Multiply'
         *  Sum: '<S11>/Add'
         *  UnitDelay: '<S11>/Unit Delay'
         */
        SIL_Raspi_DW.UnitDelay_DSTATE = (SIL_Raspi_P.Constant1_Value + (real_T)
          SIL_Raspi_B.DirectionSignal) * SIL_Raspi_P.Constant_Value +
          SIL_Raspi_B.UnitDelay;
        SIL_Raspi_DW.StepCounter_SubsysRanBC = 4;
      }
    }

    /* End of Outputs for SubSystem: '<S3>/Step Counter' */

    /* MATLAB Function: '<S3>/Steps to Angle' */
    SIL_Raspi_B.flap_angle = SIL_Raspi_B.UnitDelay * 1.8 * 2.5;

    /* Stop: '<S4>/Stop Simulation' incorporates:
     *  Constant: '<S4>/Constant5'
     *  RelationalOperator: '<S4>/Relational Operator'
     */
    if (SIL_Raspi_B.zd[0] <= SIL_Raspi_P.Constant5_Value_k) {
      rtmSetStopRequested(SIL_Raspi_M, 1);
    }

    /* End of Stop: '<S4>/Stop Simulation' */
  }

  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
    /* Update for Integrator: '<S4>/Integrator' */
    SIL_Raspi_DW.Integrator_IWORK = 0;
    if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
      /* Update for Memory: '<S3>/Memory' */
      SIL_Raspi_DW.Memory_PreviousInput = SIL_Raspi_B.flap_angle;
    }

    /* External mode */
    rtExtModeUploadCheckTrigger(2);

    {                                  /* Sample time: [0.0s, 0.0s] */
      rtExtModeUpload(0, (real_T)SIL_Raspi_M->Timing.t[0]);
    }

    if (rtmIsMajorTimeStep(SIL_Raspi_M)) {/* Sample time: [0.005s, 0.0s] */
      rtExtModeUpload(1, (real_T)((SIL_Raspi_M->Timing.clockTick1) * 0.005));
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(SIL_Raspi_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(SIL_Raspi_M)!=-1) &&
          !((rtmGetTFinal(SIL_Raspi_M)-((SIL_Raspi_M->Timing.clockTick1) * 0.005))
            > ((SIL_Raspi_M->Timing.clockTick1) * 0.005) * (DBL_EPSILON))) {
        rtmSetErrorStatus(SIL_Raspi_M, "Simulation finished");
      }

      if (rtmGetStopRequested(SIL_Raspi_M)) {
        rtmSetErrorStatus(SIL_Raspi_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&SIL_Raspi_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     */
    ++SIL_Raspi_M->Timing.clockTick0;
    SIL_Raspi_M->Timing.t[0] = rtsiGetSolverStopTime(&SIL_Raspi_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.005s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.005, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       */
      SIL_Raspi_M->Timing.clockTick1++;
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void SIL_Raspi_derivatives(void)
{
  XDot_SIL_Raspi_T *_rtXdot;
  _rtXdot = ((XDot_SIL_Raspi_T *) SIL_Raspi_M->derivs);

  /* Derivatives for Integrator: '<S4>/Integrator' */
  _rtXdot->Integrator_CSTATE[0] = SIL_Raspi_B.zd[0];
  _rtXdot->Integrator_CSTATE[1] = SIL_Raspi_B.zd[1];
}

/* Model initialize function */
void SIL_Raspi_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)SIL_Raspi_M, 0,
                sizeof(RT_MODEL_SIL_Raspi_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&SIL_Raspi_M->solverInfo,
                          &SIL_Raspi_M->Timing.simTimeStep);
    rtsiSetTPtr(&SIL_Raspi_M->solverInfo, &rtmGetTPtr(SIL_Raspi_M));
    rtsiSetStepSizePtr(&SIL_Raspi_M->solverInfo, &SIL_Raspi_M->Timing.stepSize0);
    rtsiSetdXPtr(&SIL_Raspi_M->solverInfo, &SIL_Raspi_M->derivs);
    rtsiSetContStatesPtr(&SIL_Raspi_M->solverInfo, (real_T **)
                         &SIL_Raspi_M->contStates);
    rtsiSetNumContStatesPtr(&SIL_Raspi_M->solverInfo,
      &SIL_Raspi_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&SIL_Raspi_M->solverInfo,
      &SIL_Raspi_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&SIL_Raspi_M->solverInfo,
      &SIL_Raspi_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&SIL_Raspi_M->solverInfo,
      &SIL_Raspi_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&SIL_Raspi_M->solverInfo, (&rtmGetErrorStatus
      (SIL_Raspi_M)));
    rtsiSetRTModelPtr(&SIL_Raspi_M->solverInfo, SIL_Raspi_M);
  }

  rtsiSetSimTimeStep(&SIL_Raspi_M->solverInfo, MAJOR_TIME_STEP);
  SIL_Raspi_M->intgData.y = SIL_Raspi_M->odeY;
  SIL_Raspi_M->intgData.f[0] = SIL_Raspi_M->odeF[0];
  SIL_Raspi_M->intgData.f[1] = SIL_Raspi_M->odeF[1];
  SIL_Raspi_M->intgData.f[2] = SIL_Raspi_M->odeF[2];
  SIL_Raspi_M->contStates = ((X_SIL_Raspi_T *) &SIL_Raspi_X);
  rtsiSetSolverData(&SIL_Raspi_M->solverInfo, (void *)&SIL_Raspi_M->intgData);
  rtsiSetSolverName(&SIL_Raspi_M->solverInfo,"ode3");
  rtmSetTPtr(SIL_Raspi_M, &SIL_Raspi_M->Timing.tArray[0]);
  rtmSetTFinal(SIL_Raspi_M, 30.0);
  SIL_Raspi_M->Timing.stepSize0 = 0.005;
  rtmSetFirstInitCond(SIL_Raspi_M, 1);

  /* External mode info */
  SIL_Raspi_M->Sizes.checksums[0] = (2069649503U);
  SIL_Raspi_M->Sizes.checksums[1] = (1276412655U);
  SIL_Raspi_M->Sizes.checksums[2] = (1662340380U);
  SIL_Raspi_M->Sizes.checksums[3] = (164005924U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[6];
    SIL_Raspi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&SIL_Raspi_DW.StepCounter_SubsysRanBC;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SIL_Raspi_M->extModeInfo,
      &SIL_Raspi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SIL_Raspi_M->extModeInfo, SIL_Raspi_M->Sizes.checksums);
    rteiSetTPtr(SIL_Raspi_M->extModeInfo, rtmGetTPtr(SIL_Raspi_M));
  }

  /* block I/O */
  (void) memset(((void *) &SIL_Raspi_B), 0,
                sizeof(B_SIL_Raspi_T));

  /* states (continuous) */
  {
    (void) memset((void *)&SIL_Raspi_X, 0,
                  sizeof(X_SIL_Raspi_T));
  }

  /* states (dwork) */
  (void) memset((void *)&SIL_Raspi_DW, 0,
                sizeof(DW_SIL_Raspi_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    SIL_Raspi_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for Constant: '<S4>/Initial Conditions' */
  SIL_Raspi_B.InitialConditions[0] = SIL_Raspi_P.InitialConditions_Value[0];
  SIL_Raspi_B.InitialConditions[1] = SIL_Raspi_P.InitialConditions_Value[1];

  /* Start for DiscretePulseGenerator: '<S6>/Step Frequency' */
  SIL_Raspi_DW.clockTickCounter = 0;
  SIL_Raspi_PrevZCX.StepCounter_Trig_ZCE = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Integrator: '<S4>/Integrator' */
  if (rtmIsFirstInitCond(SIL_Raspi_M)) {
    SIL_Raspi_X.Integrator_CSTATE[0] = 0.0;
    SIL_Raspi_X.Integrator_CSTATE[1] = 0.0;
  }

  SIL_Raspi_DW.Integrator_IWORK = 1;

  /* End of InitializeConditions for Integrator: '<S4>/Integrator' */

  /* InitializeConditions for Memory: '<S3>/Memory' */
  SIL_Raspi_DW.Memory_PreviousInput = SIL_Raspi_P.Memory_InitialCondition;

  /* SystemInitialize for Triggered SubSystem: '<S3>/Step Counter' */
  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  SIL_Raspi_DW.UnitDelay_DSTATE = SIL_Raspi_P.UnitDelay_InitialCondition;

  /* SystemInitialize for Outport: '<S11>/Step Count' */
  SIL_Raspi_B.UnitDelay = SIL_Raspi_P.StepCount_Y0;

  /* End of SystemInitialize for SubSystem: '<S3>/Step Counter' */

  /* set "at time zero" to false */
  if (rtmIsFirstInitCond(SIL_Raspi_M)) {
    rtmSetFirstInitCond(SIL_Raspi_M, 0);
  }
}

/* Model terminate function */
void SIL_Raspi_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
