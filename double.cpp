#include<bits/stdc++.h>
using namespace std;

string encryptOnce(string &msg, int cols, vector<int>&per)
{ 
    vector<string> columnString(cols,"");
    
    for(int i=0; i<msg.length(); i++)
    {
        columnString[i%cols] += msg[i];
    }
    
    string cipherText;
    for(int i=0;i<cols;i++) cipherText += columnString[per[i]];
    
    return cipherText;
}

string decryptOnce(string &cipher,int cols,vector<int>&per)
{
    int n = cipher.length();
    int rows = (n-1)/cols + 1;
    int lastRowFilledCols = (n%cols==0) ? cols : n%cols;
    int k=0;

    vector<string>rowBackString(rows);
    for(int i=0;i<rows-1;i++)
    {
        rowBackString[i].resize(cols);
    }
    rowBackString[rows-1].resize(lastRowFilledCols);
    

    for(int i=0;i<cols;i++)
    {
        int itr = rows - (per[i] >= lastRowFilledCols);
        for(int j=0;j<itr;j++)
        {
            rowBackString[j][per[i]]=cipher[k++];
        }
    }

    string plainText;
    for(auto it:rowBackString) plainText+=it;

    return plainText;
}

string encrypt(string s,int cols,vector<int>&per)
{
    string firstTime = encryptOnce(s,cols,per);
    return encryptOnce(firstTime,cols,per);
}

string decrypt(string s,int cols,vector<int>&per)
{
    string firstTime = decryptOnce(s,cols,per);
    return decryptOnce(firstTime,cols,per);
}

int main()
{
    int k;
    string msg;
    cout<<"Enter the message to be encrypted : ";
    getline(cin,msg);
    
    cout<<"Enter the number of columns (key) : ";
    cin>>k;

    vector<int>per(k);
    cout<<"Enter the permutation (key) : ";
    for(auto &it : per) cin>>it;

    string cipherText = encrypt(msg,k,per);
    cout<<"Encrypted cipher text is : "<<cipherText<<endl;
    cout<<"Decrypted string is : "<<decrypt(cipherText,k,per);
}
