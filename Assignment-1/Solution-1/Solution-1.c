#include <stdio.h>
#include <stdlib.h>

// This function checks whether the input has all its characters as digits.
int digitsCheck(char num[]){

    int count = 0;
    int flag = 1;
    int dotCount = 0;

    while(num[count] != '\0'){

        if(num[count] != '.' && ( num[count] < 48 || num[count] > 57)){
            flag = 0;
        }

        if(num[count] == '.'){
            dotCount++;

            if(dotCount > 1){
                flag = 0;
                break;
            }

        }

        count++;
    }

    return flag;

}

//This function checks whether there is a digit after "." or not.
int checkFloat(char num[]){

    int flag = 0;

    if(digitsCheck(num) == 1){

        int count = 1;

        while(num[count] != '\0'){
            if(num[count] == '.' && num[count+1] != '\0'){
                flag = 1;
            }
            count++;
        } 
    }

    return flag;

}


int main(){

    char num[100];
    scanf("%s",num);

    if(checkFloat(num) == 1){
        printf("Valid\n");
    }else{
        printf("Invalid\n");
    }

    return 0;
}