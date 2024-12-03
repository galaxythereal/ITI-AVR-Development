/*
 * LCD.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mahmoud Ezzat
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD_Config.h"
#define LCD_CMD_CLEAR_DISPLAY	             0x01
#define LCD_CMD_CURSOR_HOME		             0x02

// Display control
#define LCD_CMD_DISPLAY_OFF                0x08
#define LCD_CMD_DISPLAY_NO_CURSOR          0x0c
#define LCD_CMD_DISPLAY_CURSOR_NO_BLINK    0x0E
#define LCD_CMD_DISPLAY_CURSOR_BLINK       0x0F

// Function set
#define LCD_CMD_4BIT_2ROW_5X7              0x28
#define LCD_CMD_8BIT_2ROW_5X7              0x38

void HLCD_voidSendCommand(u8 A_u8Cmd);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidInit();
void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col);
void HLCD_voidClearScreen();
void HLCD_voidSendString();

#endif /* HAL_LCD_H_ */
