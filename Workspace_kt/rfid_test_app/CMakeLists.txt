cmake_minimum_required(VERSION 3.17)
project(DelayTest C)
add_executable(RfidTestApp
    rfid_test.c
    )

FIND_LIBRARY(PCSC_LIBRARY NAMES pcsclite)
FIND_PATH(PCSC_INCLUDE_DIR PCSC/winscard.h PATH_SUFFIXES PCSC)

#target_include_directories(CurlTestApp
#    PRIVATE
#    )
target_include_directories(RfidTestApp
    PRIVATE
    "${PCSC_INCLUDE_DIR}/PCSC"
)
target_link_libraries(RfidTestApp PRIVATE "${PCSC_LIBRARY}")

