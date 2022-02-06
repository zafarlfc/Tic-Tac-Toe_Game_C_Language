# include <stdio.h>

# define SIZE 10

void Main_Menu(void);                             // function prototype
void Board(char *A);                              // function prototype
int Win_Check(char *A,char Player1,char Player2); // function prototype

int main()
{
	Main_Menu();                   // Function to display main menu of game
	int choice,playagain;           
	char Player1,Player2;          // initializing variables for player's symbols
	
    do {                           // do while loop
		char A[SIZE]="         ";  // declaring string of 9 spaces            
		printf ("Player 1 make your choice:> ");   // Taking input from player1 
     	scanf ("%d",&choice);                       // for 3 main menu options
        if (choice==1){             // choice 1 and 2 are to  
		    Player1='X';            // select symbols for players
		    Player2='O';
		}
	    else if (choice==2){
		    Player1='O';
		    Player2='X';
		}
	    else if (choice==3){        // choice 3 is to exit the game
		    break;
	    }
	    else {                      // if user enters choice other than 1,2,3 
		    printf ("\n\t\t\t   Invalid Choice! Choose Again\n\n");
		    continue;	}
		printf ("\n\tPlayer1=> %c\n",Player1);   // printing player's symbols
		printf ("\tPlayer2=> %c\n",Player2);
		// Board function will display tic-tac-toe board 
		Board(A);                             
		int Turn,Win,player;          
		int i;                    // initializing counter
		for (i=1;i<SIZE;i++){     // run loop until counter is less than 10
	        // for odd counter it is player1 turn and for even player2	
			player=(i%2 ? 1 : 2);      
			printf ("\n\t\t\tPlayer %d Turn Enter Box No.(1-9): ",player);
			scanf ("%d",&Turn);
			// if player move is not betwwen 1 and 9
			// or if player wants to overwrite the board
			// keep on taking input from player for his move until its correct
			while (Turn<1 || Turn>9 || A[Turn-1]!=' '){              
				printf ("\n\t\t\t    Invalid Move!Choose Again.");
				printf ("\n\n\t\t\tPlayer %d Turn Enter Box No.(1-9): ",player);
				scanf ("%d",&Turn);
			}
			if (player==1){         // if it is player1 turn 
				A[Turn-1]=Player1;  // then change the entered box number
			}                       // index of the array with player1 symbol
			else{                   // Do same for player2 Turn
				A[Turn-1]=Player2;    
			}
			printf ("\n\n\n\n");
			Board(A);              // Again printing board after modifiacation
			// Win_Check function will check if any player has won
			Win=Win_Check(A,Player1,Player2);   
			if (Win==1){               // if function returns 1 Player1 wins
				printf ("\n\t\t\t\t Player 1 Wins!!!");
				break;
			}
			else if (Win==2){       // else if function returns 2 player2 wins
				printf ("\n\t\t\t\t Player 2 Wins!!!");
				break;
			}
			else if (i==9){ // if the loop has repeated 9 times the game has drawn
		        printf ("\n\t\t\t\t   Game Draw!");
        	}
			
		}
		printf ("\n\n\t\t  Do you want to play again(1 for yes,3 to quit)? ");
		scanf ("%d",&playagain);     // Asking players if they want to play again
		if (playagain==1){
			puts(" ");
		}
		else {
			break;
		}
		Main_Menu();
    }while (choice!=3);
}

void Main_Menu(void)
{
	printf ("\t\t\t********* T i c   T a c    T o e *********\n");
	printf ("---------MENU---------\n\n");
	printf ("1 : Play with X\n");
	printf ("2 : Play with O\n");
	printf ("3 : Exit\n");
}

void Board(char *A )
{   // printing array in the form of a board
	printf ("\n\t\t\t\t  %c  |  %c  |  %c \n",A[0],A[1],A[2]);
	printf ("\t\t\t\t-----------------\n");
	printf ("\t\t\t\t  %c  |  %c  |  %c \n",A[3],A[4],A[5]);
	printf ("\t\t\t\t-----------------\n");
	printf ("\t\t\t\t  %c  |  %c  |  %c \n",A[6],A[7],A[8]);
}		

int Win_Check(char *A,char Player1,char Player2)
{
	int j;
	// this loop will check 
	// if any row in the board is equal to any player symbol
	for (j=0;j<9;j=j+3){      
		if (A[j]==Player1 && A[j+1]==Player1 && A[j+2]==Player1){
			return 1;          // return 1 if player1 wins
		}
		else if(A[j]==Player2 && A[j+1]==Player2 && A[j+2]==Player2){
			return 2;          // return 2 if player2 wins
		}
	} // this loop will check 
	  // if any column in the board is equal to any player symbol
	for (j=0;j<3;j++){         
		if (A[j]==Player1 && A[j+3]==Player1 && A[j+6]==Player1){
			return 1;
		}
		else if(A[j]==Player2 && A[j+3]==Player2 && A[j+6]==Player2){
			return 2;
		}
	}   // Below all if else statements will check 
	    //if any diagonal in the board is equal to any player symbol
	if (A[0]==Player1 && A[4]==Player1 && A[8]==Player1){
		return 1;
	}
	else if (A[0]==Player2 && A[4]==Player2 && A[8]==Player2){
		return 2;
	}
	else if (A[2]==Player1 && A[4]==Player1 && A[6]==Player1){
		return 1;
	}
	else if (A[2]==Player2 && A[4]==Player2 && A[6]==Player2){
		return 2;
	}
}


