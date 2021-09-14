#include <bits/stdc++.h>
using namespace std;

vector<string> autokey_encrypt(string s, string autokey)
{
    int n = s.length();
    int k = autokey.length();
    string key_stream = autokey + s.substr(0, n - k);
    string cipherText = "";
    
    for (int i = 0; i < n; i++)
    {
        char t = ((s[i] - 'A' + key_stream[i] - 'A') % 26) + 'A';
        cipherText += t;
    }
    
    cout << "Encrypted text ="<<cipherText<<endl;
    return {cipherText, key_stream};
}

void autokey_decrypt(string s, string key_stream)
{
    int n = s.length();
    string decrypt = "";

    for (int i = 0; i < n; i++)
    {
        int t = ((s[i] - key_stream[i]) % 26);
        if (t < 0) t += 26;

        decrypt += (char)(t + 'A');
    }

    cout << "Decrypted text = "<<decrypt<<endl;
}

int main()
{
    string input;
    cout << "Enter the string to encrypt using autokey cipher : ";
    cin >> input;

    string key;
    cout << "Enter the autokey : ";
    cin >> key;
    
    auto temp = autokey_encrypt(input, key);
    
    autokey_decrypt(temp[0], temp[1]);
    return 0;
}