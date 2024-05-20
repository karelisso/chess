#ifndef STATICTEXT_H
#define STATICTEXT_H

#include <Widget.h>
#include "Vector2.h"

class StaticText : public Widget
{
    public:
        StaticText(Vector2 ps,Vector2 sc,string lab)
        :Widget( ps, sc)
        ,label(lab){};
        void Draw();
        void Update(genv::event);
        bool isSelected(Vector2);
        string GetValue();
        string GetLabel();
        void SetLabel(string);
    protected:
    bool selected;
    string label;
    private:
};

#endif // STATICTEXT_H
