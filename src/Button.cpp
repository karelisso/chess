#include "Button.h"
#include "graphics.hpp"
#include <vector>
using namespace genv;

void Button::Draw(){
gout << move_to(pos.x - scale.x,pos.y-scale.y) << color(col) << box(scale.x*2,scale.y*2);
gout <<color(col) << move_to(pos.x -scale.x,pos.y) << text(label );
}
void Button::Update(event ev){
    if(ev.type == ev_mouse){
        if(ev.button == btn_left && isSelected(Vector2(ev.pos_x,ev.pos_y))){
            col.blue += 30;
            if(col.blue > 220) col.blue = 10;
        }
    }
}
bool Button::isSelected(Vector2 mouse){
return mouse.x> pos.x - scale.x &&
       mouse.x< pos.x + scale.x &&
       mouse.y> pos.y - scale.y &&
       mouse.y< pos.y + scale.y;}
string Button::GetValue(){
return label;}
string Button::GetLabel(){
return label;}
void Button::SetLabel(string given){
    label = given;
}
