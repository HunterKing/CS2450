#include <stdio.h>
#include <limits.h>

double getIntArrayAverage(int myArray[], int numItems)
{
	double average = 0;
	for (int i = 0; i < numItems; i++)
	{
		average += myArray[i];
	}
	return average / numItems;
}

int getIntArrayMax(int myArray[], int numItems)
{
	int max = myArray[0];
	if (numItems == 0)
	{
		max = INT_MIN;
	}
	for (int i = 0; i < numItems; i++)
	{
		if(myArray[i] > max)
		{
			max = myArray[i];
		}
	}
	return max;
}

int getIntArrayMin(int myArray[], int numItems)
{
	int min = myArray[0];
	if (numItems == 0)
	{
		min = INT_MIN;
	}
	for (int i = 0; i < numItems; i++)
	{
		if(myArray[i] < min)
		{
			min = myArray[i];
		}
	}
	return min;
}

int getValueCount(int myArray[], int numItems, int search)
{
	int searchCount = 0;
	for (int i = 0; i < numItems; i++)
	{
		if(myArray[i] == search)
		{
			searchCount++;
		}
	}
	return searchCount;
}

int getMaxCount(int myArray[], int numItems)
{
	int maxVal = getIntArrayMax(myArray, numItems);
	return getValueCount(myArray, numItems, maxVal);
}