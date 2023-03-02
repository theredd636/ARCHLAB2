#include <stdio.h>
#include <string.h>

int main(){
    int array[10]={5,3,6,8,9,1,4,7,2};
    int temp;
    int size=10;
    for(int step=0;step<size-1;++step){
        for(int i=0;i<size-step-1;++i){
            if(array[i]>array[i+1]){
                temp=array[i];
                array[i]=array[i+1];
                array[i+1]=temp;
            }
        }
    }
    for(int i=0;i<size;i++){
        printf("%d\n",array[i]);
    }
}
