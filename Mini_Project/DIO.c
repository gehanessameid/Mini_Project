#include "stdTypes.h"
#include "bitMath.h"
#include "register.h"
#include "DIO.h"




//IMPELEMENTATION OF FUNCTIONS

void DIO_SelectDirectionForPin(u8 GroupName, u8 PinNumber, u8 DirectionState)



{
	if(GroupName>=DIO_GroupA && GroupName<=DIO_GroupD)
	{
		if(PinNumber>=DIO_Pin0 && PinNumber<=DIO_Pin7)
		{
			if(DirectionState==Input){
				switch(GroupName){
				case DIO_GroupA: ClrBit(DIO_DDRA,PinNumber); break;
				case DIO_GroupB: ClrBit(DIO_DDRB,PinNumber); break;
				case DIO_GroupC: ClrBit(DIO_DDRC,PinNumber); break;
				case DIO_GroupD: ClrBit(DIO_DDRD,PinNumber); break;
				}
			}

		}
		else if(DirectionState==Output)
		{
			switch(GroupName)
			{
			case DIO_GroupA: SetBit(DIO_DDRA,PinNumber); break;
			case DIO_GroupB: SetBit(DIO_DDRB,PinNumber); break;
			case DIO_GroupC: SetBit(DIO_DDRC,PinNumber); break;
			case DIO_GroupD: SetBit(DIO_DDRD,PinNumber); break;
			}


		}
	}
}
void DIO_SelectOutputTypeForPin(u8 GroupName,u8 PinNumber, u8 OutputState)
{
	if(GroupName>=DIO_GroupA && GroupName<=DIO_GroupD)
	{
		if(PinNumber>=DIO_Pin0 && PinNumber<=DIO_Pin7)
		{
			if(OutputState==Low){
				switch(GroupName)
				{
				case DIO_GroupA: ClrBit(DIO_PORTA,PinNumber); break;
				case DIO_GroupB: ClrBit(DIO_PORTB,PinNumber); break;
				case DIO_GroupC: ClrBit(DIO_PORTC,PinNumber); break;
				case DIO_GroupD: ClrBit(DIO_PORTD,PinNumber); break;
				}
			}
		}
		else if(OutputState==High)
		{
			switch(GroupName)
			{
			case DIO_GroupA: SetBit(DIO_PORTA,PinNumber); break;
			case DIO_GroupB: SetBit(DIO_PORTB,PinNumber); break;
			case DIO_GroupC: SetBit(DIO_PORTC,PinNumber); break;
			case DIO_GroupD: SetBit(DIO_PORTD,PinNumber); break;
			}
		}
	}
}

u8 DIO_ReadInputValueForPin(u8 GroupName,u8 PinNumber)
{
	u8 res=0;
	if(GroupName>=DIO_GroupA && GroupName<=DIO_GroupD)
	{
		if(PinNumber>=DIO_Pin0 && PinNumber<=DIO_Pin7)
		{
			switch(GroupName)
			{
			case DIO_GroupA: res = GetBit(DIO_PINA,PinNumber);break;
			case DIO_GroupB: res =GetBit(DIO_PINB,PinNumber);break;
			case DIO_GroupC: res =GetBit(DIO_PINC,PinNumber);break;
			case DIO_GroupD: res =GetBit(DIO_PIND,PinNumber);break;
			}
		}
	}
	return res;

}


void DIO_SelectDirectionForGroup(u8 GroupName,u8 DirectionState)
{
	if(GroupName>=DIO_GroupA && GroupName<=DIO_GroupD)
	{
		if(DirectionState<=MaxValue &&DirectionState>=MinValue)
		{
			switch(GroupName)
			{
			case DIO_GroupA:  DIO_DDRA=DirectionState; break;
			case DIO_GroupB:  DIO_DDRB=DirectionState; break;
			case DIO_GroupC:  DIO_DDRC=DirectionState; break;
			case DIO_GroupD:  DIO_DDRD=DirectionState; break;
			}
		}
	}
}
void DIO_SelectOutputTypeForGroup(u8 GroupName, u8 OutputState)
{
	if(GroupName>=DIO_GroupA && GroupName<=DIO_GroupD)
	{
		if(OutputState<=MaxValue &&OutputState>=MinValue)
		{

			switch(GroupName)
			{
			case DIO_GroupA: DIO_PORTA=OutputState; break;
			case DIO_GroupB:  DIO_PORTB=OutputState; break;
			case DIO_GroupC:  DIO_PORTC=OutputState; break;
			case DIO_GroupD:  DIO_PORTD=OutputState; break;
			}
		}
	}


}
u8 DIO_ReadInputValueForGroup(u8 GroupName)
{
	u8 Result=0;
	if(GroupName>=DIO_GroupA && GroupName<=DIO_GroupD)
	{
		switch (GroupName){

		 case DIO_GroupA: Result=DIO_PINA; break;
		 case DIO_GroupB: Result=DIO_PINB; break;
		 case DIO_GroupC: Result=DIO_PINC; break;
		 case DIO_GroupD: Result=DIO_PIND; break;
		}
	}
	return Result;
}
