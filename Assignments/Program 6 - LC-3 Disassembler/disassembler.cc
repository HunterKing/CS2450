#include <stdio.h>
#include <string.h>
#define LIMIT 40

void printAssembly(char filename[]);
void printBr(int, int);
void printAdd(int);
void printLd(int, int);
void printSt(int, int);
void printJsrJsrr(int, int);
void printAnd(int);
void printLdr(int);
void printStr(int);
void printRti(int);
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
          printRti(instrNoOp);
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
  int offset = (instruction & 0x01FF) << 23;
  offset = offset >> 23;
  printf("BR");
  if(n)
    printf("N");
  if(z)
    printf("Z");
  if(p)
    printf("P");
  printf("\tx%X\n", pc + offset);
}

void printAdd(int instruction)
{
  int destReg = (instruction & 0x00E0) >> 9;
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
  int destReg = (instruction & 0x00E0) >> 9;
  int offset = (instruction & 0x01FF) << 23;
  offset = offset >> 23;
  printf("LD\tR%d, x%X\n", destReg, pc + offset);
}

void printSt(int instruction, int pc)
{
  int destReg = (instruction & 0x00E0) >> 9;
  int offset = (instruction & 0x01FF) << 23;
  offset = offset >> 23;
  printf("ST\tR%d, x%X\n", destReg, pc + offset);
}

void printJsrJsrr(int instruction, int pc)
{
  if(instruction >> 11)
  {
    int offset = (instruction & 0x07FF) << 21;
    offset = offset >> 21;
    printf("JSR\tx%X\n", pc + offset);
  }
  else
  {
    int baseReg = (instruction & 0x01C0) >> 6;
    printf("JSRR\tR%d\n", baseReg);
  }
}

void printAnd(int instruction)
{
  int destReg = (instruction & 0x00E0) >> 9;
  int srcRegOne = (instruction & 0x01C0) >> 6;
  if((instruction & 0x0020) >> 5)
  {
    int immediate = (instruction & 0x001F) << 27;
    immediate = immediate >> 27;
    printf("AND\tR%d, R%d, #%d\n", destReg, srcRegOne, immediate);
  }
  else
  {
    int srcRegTwo = instruction & 0x0007;
    printf("AND\tR%d, R%d, R%d\n", destReg, srcRegOne, srcRegTwo);
  }
}

void printLdr(int instruction)
{
  int destReg = (instruction & 0x00E0) >> 9;
  int baseReg = (instruction & 0x01C0) >> 6;
  int offset = (instruction & 0x003F) << 26;
  offset = offset >> 26;
  printf("LDR\tR%d, R%d, #%d\n", destReg, baseReg, offset); 
}

void printStr(int instruction)
{
  int srcReg = (instruction & 0x00E0) >> 9;
  int baseReg = (instruction & 0x01C0) >> 6;
  int offset = (instruction & 0x003F) << 26;
  offset = offset >> 26;
  printf("STR\tR%d, R%d, #%d\n", srcReg, baseReg, offset);
}

void printRti(int instruction)
{
  printf("RTI\n");
}

void printNot(int instruction)
{
  int destReg = (instruction & 0x00E0) >> 9;
  int srcReg = (instruction & 0x01C0) >> 6;
  printf("NOT\tR%d, R%d\n", destReg, srcReg);
}

void printLdi(int instruction, int pc)
{
  int destReg = (instruction & 0x00E0) >> 9;
  int offset = (instruction & 0x01FF) << 23;
  offset = offset >> 23;
  printf("LDI\tR%d, x%X\n", destReg, pc + offset);
}

void printSti(int instruction, int pc)
{
  int srcReg = (instruction & 0x00E0) >> 9;
  int offset = (instruction & 0x01FF) << 23;
  offset = offset >> 23;
  printf("STI\tR%d, x%X\n", srcReg, pc + offset);
}

void printJmpRet(int instruction)
{
  int baseReg = (instruction & 0x01C0) >> 6;
  if(baseReg == 7)
  {
    printf("RET\n");
  }
  else
  {
    printf("JMP\tR%d\n", baseReg);
  }
}

void printLea(int instruction, int pc)
{
  int destReg = (instruction & 0x00E0) >> 9;
  int offset = (instruction & 0x01FF) << 23;
  offset = offset >> 23;
  printf("LEA\tR%d, x%X\n", destReg, pc + offset);
}

void printTrap(int instruction)
{
  int trapVector = instruction & 0x00FF;
  switch(trapVector)
  {
    case 0x0020:
      printf("GETC\n");
      break;
    case 0x0021:
      printf("OUT\n");
      break;
    case 0x0022:
      printf("PUTS\n");
      break;
    case 0x0023:
      printf("IN\n");
      break;
    case 0x0024:
      printf("PUTSP\n");
      break;
    case 0x0025:
      printf("HALT\n");
      break;
    default:
      break;
  }
}
