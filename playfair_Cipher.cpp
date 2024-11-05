#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string bogusBlend(const string text)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        char ch = toupper(text[i]);
        if (ch == ' ')
            continue;
        if (ch == 'J')
            ch = 'I';
        result += ch;
        if (i + 1 < text.length() && text[i] == text[i + 1])
        {
            result += 'X';
        }
    }
    if (result.length() % 2 != 0)
    {
        result += 'X';
    }
    return result;
}

void generateKeyMatrix(const string &key, char keyMatrix[5][5])
{
    bool used[26] = {false};
    int row = 0, col = 0;

    for (char ch : key)
    {
        ch = toupper(ch);
        if (ch == 'J')
            ch = 'I';
        if (!used[ch - 'A'])
        {
            keyMatrix[row][col++] = ch;
            used[ch - 'A'] = true;

            if (col == 5)
            {
                col = 0;
                row++;
            }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        if (ch == 'J')
            continue;
        if (!used[ch - 'A'])
        {
            keyMatrix[row][col++] = ch;
            used[ch - 'A'] = true;

            if (col == 5)
            {
                col = 0;
                row++;
            }
        }
    }
}

void findPosition(char keyMatrix[5][5], char ch, int &row, int &col)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyMatrix[i][j] == ch)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

string encryptText(const string &sentence, char keyMatrix[5][5])
{
    string encryptedSentence;
    string preparedText = bogusBlend(sentence); // Prepare the text

    for (size_t i = 0; i < preparedText.length(); i += 2)
    {
        char a = preparedText[i];
        char b = (i + 1 < preparedText.length()) ? preparedText[i + 1] : 'X'; // Use 'X' if the last character is alone
        int row1, col1, row2, col2;
        findPosition(keyMatrix, a, row1, col1);
        findPosition(keyMatrix, b, row2, col2);

        if (row1 == row2)
        {
            encryptedSentence += keyMatrix[row1][(col1 + 1) % 5];
            encryptedSentence += keyMatrix[row2][(col2 + 1) % 5];
        }
        else if (col1 == col2)
        {
            encryptedSentence += keyMatrix[(row1 + 1) % 5][col1];
            encryptedSentence += keyMatrix[(row2 + 1) % 5][col2];
        }
        else
        {
            encryptedSentence += keyMatrix[row1][col2];
            encryptedSentence += keyMatrix[row2][col1];
        }
    }

    return encryptedSentence;
}

int main()
{
    string key, sentence;
    cout << "Enter the key: ";
    cin >> key;
    cin.ignore();
    cout << "Enter the plaintext : ";
    getline(cin, sentence);
    string bpt = bogusBlend(sentence);
    cout << "Adding Bogus character to the plaintext :" << bpt;
    cout << endl;
    char keyMatrix[5][5];
    generateKeyMatrix(key, keyMatrix);

    cout << "Key Matrix:\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << keyMatrix[i][j] << " ";
        }
        cout << endl;
    }
    string ciphertext = encryptText(sentence, keyMatrix);
    cout << "Ciphertext: " << ciphertext << endl;

    return 0;
}
