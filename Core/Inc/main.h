/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
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
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
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
uint8_t eeprom_read(void);
void eeprom_pass_read(void);
void eeprom_write(void);
void eeprom_pass_write(void);
uint8_t RTC_ConvertToBinDec(uint8_t c);
uint8_t divide(float a, float b);
uint8_t multiply(float a, float b);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define RENDER_TIME_Pin GPIO_PIN_4
#define RENDER_TIME_GPIO_Port GPIOD
#define VSYNC_FREQ_Pin GPIO_PIN_6
#define VSYNC_FREQ_GPIO_Port GPIOG
#define SDIO_CMD_Pin GPIO_PIN_2
#define SDIO_CMD_GPIO_Port GPIOG
/* USER CODE BEGIN Private defines */
// EEPROM
#define EEPROMADDR 			    (0x50 << 1)	// 7-битный адрес со сдвигом. Младший бит R|W
#define DS1307_ADDRESS 			0xd0 // (0x68 << 1) // 8-битный адрес
// DATA EEPROM
#define PASSLEN					5 			// Длина пароля
//-----
#define SET_HOURS_LEN 			2 			// Длина счётчика времени
#define SET_TIME_ALARM_LEN 		1 			// Длина времени предупреждения
#define HOURS_COUNT_LEN 		3 			// Длина текущий остаток времени + минуты
#define CHECK_SUM_LEN			1			// Длина контрольной суммы
#define RECORD_COUNT_LEN		3			// Длина сколько было записей
//-----
#define PAGE_LEN		(SET_HOURS_LEN + SET_TIME_ALARM_LEN + HOURS_COUNT_LEN + CHECK_SUM_LEN + RECORD_COUNT_LEN) // Длина общая
#define OUT_OF_LIMIT 		200000 		// Количество перезаписи
#define CHECK_SUM 			0xAB 		// Проверка
#define DEFAULT_PASS 		32098		// Пароль по умолчанию
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
