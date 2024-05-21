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
#include "StaticText.h"
using namespace genv;
class App
{
    public:
        App(Vector2 windowsSize);
        void event_loop();
        void button_press(Vector2);
         Chess game;
         void startgame();
    protected:

    private:
    vector<Widget*> menu;
    vector<Widget*> chesstable;
    vector<Widget*> chessmisc;
    canvas sprites; //invidual piece is 50x50
    int font_size = 20;
    int field_size = 50;
    bool ingame = false;
};

#endif // APP_H
