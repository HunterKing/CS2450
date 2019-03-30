#include <stdio.h>
#include <limits.h>

//Prototypes the following six lines must 
//be here or the program will not compile
double getIntArrayAverage(int[], int);
int getIntArrayMax(int[], int);
int getIntArrayMin(int[], int);
int getValueCount(int[], int, int);
int getMaxCount(int[], int);
void showExampleOutput(int[], int, int);
void test1();
void test2();

int main()
{
	//test1();
	test2();
	return 0;
}

void test1()
{
	//Generate an array then run student functions
	int array[] = {2,3,6,3,5,1,6,6,5,4};

	//Variable num is the number of items in array
	int num = 10;

	//Show the output of the functions
	//The last argument below is the number to count in
	//getValueCount.  For example, 3 will count the number
	//of threes and show it in the output.
	showExampleOutput(array, num, 3);
	
	//Keep track of the number of fails
	int failCount = 0;

	printf("\n---------------------------------------------\n");
	printf("Test 1: \n");
	printf("---------------------------------------------\n");
	printf("Using int array {");

	//Printing each vaue in the array for reference
	for (int i = 0; i < num - 1; i++)
	{
		printf("%i, ", array[i]);
	}
	printf("%i}\n",array[num - 1]);

	
	double avg = getIntArrayAverage(array, num);
	if (avg < 4.0999999999 || avg > 4.100000000001 )
	{
		printf("Fail in getIntArrayAverage.\n");
		failCount++;
	}

	int max = getIntArrayMax(array, num);
	if (max != 6)
	{
		printf("Fail in getIntArrayMax.\n");
		failCount++;
	}
	
	int min = getIntArrayMin(array, num);
	if (min != 1)
	{
		printf("Fail in getIntArrayMin.\n");
		failCount++;
	}
	
	int count = getValueCount(array, num, 1);
	if (count != 1)
	{
		printf("Fail in getValueCount using %d.\n", 1);
		failCount++;
	}

	count = getValueCount(array, num, 3);
	if (count != 2)
	{
		printf("Fail in getValueCount using %d.\n", 3);
		failCount++;
	}

	int maxCount = getMaxCount(array, num);
	if (maxCount != 3)
	{
		printf("Fail in maxCount.\n");
		failCount++;
	}

	if (!failCount)
		printf("All tests pass.\n");

	printf("---------------------------------------------\n\n");
}


void showExampleOutput(int array[], int num, int countThis)
{	
	printf("\n---------------------------------------------\n");
	printf("Student Function Output:\n");
	printf("---------------------------------------------\n");
	printf("Using int array {");

	//Printing each vaue in the array for reference
	for (int i = 0; i < num - 1; i++)
	{
		printf("%i, ", array[i]);
	}
	printf("%i}\n",array[num - 1]);

	//Calling your methods on the given array.
	double avg = getIntArrayAverage(array, num);
	int max = getIntArrayMax(array, num);
	int min = getIntArrayMin(array, num);
	int count = getValueCount(array, num, countThis);
	int maxCount = getMaxCount(array, num);

	//Printing your results
	printf("getIntArrayAverage returned %.2f\n", avg);
	printf("getIntArrayMax returned %i\n", max);
	printf("getIntArrayMin returned %i\n", min);
	printf("getValueCount when the value is %d returned %d\n",countThis, count);
	printf("maxCount returned %d\n", maxCount);	
	printf("---------------------------------------------\n");
	printf("Make sure the above values match\n");
	printf("expected values for the given array.\n");
	printf("---------------------------------------------\n\n\n");
}

void test2()
{
	//Generate an array then run student functions
	int array[] = {};
	printf("%i\n", array[0]);

	//Variable num is the number of items in array
	int num = 0;

	//Show the output of the functions
	//The last argument below is the number to count in
	//getValueCount.  For example, 3 will count the number
	//of threes and show it in the output.
	showExampleOutput(array, num, 3);
}