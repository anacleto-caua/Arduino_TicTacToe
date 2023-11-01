#pragma once
#include <vector>
#include <random>

using  namespace std;

class Individuo
{
	public:
		int genes;
	
		vector<int> dnaX;
		vector<int> dnaY;
	
		int vitorias = 0;
		int derrotas = 0;
		int empates = 0;
		int pontuacao = 0;

		Individuo();

		Individuo(int genes);

		Individuo(Individuo pai, Individuo mae);

		int randomGene();
		int zeroOuUm();

		void limparPontuacaoIndividuo();
		void mutacao();

		void premiarVitoria();
		void premiarDerrota();
		void premiarEmpate();
};

