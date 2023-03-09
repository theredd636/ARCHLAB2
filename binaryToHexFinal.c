#include <stdio.h>

int* decimalToBinaryReg(int num);




char *codeToHex(char* output,int rs1,int rs2,int rd,int immx){
    int binary[32], *rdx;
    int  *r1,*r2;
    for(int i = 0; i <= 31; i++) // sets everything to 0
    {
        binary[i] = 0;
    }
    
        if(output ==  "add"){
            binary[0]=1;
            binary[1]=1;
            binary[2]=0;
            binary[3]=0;
            binary[4]=1;
            binary[5]=1;
            binary[6]=0;
            rdx=decimalToBinaryReg(rd);
            binary[7]=rdx[0];
            binary[8]=rdx[1];
            binary[9]=rdx[2];
            binary[10]=rdx[3];
            binary[11]=rdx[4];
            binary[12]=0;
            binary[13]=0; // func 3 hard coded
            binary[14]=0;
            r1 = decimalToBinaryReg(rs1);
            binary[15] = r1[0];
            binary[16] = r1[1];
            binary[17] = r1[2];
            binary[18] = r1[3];
            binary[19] = r1[4];
            r2 = decimalToBinaryReg(rs2);
            binary[20] = r2[0];
            binary[21] = r2[1];
            binary[22] = r2[2];
            binary[23] = r2[3];
            binary[24] = r2[4];
            binary[25] = 0;
            binary[26] = 0;
            binary[27] = 0;
            binary[28] = 0; // func7 hard coded
            binary[29] = 0;
            binary[30] = 0;
            binary[31] = 0;
            
            return ;
        }
        return NULL ;

    }
int* decimalToBinaryReg(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
   int binaryNum[5]; // Assuming 32 bit integer.
   int i=0;
   for ( ;num > 0; ){
      binaryNum[i++] = num % 2;
      num /= 2;
   }
   return binaryNum;
}

char * binaryToHex(int binary[32])
{
    char hex[8];
    int temp[4];
    temp[0] = 0;
    temp[1] = 0;
    temp[2] = 0;
    temp[3] = 0;
    int skip = 0;
    
    for(int i = 0; i < 8 ; i++)
    {
        skip = (i * 4);
        binary[31 - skip] = temp[3];
        binary[30 - skip] = temp[2];
        binary[29 - skip] = temp[1];
        binary[28 - skip] = temp[0];
        
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 0;
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 1;
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 2;
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 0))
        {
            hex[7- i] = 3;
        }
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 4;
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 5;
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 6;
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 0))
        {
            hex[7- i] = 7;
        }
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 8;
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 9;
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 'a';
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 0 ) & (temp[3] == 1))
        {
            hex[7- i] = 'b';
        }
        if((temp[0] == 0) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'c';
        }
        if((temp[0] == 1) & (temp[1] == 0) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'd';
        }
        if((temp[0] == 0) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'e';
        }
        if((temp[0] == 1) & (temp[1] == 1) & (temp[2] == 1 ) & (temp[3] == 1))
        {
            hex[7- i] = 'f';
        }
    }
    return hex;
}
 rdx=decimalToBinaryReg(rd); rdx=decimalToBinaryReg(rd);
