#ifndef  PLUGBOARD_H
#define PLUGBOARD_H

#include "includes.h"

#define MAXPLUGS	10

class cPlugboard {
public:
	cPlugboard()
	{
		plugs = 0;
		PLUG = vector<vector<char>>(MAXPLUGS, vector<char>(2));
	}

	void addPlug(char c1, char c2);
	char cipherPlug(char letra);
private:
	int plugs;
	vector<vector<char>> PLUG;
};
extern cPlugboard* pPlugboard;

#endif // ! PLUGBOARD_H
