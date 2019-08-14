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
 * Model version                  : 1.18
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Mon Jul 29 09:08:07 2019
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
static void raspi_test_SystemCore_release(const codertarget_raspi_internal_I2_T *
  obj);
static void raspi_test_SystemCore_delete(const codertarget_raspi_internal_I2_T
  *obj);
static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_I2_T *obj);
static void raspi_test_SystemCore_release(const codertarget_raspi_internal_I2_T *
  obj)
{
  if ((obj->isInitialized == 1) && obj->isSetupComplete) {
    MW_I2C_Close(obj->MW_I2C_HANDLE);
  }
}

static void raspi_test_SystemCore_delete(const codertarget_raspi_internal_I2_T
  *obj)
{
  raspi_test_SystemCore_release(obj);
}

static void matlabCodegenHandle_matlabCodeg(codertarget_raspi_internal_I2_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    raspi_test_SystemCore_delete(obj);
  }
}

/* Model step function */
void raspi_test_step(void)
{
  int16_T output;
  int16_T b_output;
  uint8_T status;
  uint8_T output_raw[2];
  uint8_T b_x[2];

  /* MATLABSystem: '<Root>/I2C Master Read' */
  if (raspi_test_DW.obj.SampleTime != raspi_test_P.I2CMasterRead_SampleTime) {
    raspi_test_DW.obj.SampleTime = raspi_test_P.I2CMasterRead_SampleTime;
  }

  status = 0U;
  status = MW_I2C_MasterWrite(raspi_test_DW.obj.MW_I2C_HANDLE, 72U, &status, 1U,
    true, false);
  if (0 == status) {
    MW_I2C_MasterRead(raspi_test_DW.obj.MW_I2C_HANDLE, 72U, output_raw, 2U,
                      false, true);
    memcpy((void *)&b_output, (void *)&output_raw[0], (uint32_T)((size_t)1 *
            sizeof(int16_T)));
    memcpy((void *)&output_raw[0], (void *)&b_output, (uint32_T)((size_t)2 *
            sizeof(uint8_T)));
    b_x[0] = output_raw[1];
    b_x[1] = output_raw[0];
    memcpy((void *)&output, (void *)&b_x[0], (uint32_T)((size_t)1 * sizeof
            (int16_T)));
  } else {
    output = 0;
  }

  /* DataTypeConversion: '<Root>/Cast To Double' incorporates:
   *  MATLABSystem: '<Root>/I2C Master Read'
   */
  raspi_test_B.CastToDouble = output;

  /* Product: '<S3>/Multiply1' incorporates:
   *  Constant: '<Root>/ '
   *  Constant: '<Root>/  '
   *  Constant: '<Root>/   '
   *  Product: '<S3>/Divide'
   *  Sum: '<S3>/Subtract'
   *  Sum: '<S3>/Subtract1'
   */
  raspi_test_B.FlapAngle = (raspi_test_B.CastToDouble - raspi_test_P._Value) /
    (raspi_test_P._Value_b - raspi_test_P._Value) * raspi_test_P._Value_i;

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, (real_T)raspi_test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
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
  raspi_test_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  raspi_test_M->Sizes.checksums[0] = (3517670838U);
  raspi_test_M->Sizes.checksums[1] = (4117695739U);
  raspi_test_M->Sizes.checksums[2] = (449224543U);
  raspi_test_M->Sizes.checksums[3] = (3292989292U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    raspi_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
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

  {
    codertarget_raspi_internal_I2_T *obj;
    uint32_T i2cname;

    /* Start for MATLABSystem: '<Root>/I2C Master Read' */
    raspi_test_DW.obj.matlabCodegenIsDeleted = true;
    raspi_test_DW.obj.isInitialized = 0;
    raspi_test_DW.obj.matlabCodegenIsDeleted = false;
    raspi_test_DW.obj.SampleTime = raspi_test_P.I2CMasterRead_SampleTime;
    obj = &raspi_test_DW.obj;
    raspi_test_DW.obj.isSetupComplete = false;
    raspi_test_DW.obj.isInitialized = 1;
    i2cname = 1;
    obj->MW_I2C_HANDLE = MW_I2C_Open(i2cname, 0);
    raspi_test_DW.obj.BusSpeed = 100000U;
    MW_I2C_SetBusSpeed(raspi_test_DW.obj.MW_I2C_HANDLE,
                       raspi_test_DW.obj.BusSpeed);
    raspi_test_DW.obj.isSetupComplete = true;
  }
}

/* Model terminate function */
void raspi_test_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/I2C Master Read' */
  matlabCodegenHandle_matlabCodeg(&raspi_test_DW.obj);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
