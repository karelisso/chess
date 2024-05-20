#ifndef BUTTON_H
#define BUTTON_H

#include <Widget.h>
#include <functional>
enum Activation{
OnPress,
OnRelease};

class Button : public Widget
{
       public:
        Button(Vector2 ps,Vector2 sc,string lab,std::function<void()> lamdafunc):Widget(ps,sc),label(lab),lambdafunction(lamdafunc)
        {int i =0;}
        void Draw();
        void Update(genv::event);
         bool isSelected(Vector2);
         string GetValue();
         string GetLabel();
         void SetLabel(string);
    protected:
    std::function<void()> lambdafunction;
    int col = 100;
    string label;
    private:
};

#endif // BUTTON_H
