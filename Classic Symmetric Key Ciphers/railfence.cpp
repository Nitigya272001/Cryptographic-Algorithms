#include<bits/stdc++.h>
using namespace std;

string encrypt(string& msg)
{
    string upper, lower;
       
    for(int i=0;i<msg.length();i++)
    {
        if(i%2==1) upper += msg[i];
        else lower += msg[i];
    }

    return lower + upper;
}

string decrypt(string& cipher)
{
    string plainText;

    int n = cipher.size();
    int i = 0;
    int j = (n+1)/2;
    
    while(j<n)
    {
        plainText+=cipher[i++];
        plainText+=cipher[j++];
    }

    if(n%2==1) plainText += cipher[i];
    
    return plainText;
}

int main()
{
    string msg;
    cout<<"Enter the message to be encrypted : ";
    getline(cin,msg);
    
    string cipherText = encrypt(msg);
    cout<<"Encrypted cipher text is : "<<cipherText<<endl;
    cout<<"Decrypted message is : "<<decrypt(cipherText);
}
