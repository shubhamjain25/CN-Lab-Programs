/*
Algorithm:
● Generate two large random primes, P and Q, of approximately equal size.
● Compute N=PxQ
● Compute Z=(P-1) x (Q-1).
● Choose an integer E, 1<E<Z, such that GCD (E, Z) = 1
● Compute the secret exponent D, 1<D<Z, such that ExD ≡ 1(mod Z)
*/


#include<stdio.h>
#include<math.h>

int gcd(int a, int b) {
   if(b==0){return a;}
   else{return gcd(b,a%b);}
}

int main() {
    //2 random prime numbers
    double p = 3;
    double q = 7;

    double n = p * q;
    double flag;
    double totient = (p - 1) * (q - 1);

    //public key
    //e stands for encrypt
    double e = 2;
    while (e < totient) {
        flag = gcd(e, totient);
        if (flag == 1)
            break;
        else
            e++;
    }
    
    //private key
    //d stands for decrypt
    double d;
    //k can be any arbitrary value
    double k = 2;
    
    //choosing d such that it satisfies d*e = 1 + k * totient
    d = (1 + (k * totient)) / e;
    
    double msg = 12;
    double c = pow(msg, e);
    double m = pow(c, d);
    c = fmod(c, n);
    m = fmod(m, n);
    
    //We are printing in the order of variable declaration
    printf("Message data = %lf", msg);
    printf("\n p = %lf", p);
    printf("\n q = %lf", q);
    printf("\n n = pq = %lf", n);
    printf("\n totient = %lf", totient);
    printf("\n e = %lf", e);
    printf("\n d = %lf", d);
    printf("\n Encrypted data = %lf", c);
    printf("\n Original Message Sent = %lf", m);

    return 0;
}