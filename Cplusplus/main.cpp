#include "Array.h"
#include "Sort.h"
#include "other.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	char p[] = "abcdefghijklmnopqrst";
	char q[30]="0123456789";
	char test[30] = "-256.0100";
	int m = -0;

	//���Կ���
	int quick[10] = { 54, 5, 78, 2, 4, 6, 98, 12, 9, 8 };
	QuickSort(quick, 0, 9);

	cout << atof(test) << endl;
	cout << Atof(test) << endl;
	//cout << Atoi(q) << endl;
	int *pInt = new int[10];
	Memset(pInt, -1, sizeof(int)* 10);
	for (auto i = 0; i < 10; i++)
	{
		cout << pInt[i] << " " << endl;
	}
	char *str = Strcpy(q, p);
	//MemoryCopy(p+5,p,3);
	cout << str << endl;
	cout << ENDINESS << endl;
	/*int numbers[7] = { 6, 5, 4, 3, 2, 1, 0 };
	int deNumber = 0;
	int flag = duplicate(numbers, 7, &deNumber);*/
	int sort[] = { 6, 10, 10, 3, 7,1,8 };
	QuickSort(sort, 0, 6);
	return 0;
}

