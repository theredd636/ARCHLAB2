#include "header.h"
int programCounter=1;
int branchNum=0;
int branchFlag=0;

struct immediate{
    int location;
    char* content;
};  

struct immediate branches[10];


void parseFromFile(FILE* fp,char* inst,char* inst2,int* reg1){
    char temp[4];
    char temp2[6]="     \0";
    int i=0;
    fscanf(fp,"%s",inst);
    
    while(inst[i]!='\0'){
        if(inst[i]==':'){
            branches[branchNum].content=malloc(sizeof(char)*10);
            for(int j=0;j<i;j++){
                branches[branchNum].content[j]=inst[j];
            }
            branches[branchNum].location=programCounter;
            branchNum++;
            programCounter++;
            branchFlag++;
            return;
        }
        if(inst[0]=='j'){
            fscanf(fp,"%s",temp);
            inst[1]=programCounter+'0';
            strcpy(inst2,temp);
            programCounter++;
            return;
        }
        i++;
    }
    fscanf(fp,"%s",temp);
    if (temp[3]=='\0'){
        *reg1=(int)temp[1]-48;
    }
    else{
        *reg1=(int)temp[1]-48;
        *reg1*=10;
        *reg1+=(int)temp[2]-48;
    }
    if(strcmp(inst,"bge")==0){
    	inst2[1]=programCounter+'0';
    }
    programCounter++;

}

void parseRemainder(FILE* fp,char* inst,char* inst2,int* reg2,int* reg3,int* imm){
    if(!branchFlag){
        char temp[7];
        int count,count2=1;
        int j=11;
        int neg=0;
        int i=0;
        *reg2=0,*reg3=0,*imm=0;
        fscanf(fp,"%s",temp);
        if(strcmp(inst,"add")==0){
            if (temp[3]=='\0'){
                *reg2=(int)temp[1]-48;
            }
            else{
                *reg2=(int)temp[1]-48;
                *reg2*=10;
                *reg2+=(int)temp[2]-48;
            }
            
            fscanf(fp,"%s",temp);
	    while(temp[i+1]!='\0'){
                if(count>1){
                    *reg3*=10;
                }
                *reg3+=(int)temp[i+1]-48;
                count++;
                i++;
            }
	}    
        if(strcmp(inst,"addi")==0){
            if (temp[3]=='\0'){
                *reg2=(int)temp[1]-48;
            }
            else{
                *reg2=(int)temp[1]-48;
                *reg2*=10;
                *reg2+=(int)temp[2]-48;
            }
            
            fscanf(fp,"%s",temp);
            int i=0;
            while(temp[i]!='\0'){
                if((int)temp[i]==45){
                    neg=-1;
                }
                else{
                    j=(int)temp[i]-48;
                    if((i+neg)>0){
                        *imm*=10;
                    }
                    *imm+=j;
                }
                i++;
            }
            if(neg==-1){
                *imm*=neg;
            }
        }
        if(strcmp(inst,"bge")==0){
            if (temp[3]=='\0'){
                *reg2=(int)temp[1]-48;
            }
            else{
                *reg2=(int)temp[1]-48;
                *reg2*=10;
                *reg2+=(int)temp[2]-48;
            }
	    fscanf(fp,"%s",temp);
            for(int i=0;i<branchNum;i++){
                if(strcmp(temp,branches[i].content)==0){
                    *imm=branches[i].location-(int)inst2[1]+48;
                }
            }
        }
        if(strcmp(inst,"beq")==0){
            if (temp[3]=='\0'){
                *reg2=(int)temp[1]-48;
            }
            else{
                *reg2=(int)temp[1]-48;
                *reg2*=10;
                *reg2+=(int)temp[2]-48;
                *reg2=9;
            }
	    fscanf(fp,"%s",temp);
            for(int i=0;i<branchNum;i++){
                if(strcmp(temp,branches[i].content)==0){
                    *imm=branches[i].location-(int)inst2[1]+48;
                }
            }
        }
        if(strcmp(inst,"sw")==0){
            
        }
        if(strcmp(inst,"sll")==0){
            if (temp[3]=='\0'){
                *reg2=(int)temp[1]-48;
            }
            else{
                *reg2=(int)temp[1]-48;
                *reg2*=10;
                *reg2+=(int)temp[2]-48;
            }
            
            fscanf(fp,"%s",temp);
            
            while(temp[i]!='\0'){
                if((int)temp[i]==45){
                    neg=-1;
                }   
                else{
                    j=(int)temp[i]-48;
                    if((i+neg)>0){
                        *reg3*=10;
                    }
                    *reg3+=j;
                }
                i++;
            }
            if(neg==-1){
                *reg3*=neg;
            }
        }
        if(strcmp(inst,"lw")==0){
            while(temp[i]!='('){
                
                if((int)temp[i]==45){
                    neg=-1;
                }
                else{
                    j=(int)temp[i]-48;
                
                    if((i+neg)>0){
                        *imm*=10;
                    }
                    *imm+=j;
                }
                i++;
            }
        
            if(neg==-1){
                *imm*=neg;
            }
        
            while(temp[i]!=')'){
                
                if((int)temp[i]>47&& (int)temp[i]<58){
                
                    
                    if(count2>1){
                        *reg2*=10;
                    }
                    count2++;
                    *reg2+=(int)temp[i]-48;
                }
                i++;
            }

        }
        if(inst[0]=='j'){
            for(int i=0;i<branchNum;i++){
                if(strcmp(inst2,branches[i].content)==0){
                    *imm=branches[i].location-(int)inst[1]+48;
                }
            }
        }
    }
    else{
        branchFlag=0;
    }
}
void codeToHex(char* output,int rd,int rs1,int rs2,int immx,char hex[]){
    for(int i=0;i<8;i++){
        hex[i]='0';
    }
    int binary[32],rdx[5],r1[5],r2[5],imm[12];
    if (strcmp(output,"add")==0){
        binary[0]=1;
        binary[1]=1;
        binary[2]=0;
        binary[3]=0;
        binary[4]=1;
        binary[5]=1;
        binary[6]=0;
        decimalToBinaryReg(rd,rdx);
        binary[7]=rdx[5];
        binary[8]=rdx[4];
        binary[9]=rdx[3];
        binary[10]=rdx[2];
        binary[11]=rdx[1];
        binary[12]=0;
        binary[13]=0; // func 3 hard coded
        binary[14]=0;
        decimalToBinaryReg(rs1,r1);
        binary[15] = r1[0];
        binary[16] = r1[1];
        binary[17] = r1[2];
        binary[18] = r1[3];
        binary[19] = r1[4];
        decimalToBinaryReg(rs2,r2);
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
    }
    if (strcmp(output,"addi")==0){
        binary[0]=1;
        binary[1]=1;
        binary[2]=0;
        binary[3]=0;
        binary[4]=1;
        binary[5]=0;
        binary[6]=0;
        decimalToBinaryReg(rd,rdx);
        binary[7]=rdx[5];
        binary[8]=rdx[4];
        binary[9]=rdx[3];
        binary[10]=rdx[2];
        binary[11]=rdx[1];
        binary[12]=0;
        binary[13]=0; // func 3 hard coded
        binary[14]=0;
        decimalToBinaryReg(rs1,r1);
        binary[15] = r1[0];
        binary[16] = r1[1];
        binary[17] = r1[2];
        binary[18] = r1[3];
        binary[19] = r1[4];
        decimalToBinaryIMM(immx,imm);
        binary[20] = imm[11];
        binary[21] = imm[10];
        binary[22] = imm[9];
        binary[23] = imm[8];
        binary[24] = imm[7];
        binary[25] = imm[6];
        binary[26] = imm[5];
        binary[27] = imm[4];
        binary[28] = imm[3];
        binary[29] = imm[2];
        binary[30] = imm[1];
        binary[31] = imm[0];
    }
    if (strcmp(output,"bge")==0 || strcmp(output,"beq")==0){
        decimalToBinaryIMM(rs2,imm);
        decimalToBinaryReg(rs1,r1);
        decimalToBinaryReg(rd,r2);
        binary[0]=1;
        binary[1]=1;
        binary[2]=0;
        binary[3]=0;
        binary[4]=0;
        binary[5]=1;
        binary[6]=1;
        binary[7]=imm[4];
        binary[8]=imm[3];
        binary[9]=imm[2];
        binary[10]=imm[1];
        binary[11]=imm[0];
        binary[12]=1;
        binary[13]=0; // func 3 hard coded
        binary[14]=1;
        binary[15] = r1[5];
        binary[16] = r1[4];
        binary[17] = r1[3];
        binary[18] = r1[2];
        binary[19] = r1[1];
        binary[20] = r2[5];
        binary[21] = r2[4];
        binary[22] = r2[3];
        binary[23] = r2[2];
        binary[24] = r2[1];
        binary[25] = imm[6];
        binary[26] = imm[5];
        binary[27] = imm[4];
        binary[28] = imm[3];
        binary[29] = imm[2];
        binary[30] = imm[1];
        binary[31] = imm[0];
    }
    
    if (strcmp(output,"sll")==0){
        decimalToBinaryReg(rs2,r2);
        decimalToBinaryReg(rs1,r1);
        decimalToBinaryReg(rd,rdx);
        binary[0]=1;
        binary[1]=1;
        binary[2]=0;
        binary[3]=0;
        binary[4]=1;
        binary[5]=1;
        binary[6]=0;
        binary[7]=rdx[5];
        binary[8]=rdx[4];
        binary[9]=rdx[3];
        binary[10]=rdx[2];
        binary[11]=rdx[1];
        binary[12]=1;
        binary[13]=0; // func 3 hard coded
        binary[14]=0;
        binary[15] = r1[5];
        binary[16] = r1[4];
        binary[17] = r1[3];
        binary[18] = r1[2];
        binary[19] = r1[1];
        binary[20] = r2[5];
        binary[21] = r2[4];
        binary[22] = r2[3];
        binary[23] = r2[2];
        binary[24] = r2[1];
        binary[25] = 0;
        binary[26] = 0;
        binary[27] = 0;
        binary[28] = 0;
        binary[29] = 0;
        binary[30] = 0;
        binary[31] = 0;
    }
    if (strcmp(output,"lw")==0){
        decimalToBinaryIMM(immx,imm);
        decimalToBinaryReg(rs1,r1);
        decimalToBinaryReg(rd,rdx);
        binary[0]=1;
        binary[1]=1;
        binary[2]=0;
        binary[3]=0;
        binary[4]=0;
        binary[5]=0;
        binary[6]=0;
        binary[7]=rdx[5];
        binary[8]=rdx[4];
        binary[9]=rdx[3];
        binary[10]=rdx[2];
        binary[11]=rdx[1];
        binary[12]=0;
        binary[13]=1; // func 3 hard coded
        binary[14]=0;
        binary[15] = r1[5];
        binary[16] = r1[4];
        binary[17] = r1[3];
        binary[18] = r1[2];
        binary[19] = r1[1];
        binary[20] = imm[11];
        binary[21] = imm[10];
        binary[22] = imm[9];
        binary[23] = imm[8];
        binary[24] = imm[7];
        binary[25] = imm[6];
        binary[26] = imm[5];
        binary[27] = imm[4];
        binary[28] = imm[3];
        binary[29] = imm[2];
        binary[30] = imm[1];
        binary[31] = imm[0];
    }if (strcmp(output,"sw")==0){
        decimalToBinaryReg(rs2,r2);
        decimalToBinaryReg(rs1,r1);
        decimalToBinaryIMM(immx,imm);
        binary[0]=1;
        binary[1]=1;
        binary[2]=0;
        binary[3]=0;
        binary[4]=0;
        binary[5]=1;
        binary[6]=0;
        binary[7]=imm[4];
        binary[8]=imm[3];
        binary[9]=imm[2];
        binary[10]=imm[1];
        binary[11]=imm[0];
        binary[12]=0;
        binary[13]=1; // func 3 hard coded
        binary[14]=0;
        binary[15] = r1[5];
        binary[16] = r1[4];
        binary[17] = r1[3];
        binary[18] = r1[2];
        binary[19] = r1[1];
        binary[20] = r2[5];
        binary[21] = r2[4];
        binary[22] = r2[3];
        binary[23] = r2[2];
        binary[24] = r2[1];
        binary[25] = imm[11];
        binary[26] = imm[10];
        binary[27] = imm[9];
        binary[28] = imm[8];
        binary[29] = imm[7];
        binary[30] = imm[6];
        binary[31] = imm[5];
    }
    binaryToHex(binary,hex);
    return;
}
void decimalToBinaryReg(int num,int binaryNum[]) {
    unsigned int mask = 1U << (6-1);
    int i;
    for (i = 0; i < 6; i++) {
        binaryNum[i] = (num & mask) ? 1 : 0;
        num <<= 1;
    }
}
void decimalToBinaryIMM(int num,int binaryNum[]) {
    unsigned int mask = 1U << (12-1);
    int i;
    for (i = 0; i < 12; i++) {
        binaryNum[i] = (num & mask) ? 1 : 0;
        num <<= 1;
    }
}
void binaryToHex(int binary[],char hex[]){
    int temp[4];
    temp[0] = 0;
    temp[1] = 0;
    temp[2] = 0;
    temp[3] = 0;
    int skip = 0;
    int temp1[8];
    for(int ok = 0; ok < 8; ok++)
    {
        temp1[ok] = 0;
        printf("%c" , temp1[ok]);
    }
    puts("");
    for(int i = 0; i < 8 ; i++)
    {
        skip = (i * 4);
       // binary[31 - skip] = temp[3];
       // binary[30 - skip] = temp[2];
       // binary[29 - skip] = temp[1];
       // binary[28 - skip] = temp[0];
        
        temp[3] = binary[31 - skip];
        temp[2] = binary[30 - skip];  // I am stupid this should work
        temp[1] = binary[29 - skip];
        temp[0] = binary[28 - skip];

        if((temp[0] == 0) && (temp[1] == 0) && (temp[2] == 0 ) && (temp[3] == 0))
        {
            hex[7- i] = '0';
        }
        if((temp[0] == 1) && (temp[1] == 0) && (temp[2] == 0 ) &&(temp[3] == 0))
        {
            hex[7- i] = '1';
        }
        if((temp[0] == 0) && (temp[1] == 1) && (temp[2] == 0 ) && (temp[3] == 0))
        {
            hex[7- i] = '2';
        }
        if((temp[0] == 1) && (temp[1] == 1) && (temp[2] == 0 ) && (temp[3] == 0))
        {
            hex[7- i] = '3';
        }
        if((temp[0] == 0) && (temp[1] == 0) && (temp[2] == 1 ) && (temp[3] == 0))
        {
            hex[7- i] = '4';
        }
        if((temp[0] == 1) && (temp[1] == 0) && (temp[2] == 1 ) && (temp[3] == 0))
        {
            hex[7- i] = '5';
        }
        if((temp[0] == 0) && (temp[1] == 1) && (temp[2] == 1 ) && (temp[3] == 0))
        {
            hex[7- i] = '6';
        }
        if((temp[0] == 1) && (temp[1] == 1) && (temp[2] == 1 ) && (temp[3] == 0))
        {
            hex[7- i] = '7';
        }
        if((temp[0] == 0) && (temp[1] == 0) && (temp[2] == 0 ) && (temp[3] == 1))
        {
            hex[7- i] = '8';
        }
        if((temp[0] == 1) && (temp[1] == 0) && (temp[2] == 0 ) && (temp[3] == 1))
        {
            hex[7- i] = '9';
        }
        if((temp[0] == 0) && (temp[1] == 1) && (temp[2] == 0 ) && (temp[3] == 1))
        {
            hex[7- i] = 'a';
        }
        if((temp[0] == 1) && (temp[1] == 1) && (temp[2] == 0 ) && (temp[3] == 1))
        {
            hex[7- i] = 'b';
        }
        if((temp[0] == 0) && (temp[1] == 0) && (temp[2] == 1 ) && (temp[3] == 1))
        {
            hex[7- i] = 'c';
        }
        if((temp[0] == 1) && (temp[1] == 0) && (temp[2] == 1 ) && (temp[3] == 1))
        {
            hex[7- i] = 'd';
        }
        if((temp[0] == 0) && (temp[1] == 1) && (temp[2] == 1 ) && (temp[3] == 1))
        {
            hex[7- i] = 'e';
        }
        if((temp[0] == 1) && (temp[1] == 1) && (temp[2] == 1 ) && (temp[3] == 1))
        {
            hex[7- i] = 'f';
        }
    }
    
    for(int ali = 0; ali < 8 ; ali++)
    {
        temp1[ali] = hex[ali]; // just makes a temp string 
    }
    
    for(int ali = 0; ali < 8 ; ali++)
    {
       hex[7 - ali] = temp1[ali];  // hex[7] = temp1[0] and so on just reverses the string
    }
    
    return;
}

int main(){
    FILE* fp;
    fp=fopen("text.txt","r");
    char output[6],output2[6],hex[8];
    int reg1,reg2,reg3,imm,i=0,c=1;
    int *reg1x=&reg1,*reg2x=&reg2,*reg3x=&reg3,*immx=&imm;
    while(c!=EOF){
        parseFromFile(fp,output,output2,reg1x);
        parseRemainder(fp,output,output2,reg2x,reg3x,immx);
        printf("%s %d %d %d %d\n",output,reg1,reg2,reg3,imm); 
        codeToHex(output,reg1,reg2,reg3,imm,hex);
        printf("%s\n",hex);
        i++;
        c=getc(fp);
    }
    
    return 0;
}
