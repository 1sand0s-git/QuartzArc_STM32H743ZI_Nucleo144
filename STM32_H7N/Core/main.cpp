/* ----------------------------------------------------------------------- */
/*                                                                         */
/*   Quartz Arc                                                            */
/*                                                                         */
/*   STM32 H743ZI Nucleo 144                                               */
/*                                                                         */
/*   System: Core                                                          */
/*   Role: Application Entry Point                                         */
/*   Filename: main.cpp                                                    */
/*   Date: 21st October 2021                                               */
/*   Created By: Benjamin Rosser                                           */
/*                                                                         */
/*   This code is covered by Creative Commons CC-BY-NC-SA license          */
/*   (C) Copyright 2021 Benjamin Rosser                                    */
/*                                                                         */
/* ----------------------------------------------------------------------- */

//Includes
#include "main.hpp"
#include "boot.hpp"

#include "QAD_GPIO.hpp"


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------

//User LEDs
QAD_GPIO_Output* GPIO_Green_UserLED;


//Task Timing
const uint32_t QA_FT_HeartbeatTickThreshold = 500;


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------


//main
//Application entry Point
int main(void) {

	//---------------------
  //System Initialization
	if (SystemInitialize()) {
		while (1) {}
	}

	GPIO_Green_UserLED = new QAD_GPIO_Output(QAD_USERLED_GREEN_GPIO_PORT, QAD_USERLED_GREEN_GPIO_PIN);


	//---------------
	//Processing Loop
	uint32_t uTicks;
	uint32_t uCurTick;
	uint32_t uNewTick = HAL_GetTick();
	uint32_t uOldTick = uNewTick;

	uint32_t uHeartbeatTicks;

	while (1) {

		//Frame Timing
    uCurTick = HAL_GetTick();
    if (uCurTick != uNewTick) { //Handle loop faster than 1ms issue
    	uOldTick = uNewTick;
    	uNewTick = uCurTick;
    	if (uNewTick < uOldTick) { //Handle 32bit overflow issue
    		uTicks = (uNewTick + (0xFFFFFFFF - uOldTick));
    	} else {
    		uTicks = (uNewTick - uOldTick);
    	}

    } else {
    	uTicks = 0;
    }


    //Update Heartbeat LED
    uHeartbeatTicks += uTicks;
    if (uHeartbeatTicks >= QA_FT_HeartbeatTickThreshold) {
    	GPIO_Green_UserLED->toggle();
    	uHeartbeatTicks -= QA_FT_HeartbeatTickThreshold;
    }

	}

	return 0;
}
