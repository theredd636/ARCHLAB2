#include <stdio.h>

void decimalToBinaryReg(int num , int binaryNum[])
{
    for(int lol = 0; lol < 12; lol++)
    {
        binaryNum[lol] = 0;
    }
    
    if(num > 15) // 16 or more
    {
        binaryNum[4] = 1;
        num = num - 16;
    }
    
    if(num > 7) // 8 or more
    {
        binaryNum[3] = 1;
        num = num - 8;
    }
    
    if(num > 3) //4 or more
    {
        binaryNum[2] = 1;
        num = num - 4;
    }
    if(num > 1) //2 or more
    {
        binaryNum[1] = 1l
        num = num - 2;
    }
    if(num > 0) // not zero
    {
        binaryNum[0] = 1;
        num = 0;
    }
    
    return ; 
}
