/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#define Seg7_A_Pin GPIO_PIN_0
#define Seg7_A_GPIO_Port GPIOA
#define Seg7_B_Pin GPIO_PIN_1
#define Seg7_B_GPIO_Port GPIOA
#define Seg7_C_Pin GPIO_PIN_2
#define Seg7_C_GPIO_Port GPIOA
#define Seg7_D_Pin GPIO_PIN_3
#define Seg7_D_GPIO_Port GPIOA
#define SW2_Pin GPIO_PIN_6
#define SW2_GPIO_Port GPIOA
#define SW2_EXTI_IRQn EXTI9_5_IRQn
#define Seg7_G_Pin GPIO_PIN_7
#define Seg7_G_GPIO_Port GPIOA
#define SW3_Pin GPIO_PIN_2
#define SW3_GPIO_Port GPIOB
#define SW3_EXTI_IRQn EXTI2_IRQn
#define Seg7_F_Pin GPIO_PIN_10
#define Seg7_F_GPIO_Port GPIOB
#define Seg7_E_Pin GPIO_PIN_11
#define Seg7_E_GPIO_Port GPIOB
#define Digit_3_Pin GPIO_PIN_12
#define Digit_3_GPIO_Port GPIOB
#define SW1_Pin GPIO_PIN_13
#define SW1_GPIO_Port GPIOB
#define SW1_EXTI_IRQn EXTI15_10_IRQn
#define Digit_4_Pin GPIO_PIN_14
#define Digit_4_GPIO_Port GPIOB
#define Digit_2_Pin GPIO_PIN_8
#define Digit_2_GPIO_Port GPIOA
#define Seg7_DP_Pin GPIO_PIN_9
#define Seg7_DP_GPIO_Port GPIOA
#define KEY_Pin GPIO_PIN_10
#define KEY_GPIO_Port GPIOA
#define SYS_SWDIO_Pin GPIO_PIN_13
#define SYS_SWDIO_GPIO_Port GPIOA
#define SYS_SWCLK_Pin GPIO_PIN_14
#define SYS_SWCLK_GPIO_Port GPIOA
#define Digit_1_Pin GPIO_PIN_15
#define Digit_1_GPIO_Port GPIOA
#define SYS_SWO_Pin GPIO_PIN_3
#define SYS_SWO_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_5
#define LED_GPIO_Port GPIOB
#define CH340_TX_Pin GPIO_PIN_6
#define CH340_TX_GPIO_Port GPIOB
#define CH340_RX_Pin GPIO_PIN_7
#define CH340_RX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
