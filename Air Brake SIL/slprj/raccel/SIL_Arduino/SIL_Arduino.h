#include "__cf_SIL_Arduino.h"
#ifndef RTW_HEADER_SIL_Arduino_h_
#define RTW_HEADER_SIL_Arduino_h_
#include <stddef.h>
#include <float.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef SIL_Arduino_COMMON_INCLUDES_
#define SIL_Arduino_COMMON_INCLUDES_
#include <stdlib.h>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "SIL_Arduino_types.h"
#include "multiword_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_zcfcn.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#define MODEL_NAME SIL_Arduino
#define NSAMPLE_TIMES (4) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (23) 
#define NUM_ZC_EVENTS (1) 
#ifndef NCSTATES
#define NCSTATES (15)   
#elif NCSTATES != 15
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T ahkiafeoia [ 13 ] ; real_T dffpum05ns [ 13 ] ; real_T
iustumvjtp ; real_T ej1lofn5r4 ; real_T n5ewebaudy ; real_T gq1bt1ao5w ;
real_T m1vxg5gqae ; real_T gx0or0kr3s ; real_T lwp5elo2wh ; real_T k0zs1ouug5
; real_T fziqurelun ; real_T ec3lzwjpul ; real_T pgtzcj3xlg ; real_T
p5nx0ha0gn ; real_T i3wfi0zs3s ; real_T d22mgk2nk4 ; real_T oeuf2hmy0o [ 13 ]
; real_T gvuqr1jt0i [ 4 ] ; real_T cc1cd5zhlf ; real_T flslv0y4cj ; real_T
l0euqgxhm0 ; boolean_T a0thuhlkvf ; } B ; typedef struct { real_T nu2anqwsoh
; real_T bnnyzhf4hd ; real_T moxilmktys ; int64_T kxv5tb5r11 ; struct { void
* LoggedData ; } lyitfitoch ; struct { void * AQHandles ; void * SlioLTF ; }
jcuwij5dpk ; struct { void * AQHandles ; void * SlioLTF ; } hrqoqhtymu ;
struct { void * AQHandles ; void * SlioLTF ; } fa1rhasmp4 ; struct { void *
LoggedData [ 3 ] ; } iq00tkmc3j ; struct { void * LoggedData ; } egyz1gl0dl ;
struct { void * LoggedData [ 2 ] ; } caeszugdbc ; struct { void * AQHandles ;
void * SlioLTF ; } k53fkqd2g2 ; int32_T ig2uo5piti ; int32_T av0mpygxcu ;
int_T ix0gnlc2nc ; int_T hef1fu14qj ; int8_T kijlfweplt ; boolean_T
fwrbx3e2f1 ; boolean_T gld15yigj5 ; boolean_T em2vdfypg1 ; } DW ; typedef
struct { real_T gzm0a20aj2 [ 13 ] ; real_T nkhfitlmge ; real_T iw20ly4bl4 ; }
X ; typedef struct { real_T gzm0a20aj2 [ 13 ] ; real_T nkhfitlmge ; real_T
iw20ly4bl4 ; } XDot ; typedef struct { boolean_T gzm0a20aj2 [ 13 ] ;
boolean_T nkhfitlmge ; boolean_T iw20ly4bl4 ; } XDis ; typedef struct {
real_T gzm0a20aj2 [ 13 ] ; real_T nkhfitlmge ; real_T iw20ly4bl4 ; }
CStateAbsTol ; typedef struct { real_T p4lmzczvon ; real_T okc25qnabt ;
real_T akvyvcyj0o ; real_T mpq4npk020 ; real_T oggqtnkwgz ; } ZCV ; typedef
struct { ZCSigState pysmillkpz ; } PrevZCX ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T INTAB1 [
3498 ] ; real_T INTAB3 [ 2 ] ; real_T INTAB4 [ 666 ] ; real_T PIDController_D
; real_T PIDController_I ; real_T PIDController_InitialConditionForFilter ;
real_T PIDController_InitialConditionForIntegrator ; real_T PIDController_N ;
real_T PIDController_P ; real_T StepCount_Y0 ; real_T Constant1_Value ;
real_T Constant_Value ; real_T UnitDelay_InitialCondition ; real_T
Constant1_Value_mq0yqq5e0x ; real_T Constant5_Value ; real_T
Constant_Value_e5cors3m1f [ 13 ] ; real_T Memory_InitialCondition ; real_T
Constant1_Value_oqyl4nphju ; real_T Constant_Value_knfpzjs1ar ; real_T
AngleofAirBrakeFlapswhenFullyOpendegrees_Value ; real_T
Constant_Value_ldchjia2i4 ; real_T Constant1_Value_jsld3gr050 ; real_T
StepSize_Value ; real_T StepFrequency_Amp ; real_T StepFrequency_Period ;
real_T StepFrequency_Duty ; real_T StepFrequency_PhaseDelay ; real_T
Constant5_Value_kpkyenjwdq ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern PrevZCX rtPrevZCX ; extern P rtP ; extern const
rtwCAPI_ModelMappingStaticInfo * SIL_Arduino_GetCAPIStaticMap ( void ) ;
extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
