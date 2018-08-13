#include "Array.h"
#include "Sort.h"
#include "other.h"

#include <iostream>

using namespace std;

int main()
{
	char p[] = "I love you!";
	
	MemoryCopy(p+2,p+5,-1);

	cout << ENDINESS << endl;
	/*int numbers[7] = { 6, 5, 4, 3, 2, 1, 0 };
	int deNumber = 0;
	int flag = duplicate(numbers, 7, &deNumber);*/
	int sort[] = { 6, 10, 10, 3, 7,1,8 };
	QuickSort(sort, 0, 6);
	return 0;
}

