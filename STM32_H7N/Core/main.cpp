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

//User LED driver classes (driver defined in QAD_GPIO.hpp)
QAD_GPIO_Output* GPIO_UserLED_Green;
QAD_GPIO_Output* GPIO_UserLED_Blue;
QAD_GPIO_Output* GPIO_UserLED_Red;


//Task Timing
//
//These constants are used to determine the update rate (in milliseconds) of each of the
//tasks that are run in the processing loop within the the main() function
//
const uint32_t QA_FT_HeartbeatTickThreshold = 500;   //Time in milliseconds in between heartbeat LED updates
                                                     //The rate of flashing of the heartboard LED will be double the value defined here


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------


//main
//Application entry Point
//
//This is the first C++ function to be called when the microcontroller starts up
//This function is called by the assembly language in startup_stm32h743zitx.s
int main(void) {

	//----------------------------------
	//----------------------------------
  //System Initialization

	//Calls the SystemInitialize method located within boot.hpp, which initializes the
	//CPU caches, as well as the PLLs, system, bus and some peripheral clocks.
	//All GPIO Port and DMA clocks are also enabled by this method
	if (SystemInitialize()) {
		while (1) {}
	}


	//----------------------------------
  //Initialize the User LEDs using the QAD_GPIO_Output driver class
	//QAD_USERLED_**** definitions are defined in setup.hpp
	GPIO_UserLED_Green = new QAD_GPIO_Output(QAD_USERLED_GREEN_GPIO_PORT, QAD_USERLED_GREEN_GPIO_PIN);
	GPIO_UserLED_Blue  = new QAD_GPIO_Output(QAD_USERLED_BLUE_GPIO_PORT, QAD_USERLED_BLUE_GPIO_PIN);
	GPIO_UserLED_Red   = new QAD_GPIO_Output(QAD_USERLED_RED_GPIO_PORT, QAD_USERLED_RED_GPIO_PIN);


	//Test Yellow and Red LEDs
	GPIO_UserLED_Blue->on();
	GPIO_UserLED_Red->on();


	//----------------------------------
	//----------------------------------
	//Processing Loop

	//Create processing loop timing variables
	uint32_t uTicks;
	uint32_t uCurTick;
	uint32_t uNewTick = HAL_GetTick();
	uint32_t uOldTick = uNewTick;

	//Create task timing variables
	uint32_t uHeartbeatTicks;

	//-----------------------------------
  //Infinite loop for device processing
	while (1) {

		//----------------------------------
		//Frame Timing
		//Calculates how many ticks (in milliseconds) have passed since the previous loop, this value is placed into the uTicks variable
		//uTicks is then used to calculate task timing below
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


  	//----------------------------------
    //Update Heartbeat LED
    //The heartbeat LED uses the User LED to flash at a regular rate to visually show whether the microcontroller has locked up or
    //become stuck in an exception or interrupt handler
    uHeartbeatTicks += uTicks;
    if (uHeartbeatTicks >= QA_FT_HeartbeatTickThreshold) {
    	GPIO_UserLED_Green->toggle();
    	uHeartbeatTicks -= QA_FT_HeartbeatTickThreshold;
    }

	}


	//This return value is unused, but is included in the source code to prevent compiler warning that main() doesn't return a value
	return 0;
}

