// advanced homework 25 (3A713257)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

 
int main(int argc,char** argv)
{
	int player = 0;
	int winner = 0;
	int choice = 0;
	int line = 0;
	int choose = 0;
	int random = 0;
	int scoreplayer=0, scorecomputer=0;
	int again=49;
	int board[9] = {0};
	int row[2] = {0};
	int column[2] = {0};
	int obliqueLeft[2] = {0};
	int obliqueRight[2] = {0};
	int a,i,j,k;
	for(i = 1;i<12;){
		//1-1
		system("cls");
		printf("\n\n\n\n                "); 
		for(j=2; j>=0;j--){
			for(k=0; k<3; k++){
				if(board[j*3+k]==1) printf(" X ");
				else if(board[j*3+k]==2) printf(" O ");
				else printf(" %d ",j*3+k+1);
				if(k<2) printf("|");
			}
			if(j>0) printf("\n                ---+---+---\n                ");
			else{
				printf("\n\n\n\n         Marks of Player: %d",scoreplayer);
				printf("\n        Marks of Computer: %d\n",scorecomputer);
			}
		}//1-1 end.
		if(i==1){
			a=0;
			printf("\n Please choose to play first(1) or second(2). "); 
			do{
				choose = getch()-48;
			}while(choose<0 || choose>2);
			i=2;
		}
		else if(i==11){
			//Game is over so display the final board
			//7-1
			if(winner==choose)scoreplayer+=1;
			else if(winner!=0)scorecomputer+=1;
			//7-1 end.
			//Dispay result message
			//8-1
			if(winner == 0)
				printf("\nHow boring,it is a draw\n");
			else if(winner == choose)
				printf("\nCongrations,player,YOU ARE THE WINNER!\n");
			else
				printf("\nThe WINNER is Computer.\n");
			//8-1 end.
			//9-1
			printf("\n  Play again(1)    Exit(0)");
			do{
				again=getch();
			}while(again<48 || again>49);
			if (again==48)break;
			else {
				winner=0;
				for(i=0;i<9;i++)
				board[i]=0;
				a=(a+1)%2;
				i=2;
			}//9-1 end.
		}
		else{
			//Get valid player square selection
			player = (a+i)%2+1;
			if(player==choose){
					printf("\nPlayer, please enter the number of the square "
						"where you want to place your %c. ",
						(player == 1)?'X':'O');
				do{
					choice = getch()-48;
				}while(choice<1 || choice>9 || board[choice-1]!=0);
			}
			else{
				printf("\nloading...");
				do{
		 			// Factor of computer selection
					//3-1
					choice=0;
					for(j=0;j<9;j++){
						for(k=0;k<2;k++){
							row[k]=j+k+1;
							if(row[k]/3 > j/3)
							row[k]-=3;
							column[k]=k*3+j+3;
							if(column[k]>=9)
							column[k]-=9;
							obliqueLeft[k]=k*4+j+4;
							if(obliqueLeft[k]>=12)
							obliqueLeft[k]-=12;
							obliqueRight[k]=k*2+j+2;
							if(obliqueRight[k]>=8)
							obliqueRight[k]-=obliqueRight[k]/6*6;
						}
						if(((board[row[0]]==board[row[1]] && board[row[0]]!=0)
						 || (board[column[0]]==board[column[1]] && board[column[0]]!=0))
						  && board[j]==0){
						 	choice=j+1;
						 	break;
						}
						if(j%4==0){
							if((board[obliqueLeft[0]]==board[obliqueLeft[1]] && board[obliqueLeft[0]]!=0) 
							 && board[j]==0){
							 	choice=j+1;
							 	break;
							}
						}
						if(j%2==0 && j>0 && j<=6){
							if((board[obliqueRight[0]]==board[obliqueRight[1]] && board[obliqueRight[0]]!=0) 
							 && board[j]==0){
							 	choice=j+1;
							 	break;
							}
						}
					}//3-1 end.
	 				if(choice==0){
	 					if (i<8+a){
							for(k=0;k<900;k++){
								srand(time(NULL));
			 					random=rand()%9;
			 					if(board[random]==0){
			 						choice = random+1; // choice={1,2,,...,8,9}
			 						break;
								}
							}
						}
						else{
							//5-1
							for(j=0;j<9;j++){
								if(board[j]==0){
									choice = j+1;
									break;
								}
							}//5-1 end.
						}
					}
				}while(choice<1 || choice>9 || board[choice-1]!=0);
			}
		//insert player symbol
		board[choice-1] = player ;
		//6-1
		//Check for a winning line--diagonals first
		if((board[0]==board[4] && board[0]==board[8] && board[0]!=0) ||
			(board[2]==board[4] && board[2]==board[6] && board[2]!=0))
			winner = player;
		else
			//Check rows and columns for a winning line
			for(line = 0;line <= 2;line++)
				if((board[line]==board[line+3] &&
					board[line]==board[line+6] &&
					board[line]!=0) ||
					(board[line*3]==board[line*3+1] &&
					board[line*3]==board[line*3+2] &&
					board[line*3]!=0))
					winner = player;
		//6-1 end.
		if(winner==player) i=11;
		else i++;
		}
	}
	return 0;
}
