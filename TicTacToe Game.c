#include<stdio.h>
#include<conio.h>
#define ROW 3
#define COL 3

int ch,i,j;
char brd[ROW][COL]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int turn=0,key=1;
int row,col;

void board(){
// clrscr();
 printf("\t|\t|\t\n");
 printf("___%c____|___%c___|___%c____\n",brd[0][0],brd[0][1],brd[0][2]);
 printf("\t|\t|\t\n");
 printf("___%c____|___%c___|___%c____\n",brd[1][0],brd[1][1],brd[1][2]);
 printf("\t|\t|\t\n");
 printf("___%c____|___%c___|___%c____\n",brd[2][0],brd[2][1],brd[2][2]);
 printf("\t|\t|\t\n");
 printf("\t|\t|\t\n");
}

 void turns() {
    while(key!=10){ 
	if(turn==0){
	   printf("Player1:");
	   scanf("%d",&ch);
	}
	else if(turn==1){
		printf("Player2:");
	       scanf("%d",&ch);
	}

	switch(ch){
		    case 1: row=0;col=0;
		    break;
		    case 2: row=0;col=1;
		    break;
		    case 3: row=0;col=2;
		    break;
		    case 4: row=1;col=0;
		    break;
		    case 5: row=1;col=1;
		    break;
		    case 6: row=1;col=2;
		    break;
		    case 7: row=2;col=0;
		    break;
		    case 8: row=2;col=1;
		    break;
		    case 9: row=2;col=2;
		    break;
		    default: printf("Invalid choice\n");
	}
	if(turn==0 && brd[row][col]!='X' && brd[row][col]!='O'){
	  brd[row][col]='X';
	  turn++;
	}
	else if(turn==1 && brd[row][col]!='X' && brd[row][col]!='O'){
	  brd[row][col]='O';
	  turn=0;
	}
	else{
	   printf("Already occupied!\n");
	   key--;
	}

 	board();
 	for(i=0;i<3;i++)
       		if( ( brd[i][0] == 'X' && brd[i][0] == brd[i][1] && brd[i][1] == brd[i][2]  ) || ( brd[0][i] == 'X' && brd[0][i] == brd[1][i] && brd[1][i] == brd[2][i] ) ){
	 		printf("X wins!!!\n");
	 		return;
        	}
       		else if( ( brd[i][0] == 'O' && brd[i][0] == brd[i][1] && brd[i][1] == brd[i][2]  ) || ( brd[0][i] == 'O' && brd[0][i] == brd[1][i] && brd[1][i] == brd[2][i] ) ){
         		printf("O wins!!!\n");
         		return;
     		}

 	if(brd[0][0]=='X' && brd[1][1]=='X' && brd[2][2]=='X'||brd[0][2]=='X' && brd[1][1]=='X' && brd[2][0]=='X'){
   		printf("X wins!!!\n");
   		return;
 	}
 	else if(brd[0][0]=='O' && brd[1][1]=='O' && brd[2][2]=='O'||brd[0][2]=='O' && brd[1][1]=='O' && brd[2][0]=='O'){
   		printf("O wins!!!\n");
   		return;
 	}

 	key++;
     }
     if(key==10)
 	printf("Draw");
 }



int main()
{
 clrscr();
 int i,j,turn=0;

 int p1;
 char brd[ROW][COL]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
 printf("Lets begin Tic Tac Toe\n");
 board();
 turns();
 getch();
return 0;
}


