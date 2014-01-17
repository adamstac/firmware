#ifndef USART_H
#define USART_H

    /* Includes: */
        #include <avr/io.h>

    /* Macros: */
        #define USART_BAUDRATE 38400
        #define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

        #if defined(__AVR_ATmega88__)
            #define UCSRA UCSR0A
            #define UCSRB UCSR0A
            #define RXEN RXEN0
            #define TXEN TXEN0
            #define UBRRH UBRR0H
            #define UBRRL UBRR0L
            #define UDR UDR0
            #define RXC RXC0
            #define UDRE UDRE0
        #elif defined(__AVR_ATmega32U2__)
            #define UCSRA UCSR1A
            #define UCSRB UCSR1A
            #define RXEN RXEN1
            #define TXEN TXEN1
            #define UBRRH UBRR1H
            #define UBRRL UBRR1L
            #define UDR UDR1
            #define RXC RXC1
            #define UDRE UDRE1
        #endif

    /* Function Prototypes: */
        void USART_Init(void);
        uint8_t USART_HasByte(void);
        uint8_t USART_ReceiveByte(void);
        void USART_SendByte(uint8_t byte);

#endif
