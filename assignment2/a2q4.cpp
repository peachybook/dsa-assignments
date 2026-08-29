/*String Related Programs
(a) Write a program to concatenate one string to another string.
(b) Write a program to reverse a string.
(c) Write a program to delete all the vowels from the string.
(d) Write a program to sort the strings in alphabetical order.
(e) Write a program to convert a character from uppercase to lowercase.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// (a) Concatenate one string to another
void concatenate() {
    string str1, str2;

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;

    str1 = str1 + str2;

    cout << "Concatenated string: " << str1 << endl;
}

// (b) Reverse a string
void reverseString() {
    string str;

    cout << "Enter a string  to get it reveresed : ";
    cin >> str;

    reverse(str.begin(), str.end());

    cout << "Reversed string: " << str << endl;
}

// (c) Delete all vowels from a string
void removeVowels() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u') {
            
            str.erase(i, 1);
            i--;
        }
    }

    cout << "String after removing vowels: " << str << endl;
}

// (d) Sort strings alphabetically
void sortStrings() {
    string str[5];

    cout << "Enter 5 strings:" << endl;

    for (int i = 0; i < 5; i++)
        cin >> str[i];

    for (int i = 0; i < 4; i++) {
        int minIndex = i;

        for (int j = i + 1; j < 5; j++) {
            if (str[j] < str[minIndex]) {
                minIndex = j;
            }
        }

        string temp = str[i];
        str[i] = str[minIndex];
        str[minIndex] = temp;
    }

    cout << "Strings in alphabetical order:" << endl;

    for (int i = 0; i < 5; i++)
        cout << str[i] << endl;
}

// (e) Convert uppercase character to lowercase
void convertToLower() {
    char ch;

    cout << "Enter an uppercase character: ";
    cin >> ch;

    ch = ch + 32;

    cout << "Lowercase character: " << ch << endl;
}

int main() {
    concatenate();
    reverseString();
    removeVowels();
    sortStrings();
    convertToLower();

    return 0;
}