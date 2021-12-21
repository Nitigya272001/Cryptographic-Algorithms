#include <iostream>
#include <vector>
using namespace std;

int mul_inv(int a, int b)
{
    int b0 = b, t, q;
    int x0 = 0, x1 = 1;
    if (b == 1)
        return 1;
    while (a > 1)
    {
        q = a / b;
        t = b, b = a % b, a = t;
        t = x0, x0 = x1 - q * x0, x1 = t;
    }
    if (x1 < 0)
        x1 += b0;
    return x1;
}

int crt(int *n, int *a, int len)
{
    int p, i, prod = 1, sum = 0;

    for (i = 0; i < len; i++)
        prod *= n[i];

    for (i = 0; i < len; i++)
    {
        p = prod / n[i];
        sum += a[i] * mul_inv(p, n[i]) * p;
    }
    return sum % prod;
}

int main()
{
    int k;
    cout << "Number of equations: ";
    cin >> k;
    cout << "x % num[i] = rem[i]" << endl;
    cout << "Enter num and rem: " << endl;
    int rem[k];
    int num[k];
    for (int i = 0; i < k; i++)
    {
        cin >> num[i] >> rem[i];
    }
    
    cout << "x is " << crt(num, rem, k);
    return 0;
}
