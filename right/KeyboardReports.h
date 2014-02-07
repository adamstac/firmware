#ifndef _KEYBOARD_REPORTS_H_
#define _KEYBOARD_REPORTS_H_

    /* Includes: */
        #include <avr/io.h>
        #include <LUFA/Drivers/USB/USB.h>
        #include "BootloaderJump.h"
        #include "Keyboard.h"

    /* Macros: */
        #define MOUSE_STATE_UP    (1<<0)
        #define MOUSE_STATE_LEFT  (1<<1)
        #define MOUSE_STATE_DOWN  (1<<2)
        #define MOUSE_STATE_RIGHT (1<<3)

        #define MOUSE_STATE_LEFT_CLICK   (1<<0)
        #define MOUSE_STATE_MIDDLE_CLICK (1<<1)
        #define MOUSE_STATE_RIGHT_CLICK  (1<<2)

        #define MOUSE_MAX_SPEED    10 // multiplied by 100 pixels per second
        #define MOUSE_ACCELERATION 2  // multiplied by 100 pixels per second
        #define MOUSE_SPEED_DIVISOR 10

        #define AGENT_COMMAND_REENUMERATE 0

    /* Function Prototypes: */
        bool CreateKeyboardHIDReport(void* ReportData, uint16_t* const ReportSize);
        uint8_t GetActiveLayer(void);
        uint8_t ConstructKeyboardReport(uint8_t ActiveLayer, USB_KeyboardReport_Data_t* KeyboardReport, uint16_t* const ReportSize);
        bool CreateMouseHIDReport(void* ReportData, uint16_t* const ReportSize);
        bool CreateGenericHIDReport(void* ReportData, uint16_t* const ReportSize);
        void ProcessGenericHIDReport(const void* ReportData, const uint16_t ReportSize);

#endif
