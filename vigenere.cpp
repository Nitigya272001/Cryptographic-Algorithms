#include<bits/stdc++.h> 
using namespace std;

string encrypt(string &plainText , string &key)
{
    string ans;
    int len = key.length();
    
    for(int i=0; i<plainText.length(); i++)
    {
        ans += ( (plainText[i]-'A') + (key[i%len]-'A') )%26 + 'A';
    }
    
    return ans;
}

string decrypt(string &cipher , string &key)
{
    string ans="";
    int len = key.length();
    
    for(int i=0; i<cipher.length(); i++)
    {
        ans += ( (cipher[i]-'A') - (key[i%len] -'A') + 26 )%26 + 'A';
    }
    
    return ans;
}

int main()
{
    string key,plainText;
    cout<<"Enter the message to be encrypted : "; cin>>plainText;
    cout<<"Enter the key : "; cin>>key;
    
    string cipherText = encrypt(plainText,key); 
    cout<<"Encrypted cipher text is : "<<cipherText<<endl;
    cout<<"Decrypted message is : "<<decrypt(cipherText,key)<<endl;
}
