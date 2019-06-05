#include "ai.hh"
class Game{
private:
  AI ai;
  Move M;
public:
  void Play(){
    int BOARD_SIZE,NUM_OF_WINNING,DEPTH,X,Y;
    DEPTH=6;
    std::cout<<"Podaj rozmiar planszy: "; std::cin>>BOARD_SIZE;
    std::cout<<'\n'<<"Podaj liczbe wygrywajacych pod rzad: "; std::cin>>NUM_OF_WINNING; std::cout<<'\n';

    Board B(BOARD_SIZE); //zainicjalizowanie planszy
    // B.move(0,0,'X');
    // B.move(1,1,'X');
    // B.move(2,2,'X');
    // std::cout<<B.evaluate(3)<<'\n';
    B.displayBoard(); //wyswietlenie planszy

    while(1){  //glowna petla gry

    std::cout<<"TWOJ RUCH   PODAJ WSPOLRZEDNE: X="; std::cin>>X; std::cout<<" Y=";std::cin>>Y; std::cout<<'\n'; // wczytanie ruchu gracza
    B.move(X,Y,'O'); B.displayBoard();
    if(B.isWin(NUM_OF_WINNING)){break;}   //sprawdzenie wygranej

    std::cout<<"RUCH KOMPUTERA   "<<'\n';
    M=ai.AIMove(B,DEPTH,NUM_OF_WINNING); //szukanie najlepszego ruchu dla komputera
    B.move(M.x,M.y,'X');
    B.displayBoard();
    if(B.isWin(NUM_OF_WINNING)){break;} //sprawdzenie wygranej
  }
}
};
