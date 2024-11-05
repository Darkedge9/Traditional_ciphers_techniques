#include <iostream>
#include <string>
using namespace std;

string sanitizer(const string &input) {
    string sanitized;
    for (char ch : input) {
        if (isalpha(ch)) { 
            sanitized += toupper(ch);
        }
    }
    return sanitized;
}

string vigenereEncrypt(const string &plaintext, const string &keyword) {
    string ciphertext;
    string sanitizedKeyword = sanitizer(keyword);
    string sanitizedPlaintext = sanitizer(plaintext);
    
    int keywordLength = sanitizedKeyword.length();
    for (int i = 0, j = 0; i < sanitizedPlaintext.length(); i++) {
        char p = sanitizedPlaintext[i];
        char k = sanitizedKeyword[j % keywordLength];
        char encryptedChar = 'A' + (p - 'A' + k - 'A') % 26; 
        ciphertext += encryptedChar;
        j++;
    }
    return ciphertext;
}


string vigenereDecrypt(const string &ciphertext, const string &keyword) {
    string plaintext;
    string sanitizedKeyword = sanitizer(keyword);
    string sanitizedCiphertext = sanitizer(ciphertext);
    
    int keywordLength = sanitizedKeyword.length();
    for (int i = 0, j = 0; i < sanitizedCiphertext.length(); i++) {
        char c = sanitizedCiphertext[i];
        char k = sanitizedKeyword[j % keywordLength];
        char decryptedChar = 'A' + (c - 'A' - (k - 'A') + 26) % 26;
        plaintext += decryptedChar;
        j++; 
    }
    return plaintext;
}

int main() {
    string keyword, plaintext, ciphertext;

    cout << "Enter the keyword: ";
    getline(cin, keyword);
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    ciphertext = vigenereEncrypt(plaintext, keyword);
    cout << "Ciphertext: " << ciphertext << endl;

    string decryptedText = vigenereDecrypt(ciphertext, keyword);
    cout << "Decrypted Plaintext: " << decryptedText << endl;

    return 0;
}
