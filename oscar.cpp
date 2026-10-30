#include <iostream>
using namespace std;

class classGrid{
    public:
        char grid[3][3]={
            {' ',' ',' '},
            {' ',' ',' '},
            {' ',' ',' '}
        };
        char player[2]={'X','O'};
        bool win_status=false;
        void placeDown(int turn, char (&grid)[3][3]){
            cout<<"Enter the grid you wanna place (e.g:1,2): ";
            string coordinates;
            cin>>coordinates;
            char char_row = coordinates[0];
            char char_column = coordinates[2];
            int row = char_row -'0';
            int column = char_column -'0';
           if(grid[row-1][column-1]==' '){
            grid[row-1][column-1]=player[turn];}
            else{
                cout<<"Invalid;"<<endl;
                placeDown(turn, grid);
            }
        }
        void checkWin(char (&grid)[3][3], int turn){
            char currentPlayer = player[turn];
            if((grid[0][0] == currentPlayer && grid[0][1] == currentPlayer && grid[0][2] == currentPlayer) ||
                (grid[1][0] == currentPlayer && grid[1][1] == currentPlayer && grid[1][2] == currentPlayer) ||
                (grid[2][0] == currentPlayer && grid[2][1] == currentPlayer && grid[2][2] == currentPlayer) ||
                (grid[0][0] == currentPlayer && grid[1][0] == currentPlayer && grid[2][0] == currentPlayer) ||
                (grid[0][1] == currentPlayer && grid[1][1] == currentPlayer && grid[2][1] == currentPlayer) ||
                (grid[0][2] == currentPlayer && grid[1][2] == currentPlayer && grid[2][2] == currentPlayer) ||
                (grid[0][0] == currentPlayer && grid[1][1] == currentPlayer && grid[2][2] == currentPlayer) ||
                (grid[0][2] == currentPlayer && grid[1][1] == currentPlayer && grid[2][0] == currentPlayer)){
                win_status=true;
            }
            else{
                win_status = false;
            }
        }
        void display(char (&grid)[3][3]){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<grid[i][j]<<" | ";
                }
                cout<<endl;
                cout<<"-----------"<<endl;
            }
        }
};
int main(){
    classGrid playingGrid;
    int turn=0, number_of_play=0;
    while (playingGrid.win_status!=true){
        for(;number_of_play<9;number_of_play++){
            turn=number_of_play%2;
            playingGrid.placeDown(turn, playingGrid.grid);
            playingGrid.display(playingGrid.grid);
            playingGrid.checkWin(playingGrid.grid, turn);
            if(playingGrid.win_status==true){
                break;
            }
            else{
                continue;
            }
        }
    }
    cout<<"You win!";
}