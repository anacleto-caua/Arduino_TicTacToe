#include "Individuo.h"
#include <iostream>

Individuo::Individuo() {

	this->genes = 0;

	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;

	this->dnaX = vector<int>(genes);
	this->dnaY = vector<int>(genes);

	for (int i = 0; i < genes; i++) {
		dnaX[i] = randomGene();
		dnaY[i] = randomGene();
	}
}

Individuo::Individuo(int genes) {
	
	this->genes = genes;

	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;
	
	this->dnaX = vector<int>(genes);
	this->dnaY = vector<int>(genes);

	for (int i = 0; i < genes; i++) {
		dnaX[i] = randomGene();
		dnaY[i] = randomGene();
	}
}

Individuo::Individuo(Individuo pai, Individuo mae) {
	this->genes = pai.genes;

	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;
	
	this->dnaX = vector<int>(genes);
	this->dnaY = vector<int>(genes);

	for (int i = 0; i < genes; i++) {
		if (zeroOuUm() == 0) {
			dnaX[i] = pai.dnaX[i];
		}
		else {
			dnaX[i] = mae.dnaX[i];
		}

		if (zeroOuUm() == 0) {
			dnaY[i] = pai.dnaY[i];
		}
		else {
			dnaY[i] = mae.dnaY[i];
		}
	}
}

int Individuo::randomGene()
{
	std::random_device rd; // Use a random device to seed the engine
	std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator

	// Define a distribution (e.g., for integers between 1 and 100)
	std::uniform_int_distribution<int> distribution(0, 8);

	// Generate a random integer
	int randomValue = distribution(gen);

	// Return the generated random integer
	return randomValue;
}

int Individuo::zeroOuUm()
{
	std::random_device rd; // Use a random device to seed the engine
	std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator

	// Define a distribution (e.g., for integers between 1 and 100)
	std::uniform_int_distribution<int> distribution(0, 1);

	// Generate a random integer
	int randomValue = distribution(gen);

	// Return the generated random integer
	return randomValue;
}

void Individuo::limparPontuacaoIndividuo() {
	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;
}

void Individuo::mutacao() {
	random_device rd;
	mt19937 generator(rd()); //use the Mersenne Twister algorithm to generate numbers

	uniform_int_distribution<int> generate(0, genes-1);
	
	dnaX[generate(generator)] = randomGene();
	dnaY[generate(generator)] = randomGene();
}

void Individuo::premiarVitoria() {
	vitorias++;
	pontuacao += 3;
	contarJogada();

}

void Individuo::premiarDerrota() {
	derrotas++;
	pontuacao += 0;
	contarJogada();
}

void Individuo::premiarEmpate() {
	empates++;
	pontuacao += 1;
	contarJogada();
}

void Individuo::contarJogada()
{
	jogos++;
}
