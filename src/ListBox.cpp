#include "ListBox.h"
#include "graphics.hpp"
#include <vector>
using namespace genv;

void ListBox::Draw(){


    gout << color(255,255,0);

    for(int y =-scale.y; y < scale.y; y++){
        gout << move_to(pos.x-scale.x,pos.y-y)
             << line_to(pos.x+scale.x,pos.y-y);
    }
    gout << font("LiberationSans-Regular.ttf",text_size);
    gout << color(255,0,0)
     << move_to(pos.x+scale.x-20,
                                         Vector2::lerp(Vector2(0.0,pos.y-scale.y),
                                                      Vector2(0.0,pos.y+scale.y/2),
                                                     float(currentLine) /(value.size()-buffer)).y)
         << box(20,scale.y/2);
    gout << color(0,0,255);
    for(int i=currentLine; i < value.size() && (1+i-currentLine)*text_size-1 < scale.y*2;i++ ){
             if(i==current) gout << color(100,100,100)<< move_to(pos.x-scale.x,-scale.y+ pos.y+(i-currentLine)*text_size)
                            << box(scale.x*2,15) <<color(0,0,255);
        gout <<  move_to(pos.x,-scale.y+ pos.y+(i-currentLine)*text_size)
             << text(value[i]);

    }
    gout << color(1,1,1) << move_to(pos.x,pos.y-scale.y-10) << text(label);
}
void ListBox::Update(event ev){
if(ev.type == ev_mouse){
if(ev.button == btn_left) {
current = (ev.pos_y -(pos.y-scale.y))/15;
current = Vector2::clamp(Vector2(0,value.size()),current+currentLine);
}
if(ev.button == btn_wheelup) currentLine = Vector2::clamp(Vector2(0,value.size()-buffer),currentLine+1);
if(ev.button == btn_wheeldown) currentLine = Vector2::clamp(Vector2(0,value.size()-buffer),currentLine-1);
}
if(ev.type == ev_key){
    if(ev.keycode == key_up)  currentLine = Vector2::clamp(Vector2(0,value.size()-buffer),currentLine-1);
    if(ev.keycode == key_down)  currentLine = Vector2::clamp(Vector2(0,value.size()-buffer),currentLine+1);
    if(ev.keycode == key_pgup)  currentLine = Vector2::clamp(Vector2(0,value.size()-buffer),currentLine-10);
    if(ev.keycode == key_pgdn)  currentLine = Vector2::clamp(Vector2(0,value.size()-buffer),currentLine+10);
}
}
bool ListBox::isSelected(Vector2 mouse){
return mouse.x> pos.x - scale.x &&
       mouse.x< pos.x + scale.x &&
       mouse.y> pos.y - scale.y &&
       mouse.y< pos.y + scale.y;
}
string ListBox::GetSelected(){
return value[current];}
string ListBox::GetValue(){
    string result = "";
    for(int i=0;i<value.size();i++) result+= value[current];
    return value[current];
}
void ListBox::SetValue(vector<string> val){
value = val;}
string ListBox::GetLabel(){
return label;}
void ListBox::SetLabel(string lab){
label = lab;}
