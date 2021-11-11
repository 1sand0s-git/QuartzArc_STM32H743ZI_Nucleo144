/* ----------------------------------------------------------------------- */
/*                                                                         */
/*   Quartz Arc                                                            */
/*                                                                         */
/*   STM32 H743ZI Nucleo 144                                               */
/*                                                                         */
/*   System: Core                                                          */
/*   Role: Setup                                                           */
/*   Filename: setup.hpp                                                   */
/*   Date: 21st October 2021                                               */
/*   Created By: Benjamin Rosser                                           */
/*                                                                         */
/*   This code is covered by Creative Commons CC-BY-NC-SA license          */
/*   (C) Copyright 2021 Benjamin Rosser                                    */
/*                                                                         */
/* ----------------------------------------------------------------------- */

//Prevent Recursive Inclusion
#ifndef __SETUP_HPP_
#define __SETUP_HPP_

//Includes
#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------

  //Result Enum
enum QA_Result : uint8_t {
	QA_OK = 0,
	QA_Fail,
	QA_Error_PeriphBusy,
	QA_Error_PeriphNotSupported
};


//Init State Enum
enum QA_InitState : uint8_t {QA_NotInitialized = 0, QA_Initialized};


//Active State Enum
enum QA_ActiveState : uint8_t {QA_Inactive = 0, QA_Active};


	//----------------------------------------
	//----------------------------------------
	//----------------------------------------


//-------------------------------
//QAD_IRQHandler_CallbackFunction
typedef void (*QAD_IRQHandler_CallbackFunction)(void* pData);


//----------------------------
//QAD_IRQHandler_CallbackClass
class QAD_IRQHandler_CallbackClass {
public:

	virtual void handler(void* pData) = 0;
};


	//----------------------------------------
	//----------------------------------------
	//----------------------------------------

	//----------------
	//GPIO Definitions

#define QAD_USERLED_GREEN_GPIO_PORT     GPIOB
#define QAD_USERLED_GREEN_GPIO_PIN      GPIO_PIN_0   // B0

#define QAD_USERLED_YELLOW_GPIO_PORT    GPIOE
#define QAD_USERLED_YELLOW_GPIO_PIN     GPIO_PIN_1   // E1

#define QAD_USERLED_RED_GPIO_PORT       GPIOB
#define QAD_USERLED_RED_GPIO_PIN        GPIO_PIN_14  // B14

#define QAD_USERBUTTON_GPIO_PORT        GPIOC
#define QAD_USERBUTTON_GPIO_PIN         GPIO_PIN_13  // C13


	//-----
	//UART2

/*#define QAD_UART2_TX_PORT     GPIOA
#define QAD_UART2_TX_PIN      GPIO_PIN_2        //A2
#define QAD_UART2_TX_AF       GPIO_AF7_USART2
#define QAD_UART2_RX_PORT     GPIOA
#define QAD_UART2_RX_PIN      GPIO_PIN_3        //A3
#define QAD_UART2_RX_AF       GPIO_AF7_USART2
#define QAD_UART2_BAUDRATE    57600
#define QAD_UART2_TX_FIFOSIZE 256
#define QAD_UART2_RX_FIFOSIZE 256*/


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------

	//----------------------------
	//Interrupt Request Priorities

#define QAD_IRQPRIORITY_UART2    ((uint8_t) 0x08)

#define QAD_IRQPRIORITY_EXTI     ((uint8_t) 0x0A)


//Prevent Recursive Inclusion
#endif /* __SETUP_HPP */
