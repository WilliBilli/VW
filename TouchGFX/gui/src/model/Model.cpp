#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#include "stm32f4xx_hal.h"
#include "main.h"

extern RTC_HandleTypeDef hrtc;
extern RTC_TimeTypeDef sTime;
extern RTC_DateTypeDef sDate;

extern uint16_t tachoRPM; // Переменная тахометра

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	HAL_RTC_GetTime(&hrtc, &sTime, FORMAT_BIN);
	HAL_RTC_GetDate(&hrtc, &sDate, FORMAT_BIN);

	modelListener->updateTime(sTime.Hours, sTime.Minutes, sTime.Seconds);
	modelListener->updateTachometer(tachoRPM);
}
