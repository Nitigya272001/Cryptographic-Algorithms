#include <bits/stdc++.h>
using namespace std;

string encryptMessage(string msg, int a, int b)
{
    string cipher = "";

    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')
            cipher += (((a * (msg[i] - 'A')) + b) % 26) +'A';
        
        else
            cipher += msg[i];
    }

    return cipher;
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

string decryptCipher(string cipher, int a, int b)
{   
    int a_inv = inverse(a);

    string msg = "";

    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')
            msg += ((a_inv * ((cipher[i] + 'A' - b)) %26)) + 'A';
        
        else
            msg += cipher[i];
    }

    return msg;
}

int main()
{
    string msg;
    cout << "Enter the string to encrypt using Affine Cipher : ";
    cin >> msg;
    
    int a,b;
    cout<<"Enter the values of a and b : ";
    cin>>a>>b;

    if(__gcd(a,26)!=1)
    {
        cout<<"Oops! a should be coprime with 26.";
        return 0;
    }


    string cipherText = encryptMessage(msg,a,b);
    cout << "Encrypted Message is : " << cipherText << endl;

    cout << "Decrypted Message is: " << decryptCipher(cipherText,a,b);
    return 0;
}