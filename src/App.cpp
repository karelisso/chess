#include "App.h"
#include <fstream>
using namespace std;
using namespace genv;
App::App(Vector2 windowsize)
{
      gout.open(windowsize.x,windowsize.y);
    gout << font("LiberationSans-Regular.ttf",font_size);
    menu.push_back(new Button(Vector2(windowsize.x/2,windowsize.y/2),Vector2(windowsize.x/4,100.0f),color(20,50,80),"start!",[](){}));
    int field_size = 50;
    color dark(110,80,40);
    color light(255,250,170);
    sprites.open(300,100);
    sprites.transparent(true);
    ifstream image("chesspng.kep");
    if(image.good()){

        int x=0;
        int y=0;
        image >> x>> y;

        for(int iy=0; iy<y; iy++){
            for(int ix=0; ix<x; ix++){
                    int r=50;
                    int g=0;
                    int b=0;
            image >> r>>g>>b;
            if(r+g+b > 1)
            sprites << move_to(ix,iy) << color(r,g,b) << dot;
        }
        }
    }
    image.close();


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
    gout << color(255,255,255);
    gout << stamp(sprites,100,100);
    gout << refresh;
}
void App::event_loop(){
event ev;
while(gin >> ev ){
 for(Widget* item:chesstable){
    item->Update(ev);
    item->Draw();
 }
  gout <<move_to(10,10) << stamp(sprites,0,0,300,100,10,10);
gout << refresh;
}
}