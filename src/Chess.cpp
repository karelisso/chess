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
prewmove = Vector2(-1,-1);
GenNonPawn(light);
GenNonPawn(dark);
};
int Chess::getRound(){
return int(currentState);}

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
void Chess::TryMove(Vector2 mw){
    if(prewmove.x != -1 && prewmove.y != -1){
        for(size_t i=0; i< board.size(); i++){
        babu* item = &board[i];
    if(item->pos.x == prewmove.x && item->pos.y == prewmove.y && int(item->csapat)== int(currentState) )
        /*haha i forgot implementing this operatorn */{
      board[i] = IsMoveLegal(mw, board[i]);
        //item.pos = mw;
    }
}
    }

//board.erase(board.begin(),board.end()-2);

prewmove = mw;
}
babu Chess::IsMoveLegal(Vector2 next, babu item){
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
    if(currentState == round_dark){
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
            int xmul=0;
            int ymul =0;
            if(direction.x !=0) xmul = (direction.x >0)?1:-1;
            if(direction.y !=0) ymul = (direction.y >0)?1:-1;
   for(int i=1; i<= abs(direction.x) ; i++){
            path.push_back(prewmove + Vector2((i)*xmul,(i)*ymul));
        }
}
}
    // code block
    break;
case tower:{
    if(direction.x ==0 || direction.y ==0){

            int xmul=0;
            int ymul =0;
            if(direction.x !=0) xmul = (direction.x >0)?1:-1;
            if(direction.y !=0) ymul = (direction.y >0)?1:-1;
        for(int i=1; i<= abs(direction.x) +abs(direction.y) ; i++){
            path.push_back(prewmove + Vector2(i* xmul,i*ymul ));
        }

    }
}
    // code block
    break;
case queen:{
    if(direction.x ==0 || direction.y ==0){

            int xmul=0;
            int ymul =0;
            if(direction.x !=0) xmul = (direction.x >0)?1:-1;
            if(direction.y !=0) ymul = (direction.y >0)?1:-1;
        for(int i=1; i<= abs(direction.x) +abs(direction.y) ; i++){
            path.push_back(prewmove + Vector2(i* xmul,i*ymul ));
        }

    }
    if(abs(direction.x)==abs(direction.y)){
            int xmul=0;
            int ymul =0;
            if(direction.x !=0) xmul = (direction.x >0)?1:-1;
            if(direction.y !=0) ymul = (direction.y >0)?1:-1;
   for(int i=1; i<= abs(direction.x) ; i++){
            path.push_back(prewmove + Vector2((i)*xmul,(i)*ymul));
        }
}

}

    break;
case king:// this going to be hard;
    {
        if(abs(direction.x) < 2&& abs(direction.y) <2) path.push_back(next);
    }
    // code block
    break;
}
bool freepath = true;
Vector2 road;
for(int i=0;i<path.size();i++){
    for(int n=0; n< board.size();n++){
        if(board[n].pos.x == path[i].x && board[n].pos.y == path[i].y){
                freepath = false;
          if( board[n].pos.x == next.x && board[n].pos.y == next.y) freepath = attack(n);
        }

    }
}
prewmove = next;
if(path.size() >0 && freepath) {
  item.pos = path[path.size()-1];
  prewmove = Vector2(-1,-1);
  if(currentState == round_light) currentState = round_dark;
  else if (currentState == round_dark) currentState = round_light;
}
return item;
}
bool Chess::attack(int id){

    if(board[id].fig == king) return false;
    if(int(currentState)!= int(board[id].csapat) ){
     // board.erase(board.begin()+(id-1) );

     board[id].pos = Vector2(10 +board[id].pos.x/3,2 +board[id].pos.x/4);
     if(board[id].csapat == light) board[id].pos.y += 5;
        return true;
    }

    return false;
}
