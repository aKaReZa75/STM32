/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "akareza.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
const uint8_t Seg7_cc[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};
uint16_t Counter = 1234;
uint16_t Delay   = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void Seg7_Puti(uint16_t Value)
{
	uint8_t Seg7_Data = 0;
	static uint8_t _digit = 0;
	uint8_t Segment[4] = {0, 0, 0, 0};
	
	Segment[3] = Value % 10;
	Value /= 10;
	Segment[2] = Value % 10;
	Value /= 10;
	Segment[1] = Value % 10;
	Value /= 10;
	Segment[0] = Value % 10;
	
	HAL_GPIO_WritePin(Digit_1_GPIO_Port, Digit_1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Digit_2_GPIO_Port, Digit_2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Digit_3_GPIO_Port, Digit_3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Digit_4_GPIO_Port, Digit_4_Pin, GPIO_PIN_RESET);		
	
	Seg7_Data = Seg7_cc[Segment[_digit]];
	
	HAL_GPIO_WritePin(Seg7_A_GPIO_Port, Seg7_A_Pin, bitCheck(Seg7_Data, 0));
	HAL_GPIO_WritePin(Seg7_B_GPIO_Port, Seg7_B_Pin, bitCheck(Seg7_Data, 1));
	HAL_GPIO_WritePin(Seg7_C_GPIO_Port, Seg7_C_Pin, bitCheck(Seg7_Data, 2));
	HAL_GPIO_WritePin(Seg7_D_GPIO_Port, Seg7_D_Pin, bitCheck(Seg7_Data, 3));
	HAL_GPIO_WritePin(Seg7_E_GPIO_Port, Seg7_E_Pin, bitCheck(Seg7_Data, 4));
	HAL_GPIO_WritePin(Seg7_F_GPIO_Port, Seg7_F_Pin, bitCheck(Seg7_Data, 5));
	HAL_GPIO_WritePin(Seg7_G_GPIO_Port, Seg7_G_Pin, bitCheck(Seg7_Data, 6));

	switch(_digit)
	{
		case 0:
			HAL_GPIO_WritePin(Digit_1_GPIO_Port, Digit_1_Pin, GPIO_PIN_SET);
		break;
		
		case 1:
			HAL_GPIO_WritePin(Digit_2_GPIO_Port, Digit_2_Pin, GPIO_PIN_SET);
		break;

		case 2:
			HAL_GPIO_WritePin(Digit_3_GPIO_Port, Digit_3_Pin, GPIO_PIN_SET);		
		break;

		case 3:
			HAL_GPIO_WritePin(Digit_4_GPIO_Port, Digit_4_Pin, GPIO_PIN_SET);				
		break;		
	};
	
	_digit++;
	if(_digit > 3)
	{
		_digit = 0;
	};
	
};
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
	HAL_TIM_Base_Start_IT(&htim1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		
		//HAL_Delay(Delay);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }

  /** Enables the Clock Security System
  */
  HAL_RCC_EnableCSS();
}

/* USER CODE BEGIN 4 */
/**
  * @brief  Period elapsed callback in non-blocking mode
  * @param  htim TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(htim->Instance == TIM1)
	{
		Seg7_Puti(Counter);
		Delay++;
		if(Delay>=1000)
		{
			Delay = 0;
			Counter++;
			if(Counter>9999)
			{
				Counter = 0;
			};
		};
	};
}


/**
  * @brief  EXTI line detection callbacks.
  * @param  GPIO_Pin: Specifies the pins connected EXTI line
  * @retval None
  */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch(GPIO_Pin)
	{
		case SW1_Pin:
			Counter = Counter + 1;
		break;
		
		case SW2_Pin:
			Counter = Counter + 10;
		break;

		case SW3_Pin:
			//Counter = Counter + 100;
		break;		
	};
	
	if(Counter > 9999)
	{
		Counter = 0;
	};
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
