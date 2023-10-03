#include <iostream>
#include <stdio.h>
using namespace std;

char board [3] [3]={ {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
int current_marker;
int current_player;
int k=10;
int P=0;


void drawBoard()
{
    cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
    cout<<" ---------\n";


    cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
    cout<<" ---------\n";


    cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;

}








void placeMarker(int slot)

{int row=slot/3;
int col;

if(slot%3==0)
{row=row-1;
col=2;}

else col= slot%3 - 1;

if(isdigit(board[row][col])!=0)
{board[row][col]=current_marker;
P=1;}

else if (current_player==2 && isdigit(board[row][col])==0)
{current_player=current_player -1;
k++;
P=0;
cout<<endl<<"                      INVALID MOVE, CHOOSE AGAIN"<<endl<<endl;}


else if (current_player==1 && isdigit(board[row][col])==0)
{current_player++;
k++;
P=0;
cout<<endl<<"                      INVALID MOVE, CHOOSE AGAIN"<<endl<<endl;}

}






int winner()

{int i,j;

for(i=0;i<3;i++)
{if(board[i][0]==board[i][1] && board[i][1]==board[i][2]) return current_player;
} //row

for(j=0;j<3;j++)
{if(board[0][j]==board[1][j] && board[1][j]==board[2][j]) return current_player;
} //col


if(board[0][0]==board[1][1] && board[1][1]==board[2][2]) return current_player; //diag princ

if(board[0][2]==board[1][1] && board[1][1]==board[2][0]) return current_player; // diag sec

else return 0;

}





int switch_marker_and_player()
{
if(current_player==1)
current_player=2;
else current_player=1;

}





void game()

{char marker_p1,marker_p2,next_marker;

    cout<<"Player one, choose your marker: ";
    cin>>marker_p1; cout<<endl;
    cout<<"Player two, choose your marker: ";
    cin>>marker_p2;

    next_marker=marker_p2;
    current_player=1;
    current_marker=marker_p1;
    cout<<endl;
    drawBoard();
    cout<<endl;
    int player_won;

    for(int i=1;i<k;i++)
    {cout<<"It's player "<<current_player<<"'s turn, choose your slot: ";
    int slot;
    cin>>slot;
    placeMarker(slot);
    drawBoard();
    switch_marker_and_player();


    if(P==1)

    {int aux;
    aux=current_marker;
    current_marker=next_marker;
    next_marker=aux;}

    player_won=winner();
    if(player_won==2) {cout<<"                    Player 1 is the WINNER"<<endl; break;}
    if(player_won==1) {cout<<"                    Player 2 is the WINNER"<<endl; break;}

}

if(player_won==0) cout<<"It's a TIE";

}




int main()
{game();

return 0;
}
