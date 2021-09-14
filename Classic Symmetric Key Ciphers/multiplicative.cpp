#include <bits/stdc++.h>
using namespace std;

string encryptMessage(string s, int key)
{
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        char t = (((int)(s[i] - 'A') * key) % 26) + 'A';
        res += t;
    }
    
    return res;
}

int inverse(int key)
{
    int inverseKey = 0;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (key * i) % 26;
        if (flag == 1)
        {
            inverseKey = i;
            break;
        }
    }

    return inverseKey;
}

string decryptMessage(string s, int key)
{
    key = inverse(key);
    string res = "";

    for (int i = 0; i < s.length(); i++)
    {
        char t = (((int)(s[i] - 'A') * (key)) % 26) + 'A';
        res += t;
    }

    return res;
}

int main()
{
    string s;
    cout << "Enter the string to encrypt using Multiplicative cipher : ";
    cin >> s;

    int key;
    cout<<"Enter the key : ";
    cin>>key;

    if(__gcd(key,26)!=1)
    {
        cout<<"Oops!, Key should be co-prime with 26\n";
        return 0;
    }

    string cipherText = encryptMessage(s,key);
    cout<<"The encrypted cipher is : "<<cipherText<<"\n";

    cout<<"The decrypted text is : "<<decryptMessage(cipherText,key);
}
