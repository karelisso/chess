#include "graphics.hpp"
#include <vector>
#include <fstream>
#include "Vector2.h"
#include "Transform.h"
#include "Widget.h"
#include "Slider.h"
#include "SpinBox.h"
#include "ListBox.h"
using namespace genv;

const int width = 800;
const int height = 600;
int main()
{
    vector<Widget*> w;
    Widget* selected = 0;
    Slider * first = new Slider(Vector2(150,200),Vector2(100,10),Vector2(0,10),9,"Slider");
    Slider * first2 = new Slider(Vector2(500,100),Vector2(65,5),Vector2(0,360),90,"Slider");

    SpinBox * second = new SpinBox(Vector2(200,30),Vector2(40,10),Vector2(0,10),2,-20,"SpinBox");
    SpinBox * second2 = new SpinBox(Vector2(200,80),Vector2(70,10),Vector2(0,10),2,22,"SpinBox");
    ListBox * third = new ListBox(Vector2(400,400),Vector2(100,100),Vector2(0,10),{"fds2","fsd2","fd1s","fds","f3sd","fds","fd1s","f3sd","fd4s","fds4","fs4d","fds2","fds2","fsd2","fd1s","fds","f3sd","fds","fd1s","f3sd","fd4s","fds4","fs4d","fds2"},"ListBox");
    ListBox * third2 = new ListBox(Vector2(600,400),Vector2(80,30),Vector2(0,10),{"option1","option2","option3","option4","option5"},"ListBox");
    w.push_back(first);
    w.push_back(second);
    w.push_back(third);
    w.push_back(first2);
    w.push_back(second2);
    w.push_back(third2);
    gout.open(width,height);
    gout << font("LiberationSans-Regular.ttf",15);
    event ev;
    while(gin >> ev) {
            gout << color(240,240,240)<< move_to(0,0) << box(width,height);
            for(Widget* item:w){
                if(ev.button == btn_left && item->isSelected(Vector2(ev.pos_x,ev.pos_y))) selected = item;
                else
                //item->Update(ev);
                item->Draw();
            }
            if(selected){
              selected->Update(ev);
              selected->Draw();
            }
            gout << refresh;
    }
    ofstream myout("output.txt");
     for(Widget* item:w){
        myout << item->GetLabel() + ": " + item->GetValue()+"\n";
     }
     myout.close();
    return 0;
}
