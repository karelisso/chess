#ifndef STATICTEXT_H
#define STATICTEXT_H

#include <Widget.h>
#include "Vector2.h"

class StaticText : public Widget
{
    public:
        StaticText(Vector2 ps,Vector2 sc,string lab):Widget(Vector2 ps,Vector2 sc):Transform(ps,sc,0),label(lab){};
        virtual void Draw() =0;
        virtual void Update(genv::event) =0;
        virtual bool isSelected(Vector2) = 0;
        virtual string GetValue()=0;
        virtual string GetLabel() =0;
        virtual void SetLabel(string) =0;
    protected:
    bool selected;
    string label;
    private:
};

#endif // STATICTEXT_H
