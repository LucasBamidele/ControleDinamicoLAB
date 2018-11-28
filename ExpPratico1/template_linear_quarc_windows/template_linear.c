/*
 * template_linear.c
 *
 * Real-Time Workshop code generation for Simulink model "template_linear.mdl".
 *
 * Model Version              : 1.63
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Sep 13 17:40:28 2018
 */

#include "template_linear.h"
#include "template_linear_private.h"
#include <stdio.h>
#include "template_linear_dt.h"

/* Block signals (auto storage) */
BlockIO_template_linear template_linear_B;

/* Continuous states */
ContinuousStates_template_linea template_linear_X;

/* Block states (auto storage) */
D_Work_template_linear template_linear_DWork;

/* Real-time model */
RT_MODEL_template_linear template_linear_M_;
RT_MODEL_template_linear *template_linear_M = &template_linear_M_;

/* Function: rt_WriteMat4FileHeader =========================================
 * Abstract:
 *      Writes out MAT-file header.  Returns success or failure.
 *
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

/* This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y,x,
                nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  template_linear_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f0[i]);
  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  template_linear_output(0);
  template_linear_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (temp*f1[i]);
  rtsiSetdX(si, f2);
  template_linear_output(0);
  template_linear_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++)
    x[i] = y[i] + (h*f2[i]);
  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  template_linear_output(0);
  template_linear_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void template_linear_output(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_HILReadEncoder_o2;
  real_T rtb_TmpHiddenBufferAtToFileInpo[4];

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(template_linear_M)) {
    template_linear_M->Timing.t[0] = rtsiGetT(&template_linear_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(template_linear_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&template_linear_M->solverInfo,
                          ((template_linear_M->Timing.clockTick0+1)*
      template_linear_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  {
    real_T deltaT;
    real_T riseValLimit;
    real_T rateLimiterRate;
    if (rtmIsMajorTimeStep(template_linear_M) &&
        template_linear_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: template_linear/HIL Read Encoder (hil_read_encoder_block) */
      {
        t_error result = hil_read_encoder
          (template_linear_DWork.HILInitialize_Card,
           template_linear_P.HILReadEncoder_Channels, 2,
           &template_linear_DWork.HILReadEncoder_Buffer[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(template_linear_M, _rt_error_message);
        } else {
          rtb_HILReadEncoder_o1 = template_linear_DWork.HILReadEncoder_Buffer[0];
          rtb_HILReadEncoder_o2 = template_linear_DWork.HILReadEncoder_Buffer[1];
        }
      }

      /* Gain: '<Root>/m To mm' incorporates:
       *  Gain: '<Root>/cart: counts to meters'
       */
      template_linear_B.mTomm = template_linear_P.cartcountstometers_Gain *
        rtb_HILReadEncoder_o1 * template_linear_P.mTomm_Gain;
    }

    /* TransferFcn Block: '<Root>/HPF: derivative  followed by a LPF' */
    template_linear_B.HPFderivativefollowedbyaLPF =
      template_linear_P.HPFderivativefollowedbyaLPF_D*template_linear_B.mTomm;
    template_linear_B.HPFderivativefollowedbyaLPF +=
      template_linear_P.HPFderivativefollowedbyaLPF_C*
      template_linear_X.HPFderivativefollowedbyaLPF_CST;
    if (rtmIsMajorTimeStep(template_linear_M) &&
        template_linear_M->Timing.TaskCounters.TID[1] == 0) {
    }

    /* SignalGenerator: '<Root>/Signal Generator' */
    {
      real_T phase = template_linear_P.SignalGenerator_Frequency*
        template_linear_M->Timing.t[0];
      phase = phase-floor(phase);
      template_linear_B.SignalGenerator = ( phase >= 0.5 ) ?
        template_linear_P.SignalGenerator_Amplitude :
        -template_linear_P.SignalGenerator_Amplitude;
    }

    /* RateLimiter: '<Root>/Rate Limiter' */
    if (template_linear_DWork.LastMajorTime == (rtInf)) {
      template_linear_B.RateLimiter = template_linear_B.SignalGenerator;
    } else {
      deltaT = template_linear_M->Timing.t[0] -
        template_linear_DWork.LastMajorTime;
      riseValLimit = deltaT * template_linear_P.RateLimiter_RisingLim;
      rateLimiterRate = template_linear_B.SignalGenerator -
        template_linear_DWork.PrevY;
      if (rateLimiterRate > riseValLimit) {
        template_linear_B.RateLimiter = template_linear_DWork.PrevY +
          riseValLimit;
      } else {
        deltaT *= template_linear_P.RateLimiter_FallingLim;
        if (rateLimiterRate < deltaT) {
          template_linear_B.RateLimiter = template_linear_DWork.PrevY + deltaT;
        } else {
          template_linear_B.RateLimiter = template_linear_B.SignalGenerator;
        }
      }
    }

    /* Switch: '<S1>/SwitchControl' incorporates:
     *  Constant: '<S1>/Constant'
     *  Saturate: '<Root>/Saturation'
     */
    if (template_linear_P.Constant_Value >
        template_linear_P.SwitchControl_Threshold) {
      template_linear_B.SwitchControl = rt_SATURATE
        (template_linear_B.RateLimiter, template_linear_P.Saturation_LowerSat,
         template_linear_P.Saturation_UpperSat);
    } else {
      template_linear_B.SwitchControl = template_linear_B.SignalGenerator;
    }

    if (rtmIsMajorTimeStep(template_linear_M) &&
        template_linear_M->Timing.TaskCounters.TID[1] == 0) {
      /* S-Function Block: template_linear/HIL Write Analog (hil_write_analog_block) */
      {
        t_error result;
        result = hil_write_analog(template_linear_DWork.HILInitialize_Card,
          &template_linear_P.HILWriteAnalog_Channels, 1,
          &template_linear_B.SwitchControl);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(template_linear_M, _rt_error_message);
        }
      }

      /* SignalConversion: '<Root>/TmpHiddenBufferAtTo FileInport1' */
      rtb_TmpHiddenBufferAtToFileInpo[0] =
        template_linear_B.HPFderivativefollowedbyaLPF;
      rtb_TmpHiddenBufferAtToFileInpo[1] = template_linear_B.mTomm;
      rtb_TmpHiddenBufferAtToFileInpo[2] = template_linear_B.SwitchControl;
      rtb_TmpHiddenBufferAtToFileInpo[3] = template_linear_B.SignalGenerator;

      /* ToFile: '<Root>/To File' */
      if (rtmIsMajorTimeStep(template_linear_M)) {
        if (!(++template_linear_DWork.ToFile_IWORK.Decimation % 1) &&
            (template_linear_DWork.ToFile_IWORK.Count*5)+1 < 100000000 ) {
          real_T u[5];
          FILE *fp = (FILE *) template_linear_DWork.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            template_linear_DWork.ToFile_IWORK.Decimation = 0;
            u[0] = template_linear_M->Timing.t[1];
            u[1] = rtb_TmpHiddenBufferAtToFileInpo[0];
            u[2] = rtb_TmpHiddenBufferAtToFileInpo[1];
            u[3] = rtb_TmpHiddenBufferAtToFileInpo[2];
            u[4] = rtb_TmpHiddenBufferAtToFileInpo[3];
            if (fwrite(u, sizeof(real_T), 5, fp) != 5) {
              rtmSetErrorStatus(template_linear_M,
                                "Error writing to MAT-file quad.mat");
              return;
            }

            if (((++template_linear_DWork.ToFile_IWORK.Count)*5)+1 >= 100000000)
            {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file quad.mat.\n");
            }
          }
        }
      }
    }
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Model update function */
void template_linear_update(int_T tid)
{
  /* Update for RateLimiter: '<Root>/Rate Limiter' */
  template_linear_DWork.PrevY = template_linear_B.RateLimiter;
  template_linear_DWork.LastMajorTime = template_linear_M->Timing.t[0];
  if (rtmIsMajorTimeStep(template_linear_M)) {
    rt_ertODEUpdateContinuousStates(&template_linear_M->solverInfo);
  }

  /* Update absolute time for base rate */
  if (!(++template_linear_M->Timing.clockTick0))
    ++template_linear_M->Timing.clockTickH0;
  template_linear_M->Timing.t[0] = template_linear_M->Timing.clockTick0 *
    template_linear_M->Timing.stepSize0 + template_linear_M->Timing.clockTickH0 *
    template_linear_M->Timing.stepSize0 * 4294967296.0;
  if (rtmIsMajorTimeStep(template_linear_M) &&
      template_linear_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.002s, 0.0s] */
    if (!(++template_linear_M->Timing.clockTick1))
      ++template_linear_M->Timing.clockTickH1;
    template_linear_M->Timing.t[1] = template_linear_M->Timing.clockTick1 *
      template_linear_M->Timing.stepSize1 +
      template_linear_M->Timing.clockTickH1 *
      template_linear_M->Timing.stepSize1 * 4294967296.0;
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void template_linear_derivatives(void)
{
  /* TransferFcn Block: '<Root>/HPF: derivative  followed by a LPF' */
  {
    ((StateDerivatives_template_linea *) template_linear_M->ModelData.derivs)
      ->HPFderivativefollowedbyaLPF_CST = template_linear_B.mTomm;
    ((StateDerivatives_template_linea *) template_linear_M->ModelData.derivs)
      ->HPFderivativefollowedbyaLPF_CST +=
      (template_linear_P.HPFderivativefollowedbyaLPF_A)*
      template_linear_X.HPFderivativefollowedbyaLPF_CST;
  }
}

/* Model initialize function */
void template_linear_initialize(boolean_T firstTime)
{
  (void)firstTime;

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)template_linear_M,0,
                sizeof(RT_MODEL_template_linear));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&template_linear_M->solverInfo,
                          &template_linear_M->Timing.simTimeStep);
    rtsiSetTPtr(&template_linear_M->solverInfo, &rtmGetTPtr(template_linear_M));
    rtsiSetStepSizePtr(&template_linear_M->solverInfo,
                       &template_linear_M->Timing.stepSize0);
    rtsiSetdXPtr(&template_linear_M->solverInfo,
                 &template_linear_M->ModelData.derivs);
    rtsiSetContStatesPtr(&template_linear_M->solverInfo,
                         &template_linear_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&template_linear_M->solverInfo,
      &template_linear_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&template_linear_M->solverInfo, (&rtmGetErrorStatus
      (template_linear_M)));
    rtsiSetRTModelPtr(&template_linear_M->solverInfo, template_linear_M);
  }

  rtsiSetSimTimeStep(&template_linear_M->solverInfo, MAJOR_TIME_STEP);
  template_linear_M->ModelData.intgData.y = template_linear_M->ModelData.odeY;
  template_linear_M->ModelData.intgData.f[0] = template_linear_M->
    ModelData.odeF[0];
  template_linear_M->ModelData.intgData.f[1] = template_linear_M->
    ModelData.odeF[1];
  template_linear_M->ModelData.intgData.f[2] = template_linear_M->
    ModelData.odeF[2];
  template_linear_M->ModelData.intgData.f[3] = template_linear_M->
    ModelData.odeF[3];
  template_linear_M->ModelData.contStates = ((real_T *) &template_linear_X);
  rtsiSetSolverData(&template_linear_M->solverInfo, (void *)
                    &template_linear_M->ModelData.intgData);
  rtsiSetSolverName(&template_linear_M->solverInfo,"ode4");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = template_linear_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    template_linear_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    template_linear_M->Timing.sampleTimes =
      (&template_linear_M->Timing.sampleTimesArray[0]);
    template_linear_M->Timing.offsetTimes =
      (&template_linear_M->Timing.offsetTimesArray[0]);

    /* task periods */
    template_linear_M->Timing.sampleTimes[0] = (0.0);
    template_linear_M->Timing.sampleTimes[1] = (0.002);

    /* task offsets */
    template_linear_M->Timing.offsetTimes[0] = (0.0);
    template_linear_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(template_linear_M, &template_linear_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = template_linear_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    template_linear_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(template_linear_M, -1);
  template_linear_M->Timing.stepSize0 = 0.002;
  template_linear_M->Timing.stepSize1 = 0.002;

  /* external mode info */
  template_linear_M->Sizes.checksums[0] = (4167139517U);
  template_linear_M->Sizes.checksums[1] = (2819575112U);
  template_linear_M->Sizes.checksums[2] = (1575769901U);
  template_linear_M->Sizes.checksums[3] = (3072127818U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    template_linear_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(&rt_ExtModeInfo,
      &template_linear_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(&rt_ExtModeInfo, template_linear_M->Sizes.checksums);
    rteiSetTPtr(&rt_ExtModeInfo, rtmGetTPtr(template_linear_M));
  }

  template_linear_M->solverInfoPtr = (&template_linear_M->solverInfo);
  template_linear_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&template_linear_M->solverInfo, 0.002);
  rtsiSetSolverMode(&template_linear_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  template_linear_M->ModelData.blockIO = ((void *) &template_linear_B);

  {
    template_linear_B.mTomm = 0.0;
    template_linear_B.HPFderivativefollowedbyaLPF = 0.0;
    template_linear_B.SignalGenerator = 0.0;
    template_linear_B.RateLimiter = 0.0;
    template_linear_B.SwitchControl = 0.0;
  }

  /* parameters */
  template_linear_M->ModelData.defaultParam = ((real_T *) &template_linear_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &template_linear_X;
    template_linear_M->ModelData.contStates = (x);
    (void) memset((void *)x,0,
                  sizeof(ContinuousStates_template_linea));
  }

  /* states (dwork) */
  template_linear_M->Work.dwork = ((void *) &template_linear_DWork);
  (void) memset((void *)&template_linear_DWork, 0,
                sizeof(D_Work_template_linear));

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      template_linear_DWork.HILInitialize_POValues[i] = 0.0;
    }
  }

  template_linear_DWork.PrevY = 0.0;
  template_linear_DWork.LastMajorTime = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo,0,
                  sizeof(dtInfo));
    template_linear_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 15;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }
}

/* Model terminate function */
void template_linear_terminate(void)
{
  /* S-Function Block: template_linear/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    hil_task_stop_all(template_linear_DWork.HILInitialize_Card);
    hil_task_delete_all(template_linear_DWork.HILInitialize_Card);
    hil_monitor_stop_all(template_linear_DWork.HILInitialize_Card);
    hil_monitor_delete_all(template_linear_DWork.HILInitialize_Card);
    is_switching = false;
    if ((template_linear_P.HILInitialize_AOTerminate && !is_switching) ||
        (template_linear_P.HILInitialize_AOExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &template_linear_DWork.HILInitialize_AOVoltages
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = template_linear_P.HILInitialize_AOFinal;
        }
      }

      result = hil_write_analog(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_AOChannels[0], 8U,
        &template_linear_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
      }
    }

    if ((template_linear_P.HILInitialize_DOTerminate && !is_switching) ||
        (template_linear_P.HILInitialize_DOExit && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &template_linear_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = template_linear_P.HILInitialize_DOFinal;
        }
      }

      result = hil_write_digital(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &template_linear_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
      }
    }

    if ((template_linear_P.HILInitialize_POTerminate && !is_switching) ||
        (template_linear_P.HILInitialize_POExit && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &template_linear_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = template_linear_P.HILInitialize_POFinal;
        }
      }

      result = hil_write_pwm(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_POChannels[0], 8U,
        &template_linear_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
      }
    }

    hil_close(template_linear_DWork.HILInitialize_Card);
    template_linear_DWork.HILInitialize_Card = NULL;
  }

  /* ToFile Block: '<Root>/To File' */
  {
    FILE *fp = (FILE *) template_linear_DWork.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      const char *fileName = "quad.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(template_linear_M, "Error closing MAT-file quad.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(template_linear_M, "Error reopening MAT-file quad.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 5, template_linear_DWork.ToFile_IWORK.Count,
           "dados")) {
        rtmSetErrorStatus(template_linear_M,
                          "Error writing header for dados to MAT-file quad.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(template_linear_M, "Error closing MAT-file quad.mat");
        return;
      }

      template_linear_DWork.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* External mode */
  rtExtModeShutdown(2);
}

/*========================================================================*
 * Start of GRT compatible call interface                                 *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  template_linear_output(tid);
}

void MdlUpdate(int_T tid)
{
  template_linear_update(tid);
}

void MdlInitializeSizes(void)
{
  template_linear_M->Sizes.numContStates = (1);/* Number of continuous states */
  template_linear_M->Sizes.numY = (0); /* Number of model outputs */
  template_linear_M->Sizes.numU = (0); /* Number of model inputs */
  template_linear_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  template_linear_M->Sizes.numSampTimes = (2);/* Number of sample times */
  template_linear_M->Sizes.numBlocks = (17);/* Number of blocks */
  template_linear_M->Sizes.numBlockIO = (5);/* Number of block outputs */
  template_linear_M->Sizes.numBlockPrms = (118);/* Sum of parameter "widths" */
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
  /* TransferFcn Block: '<Root>/HPF: derivative  followed by a LPF' */
  template_linear_X.HPFderivativefollowedbyaLPF_CST = 0.0;

  /* InitializeConditions for RateLimiter: '<Root>/Rate Limiter' */
  template_linear_DWork.LastMajorTime = (rtInf);
}

void MdlStart(void)
{
  /* S-Function Block: template_linear/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &template_linear_DWork.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(template_linear_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (template_linear_DWork.HILInitialize_Card, "update_rate=normal", 19);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(template_linear_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(template_linear_DWork.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(template_linear_M, _rt_error_message);
      return;
    }

    if ((template_linear_P.HILInitialize_AIPStart && !is_switching) ||
        (template_linear_P.HILInitialize_AIPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &template_linear_DWork.HILInitialize_AIMinimums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = template_linear_P.HILInitialize_AILow;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &template_linear_DWork.HILInitialize_AIMaximums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = template_linear_P.HILInitialize_AIHigh;
        }
      }

      result = hil_set_analog_input_ranges
        (template_linear_DWork.HILInitialize_Card,
         &template_linear_P.HILInitialize_AIChannels[0], 8U,
         &template_linear_DWork.HILInitialize_AIMinimums[0],
         &template_linear_DWork.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if ((template_linear_P.HILInitialize_AOPStart && !is_switching) ||
        (template_linear_P.HILInitialize_AOPEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &template_linear_DWork.HILInitialize_AOMinimums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = template_linear_P.HILInitialize_AOLow;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &template_linear_DWork.HILInitialize_AOMaximums
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = template_linear_P.HILInitialize_AOHigh;
        }
      }

      result = hil_set_analog_output_ranges
        (template_linear_DWork.HILInitialize_Card,
         &template_linear_P.HILInitialize_AOChannels[0], 8U,
         &template_linear_DWork.HILInitialize_AOMinimums[0],
         &template_linear_DWork.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if ((template_linear_P.HILInitialize_AOStart && !is_switching) ||
        (template_linear_P.HILInitialize_AOEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &template_linear_DWork.HILInitialize_AOVoltages
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = template_linear_P.HILInitialize_AOInitial;
        }
      }

      result = hil_write_analog(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_AOChannels[0], 8U,
        &template_linear_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if (template_linear_P.HILInitialize_AOReset) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &template_linear_DWork.HILInitialize_AOVoltages
          [0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = template_linear_P.HILInitialize_AOWatchdog;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (template_linear_DWork.HILInitialize_Card,
         &template_linear_P.HILInitialize_AOChannels[0], 8U,
         &template_linear_DWork.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    result = hil_set_digital_directions(template_linear_DWork.HILInitialize_Card,
      NULL, 0U, &template_linear_P.HILInitialize_DOChannels[0], 8U);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(template_linear_M, _rt_error_message);
      return;
    }

    if ((template_linear_P.HILInitialize_DOStart && !is_switching) ||
        (template_linear_P.HILInitialize_DOEnter && is_switching)) {
      {
        int_T i1;
        boolean_T *dw_DOBits = &template_linear_DWork.HILInitialize_DOBits[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOBits[i1] = template_linear_P.HILInitialize_DOInitial;
        }
      }

      result = hil_write_digital(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_DOChannels[0], 8U, (t_boolean *)
        &template_linear_DWork.HILInitialize_DOBits[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if (template_linear_P.HILInitialize_DOReset) {
      {
        int_T i1;
        int32_T *dw_DOStates = &template_linear_DWork.HILInitialize_DOStates[0];
        for (i1=0; i1 < 8; i1++) {
          dw_DOStates[i1] = template_linear_P.HILInitialize_DOWatchdog;
        }
      }

      result = hil_watchdog_set_digital_expiration_state
        (template_linear_DWork.HILInitialize_Card,
         &template_linear_P.HILInitialize_DOChannels[0], 8U, (const
          t_digital_state *) &template_linear_DWork.HILInitialize_DOStates[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if ((template_linear_P.HILInitialize_EIPStart && !is_switching) ||
        (template_linear_P.HILInitialize_EIPEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &template_linear_DWork.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = template_linear_P.HILInitialize_EIQuadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (template_linear_DWork.HILInitialize_Card,
         &template_linear_P.HILInitialize_EIChannels[0], 8U,
         (t_encoder_quadrature_mode *)
         &template_linear_DWork.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if ((template_linear_P.HILInitialize_EIStart && !is_switching) ||
        (template_linear_P.HILInitialize_EIEnter && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &template_linear_DWork.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = template_linear_P.HILInitialize_EIInitial;
        }
      }

      result = hil_set_encoder_counts(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_EIChannels[0], 8U,
        &template_linear_DWork.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if ((template_linear_P.HILInitialize_POPStart && !is_switching) ||
        (template_linear_P.HILInitialize_POPEnter && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &template_linear_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = template_linear_P.HILInitialize_POModes;
        }
      }

      result = hil_set_pwm_mode(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_POChannels[0], 8U, (t_pwm_mode *)
        &template_linear_DWork.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_POChannels =
          &template_linear_P.HILInitialize_POChannels[0];
        int32_T *dw_POModeValues =
          &template_linear_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            template_linear_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = (p_HILInitialize_POChannels[i1]);
            template_linear_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = template_linear_P.HILInitialize_POFrequency;
            num_duty_cycle_modes++;
          } else {
            template_linear_DWork.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = (p_HILInitialize_POChannels[i1]);
            template_linear_DWork.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] = template_linear_P.HILInitialize_POFrequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(template_linear_DWork.HILInitialize_Card,
          &template_linear_DWork.HILInitialize_POSortedChans[0],
          num_duty_cycle_modes,
          &template_linear_DWork.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(template_linear_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(template_linear_DWork.HILInitialize_Card,
          &template_linear_DWork.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &template_linear_DWork.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(template_linear_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &template_linear_DWork.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = template_linear_P.HILInitialize_POConfiguration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &template_linear_DWork.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = template_linear_P.HILInitialize_POAlignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &template_linear_DWork.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = template_linear_P.HILInitialize_POPolarity;
        }
      }

      result = hil_set_pwm_configuration
        (template_linear_DWork.HILInitialize_Card,
         &template_linear_P.HILInitialize_POChannels[0], 8U,
         (t_pwm_configuration *)
         &template_linear_DWork.HILInitialize_POModeValues[0],
         (t_pwm_alignment *) &template_linear_DWork.HILInitialize_POAlignValues
         [0],
         (t_pwm_polarity *) &template_linear_DWork.HILInitialize_POPolarityVals
         [0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &template_linear_DWork.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = template_linear_P.HILInitialize_POLeading;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &template_linear_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = template_linear_P.HILInitialize_POTrailing;
        }
      }

      result = hil_set_pwm_deadband(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_POChannels[0], 8U,
        &template_linear_DWork.HILInitialize_POSortedFreqs[0],
        &template_linear_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if ((template_linear_P.HILInitialize_POStart && !is_switching) ||
        (template_linear_P.HILInitialize_POEnter && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &template_linear_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = template_linear_P.HILInitialize_POInitial;
        }
      }

      result = hil_write_pwm(template_linear_DWork.HILInitialize_Card,
        &template_linear_P.HILInitialize_POChannels[0], 8U,
        &template_linear_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }

    if (template_linear_P.HILInitialize_POReset) {
      {
        int_T i1;
        real_T *dw_POValues = &template_linear_DWork.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = template_linear_P.HILInitialize_POWatchdog;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (template_linear_DWork.HILInitialize_Card,
         &template_linear_P.HILInitialize_POChannels[0], 8U,
         &template_linear_DWork.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(template_linear_M, _rt_error_message);
        return;
      }
    }
  }

  /* ToFile Block: '<Root>/To File' */
  {
    const char *fileName = "quad.mat";
    FILE *fp;
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(template_linear_M, "Error creating .mat file quad.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,5,0,"dados")) {
      rtmSetErrorStatus(template_linear_M,
                        "Error writing mat file header to file quad.mat");
      return;
    }

    template_linear_DWork.ToFile_IWORK.Count = 0;
    template_linear_DWork.ToFile_IWORK.Decimation = -1;
    template_linear_DWork.ToFile_PWORK.FilePtr = fp;
  }

  MdlInitialize();
}

RT_MODEL_template_linear *template_linear(void)
{
  template_linear_initialize(1);
  return template_linear_M;
}

void MdlTerminate(void)
{
  template_linear_terminate();
}

/*========================================================================*
 * End of GRT compatible call interface                                   *
 *========================================================================*/
