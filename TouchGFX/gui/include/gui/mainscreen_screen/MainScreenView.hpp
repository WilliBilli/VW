#ifndef MAINSCREENVIEW_HPP
#define MAINSCREENVIEW_HPP

#include <gui_generated/mainscreen_screen/MainScreenViewBase.hpp>
#include <gui/mainscreen_screen/MainScreenPresenter.hpp>

class MainScreenView : public MainScreenViewBase
{
public:
    MainScreenView();
    virtual ~MainScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
    void updateTime(uint8_t hours, uint8_t minutes, uint8_t seconds);
    void updateTachometer(uint16_t tacho);
protected:
    uint8_t tickCounter = 0;
    int digitalSeconds;
    int digitalSecondsDown;
    bool  digitalDownFlag = false;
    uint16_t time_left[2][15] = {{0x41e,0x421,0x422,0x410,0x41b,0x41e,0x421,0x42c,0x2f,0x427,0x410,0x421}, {0x41e,0x421,0x422,0x410,0x41b,0x41e,0x421,0x42c,0x2f,0x41c,0x418,0x41d}};
};

#endif // MAINSCREENVIEW_HPP
