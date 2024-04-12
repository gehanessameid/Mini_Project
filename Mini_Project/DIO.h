#ifndef DIO_H_
#define DIO_H_

#include "stdTypes.h"

/**DIRECTION***/
void DIO_SelectDirectionForPin(u8 GroupName, u8 PinNumber, u8 DirectionState);
void DIO_SelectDirectionForGroup(u8 GroupName,u8 DirectionState);
//OUTPUT
void DIO_SelectOutputTypeForPin(u8 GroupName,u8 PinNumber, u8 OutputState);
void DIO_SelectOutputTypeForGroup(u8 GroupName, u8 OutputState);
/**INPUT**/
u8 DIO_ReadInputValueForPin(u8 GroupName,u8 PinNumber);
u8 DIO_ReadInputValueForGroup(u8 GroupName);


#endif