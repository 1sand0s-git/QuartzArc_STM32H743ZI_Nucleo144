/* ----------------------------------------------------------------------- */
/*                                                                         */
/*   Quartz Arc                                                            */
/*                                                                         */
/*   STM32 H743ZI Nucleo 144                                               */
/*                                                                         */
/*   System: Drivers                                                       */
/*   Role: GPIO Driver                                                     */
/*   Filename: QAD_GPIO.hpp                                                */
/*   Date: 21st October 2021                                               */
/*   Created By: Benjamin Rosser                                           */
/*                                                                         */
/*   This code is covered by Creative Commons CC-BY-NC-SA license          */
/*   (C) Copyright 2021 Benjamin Rosser                                    */
/*                                                                         */
/* ----------------------------------------------------------------------- */

//Prevent Recursive Inclusion
#ifndef __QAD_GPIO_HPP_
#define __QAD_GPIO_HPP_

//Includes
#include "setup.hpp"


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------

//---------------
//QAD_GPIO_Output
class QAD_GPIO_Output {
public:
	enum PinState : uint8_t {PinOff = 0, PinOn};

private:

	GPIO_TypeDef* m_pGPIO;
	uint16_t      m_uPin;

	PinState      m_eState;

public:

	//Constructor / Destructor
	QAD_GPIO_Output() = delete;
	QAD_GPIO_Output(GPIO_TypeDef* pGPIO, uint16_t uPin);
	~QAD_GPIO_Output();

	//Control Methods
	void on(void);
	void off(void);
	void toggle(void);
	PinState getState(void);

};


//--------------
//QAD_GPIO_Input
class QAD_GPIO_Input {
public:
	enum PinState : uint8_t {PinOff = 0, PinOn};

protected:

	GPIO_TypeDef* m_pGPIO;
	uint16_t      m_uPin;

public:

	//Contructor / Destructor
	QAD_GPIO_Input() = delete;
	QAD_GPIO_Input(GPIO_TypeDef* pGPIO, uint16_t uPin);
	~QAD_GPIO_Input();

	//Control Method
	PinState getState(void);

};


//Prevent Recursive Inclusion
#endif /* __QAD_GPIO_HPP */
