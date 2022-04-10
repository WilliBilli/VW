#include <gui/mainscreen_screen/MainScreenView.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

MainScreenPresenter::MainScreenPresenter(MainScreenView& v)
    : view(v)
{

}

void MainScreenPresenter::activate()
{

}

void MainScreenPresenter::deactivate()
{

}

void MainScreenPresenter::updateTime(uint8_t hours, uint8_t minutes, uint8_t seconds)
{
	view.updateTime(hours, minutes, seconds);
}

void MainScreenPresenter::updateTachometer(uint16_t tacho)
{
	view.updateTachometer(tacho);
}
