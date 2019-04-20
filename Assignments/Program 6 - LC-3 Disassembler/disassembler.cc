#include <stdio.h>
#include <string.h>
#define LIMIT 40
#define DESTREG 0x00E0
#define PCOFFSET9 0x01FF

void printAssembly(char filename[]);
void printBr(int, int);
void printAdd(int);
void printLd(int, int);

//**************************************************
//Make sure to comment main out before submitting
//**************************************************

int main()
{
	char filename[] = "test1.hex";
	printAssembly(filename);
}



void printAssembly(char filename[])
{
	FILE *infile;	
	infile = fopen(filename, "r");
	
	if (infile == NULL)	{
		printf("File %s is null.\n", filename);			
	} else {
    int count = 0;
    int instruction = 0; 
    int pc = 0;
    fscanf(infile, "%d", &pc); //Read the first hex val as the starting pc.
    while (fscanf(infile, "%x", &instruction) != EOF && count < LIMIT) {
      count++;  //Count number of lines for limit
      //Remove the print and put your code here
      //printf("%X\n", instruction);
      pc++; //Increment the PC
      int opcode = instruction >> 12; //Figure out the opcode from the high 4 bits. 
      int instrNoOp = instruction & 0x0FFF;
      switch(opcode)
      {
        case 0:
          printBr(instrNoOp, pc);
          break;
        case 1:
          printAdd(instrNoOp);
          break;
        case 2:
          printLd(instrNoOp, pc);
          break;
        case 3:
          printSt();
          break;
        /*case 4:
          printJsrJsrr();
          break;
        case 5:
          printAnd();
          break;
        case 6:
          printLdr();
          break;
        case 7:
          printStr();
          break;
        case 8:
          printRti();
          break;
        case 9:
          printNot();
          break;
        case 10:
          printLdi();
          break;
        case 11:
          printSti();
          break;
        case 12:
          printJmpRet();
          break;
        case 13:
          break;
        case 14:
          printLea();
          break;
        case 15:
          printTrap();
          break;*/
        default:
          break;
      }
      //Pass the function the full instruction and the PC, but only if necessary.
    }
  }
}

void printBr(int instruction, int pc)
{
  int n = (instruction & 0x0800) >> 11;
  int z = (instruction & 0x0400) >> 10;
  int p = (instruction & 0x0200) >> 9;
  int offset = (instruction & PCOFFSET9) << 23;
  offset = offset >> 23;
  printf("BR");
  if(n)
    printf("N");
  if(z)
    printf("Z");
  if(p)
    printf("P");
  printf("\tx%d\n", pc + offset);
}

void printAdd(int instruction)
{
  int destReg = (instruction & DESTREG) >> 9;
  int srcRegOne = (instruction & 0x01C0) >> 6;
  printf("ADD\tR%d, R%d, ", destReg, srcRegOne);
  if(instruction & 0x0020) //check if bit 5 is set to 1
  {
    int immediate = (instruction & 0x0001F) << 27; //Shift immediate add left in order to sign extend correctly.
    immediate = immediate >> 27;
    printf("#%d\n", immediate);
  } 
  else
  {
    int srcRegTwo = instruction & 0x0007;
    printf("R%d\n", srcRegTwo);
  }
}

void printLd(int instruction, int pc)
{
  int destReg = (instruction & DESTREG) >> 9;
  int offset = (instruction & PCOFFSET9) << 23;
  offset = offset >> 23;
  printf("LD\tR%d, x%d\n", destReg, pc + offset);
}

void printSt(int instruction, int pc)
{
  int destReg = (instruction & DESTREG) >> 9;
  int offset = (instruction & PCOFFSET9) << 23;
  offset = offset >> 23;
  printf("ST\tR%d, x%d\n", destReg, pc + offset);
}
