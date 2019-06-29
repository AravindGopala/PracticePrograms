#include <stdio.h>
#include <stdbool.h>
#include <string.h>
typedef struct CellCopsData_s
{
    int tTimeIn;    ///< Local time stamp this structure was updated
    int eMode;      ///< Operator selection mode
    int eFormat;    ///< Format of the current data result
    char sOper[17]; ///< Operator result, See eFormat for output format
    int eAct;       ///< Access technology result
} CellCopsData_t;

void Cell_COPSDataClear(CellCopsData_t *pObj)
{
    // Mem clear the structure, if pointer not NULL
    if (pObj)
    {
        memset(pObj, 0, sizeof(*pObj));
        pObj->eMode = -1;
        pObj->eFormat = -1;
        pObj->eAct = -1;
    }
}

bool ProcessCOPSRsp(const char *pBuffer, CellCopsData_t *pData)
{
    /* Sample WDSC response
     at+COPS?
    +COPS: 0,0,"AT&T",2
    */
    char pformat[10], pMode[10], pOper[256], pAct[10];
    char *pStart;
    int iAct;
    // Pointer checks
    if (pBuffer == NULL || pData == NULL)
    {
        return false;
    }

    /* Search for the start of the response */
    pStart = strstr(pBuffer, "+COPS:"); ///< Scan to first instance of WDSS
    if (pStart == NULL)
    {
        return false;
    }

    // Check for the next occurence of WDSC
    int num_fields = sscanf(pStart, "+COPS:%d,%d,%*[\"]%[^, \"]%*[\"],%d",
                            &pData->eMode, &pData->eFormat, pData->sOper, &pData->eAct);
    printf("num is %d, Mode is %d Format is %d Operator is%seAct is %d\n", num_fields, pData->eMode, pData->eFormat, pData->sOper, pData->eAct);

    if (num_fields < 4)
    {
        return false;
    }
    return true;
    //    int num_parsed = sscanf(pStart+1, "%d%*[, ]%d%*[, ]%*[\"]%s%*[ ]%*[\"]%*[, ]%d", &pData->eMode, &pData->eFormat, pData->sOper, &pData->eAct);
}

int main()
{
    CellCopsData_t ft;
    Cell_COPSDataClear(&ft);

    bool res = ProcessCOPSRsp("at+COPS?\
                               +COPS: 1, 2, \" AT&T \" ,2\
                               OK",
                              &ft);
    return 0;
}
