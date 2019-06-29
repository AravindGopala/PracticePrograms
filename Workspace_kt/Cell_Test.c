//******************************************************************************
// FILE:          pwr_cmd_test.c
//
// AUTHOR:        Patrick Miller
// CREATION DATE: July 18, 2016
// FIRST USE:     LBB-1
//
// DESCRIPTION:   Connects to a target process and commands a power state.
//
// All information contained herein is the property of KeepTruckin Inc. The
// intellectual and technical concepts contained herein are proprietary to
// KeepTruckin. Dissemination of this information or reproduction of this
// material is strictly forbidden unless prior written permission is obtained
// from KeepTruckin.
//
// Copyright 2016, KeepTruckin, Inc. All rights reserved.
//
//******************************************************************************


// Library Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stropts.h>
#include <poll.h>
#include <systemd/sd-journal.h>
#include <errno.h>
#include "../include/cell/cell_modem_api.h"
#include "../../ktdaqd/sensors/cell/cell_service_logic.h"
#include "../src/cell/cell_modem_hl7588.c"
#include "../../ktdaqd/sensors/cell/cell_service_logic.c"

// Local defines
#define DEFAULT_POLL_MS             1000
#define DEFAULT_PUBLISH_MS          1000        //1 Hz (or on drastic change)
#define NDOF_TTL                    DEFAULT_DATA_TTL

//FILE *fp;


const char *LBBDmnHelp =
        "    %s [ARG] [on|off] \n\n"
        "     -c [NUM]        number of messages to send\n"
        "     -p [on | off ]  power state [ defaults to on ]\n"
        "     -v              print version and exit\n\n";

CellServiceData_t * pObj = NULL;
CellModemHL7588Opts_t HL7588Opts =
{
    .eResetPin      = CELL_RESET_N,
    .ePwrPin        = CELL_POWER_ON,
    .eSleepEn       = CELL_DTR_N,
    .eModemRdy      = CELL_RDY,
    .bEnableXInfo   = false
};
// Local prototype
static void TestCellSrvStateChg(void * UsrObj, const CellModemHwStates_e eNewState)
{
    // Copy provided state to local variable
printf("State Change");
}

static void TestCellSrvCmdOut(void * UsrObj, const char * pBuf, const size_t uMsgLen)
{
   // Check input command against local buffer size
printf("State Change");

}
// Main
int main(int argc, char **args)
{
    // Command line flags
    //listen for signals
    //NOTE: LBB_SignalHandler provides the default
    //  behavior for each signal, these can be changed
    //  by providing a different function callback
    //    eg. signal (SIGINT,  NewSignalHandler);
    //  afte the LBB_Register call
    printf("Initialized HL7588 Hardware Object");
    pObj = (CellServiceData_t*)malloc(sizeof(CellServiceData_t));
    memset(pObj, 0, sizeof(CellServiceData_t));

    pObj->pCellHw = CellModemHL7588Create(TestCellSrvCmdOut,TestCellSrvStateChg, &HL7588Opts);
    pObj->pCellHw->set_power_state = hl7588_set_power_state;

    printf("Initialized HL7588 Hardware Object");


    int opt = 0;
    while ((opt = getopt(argc, args, "c:p:v")) != -1)
    {
        switch (opt)
        {
        case 'p':
            if (strncmp("on", optarg, 2) == 0)
            {
                printf("Power up cell modem \n");
                fflush(stdout);

                pObj->pCellHw->set_power_state(pObj->pCellHw, CELL_MODEM_POWER_UP);
            }
            else if (strncmp("off", optarg, 3) == 0)
            {
                printf("Power down cell modem \n");

                printf("%d",pObj->pCellHw->set_power_state(pObj->pCellHw, CELL_MODEM_POWER_DOWN));
            }
            else if (strncmp("reset", optarg, 4) == 0)
            {
                printf("Power reset cell modem \n");

                pObj->pCellHw->set_power_state(pObj->pCellHw, CELL_MODEM_POWER_RESET);
            }
            break;

        case 'v':
            exit(EXIT_SUCCESS);
            break;

        case ':':
            break;

        case '?':
            break;
        }
    }

    return EXIT_SUCCESS;
}


