#include<iostream>
#include<cmath>
#include<iomanip>
#include<conio.h>
using namespace std;

bool youlose;
const int wide=30;
const int height = 20;
int x,y,fruitX,fruitY,score;
enum direction {STOP,LEFT,RIGHT,UP,DOWN};
direction direct;
int tailx[100];
int taily[100];
int ntail;
void setup(){
youlose=false;
direct=STOP;
x = wide/2;
y = height/2;
fruitX= rand()% wide;
fruitY = rand()% height;
score = 0;
}





void draw(){

    system("cls");
    for(int i=0;i< wide;i++){cout<< "#";}
    cout<< endl;
    for(int i=0;i< height;i++){
            for(int j=0;j<wide;j++){
                if(j==0)
                    cout<<"#";
              if(i == y&& j == x)

                cout<< "<>";
              else if(i== fruitY-1&&j == fruitX-1)
              cout<< "O";
                else{
                    for(int k=0;k<ntail;k++){
                       bool print = false;
                        if(tailx[k] == j&& taily[k]== i){
                            cout<< "o";
                             print = true;
                        }



                    }
                      cout<< " ";
                }
                    cout<< " ";
                if(j== wide-1)
                    cout<< "#";
            }
           cout<< endl;
    }
    system("cls");
    for(int i=0;i< wide+2;i++){cout<< "#";}
    cout<< endl;
    cout<< "score: "<< score << endl;
}
void input(){
  if(_kbhit()){
    switch(_getch()){
   case 'w':
    direct = UP;
    break;
   case 'a':
    direct = LEFT;
    break;
   case 'd':
    direct = RIGHT;
    break;
   case 's':
    direct = DOWN;
    break;
   case 'x':
    youlose = true;
    cout<< "GAME OVER";


    }
  }
}
void logic()
{
    int prevx = tailx[0];
    int prevy = taily[0];
    int prev2x;
    int prev2y;
    tailx[0]= x;
    taily[0]= y;
    for(int i=1;i< ntail;i++)

    {
    prev2x = tailx[i];
    prev2y= taily[i];
    tailx[i] = prevx;
    taily[i] = prev2y;
    prevx = prev2x;
    prev2y = prevy;
    }
 switch(direct){
  case LEFT:
      x--;
      break;
  case RIGHT:
      x++;
    break;
  case UP:
      y--;
    break;
  case DOWN:
      y++;
    break;
  default:
    break;
 }
 if(x> wide || x < 0|| y > height|| y <0)

  direct = STOP;
  

 if(x == fruitX || y == fruitY){score += 10;
 fruitX= rand()% wide;
 fruitY = rand()% height;
 ntail++;
 }

}






using namespace std;


  int main(){


setup();
while(!youlose){
    draw();
    input();
    logic();

}



   return 0;
  }
