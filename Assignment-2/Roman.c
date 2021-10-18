#include<stdio.h>
#include <string.h>

//Function to find the numeric value of ther entered Roman Numeral.
long int  digit(char c){
 
    long int  value=0;
    
    switch (c) {

    case 'I':

        value = 1;
        break;

    case 'V':

        value = 5;
        break;

    case 'X':

        value = 10;
        break;

    case 'L':

        value = 50;
        break;

    case 'C':

        value = 100;
        break;
        
    case 'D':

        value = 500;
        break;

    case 'M':

        value = 1000;
        break;

    case '\0':

        value = 0;
        break;

    default:
        value = -1;
    }
 
    return value;
}

//Funtion to convet Roman numbers into their Decimal equivalent.
long int convert_roman_to_decimal(char roman[]){

  int i = 0;
  long int number = 0;

  while (roman[i]){
    
    if(digit(roman[i])<0){
      printf("Invalid roman literal \n");
      return -1;

    }

    if((strlen(roman)-i)>2){
      
      if(digit(roman[i]) < digit(roman[i+2])){
        printf("Invalid roman literal \n");
        return -1;

      }
    }

    if(digit(roman[i]) >= digit(roman[i+1])){

      number += digit(roman[i]);

    }else{

      number += digit(roman[i+1]) - digit(roman[i]);
      i++;

    }

    i++;

  }

  return number;

}

//Function to convert Decimal numbers into their Roman Equivalent.
long int  convert_decimal_to_roman(long int num){

  if(num <= 0){
    return -1;
  }

  while(num != 0){

    if (num >= 1000) {

      printf("M");
      num -= 1000;

    } else if (num >= 900){

      printf("CM");
      num -= 900;

    } else if (num >= 500){  

      printf("D");
      num -= 500;

    } else if (num >= 400){

      printf("CD");
      num -= 400;

    } else if (num >= 100){

      printf("C");
      num -= 100;

    } else if (num >= 90){

      printf("XC");
      num -= 90; 

    } else if (num >= 50){

      printf("L");
      num -= 50;          

    } else if (num >= 40){

      printf("XL");           
      num -= 40;

    } else if (num >= 10){

      printf("X");
      num -= 10;           

    } else if (num >= 9){

      printf("IX");
      num -= 9;        

    } else if (num >= 5){

      printf("V");
      num -= 5;       

    } else if (num >= 4){

      printf("IV");
      num -= 4;      

    } else if (num >= 1){

      printf("I");
      num -= 1;     

    }

  }
  return 1;
}


int main(){

  while(1){
    int select;
    
    printf("\nSelect an option : \n1. Convert from Decimal to Roman \n2. Convert from Roman to Decimal \n3. Addition \n4. Multiplication \n5. Exit\n");
    
    
    scanf("%d",&select);

    if(select == 1){

      long int decimal;
      printf("Enter the Decimal numeral : ");
      scanf("%ld",&decimal);

      printf("The Roman equivalent for the entered Decimal number is : ");  
      convert_decimal_to_roman(decimal);
      printf("\n");

    } else if(select == 2) {

      char roman_num_1[500];
      printf("Enter the Roman number : ");
      scanf("%s",&roman_num_1);

      long int conversion =  convert_roman_to_decimal(roman_num_1);

      if(conversion != -1) {  

        printf("The Decimal equivalent for the entered Roman numeral is : %ld\n", conversion);

      }
    
    } else if(select == 3) {

      char roman_num_1[500], roman_num_2[500];
      printf("Enter two roman numerals : ");
      scanf("%s %s",roman_num_1, roman_num_2);
      
      long int decimal_num_1 = convert_roman_to_decimal(roman_num_1);
      long int decimal_num_2 = convert_roman_to_decimal(roman_num_2);

      if(decimal_num_1 == -1 || decimal_num_2 == -1) {

            break;

      } else {

        long int sum = decimal_num_1 + decimal_num_2;
        printf("The sum  of %s and %s  is : ",roman_num_1, roman_num_2);
        convert_decimal_to_roman(sum);
        printf("\n");

      }

    } else if(select == 4 ) {

      char roman_num_1[500], roman_num_2[500];
      printf("Enter two roman numeral: ");
      scanf("%s %s",roman_num_1, roman_num_2);

      long int decimal_num_1 = convert_roman_to_decimal(roman_num_1);
      long int decimal_num_2 = convert_roman_to_decimal(roman_num_2);

      if(decimal_num_1 == -1 || decimal_num_2 == -1) {

        break;

      } else {

        long int product = decimal_num_1 * decimal_num_2;
        printf("The product of %s and %s is : ",roman_num_1,roman_num_2);
        convert_decimal_to_roman(product);
        printf("\n");

      }

    } else {

      printf("Exited.");
      break;

    }

  }

  return 0;
}



