#ifndef LISTBOX_H
#define LISTBOX_H

#include <Widget.h>


class ListBox : public Widget
{
    public:
        ListBox(Vector2 ps,Vector2 sc,Vector2 rage,std::initializer_list<std::string> val,string lab):Widget(ps,sc),range(rage),value(val),label(lab)
        {grabbed = 0; text_size = 15;}
        void Draw();
        void Update(genv::event);
        bool isSelected(Vector2);
        string GetSelected();
        string GetValue();
        void SetValue(vector<string>);
        string GetLabel();
        void SetLabel(string);
    protected:
    vector<string> value;
    int current;
    int text_size;
    int currentLine = 0;
    int buffer = 3;
    Vector2 range;
    string label;
    bool grabbed;
    private:
};

#endif // LISTBOX_H
