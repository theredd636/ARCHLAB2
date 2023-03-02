/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// x2 = x1 + x0
// x3 = x2 + x1

int main()
{
   int num1 = 1;
   int num2 = 0;
   int sum = 0;
   
   for(int i = 0; i < 9 ; i++)
   {
       sum = num1 + num2;
       num2 = num1;
       num1 = sum;
       
       cout << "The sum is " << sum << "\n";
   }
}


//sum = x5
//num1 = x6
//num2 = x7
// i = x8

    stw 0 , x5   #sum = 0 
    stw 1 , x6  # num1 = 1
    stw 0 , x7  # num2 = 0
    stw 0 , x8 # i = 0
loop1
    beq x8 , 9 , end    # skip to end if i == 9
    add x5, x6, x7 # x5 = x6 + x7
    sw x6, 0(x7)   # num1 -> num2
    sw x5, 0(x6)   # sum -> num1
    addi x8, x8 , 1 # i++ 
    beq x0 , x0,loop1 #go back to the start of the loop 
end
    
