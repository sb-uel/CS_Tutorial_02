#ifndef ROTORS_H
#define ROTORS_H

#include "includes.h"

enum rotors_type {
	//Rotores
	rotor_I, rotor_II, rotor_III, rotor_IV, rotor_V, rotor_VI, rotor_VII, rotor_VIII,
	rotor_beta, rotor_gama,

	//Refletores
	refletor_m3_b, refletor_m3_c,
	refletor_m4_b, refletor_m4_c
};

struct sRotors
{
	rotors_type rot_1;
	rotors_type rot_2;
	rotors_type rot_3;
	rotors_type rot_4;
	rotors_type ref_1;
};

class cRotors {
public:
	cRotors(vector<int> startPos, sRotors *MyRotors)
	{
		this->startPos = { 0, 0, 0 }; // referencia
		this->currentPos == startPos;
		this-> MyRotors = MyRotors;
	}

	sRotors *MyRotors;
	void setRotors(int Pos1, int Pos2, int Pos3);
	vector<int> getRotors();
	void rotacionar();
	char mapearLetra(char letra, rotors_type rotor, int left_right);
	char refletor(char letra, rotors_type refletor);
private:
	int getRotorNumberByRotor(rotors_type rotor);
	string rotor_alfabeto(rotors_type index);
	vector<int> startPos, currentPos;
	vector<int> quandoRotacionar(rotors_type type);
};
extern cRotors *pRotors;

#endif // ! ROTORS_H
