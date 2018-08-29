#define ARRAY_H

bool duplicate(int numbers[], int length, int *deplication);

bool FindInMatrix(int *matrix, int rows, int columns, int number);

int MinInOrder(int *numbers, int i, int j);

int Min(int *numbers, int length);

bool HasPathCore(char *matrix, int rows, int columns, int row, int column, const char *str, int &pathLength, bool *visited);
bool HasPath(char *matrix, int rows, int columns, char *str);

int MaxSubSum(int *numbers, int length);

int GetDigitSum(int number);
bool Check(int k, int rows, int columns, int row, int column, bool *visited);
int MovingCountCore(int k, int rows, int columns, int row, int column, bool *visited);
int MovingCount(int k, int rows, int columns);

int NumberOf1_normal(int n);