#include "Includes.h"

int cStuff::mod(int a, int b) {
	return (a >= 0 || a % b == 0) ? (a % b) : (b + a % b);
}

char cStuff::intToChar(int letra) {
	return letra + ASCII_START;
}

int cStuff::charToInt(char letra) {
	return letra - ASCII_START;
}

bool cStuff::buscaInt(vector<int> vetor, int item)
{
	return std::find(vetor.begin(), vetor.end(), item) != vetor.end();
}

bool cStuff::buscaChar(vector<char> vetor, int item)
{
	return std::find(vetor.begin(), vetor.end(), item) != vetor.end();
}
