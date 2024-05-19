#ifndef SPINBOX_H
#define SPINBOX_H

#include <Widget.h>


class SpinBox : public Widget
{
    public:
        SpinBox(Vector2 ps,Vector2 sc,Vector2 rage,int val,int btnw,string lab):Widget(ps,sc),range(rage),value(Vector2::clamp(range,val)),label(lab),btnwidth(btnw)
        {value = Vector2::clamp(range,val); grabbed = 0;}
        void Draw();
        void Update(genv::event);
        bool isSelected(Vector2);
        bool isButton(Vector2);
        string GetValue();
        void SetValue(int);
        Vector2 GetRange();
        void SetRange(Vector2);
        int Getbtnwidth();
        void Setbtnwidth(int);
        string GetLabel();
        void SetLabel(string);
    protected:
    int value;
    Vector2 range;
    string label;
    bool grabbed;
    int btnwidth;
    void btnChange(int);
    private:
};

#endif // SPINBOX_H
