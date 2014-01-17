#ifndef _KEYBOARD_REPORTS_H_
#define _KEYBOARD_REPORTS_H_

    /* Includes: */
        #include <avr/io.h>
        #include <LUFA/Drivers/USB/USB.h>
        #include "BootloaderJump.h"
        #include "Keyboard.h"

    /* Macros: */
        #define AGENT_COMMAND_REENUMERATE 0

        #define REENUMERATE_AS_KEYBOARD      0
        #define REENUMERATE_AS_BOOTLOADER    1
        #define REENUMERATE_AS_USB_TO_SERIAL 2

    /* Function Prototypes: */
        bool CreateKeyboardHIDReport(void* ReportData, uint16_t* const ReportSize);
        bool CreateMouseHIDReport(void* ReportData, uint16_t* const ReportSize);
        bool CreateGenericHIDReport(void* ReportData, uint16_t* const ReportSize);
        void ProcessGenericHIDReport(const void* ReportData, const uint16_t ReportSize);

#endif
