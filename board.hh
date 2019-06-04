class Board{
private:
  char** board;
  int size;

public:
  Board(int s){           //konstruktor parametryczny-> inicjalizacja tablicy dwuwymiarowej, komorki tablicy odpowiadaja polom na planszy
    size=s;
    board= new char*[size];
    for(int i=0; i<size; i++){
      board[i]=new char[size];
      for(int j=0; j<size; j++){
        board[i][j]=' ';
      }
    }
  }

bool isMoveleft(){        // funkca sprawdzajaca czy poozstało jeszcze nie wypelnione pole na planszy
  for(int i=0; i<size;i++){
    for(int j=0;j<size;j++){
      if(board[i][j]==' ')return true;
    }
  }
  return false;
}


void move(int x,int y,char c){
  if(this->isMoveleft() && x<size &&  y<size && x >= 0  && y>=0 && board[x][y]==' '){
    board[x][y]=c;
    // this->displaBoard();
  }else std::cout<<"WRONG MOVE"<<'\n';
}

//n-number of winning x or o in a row
//funkcja oceniajaca sytuacje na planszy
//w przypadku wygranej gracza X zwraca 10
//w przypadku wygranej gracza O zwraca -10
//w pozostalych przypadkach zwraca 0
int evaluate(int n){
  int value;
  char tmp;

  //checking for rows
  for(int i=0;i<size;i++){
    value=1;
    for(int j=0;j<size-1;j++){
      if(board[i][j]!=' ' && board[i][j]==board[i][j+1]){value=value+1;tmp=board[i][j];}else{value=1;}
      if(value==n && tmp!=' '){
        if(tmp=='X'){
          return 10;
        }else{return -10;}
      }
    }
  }

  //checking for columns
  for(int i=0;i<size;i++){
    value=1;
    for(int j=0;j<size-1;j++){
      if(board[j][i]!=' ' && board[j][i]==board[j+1][i]){value=value+1;tmp=board[j][i];}else{value=1;}
      if(value==n && tmp!=' '){
        if(tmp=='X'){
          return 10;
        }else{return -10;}
      }
    }
  }

  //checkig for diagonals
  for(int a=0;a<=size-n;a++){
    value=1;
    for(int i=0;i<size-a-1;i++){
      if(board[i+a][i]!=' ' && board[i+a][i]==board[i+a+1][i+1]){value=value+1;tmp=board[i+a][i];}else{value=1;}
      if(value==n){
        if(tmp=='X'){
          return 10;
        }else{return -10;}
      }
    }

    value=1;
    for(int i=0;i<size-a-1;i++){

      if(board[i][i+a]!=' ' && board[i][i+a]==board[i+1][i+a+1]){value=value+1;tmp=board[i][i+a];}else{value=1;}
      if(value==n){
        if(tmp=='X'){
          return 10;
        }else{return -10;}
      }
    }

    value=1;
    for(int i=0;i<size-a-1;i++){
      if(board[i+a][size-i-1]!=' ' && board[i+a][size-i-1]==board[i+a+1][size-i-1-1]){value=value+1;tmp=board[i+a][size-i-1];}else{value=1;}
      if(value==n){
        if(tmp=='X'){
          return 10;
        }else{return -10;}
      }
    }

    value=1;
    for(int i=0;i<size-a-1;i++){
      if(board[i][size-i-1-a]!=' ' && board[i][size-i-1-a]==board[i+1][size-i-1-1-a]){value=value+1;tmp=board[i][size-i-1-a];}else{value=1;}
      if(value==n){
        if(tmp=='X'){
          return 10;
        }else{return -10;}
      }
    }
  }
  return 0;
}


//funkcja sprawdzajaca czy padla wygrana ktoregos z graczy lub czy jest remis
//
int isWin(int n){
  int score=this->evaluate(n);
  if(score<0){std::cout<<'\n'<<"YOU WON!"<<'\n'; return score;}
  if(score>0){std::cout<<'\n'<<"COMPUTER WON!"<<'\n'; return score;}
  if(score==0 && !this->isMoveleft()){std::cout<<'\n'<<"DRAW!"<<'\n'; return -1; }else{return 0;}
}

//funkcja wyswietlajaca plansze
void displayBoard()const{
  for(int i=0; i<size; i++){

    for(int j=0; j<size; j++){
      std::cout<<" "<<board[i][j]<<" ";
      if(j!=size-1) std::cout<<"|";
    }
    std::cout<<'\n';
    if(i!=size-1){
      for(int j=0; j<size; j++){
        std::cout<<"---";
        if(j!=size-1 ) std::cout<<"+";
      }
      std::cout<<'\n';
    }
  }
  std::cout<<'\n';
}

int returnSize(){return size;}
char returnVal(int x, int y){
  return board[x][y];
}
void setVal(int x,int y,char c){
  this->board[x][y]=c;
}
};
