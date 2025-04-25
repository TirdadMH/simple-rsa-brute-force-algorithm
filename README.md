# Simple RSA Brute Force Algorithm

This project demonstrates a **simple brute-force method** for factoring the modulus in RSA encryption, built for educational purposes only.  
It attempts to **crack small RSA keys** by factoring the public modulus \( n \), reconstructing the private key \( d \), and decrypting the ciphertext \( c \).

---

## 🚀 Features

- Factorizes small RSA modulus \( n \) into primes \( p \) and \( q \)
- Calculates Euler’s totient function \( φ(n) = (p - 1)(q - 1) \)
- Computes the private key \( d \) using the extended Euclidean algorithm
- Decrypts the ciphertext using modular exponentiation
- Fully implemented in C++ with clean logic and CLI output

---

## 📂 Project Structure

| File        | Description                                  |
|-------------|----------------------------------------------|
| `Main.cpp`  | Source code with RSA brute-force algorithm   |
| `Makefile`  | Build file to compile the project            |
| `Main`      | Compiled binary (optional)                   |

---

## 🔧 Build & Run

### Compile with Makefile
```bash
make
```

### Or compile manually
```bash
g++ -o Main Main.cpp
```

### Run the program
```bash
./Main
```

---

## 🧠 Concepts Demonstrated

- Prime factorization
- Euler’s Totient Function
- Modular inverse
- Fast modular exponentiation
- RSA encryption and decryption process

---

## 📎 Example

For inputs:

- Cipher Text: 41
- n: 187
- e: 3

The program outputs:

- Totient Euler(n): 160
- p and q: 11, 17
- d: 107
- Plain Text: 2
