#include <iostream>
#include <string>
using namespace std;

string Encipher(string text, int s)
{
    string result = "";

    int i = 0;
    while (i < text.length())
    {

        if (isupper(text[i]))
            result += char(int((text[i] - 65) * s % 26) + 65);

        else if (islower(text[i]))
            result += char(int((text[i] - 97) * s % 26) + 65);

        else
            result += text[i];

        i++;
    }
    return result;
}
string Plaintxt(string ciphertext, int key)
{
    string result = "";
    int modInverse = 0;
    for (int i = 0; i < 26; i++)
    {
        if ((key * i) % 26 == 1)
        {
            modInverse = i;
            break;
        }
    }
    for (char &c : ciphertext)
    {
        if (isalpha(c))
        {
            if (isupper(c))
                result += char(((c - 'A') * modInverse) % 26 + 'A');
            else
                result += char(((c - 'a') * modInverse) % 26 + 'a');
        }
        else
        {
            result += c;
        }
    }
    return result;
}

int main()
{
    string PT;
    int key;
    cout << "\nEnter the Plaintext : ";
    getline(cin, PT);
    cout << "Enter the Multiplicative Key : ";
    cin >> key;
    string CT = Encipher(PT, key);
    cout << "-----------Encryption----------------";
    cout << "\nGenerated Cipher Text :" << CT;
    string Plain = Plaintxt(CT, key);
    cout << "\n-----------Decryption----------------";
    cout << "\nGenerated Plaintxt Text :" << Plain;
    return 0;
}