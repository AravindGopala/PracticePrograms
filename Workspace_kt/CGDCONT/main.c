#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define     CellCommonCGDCONTSize   (256)       ///< Allow for IPv6 addresses
typedef struct CellCGDCONTData_s
{
    int    iContext;
    char   sIPType[CellCommonCGDCONTSize];
    char   sAPN[CellCommonCGDCONTSize];
} CellCGDCONTData_t;

#define     CellCommonCGDCONTListSize   (3)       ///< Allow for IPv6 addresses
typedef struct {
    CellCGDCONTData_t aCGDCONT[CellCommonCGDCONTListSize];  ///< Array of CellCGDCONTData's
} CellCGDCONTList_t;

void Cell_CGDCONTDataListClear(CellCGDCONTList_t* pObjList)
{
    // Mem clear the structure, if pointer not NULL
    if(pObjList)
    {
        memset(pObjList, 0, sizeof(*pObjList));
    }
}

/**
 * @brief Searches and extracts string between quotes delimted by pBoundary
 *
 * @param pBuffer contains adress to a character buffer
 * @param pData points to the extracted string with Quotes
 * @param pBoundary delimiter for the search
 * @param uMaxlen max length of buffer pointed by pData
 *
 * @return returns pointer to the end of the extracted string if present
 *         otherwise returns pointer to thew passed in buffer
 */
static char* ExtractStringBetweenQuotes(char* pBuffer, char *pData, char* pBoundary, size_t uMaxLen)
{
    /* +CGDCONT: 1,"IPV4V6","vzwims","",0,0,0,0,1,0 +CGDCONT:*/
    char *pStart = NULL, *pEnd = NULL;

    // Pointer checks
    if (pBuffer == NULL || pData == NULL)
    {
        return NULL;
    }

    // postion to the first occurence of (")
    pStart = strchr(pBuffer, '\"');
    // pBuffer does not contain ("), do not truncate pBuffer
    if (pStart == NULL) { return pBuffer;}

    pEnd = pBoundary;

    if(pEnd != NULL)
    {
        if(pEnd > pStart)
        {
            // postion to the first occurence of (")
            pEnd   = strchr(pStart+1, '\"');
            // pBuffer does not contain ("), do not truncate pBuffer
            if (pEnd == NULL) { return pBuffer;}
        }
        else
        {
            // pStart exceeds pBoundary
            return pBuffer;
        }
    }
    else
    {
        pEnd   = strchr(pStart+1, '\"');
        // pBuffer does not contain ("), do not truncate pBuffer
        if (pEnd == NULL) { return pBuffer;}
    }

    // point the start of passed in buffer to pEnd(")
//    *pBuffer = pEnd;
    // Length of response APN is (pEnd - pStart)
    size_t RespLen = (pEnd - pStart - 1);
    uMaxLen = MIN(RespLen, uMaxLen);

    memcpy(pData, pStart+1, uMaxLen);

    // String between quotes extracted successfully, return pointer
    // to the end of the extracted string
    return pEnd;
}


bool ProcessCGDCONTRsp(char *pBuffer, CellCGDCONTList_t * pDataL)
{
    /* +CGDCONT: 1,"IPV4V6","vzwims","",0,0,0,0,1,0 */
    char *pStart = NULL, *pEnd = NULL;
    bool bRes = false;
    CellCGDCONTData_t*         pData;
    // Pointer checks
    if (pBuffer == NULL || pDataL == NULL)
    {
        return false;
    }
    size_t i=0;

            pStart = strstr(pBuffer, "+CGDCONT");
            if (pStart == NULL){ return bRes;}
    while(pStart != NULL && i<CellCommonCGDCONTListSize)
    {
        // Parse CGDCONT result starting at pStart
        /* +CGDCONT: 1,"IPV4V6","vzwims","",0,0,0,0,1,0 +CGDCONT:*/
        int iNumParsed = sscanf(pStart,
            "%*s%d,%*[ \"]%[^,\"]%*[\"],%*[ \"]%[^,\"]%*[\"]",
            &pDataL->aCGDCONT[i].iContext,
            pDataL->aCGDCONT[i].sIPType,
            pDataL->aCGDCONT[i].sAPN
            //vOption for IP address parsing here
            );
        printf("iContext is %d, sIPType is%s, sAPN is%s,\n", pDataL->aCGDCONT[i].iContext, pDataL->aCGDCONT[i].sIPType, pDataL->aCGDCONT[i].sAPN);
            i++;
        pStart = strstr(pStart+1, "+CGDCONT"); ///< No buffer overflow possible as we found the target string previously
    }

    return (i>0? true:false);
}
int main()
{
    CellCGDCONTList_t         sContextList;
    CellCGDCONTData_t         sContext;

    Cell_CGDCONTDataListClear(&sContextList);


    bool res = ProcessCGDCONTRsp("+CGDCONT: 5, \" NONE \", \" Pat SApN \", \"\" ",
                              &sContextList);
    return 0;
}
