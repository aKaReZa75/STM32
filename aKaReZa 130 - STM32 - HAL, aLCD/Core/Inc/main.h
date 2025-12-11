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
#define __alcd_DB4_Pin GPIO_PIN_7
#define __alcd_DB4_GPIO_Port GPIOA
#define __alcd_DB5_Pin GPIO_PIN_0
#define __alcd_DB5_GPIO_Port GPIOB
#define __alcd_DB6_Pin GPIO_PIN_1
#define __alcd_DB6_GPIO_Port GPIOB
#define __alcd_BL_Pin GPIO_PIN_12
#define __alcd_BL_GPIO_Port GPIOB
#define __alcd_EN_Pin GPIO_PIN_8
#define __alcd_EN_GPIO_Port GPIOA
#define __alcd_DB7_Pin GPIO_PIN_9
#define __alcd_DB7_GPIO_Port GPIOA
#define KEY_Pin GPIO_PIN_10
#define KEY_GPIO_Port GPIOA
#define SYS_SWDIO_Pin GPIO_PIN_13
#define SYS_SWDIO_GPIO_Port GPIOA
#define SYS_SWCLK_Pin GPIO_PIN_14
#define SYS_SWCLK_GPIO_Port GPIOA
#define __alcd_RS_Pin GPIO_PIN_15
#define __alcd_RS_GPIO_Port GPIOA
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
