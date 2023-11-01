#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "Individuo.h"
#include "Tabuleiro.h"

class AlgoritmoGenetico
{
public:
	int rounds;

	int genes;
	int numIndividuos;
	float removerPercent;
	float mutacaoPercent;
	
	vector<Individuo> individuos;

	AlgoritmoGenetico(int genes, int numIndividuos,  float removerPercent, float mutacaoPercent);

	void gerarPopulacaoInicial();

	void competir();

	void ordenarPopulacao();

	bool compareIndividuos(const Individuo& a, const Individuo& b);
	
	void eliminarPopulacao();

	void limparPontuacaoPopulacao();

	void cruzarPopulacao();

	void selecao();

	void apresentacao();
};

