#include <iostream>
#include <string>
using namespace std;

string shiftCipher(string text, int s)
{
    string result = "";
    int i = 0;
    while (i < text.length())
    {
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);

        else if (islower(text[i]))
            result += char(int(text[i] + s - 97) % 26 + 97);

        else
            result += text[i];

        i++;
    }
    return result;
}
string Plaintxt(string text, int s)
{
    string result = "";
    int i = 0;
    while (i < text.length())
    {
        if (isupper(text[i]))
            result += char(int(text[i] - s - 65) % 26 + 65);

        else if (islower(text[i]))
            result += char(int(text[i] - s - 97) % 26 + 97);

        else
            result += text[i];

        i++;
    }
    return result;
}

int main()
{
    string PT;
    int key;
    cout << "\nEnter the Plaintext : ";
    getline(cin, PT);
    cout << "Enter the Shift Key : ";
    cin >> key;
    string CT = shiftCipher(PT, key);
    cout<<"-----------Encryption----------------";
    cout << "\nGenerated Cipher Text :" << CT;
    string Plain = Plaintxt(CT, key);
    cout<<"\n-----------Decryption----------------";
    cout << "\nGenerated Plaintxt Text :" << Plain;
    return 0;
}