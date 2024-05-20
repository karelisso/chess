#ifndef APP_H
#define APP_H
#include "graphics.hpp"
#include <vector>
#include <fstream>
#include "Vector2.h"
#include "Transform.h"
#include "Widget.h"
#include "Slider.h"
#include "SpinBox.h"
#include "ListBox.h"
#include "Button.h"
#include "Chess.h"
using namespace genv;
class App
{
    public:
        App(Vector2 windowsSize);
        void event_loop();
        void button_press(Vector2);
    protected:

    private:
    vector<Widget*> menu;
    vector<Widget*> chesstable;
    canvas sprites; //invidual piece is 50x50
    int font_size = 20;
    int field_size = 50;
    Chess game;
};

#endif // APP_H
