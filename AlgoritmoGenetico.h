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
	float pontuacaoPercent;

	float percentMelhorIndividuo;
	
	vector<Individuo> individuos;

	AlgoritmoGenetico(int genes, int numIndividuos,  float removerPercent, float mutacaoPercent, float pontuacaoPercent);

	void gerarPopulacaoInicial();

	void competir();

	void ordenarPopulacao();

	bool compareIndividuos(const Individuo& a, const Individuo& b);
	
	void eliminarPopulacao();

	void limparPontuacaoPopulacao();

	void cruzarPopulacao();

	array<vector<array<int, 2>>, 2> selecao();

	void apresentacao();

	void salvaPorcentMelhorIndividuo();

	array<vector<array<int, 2>>, 2> jogarContraAleatorio();

};

