#include "__cf_SIL_Arduino.h"
#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "int64_T" , 14 , 8 } , { "int64_T" , 15
, 8 } , { "uint64_T" , 16 , 8 } } ; static uint_T rtDataTypeSizes [ ] = {
sizeof ( real_T ) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof (
uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) ,
sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof (
int_T ) , sizeof ( pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T
) , sizeof ( int64_T ) , sizeof ( int64_T ) , sizeof ( uint64_T ) } ; static
const char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" ,
"uint8_T" , "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"int64_T" , "int64_T" , "uint64_T" } ; static DataTypeTransition
rtBTransitions [ ] = { { ( char_T * ) ( & rtB . ahkiafeoia [ 0 ] ) , 0 , 0 ,
60 } , { ( char_T * ) ( & rtB . a0thuhlkvf ) , 8 , 0 , 1 } , { ( char_T * ) (
& rtDW . nu2anqwsoh ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtDW . kxv5tb5r11 )
, 14 , 0 , 1 } , { ( char_T * ) ( & rtDW . lyitfitoch . LoggedData ) , 11 , 0
, 11 } , { ( char_T * ) ( & rtDW . ig2uo5piti ) , 6 , 0 , 2 } , { ( char_T *
) ( & rtDW . ix0gnlc2nc ) , 10 , 0 , 2 } , { ( char_T * ) ( & rtDW .
kijlfweplt ) , 2 , 0 , 1 } , { ( char_T * ) ( & rtDW . fwrbx3e2f1 ) , 8 , 0 ,
3 } } ; static DataTypeTransitionTable rtBTransTable = { 9U , rtBTransitions
} ; static DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP .
INTAB1 [ 0 ] ) , 0 , 0 , 4203 } } ; static DataTypeTransitionTable
rtPTransTable = { 1U , rtPTransitions } ;
