#ifndef WIDGET_H
#define WIDGET_H
#include "Transform.h"
#include "graphics.hpp"
class Widget : public Transform
{
    public:
        Widget(Vector2 ps,Vector2 sc):Transform(ps,sc,0){};
        virtual void Draw() =0;
        virtual void Update(genv::event) =0;
        virtual bool isSelected(Vector2) = 0;
        virtual string GetValue()=0;
        virtual string GetLabel() =0;
        virtual void SetLabel(string) =0;
    protected:
    bool selected;
    private:
};

#endif // WIDGET_H
