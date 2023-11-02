#include "AlgoritmoGenetico.h"
#include <iostream>

AlgoritmoGenetico::AlgoritmoGenetico(int genes, int numIndividuos, float removerPercent, float mutacaoPercent, float pontuacaoPercent)
{
	rounds = 0;

	this->genes = genes;
	this->numIndividuos = numIndividuos;
	this->removerPercent = removerPercent;
	this->mutacaoPercent = mutacaoPercent;
	this->pontuacaoPercent = pontuacaoPercent;
}

void AlgoritmoGenetico::gerarPopulacaoInicial()
{
	for (int i = 0; i < numIndividuos; i++) {
		Individuo ind = Individuo(genes);
		individuos.push_back(ind);
	}
}

void AlgoritmoGenetico::competir()
{
	Tabuleiro tabuleiro = Tabuleiro();
	int n = 0;
	for (int i = 0; i < numIndividuos; i++) {
		for (int j = 0; j < numIndividuos; j++) {
			tabuleiro.competir(individuos[i], individuos[j]);
		}
	}
}

bool AlgoritmoGenetico::compareIndividuos(const Individuo& a, const Individuo& b)
{
	return a.pontuacao > b.pontuacao;
}

void AlgoritmoGenetico::ordenarPopulacao()
{
	sort(individuos.begin(), individuos.end(), [](const Individuo& a, const Individuo& b) {
		return a.pontuacao > b.pontuacao;
	});
}

void AlgoritmoGenetico::eliminarPopulacao()
{
	int remocao = numIndividuos * removerPercent / 100.0;

	for (int i = 0; i < remocao; i++) {
		individuos.pop_back();
	}
}

void AlgoritmoGenetico::limparPontuacaoPopulacao()
{
	for (int i = 0; i < individuos.size(); i++) {
		individuos[i].limparPontuacaoIndividuo();
	}
}

void AlgoritmoGenetico::cruzarPopulacao()
{
	int remocao = numIndividuos * removerPercent / 100.0;
	
	Individuo ind;
	while (individuos.size() != numIndividuos) {
		for (int i = 0; i < numIndividuos - remocao && individuos.size() != numIndividuos; i += 2) {
			ind = Individuo(individuos[i], individuos[i + 1]);
			
			random_device rd;
			mt19937 generator(rd()); //use the Mersenne Twister algorithm to generate numbers

			uniform_int_distribution<int> generate(1, 100);
			if (generate(generator) < mutacaoPercent) {
				ind.mutacao();
			}

			if (individuos.size() != numIndividuos) {
				individuos.push_back(ind);
			}
		}
	}
}

void AlgoritmoGenetico::selecao()
{	
	int pontuacaoMaxima = numIndividuos * numIndividuos * 3;
	gerarPopulacaoInicial();

	while (individuos[0].pontuacao <= pontuacaoMaxima * pontuacaoPercent) {
		limparPontuacaoPopulacao();

		competir();

		ordenarPopulacao();

		apresentacao();

		eliminarPopulacao();

		cruzarPopulacao();

		rounds++;
	}
}

void AlgoritmoGenetico::apresentacao()
{

	cout << "Round: " << rounds << endl;
	cout << "Melhor individuo" << endl;
	cout << "Pontuacao: " << individuos[0].pontuacao << endl;
	cout << "Jogadas: " << individuos[0].vitorias + individuos[0].empates + individuos[0].derrotas << endl;
	cout << endl << endl;
	cout << "Pior individuo" << endl;
	cout << "Pontuacao: " << individuos[numIndividuos-1].pontuacao << endl;
	cout << "Jogadas: " << individuos[numIndividuos - 1].vitorias + individuos[numIndividuos - 1].empates + individuos[numIndividuos - 1].derrotas << endl;

	cout << endl << endl;

}
