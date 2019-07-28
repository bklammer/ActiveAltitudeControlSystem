#include "__cf_SIL_Arduino.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "SIL_Arduino_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#ifndef SS_INT64
#define SS_INT64  15
#endif
#ifndef SS_UINT64
#define SS_UINT64  16
#endif
#else
#include "builtin_typeid_types.h"
#include "SIL_Arduino.h"
#include "SIL_Arduino_capi.h"
#include "SIL_Arduino_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"SIL_Arduino/Sum" ) , TARGET_STRING ( "CdA Error" ) , 0 , 0 , 0 , 0 , 0 } , {
1 , 2 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Step Counter" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 2 , 3 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Steps to Angle" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 3 , 0 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Memory" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 2 } , { 4 , 4 , TARGET_STRING (
"SIL_Arduino/Rocket Dynamics/Flap Angle to Drag Coefficient" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 5 , 5 , TARGET_STRING (
"SIL_Arduino/Rocket Dynamics/MATLAB Function" ) , TARGET_STRING (
"Velocities, Forces" ) , 0 , 0 , 1 , 0 , 0 } , { 6 , 5 , TARGET_STRING (
"SIL_Arduino/Rocket Dynamics/MATLAB Function" ) , TARGET_STRING (
"Sensor Data" ) , 1 , 0 , 2 , 0 , 0 } , { 7 , 0 , TARGET_STRING (
"SIL_Arduino/Rocket Dynamics/Constant" ) , TARGET_STRING (
"Initial Conditions" ) , 0 , 0 , 1 , 0 , 3 } , { 8 , 0 , TARGET_STRING (
"SIL_Arduino/Rocket Dynamics/Integrator" ) , TARGET_STRING (
"Positions, Momentums" ) , 0 , 0 , 1 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Abs" ) , TARGET_STRING (
"Magnitude of Control Signal\n(degrees of stepper rotation)" ) , 0 , 0 , 0 ,
0 , 0 } , { 10 , 0 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Step Frequency" ) ,
TARGET_STRING ( "How fast to step" ) , 0 , 0 , 0 , 0 , 4 } , { 11 , 0 ,
TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Multiply1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/GreaterThan1" ) ,
TARGET_STRING ( "Direction Signal" ) , 0 , 1 , 0 , 0 , 2 } , { 13 , 0 ,
TARGET_STRING (
"SIL_Arduino/Motor Controller/Rotary Sensor Fail Safe/Multiply" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 14 , 0 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Rotary Sensor Fail Safe/Subtract" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 15 , 2 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Step Counter/Unit Delay" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 16 , 0 , TARGET_STRING (
"SIL_Arduino/PID Controller/D Gain/Internal Parameters/Derivative Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"SIL_Arduino/PID Controller/Filter/Cont. Filter/Filter" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"SIL_Arduino/PID Controller/Filter/Cont. Filter/SumD" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"SIL_Arduino/PID Controller/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"SIL_Arduino/PID Controller/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"SIL_Arduino/PID Controller/N Gain/Internal Parameters/Filter Coefficient" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"SIL_Arduino/PID Controller/Sum/Sum_PID/Sum" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 23 ,
TARGET_STRING ( "SIL_Arduino/PID Controller" ) , TARGET_STRING ( "P" ) , 0 ,
0 , 0 } , { 24 , TARGET_STRING ( "SIL_Arduino/PID Controller" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 25 , TARGET_STRING (
"SIL_Arduino/PID Controller" ) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 26 ,
TARGET_STRING ( "SIL_Arduino/PID Controller" ) , TARGET_STRING ( "N" ) , 0 ,
0 , 0 } , { 27 , TARGET_STRING ( "SIL_Arduino/PID Controller" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 28 ,
TARGET_STRING ( "SIL_Arduino/PID Controller" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 29 , TARGET_STRING (
"SIL_Arduino/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 30 ,
TARGET_STRING ( "SIL_Arduino/Constant5" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 31 , TARGET_STRING (
 "SIL_Arduino/Motor Controller/Angle of Air Brake Flaps when Fully Open (degrees)"
) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Memory" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING (
"SIL_Arduino/Rocket Dynamics/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 3
, 0 } , { 34 , TARGET_STRING ( "SIL_Arduino/Rocket Dynamics/Constant5" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 36 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Step Size" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Step Frequency" ) ,
TARGET_STRING ( "Amplitude" ) , 0 , 0 , 0 } , { 39 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Step Frequency" ) ,
TARGET_STRING ( "Period" ) , 0 , 0 , 0 } , { 40 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Step Frequency" ) ,
TARGET_STRING ( "PulseWidth" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Motor Signal Converter/Step Frequency" ) ,
TARGET_STRING ( "PhaseDelay" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Rotary Sensor Fail Safe/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 43 , TARGET_STRING (
"SIL_Arduino/Motor Controller/Rotary Sensor Fail Safe/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 44 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Step Counter/Step Count" ) ,
TARGET_STRING ( "InitialOutput" ) , 0 , 0 , 0 } , { 45 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Step Counter/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 46 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Step Counter/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 47 , TARGET_STRING (
"SIL_Arduino/Motor and Gearbox Transfer Function/Step Counter/Unit Delay" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [
] = { { 48 , TARGET_STRING ( "INTAB1" ) , 0 , 4 , 0 } , { 49 , TARGET_STRING
( "INTAB3" ) , 0 , 5 , 0 } , { 50 , TARGET_STRING ( "INTAB4" ) , 0 , 6 , 0 }
, { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . gx0or0kr3s , & rtB . l0euqgxhm0 ,
& rtB . flslv0y4cj , & rtB . iustumvjtp , & rtB . cc1cd5zhlf , & rtB .
oeuf2hmy0o [ 0 ] , & rtB . gvuqr1jt0i [ 0 ] , & rtB . ahkiafeoia [ 0 ] , &
rtB . dffpum05ns [ 0 ] , & rtB . p5nx0ha0gn , & rtB . m1vxg5gqae , & rtB .
pgtzcj3xlg , & rtB . a0thuhlkvf , & rtB . i3wfi0zs3s , & rtB . gq1bt1ao5w , &
rtB . l0euqgxhm0 , & rtB . lwp5elo2wh , & rtB . n5ewebaudy , & rtB .
k0zs1ouug5 , & rtB . d22mgk2nk4 , & rtB . ej1lofn5r4 , & rtB . fziqurelun , &
rtB . ec3lzwjpul , & rtP . PIDController_P , & rtP . PIDController_I , & rtP
. PIDController_D , & rtP . PIDController_N , & rtP .
PIDController_InitialConditionForIntegrator , & rtP .
PIDController_InitialConditionForFilter , & rtP . Constant1_Value_mq0yqq5e0x
, & rtP . Constant5_Value , & rtP .
AngleofAirBrakeFlapswhenFullyOpendegrees_Value , & rtP .
Memory_InitialCondition , & rtP . Constant_Value_e5cors3m1f [ 0 ] , & rtP .
Constant5_Value_kpkyenjwdq , & rtP . Constant_Value_knfpzjs1ar , & rtP .
Constant1_Value_oqyl4nphju , & rtP . StepSize_Value , & rtP .
StepFrequency_Amp , & rtP . StepFrequency_Period , & rtP . StepFrequency_Duty
, & rtP . StepFrequency_PhaseDelay , & rtP . Constant_Value_ldchjia2i4 , &
rtP . Constant1_Value_jsld3gr050 , & rtP . StepCount_Y0 , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . UnitDelay_InitialCondition
, & rtP . INTAB1 [ 0 ] , & rtP . INTAB3 [ 0 ] , & rtP . INTAB4 [ 0 ] , } ;
static int32_T * rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_VECTOR , 6 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } , {
rtwCAPI_MATRIX_COL_MAJOR , 12 , 2 , 0 } } ; static const uint_T
rtDimensionArray [ ] = { 1 , 1 , 13 , 1 , 4 , 1 , 1 , 13 , 318 , 11 , 1 , 2 ,
111 , 6 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 1.0 , - 2.0
} ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } , { ( NULL ) , ( NULL ) ,
- 1 , 0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * )
& rtcapiStoredFloats [ 1 ] , 1 , 0 } , { ( NULL ) , ( NULL ) , 3 , 0 } , { (
const void * ) & rtcapiStoredFloats [ 2 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 2 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 23 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 25 , rtModelParameters , 3 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2887184815U , 2526773862U , 209535582U ,
2430258776U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
SIL_Arduino_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void SIL_Arduino_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void SIL_Arduino_host_InitializeDataMapInfo ( SIL_Arduino_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
