#include "Slider.h"
#include "graphics.hpp"
using namespace genv;

void Slider::Draw(){
    gout << color(255,255,0);
    for(int y =-scale.y; y < scale.y; y++){
        gout << move_to(pos.x-scale.x,pos.y-y)
             << line_to(pos.x+scale.x,pos.y-y);
    }
    gout << font("LiberationSans-Regular.ttf",scale.y);
    Vector2 pointer= Vector2::lerp(pos-scale,pos+scale,(value+range.x)/range.y);
    gout << color(0,0,255)
         << move_to(pointer.x-(scale.y/2),pos.y-scale.y)
         << box(scale.y+2,scale.y*2+2);
    gout << color(1,1,1) << move_to(pos.x,pos.y-scale.y-10) << text(label);
}
void Slider::Update(event ev){
if(ev.type == ev_mouse){
if(ev.button == btn_left) grabbed = isSelected(Vector2(ev.pos_x,ev.pos_y));
if(ev.button == -btn_left) grabbed = false;
        if(grabbed)
        {
            value = Vector2::clamp(range, (ev.pos_x -(pos.x-scale.x))/(scale.x*2) *(range.y));
        }
}
}
bool Slider::isSelected(Vector2 mouse){
return mouse.x> pos.x - scale.x &&
       mouse.x< pos.x + scale.x &&
       mouse.y> pos.y - scale.y &&
       mouse.y< pos.y + scale.y;
}
string Slider::GetValue(){
return to_string(value) ;
}
void Slider::SetValue(int val){
value = val;}
Vector2 Slider::GetRange(){
return range;}
void Slider::SetRange(Vector2 rg){
    range = rg;
}
string Slider::GetLabel(){
return label;}
void Slider::SetLabel(string lab){
label =lab;}
