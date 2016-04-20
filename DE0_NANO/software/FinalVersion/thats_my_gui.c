/*
 * thats_my_gui.c
 *
 *  Created on: 5 avr. 2016
 *      Author: Vianney Lechien
 */

/* Includes */
#include "thats_my_gui.h"


void my_GUI_ShowWelcome(alt_video_display *pDisplay){
	int x, y;


	x = 5;
	y = pDisplay->height / 2 - 10;

	vid_print_string_alpha(x, y, BLACK_24, CYAN_24, tahomabold_20, pDisplay, "Team Mr. Sandbot :");
	vid_print_string_alpha(x, y+22, BLACK_24, CYAN_24, tahomabold_20, pDisplay, "Welcome in the brain");
	vid_print_string_alpha(x, y+44, BLACK_24, CYAN_24, tahomabold_20, pDisplay, "of Mr. Sandbot");
}

//----------------------------------------------------------------------------------------------------

void Set_Menu(alt_video_display *pDisplay, TwoRect *Menu, alt_u32 *Color){

	int left = (pDisplay->width - 180) / 2;
	int right = left + 180;
	int top = (pDisplay->height / 4) - 40;
	int bottom = top + 80;
	int verticalOffset = pDisplay->height /3;

	RectSet(&Menu->rcUp, left, right, top, bottom);
	RectSet(&Menu->rcDown, left, right, top + verticalOffset , bottom + verticalOffset );
	RectSet(&Menu->rcreset, 10, left + 60, pDisplay->height - 60, pDisplay->height - 10);
	RectSet(&Menu->rcback, pDisplay->width - 70, pDisplay->width - 10, pDisplay->height - 60, pDisplay->height - 10);

	Menu->UpColor = Color[0];
	Menu->UpEdgeColor = Color[1];
	Menu->DownColor = Color[2];
	Menu->DownEdgeColor = Color[3];
}

//----------------------------------------------------------------------------------------------------

void Finish(alt_video_display *pDisplay, char *Message, alt_u32 Color, FinishRect *Menu){
	int left = (pDisplay->width - 180) / 2;
	int right = left + 180;
	int top = (pDisplay->height / 2) - 40;
	int bottom = top + 80;

	RectSet(&Menu->rc, left, right, top, bottom);
	RectSet(&Menu->rcreset, 10, left + 60, pDisplay->height - 60, pDisplay->height - 10);
	RectSet(&Menu->rcback, pDisplay->width - 70, pDisplay->width - 10, pDisplay->height - 60, pDisplay->height - 10);


	vid_draw_box (left, top, right, bottom, Color , DO_NOT_FILL, pDisplay);
	vid_draw_box (Menu->rcback.left, Menu->rcback.top, Menu->rcback.right, Menu->rcback.bottom, BLACK_24, DO_NOT_FILL, pDisplay);
	vid_draw_box (Menu->rcreset.left, Menu->rcreset.top, Menu->rcreset.right, Menu->rcreset.bottom, BLACK_24, DO_NOT_FILL, pDisplay);

	vid_print_string_alpha(left+50, top + (80 - 22) / 2, Color, CYAN_24, tahomabold_20, pDisplay, Message);
	vid_print_string_alpha(Menu->rcback.left+4, Menu->rcback.top+(RectHeight(&Menu->rcback)-22)/2, BLACK_24, CYAN_24, tahomabold_20, pDisplay, "back");
	vid_print_string_alpha(Menu->rcreset.left+4, Menu->rcreset.top+(RectHeight(&Menu->rcreset)-22)/2, BLACK_24, CYAN_24, tahomabold_20, pDisplay, "reset");
}

//----------------------------------------------------------------------------------------------------

void Draw_Menu(alt_video_display *pDisplay, TwoRect *Menu, char *UpMessage, char *DownMessage){
	vid_draw_box (Menu->rcUp.left  , Menu->rcUp.top  , Menu->rcUp.right  , Menu->rcUp.bottom  , Menu->UpEdgeColor  , DO_NOT_FILL, pDisplay);
	vid_draw_box (Menu->rcDown.left, Menu->rcDown.top, Menu->rcDown.right, Menu->rcDown.bottom, Menu->DownEdgeColor, DO_NOT_FILL, pDisplay);
	vid_draw_box (Menu->rcback.left, Menu->rcback.top, Menu->rcback.right, Menu->rcback.bottom, BLACK_24, DO_NOT_FILL, pDisplay);
	vid_draw_box (Menu->rcreset.left, Menu->rcreset.top, Menu->rcreset.right, Menu->rcreset.bottom, BLACK_24, DO_NOT_FILL, pDisplay);

	vid_print_string_alpha(Menu->rcUp.left+8  , Menu->rcUp.top+(RectHeight(&Menu->rcUp)-22)/2    , Menu->UpColor  , CYAN_24, tahomabold_20, pDisplay, UpMessage);
	vid_print_string_alpha(Menu->rcDown.left+8, Menu->rcDown.top+(RectHeight(&Menu->rcDown)-22)/2, Menu->DownColor, CYAN_24, tahomabold_20, pDisplay, DownMessage);
	vid_print_string_alpha(Menu->rcback.left+4, Menu->rcback.top+(RectHeight(&Menu->rcback)-22)/2, BLACK_24, CYAN_24, tahomabold_20, pDisplay, "back");
	vid_print_string_alpha(Menu->rcreset.left+4, Menu->rcreset.top+(RectHeight(&Menu->rcreset)-22)/2, BLACK_24, CYAN_24, tahomabold_20, pDisplay, "reset");
}

//----------------------------------------------------------------------------------------------------

void Draw_BackGround(alt_video_display *pDisplay){
	vid_clean_screen(pDisplay, CYAN_24);
	int Hcenter = 0;
	int Vcenter = 0;
	int radius = 50;
	int color = YELLOW_24;
	char fill = DO_FILL;
	vid_draw_circle(Hcenter, Vcenter, radius, color, fill, pDisplay);
}

//----------------------------------------------------------------------------------------------------

void my_GUI(alt_video_display *pDisplay, TOUCH_HANDLE *pTouch){
	// video
	int X, Y, Xold, Yold;
	POINT Pt;
	TwoRect rectMenu;
	TwoRect CalibMenu;
	TwoRect ColorMenu;
	FinishRect FinishMenu;
	StateMenu State = StateFisrtMenu;
	int lastState;

	alt_u32 ColorFisrt[4]  = {BLACK_24, BLACK_24, BLACK_24, BLACK_24};
	alt_u32 ColorCalib[4]  = {BLACK_24, BLACK_24, BLACK_24, BLACK_24};
	alt_u32 ColorChoose[4] = {BLACK_24, BLACK_24, BLACK_24, BLACK_24};


	Draw_BackGround(pDisplay);// clean screen

	// Show Welcome Message
	my_GUI_ShowWelcome(pDisplay);
	usleep(1*1000*1000);
	vid_clean_screen(pDisplay, CYAN_24);

	// Set different menus
	Set_Menu(pDisplay, &rectMenu,  ColorFisrt);
	Set_Menu(pDisplay, &CalibMenu, ColorCalib);
	Set_Menu(pDisplay, &ColorMenu, ColorChoose);

	// Draw first menu
	Draw_BackGround(pDisplay);// clean screen
	Draw_Menu(pDisplay, &rectMenu, "Calibration", "Choose Color");

	Xold = 0;
	Yold = 0;
	X = 0;
	Y = 0;

	while(1){
		Touch_GetXY(pTouch, &X, &Y);
		if(fabs(Xold - X) >= 5 && fabs(Yold - Y) >= 5){
			Xold = X;
			Yold = Y;
			printf("x=%d, y=%d\r\n", X,Y);
			PtSet(&Pt, X, Y);
			switch(State){
			case(StateFisrtMenu):
									if (IsPtInRect(&Pt, &rectMenu.rcUp)){
										State = StateCalibMenu;
										lastState = StateFisrtMenu;
										Draw_BackGround(pDisplay);// clean screen
										Draw_Menu(pDisplay, &CalibMenu, "X et Theta", "Y et Theta");
									}
									else if(IsPtInRect(&Pt, &rectMenu.rcDown)){
										State = StateChooseColorMenu;
										lastState = StateFisrtMenu;
										Draw_BackGround(pDisplay);// clean screen
										Draw_Menu(pDisplay, &ColorMenu, "Green", "Violet");
									}
									else if(IsPtInRect(&Pt, &rectMenu.rcreset) || IsPtInRect(&Pt, &rectMenu.rcback)){
										State = StateFisrtMenu;
										lastState = StateFisrtMenu;
										Draw_BackGround(pDisplay);// clean screen
										Draw_Menu(pDisplay, &rectMenu, "Calibration", "Choose Color");
										IOWR(LED_CTRL_BASE, 0x0, 0x01);
									}
			break;

			case(StateCalibMenu):
								if (IsPtInRect(&Pt, &CalibMenu.rcUp)){
									State = StateFinish;
									lastState = StateCalibMenu;
									Draw_BackGround(pDisplay);// clean screen
									Finish(pDisplay, "X et Theta", CYAN_24, &FinishMenu);
									IOWR(LED_CTRL_BASE, 0x0, 0x02);
								}
								else if(IsPtInRect(&Pt, &CalibMenu.rcDown)){
									State = StateFinish;
									lastState = StateCalibMenu;
									Draw_BackGround(pDisplay);// clean screen
									Finish(pDisplay, "Y et Theta", CYAN_24, &FinishMenu);
									IOWR(LED_CTRL_BASE, 0x0, 0x03);
								}
								else if(IsPtInRect(&Pt, &CalibMenu.rcreset)){
									State = StateFisrtMenu;
									lastState = StateCalibMenu;
									Draw_BackGround(pDisplay);// clean screen
									Draw_Menu(pDisplay, &rectMenu, "Calibration", "Choose Color");
									IOWR(LED_CTRL_BASE, 0x0, 0x01);
								}
								else if(IsPtInRect(&Pt, &CalibMenu.rcback)){
									State = StateFisrtMenu;
									lastState = StateCalibMenu;
									Draw_BackGround(pDisplay);// clean screen
									Draw_Menu(pDisplay, &rectMenu, "Calibration", "Choose Color");
								}
			break;

			case(StateChooseColorMenu):
								if (IsPtInRect(&Pt, &ColorMenu.rcUp)){
									State = StateFinish;
									lastState = StateChooseColorMenu;
									Draw_BackGround(pDisplay);// clean screen
									Finish(pDisplay, "GREEN", GREEN_24, &FinishMenu);
									IOWR(LED_CTRL_BASE, 0x0, 0x04);
								}
								else if(IsPtInRect(&Pt, &ColorMenu.rcDown)){
									State = StateFinish;
									lastState = StateChooseColorMenu;
									Draw_BackGround(pDisplay);// clean screen
									Finish(pDisplay, "VIOLET", VIOLET_24, &FinishMenu);
									IOWR(LED_CTRL_BASE, 0x0, 0x05);
								}
								else if(IsPtInRect(&Pt, &ColorMenu.rcreset)){
									State = StateFisrtMenu;
									lastState = StateChooseColorMenu;
									Draw_BackGround(pDisplay);// clean screen
									Draw_Menu(pDisplay, &rectMenu, "Calibration", "Choose Color");
									IOWR(LED_CTRL_BASE, 0x0, 0x01);
								}
								else if(IsPtInRect(&Pt, &ColorMenu.rcback)){
									State = StateFisrtMenu;
									lastState = StateChooseColorMenu;
									Draw_BackGround(pDisplay);// clean screen
									Draw_Menu(pDisplay, &rectMenu, "Calibration", "Choose Color");
								}
			break;
			case(StateFinish):
								if(IsPtInRect(&Pt, &FinishMenu.rcreset)){
									State = StateFisrtMenu;
									Draw_BackGround(pDisplay);// clean screen
									Draw_Menu(pDisplay, &rectMenu, "Calibration", "Choose Color");
									IOWR(LED_CTRL_BASE, 0x0, 0x01);
								}
								else if(IsPtInRect(&Pt, &FinishMenu.rcback)){
									State = lastState;
									Draw_BackGround(pDisplay);// clean screen
									if(State == StateChooseColorMenu){
										Draw_Menu(pDisplay, &ColorMenu, "Green", "Violet");
									}
									else if(State == StateCalibMenu){
										Draw_Menu(pDisplay, &CalibMenu, "X et Theta", "Y et Theta");
									}
								}
			break;

			default:
				IOWR(LED_CTRL_BASE, 0x0, 0x01);
				break;

			} // switch
		} // if touch
	} // while
}
