/* ----------------------------------------------------------------------- */
/*                                                                         */
/*   Quartz Arc                                                            */
/*                                                                         */
/*   STM32 H743ZI Nucleo 144                                               */
/*                                                                         */
/*   System: Core                                                          */
/*   Role: System Initialization                                           */
/*   Filename: boot.cpp                                                    */
/*   Date: 21st October 2021                                               */
/*   Created By: Benjamin Rosser                                           */
/*                                                                         */
/*   This code is covered by Creative Commons CC-BY-NC-SA license          */
/*   (C) Copyright 2021 Benjamin Rosser                                    */
/*                                                                         */
/* ----------------------------------------------------------------------- */

//Includes
#include "boot.hpp"


	//------------------------------------------
	//------------------------------------------
	//------------------------------------------

  //------------------------------
  //System Initialization Function


//SystemInitialize
//System Initialization Function
QA_Result SystemInitialize(void) {

  //-----------------------
  //Enable Cache & Prefetch
  SCB_EnableICache();
  SCB_EnableDCache();


  //--------------------------
  //Set NVIC Priority Grouping
  HAL_NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);


  //------------
	//Init SysTick
	if (HAL_InitTick(TICK_INT_PRIORITY) != HAL_OK)
		return QA_Fail;


  //----------------------------------
  //Configure Internal Power Regulator
	HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);
  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}


  //---------------------
  //Configure Oscillators
  RCC_OscInitTypeDef RCC_OscInit = {0};
  RCC_OscInit.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInit.HSEState       = RCC_HSE_BYPASS;
  RCC_OscInit.PLL.PLLState   = RCC_PLL_ON;
  RCC_OscInit.PLL.PLLSource  = RCC_PLLSOURCE_HSE;
  RCC_OscInit.PLL.PLLM       = 1;
  RCC_OscInit.PLL.PLLN       = 120;
  RCC_OscInit.PLL.PLLP       = 2;
  RCC_OscInit.PLL.PLLQ       = 20;
  RCC_OscInit.PLL.PLLR       = 2;
  RCC_OscInit.PLL.PLLRGE     = RCC_PLL1VCIRANGE_3;
  RCC_OscInit.PLL.PLLVCOSEL  = RCC_PLL1VCOWIDE;
  RCC_OscInit.PLL.PLLFRACN   = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInit) != HAL_OK) {
    return QA_Fail;
  }


  //-------------------
  //Enable SysCfg Clock
//  __HAL_RCC_SYSCFG_CLK_ENABLE();


  //--------------------------
  //Configure CPU & Bus Clocks
  RCC_ClkInitTypeDef RCC_ClkInit = {0};
  RCC_ClkInit.ClockType      = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
  		                         RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 |
															 RCC_CLOCKTYPE_D3PCLK1 | RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInit.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInit.SYSCLKDivider  = RCC_SYSCLK_DIV1;
  RCC_ClkInit.AHBCLKDivider  = RCC_HCLK_DIV2;
  RCC_ClkInit.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInit.APB2CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInit.APB3CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInit.APB4CLKDivider = RCC_HCLK_DIV2;
  if (HAL_RCC_ClockConfig(&RCC_ClkInit, FLASH_LATENCY_4) != HAL_OK) {
  	return QA_Fail;
  }


  //------------------
  //Enable GPIO Clocks
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOJ_CLK_ENABLE();
  __HAL_RCC_GPIOK_CLK_ENABLE();



  //Return
  return QA_OK;
}



