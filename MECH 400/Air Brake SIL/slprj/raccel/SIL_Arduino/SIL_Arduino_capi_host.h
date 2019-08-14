#include "__cf_SIL_Arduino.h"
#ifndef RTW_HEADER_SIL_Arduino_cap_host_h_
#define RTW_HEADER_SIL_Arduino_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
SIL_Arduino_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void SIL_Arduino_host_InitializeDataMapInfo ( SIL_Arduino_host_DataMapInfo_T
* dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
