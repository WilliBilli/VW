#ifndef SCREENTOPMENUVIEW_HPP
#define SCREENTOPMENUVIEW_HPP

#include <gui_generated/screentopmenu_screen/ScreenTopMenuViewBase.hpp>
#include <gui/screentopmenu_screen/ScreenTopMenuPresenter.hpp>

class ScreenTopMenuView : public ScreenTopMenuViewBase
{
public:
    ScreenTopMenuView();
    virtual ~ScreenTopMenuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SCREENTOPMENUVIEW_HPP
