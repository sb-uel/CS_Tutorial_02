#include "Includes.h"

string cRotors::rotor_alfabeto(rotors_type rotor)
{
	switch (rotor)
	{
	case rotor_I:
		return "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	case rotor_II:
		return "AJDKSIRUXBLHWTMCQGZNPYFVOE";
	case rotor_III:
		return "BDFHJLCPRTXVZNYEIWGAKMUSQO";
	case rotor_IV:
		return "ESOVPZJAYQUIRHXLNFTGKDCMWB";
	case rotor_V:
		return "VZBRGITYUPSDNHLXAWMJQOFECK";
	case rotor_VI:
		return "JPGVOUMFYQBENHZRDKASXLICTW";
	case rotor_VII:
		return "NZJHGRCXMYSWBOUFAIVLPEKQDT";
	case rotor_VIII:
		return "FKQHTLXOCBJSPDZRAMEWNIUYGV";
	case rotor_beta:
		return "LEYJVCNIXWPBQMDRTAKZGFUHOS";
	case rotor_gama:
		return "FSOKANUERHMBTIYCWLQPZXVGJD";
	case refletor_m3_b:
		return "YRUHQSLDPXNGOKMIEBFZCWVJAT";
	case refletor_m3_c:
		return "FVPJIAOYEDRZXWGCTKUQSBNMHL";
	case refletor_m4_b:
		return "ENKQAUYWJICOPBLMDXZVFTHRGS";
	case refletor_m4_c:
		return "RDOBJNTKVEHMLFCWZAXGYIPSUQ";
	default:
		return "";
	}
}

vector<int> cRotors::quandoRotacionar(rotors_type rotor) {
	switch (rotor) {
	case rotor_I:
		return { 16 };
	case rotor_II:
		return { 4 };
	case rotor_III:
		return { 21 };
	case rotor_IV:
		return { 9 };
	case rotor_V:
		return { 25 };
	case rotor_VI:
	case rotor_VII:
	case rotor_VIII:
		return { 12, 25 };
	default:
		return {};
	}
}

void cRotors::setRotors(int Pos1, int Pos2, int Pos3)
{
	this->currentPos[0] = Pos1;
	this->currentPos[1] = Pos2;
	this->currentPos[2] = Pos3;
}

vector<int> cRotors::getRotors()
{
	return this->currentPos;
}

void cRotors::rotacionar()
{
	if ( pStuff->buscaInt(this->quandoRotacionar(MyRotors->rot_3), this->currentPos[2]) ) {
		if (pStuff->buscaInt(this->quandoRotacionar(MyRotors->rot_2), this->currentPos[1])) {
			this->currentPos[0]++;
		}

		this->currentPos[1]++;
	}
	else {
		if (pStuff->buscaInt(this->quandoRotacionar(MyRotors->rot_2), this->currentPos[1])) {
			this->currentPos[0]++;
			this->currentPos[1]++;
		}
	}
	
	this->currentPos[2]++;

	if (this->currentPos[0] > 25) this->currentPos[0] = 0;
	if (this->currentPos[1] > 25) this->currentPos[1] = 0;
	if (this->currentPos[2] > 25) this->currentPos[2] = 0;
}

int cRotors::getRotorNumberByRotor(rotors_type rotor)
{
	if (rotor == this->MyRotors->rot_1)
		return 0;
	else if (rotor == this->MyRotors->rot_2)
		return 1;
	else if (rotor == this->MyRotors->rot_3)
		return 2;
	else
		return -1; /// error
}

char cRotors::mapearLetra(char letra, rotors_type rotor, int left_right)
{
	letra = pStuff->charToInt(letra);

	int startPos = this->startPos[getRotorNumberByRotor(rotor)];
	letra -= startPos;
	letra = pStuff->mod(letra, 26);

	int currentPos = this->currentPos[getRotorNumberByRotor(rotor)];
	letra += currentPos;
	letra = pStuff->mod(letra, 26);

	if (left_right == 0) { // da direita para a esquerda
		char temp = rotor_alfabeto(rotor).at(letra);
		letra = pStuff->charToInt(temp);
	}
	else { // da esquerda para a direita
		letra = rotor_alfabeto(rotor).find(pStuff->intToChar(letra));
	}

	letra -= currentPos;
	letra = pStuff->mod(letra, 26);

	letra += startPos;
	letra = pStuff->mod(letra, 26);

	return pStuff->intToChar(letra);
}

char cRotors::refletor(char letra, rotors_type refletor)
{
	return rotor_alfabeto(refletor)[pStuff->charToInt(letra)];
}