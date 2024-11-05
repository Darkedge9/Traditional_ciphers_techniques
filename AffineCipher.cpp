#include <iostream>
#include <string>
using namespace std;

string affineEncipher(string text, int a, int b) {
    string result = "";

    for (char c : text) {
        if (isupper(c))
            result += char(((a * (c - 'A') + b) % 26) + 'A');
        else if (islower(c))
            result += char(((a * (c - 'a') + b) % 26) + 'a');
        else
            result += c;
    }
    return result;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; 
}

string Plaintxt(string ciphertext, int a, int b) {
    string result = "";
    int aInverse = modInverse(a, 26);
    if (aInverse == -1) {
        return "Error: Multiplicative inverse does not exist.";
    }

    for (char c : ciphertext) {
        if (isupper(c))
            result += char((aInverse * (c - 'A' - b + 26)) % 26 + 'A');
        else if (islower(c))
            result += char((aInverse * (c - 'a' - b + 26)) % 26 + 'a');
        else
            result += c;
    }
    return result;
}

int main() {
    string PT ;
    int a ,b;
    cout<<"Enter the string for Affine Cipher :";getline(cin,PT);

    cout<<"Enter the keys , a and b :";cin>>a>>b;

    string CT = affineEncipher(PT, a, b);
    cout << "-----------Encryption----------------";
    cout << "\nGenerated Cipher Text: " << CT;

    string Plain = Plaintxt(CT, a, b);
    cout << "\n-----------Decryption----------------";
    cout << "\nGenerated Plaintext Text: " << Plain;

    return 0;
}
