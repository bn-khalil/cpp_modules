
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>

bool isPseudo(std::string arg);

void displayPseudoLiterals(std::string arg);

bool isChar(std::string arg);

void printChar(std::string arg);

bool isNum(std::string arg);

void displayInterger(int num);

void displayFloat(float num);

void displayDouble(double num);

void displayImpossible();

bool isFloat(std::string arg);

bool isDouble(std::string arg);

#endif