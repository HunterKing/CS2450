#include <stdio.h>

int getMask(int startbit, int endbit, int bitval)
{
	int mask = 0;
	int startval = 1;
	if (startbit < 0 || endbit > 31) //Check that the start and end are within int range. 
		return 0;
	if (startbit > endbit) //Check that the start comes before the end.
		return 0;
	if (bitval != 0 && bitval != 1) //Check that bitval is a valid bit toggle.
		return 0;
	for (int i = 0; i < 32; i++)
	{
		if (i >= startbit && i <= endbit)
			mask = mask | startval;
		startval = startval << 1;
	}
	if (bitval == 0)
		mask = ~mask;

	return mask;
}

int getSubInt(int startbit, int endbit, int value)
{
	int mask = getMask(startbit, endbit, 1);
	unsigned int retValue = value & mask; //Use uint to avoid negative sign extension.
	retValue = retValue >> startbit;
	return retValue;
}

void printDashHex(int val) //Construction Zone
{
	int mask = 0xF0000000;
	int storedVal[8];
	for (int i = 0; i < 8; i++)
	{
		storedVal[i] = (unsigned)(val & mask) >> 28;
		val = val << 4;
	}
	for (int i = 0; i < 15; i++)
	{
		if (i % 2 == 0)
			printf("%X", storedVal[i/2]);
		else
			printf("-");
	}
	printf("\n");
}