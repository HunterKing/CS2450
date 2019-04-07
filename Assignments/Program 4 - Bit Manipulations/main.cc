#include <stdio.h>

int getMask(int, int, int);
int getSubInt(int, int, int);
void printDashHex(int);

int main(void)
{
	printDashHex(5);
	printDashHex(0x12AB);
}