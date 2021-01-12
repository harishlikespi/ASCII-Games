#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


using namespace std;
const int height = 20;
const int width = 10;
struct coord{
    int x;
    int y;
};

coord X1{0,0};
coord X2{1,0};
coord X3{0,1};
coord X4{1,1};
coord X5{2,0};
coord X6{2,1};
bool cont = true;
int randn;
int selec = 3;
int cnt = 1;
int seq;
int score;


string gameboard[height][width];
void clearRow(int row){
    int sec = 0;
    for(int c = 0; c < width; c++){
        if(gameboard[row][c] == "O"){
            sec++;
        }
        seq = sec;
    } 
}

void clr(int row){
        clearRow(row);
    if(seq == width){
        score += 100;
       for( int r = 0; r < width; r++){
           gameboard[row][r] = " ";
       }
       for(int x = row; x > 0; x--){
           for( int y = 0; y < width; y++){
           if(gameboard[x-1][y] == "O"){
               gameboard[x][y] = "O";
               gameboard[x-1][y] = " ";
                }
            }
       }
    }
}

void input(){
    if (_kbhit()){
        switch(_getch()){

            case 'a':
            X1.y--;
            X2.y--;
            X3.y--;
            X4.y--;
            X5.y--;
            X6.y--;
            
            break;
            case 's':
            X1.x++;
            X2.x++;
            X3.x++;
            X4.x++;
            X5.x++;
            X6.x++;
            break;

            case 'd':
            X1.y++;
            X2.y++;
            X3.y++;
            X4.y++;
            X5.y++;
            X6.y++;
            break;

            case 'x':
            cont = false;
        }
        
    }
}

void drawLine(){
        if(X2.x != height - 1){
            if(gameboard[X2.x + 1][X2.y] != "O"){
                for(int x = 0; x < height; x++){
                    for(int y = 0; y < width; y++){
                        if(x == X1.x && y == X1.y || (x == X2.x && y == X2.y)){
                            gameboard[x][y] = "X";

                        } else {
                            if(gameboard[x][y] != "O")
                            gameboard[x][y] = " ";
                    }
                }
            }
        } else if(gameboard[X2.x +1][X1.y] == "O"){
        gameboard[X1.x][X1.y] = "O";
        gameboard[X2.x][X2.y] = "O";
        X1 = {0,0};
        X2 = {1,0};
       

        } 
        } else if (X2.x == height - 1) {     
        gameboard[X1.x][X1.y] = "O";
        gameboard[X2.x][X2.y] = "O";
        X1 = {0,0};
        X2 = {1,0};
    }    

    for(int row = 0; row < height; row++){
    clr(row);
    }
}


void drawSquare(){
        if(X2.x != height - 1){
            if(gameboard[X2.x + 1][X2.y] != "O" && gameboard[X4.x + 1][X4.y] != "O"){
                for(int x = 0; x < height; x++){
                    for(int y = 0; y < width; y++){
                        if(x == X1.x && y == X1.y || (x == X2.x && y == X2.y) || (x == X3.x && y == X3.y) || (x == X4.x && y == X4.y)){
                            gameboard[x][y] = "X";

                        } else {
                            if(gameboard[x][y] != "O")
                            gameboard[x][y] = " ";
                    }
                }
            }
        } else if((gameboard[X2.x + 1][X2.y] == "O") || gameboard[X4.x + 1][X4.y] == "O"){
        gameboard[X1.x][X1.y] = "O";
        gameboard[X2.x][X2.y] = "O";
        gameboard[X3.x][X3.y] = "O";
        gameboard[X4.x][X4.y] = "O";
        X1 = {0,0};
        X2 = {1,0};
        X3 = {0,1};
        X4 = {1,1};
        } 
        } else if (X2.x == height - 1) {     
        gameboard[X1.x][X1.y] = "O";
        gameboard[X2.x][X2.y] = "O";
        gameboard[X3.x][X3.y] = "O";
        gameboard[X4.x][X4.y] = "O";
        X1 = {0,0};
        X2 = {1,0};
        X3 = {0,1};
        X4 = {1,1};
    }    

    for(int row = 0; row < height; row++){
    clr(row);
    }    
}

void drawL(){
        if(X5.x != height - 1){
            if(gameboard[X5.x + 1][X5.y] != "O" && gameboard[X6.x + 1][X6.y] != "O"){
                for(int x = 0; x < height ; x++){
                    for(int y = 0; y < width; y++){
                        if(x == X1.x && y == X1.y || (x == X2.x && y == X2.y) || (x == X5.x && y == X5.y) || (x == X6.x && y == X6.y)){
                            gameboard[x][y] = "X";

                        } else {
                            if(gameboard[x][y] != "O")
                            gameboard[x][y] = " ";
                    }
                }
            }
        } else if(gameboard[X5.x +1][X5.y] == "O" || gameboard[X6.x + 1][X6.y] == "O"){
        gameboard[X1.x][X1.y] = "O";
        gameboard[X2.x][X2.y] = "O";
        gameboard[X5.x][X5.y] = "O";
        gameboard[X6.x][X6.y] = "O";
        X1 = {0,0};
        X2 = {1,0};
        X5 = {2,0};
        X6 = {2,1};
        } 
        } else if (X5.x == height - 1) {     
        gameboard[X1.x][X1.y] = "O";
        gameboard[X2.x][X2.y] = "O";
        gameboard[X5.x][X5.y] = "O";
        gameboard[X6.x][X6.y] = "O";
        X1 = {0,0};
        X2 = {1,0};
        X5 = {2,0};
        X6 = {2,1};
    }    

    for(int row = 0; row < height; row++){
    clr(row);
    } 
}


void Draw() {
drawSquare();

    for(int x = 0; x < height; x++){

        for(int y = 0; y < width; y++){
            cout << gameboard[x][y];
        } 
        cout << endl;
    }
    cout << "Score:" << score << endl;

    system("cls");
}

int main(){ 
    while(cont){
        input();
        Draw();
    }
}
