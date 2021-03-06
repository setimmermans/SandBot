/**************************************************************
 * HTTPPrint.h
 * Provides callback headers and resolution for user's custom
 * HTTP Application.
 * 
 * This file is automatically generated by the MPFS Utility
 * ALL MODIFICATIONS WILL BE OVERWRITTEN BY THE MPFS GENERATOR
 **************************************************************/

#ifndef __HTTPPRINT_H
#define __HTTPPRINT_H

#include "TCPIP Stack/TCPIP.h"

#if defined(STACK_USE_HTTP2_SERVER)

extern HTTP_STUB httpStubs[MAX_HTTP_CONNECTIONS];
extern BYTE curHTTPID;

void HTTPPrint(DWORD callbackID);
void HTTPPrint_led(WORD);
void HTTPPrint_btn(WORD);
void HTTPPrint_pot(void);
void HTTPPrint_MyVideoCounter(void);
void HTTPPrint_TourelleStatus(void);
void HTTPPrint_RightMotorStatus(void);
void HTTPPrint_LeftMotorStatus(void);
void HTTPPrint_var1Status(void);
void HTTPPrint_var2Status(void);
void HTTPPrint_var3Status(void);
void HTTPPrint_var4Status(void);
void HTTPPrint_var5Status(void);
void HTTPPrint_var6Status(void);
void HTTPPrint_var7Status(void);
void HTTPPrint_var8Status(void);
void HTTPPrint_var9Status(void);
void HTTPPrint_var10Status(void);
void HTTPPrint_var11Status(void);
void HTTPPrint_var12Status(void);
void HTTPPrint_var13Status(void);
void HTTPPrint_var14Status(void);
void HTTPPrint_var15Status(void);
void HTTPPrint_var16Status(void);
void HTTPPrint_var17Status(void);
void HTTPPrint_var18Status(void);
void HTTPPrint_var19Status(void);
void HTTPPrint_var20Status(void);
void HTTPPrint_var21Status(void);
void HTTPPrint_var22Status(void);
void HTTPPrint_var23Status(void);
void HTTPPrint_var24Status(void);
void HTTPPrint_var25Status(void);
void HTTPPrint_var26Status(void);
void HTTPPrint_var27Status(void);
void HTTPPrint_var28Status(void);
void HTTPPrint_var29Status(void);
void HTTPPrint_var30Status(void);
void HTTPPrint_var31Status(void);
void HTTPPrint_var32Status(void);
void HTTPPrint_var33Status(void);
void HTTPPrint_var34Status(void);
void HTTPPrint_var35Status(void);
void HTTPPrint_var36Status(void);
void HTTPPrint_var37Status(void);
void HTTPPrint_var38Status(void);
void HTTPPrint_var39Status(void);
void HTTPPrint_var40Status(void);

void HTTPPrint(DWORD callbackID)
{
	switch(callbackID)
	{
        case 0x00000006:
			HTTPPrint_led(7);
			break;
        case 0x00000007:
			HTTPPrint_led(6);
			break;
        case 0x00000008:
			HTTPPrint_led(5);
			break;
        case 0x00000009:
			HTTPPrint_led(4);
			break;
        case 0x0000000a:
			HTTPPrint_led(3);
			break;
        case 0x0000000b:
			HTTPPrint_led(2);
			break;
        case 0x0000000c:
			HTTPPrint_led(1);
			break;
        case 0x00000017:
			HTTPPrint_led(0);
			break;
        case 0x00000018:
			HTTPPrint_btn(0);
			break;
        case 0x00000019:
			HTTPPrint_btn(1);
			break;
        case 0x0000001a:
			HTTPPrint_btn(2);
			break;
        case 0x0000001b:
			HTTPPrint_btn(3);
			break;
        case 0x0000001c:
			HTTPPrint_pot();
			break;
        case 0x0000004c:
			HTTPPrint_MyVideoCounter();
			break;
        case 0x0000004d:
			HTTPPrint_TourelleStatus();
			break;
        case 0x0000004e:
			HTTPPrint_RightMotorStatus();
			break;
        case 0x0000004f:
			HTTPPrint_LeftMotorStatus();
			break;
        case 0x0000005e:
			HTTPPrint_var1Status();
			break;
        case 0x0000005f:
			HTTPPrint_var2Status();
			break;
        case 0x00000060:
			HTTPPrint_var3Status();
			break;
        case 0x00000061:
			HTTPPrint_var4Status();
			break;
        case 0x00000062:
			HTTPPrint_var5Status();
			break;
        case 0x00000063:
			HTTPPrint_var6Status();
			break;
        case 0x00000064:
			HTTPPrint_var7Status();
			break;
        case 0x00000065:
			HTTPPrint_var8Status();
			break;
        case 0x00000066:
			HTTPPrint_var9Status();
			break;
        case 0x00000067:
			HTTPPrint_var10Status();
			break;
        case 0x00000068:
			HTTPPrint_var11Status();
			break;
        case 0x00000069:
			HTTPPrint_var12Status();
			break;
        case 0x0000006a:
			HTTPPrint_var13Status();
			break;
        case 0x0000006b:
			HTTPPrint_var14Status();
			break;
        case 0x0000006c:
			HTTPPrint_var15Status();
			break;
        case 0x0000006d:
			HTTPPrint_var16Status();
			break;
        case 0x0000006e:
			HTTPPrint_var17Status();
			break;
        case 0x0000006f:
			HTTPPrint_var18Status();
			break;
        case 0x00000070:
			HTTPPrint_var19Status();
			break;
        case 0x00000071:
			HTTPPrint_var20Status();
			break;
        case 0x00000072:
			HTTPPrint_var21Status();
			break;
        case 0x00000073:
			HTTPPrint_var22Status();
			break;
        case 0x00000074:
			HTTPPrint_var23Status();
			break;
        case 0x00000075:
			HTTPPrint_var24Status();
			break;
        case 0x00000076:
			HTTPPrint_var25Status();
			break;
        case 0x00000077:
			HTTPPrint_var26Status();
			break;
        case 0x00000078:
			HTTPPrint_var27Status();
			break;
        case 0x00000079:
			HTTPPrint_var28Status();
			break;
        case 0x0000007a:
			HTTPPrint_var29Status();
			break;
        case 0x0000007b:
			HTTPPrint_var30Status();
			break;
        case 0x0000007c:
			HTTPPrint_var31Status();
			break;
        case 0x0000007d:
			HTTPPrint_var32Status();
			break;
        case 0x0000007e:
			HTTPPrint_var33Status();
			break;
        case 0x0000007f:
			HTTPPrint_var34Status();
			break;
        case 0x00000080:
			HTTPPrint_var35Status();
			break;
        case 0x00000081:
			HTTPPrint_var36Status();
			break;
        case 0x00000082:
			HTTPPrint_var37Status();
			break;
        case 0x00000083:
			HTTPPrint_var38Status();
			break;
        case 0x00000084:
			HTTPPrint_var39Status();
			break;
        case 0x00000085:
			HTTPPrint_var40Status();
			break;
		default:
			// Output notification for undefined values
			TCPPutROMArray(sktHTTP, (ROM BYTE*)"!DEF", 4);
	}

	return;
}

void HTTPPrint_(void)
{
	TCPPut(sktHTTP, '~');
	return;
}

#endif

#endif
