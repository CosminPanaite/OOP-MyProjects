//
// Created by Cosmin on 27/03/2021.
//

#ifndef EXTRA_PROJECT02_FUNCTIONS_H
#define EXTRA_PROJECT02_FUNCTIONS_H

void readDistributions(float distribution[26]);

void readText(char text[500]);

float computeLength(char text[500], int order, float distribution[26]);

void computeFrequencyInText(char text[500], int frequncy[26]);

float computeChiSquaredDistance(char text[500], float distribution[26]);

void makeShifts(char text[500], int shift);

void decipherCaesarCipher(char text[500], float distribution[26]);

#endif //EXTRA_PROJECT02_FUNCTIONS_H
