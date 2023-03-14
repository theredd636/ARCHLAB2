#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void parseFromFile(FILE* fp,char* inst,char* inst2,int* reg1);
void parseRemainder(FILE* fp,char* inst,char* inst2,int* reg2,int* reg3,int* imm);
void codeToHex(char* output,int rd,int rs1,int rs2,int immx,char hex[]);
void decimalToBinaryReg(int num,int binaryNum[]);
void binaryToHex(int binary[],char hex[]);
void decimalToBinaryIMM(int num,int binaryNum[]);