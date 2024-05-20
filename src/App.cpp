#include "App.h"

App::App(Vector2 windowsize)
{
      gout.open(width,height);
    gout << font("LiberationSans-Regular.ttf",font_size);
    event ev;
}

App::~App()
{
    //dtor
}
