#include <iostream>
using namespace std;

void getKeyMatrix(string key, int keyMatrix[][3])
{
    int k = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            keyMatrix[i][j] = (key[k] - 'A') % 26;
            k++;
        }
    }
}

void getCofactor(int A[N][N], int temp[N][N], int p, int q, int n)
{
    int i = 0, j = 0;
 
    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
 
                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

int determinant(int A[N][N], int n)
{
    int D = 0; // Initialize result
 
    //  Base case : if matrix contains single element
    if (n == 1)
        return A[0][0];
 
    int temp[N][N]; // To store cofactors
 
    int sign = 1;  // To store sign multiplier
 
     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of A[0][f]
        getCofactor(A, temp, 0, f, n);
        D += sign * A[0][f] * determinant(temp, n - 1);
 
        // terms are to be added with alternate sign
        sign = -sign;
    }
 
    return D;
}

void inversematrix(int a[][3], int b[][3]) 
{
    int det = determinant(A, N);
    if (det == 0)
    {
        cout << "Singular matrix, can't find its inverse";
        return;
    }
 
    // Find adjoint
    int adj[N][N];
    adjoint(A, adj);
 
    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i=0; i<N; i++)
        for (int j=0; j<N; j++)
            inverse[i][j] = adj[i][j]/float(det);
 
    return true;
}

string encrypt(string message, string key)
{
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageVector[3][1];
    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (message[i] - 'A') % 26;
    
    int cipherMatrix[3][1];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cipherMatrix[i][j] = 0;

            for (int k = 0; k < 3; k++)
            {
                cipherMatrix[i][j] = (cipherMatrix[i][j] + keyMatrix[i][k] * messageVector[k][j])%26;
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }

    string CipherText;
    for (int i = 0; i < 3; i++)
        CipherText += cipherMatrix[i][0] + 'A';

    return CipherText;
}

int main()
{
    string key, plainText;
    cout << "Enter the message to be encrypted : ";
    cin >> plainText;
    cout << "Enter the key : ";
    cin >> key;
    key = "GYBNQKURP";

    string cipherText = encrypt(plainText, key);
    cout << "Encrypted cipher text is : " << cipherText << endl;
    cout << "Decrypted message is : " << decrypt(cipherText, key) << endl;
}
