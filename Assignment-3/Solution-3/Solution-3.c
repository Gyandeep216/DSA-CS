#include <stdio.h>
#include <limits.h>

//Considering the max input size as 2^29

#define MAX 536870911 //2^29-1

char primes[MAX+1] = {0};

// Function to find the prime values using sieve of Eratosthenes
void sieveOfEratosthenes(int n) {

  for(int i = 2; i*i<=n; i++) {
    // 0 -> Prime, 1 -> Non-prime
    if(primes[i] == 0) {
      for(int j = 2; j*i<=n; j++)
        primes[i*j] = 1;
    }
  }

}

//Function to print the prime numbers found.
void displayPrimes(int n) {
  for(int i = 2; i<=n; i++) {
    if(primes[i] == 0)
      printf("%d ", i);
  }
  printf("\n");
}

int main() {

  int n;

  printf("Enter the number till which you want to generate the Prime Numbers :");
  scanf("%d", &n);

  sieveOfEratosthenes(n);
  displayPrimes(n);

  return 0;
}