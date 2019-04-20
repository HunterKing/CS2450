#include <stdio.h>
#include <string.h>
#define LIMIT 40
#define DESTREG 0x00E0
#define PCOFFSET9 0x01FF

void printAssembly(char filename[]);
void printBr(int, int);
void printAdd(int);
void printLd(int, int);
void printSt(int, int);
void printJsrJsrr(int, int);
void printAnd(int);
void printLdr(int);
void printStr(int);
void printRti();
void printNot(int);
void printLdi(int, int);
void printSti(int, int);
void printJmpRet(int);
void printLea(int, int);
void printTrap(int);

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
          printSt(instrNoOp, pc);
          break;
        case 4:
          printJsrJsrr(instrNoOp, pc);
          break;
        case 5:
          printAnd(instrNoOp);
          break;
        case 6:
          printLdr(instrNoOp);
          break;
        case 7:
          printStr(instrNoOp);
          break;
        case 8:
          printRti();
          break;
        case 9:
          printNot(instrNoOp);
          break;
        case 10:
          printLdi(instrNoOp, pc);
          break;
        case 11:
          printSti(instrNoOp, pc);
          break;
        case 12:
          printJmpRet(instrNoOp);
          break;
        case 13:
          break;
        case 14:
          printLea(instrNoOp, pc);
          break;
        case 15:
          printTrap(instrNoOp);
          break;
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

void printJsrJsrr(int instuction, int pc)
{
  if(instruction >> 11)
  {
    int offset = (instruction & 0x07FF) << 21;
    offset = offset >> 21;
    printf("JSR\tx%d", pc + offset);
  }
  else
  {
    int baseReg = (instruction & 0x01C0) >> 6;
    print("JSRR\tR%d", baseReg);
  }
}

void printAnd(int instruction)
{
  printf("\n");
}

void printLdr(int instruction)
{
  printf("\n");
}

void printStr(int instruction)
{
  printf("\n");
}

void printRti()
{
  printf("RTI");
}

void printNot(int instruction)
{
  printf("\n");
}

void printLdi(int instruction, int pc)
{
  printf("\n");
}

void printSti(int instruction, int pc)
{
  printf("\n");
}

void printJmpRet(int instruction)
{
  printf("\n");
}

void printLea(int instruction, int pc)
{
  printf("\n");
}

void printTrap(int)
{
  printf("\n");
}
