#include "Array.h"
#include "Sort.h"
#include "other.h"

#include <iostream>

using namespace std;

int main()
{
	char p[] = "abcdefghijklmnopqrst";
	char q[30]="0123456789";
	
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

