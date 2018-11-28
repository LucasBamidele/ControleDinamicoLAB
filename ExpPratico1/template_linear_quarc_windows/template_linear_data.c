/*
 * template_linear_data.c
 *
 * Real-Time Workshop code generation for Simulink model "template_linear.mdl".
 *
 * Model Version              : 1.63
 * Real-Time Workshop version : 7.2  (R2008b)  04-Aug-2008
 * C source code generated on : Thu Sep 13 17:40:28 2018
 */

#include "template_linear.h"
#include "template_linear_private.h"

/* Block parameters (auto storage) */
Parameters_template_linear template_linear_P = {
  0.0,                                 /* HILInitialize_OOStart : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOEnter : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOTerminate : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_OOExit : '<Root>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AIHigh : '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AILow : '<Root>/HIL Initialize'
                                        */
  10.0,                                /* HILInitialize_AOHigh : '<Root>/HIL Initialize'
                                        */
  -10.0,                               /* HILInitialize_AOLow : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOInitial : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOFinal : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_AOWatchdog : '<Root>/HIL Initialize'
                                        */
  2.4305934065934067E+004,             /* HILInitialize_POFrequency : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POLeading : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POTrailing : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POInitial : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POFinal : '<Root>/HIL Initialize'
                                        */
  0.0,                                 /* HILInitialize_POWatchdog : '<Root>/HIL Initialize'
                                        */
  2.2749E-005,                         /* cartcountstometers_Gain : '<Root>/cart: counts to meters'
                                        */
  1000.0,                              /* mTomm_Gain : '<Root>/m To mm'
                                        */
  -30.0,                               /* HPFderivativefollowedbyaLPF_A : '<Root>/HPF: derivative  followed by a LPF'
                                        */
  -900.0,                              /* HPFderivativefollowedbyaLPF_C : '<Root>/HPF: derivative  followed by a LPF'
                                        */
  30.0,                                /* HPFderivativefollowedbyaLPF_D : '<Root>/HPF: derivative  followed by a LPF'
                                        */
  2.0,                                 /* SignalGenerator_Amplitude : '<Root>/Signal Generator'
                                        */
  0.4,                                 /* SignalGenerator_Frequency : '<Root>/Signal Generator'
                                        */
  40.0,                                /* RateLimiter_RisingLim : '<Root>/Rate Limiter'
                                        */
  -40.0,                               /* RateLimiter_FallingLim : '<Root>/Rate Limiter'
                                        */
  7.2,                                 /* Saturation_UpperSat : '<Root>/Saturation'
                                        */
  -7.2,                                /* Saturation_LowerSat : '<Root>/Saturation'
                                        */

  /*  HILInitialize_CKChannels : '<Root>/HIL Initialize'
   */
  { 0, 1, 2 },
  0,                                   /* HILInitialize_DOWatchdog : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIInitial : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POModes : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POConfiguration : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POAlignment : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPolarity : '<Root>/HIL Initialize'
                                        */

  /*  HILInitialize_AIChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_AOChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_DOChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILInitialize_EIChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },
  4U,                                  /* HILInitialize_EIQuadrature : '<Root>/HIL Initialize'
                                        */

  /*  HILInitialize_POChannels : '<Root>/HIL Initialize'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U },

  /*  HILReadEncoder_Channels : '<Root>/HIL Read Encoder'
   */
  { 0U, 1U },
  0U,                                  /* HILWriteAnalog_Channels : '<Root>/HIL Write Analog'
                                        */
  1U,                                  /* Constant_Value : '<S1>/Constant'
                                        */
  0U,                                  /* SwitchControl_Threshold : '<S1>/SwitchControl'
                                        */
  0,                                   /* HILInitialize_Active : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_CKPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AIPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AIPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_AOTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_AOReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_DOTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOReset : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_EIStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_EIEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POPStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POPEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POStart : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POEnter : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILInitialize_POTerminate : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POExit : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_POReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_OOReset : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOInitial : '<Root>/HIL Initialize'
                                        */
  0,                                   /* HILInitialize_DOFinal : '<Root>/HIL Initialize'
                                        */
  1,                                   /* HILReadEncoder_Active : '<Root>/HIL Read Encoder'
                                        */
  0                                    /* HILWriteAnalog_Active : '<Root>/HIL Write Analog'
                                        */
};
