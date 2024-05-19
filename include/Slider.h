#ifndef SLIDER_H
#define SLIDER_H

#include <Widget.h>


class Slider : public Widget
{
    public:
        Slider(Vector2 ps,Vector2 sc,Vector2 rage,int val,string lab):Widget(ps,sc),range(rage),value(Vector2::clamp(range,val)),label(lab)
        {value = Vector2::clamp(range,val); grabbed = 0;}
        void Draw();
        void Update(genv::event);
        bool isSelected(Vector2);
        string GetValue();
        void SetValue(int);
        Vector2 GetRange();
        void SetRange(Vector2);
        string GetLabel();
        void SetLabel(string);
    protected:
    int value;
    Vector2 range;
    string label;
    bool grabbed;
    private:
};

#endif // SLIDER_H
