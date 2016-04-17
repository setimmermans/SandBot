/*! 
 * \file CtrlStruct_gr2.h
 * \brief Controller main structure
 */

#define REALBOT

#ifndef _CTRL_STRUCT_GR2_H_
#define _CTRL_STRUCT_GR2_H_

#ifndef REALBOT
#include "ctrl_io.h"
#include "namespace_ctrl.h"
#include <stdlib.h>

NAMESPACE_INIT(ctrlGr2);
#else
#include "MyApp.h"
#include <math.h>
#endif // !REALBOT

#include <stdbool.h>


#define DEGtoRAD M_PI/180
#define RADtoDEG 180/M_PI
#define VOLTtoDC 100/24

#define RIGHTMOTOR  0
#define LEFTMOTOR   1
#define TOWERMOTOR  2
#ifdef REALBOT
#define RATRMOTOR   3
#define RATLMOTOR   4
#define PINCEMOTOR  5
#define NB_STORE_EDGE 10
#endif //REALBOT

#define BLUE 0
#define RED 1
#define YELLOW 2
#define WHITE  3
#define GREEN 4
#define PINK 5

#define EPSILON 0.000001

#define LIMITACCELERATION 1
#define MAXSPEED 2*M_PI
#define MAXSPEEDROT 30*MAXSPEED

#define KIFLUSHLIMIT 1000
#define MaxGoals 15

#define TOWER_AVERAGING_NUMBER 2
#define TOWER_OUTLIERS_COMPARE 1
#define BEACON_POSITION_TOLERANCE 0.1
#define MAXSPEED_ENNEMYBOT 3
#define NUMBER_WITHOUT_DETECTION_MAX 3
//enum StateCalib {Cal_y_arr, Cal_y_arr2, Cal_y_av, Cal_y_av1, Cal_rot_neg, Cal_x_arr, Cal_x_av, Cal_rot_pos, Action1 };
enum StateCalib {Cal_y_arr, GoToPoint, AlignAngle, Cal_x_arr, ReturnToBase, AlignForBaseAndReturnInIt, Wait}; // GoToBlocOne, AlignBlocOne, TakeBlocOne, BringBlocOne, ReleaseBlockOne, AlignForBlockOne};
enum StateDyna {grap, release};
enum StateVia {backHomeViaBase, backHomeStraight, normalPoint, viaPoint};
enum StateHomologation {PinceCalib, reachViaPoint, AlignWithTheta, ReachBlocs, ClosingPince, GoViaZone, AlignZone, GoInZone, OpeningPince};
enum StateAction1{GoToBlocOne, AlignForBlocOne, TakeBlocOne, BringBlockOne, ReleaseBlockOne, AlignForBlockOne};
enum StateAction2{GoToBlocTwo, AlignForBlocTwo, AvanceForBlockTwo, ReculeForBlockTwo, BringBlockTwoViaPoint, TakeBlocTwo, BringBlockTwo, ReleaseBlockTwo, AlignForBlockTwo};
typedef struct Potential {
	double katt;
	double krep;
	double kFV;
	double FXRob;
	double FYRob;
	double kw;
	double minDistance;
    double thresholdAligned;
} Potential;

typedef struct Odometry {
	double timein;
	int timeDelay;
	double x;
	double y;
	double theta;
    double speedL;
    double speedR;
    double bufferTime;
    double flagBufferPosition;
#ifdef REALBOT
    double clicNumber;
#endif // REALBOT
} Odometry;

typedef struct Parametres {
	double radiusBot;
	double width;
	double lengthTower;
    double wheelRRadius;
    double wheelLRadius;
	double wheelRadius;
	double KpRot;
	double KiRot;
	double totalErrorRot;
	double speedDifThreshold;
	double KiAngleThreshold;
	double rayonBeacon;
    double maxAcceleration;
    bool MotorCommandByHand;
    double PasFiletVisRat;
    double PasFiletVisPince;
} Parametres;

typedef struct Sensors {
	bool uSwitchLeft;
	bool uSwitchRight;
#ifdef REALBOT
    bool uSwitchPinceOut;
    bool uSwitchRatL;
    bool uSwitchRatR; 
#endif // REALBOT
} Sensors;

typedef struct Motor {
	double Kp;
	double Ki;
	double KpPos;
	double Kphi;
	double speed;
	double position;
	double R;
	int reverseRotation;
	double totalError;
	double dutyCycle;
    double previousDutyCycle;
    bool areBrakesEnabled;
	int ID;
#ifdef REALBOT
    int PWMReg; 
    int timerReg;
    int perReg; 
    int brakesMask;
    int SID;
    double clicNumber;
#endif // REALBOT
} Motor;

typedef struct Dyna{
    double timer;
    enum StateDyna stateDyna;
    bool enable;
} Dyna;

typedef struct Rectangle {
	bool isActive;
	double x;
	double y;
	double width;
	double height;
} Rectangle;

typedef struct Circle {
	bool isActive;
	bool hasBeenUpdated;
	double x;
	double y;
	double radius;
} Circle;

typedef struct QuarterOfCircle {
	bool isActive;
	double x;
	double y;
	double radius;
	int quadrant;
} QuarterOfCircle;
typedef struct Obstacles {
	int NumberOfCircles;
	int NumberOfRectangles;
	int NumberOfQuarterOfCircle;
	Circle *CircleList;
	Rectangle *RectangleList;
	QuarterOfCircle *QuarterOfCircleList;
} Obstacles;

typedef struct Points {
	double X;
	double Y;
	bool taken;
} Points;

typedef struct Goals {
	int NumberOfGoals;
	int CurrentGoal;
	int lockState;
	int goalIN;
	int previousGoal;
	int nbr_target_prev;
	double precision;
	double timeIN;
	double maxtimewait;
	bool endParcourt;
	bool backHome;
	bool isblocked;
	bool via;
	bool endConstr;
	bool inConstr;
	bool over;
	Points *ListOfGoals;
} Goals;

typedef struct Tower {
	bool newTurn;
    double tower_pos; 
	double tower_prevPos;
	double last_rising[NB_STORE_EDGE];  
	double last_falling[NB_STORE_EDGE]; 
	int rising_index;  
	int falling_index;
	int nb_rising;  
	int nb_falling; 
	int nb_opponents; 
	double last_rising_fixed[NB_STORE_EDGE];
	double last_falling_fixed[NB_STORE_EDGE];
	int rising_index_fixed;  
	int falling_index_fixed; 
	int nb_rising_fixed;  
	int nb_falling_fixed; 
} Tower;

typedef struct FilterTower {
	int currentIndex;
	int currentCountOutliers;
    int numberWithoutDetection;
	double xList[TOWER_AVERAGING_NUMBER];
	double yList[TOWER_AVERAGING_NUMBER];
	bool detectedVeryClose;
    bool firstInit;
} FilterTower;

typedef struct AllFiltersTower {
	int numberOfEnnemy;
	FilterTower *FilterTowerList;
} AllFiltersTower;

/// Main controller structure
typedef struct CtrlStruct
{
    double previousTimeCAN;
    int robotID;
    double previousTime;
    double timeStep;
    double time;
    double timeOffset;
#ifndef REALBOT
	CtrlIn *inputs;   ///< controller inputs
	CtrlOut *outputs; ///< controller outputs
#endif // !REALBOT
	enum StateCalib stateCalib;
	enum StateVia stateVia;
    enum StateHomologation stateHomologation;
    enum StateAction1 stateAction1;
    enum StateAction2 stateAction2;
	Parametres *Param;
	Potential *Poto;
	Odometry *Odo;
	Sensors *Sensors;
	Motor *MotorR;
	Motor *MotorL;
	Motor *MotorTower;
#ifdef REALBOT
    Motor *MotorRatL;
    Motor *MotorRatR;
    Motor *MotorPince;
    Dyna *DynaLeft;
    Dyna *DynaRight;
#endif // REALBOT
	Obstacles *Obstacles;
	Tower *Tower;
	Goals *Goals;
	AllFiltersTower *AllFiltersTower;
} CtrlStruct;


// function prototypes
#ifndef REALBOT
CtrlStruct* init_CtrlStruct(CtrlIn *inputs, CtrlOut *outputs);
void free_CtrlStruct(CtrlStruct *cvs);

NAMESPACE_CLOSE();
#endif // !REALBOT

#endif
