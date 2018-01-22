#include <stdio.h>
#include <stdlib.h> //exit�� �̿� 
#define SIGN '#'// ���� �ش� �κ��� ����� �����ߴ�. 
void main(){
	int num, x, y, x0, y0, w, h, r;

	do {
        
        //�޴� 
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
                    printf("%d ",y%10);//������ ���� 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//������ ���� 
                      }
					else if (x >= x0 && x <= x0 + w&& y >= y0 && y <= y0 + h) {
						printf("%c ", SIGN);//�� ���ǿ� �ش�� �� SIGN�� ���ǵ� ���ڸ� ����Ѵ�. 
					}
					else {
						printf(". ");// else if�� ���ǿ� �ش���� ������ . �� ����Ѵ�. 
					}
				}
				
				printf("\n");
			}
			break;
		case 2: //2. Triangle	
			printf("Input x, y, width, height: ");
			scanf("%d %d %d %d", &x0, &y0, &w, &h);
		for (y = 0; y <= 40; y++) { 
                    printf("%d ",y%10);//������ ���� 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//������ ���� 
                      }
					else if (y-(y0+h)>=-x+(x0-w/2)&&y-(y0+h)>=x-(x0+w/2)&&y<=y0+h) {
						printf("%c ", SIGN);//�� ���ǿ� �ش�� �� SIGN�� ���ǵ� ���ڸ� ����Ѵ�. 
					}
					else {
						printf(". ");// else if�� ���ǿ� �ش���� ������ . �� ����Ѵ�. 
					}
				}
				printf("\n");
			}
			break;
		case 3: //3. Circle 
			printf("Input x, y, radius: ");
			scanf("%d %d %d", &x0, &y0, &r);
			for (y = 0; y <= 40; y++) { 
                    printf("%d ",y%10);//������ ���� 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//������ ���� 
                      }
					else if ((x - x0)*(x - x0) + (y - y0)*(y - y0)<r*r) {
						printf("%c ", SIGN);//�� ���ǿ� �ش�� �� SIGN�� ���ǵ� ���ڸ� ����Ѵ�. 
					}
					else {
						printf(". ");// else if�� ���ǿ� �ش���� ������ . �� ����Ѵ�. 
					}
				}
				printf("\n");
			}
			break;
		case 4: //free
			printf("Input x, y, radius: ");
			scanf("%d %d %d", &x0, &y0, &r);
			for (y = 0; y <= 40; y++) { 
                    printf("%d ",y%10);//������ ���� 
				for (x =1; x <= 40; x++) {
                    if (y==0){
                      printf("%d ",x%10);//������ ���� 
                      }
					else if ((y>=-x+(2*x0-r)&&y>=x-r&&y<=y0)||(y>=y0&&x>=x0-r/2&&x<=x0+r/2&&y<=y0+r)) {
						printf("%c ", SIGN);//�� ���ǿ� �ش�� �� SIGN�� ���ǵ� ���ڸ� ����Ѵ�. 
					}
					else {
						printf(". ");// else if�� ���ǿ� �ش���� ������ . �� ����Ѵ�. 
					}
				}
				printf("\n");
			}
			break;
		case 5: printf("���α׷��� ����˴ϴ�.\n");  break;//���α׷��� ����ȴٰ� ��µ� ���� ���ᰡ �ȴ�. 
		default: printf("1���� 5������ �ڿ����� �Է��ϼ���\n"); break;//1-5 �̿��� �ٸ� ���� ���ڸ� �Է��Ҷ� �� �ȳ��� �߰� �ٽ� �޴��� ���. 
		}
		
	} while (num != 5);//�� do - while ���� not 5�϶� ���ѷ����� ����. 
exit(0);
}
