#include<bits/stdc++.h>
using namespace std;

string encrypt(string &msg,int cols)
{
    vector<string> columnString(cols,"");
    
    for(int i=0;i<msg.length();i++)
    {
      columnString[i%cols] += msg[i];
    }
    
    for(int j = 0; j < columnString[0].size(); j++)
    {
        for(int i = 0; i < 3; i++)
        {
            cout<<columnString[i][j]<<" ";
        }
        cout<<"\n";
    }
        
    string cipherText;
    for(auto &it : columnString) cipherText += it;
    
    return cipherText;
}

string decrypt(string &cipher,int cols)
{
    int n = cipher.length();
    int rows = (n-1)/cols + 1;
    int lastRowFilledCols = (n%cols==0) ? cols : n%cols;
    int k=0;

    vector<string>rowBackString(rows,"");
    for(int i=0;i<cols;i++)
    {
        int itr = rows - (i >= lastRowFilledCols);
        for(int j=0;j<itr;j++)
        {
            rowBackString[j] += cipher[k++];
        }
    }

    string plainText;
    for(auto it:rowBackString) plainText+=it;

    return plainText;
}

int main()
{
    int k;
    string msg;
    cout<<"Enter the message to be encrypted : ";
    getline(cin,msg);
    
    cout<<"Enter the number of columns (key) : ";
    cin>>k;

    string cipherText = encrypt(msg,k);
    cout<<"Encrypted cipher text is : "<<cipherText<<endl;
    cout<<"Decrypted string is : "<<decrypt(cipherText,k);
}
