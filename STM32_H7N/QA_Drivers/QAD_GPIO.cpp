/* ----------------------------------------------------------------------- */
/*                                                                         */
/*   Quartz Arc                                                            */
/*                                                                         */
/*   STM32 H743ZI Nucleo 144                                               */
/*                                                                         */
/*   System: Drivers                                                       */
/*   Role: GPIO Driver                                                     */
/*   Filename: QAD_GPIO.cpp                                                */
/*   Date: 21st October 2021                                               */
/*   Created By: Benjamin Rosser                                           */
/*                                                                         */
/*   This code is covered by Creative Commons CC-BY-NC-SA license          */
/*   (C) Copyright 2021 Benjamin Rosser                                    */
/*                                                                         */
/* ----------------------------------------------------------------------- */

//Includes
#include "QAD_GPIO.hpp"


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------

  //---------------
  //---------------
  //QAD_GPIO_Output

//QAD_GPIO_Output::QAD_GPIO_Output
//QAD_GPIO_Output Constructor
QAD_GPIO_Output::QAD_GPIO_Output(GPIO_TypeDef* pGPIO, uint16_t uPin) :
	m_pGPIO(pGPIO), m_uPin(uPin), m_eState(PinOff) {

	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Pin    = m_uPin;
	GPIO_Init.Mode   = GPIO_MODE_OUTPUT_PP;
	GPIO_Init.Pull   = GPIO_NOPULL;
	GPIO_Init.Speed  = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(m_pGPIO, &GPIO_Init);
}


//QAD_GPIO_Output::~QAD_GPIO_Output
//QAD_GPIO_Output Destructor
QAD_GPIO_Output::~QAD_GPIO_Output() {

	HAL_GPIO_DeInit(m_pGPIO, m_uPin);
}


//QAD_GPIO_Output::on
//QAD_GPIO_Output Control Method
void QAD_GPIO_Output::on(void) {
	HAL_GPIO_WritePin(m_pGPIO, m_uPin, GPIO_PIN_SET);
	m_eState = PinOn;
}


//QAD_GPIO_Output::off
//QAD_GPIO_Output Control Method
void QAD_GPIO_Output::off(void) {
	HAL_GPIO_WritePin(m_pGPIO, m_uPin, GPIO_PIN_RESET);
	m_eState = PinOff;
}


//QAD_GPIO_Output::toggle
//QAD_GPIO_Output Control Method
void QAD_GPIO_Output::toggle(void) {
  if (m_eState) {
  	off();
  } else {
  	on();
  }
}


//QAD_GPIO_Output::getState
//QAD_GPIO_Output Control Method
QAD_GPIO_Output::PinState QAD_GPIO_Output::getState(void) {
  return m_eState;
}


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------

  //--------------
  //--------------
  //QAD_GPIO_Input

//QAD_GPIO_Input::QAD_GPIO_Input
//QAD_GPIO_Input Constructor
QAD_GPIO_Input::QAD_GPIO_Input(GPIO_TypeDef* pGPIO, uint16_t uPin) :
		m_pGPIO(pGPIO), m_uPin(uPin) {

	GPIO_InitTypeDef GPIO_Init;
	GPIO_Init.Pin    = m_uPin;
	GPIO_Init.Mode   = GPIO_MODE_INPUT;
	GPIO_Init.Pull   = GPIO_NOPULL;
	GPIO_Init.Speed  = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(m_pGPIO, &GPIO_Init);
}


//QAD_GPIO_Input::~QAD_GPIO_Input
//QAD_GPIO_Input Destructor
QAD_GPIO_Input::~QAD_GPIO_Input() {

	HAL_GPIO_DeInit(m_pGPIO, m_uPin);
}

//QAD_GPIO_Input::getState
//QAD_GPIO_Input Control Method
QAD_GPIO_Input::PinState QAD_GPIO_Input::getState(void) {
	return (HAL_GPIO_ReadPin(m_pGPIO, m_uPin) == GPIO_PIN_SET) ? PinOn : PinOff;
}
