#include <stdio.h>




int isPrime(int x)
{
    if (x <= 1)
        return 0;
    for (int divisor = 2; divisor <= x/2 + 1; divisor++)
        if (x % divisor == 0) 
        return 0;
    return 1;
}

int main()
{
  int aMax;
  int bMax;
  int nMax = 0;
  for (int a = -999; a < 1000;a+=2){
      for (int b = 0; b <= 1000; b++){
        // a is always odd in order to find a prime number
        // with a quadratic formula n*n + a*n + b
        // same with b, when n = 0, the quadratic must be prime
        // so b is a prime number and primes are non-negative
        // so loop is from 0 instead of -1000 like the problem
        // states, halving the iterations again just like a. 
        int n = 0;
        while (isPrime(n*n + a*n + b) == 1){
          n++;
        }
        if (n > nMax){
          nMax = n;
          aMax = a;
          bMax = b;
        }
        if (aMax == a & bMax == b & nMax == n){
          printf("A: %d, B: %d, n: %d\n", aMax, bMax, nMax);
        }
        //printf("A: %d\n", aMax);
      }   
    }
  printf("Consecutive: %d,\nCoefficient a: %d, \nCoefficient b: %d\n", nMax,aMax,bMax);
  printf("Product of a and b: %d\n", aMax*bMax);
  return 0;
}

