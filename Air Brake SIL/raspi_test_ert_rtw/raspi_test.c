/*
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * File: raspi_test.c
 *
 * Code generated for Simulink model 'raspi_test'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sun Jul 28 14:40:13 2019
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "raspi_test.h"
#include "raspi_test_private.h"
#include "raspi_test_dt.h"

/* Block signals (default storage) */
B_raspi_test_T raspi_test_B;

/* Block states (default storage) */
DW_raspi_test_T raspi_test_DW;

/* Real-time model */
RT_MODEL_raspi_test_T raspi_test_M_;
RT_MODEL_raspi_test_T *const raspi_test_M = &raspi_test_M_;

/* Forward declaration for local functions */
static void raspi_test_SystemCore_release(const codertarget_linux_blocks_Digi_T *
  obj);
static void raspi_test_SystemCore_delete(const codertarget_linux_blocks_Digi_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_linux_blocks_Digi_T *obj);
static void raspi_test_SystemCore_release_a(const
  codertarget_linux_blocks_Digi_T *obj);
static void raspi_test_SystemCore_delete_a(const codertarget_linux_blocks_Digi_T
  *obj);
static void matlabCodegenHandle_matlabCod_a(codertarget_linux_blocks_Digi_T *obj);
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

static void raspi_test_SystemCore_release(const codertarget_linux_blocks_Digi_T *
  obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(21U);
  }
}

static void raspi_test_SystemCore_delete(const codertarget_linux_blocks_Digi_T
  *obj)
{
  raspi_test_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_linux_blocks_Digi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    raspi_test_SystemCore_delete(obj);
  }
}

static void raspi_test_SystemCore_release_a(const
  codertarget_linux_blocks_Digi_T *obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_gpioTerminate(20U);
  }
}

static void raspi_test_SystemCore_delete_a(const codertarget_linux_blocks_Digi_T
  *obj)
{
  raspi_test_SystemCore_release_a(obj);
}

static void matlabCodegenHandle_matlabCod_a(codertarget_linux_blocks_Digi_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    raspi_test_SystemCore_delete_a(obj);
  }
}

/* Model step function */
void raspi_test_step(void)
{
  real_T tmp;
  uint8_T tmp_0;

  /* MATLABSystem: '<S1>/Digital Write' incorporates:
   *  Constant: '<Root>/DIR'
   */
  tmp = rt_roundd_snf(raspi_test_P.DIR_Value);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  MW_gpioWrite(21U, tmp_0);

  /* End of MATLABSystem: '<S1>/Digital Write' */

  /* DiscretePulseGenerator: '<Root>/STEP' */
  raspi_test_B.STEP = (raspi_test_DW.clockTickCounter < raspi_test_P.STEP_Duty) &&
    (raspi_test_DW.clockTickCounter >= 0) ? raspi_test_P.STEP_Amp : 0.0;
  if (raspi_test_DW.clockTickCounter >= raspi_test_P.STEP_Period - 1.0) {
    raspi_test_DW.clockTickCounter = 0;
  } else {
    raspi_test_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/STEP' */

  /* MATLABSystem: '<S2>/Digital Write' */
  tmp = rt_roundd_snf(raspi_test_B.STEP);
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      tmp_0 = (uint8_T)tmp;
    } else {
      tmp_0 = 0U;
    }
  } else {
    tmp_0 = MAX_uint8_T;
  }

  MW_gpioWrite(20U, tmp_0);

  /* End of MATLABSystem: '<S2>/Digital Write' */

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rtExtModeUpload(0, (real_T)raspi_test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0005s, 0.0s] */
    if ((rtmGetTFinal(raspi_test_M)!=-1) &&
        !((rtmGetTFinal(raspi_test_M)-raspi_test_M->Timing.taskTime0) >
          raspi_test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(raspi_test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(raspi_test_M)) {
      rtmSetErrorStatus(raspi_test_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  raspi_test_M->Timing.taskTime0 =
    (++raspi_test_M->Timing.clockTick0) * raspi_test_M->Timing.stepSize0;
}

/* Model initialize function */
void raspi_test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)raspi_test_M, 0,
                sizeof(RT_MODEL_raspi_test_T));
  rtmSetTFinal(raspi_test_M, -1);
  raspi_test_M->Timing.stepSize0 = 0.0005;

  /* External mode info */
  raspi_test_M->Sizes.checksums[0] = (2150311049U);
  raspi_test_M->Sizes.checksums[1] = (875592828U);
  raspi_test_M->Sizes.checksums[2] = (2141719665U);
  raspi_test_M->Sizes.checksums[3] = (3886293555U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    raspi_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(raspi_test_M->extModeInfo,
      &raspi_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(raspi_test_M->extModeInfo, raspi_test_M->Sizes.checksums);
    rteiSetTPtr(raspi_test_M->extModeInfo, rtmGetTPtr(raspi_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &raspi_test_B), 0,
                sizeof(B_raspi_test_T));

  /* states (dwork) */
  (void) memset((void *)&raspi_test_DW, 0,
                sizeof(DW_raspi_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    raspi_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for MATLABSystem: '<S1>/Digital Write' */
  raspi_test_DW.obj_f.matlabCodegenIsDeleted = true;
  raspi_test_DW.obj_f.isInitialized = 0;
  raspi_test_DW.obj_f.matlabCodegenIsDeleted = false;
  raspi_test_DW.obj_f.isSetupComplete = false;
  raspi_test_DW.obj_f.isInitialized = 1;
  MW_gpioInit(21U, true);
  raspi_test_DW.obj_f.isSetupComplete = true;

  /* Start for DiscretePulseGenerator: '<Root>/STEP' */
  raspi_test_DW.clockTickCounter = 0;

  /* Start for MATLABSystem: '<S2>/Digital Write' */
  raspi_test_DW.obj.matlabCodegenIsDeleted = true;
  raspi_test_DW.obj.isInitialized = 0;
  raspi_test_DW.obj.matlabCodegenIsDeleted = false;
  raspi_test_DW.obj.isSetupComplete = false;
  raspi_test_DW.obj.isInitialized = 1;
  MW_gpioInit(20U, true);
  raspi_test_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void raspi_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<S1>/Digital Write' */
  matlabCodegenHandle_matlabCodeg(&raspi_test_DW.obj_f);

  /* Terminate for MATLABSystem: '<S2>/Digital Write' */
  matlabCodegenHandle_matlabCod_a(&raspi_test_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
