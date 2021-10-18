#include<stdio.h>
#include<string.h>

int main() {

    int cycles = 1;

  while(cycles) {

    int select; 
    printf("Select your choice : \n1. Addition \n2. Multiplication \n3. Exit\n");
    scanf("%d",&select);

    char unary_1[100], unary_2[100],temp[100];

        if(select != 3) {

             printf("Enter two unary numbers: ");
             scanf("%s %s", unary_1, unary_2);

        }

    switch (select) {

    case 1:

        strcpy(temp,unary_2);
        strcat(unary_2, unary_1);
        printf("The sum of  %s and %s is : %s\n",unary_1, temp, unary_2);

        break;

    case 2:

        printf("The product of %s and %s  is: ",unary_1,unary_2);
          for(int i=0; i<strlen(unary_1); i++){
            printf("%s", unary_2);}
        printf("\n");
 
        break;
    
    case 3:

        printf("Exited.");
        cycles = 0;

        break;

    default:

        printf("Your Selection is invalid. Please enter your choices again.");
        break;

    }

  }
     
   
  return 0;
}