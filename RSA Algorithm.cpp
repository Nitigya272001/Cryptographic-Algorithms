#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> random_prime_numbers = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

ll _pow(ll a, ll b, ll n)
{
    ll res = 1;
    a = a % n;
    if (a == 0)
        return 0;

    while (b > 0)
    {
        if (b % 2 != 0)
            res = (res * a) % n;

        b = b / 2;
        a = (a * a) % n;
    }
    return res;
}

int main()
{
    srand(time(0));
    int size = random_prime_numbers.size();
    // Two random prime numbers
    ll p = random_prime_numbers[rand() % size];
    ll q = random_prime_numbers[rand() % size];
    while (q == p)
        q = random_prime_numbers[rand() % size];
    cout << "p : " << p << " q : " << q << endl;
    // 1st part of public key:
    ll n = p * q;
    ll e = 2;
    ll phi = (p - 1) * (q - 1);
    while (e < phi)
    {
        if (gcd(e, phi) == 1)
            break;
        else
            e++;
    }
    cout << "e : " << e << endl;
    cout << "phi : " << phi << endl;
    int k = 2;
    ll d = (1 + (k * phi)) / e;

    ll msg;
    cout << "Enter Message Data = ";
    cin >> msg;

    ll c = _pow(msg, e, n);
    cout << "Encrypted data = " << c << endl;

    ll m = _pow(c, d, n);
    cout << "After Decrypiton\nOriginal Message sent = " << m << endl;

    return 0;
}