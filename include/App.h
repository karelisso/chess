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

class App
{
    public:
        App(Vector2 windowsSize);
        void event_loop();

    protected:

    private:
    vector<Widget*> menu;
    vector<Widget*> chesstable;
    int font_size = 20;
};

#endif // APP_H
