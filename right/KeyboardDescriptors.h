#ifndef __KEYBOARD_DESCRIPTORS_H__
#define __KEYBOARD_DESCRIPTORS_H__

    /* Includes: */
        #include <LUFA/Drivers/USB/USB.h>

    /* Type Defines: */
        typedef struct
        {
            USB_Descriptor_Configuration_Header_t Config;

            // Generic HID Interface
            USB_Descriptor_Interface_t            HID1_GenericHIDInterface;
            USB_HID_Descriptor_HID_t              HID1_GenericHID;
            USB_Descriptor_Endpoint_t             HID1_ReportINEndpoint;

            // Keyboard HID Interface
            USB_Descriptor_Interface_t            HID2_KeyboardInterface;
            USB_HID_Descriptor_HID_t              HID2_KeyboardHID;
            USB_Descriptor_Endpoint_t             HID2_ReportINEndpoint;

            // Mouse HID Interface
            USB_Descriptor_Interface_t            HID3_MouseInterface;
            USB_HID_Descriptor_HID_t              HID3_MouseHID;
            USB_Descriptor_Endpoint_t             HID3_ReportINEndpoint;
        } Keyboard_USB_Descriptor_Configuration_t;

        enum KeyboardInterfaceDescriptors_t
        {
            INTERFACE_ID_GenericHID = 0, /**< Generic HID interface descriptor ID */
            INTERFACE_ID_Keyboard   = 1, /**< Keyboard interface descriptor ID */
            INTERFACE_ID_Mouse      = 2, /**< Mouse interface descriptor ID */
        };

        enum KeyboardStringDescriptors_t
        {
            STRING_ID_Language     = 0, /**< Supported Languages string descriptor ID (must be zero) */
            STRING_ID_Manufacturer = 1, /**< Manufacturer string ID */
            STRING_ID_Product      = 2, /**< Product string ID */
        };

    /* Macros: */
        /** Endpoint address of the Keyboard HID reporting IN endpoint. */
        #define KEYBOARD_IN_EPADDR        (ENDPOINT_DIR_IN | 1)

        #define KEYBOARD_ROLLOVER         6  // key

        /** Endpoint address of the Mouse HID reporting IN endpoint. */
        #define MOUSE_IN_EPADDR           (ENDPOINT_DIR_IN | 3)

        /** Size in bytes of each of the HID reporting IN endpoints. */
        #define HID_EPSIZE                8

        /** Endpoint address of the Generic HID reporting IN endpoint. */
        #define GENERIC_IN_EPADDR         (ENDPOINT_DIR_IN | 1)

        /** Size in bytes of the Generic HID reporting endpoint. */
        #define GENERIC_EPSIZE            64

    /* Function Prototypes: */
        uint16_t CALLBACK_USB_GetKeyboardDescriptor(const uint16_t wValue,
                                                    const uint8_t wIndex,
                                                    const void** const DescriptorAddress);

#endif
