#include<stdio.h>

int main(){

    int cycles = 1;

    while(cycles){

        int select;
        printf("Select your Choice: \n 1.Addition \n 2.Multiplication \n 3.Exit \n");
        printf("Enter your choice: ");
        scanf("%d",&select);

        long long int num1,num2;

            if(select != 3){

                printf("Enter two decimal numbers: ");
                scanf("%lld %lld", &num1,&num2);

            }

        switch (select){

        case 1:

            printf("Sum is: %lld \n",num1+num2);
            break;

        case 2:
            
            printf("Product is: %lld \n",num1*num2);
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