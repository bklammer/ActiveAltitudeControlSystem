#include "SIL_Arduino_capi_host.h"
static SIL_Arduino_host_DataMapInfo_T root;
static int initialized = 0;
__declspec( dllexport ) rtwCAPI_ModelMappingInfo *getRootMappingInfo()
{
    if (initialized == 0) {
        initialized = 1;
        SIL_Arduino_host_InitializeDataMapInfo(&(root), "SIL_Arduino");
    }
    return &root.mmi;
}

rtwCAPI_ModelMappingInfo *mexFunction() {return(getRootMappingInfo());}
