#include "SpinBox.h"
#include "graphics.hpp"
#include <math.h>
using namespace genv;

void SpinBox::Draw(){
    gout << color(255,255,0);
    for(int y =-scale.y; y < scale.y; y++){
        gout << move_to(pos.x-scale.x,pos.y-y)
             << line_to(pos.x+scale.x,pos.y-y);
    }
    gout << font("LiberationSans-Regular.ttf",scale.y);
    if(btnwidth < 0)
    gout << color(0,0,0)
         << move_to(pos.x-scale.x,pos.y-scale.y)
         << box(-btnwidth,scale.y*2+1)
         << color(255,255,255)
         << move_to(pos.x-scale.x+(abs(btnwidth)/2),pos.y-scale.y)
         << text("/\\")
         << move_to(pos.x-scale.x+(abs(btnwidth)/2),pos.y)
         << text("\\/");
    else
        gout << color(0,0,0)
             << move_to(pos.x+scale.x-btnwidth,pos.y-scale.y)
             << box(btnwidth,scale.y*2+1)
             << color(255,255,255)
             << move_to(pos.x+scale.x-btnwidth,pos.y-scale.y)
             << text("/\\")
             << move_to(pos.x+scale.x-btnwidth,pos.y)
             << text("\\/");
    gout << color(0,0,255)
         << move_to(pos.x,pos.y)
         << text(to_string(value));
    gout << color(1,1,1) << move_to(pos.x,pos.y-scale.y-10) << text(label);
}
void SpinBox::Update(event ev){
if(ev.type == ev_mouse){
if(ev.button == btn_left &&isSelected(Vector2(ev.pos_x,ev.pos_y))) {
  if(ev.pos_y < pos.y) btnChange(1);
  else btnChange(-1);
}

}
if(ev.type == ev_key){
    if(ev.keycode == key_up) btnChange(1);
    if(ev.keycode == key_down) btnChange(-1);
    if(ev.keycode == key_pgup) btnChange(10);
    if(ev.keycode == key_pgdn) btnChange(-10);
}
}
bool SpinBox::isButton(Vector2 mouse){
    if(btnwidth < 0)
return mouse.x> pos.x - scale.x &&
       mouse.x< pos.x - scale.x-btnwidth &&
       mouse.y> pos.y - scale.y &&
       mouse.y< pos.y + scale.y;

return mouse.x> pos.x + scale.x-btnwidth &&
       mouse.x< pos.x + scale.x &&
       mouse.y> pos.y - scale.y &&
       mouse.y< pos.y + scale.y;
}
bool SpinBox::isSelected(Vector2 mouse){
return mouse.x> pos.x - scale.x &&
       mouse.x< pos.x + scale.x &&
       mouse.y> pos.y - scale.y &&
       mouse.y< pos.y + scale.y;
}
void SpinBox::btnChange(int change){
value+=change;
}
string SpinBox::GetValue(){ return to_string(value);}
void SpinBox::SetValue(int val){
value = val;}
Vector2 SpinBox::GetRange(){
return range;}
void SpinBox::SetRange(Vector2 rg){
    range = rg;
}
int SpinBox::Getbtnwidth(){
return btnwidth;}
void SpinBox::Setbtnwidth(int wdth){
btnwidth = wdth;}
string SpinBox::GetLabel(){
return label;}
void SpinBox::SetLabel(string lab){
label =lab;}
