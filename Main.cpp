// Mohammad Hossein Moazzen - 991830256
#include <iostream>
#include <cmath>

int calculate_totient_euler(std::pair<int, int>);
std::pair<int, int> factorization_to_p_q(int);
int get_gcd(std::pair<int, int>);
int get_private_key(std::pair<int, int>);
int decrypt_message(std::pair<int, int>, int);

int main()
{
    // c is the Ciphertext.
    int c = 11;

    // m is the plain text message.
    int m = -1;

    // public_key: n, e = 187, 7
    std::pair<int, int> public_key = {187, 7};

    // prime factorization of n
    std::pair<int, int> pq = factorization_to_p_q(public_key.first);

    // calculate the totient euler of n using p & q.
    int te_n = calculate_totient_euler(pq);

    // get the private key 'd'.
    int d = get_private_key({te_n, public_key.second});

    // now that the program has the d, it makes the private key.
    std::pair<int, int> private_key = {d, public_key.first};

    // program checks if it got the d right, if true, then it starts the decryption process.
    if (d == -1)
        std::cout << "ERROR: Can not get the private key.\n";
    else
        m = decrypt_message(private_key, c);

    // Print everything.
    std::cout << "Cipher Text: " << c << ", n: " << public_key.first << ", e: " << public_key.second << std::endl << "Totient Euler(n): " << te_n << ", p and q: " << pq.first << ", " << pq.second << ", d: " << d << std::endl << "Plain Text: " << m << std::endl; 
}

int calculate_totient_euler(std::pair<int, int> pq)
{
    return (1 - pq.first) * (1 - pq.second);
}

std::pair<int, int> factorization_to_p_q(int n)
{
    int p{0}, q{0};
    while (n > 1) 
    {
        for (int i = 2; i <= n ; i++) 
        {
            while (n % i == 0) 
            {
                fflush(stdout);
                if (p == 0) 
                {
                    p = i;
                } 
                else 
                {
                    q = i;
                    break;
                }
                n /= i;
            }
        }
        break;
    }
    return {p, q};
}


int get_gcd(std::pair<int, int> ab)
{
    int i = 1;
    int a = ab.first;
    int b = ab.second;
    if (a > b)
        i = a;
    else
        i = b;
    while ((a % i != 0) || (b % i != 0))
        i--;
    return i;    
}

int get_private_key(std::pair<int, int> te_e)
{
    if (get_gcd(te_e) == 1)
    {
        // actual brute force process, I think.
        int i = 1;
        while (true)
        {
            if (((i * te_e.second) % te_e.first) == 1)
                return i;
            else 
                i++;
        }
    }
    else return -1;
}

int decrypt_message(std::pair<int, int> private_key, int c)
{
    // found the solution to keep the numbers small thanks to user "lastchance6980" on:
    // https://cplusplus.com/forum/general/228429/
    int value = 1;
    while (private_key.first > 0)
    {
        value *= c;
        value %= private_key.second;
        private_key.first--;
    }
    return value;
}
