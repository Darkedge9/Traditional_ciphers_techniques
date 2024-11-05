#include <iostream>
#include <string>

using namespace std;

string railFenceEncrypt(const string &plaintext, int rails) {
    string ciphertext;
    int len = plaintext.length();
    char rail[rails][len];
    fill(&rail[0][0], &rail[0][0] + sizeof(rail), '\n'); 
   
    for (int row = 0, col = 0, down = 0; col < len; col++) {
        rail[row][col] = plaintext[col];
        if (row == 0) down = 1; 
        if (row == rails - 1) down = 0;
        down ? row++ : row--;
    }

    
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != '\n') ciphertext += rail[i][j];

    return ciphertext;
}

string railFenceDecrypt(const string &ciphertext, int rails) {
    string plaintext;
    int len = ciphertext.length();
    char rail[rails][len];
    fill(&rail[0][0], &rail[0][0] + sizeof(rail), '\n');

    for (int row = 0, col = 0, down = 0; col < len; col++) {
        rail[row][col] = '*';
        if (row == 0) down = 1;
        if (row == rails - 1) down = 0;
        down ? row++ : row--;
    }

    for (int i = 0, index = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len) rail[i][j] = ciphertext[index++];

    for (int row = 0, col = 0, down = 0; col < len; col++) {
        plaintext += rail[row][col];
        if (row == 0) down = 1;
        if (row == rails - 1) down = 0;
        down ? row++ : row--;
    }

    return plaintext;
}

int main() {
    string plaintext;
    int rails;
    cout << "Enter plaintext: ";
    getline(cin, plaintext);
    cout << "Enter number of rails: ";
    cin >> rails;

    string ciphertext = railFenceEncrypt(plaintext, rails);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = railFenceDecrypt(ciphertext, rails);
    cout << "Decrypted Text: " << decryptedText << endl;

    return 0;
}
