#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


void menu()
{
	printf("******************************\n");
	printf("******  1.play 0 exit  *******\n");
	printf("******************************\n");
}

void game()
{
	int answer = 0;
	int guess = 0;
	answer = rand()%100+1;
	printf("%d\n", answer);
	while (1)
	{
		printf("�������:");
		scanf_s("%d", &guess);
		if (guess > answer)
		{
			printf("�´���\n");
		}
		else if (guess < answer)
		{
			printf("��С��\n");
		}
		else
		{
			printf("�¶���\n");
			break;
		}
	}


}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//���ѡ��1-100������
	do
	{
		menu();
		printf("��ѡ��:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("quit\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);


	return 0;
}
