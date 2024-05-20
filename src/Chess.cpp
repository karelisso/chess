#include "Chess.h"

Chess::Chess()
{
    for(int i=0; i<8; i++){
        board.push_back(babu(Vector2(i+1,2)
                                 ,light,
                                 pawn));
           board.push_back(babu(Vector2(i+1,7)
                                 ,dark,
                                 pawn));
    }

GenNonPawn(light);
GenNonPawn(dark);
};
void Chess::GenNonPawn(Team col){
        board.push_back(babu(Vector2(1,1+int(col)*7)
                                 ,col,
                                 tower));
    board.push_back(babu(Vector2(2,1+int(col)*7)
                                 ,col,
                                 knight));
     board.push_back(babu(Vector2(3,1+int(col)*7)
                                 ,col,
                                 runner));
     board.push_back(babu(Vector2(4,1+int(col)*7)
                                 ,col,
                                 king));
     board.push_back(babu(Vector2(5,1+int(col)*7)
                                 ,col,
                                 queen));
     board.push_back(babu(Vector2(6,1+int(col)*7)
                                 ,col,
                                 runner));
     board.push_back(babu(Vector2(7,1+int(col)*7)
                                 ,col,
                                 knight));
     board.push_back(babu(Vector2(8,1+int(col)*7)
                                 ,col,
                                 tower));
}
bool Chess::TryMove(Vector2 mw){
for(babu item:board){
    if(item.pos.x == prewmove.x && item.pos.y == prewmove.y && int(item.csapat)== int(currentState) )
        /*haha i forgot implementing this operatorn */{
        IsMoveLegal(mw,item);
    }
}

prewmove = mw;
}
bool Chess::IsMoveLegal(Vector2 next, babu item){
  vector<Vector2> path;
  Vector2 direction = next - prewmove;
switch(item.fig) {

  case pawn:
  {
    if(currentState == round_light){
       if(prewmove.y == 2 && direction.x ==0&& direction.y == 2){
        path.push_back(prewmove + Vector2(0,2));
       }
       if(direction.y == 1 && abs(direction.x) < 2){
        path.push_back(next);
       }
    }
    if(prewmove.y == 2 && currentState == round_dark){
        if(prewmove.y == 7&& direction.x ==0&& direction.y == -2){
        path.push_back(prewmove + Vector2(0,-2));
       }
       if(direction.y == -1 && abs(direction.x) < 2){
        path.push_back(next);
       }
    }
  }

    break;
case knight:{}
    if((abs(direction.x) == 2 && abs(direction.y) == 1 )|| (abs(direction.x) == 1 && abs(direction.y) == 2 )){
        path.push_back(next);
    }
    break;
case runner:{
if(abs(direction.x)==abs(direction.y)){

}
}
    // code block
    break;
case tower:{
    if(direction.x ==0 || direction.y ==0){
        for(int i=1; i<= direction.x+direction.y; i++){
            path.push_back(prewmove + Vector2(i*(direction.x >0)?1:-1 ,i*(direction.y>0)?1:-1 ));
        }

    }
}
    // code block
    break;
case queen:{}
    // code block
    break;
case king:{}
    // code block
    break;
}
}
