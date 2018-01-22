#include <stdio.h>
#include <time.h>
int main()
{
	int i, a = 73, c = 97, m = 36, x = time(0) % m, r1, r2;
	int draw = 0, win = 0, lose = 0;
	
	for (i = 0; i < 10; i++){
		x = (a*x + c) % m;
		if (x < 6)
			printf("You: %d, ", r1 = x + 1);
		else
			printf("You: %d, ", r1 = x / 6 + 1);
		x = (a*x + c) % m;
		if (x < 6)
			printf("Computer: %d --->  ", r2 = x + 1);
		else
			printf("Computer: %d --->  ", r2 = x / 6 + 1);

		if (r1 == r2){
			printf("Draw\n");
			draw = draw++;
		}
		else if (r1 > r2){
			printf("Win\n");
			win = win++;
		}
		else{
			printf("Lose\n");
			lose = lose++;
		}
		
	}
	printf("\n\n\n");
	printf("# of Wins: %d\n", win);
	printf("# of Lossed: %d\n", lose);
	printf("# of Draws: %d\n", draw);
	
	return 0;
	
}