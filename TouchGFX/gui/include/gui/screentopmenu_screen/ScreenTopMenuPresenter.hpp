#ifndef SCREENTOPMENUPRESENTER_HPP
#define SCREENTOPMENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ScreenTopMenuView;

class ScreenTopMenuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ScreenTopMenuPresenter(ScreenTopMenuView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ScreenTopMenuPresenter() {};

private:
    ScreenTopMenuPresenter();

    ScreenTopMenuView& view;
};

#endif // SCREENTOPMENUPRESENTER_HPP
