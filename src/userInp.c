/*
 * askUser.c
 *
 *  Created on: Aug 17, 2023
 *      Author: mm929
 */
#include "functions.h"


void userInp(){
	char inp;

	do{
		printf("a. Turn on the vehicle engine \n");
		printf("b. Turn off the vehicle engine \n");
		printf("c. Quit the system \n");
		printf("your choice: \t");
		fflush(stdout);
		scanf("  %c",&inp);
		printf("\n");
		//printf("%d \n",inp == 'c');
	}while(inp != 'a' && inp != 'b' && inp != 'c');


	switch(inp){
	case 'c':
		printf("Quit the system \n");
		printf("closing the system... \n");
		return;

	case 'b':
		printf("Turn off the vehicle engine \n");
		turnOffEngine();
		break;

	case 'a':
		printf("Turn on the vehicle engine \n");
		turnOnVehicle();
	}



}
