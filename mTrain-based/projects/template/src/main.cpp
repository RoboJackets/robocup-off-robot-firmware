/**
  ******************************************************************************
  * @file           : main.cpp
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 RoboJackets.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by RoboJackets under Apache License
  * 2.0; You may not use this file except in compliance with the License. You 
  * may obtain a copy of the License at: 
  *                    https://www.apache.org/licenses/LICENSE-2.0
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "mtrain.hpp"

/* Private includes ----------------------------------------------------------*/

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

int sampleFunction(int);

/* Private user code ---------------------------------------------------------*/

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  DigitalOut led1(LED1, PullNone, PushPull);
  DigitalOut led2(LED2, PullNone, PushPull);
  DigitalOut led3(LED3, PullNone, PushPull);
  DigitalOut led4(LED4, PullNone, PushPull);

  uint32_t num = 0;

  /* Infinite loop */
  while (1)
  {
    led1.toggle();
    led4.toggle();
    HAL_Delay(200);
  }

}

/**
  * @brief  Function Description
  * @note Put any Notes Here
  * @param val Sample input argument
  * @retval Returns input argument
  */
int sampleFunction(int val)
{
    return val;
}

