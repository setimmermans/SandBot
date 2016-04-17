/*******************************************************************************
* Header file for MyCyclone                                                    *
*******************************************************************************/

// SPI frame = 1 opcode (R/W bit + 7-bit address) + 1 data byte
//
// Registers Definition :
//
// 00 - R/W : Config: Enable INT, IO_A/B, IO_C/D, CAN
// 01 - R   : Status : KEY, SW
// 02 - R/W : Led70 : LED
// 10 - R/W : IO_A_Data
// 11 - R/W : IO_A_Enable_Out
// 20 - R/W : IO_B_Data
// 21 - R/W : IO_B_Enable_Out
// 30 - R/W : IO_C_Data
// 31 - R/W : IO_C_Enable_Out
// 40 - R/W : IO_D_Data
// 41 - R/W : IO_D_Enable_Out
//
// Config : Bit0 = 1 : Enable INT1 for KEY0
//          Bit1 = 1 : Enable INT2 for KEY1
//          Bit2 = 1 : Reserved
//          Bit3 = 1 : Reserved
//          Bit4 = 1 : Enable IO_A and IO_B (GPIO_10)
//          Bit5 = 1 : Enable IO_C and IO_D (GPIO_33)
//          Bit6 = 1 : Enable CAN
//          Bit7 = 1 : Reserved
//
// Status : Bit0 = KEY0
//          Bit1 = KEY1
//          Bit2 = 0
//          Bit3 = 0
//          Bit4 = SW0
//          Bit5 = SW1
//          Bit6 = SW2
//          Bit7 = SW3


#ifndef MyCYCLONE_H_
#define MyCYCLONE_H_

#define CYCLONE_CONFIG          0x00
#define CYCLONE_STATUS          0x01
#define CYCLONE_LED70           0x02
#define CYCLONE_IO_A_Data       0x10
#define CYCLONE_IO_A_Enable_Out 0x11
#define CYCLONE_IO_B_Data       0x12
#define CYCLONE_IO_B_Enable_Out 0x13
#define CYCLONE_IO_C_Data       0x14
#define CYCLONE_IO_C_Enable_Out 0x15
#define CYCLONE_IO_D_Data       0x16
#define CYCLONE_IO_D_Enable_Out 0x17
#define CYCLONE_IO_E_Data       0x18
#define CYCLONE_IO_E_Enable_Out 0x19
#define CYCLONE_IO_F_Data       0x20
#define CYCLONE_IO_F_Enable_Out 0x21
#define CYCLONE_IO_G_Data       0x22
#define CYCLONE_IO_G_Enable_Out 0x23
#define CYCLONE_IO_H_Data       0x24
#define CYCLONE_IO_H_Enable_Out 0x25
#define CYCLONE_IO_I_Data       0x26
#define CYCLONE_IO_I_Enable_Out 0x27
#define CYCLONE_IO_J_Data       0x28
#define CYCLONE_IO_J_Enable_Out 0x29
#define CYCLONE_IO_K_Data       0x30
#define CYCLONE_IO_K_Enable_Out 0x31
#define CYCLONE_IO_L_Data       0x32
#define CYCLONE_IO_L_Enable_Out 0x33
#define CYCLONE_IO_M_Data       0x34
#define CYCLONE_IO_M_Enable_Out 0x35

#define CYCLONE_ENABLE_INT_KEY0 0x01
#define CYCLONE_ENABLE_INT_KEY1 0x02
#define CYCLONE_RESERVED_1      0x04
#define CYCLONE_RESERVED_2      0x08
#define CYCLONE_ENABLE_IO_AB    0x10
#define CYCLONE_ENABLE_IO_CD    0x20
#define CYCLONE_ENABLE_CAN      0x40
#define CYCLONE_RESERVED_3      0x80


/*******************************************************************************
* Functions Prototypes                                                         *
*******************************************************************************/

void            MyCyclone_Init(void);
void            MyCyclone_Write(unsigned int theAddress, unsigned int theData);
unsigned int    MyCyclone_Read(unsigned int theAddress);

#endif /* MyCYCLONE_H_ */

