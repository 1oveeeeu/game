#include<stdio.h>

void move(int n,char begin,char end)
	{
	printf("将%d从%c移动到%c\n", n, begin, end);
	}
void hanoi(int n, char begin, char mid, char end)
{
	if (n == 1)
	{
		move(n, begin, end);
	}
	else
	{
		hanoi(n - 1, begin, end, mid);
		move(n, begin, end);
		hanoi(n - 1, mid, begin, end);
	}
}
int main()
{
	int n =0;
	printf("请输入:");
	scanf_s("%d", &n);
	
	hanoi(n, 'A', 'B', 'C');
	return 0;
}