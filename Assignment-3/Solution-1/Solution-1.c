#include<stdio.h>
#include<string.h>

#define MAX 1000000009

// Function to calculate the hash value for the input String.
long long calculate_hash_value(char *s) {

    const int p = 31;
    long long hash_value = 0;
    long long p_pow = 1;

    for (int i=0; i<strlen(s); i++) {
        hash_value = (hash_value + (s[i] - 'A' + 1) * p_pow) % MAX;
        p_pow = (p_pow * p) % MAX;
    }

    return hash_value;

}

int main() {

    char s[1000];

    printf("Enter an uppercase String\n");
    scanf("%[^\n]s",s);

    printf("Hash value for the entered string is : %lld",calculate_hash_value(s));

    return 0;
}