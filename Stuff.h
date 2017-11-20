#ifndef  STUFF_H
#define STUFF_H

#include "Includes.h"

#define ASCII_START	'A'

class cStuff {
public:
	cStuff()
	{

	}
	int mod(int a, int b);
	char intToChar(int letra);
	int charToInt(char letra);
	bool buscaInt(vector<int> vetor, int item);
	bool buscaChar(vector<char> vetor, int item);
};

extern cStuff *pStuff;
#endif // ! STUFF_H
