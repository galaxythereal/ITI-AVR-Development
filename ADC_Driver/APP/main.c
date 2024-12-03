

#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
#include"../MCAL/DIO/DIO_Interface.h"
#include"../HAL/LCD/LCD.h"
#include<util/delay.h>
#include"../MCAL/GIE/GIE_Interface.h"
#include"../MCAL/EXTI/EXTI_Interface.h"
#include"../MCAL/ADC/ADC_Interface.h"
#include<stdio.h>


#define LM35_CHANNEL 0 // ADC channel for LM35 sensor (e.g., ADC0)
#define LM35_VREF    5.0 // LM35 operating voltage (5V)

void LM35_Init(void) {
    MADC_voidInit(1); // Set reference voltage to AVCC (5V)
}

float LM35_ReadTemperature(void) {

    u16 adcValue = MADC_u8GetChannelReading(LM35_CHANNEL);
    float voltage = ((float)adcValue / 1024.0) * LM35_VREF;
    float temperature = (voltage - 0.5) * 100.0; // LM35 temperature calculation
    return temperature;
}

int main(void) {
    // Initialize LM35 sensor and ADC
    LM35_Init();
    MDIO_voidSetPortDirection('C',0xFF);
    MDIO_voidSetPortDirection('D',0xFF);
    // Initialize LCD
    HLCD_voidInit();

    // Main loop
    while (1) {
        // Read temperature from LM35 sensor
        float tempCelsius = LM35_ReadTemperature();

        // Convert temperature to a string
        char tempStr[10];
        snprintf(tempStr, sizeof(tempStr), "%.2f C", tempCelsius);

        // Display temperature on LCD
        HLCD_voidClearScreen();
        HLCD_voidGoTo(0, 0);
        HLCD_voidSendString("Temperature:");
        _delay_ms(1000);
        HLCD_voidGoTo(1, 0);
        _delay_ms(1000);
        HLCD_voidSendString(tempStr);

        // Delay for stability
        _delay_ms(1000);
    }

    return 0;
}
