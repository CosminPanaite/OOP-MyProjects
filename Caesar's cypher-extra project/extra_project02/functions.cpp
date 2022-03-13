//
//
#include <iostream>
#include <fstream>
#include <cstring>
#include "functions.h"

using namespace std;
ifstream f("C:\\Users\\Cosmin\\CLionProjects\\extra_project02\\distribution.txt");
ifstream g("C:\\Users\\Cosmin\\CLionProjects\\extra_project02\\text.txt");

void readDistributions(float distribution[26]) {
    /// Reads the expected frequency of characters in english

    int i;
    for (i = 0; i < 26; i++)
        f >> distribution[i]; /// a vector that reads from files
    f.close();
}

void readText(char text[500]) {
    /// Reads the original text

    char message[500];
    g.get(message, 500);
    strcpy(text, message);
    g.close();
}

float computeLength(char text[500], int order, float distribution[26]) {
    /// computes the distribution of a given character (having the position in alphabet equal to order)
    /// multiplied with the number of characters in text and divided by 100
    int length = 0;
    for (int index = 0; index < strlen(text); index++) {
        if (isalpha(text[index]))
            length++;
    }
    float dist = distribution[order] * 0.01;
    return float(dist * length);
}

void computeFrequencyInText(char text[500], int frequency[26]) {
    /// Computes the frequecy of both lower/upper case letters in the given text

    int index, ascii;
    for (index = 0; index < 26; index++) {
        frequency[index] = 0;
    }
    for (index = 0; index < strlen(text); index++) {
        if (islower(text[index])) {
            ascii = text[index] - 'a';
            frequency[ascii]++;
        }
        if (isupper(text[index])) {
            ascii = text[index] - 'A';
            frequency[ascii]++;
        }
    }
}

float computeChiSquaredDistance(char text[500], float distribution[26]) {
    /// computes the CHIsquared distance

    float chiSquared = 0;
    int frequency[26], order;
    computeFrequencyInText(text, frequency);
    for (order = 0; order < 26; order++) {
        chiSquared += (frequency[order] - computeLength(text, order, distribution)) *
                      (frequency[order] - computeLength(text, order, distribution)) /
                      computeLength(text, order, distribution);
    }
    return chiSquared;
}

void makeShifts(char text[500], int shift) {
    /// Makes shifts moving letters back to the specified shift

    int index;
    for (index = 0; index < strlen(text); index++) {
        if (islower(text[index])) {
            if (char(text[index] - shift) < 'a')
                text[index] = char(text[index] + 26 - shift);
            else
                text[index] = char(text[index] - shift);
        }
        if (isupper(text[index])) {
            if (char(text[index] - shift) < 'A')
                text[index] = char(text[index] + 26 - shift);
            else
                text[index] = char(text[index] - shift);
        }
    }
}

void decipherCaesarCipher(char text[500], float distribution[26]) {
    /// Breaks the cipher

    char decrytedText[500];
    float minimumChiSquared = computeChiSquaredDistance(text, distribution); /// here i retain the minimum Chi Squared distance
    int index;
    for (index = 0; index < 26; index++) {
        makeShifts(text, 1);
        if (computeChiSquaredDistance(text, distribution) < minimumChiSquared) {
            minimumChiSquared = computeChiSquaredDistance(text, distribution);
            strcpy(decrytedText, text);
        }
    }
    cout << "The deciphered text is:" << endl;
    cout << decrytedText << endl;
}