/*
 * TurnOnVehicle.c
 *
 *  Created on: Aug 17, 2023
 *      Author: mm929
 */

#include "functions.h"

#define engineTemp 1

enum state{
	OFF, ON
};

struct vehicleState{
	char engineState;
	char AC;
	unsigned int vehicleSpeed;
	int roomTemperature;
	char engineTemperatureController;
	int engineTemperature;
}vehicle = {ON, OFF, 35, 35, OFF, 35};

int currRoomTemp = 35;
#if engineTemp
int currEngineTemp = 35;
#endif

void printVehivleInfo(struct vehicleState * vehicle);
void SetRoomTemp(struct vehicleState * vehicle);
void SetEngineTemp(struct vehicleState * vehicle);
void SetTrafficColor(struct vehicleState * vehicle);


void turnOnVehicle(){
	char inp;

	do{
		printf("a. Turn off the engine \n");
		printf("b. Set the traffic light color. \n");
		printf("c. Set the room temperature (Temperature Sensor) \n");
#if engineTemp
		printf("d. Set the engine temperature (Engine Temperature Sensor) \n");
#endif
		printf("your choice: \t");
		fflush(stdout);
		scanf(" %c",&inp);
		printf("\n");
	}while(inp != 'a' && inp != 'b' && inp != 'c' && inp != 'd');

	switch(inp){

	case 'b':
		SetTrafficColor(&vehicle);
		break;


	case 'c':
		SetRoomTemp(&vehicle);
		break;

	case 'd':
#if engineTemp
		SetEngineTemp(&vehicle);
#else
		printf("Not available..:( \n");
#endif
		turnOnVehicle();
		break;

	case 'a':
		printf("Turn off the vehicle engine \n");
		turnOffEngine();

	}

}

#if engineTemp
void SetEngineTemp(struct vehicleState * vehicle){

	printf("Enter the engine temperature: ");
	fflush(stdout);
	scanf(" %d",&currEngineTemp);
	printf("\n");

	if(currEngineTemp < 100){
		vehicle->engineTemperatureController = ON;
		vehicle->engineTemperature = 125;
		printVehivleInfo(vehicle);
		turnOnVehicle();

	}else if(currEngineTemp > 150){
		vehicle->engineTemperatureController = ON;
		vehicle->engineTemperature = 125;
		printVehivleInfo(vehicle);
		turnOnVehicle();
	}else{
		vehicle->engineTemperatureController = OFF;
		printVehivleInfo(vehicle);
		turnOnVehicle();
	}
}
#endif

void SetRoomTemp(struct vehicleState * vehicle){

	printf("Enter the room temperature: ");
	fflush(stdout);
	scanf(" %d",&currRoomTemp);
	printf("\n");

	if(currRoomTemp < 10){
		vehicle->AC = 1;
		vehicle->roomTemperature = 20;
		printVehivleInfo(vehicle);
		turnOnVehicle();

	}else if(currRoomTemp > 30){
		vehicle->AC = 1;
		vehicle->roomTemperature = 20;
		printVehivleInfo(vehicle);
		turnOnVehicle();
	}else{
		vehicle->AC = OFF;
		printVehivleInfo(vehicle);
		turnOnVehicle();
	}
}


void SetTrafficColor(struct vehicleState * vehicle){

	char color;

	do{
		printf("Enter the required color: ");
		fflush(stdout);
		scanf(" %c",&color);
		printf("\n");
	}while(color != 'g' && color != 'o' && color != 'r');

	switch(color){

	case 'g':
		vehicle->vehicleSpeed = 100;
		printVehivleInfo(vehicle);
		turnOnVehicle();
		break;

	case 'o':
		vehicle->vehicleSpeed = 30;

		if(vehicle->vehicleSpeed == 30){
			vehicle->AC = ON;
			vehicle->roomTemperature = currRoomTemp * (5/4) + 1;
			vehicle->engineTemperatureController = ON;
#if engineTemp
			vehicle->engineTemperature = currEngineTemp * (5/4) + 1;
#endif
		}
		printVehivleInfo(vehicle);
		turnOnVehicle();
		break;

	case 'r':
		vehicle->vehicleSpeed = 0;
		printVehivleInfo(vehicle);
		turnOnVehicle();
	}

}

void printVehivleInfo(struct vehicleState * vehicle){
	printf("Engine is ON \n");
	printf("AC is %s\n", (vehicle->AC == ON)? "ON":"OFF");
	printf("Vehicle Speed: %d Km/Hr\n", vehicle->vehicleSpeed);
	printf("Room Temperature: %d C\n", vehicle->roomTemperature);
	printf("Engine Temperature Controller is %s \n", (vehicle->engineTemperatureController == ON)? "ON":"OFF");
#if engineTemp
	printf("Engine Temperature %d C\n", vehicle->engineTemperature);
#endif
	printf("\n");
}



