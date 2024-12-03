/*
 * LCD.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mahmoud Ezzat
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

void HLCD_voidSendCommand(u8 A_u8Cmd);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidInit();
void HLCD_voidGoTo(u8 A_u8Row, u8 A_u8Col);
void HLCD_voidClearScreen();
void HLCD_voidSendString(const char *str);

#endif /* HAL_LCD_H_ */
