#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function declarations
long long gcd(long long a, long long b);
long long mod_pow(long long base, long long exponent, long long modulus);
long long find_period(long long a, long long N);
int is_prime(long long n);
void factor_number(long long N);

// Calculate greatest common divisor using Euclidean algorithm
long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Modular exponentiation using square-and-multiply algorithm
long long mod_pow(long long base, long long exponent, long long modulus) {
    if (modulus == 1)
        return 0;
    
    long long result = 1;
    base = base % modulus;
    
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        
        base = (base * base) % modulus;
        exponent = exponent >> 1;
    }
    return result;
}

// Find the period of f(x) = a^x mod N
// This is a classical implementation - quantum computers would use QFT
long long find_period(long long a, long long N) {
    long long x = 1;
    long long period = 1;
    
    // Maximum iterations to prevent infinite loops
    long long max_iter = N * 2;
    
    while (period < max_iter) {
        if (mod_pow(a, period, N) == 1)
            return period;
        period++;
    }
    
    return 0;  // Period not found
}

// Check if a number is prime
int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

// Main Shor's algorithm implementation
void factor_number(long long N) {
    // Step 1: Check if N is even
    if (N % 2 == 0) {
        printf("Factor found: 2\n");
        return;
    }
    
    // Step 2: Check if N is prime
    if (is_prime(N)) {
        printf("%lld is prime\n", N);
        return;
    }
    
    // Maximum attempts for finding a random base
    int max_attempts = 100;
    
    for (int attempt = 0; attempt < max_attempts; attempt++) {
        // Step 3: Choose random number a < N
        long long a = 2 + rand() % (N - 2);
        
        // Step 4: Ensure a and N are coprime
        long long factor = gcd(a, N);
        if (factor > 1) {
            printf("Factor found: %lld\n", factor);
            return;
        }
        
        printf("Attempting with base a = %lld\n", a);
        
        // Step 5: Find period
        long long r = find_period(a, N);
        if (r == 0) {
            printf("Period finding failed for a = %lld\n", a);
            continue;
        }
        
        printf("Found period r = %lld\n", r);
        
        // Step 6: Check if period is even and a^(r/2) != -1 mod N
        if (r % 2 == 0) {
            long long power = mod_pow(a, r/2, N);
            if (power != N-1) {
                // Step 7: Compute factors
                long long factor1 = gcd(power + 1, N);
                long long factor2 = gcd(power - 1, N);
                
                if (factor1 > 1 && factor1 < N) {
                    printf("Factors found: %lld and %lld\n", factor1, N/factor1);
                    return;
                }
                if (factor2 > 1 && factor2 < N) {
                    printf("Factors found: %lld and %lld\n", factor2, N/factor2);
                    return;
                }
            }
        }
        
        printf("No factors found with this base, trying another...\n");
    }
    
    printf("Failed to factor %lld after %d attempts\n", N, max_attempts);
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Example usage
    long long N;
    printf("Enter a number to factor: ");
    scanf("%lld", &N);
    
    if (N < 2) {
        printf("Please enter a number greater than 1\n");
        return 1;
    }
    
    printf("Attempting to factor %lld using Shor's algorithm\n", N);
    factor_number(N);
    
    return 0;
}
