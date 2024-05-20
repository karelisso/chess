#include "StaticText.h"

void StaticText::Draw(){
gout <<color(255,255,255) << move_to(pos.x -scale.x,pos.y) << text(label );
}
void StaticText::Update(event ev){
}
bool StaticText::isSelected(Vector2 mouse){
return false;}
string StaticText::GetValue(){
return label;}
string StaticText::GetLabel(){
return label;}
void StaticText::SetLabel(string given){
    label = given;
}
