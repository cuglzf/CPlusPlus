#include "Array.h"

int main()
{
	int numbers[7] = { 6, 5, 4, 3, 2, 1, 0 };
	int deNumber = 0;
	int flag = duplicate(numbers, 7, &deNumber);
	return 0;
}