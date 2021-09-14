#include<bits/stdc++.h>
using namespace std;

//Encrypting a message using additive cipher
string encrypt(string message, int shift)
{
    char ch;
    for(int i = 0; i < message.size(); i++)
    {
        ch = message[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch + shift;
            if(ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }

            message[i] = ch;
        }

        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + shift;
            if(ch > 'Z'){
                ch = ch - 'Z' + 'A' - 1;
            }
            
            message[i] = ch;
        }
    }
    
    return message;
}

//Decrypting a additive cipher to normal message
string decrypt(string cipher, int shift)
{
    char ch;
    for(int i = 0; i < cipher.size(); i++)
    {
        ch = cipher[i];
        if(ch >= 'a' && ch <= 'z')
        {
            ch = ch - shift;
            if(ch < 'a')
            {
            ch = ch + 'z' - 'a' + 1;
            }

            cipher[i] = ch;
        }

        else if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch - shift;
            if(ch > 'a')
            {
                ch = ch + 'Z' - 'A' + 1;
            }
            
            cipher[i] = ch;
        }
    }
    
    return cipher;
}


int main()
{
    string message;
    int shift;

    cout << "Enter a message to encrypt : ";
    getline(cin,message);
    cout << "Enter the shift : ";
    cin >> shift;

    string encryptedCipher = encrypt(message,shift);
    cout<<"\nEncrpting the message...\n";
    cout<<"The encrypted message is :"<<encryptedCipher<<"\n\n";

    
    string decryptedMessage = decrypt(encryptedCipher,shift);
    cout<<"Decrypting the encrypted cipher...\n";
    cout<<"The decrypted message is :"<<decryptedMessage<<"\n";

    return 0;
}