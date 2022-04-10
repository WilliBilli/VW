#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

#include "main.h"

bool countDown = false;
bool minDone = false;
bool dataSave = false;
extern uint8_t wmsg[PAGE_LEN];
extern uint16_t hours_left;
extern uint8_t min_left;
extern uint16_t timeSet;
extern uint8_t timeAlarmSet;

bool alert = false;
bool warning = false;
MainScreenView::MainScreenView()
{

}

void MainScreenView::setupScreen()
{
    MainScreenViewBase::setupScreen();
}

void MainScreenView::tearDownScreen()
{
    MainScreenViewBase::tearDownScreen();
}

void MainScreenView::handleTickEvent()
{

}

void MainScreenView::updateTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	if (!digitalDownFlag)
	{
		if(tickCounter == 60)
		{
			digitalDownFlag = true;
			tickCounter = 0;
		}
		if (seconds == tickCounter)
		{
			if (hours_left < timeAlarmSet / 4) {
				alert = false;
				warning = true;
			    imgWarning.setVisible(true);
			    imgWarning.invalidate();
			    imgAlert.setVisible(false);
			    imgAlert.invalidate();
			} else if (hours_left <= timeAlarmSet) {
				alert = true;
			    imgAlert.setVisible(true);
			    imgAlert.invalidate();
			}

			digitalSecondsDown = tickCounter + 2;
			if(hours >= 12)
			{
				Unicode::snprintf(textWatchBuffer, TEXTWATCH_SIZE, "PM");
				textWatch.invalidate();
				hours -= 12;
			}
			else
			{
				Unicode::snprintf(textWatchBuffer, TEXTWATCH_SIZE, "AM");
				textWatch.invalidate();
			}
			digitalClock.setTime24Hour(hours, minutes, seconds);
			digitalClock.invalidate();
			circleWatch.setValue(digitalSecondsDown);
			circleWatch.invalidate();
		}
		tickCounter = seconds + 1;
	}
    else
    {
        digitalSecondsDown -= 1;
        circleWatch.setValue(digitalSecondsDown);
        circleWatch.invalidate();
        if (digitalSecondsDown < 1)
		{
			digitalDownFlag = false;
		}
    }

	if(seconds == 0 && !minDone && countDown){
		minDone = true;
	    if(min_left > 0) {
	    	min_left--;
	    } else {
	    	if (hours_left > 0) {
	    		hours_left--;
	    		min_left = 59;
	    	}
	    }
	    if(hours_left > 0) {
		    Unicode::snprintf(timeLeftBuffer, TIMELEFT_SIZE, "%d", hours_left);
		    timeLeft.invalidate();
		    // Текст ОСТАЛОСЬ ЧАС/...
			Unicode::snprintf(textTimeLeftBuffer, TEXTTIMELEFT_SIZE, time_left[0]);
			textTimeLeft.invalidate();
		} else {
		    Unicode::snprintf(timeLeftBuffer, TIMELEFT_SIZE, "%d", min_left);
		    timeLeft.invalidate();
		    // Текст ОСТАЛОСЬ МИН/...
			Unicode::snprintf(textTimeLeftBuffer, TEXTTIMELEFT_SIZE, time_left[1]);
			textTimeLeft.invalidate();
		}
	} else if (seconds > 0) minDone = false;
}

void MainScreenView::updateTachometer(uint16_t tacho)
{
	// круг из 44 ступеней
	circle_rpm.setValue(tacho / 47);
	circle_rpm.invalidate();

	Unicode::snprintf(tachometerRPMBuffer, TACHOMETERRPM_SIZE, "%d",  tacho / 340);
	tachometerRPM.invalidate();
	if(tacho > 0) {
		countDown = true;
		dataSave = true;
	} else {
		countDown = false;
		if(dataSave){
			wmsg[3] = (hours_left >> 8);
			wmsg[4] = hours_left;
			wmsg[5] = min_left;
			eeprom_write();
			dataSave = false;
		}
	}
}
