#include <stdio.h>
#include <stdlib.h>

//This function checks whether the first and last character of the input is an alphanumeric character or not.
int checkFirstAndLast(char email[]){

    int index = 0;
    int flag = 0;

    if((email[index] >= 'a' && email[index] <= 'z') || (email[index] >= 'A' && email[index] <= 'Z') || (email[index] >= 48 && email[index] <= 57)){

        while(email[index+1] != '\0'){
            index++;
        }

        if((email[index] >= 'a' && email[index] <= 'z') || (email[index] >= 'A' && email[index] <= 'Z') || (email[index] >= 48 && email[index] <= 57)){
            flag = 1;
        }

    }

    return flag;

}

//This function checks if there is one "@" and whether the last "." comes after the "@" or not.
int checkAtDotPos(char email[]){

    int dotPos = 0;
    int atPos = 0;
    int index = 0;
    int atcount = 0;

    while (email[index] != '\0'){

        if (email[index] == '@'){
            atPos = index;
            atcount++;
        }

        if (email[index] == '.'){
            dotPos = index;
        }

        index++;
        if(atcount>1) return 0;
    }
    if(atcount!=0){
        return ((dotPos > atPos) ? 1 : 0);
    }else{
        return 0;
    }
    
}

//This function checks whether the input contains any invalid character or not.
int checkInvalidCharacters (char email[]){

  int index = 0;
  int flag = 1;


    while(email[index] != '\0'){
            
        
        if( email[index] != '!' && email[index] != '#' && email[index] != '$' && email[index] != '%' && email[index] != '&' &&
            email[index] != '"' && email[index] != '*' && email[index] != '+' && email[index] != '-' && email[index] != '/' &&
            email[index] != '=' && email[index] != '?' && email[index] != '^' && email[index] != '_' && email[index] != '`' && 
            email[index] != '{' && email[index] != '|' && email[index] != '}' && email[index] != '~' && email[index] != '.' &&
            email[index] != '@' &&
            !(email[index] >= 'a' && email[index] <= 'z') &&
            !(email[index] >= 'A' && email[index] <= 'Z') &&
            !(email[index] >= 48 && email[index] <= 57) ){

            flag = 0;
            break;
        }

        index++;
    }    

    return flag;
    

}

//The basic function to check whether the input is valid or not.
int checkValidity(char email[]){
    
    if(checkFirstAndLast(email) && checkAtDotPos(email) && checkInvalidCharacters(email)) {
        return 1;
    }else{
        return 0;
    }

}

int main() {

    char email[100];
    gets(email);

    if(checkValidity(email)){
        printf("Valid\n");
    }else{
        printf("Invalid\n");
    }
    
    return 0;

}