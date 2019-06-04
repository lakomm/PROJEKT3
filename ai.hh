#include "board.hh"
#include <algorithm>
#include"move.hh"
class AI{
private:

public:

//algorytm minmax z obcinaniem alpha beta
//zwraca wartosc sekwencji ruchow
//parametr depth okresla ile ruchow zostaje przeszukanych
  int minmax(Board board, int depth, bool isMaximizing, int NumberOfWin, int alpha, int beta){

    int score=board.evaluate(NumberOfWin);

    if(depth==0 || !board.isMoveleft())return score; //warunki zakonczenia rekursji
    if( score==10)return score+depth;
    if( score==-10)return score-depth;

    int const MIN=-1000;
    int const MAX=1000;
    int size=board.returnSize();

    if(isMaximizing){
      int maxVal=MIN;
      for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
          if(board.returnVal(i, j)==' '){
            board.move(i, j, 'X');        //wykonanie ruchu

            int eval=minmax(board, depth-1, !isMaximizing, NumberOfWin, MIN, MAX);// ocena kolejnych ruchow

            maxVal=std::max(eval, maxVal);
            alpha=std::max(maxVal, alpha);
            board.setVal(i, j, ' ');     //cofniecie ruchu
            if(beta<=alpha)break;
          }
        }
      }
      return maxVal;
    }else{
      int minVal=MAX;
      for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
          if(board.returnVal(i,j)==' '){
            board.move(i,j,'O');                //wykonanie ruchu

            int eval=minmax(board,depth-1,!isMaximizing,NumberOfWin,MIN,MAX);   //ocena kolejnych ruchow

            minVal=std::min(eval,minVal);
            beta=std::min(minVal,beta);
            board.setVal(i,j,' ');          //cofniecie ruchu
            if(beta<=alpha)break;
          }
        }
      }
      return minVal;
    }
  }

// board, depth, number of winning in a row
//funkcja srawdza kazdy z dostepnych ruchow i za pomoca algorytmu min max go ocenia
//najlepszy ruch zostaje zwrocony
Move BestMove(Board board,int depth, int winningrow){
  int bestVal=-1000;
  Move bestMove;
  bestMove.x=-1;
  bestMove.y=-1;
  int size=board.returnSize();
  for(int i=0;i<size;i++){
    for(int j=0;j<size;j++){
      if(board.returnVal(i,j)==' '){
        board.move(i,j,'X');

        int moveVal=minmax(board,depth,false,winningrow,-100,100);
        // board.displaBoard();
        board.setVal(i,j,' ');
        if(moveVal>bestVal){
          bestMove.x=i; bestMove.y=j;
          bestVal=moveVal;}
        }
      }
    }
    return bestMove;
}

};
