#ifndef CUSTOMLOGIN_HPP
#define CUSTOMLOGIN_HPP

#include <gui_generated/containers/CustomLoginBase.hpp>

class CustomLogin : public CustomLoginBase
{
public:
    CustomLogin();
    virtual ~CustomLogin() {}

    virtual void initialize();

protected:
};

#endif // CUSTOMLOGIN_HPP
