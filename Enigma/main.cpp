/*************************************
**    Criado por Marcos Santana     **
** Contato: marcos_santana@ieee.org **
**************************************/

#include "Includes.h"

// Ponteiros
cRotors *pRotors;
cPlugboard* pPlugboard;
cStuff *pStuff;

void doCipher(char letra)
{
	// Rotacionar os motres ao pressionar uma tecla
	pRotors->rotacionar();

	// Plugboard Entrada
	letra = pPlugboard->cipherPlug(letra);

	// Ir da Direita para a Esquerda
	letra = pRotors->mapearLetra(letra, rotor_III, 0);
	letra = pRotors->mapearLetra(letra, rotor_II, 0);
	letra = pRotors->mapearLetra(letra, rotor_I, 0);

	// Refletores
	letra = pRotors->refletor(letra, refletor_m3_b);

	// Ir da Esquerda para a Direita
	letra = pRotors->mapearLetra(letra, rotor_I, 1);
	letra = pRotors->mapearLetra(letra, rotor_II, 1);
	letra = pRotors->mapearLetra(letra, rotor_III, 1);

	// Plugboard Sairda
	letra = pPlugboard->cipherPlug(letra);

	cout << letra;
}

int main()
{
	sRotors MyRotors = { rotor_I, rotor_II, rotor_III, refletor_m3_b };
	vector<int> StartPos = { 0, 0, 0 }; // AAA
	pRotors = new cRotors(StartPos, &MyRotors);

	pPlugboard = new cPlugboard();
	pPlugboard->addPlug('A', 'B');
	pPlugboard->addPlug('C', 'D');

	string texto = "ARROZ";

	for (size_t i = 0; i < texto.size(); i++)	doCipher(texto[i]);
	cout << endl;

	return 0;
}