/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define up_Pin GPIO_PIN_0
#define up_GPIO_Port GPIOB
#define up_EXTI_IRQn EXTI0_IRQn
#define start_Pin GPIO_PIN_1
#define start_GPIO_Port GPIOB
#define start_EXTI_IRQn EXTI1_IRQn
#define speed_Pin GPIO_PIN_10
#define speed_GPIO_Port GPIOB
#define speed_EXTI_IRQn EXTI15_10_IRQn
#define down_Pin GPIO_PIN_3
#define down_GPIO_Port GPIOB
#define down_EXTI_IRQn EXTI3_IRQn
#define right_Pin GPIO_PIN_4
#define right_GPIO_Port GPIOB
#define right_EXTI_IRQn EXTI4_IRQn
#define left_Pin GPIO_PIN_5
#define left_GPIO_Port GPIOB
#define left_EXTI_IRQn EXTI9_5_IRQn

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
