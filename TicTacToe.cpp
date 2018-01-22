#include <stdio.h>
#include <stdlib.h> //exit에 이용, rand함수에 이용--
//0=빈칸, 1=O(player1), 2=X(player2)
void printBoard( int b[3][3] );
void clearBoard(int b[3][3]);//게임판, 플레이어 순서 초기화
void AI(int i,int b[3][3],int* x, int* y);
void Put_the_ox(int i,int* x,int* y);
int isPlaceable( int b[3][3], int x, int y );
int isGameEnded( int b[3][3], int i_);
void main(){
	int menu_num;
	int i,x,y;
	int board[3][3] = {0};
	do {

		//메뉴 
		printf("======================================\n");
		printf("======================================\n");
		printf("===  TicTacToe(틱택토)게임     =======\n");
		printf("======================================\n");
		printf("=== 게임의 모드를 선택하시오   =======\n");
		printf("======================================\n");
		printf("=== 1인용(User VS Computer)    =======\n");
		printf("=== └ 1. Com 먼저              =======\n");
		printf("=== └ 2. User 먼저             =======\n");
		printf("===  3. 2인용(Player1 VS Player2)=====\n");
		printf("===  4. TicTacToe 종료         =======\n");
		printf("======================================\n");
		printf("Select an item (1-4): \n");
		scanf("%d", &menu_num);

		switch (menu_num)
		{
		case 1: 
			i=0;
			clearBoard(board);
			do{
				if(isGameEnded( board, (i-1)%2+1)!=0){
					printBoard( board );
					if(isGameEnded( board, (i-1)%2+1)==2)
						printf("무승부입니다. \n");
					else if(isGameEnded( board, (i-1)%2+1==1))
						if((i-1)%2+1==1)
						printf("Computer(이/가) 이겼습니다.\n", (i-1)%2+1);
						else if((i-1)%2+1==2)
						printf("Player%d(이/가) 이겼습니다.\n", (i-1)%2+1);
					break;
				}
				printBoard( board );
				if(i%2+1==2)
					Put_the_ox(i,&x,&y);				
				else if (i%2+1==1)
					AI(i,board,&x,&y);
				printf("COMPUTER %d %d\n", x,y);
				if( isPlaceable(board, x, y)){
					board[x][y] = i%2+1;
					i++;
				}

			}while(1);


			break;
		case 2: break;

		case 3: //3. 2인용
			i=0;
			clearBoard(board);
			do{
				if(isGameEnded( board, (i-1)%2+1)!=0){
					printBoard( board );
					if(isGameEnded( board, (i-1)%2+1)==2)
						printf("무승부입니다. \n");
					else if(isGameEnded( board, (i-1)%2+1==1))
						printf("Player%d(이/가) 이겼습니다.\n", (i-1)%2+1);
					break;
				}
				printBoard( board );
				Put_the_ox(i,&x,&y);
				if( isPlaceable(board, x, y)){
					board[x][y] = i%2+1;
					i++;
				}
			}while(1);


			break;
		case 4: printf("프로그램이 종료됩니다.\n");  break;//프로그램이 종료된다고 출력된 다음 종료가 된다. 
		default: printf("1에서 4까지의 자연수를 입력하세요\n"); break;//1-5 이외의 다른 수나 문자를 입력할때 저 안내가 뜨고 다시 메뉴가 뜬다. 
		}

	} while (menu_num != 4);//do - while 문은 not 4일때 무한루프로 돈다. 
	exit(0);
}

void printBoard( int b[3][3] )
{

	int i, j;
	for( i=0; i < 3; i++ ) {
		for( j=0; j < 3; j++ ) {
			switch(b[i][j]){
			case 0: printf("[ ]");break;
			case 1: printf("[O]");break;
			case 2: printf("[X]");break;
			}
		}
		printf("\n");
	}
}

void clearBoard(int b[3][3]){
	int j,k;
	for(j=0; j<=2;j++){
		for(k=0; k<=2; k++)
			b[j][k]=0;
	}
}

int isPlaceable( int b[3][3], int x, int y ){

	return (b[x][y]== 0)&&(x >= 0)&&x <= 2&&y >= 0&&y <= 2;
}
int isGameEnded( int b[3][3], int i_){
	if(i_!=0){
		if((b[0][0]==i_&&b[0][1]==i_&&b[0][2]==i_)||//가로
			(b[1][0]==i_&&b[1][1]==i_&&b[1][2]==i_)||
			(b[2][0]==i_&&b[2][1]==i_&&b[2][2]==i_)||

			(b[0][0]==i_&&b[1][0]==i_&&b[2][0]==i_)||//세로
			(b[0][1]==i_&&b[1][1]==i_&&b[2][1]==i_)||
			(b[0][2]==i_&&b[1][2]==i_&&b[2][2]==i_)||

			(b[0][0]==i_&&b[1][1]==i_&&b[2][2]==i_)||//대각선
			(b[2][0]==i_&&b[1][1]==i_&&b[0][2]==i_))
			return 1;
		else if (b[0][0]!=0&&b[0][1]!=0&&b[0][2]!=0&&
			b[1][0]!=0&&b[1][1]!=0&&b[1][2]!=0&&
			b[2][0]!=0&&b[2][1]!=0&&b[2][2]!=0)
			return 2;
		else
			return 0;
	}
	else
		return 0;
}

void AI(int i,int b[3][3], int* x, int* y){
	int m,n;
	if(i==0){
		*x=1;
		*y=1;
	}
	else if(i==2){
		while(1){
			*x=(((int)abs(rand()))%2)*2;
			*y=(((int)abs(rand()))%2)*2;
			if(isPlaceable(b, *x, *y))
				break;
		}
	}
	else{
		while(1){
		for(m=0;m<=2;m++){
			for(n=0;n<=2;n++){
				if(b[m][n]==0){
					*x=m;*y=n;
				break;}
			}
			break;
		}
		if(isPlaceable(b, *x, *y))
				break;
		}
		

	}
}
void Put_the_ox(int i,int* x,int* y){
	printf("Player %d:", i%2+1 );
	scanf( "%d %d", &*x, &*y );
}

