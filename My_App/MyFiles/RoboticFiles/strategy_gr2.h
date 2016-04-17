/*!
* \file Strategy_gr2.h
* \brief main header of the strategy
*/

#ifndef _STRATEGY_GR2_H_
#define _STRATEGY_GR2_H_

#include "CtrlStruct_gr2.h"
#include <math.h>
#include "controller_gr2.h"
#include "ctrl_main_gr2.h"
#include "dynamixel_gr2.h"
#ifndef REALBOT
#include "namespace_ctrl.h"
#include <stdlib.h>
#include <cstdio>
NAMESPACE_INIT(ctrlGr2);
#endif // ! REALBOT

#ifdef REALBOT
void	ActivateBase(CtrlStruct *cvs);
void	DisactivateBase(CtrlStruct *cvs);
void	Calibration(CtrlStruct *cvs);
void    PointHomologation(CtrlStruct *cvs);
void    Action1(CtrlStruct *cvs);
void    Action2(CtrlStruct *cvs);
void    DynaTestFunction(CtrlStruct *cvs);
#endif

#ifndef REALBOT
NAMESPACE_CLOSE();
#endif // ! REALBOT

#endif