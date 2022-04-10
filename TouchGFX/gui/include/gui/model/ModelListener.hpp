#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <touchgfx/hal/Types.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void updateTime(uint8_t hours, uint8_t minutes, uint8_t seconds) {}
    virtual void updateTachometer(uint16_t tacho){}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
