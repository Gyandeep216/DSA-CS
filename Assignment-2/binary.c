#include <stdio.h>

//Function to find the product of two binary numbers.
int binaryMultiplication(int binary_1, int binary_2){
    int i = 0, remainder = 0, sum[20];
    int binaryprod = 0;
 
    while (binary_1 != 0 || binary_2 != 0)
    {
        sum[i++] =(binary_1 % 10 + binary_2 % 10 + remainder) % 2;
        remainder =(binary_1 % 10 + binary_2 % 10 + remainder) / 2;
        binary_1 = binary_1 / 10;
        binary_2 = binary_2 / 10;
    }
    if (remainder != 0)
        sum[i++] = remainder;
    --i;
    while (i >= 0){
        binaryprod = binaryprod * 10 + sum[i--];
    }

    return binaryprod;
}

//Function to find the sum of two binary numbers.
void binaryAddition (int binary_1, int binary_2, int sum[], int remainder){

    int i = 0;

    while (binary_1 != 0 || binary_2 != 0){

        sum[i++] =(binary_1 % 10 + binary_2 % 10 + remainder) % 2;
        remainder =(binary_1 % 10 + binary_2 % 10 + remainder) / 2;
        binary_1 = binary_1 / 10;
        binary_2 = binary_2 / 10;
        
    }

    if (remainder != 0){
        sum[i++] = remainder;
    }

    --i;

    printf("The sum of the two binary numbers: ");
    while (i >= 0){
        printf("%d", sum[i--]);
    }

    printf("\n");

}
 
int main() {
 
    long binary_1, binary_2, multiply=0;
    int remainder = 0, sum[20], digit, factor = 1;
    int cycles = 1;

    while(cycles){

        int select;
        printf("Enter the Choice :\n");
        printf("1.Addition\n2.Multiplication\n3.Exit\n");
        scanf("%d",&select);

        switch (select){

        case 1:

            printf("Enter the first binary number: ");
            scanf("%ld", &binary_1);
            printf("Enter the second binary number: ");
            scanf("%ld", &binary_2);
            binaryAddition(binary_1,binary_2,sum,remainder);

            break;
        
        case 2:

            printf("Enter the first binary number: ");
            scanf("%ld", &binary_1);
            printf("Enter the second binary number: ");
            scanf("%ld", &binary_2);

            while (binary_2 != 0){

                digit =  binary_2 % 10;
                if (digit == 1){

                    binary_1 = binary_1 * factor;
                    multiply = binaryMultiplication(binary_1, multiply);

                } else {
                    binary_1 = binary_1 * factor;
                }

            binary_2 = binary_2 / 10;
            factor = 10;

        }

            printf("Product of the two binary numbers: %ld", multiply);
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