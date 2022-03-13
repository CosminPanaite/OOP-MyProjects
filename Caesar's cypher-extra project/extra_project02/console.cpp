//
//
#include <iostream>
#include <cstring>
#include "console.h"
#include "functions.h"

using namespace std;

void print_menu() {
    cout << "1. Read the expected frequency of characters in english" << endl;
    cout << "2. Read the original text" << endl;
    cout << "3. Display the original text" << endl;
    cout << "4. Decipher Caesar's Cipher" << endl;
    cout << "x. EXIT" << endl;
}

void console() {
    char option[2], text[500];
    float distribution[26];
    while (true) {
        print_menu();
        cin >> option;
        if (strcmp(option, "1") == 0) {
            readDistributions(distribution);
            cout << endl;
        } else if (strcmp(option, "2") == 0) {
            readText(text);
            cout << endl;
        } else if (strcmp(option, "3") == 0) {
            cout << "The original text is:" << endl;
            cout << text << endl;
        } else if (strcmp(option, "4") == 0) {
            decipherCaesarCipher(text, distribution);
            cout << endl;
        } else if (strcmp(option, "x") == 0) {
            cout << "EXIT" << endl;
            break;
        }
    }
}