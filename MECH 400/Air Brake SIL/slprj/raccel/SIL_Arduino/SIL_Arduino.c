#include "__cf_SIL_Arduino.h"
#include "rt_logging_mmi.h"
#include "SIL_Arduino_capi.h"
#include <math.h>
#include "SIL_Arduino.h"
#include "SIL_Arduino_private.h"
#include "SIL_Arduino_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 3 , & stopRequested ) ; }
rtExtModeShutdown ( 3 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 4 ; const char_T
* gbl_raccel_Version = "9.0 (R2018b) 24-May-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\SIL_Arduino\\SIL_Arduino_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 , 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; PrevZCX rtPrevZCX ; static SimStruct model_S ;
SimStruct * const rtS = & model_S ; static real_T cfg3dsmpkp ( const real_T
varargin_1 [ 318 ] , const real_T varargin_2 [ 318 ] , real_T varargin_3 ) ;
static real_T cfg3dsmpkpi ( const real_T varargin_1 [ 111 ] , const real_T
varargin_2 [ 111 ] , real_T varargin_3 ) ; static void nlwm4xj33c ( const
real_T b [ 4 ] , real_T a [ 4 ] ) ; static void b5npvcelre ( const real_T qt
[ 4 ] , real_T Rt [ 9 ] ) ; static void nhxyxo3xco ( const real_T A [ 9 ] ,
const real_T B_p [ 3 ] , real_T Y [ 3 ] ) ; static void ca1i44t24n ( const
real_T a [ 3 ] , const real_T b [ 3 ] , real_T c [ 3 ] ) ; static real_T
oqgpsrqqr4 ( const real_T b [ 3 ] ) ; static void nlwm4xj33c4 ( const real_T
b [ 3 ] , real_T a [ 3 ] ) ; static real_T d2wn0mmixj ( const real_T a [ 3 ]
, const real_T b [ 3 ] ) ; static real_T cfg3dsmpkp ( const real_T varargin_1
[ 318 ] , const real_T varargin_2 [ 318 ] , real_T varargin_3 ) { real_T Vq ;
real_T y [ 318 ] ; real_T x [ 318 ] ; real_T xtmp ; int32_T low_i ; int32_T
low_ip1 ; int32_T high_i ; int32_T mid_i ; int32_T exitg1 ; memcpy ( & y [ 0
] , & varargin_2 [ 0 ] , 318U * sizeof ( real_T ) ) ; memcpy ( & x [ 0 ] , &
varargin_1 [ 0 ] , 318U * sizeof ( real_T ) ) ; low_i = 0 ; do { exitg1 = 0 ;
if ( low_i < 318 ) { if ( muDoubleScalarIsNaN ( varargin_1 [ low_i ] ) ) {
exitg1 = 1 ; } else { low_i ++ ; } } else { if ( varargin_1 [ 1 ] <
varargin_1 [ 0 ] ) { for ( low_i = 0 ; low_i < 159 ; low_i ++ ) { xtmp = x [
low_i ] ; x [ low_i ] = x [ 317 - low_i ] ; x [ 317 - low_i ] = xtmp ; } for
( low_i = 0 ; low_i < 159 ; low_i ++ ) { xtmp = y [ low_i ] ; y [ low_i ] = y
[ 317 - low_i ] ; y [ 317 - low_i ] = xtmp ; } } Vq = ( rtNaN ) ; if ( ( !
muDoubleScalarIsNaN ( varargin_3 ) ) && ( ! ( varargin_3 > x [ 317 ] ) ) && (
! ( varargin_3 < x [ 0 ] ) ) ) { low_i = 1 ; low_ip1 = 2 ; high_i = 318 ;
while ( high_i > low_ip1 ) { mid_i = ( low_i + high_i ) >> 1 ; if (
varargin_3 >= x [ mid_i - 1 ] ) { low_i = mid_i ; low_ip1 = mid_i + 1 ; }
else { high_i = mid_i ; } } xtmp = ( varargin_3 - x [ low_i - 1 ] ) / ( x [
low_i ] - x [ low_i - 1 ] ) ; if ( xtmp == 0.0 ) { Vq = y [ low_i - 1 ] ; }
else if ( xtmp == 1.0 ) { Vq = y [ low_i ] ; } else if ( y [ low_i - 1 ] == y
[ low_i ] ) { Vq = y [ low_i - 1 ] ; } else { Vq = ( 1.0 - xtmp ) * y [ low_i
- 1 ] + xtmp * y [ low_i ] ; } } exitg1 = 1 ; } } while ( exitg1 == 0 ) ;
return Vq ; } static real_T cfg3dsmpkpi ( const real_T varargin_1 [ 111 ] ,
const real_T varargin_2 [ 111 ] , real_T varargin_3 ) { real_T Vq ; real_T y
[ 111 ] ; real_T x [ 111 ] ; real_T xtmp ; int32_T low_i ; int32_T low_ip1 ;
int32_T high_i ; int32_T mid_i ; int32_T exitg1 ; memcpy ( & y [ 0 ] , &
varargin_2 [ 0 ] , 111U * sizeof ( real_T ) ) ; memcpy ( & x [ 0 ] , &
varargin_1 [ 0 ] , 111U * sizeof ( real_T ) ) ; low_i = 0 ; do { exitg1 = 0 ;
if ( low_i < 111 ) { if ( muDoubleScalarIsNaN ( varargin_1 [ low_i ] ) ) {
exitg1 = 1 ; } else { low_i ++ ; } } else { if ( varargin_1 [ 1 ] <
varargin_1 [ 0 ] ) { for ( low_i = 0 ; low_i < 55 ; low_i ++ ) { xtmp = x [
low_i ] ; x [ low_i ] = x [ 110 - low_i ] ; x [ 110 - low_i ] = xtmp ; } for
( low_i = 0 ; low_i < 55 ; low_i ++ ) { xtmp = y [ low_i ] ; y [ low_i ] = y
[ 110 - low_i ] ; y [ 110 - low_i ] = xtmp ; } } Vq = ( rtNaN ) ; if ( ( !
muDoubleScalarIsNaN ( varargin_3 ) ) && ( ! ( varargin_3 > x [ 110 ] ) ) && (
! ( varargin_3 < x [ 0 ] ) ) ) { low_i = 1 ; low_ip1 = 2 ; high_i = 111 ;
while ( high_i > low_ip1 ) { mid_i = ( low_i + high_i ) >> 1 ; if (
varargin_3 >= x [ mid_i - 1 ] ) { low_i = mid_i ; low_ip1 = mid_i + 1 ; }
else { high_i = mid_i ; } } xtmp = ( varargin_3 - x [ low_i - 1 ] ) / ( x [
low_i ] - x [ low_i - 1 ] ) ; if ( xtmp == 0.0 ) { Vq = y [ low_i - 1 ] ; }
else if ( xtmp == 1.0 ) { Vq = y [ low_i ] ; } else if ( y [ low_i - 1 ] == y
[ low_i ] ) { Vq = y [ low_i - 1 ] ; } else { Vq = ( 1.0 - xtmp ) * y [ low_i
- 1 ] + xtmp * y [ low_i ] ; } } exitg1 = 1 ; } } while ( exitg1 == 0 ) ;
return Vq ; } static void nlwm4xj33c ( const real_T b [ 4 ] , real_T a [ 4 ]
) { real_T sb ; sb = muDoubleScalarSqrt ( ( ( b [ 0 ] * b [ 0 ] + b [ 1 ] * b
[ 1 ] ) + b [ 2 ] * b [ 2 ] ) + b [ 3 ] * b [ 3 ] ) ; if ( sb == 0.0 ) { a [
0 ] = 0.0 ; a [ 1 ] = 0.0 ; a [ 2 ] = 0.0 ; a [ 3 ] = 0.0 ; } else { a [ 0 ]
= b [ 0 ] / sb ; a [ 1 ] = b [ 1 ] / sb ; a [ 2 ] = b [ 2 ] / sb ; a [ 3 ] =
b [ 3 ] / sb ; } } static void b5npvcelre ( const real_T qt [ 4 ] , real_T Rt
[ 9 ] ) { Rt [ 0 ] = ( 1.0 - qt [ 2 ] * qt [ 2 ] * 2.0 ) - qt [ 3 ] * qt [ 3
] * 2.0 ; Rt [ 3 ] = 2.0 * qt [ 1 ] * qt [ 2 ] - 2.0 * qt [ 0 ] * qt [ 3 ] ;
Rt [ 6 ] = 2.0 * qt [ 1 ] * qt [ 3 ] + 2.0 * qt [ 0 ] * qt [ 2 ] ; Rt [ 1 ] =
2.0 * qt [ 1 ] * qt [ 2 ] + 2.0 * qt [ 0 ] * qt [ 3 ] ; Rt [ 4 ] = ( 1.0 - qt
[ 1 ] * qt [ 1 ] * 2.0 ) - qt [ 3 ] * qt [ 3 ] * 2.0 ; Rt [ 7 ] = 2.0 * qt [
2 ] * qt [ 3 ] - 2.0 * qt [ 0 ] * qt [ 1 ] ; Rt [ 2 ] = 2.0 * qt [ 1 ] * qt [
3 ] - 2.0 * qt [ 0 ] * qt [ 2 ] ; Rt [ 5 ] = 2.0 * qt [ 2 ] * qt [ 3 ] + 2.0
* qt [ 0 ] * qt [ 1 ] ; Rt [ 8 ] = ( 1.0 - qt [ 1 ] * qt [ 1 ] * 2.0 ) - qt [
2 ] * qt [ 2 ] * 2.0 ; } static void nhxyxo3xco ( const real_T A [ 9 ] ,
const real_T B_p [ 3 ] , real_T Y [ 3 ] ) { real_T b_A [ 9 ] ; int32_T r1 ;
int32_T r2 ; int32_T r3 ; real_T maxval ; real_T a21 ; int32_T rtemp ; memcpy
( & b_A [ 0 ] , & A [ 0 ] , 9U * sizeof ( real_T ) ) ; r1 = 0 ; r2 = 1 ; r3 =
2 ; maxval = muDoubleScalarAbs ( A [ 0 ] ) ; a21 = muDoubleScalarAbs ( A [ 1
] ) ; if ( a21 > maxval ) { maxval = a21 ; r1 = 1 ; r2 = 0 ; } if (
muDoubleScalarAbs ( A [ 2 ] ) > maxval ) { r1 = 2 ; r2 = 1 ; r3 = 0 ; } b_A [
r2 ] = A [ r2 ] / A [ r1 ] ; b_A [ r3 ] /= b_A [ r1 ] ; b_A [ 3 + r2 ] -= b_A
[ 3 + r1 ] * b_A [ r2 ] ; b_A [ 3 + r3 ] -= b_A [ 3 + r1 ] * b_A [ r3 ] ; b_A
[ 6 + r2 ] -= b_A [ 6 + r1 ] * b_A [ r2 ] ; b_A [ 6 + r3 ] -= b_A [ 6 + r1 ]
* b_A [ r3 ] ; if ( muDoubleScalarAbs ( b_A [ 3 + r3 ] ) > muDoubleScalarAbs
( b_A [ 3 + r2 ] ) ) { rtemp = r2 ; r2 = r3 ; r3 = rtemp ; } b_A [ 3 + r3 ]
/= b_A [ 3 + r2 ] ; b_A [ 6 + r3 ] -= b_A [ 3 + r3 ] * b_A [ 6 + r2 ] ; Y [ 1
] = B_p [ r2 ] - B_p [ r1 ] * b_A [ r2 ] ; Y [ 2 ] = ( B_p [ r3 ] - B_p [ r1
] * b_A [ r3 ] ) - b_A [ 3 + r3 ] * Y [ 1 ] ; Y [ 2 ] /= b_A [ 6 + r3 ] ; Y [
0 ] = B_p [ r1 ] - b_A [ 6 + r1 ] * Y [ 2 ] ; Y [ 1 ] -= b_A [ 6 + r2 ] * Y [
2 ] ; Y [ 1 ] /= b_A [ 3 + r2 ] ; Y [ 0 ] -= b_A [ 3 + r1 ] * Y [ 1 ] ; Y [ 0
] /= b_A [ r1 ] ; } static void ca1i44t24n ( const real_T a [ 3 ] , const
real_T b [ 3 ] , real_T c [ 3 ] ) { c [ 0 ] = a [ 1 ] * b [ 2 ] - a [ 2 ] * b
[ 1 ] ; c [ 1 ] = a [ 2 ] * b [ 0 ] - a [ 0 ] * b [ 2 ] ; c [ 2 ] = a [ 0 ] *
b [ 1 ] - a [ 1 ] * b [ 0 ] ; } static real_T oqgpsrqqr4 ( const real_T b [ 3
] ) { return muDoubleScalarSqrt ( ( b [ 0 ] * b [ 0 ] + b [ 1 ] * b [ 1 ] ) +
b [ 2 ] * b [ 2 ] ) ; } static void nlwm4xj33c4 ( const real_T b [ 3 ] ,
real_T a [ 3 ] ) { real_T bmag ; bmag = oqgpsrqqr4 ( b ) ; if ( bmag == 0.0 )
{ a [ 0 ] = 0.0 ; a [ 1 ] = 0.0 ; a [ 2 ] = 0.0 ; } else { a [ 0 ] = b [ 0 ]
/ bmag ; a [ 1 ] = b [ 1 ] / bmag ; a [ 2 ] = b [ 2 ] / bmag ; } } static
real_T d2wn0mmixj ( const real_T a [ 3 ] , const real_T b [ 3 ] ) { return (
a [ 0 ] * b [ 0 ] + a [ 1 ] * b [ 1 ] ) + a [ 2 ] * b [ 2 ] ; } void
MdlInitialize ( void ) { if ( ssIsFirstInitCond ( rtS ) ) { rtX . gzm0a20aj2
[ 0 ] = 0.0 ; rtX . gzm0a20aj2 [ 1 ] = 0.0 ; rtX . gzm0a20aj2 [ 2 ] = 0.0 ;
rtX . gzm0a20aj2 [ 3 ] = 0.998629534754574 ; rtX . gzm0a20aj2 [ 4 ] = -
0.0523359562429438 ; rtX . gzm0a20aj2 [ 5 ] = 1.92279183879711E-17 ; rtX .
gzm0a20aj2 [ 6 ] = 0.0 ; rtX . gzm0a20aj2 [ 7 ] = 0.0 ; rtX . gzm0a20aj2 [ 8
] = 0.0 ; rtX . gzm0a20aj2 [ 9 ] = 0.0 ; rtX . gzm0a20aj2 [ 10 ] = 0.0 ; rtX
. gzm0a20aj2 [ 11 ] = 0.0 ; rtX . gzm0a20aj2 [ 12 ] = 0.0 ; } rtDW .
ix0gnlc2nc = 1 ; rtDW . bnnyzhf4hd = rtP . Memory_InitialCondition ; rtX .
nkhfitlmge = rtP . PIDController_InitialConditionForIntegrator ; rtX .
iw20ly4bl4 = rtP . PIDController_InitialConditionForFilter ; rtDW .
nu2anqwsoh = rtP . UnitDelay_InitialCondition ; rtB . l0euqgxhm0 = rtP .
StepCount_Y0 ; } void MdlEnable ( void ) { rtDW . ig2uo5piti = 1 ;
_ssSetSampleHit ( rtS , 2 , 1 ) ; _ssSetTaskTime ( rtS , 2 , ssGetT ( rtS ) )
; _ssSetVarNextHitTime ( rtS , 0 , ssGetT ( rtS ) ) ; ; } void MdlStart (
void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ; void * r2
= ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int
maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ;
bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } { void * slioCatalogue =
rt_slioCatalogue ( ) ? rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) :
sdiGetSlioCatalogue ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if (
! slioCatalogue || ! rtwDisableStreamingToRepository ( slioCatalogue ) ) { {
sdiSignalSourceInfoU srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars (
"Actual CdA" ) ; sdiLabelU origSigName = sdiGetLabelFromChars ( "Actual CdA"
) ; sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "SIL_Arduino/Controller/Demux" ) ; sdiLabelU blockSID
= sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( ""
) ; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Actual CdA"
) ; sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . jcuwij5dpk . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "4dd06c1a-9c0f-4756-8a13-9fcea8ab935c" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. jcuwij5dpk . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . jcuwij5dpk
. AQHandles , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime
( rtDW . jcuwij5dpk . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . jcuwij5dpk . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . jcuwij5dpk . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } rtDW . jcuwij5dpk . SlioLTF = ( NULL ) ; {
void * treeVector = ( NULL ) ; void * accessor = ( NULL ) ; const void *
signalDescriptor = ( NULL ) ; void * loggingInterval = ( NULL ) ; char *
datasetName = "tmp_raccel_logsout" ; if ( slioCatalogue && rtwIsLoggingToFile
( slioCatalogue ) ) { treeVector = rtwGetTreeVector ( ) ; { int_T
sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode ( 0 , "Actual CdA" , "linear" , 0
, ( unsigned int * ) sigDimsArray , 1 , "double" , "" , "Continuous" , 0.0 ,
ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "Actual CdA" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Controller/Demux" , 1 , 0 , slioCatalogue , ( NULL ) , 0 , (
NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) { sdiSlioIsLoggingSignal (
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Controller/Demux" , 1 , "Actual CdA" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . jcuwij5dpk . SlioLTF = accessor ;
} } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Vertical Velocity" )
; sdiLabelU origSigName = sdiGetLabelFromChars ( "Vertical Velocity" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "SIL_Arduino/Controller/Demux" ) ; sdiLabelU blockSID
= sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( ""
) ; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"Vertical Velocity" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 1 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. hrqoqhtymu . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"63a01f7a-8dea-4410-9136-8aacafc8361c" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . hrqoqhtymu . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . hrqoqhtymu . AQHandles , "Continuous"
, 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . hrqoqhtymu .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . hrqoqhtymu . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . hrqoqhtymu . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } rtDW .
hrqoqhtymu . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "Vertical Velocity" , "linear" , 0 , ( unsigned int * ) sigDimsArray , 1
, "double" , "" , "Continuous" , 0.0 , ssGetTFinal ( rtS ) , treeVector ) ; }
signalDescriptor = rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 ,
"Vertical Velocity" , "" , rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Controller/Demux" , 2 , 0 , slioCatalogue , ( NULL ) , 0 , (
NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) { sdiSlioIsLoggingSignal (
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Controller/Demux" , 2 , "Vertical Velocity" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . hrqoqhtymu . SlioLTF = accessor ;
} } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "Altitude" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "Altitude" ) ; sdiLabelU
propName = sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath =
sdiGetLabelFromChars ( "SIL_Arduino/Controller/Demux" ) ; sdiLabelU blockSID
= sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( ""
) ; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars ( "Altitude" )
; sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 2 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . fa1rhasmp4 . AQHandles =
sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "3a1a4f13-7586-4974-986b-43fbdc055fe0" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW
. fa1rhasmp4 . AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . fa1rhasmp4
. AQHandles , "Continuous" , 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime
( rtDW . fa1rhasmp4 . AQHandles , ssGetTaskTime ( rtS , 1 ) ) ;
sdiAsyncRepoSetSignalExportSettings ( rtDW . fa1rhasmp4 . AQHandles , 1 , 0 )
; sdiAsyncRepoSetSignalExportName ( rtDW . fa1rhasmp4 . AQHandles ,
loggedName , origSigName , propName ) ; } sdiFreeLabel ( sigName ) ;
sdiFreeLabel ( loggedName ) ; sdiFreeLabel ( origSigName ) ; sdiFreeLabel (
propName ) ; sdiFreeLabel ( blockPath ) ; sdiFreeLabel ( blockSID ) ;
sdiFreeLabel ( subPath ) ; } } } rtDW . fa1rhasmp4 . SlioLTF = ( NULL ) ; {
void * treeVector = ( NULL ) ; void * accessor = ( NULL ) ; const void *
signalDescriptor = ( NULL ) ; void * loggingInterval = ( NULL ) ; char *
datasetName = "tmp_raccel_logsout" ; if ( slioCatalogue && rtwIsLoggingToFile
( slioCatalogue ) ) { treeVector = rtwGetTreeVector ( ) ; { int_T
sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode ( 0 , "Altitude" , "linear" , 0 ,
( unsigned int * ) sigDimsArray , 1 , "double" , "" , "Continuous" , 0.0 ,
ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor =
rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "Altitude" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Controller/Demux" , 3 , 0 , slioCatalogue , ( NULL ) , 0 , (
NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) ) { sdiSlioIsLoggingSignal (
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Controller/Demux" , 3 , "Altitude" ) ; } if ( rtwLoggingOverride
( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS ( rtS ) -> mdlInfo
-> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval ( ssGetRootSS (
rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . fa1rhasmp4 . SlioLTF = accessor ;
} } } } { void * slioCatalogue = rt_slioCatalogue ( ) ?
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) : sdiGetSlioCatalogue (
rt_dataMapInfo . mmi . InstanceMap . fullPath ) ; if ( ! slioCatalogue || !
rtwDisableStreamingToRepository ( slioCatalogue ) ) { { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "" ) ; sdiLabelU
origSigName = sdiGetLabelFromChars ( "" ) ; sdiLabelU propName =
sdiGetLabelFromChars ( "" ) ; sdiLabelU blockPath = sdiGetLabelFromChars (
"SIL_Arduino/Motor and Gearbox Transfer Function/Memory" ) ; sdiLabelU
blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont = SAMPLE_TIME_DISCRETE
; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims .
dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ; srcInfo .
fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. k53fkqd2g2 . AQHandles = sdiAsyncRepoCreateAsyncioQueue ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b98969e7-5443-4525-86ce-e59840c48069" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; if ( rtDW . k53fkqd2g2 . AQHandles )
{ sdiSetSignalSampleTimeString ( rtDW . k53fkqd2g2 . AQHandles , "Continuous"
, 0.0 , ssGetTFinal ( rtS ) ) ; sdiSetRunStartTime ( rtDW . k53fkqd2g2 .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . k53fkqd2g2 . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . k53fkqd2g2 . AQHandles , loggedName , origSigName , propName ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } } rtDW .
k53fkqd2g2 . SlioLTF = ( NULL ) ; { void * treeVector = ( NULL ) ; void *
accessor = ( NULL ) ; const void * signalDescriptor = ( NULL ) ; void *
loggingInterval = ( NULL ) ; char * datasetName = "tmp_raccel_logsout" ; if (
slioCatalogue && rtwIsLoggingToFile ( slioCatalogue ) ) { treeVector =
rtwGetTreeVector ( ) ; { int_T sigDimsArray [ 1 ] = { 1 } ; rtwAddLeafNode (
0 , "" , "zoh" , 0 , ( unsigned int * ) sigDimsArray , 1 , "double" , "" ,
"Continuous" , 0.0 , ssGetTFinal ( rtS ) , treeVector ) ; } signalDescriptor
= rtwGetSignalDescriptor ( treeVector , 1 , 1 , 0 , 1 , "" , "" ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Motor and Gearbox Transfer Function/Memory" , 1 , 0 ,
slioCatalogue , ( NULL ) , 0 , ( NULL ) , 0 ) ; if ( ! rt_slioCatalogue ( ) )
{ sdiSlioIsLoggingSignal ( rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"SIL_Arduino/Motor and Gearbox Transfer Function/Memory" , 1 , "" ) ; } if (
rtwLoggingOverride ( signalDescriptor , slioCatalogue ) ) { if ( ssGetRootSS
( rtS ) -> mdlInfo -> rtwLogInfo ) { loggingInterval = rtliGetLoggingInterval
( ssGetRootSS ( rtS ) -> mdlInfo -> rtwLogInfo ) ; } else { loggingInterval =
sdiGetLoggingIntervals ( rt_dataMapInfo . mmi . InstanceMap . fullPath ) ;
datasetName = "" ; } accessor = rtwGetAccessor ( signalDescriptor ,
loggingInterval ) ; rtwAddR2Client ( accessor , signalDescriptor ,
slioCatalogue , datasetName , 1 ) ; rtDW . k53fkqd2g2 . SlioLTF = accessor ;
} } } } memcpy ( & rtB . ahkiafeoia [ 0 ] , & rtP . Constant_Value_e5cors3m1f
[ 0 ] , 13U * sizeof ( real_T ) ) ; MdlInitialize ( ) ; MdlEnable ( ) ; }
void MdlOutputs ( int_T tid ) { real_T xt [ 3 ] ; real_T qt [ 4 ] ; real_T Ti
; real_T Mi ; real_T Ixxi ; real_T Iyyi ; real_T Izzi ; real_T Ixyi ; real_T
Ixzi ; real_T Iyzi ; real_T Xcmi ; real_T Wxi ; real_T Wyi ; real_T Wzi ;
real_T temp ; real_T Wt [ 3 ] ; real_T vt [ 3 ] ; real_T Rt [ 9 ] ; real_T RA
[ 3 ] ; real_T omegat [ 3 ] ; real_T Vcptnorm [ 3 ] ; static const int8_T b [
3 ] = { 0 , 0 , 1 } ; boolean_T aye5salj4v ; boolean_T f4aaprvzvh ; uint32_T
numCycles ; boolean_T cehmom0v5t ; ZCEventType zcEvent ; real_T mshle03l0j ;
int32_T i ; real_T Rt_p [ 9 ] ; real_T tmp [ 3 ] ; real_T tmp_p [ 4 ] ;
real_T Ixxi_p [ 9 ] ; real_T Rt_e [ 9 ] ; boolean_T tmp_e ; int32_T i_p ;
real_T Ut_idx_0 ; real_T Ut_idx_1 ; real_T Ut_idx_2 ; srClearBC ( rtDW .
kijlfweplt ) ; for ( i = 0 ; i < 13 ; i ++ ) { if ( rtDW . ix0gnlc2nc != 0 )
{ rtX . gzm0a20aj2 [ i ] = rtB . ahkiafeoia [ i ] ; } rtB . dffpum05ns [ i ]
= rtX . gzm0a20aj2 [ i ] ; } mshle03l0j = ssGetT ( rtS ) ; if ( ssIsSampleHit
( rtS , 1 , 0 ) ) { rtB . iustumvjtp = rtDW . bnnyzhf4hd ; rtB . cc1cd5zhlf =
( ( rtB . iustumvjtp * rtB . iustumvjtp * - 3.953E-7 + 8.737E-5 * rtB .
iustumvjtp ) + 4.547E-5 ) * 1.1 / 0.010751315458748 + 0.4 ; } xt [ 0 ] = rtB
. dffpum05ns [ 0 ] ; xt [ 1 ] = rtB . dffpum05ns [ 1 ] ; xt [ 2 ] = rtB .
dffpum05ns [ 2 ] ; if ( mshle03l0j <= rtP . INTAB1 [ 0 ] ) { Ti = rtP .
INTAB1 [ 318 ] ; Mi = rtP . INTAB1 [ 636 ] ; Ixxi = rtP . INTAB1 [ 954 ] ;
Iyyi = rtP . INTAB1 [ 1272 ] ; Izzi = rtP . INTAB1 [ 1590 ] ; Ixyi = rtP .
INTAB1 [ 1908 ] ; Ixzi = rtP . INTAB1 [ 2226 ] ; Iyzi = rtP . INTAB1 [ 2544 ]
; Xcmi = rtP . INTAB1 [ 2862 ] ; mshle03l0j = rtP . INTAB1 [ 3180 ] ; } else
if ( ( mshle03l0j < rtP . INTAB1 [ 317 ] ) && ( mshle03l0j >= rtP . INTAB1 [
0 ] ) ) { Ti = cfg3dsmpkp ( & rtP . INTAB1 [ 0 ] , & rtP . INTAB1 [ 318 ] ,
mshle03l0j ) ; Mi = cfg3dsmpkp ( & rtP . INTAB1 [ 0 ] , & rtP . INTAB1 [ 636
] , mshle03l0j ) ; Ixxi = cfg3dsmpkp ( & rtP . INTAB1 [ 0 ] , & rtP . INTAB1
[ 954 ] , mshle03l0j ) ; Iyyi = cfg3dsmpkp ( & rtP . INTAB1 [ 0 ] , & rtP .
INTAB1 [ 1272 ] , mshle03l0j ) ; Izzi = cfg3dsmpkp ( & rtP . INTAB1 [ 0 ] , &
rtP . INTAB1 [ 1590 ] , mshle03l0j ) ; Ixyi = cfg3dsmpkp ( & rtP . INTAB1 [ 0
] , & rtP . INTAB1 [ 1908 ] , mshle03l0j ) ; Ixzi = cfg3dsmpkp ( & rtP .
INTAB1 [ 0 ] , & rtP . INTAB1 [ 2226 ] , mshle03l0j ) ; Iyzi = cfg3dsmpkp ( &
rtP . INTAB1 [ 0 ] , & rtP . INTAB1 [ 2544 ] , mshle03l0j ) ; Xcmi =
cfg3dsmpkp ( & rtP . INTAB1 [ 0 ] , & rtP . INTAB1 [ 2862 ] , mshle03l0j ) ;
mshle03l0j = cfg3dsmpkp ( & rtP . INTAB1 [ 0 ] , & rtP . INTAB1 [ 3180 ] ,
mshle03l0j ) ; } else { Ti = rtP . INTAB1 [ 635 ] ; Mi = rtP . INTAB1 [ 953 ]
; Ixxi = rtP . INTAB1 [ 1271 ] ; Iyyi = rtP . INTAB1 [ 1589 ] ; Izzi = rtP .
INTAB1 [ 1907 ] ; Ixyi = rtP . INTAB1 [ 2225 ] ; Ixzi = rtP . INTAB1 [ 2543 ]
; Iyzi = rtP . INTAB1 [ 2861 ] ; Xcmi = rtP . INTAB1 [ 3179 ] ; mshle03l0j =
rtP . INTAB1 [ 3497 ] ; } if ( ( rtB . dffpum05ns [ 2 ] < rtP . INTAB4 [ 110
] ) && ( rtB . dffpum05ns [ 2 ] >= rtP . INTAB4 [ 0 ] ) ) { Wxi = cfg3dsmpkpi
( & rtP . INTAB4 [ 0 ] , & rtP . INTAB4 [ 111 ] , rtB . dffpum05ns [ 2 ] ) ;
Wyi = cfg3dsmpkpi ( & rtP . INTAB4 [ 0 ] , & rtP . INTAB4 [ 222 ] , rtB .
dffpum05ns [ 2 ] ) ; Wzi = cfg3dsmpkpi ( & rtP . INTAB4 [ 0 ] , & rtP .
INTAB4 [ 333 ] , rtB . dffpum05ns [ 2 ] ) ; temp = cfg3dsmpkpi ( & rtP .
INTAB4 [ 0 ] , & rtP . INTAB4 [ 444 ] , rtB . dffpum05ns [ 2 ] ) ; } else {
Wxi = rtP . INTAB4 [ 221 ] ; Wyi = rtP . INTAB4 [ 332 ] ; Wzi = rtP . INTAB4
[ 443 ] ; temp = ( 0.00299 * rtB . dffpum05ns [ 2 ] + - 131.21 ) + 273.15 ;
temp *= muDoubleScalarPower ( temp / 216.6 , - 11.388 ) * 0.002488 / 287.0 ;
} Ut_idx_0 = rtB . dffpum05ns [ 7 ] / Mi ; Ut_idx_1 = rtB . dffpum05ns [ 8 ]
/ Mi ; Ut_idx_2 = rtB . dffpum05ns [ 9 ] / Mi ; tmp_p [ 0 ] = rtB .
dffpum05ns [ 3 ] ; tmp_p [ 1 ] = rtB . dffpum05ns [ 4 ] ; tmp_p [ 2 ] = rtB .
dffpum05ns [ 5 ] ; tmp_p [ 3 ] = rtB . dffpum05ns [ 6 ] ; nlwm4xj33c ( tmp_p
, qt ) ; vt [ 0 ] = qt [ 1 ] ; vt [ 1 ] = qt [ 2 ] ; vt [ 2 ] = qt [ 3 ] ;
b5npvcelre ( qt , Rt ) ; Xcmi = rtP . INTAB3 [ 1 ] - Xcmi ; Ixxi_p [ 0 ] =
Ixxi ; Ixxi_p [ 3 ] = Ixyi ; Ixxi_p [ 6 ] = Ixzi ; Ixxi_p [ 1 ] = Ixyi ;
Ixxi_p [ 4 ] = Iyyi ; Ixxi_p [ 7 ] = Iyzi ; Ixxi_p [ 2 ] = Ixzi ; Ixxi_p [ 5
] = Iyzi ; Ixxi_p [ 8 ] = Izzi ; for ( i = 0 ; i < 3 ; i ++ ) { RA [ i ] =
0.0 ; for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { Rt_e [ i + 3 * i_p ] = 0.0 ; Rt_e
[ i + 3 * i_p ] += Ixxi_p [ 3 * i_p ] * Rt [ i ] ; Rt_e [ i + 3 * i_p ] +=
Ixxi_p [ 3 * i_p + 1 ] * Rt [ i + 3 ] ; Rt_e [ i + 3 * i_p ] += Ixxi_p [ 3 *
i_p + 2 ] * Rt [ i + 6 ] ; RA [ i ] += Rt [ 3 * i_p + i ] * ( real_T ) b [
i_p ] ; } for ( i_p = 0 ; i_p < 3 ; i_p ++ ) { Rt_p [ i + 3 * i_p ] = 0.0 ;
Rt_p [ i + 3 * i_p ] += Rt_e [ i ] * Rt [ i_p ] ; Rt_p [ i + 3 * i_p ] +=
Rt_e [ i + 3 ] * Rt [ i_p + 3 ] ; Rt_p [ i + 3 * i_p ] += Rt_e [ i + 6 ] * Rt
[ i_p + 6 ] ; } } tmp [ 0 ] = rtB . dffpum05ns [ 10 ] ; tmp [ 1 ] = rtB .
dffpum05ns [ 11 ] ; tmp [ 2 ] = rtB . dffpum05ns [ 12 ] ; nhxyxo3xco ( Rt_p ,
tmp , omegat ) ; Vcptnorm [ 0 ] = - Xcmi * RA [ 0 ] ; Vcptnorm [ 1 ] = - Xcmi
* RA [ 1 ] ; Vcptnorm [ 2 ] = - Xcmi * RA [ 2 ] ; ca1i44t24n ( omegat ,
Vcptnorm , tmp ) ; tmp_e = ( oqgpsrqqr4 ( xt ) <= 4.3 ) ; if ( tmp_e ) { Wxi
= 0.0 ; Wyi = 0.0 ; } Wt [ 0 ] = ( Ut_idx_0 + Wxi ) + tmp [ 0 ] ; Wt [ 1 ] =
( Ut_idx_1 + Wyi ) + tmp [ 1 ] ; if ( tmp_e ) { Wzi = 0.0 ; } Wt [ 2 ] = (
Ut_idx_2 + Wzi ) + tmp [ 2 ] ; Ixxi = oqgpsrqqr4 ( Wt ) ; nlwm4xj33c4 ( Wt ,
Vcptnorm ) ; if ( Ixxi == 0.0 ) { Iyyi = 0.0 ; } else { Iyyi = d2wn0mmixj (
Vcptnorm , RA ) ; if ( Iyyi > 1.0 ) { Iyyi = 1.0 ; } Iyyi =
muDoubleScalarAcos ( Iyyi ) ; } Izzi = rtB . cc1cd5zhlf * 0.5 * temp * ( Ixxi
* Ixxi ) * 0.010751315458748 * muDoubleScalarCos ( Iyyi ) ; Ixxi = rtP .
INTAB3 [ 0 ] * Iyyi * 0.5 * temp * ( Ixxi * Ixxi ) * 0.010751315458748 *
muDoubleScalarSin ( Iyyi ) ; ca1i44t24n ( RA , Vcptnorm , tmp ) ; nlwm4xj33c4
( tmp , Vcptnorm ) ; ca1i44t24n ( RA , Vcptnorm , tmp ) ; nlwm4xj33c4 ( tmp ,
Wt ) ; Iyyi = 3.987300564E+14 / ( ( 6.3781E+6 + rtB . dffpum05ns [ 2 ] ) * (
6.3781E+6 + rtB . dffpum05ns [ 2 ] ) ) * Mi ; Mi = Ixxi * Xcmi ; ca1i44t24n (
omegat , vt , tmp ) ; Ixyi = Izzi * - RA [ 0 ] ; RA [ 0 ] *= Ti ; Vcptnorm [
0 ] = Mi * Vcptnorm [ 0 ] + - mshle03l0j * omegat [ 0 ] ; Ixzi = Izzi * - RA
[ 1 ] ; RA [ 1 ] *= Ti ; Vcptnorm [ 1 ] = Mi * Vcptnorm [ 1 ] + - mshle03l0j
* omegat [ 1 ] ; if ( ( Ti <= Iyyi ) && ( rtB . dffpum05ns [ 2 ] < 0.1 ) ) {
rtB . oeuf2hmy0o [ 7 ] = 0.0 ; rtB . oeuf2hmy0o [ 8 ] = 0.0 ; rtB .
oeuf2hmy0o [ 9 ] = 0.0 ; } else { rtB . oeuf2hmy0o [ 7 ] = ( RA [ 0 ] + Ixyi
) + Ixxi * Wt [ 0 ] ; rtB . oeuf2hmy0o [ 8 ] = ( RA [ 1 ] + Ixzi ) + Ixxi *
Wt [ 1 ] ; rtB . oeuf2hmy0o [ 9 ] = ( ( Ti * RA [ 2 ] + Izzi * - RA [ 2 ] ) +
Ixxi * Wt [ 2 ] ) - Iyyi ; } if ( oqgpsrqqr4 ( xt ) <= 4.3 ) { rtB .
oeuf2hmy0o [ 10 ] = 0.0 ; rtB . oeuf2hmy0o [ 11 ] = 0.0 ; rtB . oeuf2hmy0o [
12 ] = 0.0 ; } else { rtB . oeuf2hmy0o [ 10 ] = Vcptnorm [ 0 ] ; rtB .
oeuf2hmy0o [ 11 ] = Vcptnorm [ 1 ] ; rtB . oeuf2hmy0o [ 12 ] = Mi * Vcptnorm
[ 2 ] + - mshle03l0j * omegat [ 2 ] ; } rtB . oeuf2hmy0o [ 0 ] = Ut_idx_0 ;
rtB . oeuf2hmy0o [ 1 ] = Ut_idx_1 ; rtB . oeuf2hmy0o [ 2 ] = Ut_idx_2 ; rtB .
oeuf2hmy0o [ 3 ] = - d2wn0mmixj ( omegat , vt ) * 0.5 ; rtB . oeuf2hmy0o [ 4
] = ( qt [ 0 ] * omegat [ 0 ] + tmp [ 0 ] ) * 0.5 ; rtB . oeuf2hmy0o [ 5 ] =
( qt [ 0 ] * omegat [ 1 ] + tmp [ 1 ] ) * 0.5 ; rtB . oeuf2hmy0o [ 6 ] = ( qt
[ 0 ] * omegat [ 2 ] + tmp [ 2 ] ) * 0.5 ; rtB . gvuqr1jt0i [ 0 ] = rtB .
cc1cd5zhlf * 0.010751315458748 ; rtB . gvuqr1jt0i [ 1 ] = Ut_idx_2 ; rtB .
gvuqr1jt0i [ 2 ] = rtB . dffpum05ns [ 2 ] ; rtB . gvuqr1jt0i [ 3 ] = temp ;
rtB . ej1lofn5r4 = rtX . nkhfitlmge ; rtB . n5ewebaudy = rtX . iw20ly4bl4 ;
if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { aye5salj4v = ( rtB . iustumvjtp > rtB
. gq1bt1ao5w ) ; f4aaprvzvh = ( rtB . iustumvjtp > rtP .
Constant1_Value_jsld3gr050 ) ; } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { Ti =
ssGetTaskTime ( rtS , 2 ) ; if ( ssGetTNextWasAdjusted ( rtS , 2 ) ) { rtDW .
moxilmktys = _ssGetVarNextHitTime ( rtS , 0 ) ; } if ( rtDW . ig2uo5piti != 0
) { rtDW . ig2uo5piti = 0 ; if ( Ti >= rtP . StepFrequency_PhaseDelay ) {
mshle03l0j = ( Ti - rtP . StepFrequency_PhaseDelay ) / rtP .
StepFrequency_Period ; numCycles = ( uint32_T ) muDoubleScalarFloor (
mshle03l0j ) ; if ( muDoubleScalarAbs ( ( real_T ) ( numCycles + 1U ) -
mshle03l0j ) < DBL_EPSILON * mshle03l0j ) { numCycles ++ ; } rtDW .
kxv5tb5r11 = numCycles ; mshle03l0j = ( ( real_T ) numCycles * rtP .
StepFrequency_Period + rtP . StepFrequency_PhaseDelay ) + rtP .
StepFrequency_Duty * rtP . StepFrequency_Period / 100.0 ; if ( Ti <
mshle03l0j ) { rtDW . av0mpygxcu = 1 ; rtDW . moxilmktys = mshle03l0j ; }
else { rtDW . av0mpygxcu = 0 ; rtDW . moxilmktys = ( real_T ) ( numCycles +
1U ) * rtP . StepFrequency_Period + rtP . StepFrequency_PhaseDelay ; } } else
{ rtDW . kxv5tb5r11 = rtP . StepFrequency_PhaseDelay != 0.0 ? - 1 : 0 ; rtDW
. av0mpygxcu = 0 ; rtDW . moxilmktys = rtP . StepFrequency_PhaseDelay ; } }
else { if ( rtDW . moxilmktys <= Ti ) { if ( rtDW . av0mpygxcu == 1 ) { rtDW
. av0mpygxcu = 0 ; rtDW . moxilmktys = ( real_T ) ( rtDW . kxv5tb5r11 + 1LL )
* rtP . StepFrequency_Period + rtP . StepFrequency_PhaseDelay ; } else { rtDW
. kxv5tb5r11 ++ ; rtDW . av0mpygxcu = 1 ; rtDW . moxilmktys = ( rtP .
StepFrequency_Duty * rtP . StepFrequency_Period * 0.01 + ( real_T ) rtDW .
kxv5tb5r11 * rtP . StepFrequency_Period ) + rtP . StepFrequency_PhaseDelay ;
} } } _ssSetVarNextHitTime ( rtS , 0 , rtDW . moxilmktys ) ; if ( rtDW .
av0mpygxcu == 1 ) { rtB . m1vxg5gqae = rtP . StepFrequency_Amp ; } else { rtB
. m1vxg5gqae = 0.0 ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( ( rtDW
. jcuwij5dpk . AQHandles || rtDW . jcuwij5dpk . SlioLTF ) && ssGetLogOutput (
rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . jcuwij5dpk . AQHandles , rtDW .
jcuwij5dpk . SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , ( void * ) & rtB .
gvuqr1jt0i [ 0 ] ) ; } } { if ( ( rtDW . hrqoqhtymu . AQHandles || rtDW .
hrqoqhtymu . SlioLTF ) && ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal (
rtDW . hrqoqhtymu . AQHandles , rtDW . hrqoqhtymu . SlioLTF , 0 ,
ssGetTaskTime ( rtS , 1 ) , ( void * ) & rtB . gvuqr1jt0i [ 1 ] ) ; } } { if
( ( rtDW . fa1rhasmp4 . AQHandles || rtDW . fa1rhasmp4 . SlioLTF ) &&
ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW . fa1rhasmp4 .
AQHandles , rtDW . fa1rhasmp4 . SlioLTF , 0 , ssGetTaskTime ( rtS , 1 ) , (
void * ) & rtB . gvuqr1jt0i [ 2 ] ) ; } } } Ti = rtB . gvuqr1jt0i [ 0 ] ; Mi
= rtP . Constant5_Value / rtB . gvuqr1jt0i [ 3 ] ; mshle03l0j = 19.62 / ( rtB
. gvuqr1jt0i [ 1 ] * rtB . gvuqr1jt0i [ 1 ] ) ; temp = rtP .
Constant1_Value_mq0yqq5e0x - rtB . gvuqr1jt0i [ 2 ] ; Xcmi = - mshle03l0j *
temp * muDoubleScalarExp ( - mshle03l0j * temp ) ; Ixxi = - 2.0 ; Iyyi = (
rtMinusInf ) ; while ( muDoubleScalarAbs ( Ixxi - Iyyi ) / muDoubleScalarAbs
( Ixxi ) > 1.0E-8 ) { Iyyi = Ixxi ; Izzi = muDoubleScalarExp ( Ixxi ) ; Ixyi
= Ixxi * Izzi - Xcmi ; Ixxi -= Ixyi / ( ( Ixxi + 1.0 ) * Izzi - ( Ixxi + 2.0
) * Ixyi / ( 2.0 * Ixxi + 2.0 ) ) ; } mshle03l0j = ( - Mi * Ixxi - Mi *
mshle03l0j * temp ) / temp ; if ( ! muDoubleScalarIsNaN ( mshle03l0j ) ) { Ti
= mshle03l0j ; } rtB . gx0or0kr3s = Ti - rtB . gvuqr1jt0i [ 0 ] ; rtB .
lwp5elo2wh = rtP . PIDController_D * rtB . gx0or0kr3s ; rtB . k0zs1ouug5 =
rtB . lwp5elo2wh - rtB . n5ewebaudy ; rtB . fziqurelun = rtP .
PIDController_N * rtB . k0zs1ouug5 ; rtB . ec3lzwjpul = ( rtP .
PIDController_P * rtB . gx0or0kr3s + rtB . ej1lofn5r4 ) + rtB . fziqurelun ;
rtB . pgtzcj3xlg = rtB . ec3lzwjpul * rtP . Constant1_Value_oqyl4nphju ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep ( rtS ) ) { rtDW .
fwrbx3e2f1 = ( rtB . pgtzcj3xlg > rtP . Constant_Value_knfpzjs1ar ) ; } rtB .
a0thuhlkvf = rtDW . fwrbx3e2f1 ; cehmom0v5t = ( ( ( ! rtB . a0thuhlkvf ) || (
! aye5salj4v ) ) && ( rtB . a0thuhlkvf || f4aaprvzvh ) ) ; } if (
ssIsMajorTimeStep ( rtS ) ) { rtDW . hef1fu14qj = ( rtB . pgtzcj3xlg >= 0.0 )
; } rtB . p5nx0ha0gn = rtDW . hef1fu14qj > 0 ? rtB . pgtzcj3xlg : - rtB .
pgtzcj3xlg ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . gld15yigj5 = ( rtB . p5nx0ha0gn > rtP . StepSize_Value ) ; }
rtB . i3wfi0zs3s = ( real_T ) rtDW . gld15yigj5 * rtB . m1vxg5gqae * ( real_T
) cehmom0v5t ; { if ( ( rtDW . k53fkqd2g2 . AQHandles || rtDW . k53fkqd2g2 .
SlioLTF ) && ssGetLogOutput ( rtS ) ) { sdiSlioSdiWriteSignal ( rtDW .
k53fkqd2g2 . AQHandles , rtDW . k53fkqd2g2 . SlioLTF , 0 , ssGetTaskTime (
rtS , 1 ) , ( void * ) & rtB . iustumvjtp ) ; } } if ( ssIsMajorTimeStep (
rtS ) ) { zcEvent = rt_ZCFcn ( RISING_ZERO_CROSSING , & rtPrevZCX .
pysmillkpz , ( rtB . i3wfi0zs3s ) ) ; if ( zcEvent != NO_ZCEVENT ) { rtB .
l0euqgxhm0 = rtDW . nu2anqwsoh ; rtDW . nu2anqwsoh = ( rtP . Constant1_Value
+ ( real_T ) rtB . a0thuhlkvf ) * rtP . Constant_Value + rtB . l0euqgxhm0 ;
rtDW . kijlfweplt = 4 ; } } rtB . flslv0y4cj = rtB . l0euqgxhm0 * 1.8 *
0.1820830298616169 ; } rtB . d22mgk2nk4 = rtP . PIDController_I * rtB .
gx0or0kr3s ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { if ( ssIsMajorTimeStep (
rtS ) ) { rtDW . em2vdfypg1 = ( rtB . oeuf2hmy0o [ 2 ] <= rtP .
Constant5_Value_kpkyenjwdq ) ; } if ( rtDW . em2vdfypg1 ) {
ssSetStopRequested ( rtS , 1 ) ; } } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID3 ( int_T tid ) { memcpy ( & rtB . ahkiafeoia [ 0 ] , & rtP .
Constant_Value_e5cors3m1f [ 0 ] , 13U * sizeof ( real_T ) ) ; rtB .
gq1bt1ao5w = rtP . AngleofAirBrakeFlapswhenFullyOpendegrees_Value - rtP .
Constant_Value_ldchjia2i4 ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { rtDW . ix0gnlc2nc = 0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) {
rtDW . bnnyzhf4hd = rtB . flslv0y4cj ; } UNUSED_PARAMETER ( tid ) ; } void
MdlUpdateTID3 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void
MdlDerivatives ( void ) { XDot * _rtXdot ; _rtXdot = ( ( XDot * ) ssGetdX (
rtS ) ) ; memcpy ( & _rtXdot -> gzm0a20aj2 [ 0 ] , & rtB . oeuf2hmy0o [ 0 ] ,
13U * sizeof ( real_T ) ) ; _rtXdot -> nkhfitlmge = rtB . d22mgk2nk4 ;
_rtXdot -> iw20ly4bl4 = rtB . fziqurelun ; } void MdlProjection ( void ) { }
void MdlZeroCrossings ( void ) { ZCV * _rtZCSV ; _rtZCSV = ( ( ZCV * )
ssGetSolverZcSignalVector ( rtS ) ) ; _rtZCSV -> p4lmzczvon = rtB .
pgtzcj3xlg - rtP . Constant_Value_knfpzjs1ar ; _rtZCSV -> okc25qnabt = rtB .
pgtzcj3xlg ; _rtZCSV -> akvyvcyj0o = rtB . p5nx0ha0gn - rtP . StepSize_Value
; _rtZCSV -> mpq4npk020 = rtB . oeuf2hmy0o [ 2 ] - rtP .
Constant5_Value_kpkyenjwdq ; } void MdlTerminate ( void ) { { if ( rtDW .
jcuwij5dpk . AQHandles ) { sdiTerminateStreaming ( & rtDW . jcuwij5dpk .
AQHandles ) ; } if ( rtDW . jcuwij5dpk . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . jcuwij5dpk . SlioLTF ) ; } } { if ( rtDW
. hrqoqhtymu . AQHandles ) { sdiTerminateStreaming ( & rtDW . hrqoqhtymu .
AQHandles ) ; } if ( rtDW . hrqoqhtymu . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . hrqoqhtymu . SlioLTF ) ; } } { if ( rtDW
. fa1rhasmp4 . AQHandles ) { sdiTerminateStreaming ( & rtDW . fa1rhasmp4 .
AQHandles ) ; } if ( rtDW . fa1rhasmp4 . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . fa1rhasmp4 . SlioLTF ) ; } } { if ( rtDW
. k53fkqd2g2 . AQHandles ) { sdiTerminateStreaming ( & rtDW . k53fkqd2g2 .
AQHandles ) ; } if ( rtDW . k53fkqd2g2 . SlioLTF ) {
rtwDestructAccessorPointer ( rtDW . k53fkqd2g2 . SlioLTF ) ; } } if (
rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 15 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
3 ) ; ssSetNumBlocks ( rtS , 63 ) ; ssSetNumBlockIO ( rtS , 23 ) ;
ssSetNumBlockParams ( rtS , 4203 ) ; } void MdlInitializeSampleTimes ( void )
{ ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetSampleTime ( rtS , 2 , - 2.0 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 1.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 2887184815U ) ;
ssSetChecksumVal ( rtS , 1 , 2526773862U ) ; ssSetChecksumVal ( rtS , 2 ,
209535582U ) ; ssSetChecksumVal ( rtS , 3 , 2430258776U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 17 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
SIL_Arduino_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS ,
true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "SIL_Arduino" ) ;
ssSetPath ( rtS , "SIL_Arduino" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal (
rtS , 30.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo .
loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } {
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 15 ] ; static
real_T absTol [ 15 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6
, 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 15 ] = { 0U , 0U , 0U , 0U , 0U ,
0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U , 0U } ; static uint8_T
zcAttributes [ 5 ] = { ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL ) , ( ZC_EVENT_ALL )
, ( ZC_EVENT_ALL ) , ( 0xc0 | ZC_EVENT_ALL_UP ) } ; static
ssNonContDerivSigInfo nonContDerivSigInfo [ 1 ] = { { 1 * sizeof ( real_T ) ,
( char * ) ( & rtB . cc1cd5zhlf ) , ( NULL ) } } ; ssSetSolverRelTol ( rtS ,
0.001 ) ; ssSetStepSize ( rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ;
ssSetMaxNumMinSteps ( rtS , - 1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ;
ssSetMaxStepSize ( rtS , 0.6 ) ; ssSetSolverMaxOrder ( rtS , - 1 ) ;
ssSetSolverRefineFactor ( rtS , 1 ) ; ssSetOutputTimes ( rtS , ( NULL ) ) ;
ssSetNumOutputTimes ( rtS , 0 ) ; ssSetOutputTimesOnly ( rtS , 0 ) ;
ssSetOutputTimesIndex ( rtS , 0 ) ; ssSetZCCacheNeedsReset ( rtS , 1 ) ;
ssSetDerivCacheNeedsReset ( rtS , 0 ) ; ssSetNumNonContDerivSigInfos ( rtS ,
1 ) ; ssSetNonContDerivSigInfos ( rtS , nonContDerivSigInfo ) ;
ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetSolverZcSignalAttrib (
rtS , zcAttributes ) ; ssSetSolverNumZcSignals ( rtS , 5 ) ;
ssSetModelZeroCrossings ( rtS , MdlZeroCrossings ) ;
ssSetSolverConsecutiveZCsStepRelTol ( rtS , 2.8421709430404007E-13 ) ;
ssSetSolverMaxConsecutiveZCs ( rtS , 1000 ) ; ssSetSolverConsecutiveZCsError
( rtS , 2 ) ; ssSetSolverMaskedZcDiagnostic ( rtS , 1 ) ;
ssSetSolverIgnoredZcDiagnostic ( rtS , 1 ) ; ssSetSolverMaxConsecutiveMinStep
( rtS , 1 ) ; ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid (
rtS , INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset (
rtS ) ; ssSetNumNonsampledZCs ( rtS , 4 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; } {
ZCSigState * zc = ( ZCSigState * ) & rtPrevZCX ; ssSetPrevZCSigState ( rtS ,
zc ) ; } { rtPrevZCX . pysmillkpz = UNINITIALIZED_ZCSIG ; } ssSetChecksumVal
( rtS , 0 , 2887184815U ) ; ssSetChecksumVal ( rtS , 1 , 2526773862U ) ;
ssSetChecksumVal ( rtS , 2 , 209535582U ) ; ssSetChecksumVal ( rtS , 3 ,
2430258776U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 6 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = ( sysRanDType * ) & rtDW . kijlfweplt ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 3 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID3 ( tid ) ; }
