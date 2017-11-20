#include "Includes.h"

void cPlugboard::addPlug(char c1, char c2)
{
	PLUG[plugs][0] = c1;
	PLUG[plugs][1] = c2;

	plugs++;
}

char cPlugboard::cipherPlug(char letra) 
{
	for (int i = 0; i < plugs; i++) {
		if (pStuff->buscaChar(PLUG[i], letra)) {
			if (letra == PLUG[i][0])
				letra = PLUG[i][1];
			else
				letra = PLUG[i][0];
			}
	}
	return letra;
}