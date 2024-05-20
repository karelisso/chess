#include "App.h"
using namespace std;
using namespace genv;
App::App(Vector2 windowsize)
{
      gout.open(windowsize.x,windowsize.y);
    gout << font("LiberationSans-Regular.ttf",font_size);
    menu.push_back(new Button(Vector2(windowsize.x/2,windowsize.y/2),Vector2(windowsize.x/4,100.0f),color(20,50,80),"start!",[](){}));
    int field_size = 30;
    color dark(40,40,40);
    color light(230,230,230);
    for(int y=0; y<8; y++){
         for(int x=0; x<8; x++){
            chesstable.push_back(new Button(Vector2(50+ x*field_size,50+ y*field_size)
                                      ,Vector2(field_size/2,field_size/2)
                                      ,color( ((y%2+x)%2)? light:dark  )
                                      ,to_string(y)+""+to_string(x)
                                      ,[](){}));

        }
    }
    for(size_t i=0; i< chesstable.size(); i++){
     chesstable[i]->Draw();
    }
    gout << refresh;
}
void App::event_loop(){
event ev;
while(gin >> ev ){
 for(Widget* item:chesstable){
    item->Update(ev);
    item->Draw();
 }
gout << refresh;
}
}
