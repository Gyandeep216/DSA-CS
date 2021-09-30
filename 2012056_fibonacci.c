// Code by -
// Name : Gyandeep Kalita
// Scholar ID : 2012056


#include<stdio.h>
#include<string.h>

void stringAdd(char first_num[], char second_num[], char result[]){
    
    int carry = 0;
    
    for(int i=9999; i>=0; i--){
        result[i] = (((first_num[i] - '0') + (second_num[i] - '0') + carry)%10) + '0';
        carry = ((first_num[i] - '0') + (second_num[i] - '0') + carry)/10;
    }
    
}

void stringShift(char s1[], char s2[]){
    
    for(int i=9999; i>=0; i--){
        s2[i] = s1[i];
    }
    
}
    

void fibonacci(int n,char first_num[],char second_num[],char result[]){
    
    second_num[9999] = '1';
    
    for (int i = 2; i <= n; i++){
     stringAdd(first_num,second_num,result);
     stringShift(second_num,first_num);
     stringShift(result,second_num);
    }
   
}

char first_num[10000];
char second_num[10000];
char result[10000];
 
int main (){
    
    for(int i=0; i<10000; i++){
        first_num[i] = '0';
        second_num[i] = '0';
        result[i] = '0';
    }
   
    
    int n;
    printf("Please enter the number of the term: ");
    scanf("%d",&n);
    
    if(n==0 || n==1){
        printf("The required number is: ");
        printf("%d",n);
        return 0;
    }
    
    
    fibonacci(n,first_num,second_num,result);
   
    
    printf("The required number is: ");
    
    int flag = 0;
    for(int i=0; i<10000; i++){
        
        if (!flag && result[i] == '0'){
            continue;
        }
        
        if (!flag  && result[i] != '0'){
            flag = 1;
        }
        
        printf("%c",result[i]);

    }
    
    return 0;
}