
import math

def sieveOfEratosthenes(n):
    prime = [True for i in range(n+1)]
    primes = []
    p = 2

    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1

    for p in range(n+1):
        if prime[p]:
            primes.append(p)

    return primes

prime = sieveOfEratosthenes(10**6)

sieveT = {}

prod = 1
for i in range(len(prime)):
    prod = prime[i] * prime[i]

    if prod > 10**12:
        break

    sieveT[prod] = True;

sieveT.pop(1)

n = int(input())
A = [int(x) for x in input().split()]

for i in A:
    if i in sieveT:
        print("YES")
    else:
        print("NO")

