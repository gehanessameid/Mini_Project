#ifndef BITMATH_H_
#define BITMATH_H_

#define BITMATH_H_



#define SetBit(Reg,BitNo)    Reg|=(1<<BitNo)
#define ClrBit(Reg,BitNo)    Reg&=~(1<<BitNo)
#define TogBit(Reg,BitNo)    Reg^=(1<<BitNo)
#define GetBit(Reg,BitNo)    ((Reg>>BitNo)&1)
#endif
