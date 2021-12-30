# permutation_polynomials
This code generates all polynomials that form permutations over a modular arithmetic p, where p is prime.
The permutations plus their corresponding polynomial are saved to file (perm_poly.txt).

# compiling
Place all files in a directory, then:
> $ g++ -o permute permute.cpp matrix.cpp
 
# running
```
 $ permute <small prime value>
```
# warning
This module will segfault if you enter a composite number. It will also consume a lot of disk space for primes above 7. I recommend not going above 11, which consumed at least 2 gigabytes on my hard drive.
