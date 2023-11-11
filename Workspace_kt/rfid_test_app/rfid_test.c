#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <winscard.h>
#include <unistd.h>
#include <reader.h>



SCARDCONTEXT applicationContext;
LPSTR reader = NULL;
SCARDHANDLE connectionHandler;
DWORD activeProtocol;


void establishContext() {
    LONG status = SCardEstablishContext(SCARD_SCOPE_SYSTEM, NULL, NULL, &applicationContext);
    if (status == SCARD_S_SUCCESS) {
        printf("Context established\n");
    } else {
        printf("Establish context error: %s\n", pcsc_stringify_error(status));
        exit(1);
    }
}
void releaseContext() {
    LONG status = SCardReleaseContext(applicationContext);
    if (status == SCARD_S_SUCCESS) {
        printf("Context released\n");
    } else {
        printf("Release context error: %s\n", pcsc_stringify_error(status));
        exit(1);
    }
}


void listReaders() {
    DWORD readers = SCARD_AUTOALLOCATE;
    LONG status = SCardListReaders(applicationContext, NULL, (LPSTR)&reader, &readers);

    if (status == SCARD_S_SUCCESS) {
        char *p = reader;
        while (*p) {
            printf("Reader found: %s\n", p);
            p += strlen(p) +1;
        }
    } else {
        printf("List reader error: %s\n", pcsc_stringify_error(status));
        exit(1);
    }
}

void freeListReader() {
    LONG status = SCardFreeMemory(applicationContext, reader);
    if (status == SCARD_S_SUCCESS) {
        printf("Reader list free\n");
    } else {
        printf("Free reader list error: %s\n", pcsc_stringify_error(status));
        exit(1);
    }
}


void connectToCard() {
    activeProtocol = -1;

    LONG status = SCardConnect(applicationContext, reader, SCARD_SHARE_DIRECT, 0, &connectionHandler, &activeProtocol);
    if (status == SCARD_S_SUCCESS) {
        printf("Connected to card\n");
    } else {
        printf("Card connection error: %s\n", pcsc_stringify_error(status));
        // exit(1);
    }
}
void disconnectFromCard() {
    LONG status = SCardDisconnect(connectionHandler, SCARD_LEAVE_CARD);
    if (status == SCARD_S_SUCCESS) {
        printf("Disconnected from card\n");
    } else {
        printf("Card deconnection error: %s\n", pcsc_stringify_error(status));
        exit(1);
    }
}


void getCardInformation() {
    BYTE ATR[MAX_ATR_SIZE] = "";
    DWORD ATRLength = sizeof(ATR);
    char readerName[MAX_READERNAME] = "";
    DWORD readerLength = sizeof(readerName);
    DWORD readerState;
    DWORD readerProtocol;

    LONG status = SCardStatus(connectionHandler, readerName, &readerLength, &readerState, &readerProtocol, ATR, &ATRLength);
    if (status == SCARD_S_SUCCESS) {
        printf("\n");
        printf("Name of the reader: %s\n", readerName);
        printf("ATR: ");
        for (size_t i=0; i<ATRLength; i++) {
            printf("%02X ", ATR[i]);
        }
        printf("\n\n");
    } else {
        printf("Get card information error: %s\n", pcsc_stringify_error(status));
        exit(1);
    }
}


void sendCommand(uint8_t command[], unsigned short commandLength) {
    const SCARD_IO_REQUEST *pioSendPci;
    SCARD_IO_REQUEST pioRecvPci;
    uint8_t response[300];
    unsigned long responseLength = sizeof(response);
    pioSendPci = SCARD_PCI_RAW;
    // switch(activeProtocol) {
    // 	case SCARD_PROTOCOL_T0:
    // 		pioSendPci = SCARD_PCI_T0;
    //         printf("SCARD_PCI_T0 found\n");
    // 		break;
    // 	case SCARD_PROTOCOL_T1:
    // 		pioSendPci = SCARD_PCI_T1;
    //         printf("SCARD_PCI_T1 found\n");
    // 		break;
    // 	default:
    //         pioSendPci = SCARD_PCI_T1;
    // 		printf("Protocol not found\n");
    // 		// exit(1);
    // }


    LONG status = SCardTransmit(connectionHandler, pioSendPci, command, commandLength, &pioRecvPci, response, &responseLength);
    if (status == SCARD_S_SUCCESS) {
        printf("Command sent: \n");
        for (int i=0; i<commandLength; i++) {
            printf("%02X ", command[i]);
        }
        printf("\nResponse: \n");
        for (size_t i=0; i<responseLength; i++) {
            printf("%02X ", response[i]);
        }
        printf("\n\n");
    } else {
        printf("Send command error: %s\n", pcsc_stringify_error(status));
        printf("\nResponse: \n");
        for (size_t i=0; i<responseLength; i++) {
            printf("%02X ", response[i]);
        }
        // exit(1);
    }
}

void mifareUltralight() {
    printf("### MIFARE Ultralight ###\n");
    uint8_t pageNumber = 0x04;

    // Read 4 blocks (16 bytes) starting from pageNumber
    uint8_t readCommand[] = { 0xFF, 0xB0, 0x00, pageNumber, 0x10 };
    unsigned short readCommandLength = sizeof(readCommand);
    sendCommand(readCommand, readCommandLength);

    // Write 1 block (4 bytes) to pageNumber
    uint8_t data[] = { 0x00, 0x01, 0x02, 0x03 };
    uint8_t writeCommand[9] = { 0xFF, 0xD6, 0x00, pageNumber, 0x04 };
    unsigned short writeCommandLength = sizeof(writeCommand);
    for (size_t i=0; i<4; i++) {
        writeCommand[i+5] = data[i];
    }
    sendCommand(writeCommand, writeCommandLength);
}


void mifareClassic() {
    printf("### MIFARE Classic ###\n");
    uint8_t blockNumber = 0x04;

    // Load Authentication Keys
    uint8_t key[6] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    uint8_t authenticationKeysCommand[11] = { 0xFF, 0x82, 0x00, 0x00, 0x06 };
    unsigned short authenticationKeysCommandLength = sizeof(authenticationKeysCommand);
    for (int i=0; i<6; i++) {
        authenticationKeysCommand[i+5] = key[i];
    }
    sendCommand(authenticationKeysCommand, authenticationKeysCommandLength);

    // Authenticate
    uint8_t authenticateCommand[] = { 0xFF, 0x86, 0x00, 0x00, 0x05, 0x01, 0x00, blockNumber, 0x60, 0x00 };
    unsigned short authenticateCommandLength = sizeof(authenticateCommand);
    sendCommand(authenticateCommand, authenticateCommandLength);

    // Read 1 blocks (16 bytes) at blockNumber
    uint8_t readCommand[] = { 0xFF, 0xB0, 0x00, blockNumber, 0x10 };
    unsigned short readCommandLength = sizeof(readCommand);
    sendCommand(readCommand, readCommandLength);

    // Write 1 blocks (16 bytes) at blockNumber
    uint8_t data[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };
    uint8_t writeCommand[21] = { 0xFF, 0xD6, 0x00, blockNumber, 0x10 };
    unsigned short writeCommandLength = sizeof(writeCommand);
    for (int i=0; i<16; i++) {
        writeCommand[i+5] = data[i];
    }
    sendCommand(writeCommand, writeCommandLength);
}

#define IOCTL_CCID_ESCAPE SCARD_CTL_CODE(3500)

void blink_led(){
    printf("sending command \n");
    uint8_t NumRepeat = 2;
    uint8_t bBuzzerState = 0;
//    uint8_t command[] = {0xFF, 0x00, 0x40, 0xA4, 0x04, 0x05, 0x05, NumRepeat, bBuzzerState, 0x00};
//    fflush(stdout);
//    sendCommand(command, sizeof(command));
//    fflush(stdout);
//     uint8_t command[] = {0xFF, 0x00, 0x40, 0xFF, 0x00};
//     uint8_t command[] = {0xff, 0x00, 0x48, 0x00, 0x00};
//       uint8_t command[] = {0xff, 0x00, 0x52, 0x00, 0x00}; // --> buzzer off permanently
//       uint8_t command[] = {0xff, 0x00, 0x50, 0x00, 0x00}; // --> Get the pic polling parameter
//       uint8_t command[] = {0xff, 0x00, 0x51, 0x7F, 0x00}; // --> Set the pic polling parameter, disable polling
//         uint8_t command[] = {0xff, 0x00, 0x51, 0xFF, 0x00}; // --> Set the pic polling parameter, enable polling
//       uint8_t command[] = {0xFF, 0x00, 0x00, 0x00, 0x05, 0xD4, 0x60, 0xFF, 0x0F, 0x10}; // --> PN532 direct communication
//       uint8_t command[] = {0xFF, 0x00, 0x00, 0x00, 0x02, 0xD4, 0x02}; // --> PN532 direct communication, get firmware version

     uint8_t command[] = {0xFF, 0x00, 0x00, 0x21, 0x01, 0x80}; // --> To PICC Polling Status Disable
//    uint8_t command[] = {0xFF, 0x00, 0x40, 0x55, 0x04, 0x05, 0x05, 0x02, 0x00}; // --> Blink red and stay Red
//    uint8_t command[] = {0xFF, 0x00, 0x40, 0xA4, 0x04, 0x05, 0x05, 0x02, 0x00}; // --> Blink green and stay green
//    uint8_t command[] = {0xFF, 0x00, 0x40, 0xAF, 0x04, 0x05, 0x05, 0x02, 0x00}; // --> Blink green and stay orange

//     unsigned short CommandLength = sizeof(command);
     BYTE abResponse[65548];
     DWORD dwRespLen;
     unsigned long responseLength = sizeof(abResponse);
     LONG res = SCardControl(connectionHandler, IOCTL_CCID_ESCAPE, command, sizeof(command),
          abResponse, responseLength, &dwRespLen);

     if (res != SCARD_S_SUCCESS)
     {
         printf("Error -> (%ld)\n", res);
     }
     else
     {
         printf("\nResponse\n");
         for (size_t i=0; i<dwRespLen; i++) {
            printf("%02X ", abResponse[i]);
        }
         printf("\n");
         printf("\nSuccess\n");
     }
}

int main() {
    establishContext();
    listReaders();
    connectToCard();
//    SCARD_READERSTATE txreaderState;
//    txreaderState.szReader = "ACS ACR122U 00 00";
//    txreaderState.szReader = "\\\\?PnP?\\Notification";
//    txreaderState.dwCurrentState = SCARD_STATE_UNAWARE;
//    SCardGetStatusChange(applicationContext, 0, &txreaderState, 1);

//    LONG status = SCardGetStatusChange(applicationContext, INFINITE, &txreaderState, 1);
    // getCardInformation();

    blink_led();

    // printf("Firmware command:\n");
    // uint8_t firmwareCommand[] = { 0xFF, 0x00, 0x48, 0x00, 0x00 };
    // unsigned short firmwareCommandLength = sizeof(firmwareCommand);
    // sendCommand(firmwareCommand, firmwareCommandLength);

    // mifareUltralight();
    //mifareClassic();

    disconnectFromCard();
    freeListReader();
    releaseContext();

    return 0;
}
