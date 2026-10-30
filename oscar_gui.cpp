#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
using namespace std;

// Same game logic as oscar.cpp, but placeDown takes the clicked cell instead of cin
class classGrid{
    public:
        char grid[3][3]={
            {' ',' ',' '},
            {' ',' ',' '},
            {' ',' ',' '}
        };
        char player[2]={'X','O'};
        bool win_status=false;
        bool placeDown(int turn, int row, int column){
            if(grid[row][column]==' '){
                grid[row][column]=player[turn];
                return true;
            }
            return false;
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
        void reset(){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    grid[i][j]=' ';
                }
            }
            win_status=false;
        }
};

class GameWindow : public QWidget{
    public:
        classGrid playingGrid;
        int turn=0, number_of_play=0;
        QPushButton* cells[3][3];
        QLabel* status;

        GameWindow(){
            setWindowTitle("Tic-Tac-Toe");
            setStyleSheet("QWidget { background: #1e1e2e; }"
                          "QLabel { color: #cdd6f4; font-size: 22px; }"
                          "QPushButton#newGame { background: #45475a; color: #cdd6f4; font-size: 16px;"
                          " padding: 8px; border-radius: 6px; }");

            status = new QLabel("Player X's turn");
            status->setAlignment(Qt::AlignCenter);

            QGridLayout* board = new QGridLayout;
            board->setSpacing(6);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cells[i][j] = new QPushButton(" ");
                    cells[i][j]->setFixedSize(110,110);
                    setCellStyle(cells[i][j], ' ');
                    board->addWidget(cells[i][j], i, j);
                    connect(cells[i][j], &QPushButton::clicked, this, [this, i, j](){ cellClicked(i, j); });
                }
            }

            QPushButton* newGame = new QPushButton("New Game");
            newGame->setObjectName("newGame");
            connect(newGame, &QPushButton::clicked, this, [this](){ resetGame(); });

            QVBoxLayout* layout = new QVBoxLayout(this);
            layout->addWidget(status);
            layout->addLayout(board);
            layout->addWidget(newGame);
        }

        void setCellStyle(QPushButton* cell, char mark){
            QString color = mark=='X' ? "#f38ba8" : "#89b4fa";
            cell->setStyleSheet("QPushButton { background: #313244; color: " + color + ";"
                                " font-size: 56px; font-weight: bold; border-radius: 8px; }"
                                "QPushButton:hover { background: #45475a; }");
        }

        // One click = one pass of the loop body in oscar.cpp's main
        void cellClicked(int row, int column){
            if(playingGrid.win_status==true || number_of_play>=9){
                return;
            }
            turn=number_of_play%2;
            if(!playingGrid.placeDown(turn, row, column)){
                status->setText("Invalid, pick another cell");
                return;
            }
            display(row, column);
            playingGrid.checkWin(playingGrid.grid, turn);
            number_of_play++;
            if(playingGrid.win_status==true){
                status->setText(QString("Player ") + playingGrid.player[turn] + " wins!");
            }
            else if(number_of_play==9){
                status->setText("Draw!");
            }
            else{
                status->setText(QString("Player ") + playingGrid.player[number_of_play%2] + "'s turn");
            }
        }

        void display(int row, int column){
            char mark = playingGrid.grid[row][column];
            cells[row][column]->setText(QString(mark));
            setCellStyle(cells[row][column], mark);
        }

        void resetGame(){
            playingGrid.reset();
            turn=0;
            number_of_play=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cells[i][j]->setText(" ");
                }
            }
            status->setText("Player X's turn");
        }
};

int main(int argc, char* argv[]){
    QApplication app(argc, argv);
    GameWindow window;
    window.show();
    return app.exec();
}
