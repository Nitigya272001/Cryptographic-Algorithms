#include<bits/stdc++.h>
using namespace std;

vector<string> keys(16);

string hex_2_bin(string s)
{
    unordered_map<char, string> mp;
    mp['0'] = "0000";
    mp['1'] = "0001";
    mp['2'] = "0010";
    mp['3'] = "0011";
    mp['4'] = "0100";
    mp['5'] = "0101";
    mp['6'] = "0110";
    mp['7'] = "0111";
    mp['8'] = "1000";
    mp['9'] = "1001";
    mp['A'] = "1010";
    mp['B'] = "1011";
    mp['C'] = "1100";
    mp['D'] = "1101";
    mp['E'] = "1110";
    mp['F'] = "1111";
    string bin = "";
    for (int i = 0; i < s.size(); i++) {
        bin += mp[s[i]];
    }
    return bin;
}

string bin_2_hex(string s){

    unordered_map<string, string> mp;
    mp["0000"] = "0";
    mp["0001"] = "1";
    mp["0010"] = "2";
    mp["0011"] = "3";
    mp["0100"] = "4";
    mp["0101"] = "5";
    mp["0110"] = "6";
    mp["0111"] = "7";
    mp["1000"] = "8";
    mp["1001"] = "9";
    mp["1010"] = "A";
    mp["1011"] = "B";
    mp["1100"] = "C";
    mp["1101"] = "D";
    mp["1110"] = "E";
    mp["1111"] = "F";
    string hex = "";
    for (int i = 0; i < s.length(); i += 4) {
        string ch = "";
        ch += s[i];
        ch += s[i + 1];
        ch += s[i + 2];
        ch += s[i + 3];
        hex += mp[ch];
    }
    return hex;
}

string permutate(string s,int *mat,int n){
    string ans="";
    for(int i=0;i<n;i++){
        ans+=s[mat[i]-1];
    }
    return ans;
}

string shift(string s){
    string ans="";
    for(int i=1;i<s.length();i++){
        ans+=s[i];
    }
    ans+=s[0];
    return ans;
}

void generate_key(string s){
    int remove_last_bit[56] = { 57, 49, 41, 33, 25, 17, 9,
                                1, 58, 50, 42, 34, 26, 18,
                                10, 2, 59, 51, 43, 35, 27,
                                19, 11, 3, 60, 52, 44, 36,
                                 63, 55, 47, 39, 31, 23, 15,
                                 7, 62, 54, 46, 38, 30, 22,
                                 14, 6, 61, 53, 45, 37, 29,
                                 21, 13, 5, 28, 20, 12, 4 };

    int key_compressor[48] = { 14, 17, 11, 24, 1, 5,
                                 3, 28, 15, 6, 21, 10,
                                 23, 19, 12, 4, 26, 8,
                                 16, 7, 27, 20, 13, 2,
                                 41, 52, 31, 37, 47, 55,
                                 30, 40, 51, 45, 33, 48,
                                 44, 49, 39, 56, 34, 53,
                                 46, 42, 50, 36, 29, 32 };
    s = permutate(s,remove_last_bit,56);
    // now we have 56 bit key by discarding 8th bit
    string l = s.substr(0,28);
    string r = s.substr(28,28);
    for(int i=0;i<16;i++){
        if(i==0 || i==1 ||i==8 || i==15){
            l = shift(l);
            r = shift(r);
        }
        else{
            l=shift(l);
            l=shift(l);
            r=shift(r);
            r=shift(r);
        }
        string temp = l+r;
        string ans="";
        for(int i=0;i<48;i++){
            ans+=temp[key_compressor[i]-1];
        }
        // now we have 48 bit key
        keys[i]=ans;
    }
}

string Xor(string a,string b){
    string ans="";
    for(int i=0;i<a.length();i++){
        if(a[i]!=b[i]) ans+="1";
        else ans+="0";
    }
    return ans;
}

string convertDecimalToBinary(int decimal)
{
    string binary;
    while(decimal != 0) {
        binary = (decimal % 2 == 0 ? "0" : "1") + binary;
        decimal = decimal/2;
    }
    while(binary.length() < 4){
        binary = "0" + binary;
    }
    return binary;
}

int convertBinaryToDecimal(string binary)
{
    int decimal = 0;
    int counter = 0;
    int size = binary.length();
    for(int i = size-1; i >= 0; i--)
    {
        if(binary[i] == '1'){
            decimal += pow(2, counter);
        }
    counter++;
    }
    return decimal;
}

string encrypt(string s){
    int initial_perm[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17, 9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7 };
    int exp_box[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
                      6, 7, 8, 9, 8, 9, 10, 11,
                      12, 13, 12, 13, 14, 15, 16, 17,
                      16, 17, 18, 19, 20, 21, 20, 21,
                      22, 23, 24, 25, 24, 25, 26, 27,
                      28, 29, 28, 29, 30, 31, 32, 1 };

    int S_box[8][4][16] =
    {{
        14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7,
        0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8,
        4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0,
        15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13
    },
    {
        15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10,
        3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5,
        0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15,
        13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9
    },
    {
        10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8,
        13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1,
        13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7,
        1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12
    },
    {
        7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15,
        13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9,
        10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4,
        3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14
    },
    {
        2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9,
        14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6,
        4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14,
        11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3
    },
    {
        12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11,
        10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8,
        9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6,
        4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13
    },
    {
        4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1,
        13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6,
        1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2,
        6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12
    },
    {
        13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7,
        1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2,
        7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8,
        2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11
    }};

    /// The permutation table
    int permutation_tab[32] = {16,7,20,21,29,12,28,17,
                                1,15,23,26,5,18,31,10,
                                2,8,24,14,32,27,3,9,
                                19,13,30,6,22,11,4,25};

    /// The inverse permutation table
    int inverse_permutation[64] =  {40,8,48,16,56,24,64,32,
                                    39,7,47,15,55,23,63,31,
                                    38,6,46,14,54,22,62,30,
                                    37,5,45,13,53,21,61,29,
                                    36,4,44,12,52,20,60,28,
                                    35,3,43,11,51,19,59,27,
                                    34,2,42,10,50,18,58,26,
                                    33,1,41,9,49,17,57,25};


    s = permutate(s,initial_perm,64);
    string l = s.substr(0,32);
    string r = s.substr(32,32);

    for(int i=0;i<16;i++)
    {
        string exp_rpt = "";
        for(int i=0;i<48;i++){
            exp_rpt+=r[exp_box[i]-1];
        }
        string xor_48 = Xor(keys[i],exp_rpt);
        string comp="";
        for(int i=0;i<8;i++){
            string srow = xor_48.substr(i*6,1)+xor_48.substr(i*6+5,1);
            int row = convertBinaryToDecimal(srow);
            string scol = xor_48.substr(i*6 + 1,1) + xor_48.substr(i*6 + 2,1) + xor_48.substr(i*6 + 3,1) + xor_48.substr(i*6 + 4,1);
            int col = convertBinaryToDecimal(scol);
            int val = S_box[i][row][col];
            comp+=convertDecimalToBinary(val);
        }
        string p_box="";
        for(int i=0;i<32;i++){
            p_box+=comp[permutation_tab[i]-1];
        }
        l = Xor(l,p_box);
        if(i<15){
            string temp = r;
            r=l;
            l=temp;
        }
    }

    string comb = l+r;
    string ans="";
    for(int i=0;i<64;i++){
        ans += comb[inverse_permutation[i]-1];
    }
    return ans;
}

int main(){
    cout<<"Enter plain text in hexa: ";
    string text;
    cin>>text;
    string key;
    cout<<"Enter key = ";
    cin>>key;

    text = hex_2_bin(text);
    key = hex_2_bin(key);
    generate_key(key);
    string cipher_text = encrypt(text);
    cipher_text = bin_2_hex(cipher_text);
    cout<<"Encrypted text = "<<cipher_text<<endl;

    reverse(keys.begin(),keys.end());
    cipher_text = hex_2_bin(cipher_text);
    string decrypt = encrypt(cipher_text);
    decrypt = bin_2_hex(decrypt);
    cout<<"Decrypted text = "<<decrypt<<endl;

    return 0;
}