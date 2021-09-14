#include <bits/stdc++.h>
using namespace std;


void constructMatrix(vector<vector<char>>& encoder, string key, map<char,pair<int,int>>& get_pos)
{
    int n = 5;
    map<char,int> mp;
    int i,j,k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            while(mp[key[k]]>0 && k<key.size())
            {
                k++;
            }

            if(k<key.size())
            {
                encoder[i][j] = key[k];
                mp[key[k]]++;
            }

            if(k==key.size()) break;
        }

        if(k==key.size()) break;
    }

    k=0;
    for(;i<n;i++)
    {
        for(;j<n;j++)
        {
            while(mp[char(k+'a')]>0 && k<26)
            {
                k++;
            }

            if(char(k+'a')=='j')
            {
                j--;
                k++;
                continue;
            }

            if(k<26)
            {
                encoder[i][j] = char(k+'a');
                mp[char(k+'a')]++;
            }
        }

        j=0;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            get_pos[encoder[i][j]] = make_pair(i,j);
        }
    }
}

string convertString(string msg)
{
    string msgx = "";
    int i, j;
    i = j = 0;

    while (i < msg.size())
    {
        msgx.push_back(msg[i]);
        i++;
        
        if (i == msg.size())
        {
            msgx.push_back('x');
            break;
        }

        if (msg[i] == msgx[j])
        {
            msgx.push_back('x');
            j++;
        }

        else if (msg[i] != msgx[j])
        {
            j++;
            msgx.push_back(msg[i]);
            i += 1;
        }

        j++;
    }

    return msgx;
}

string encryptMessage(string& msg, vector<vector<char>>& encoder, map<char,pair<int,int>>& get_pos)
{
    int len = msg.size();
    string cipher;
    int i = 0, j = 0;
    int r1, c1, r2, c2;
    for (i = 0; i < len - 1; i+=2)
    {
        r1 = get_pos[msg[i]].first;
        c1 = get_pos[msg[i]].second;

        r2 = get_pos[msg[i+1]].first;
        c2 = get_pos[msg[i+1]].second;
        
        if (r1 == r2)  //Same Row
        {
            cipher.push_back(encoder[r1][(c1 + 1) % 5]);
            cipher.push_back(encoder[r1][(c2 + 1) % 5]);
        }

        else if (c1 == c2)  //Same Column
        {
            cipher.push_back(encoder[(r1 + 1) % 5][c1]);
            cipher.push_back(encoder[(r2 + 1) % 5][c1]);
        }
        
        else // Different
        {
            cipher.push_back(encoder[r1][c2]);
            cipher.push_back(encoder[r2][c1]);
        }
    }
    
    
    return cipher;
}

string decryptMessage(string& cipher, vector<vector<char>>& encoder, map<char,pair<int,int>>& get_pos)
{
    int len = cipher.size();
    string plainText;
    int i = 0, j = 0;
    int r1, c1, r2, c2;
    for (i = 0; i < len - 1; i+=2)
    {
        r1 = get_pos[cipher[i]].first;
        c1 = get_pos[cipher[i]].second;

        r2 = get_pos[cipher[i+1]].first;
        c2 = get_pos[cipher[i+1]].second;
        
        if (r1 == r2)  //Same Row
        {
            plainText.push_back(encoder[r1][(c1 - 1 + 5) % 5]);
            plainText.push_back(encoder[r1][(c2 - 1 + 5) % 5]);
        }

        else if (c1 == c2)  //Same Column
        {
            plainText.push_back(encoder[(r1 - 1 + 5) % 5][c1]);
            plainText.push_back(encoder[(r2 - 1 + 5) % 5][c1]);
        }
        
        else // Different
        {
            plainText.push_back(encoder[r1][c2]);
            plainText.push_back(encoder[r2][c1]);
        }
    }
    
    if(plainText[plainText.size()-1]=='x')
        plainText.pop_back();

    string plain;
    for(int i = 0; i < plainText.size(); i++)
    {
        if(plainText[i]!='x') plain.push_back(plainText[i]);
    }

    return plain;
}

int main()
{
    string msg,key;
    int i, j;
    cout << "Enter the Message : ";
    getline(cin,msg);

    cout<<"Enter the key : ";
    cin>>key;
    vector<vector<char> > encoder(5,vector<char>(5,' '));
    map<char,pair<int,int>> get_pos;
    constructMatrix(encoder,key,get_pos);


    string temp = "";
    for(int i=0;i<msg.size();i++)
    {
        if(msg[i]!=' ') temp += msg[i];
    }
    string msgx = convertString(temp);

    string cipherText = encryptMessage(msgx,encoder,get_pos);;
    cout<<"The encrypted cipher is : "<<cipherText<<"\n";

    string cipherx = convertString(cipherText);
    cout<<"The decrypted message is : "<<decryptMessage(cipherx,encoder,get_pos);
    return 0;
}