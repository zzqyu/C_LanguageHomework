#include <stdio.h>
#include <stdlib.h> //exit에 이용 
#define SIGN '#'// 조건 해당 부분의 모양을 정의했다. 
void main(){
	int num, x, y, x0, y0, w, h, r;

	do {
        
        //메뉴 
		printf("=============================\n");
		printf("==   MENU                  ==\n");
		printf("==   1. Rectangle          ==\n");
		printf("==   2. Triangle           ==\n");
		printf("==   3. Circle             ==\n");
		printf("==   4. Free               ==\n");
		printf("==   5. Exit               ==\n");
		printf("=============================\n");
		printf("Select an item (1-5): \n");
		scanf("%d", &num);

		switch (num)
		{
		case 1: //1. Rectangle
			printf("Input x, y, width, height: ");
			scanf("%d %d %d %d", &x0, &y0,&w,&h);
				for (y = 0; y <= 40; y++) { 
                    printf("%d ",y%10);//세로줄 숫자 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//가로줄 숫자 
                      }
					else if (x >= x0 && x <= x0 + w&& y >= y0 && y <= y0 + h) {
						printf("%c ", SIGN);//위 조건에 해당될 때 SIGN에 정의된 문자를 출력한다. 
					}
					else {
						printf(". ");// else if에 조건에 해당되지 않으면 . 을 출력한다. 
					}
				}
				
				printf("\n");
			}
			break;
		case 2: //2. Triangle	
			printf("Input x, y, width, height: ");
			scanf("%d %d %d %d", &x0, &y0, &w, &h);
		for (y = 0; y <= 40; y++) { 
                    printf("%d ",y%10);//세로줄 숫자 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//가로줄 숫자 
                      }
					else if (y-(y0+h)>=-x+(x0-w/2)&&y-(y0+h)>=x-(x0+w/2)&&y<=y0+h) {
						printf("%c ", SIGN);//위 조건에 해당될 때 SIGN에 정의된 문자를 출력한다. 
					}
					else {
						printf(". ");// else if에 조건에 해당되지 않으면 . 을 출력한다. 
					}
				}
				printf("\n");
			}
			break;
		case 3: //3. Circle 
			printf("Input x, y, radius: ");
			scanf("%d %d %d", &x0, &y0, &r);
			for (y = 0; y <= 40; y++) { 
                    printf("%d ",y%10);//세로줄 숫자 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//가로줄 숫자 
                      }
					else if ((x - x0)*(x - x0) + (y - y0)*(y - y0)<r*r) {
						printf("%c ", SIGN);//위 조건에 해당될 때 SIGN에 정의된 문자를 출력한다. 
					}
					else {
						printf(". ");// else if에 조건에 해당되지 않으면 . 을 출력한다. 
					}
				}
				printf("\n");
			}
			break;
		case 4: //free
			printf("Input x, y, radius: ");
			scanf("%d %d %d", &x0, &y0, &r);
			for (y = 0; y <= 40; y++) { 
                    printf("%d ",y%10);//세로줄 숫자 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//가로줄 숫자 
                      }
					else if ((y>=-x+(2*x0-r)&&y>=x-r&&y<=y0)||(y>=y0&&x>=x0-r/2&&x<=x0+r/2&&y<=y0+r)) {
						printf("%c ", SIGN);//위 조건에 해당될 때 SIGN에 정의된 문자를 출력한다. 
					}
					else {
						printf(". ");// else if에 조건에 해당되지 않으면 . 을 출력한다. 
					}
				}
				printf("\n");
			}
			break;
		case 5: printf("프로그램이 종료됩니다.\n");  break;//프로그램이 종료된다고 출력된 다음 종료가 된다. 
		default: printf("1에서 5까지의 자연수를 입력하세요\n"); break;//1-5 이외의 다른 수나 문자를 입력할때 저 안내가 뜨고 다시 메뉴가 뜬다. 
		}
		
	} while (num != 5);//이 do - while 문은 not 5일때 무한루프로 돈다. 
exit(0);
}
