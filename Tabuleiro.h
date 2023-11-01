#pragma once
#include <vector>
#include "Individuo.h"

class Tabuleiro
{
public:

	Individuo a;
	Individuo b;
	
	int vitoriasPrimeiro;
	int vitoriasSegundo;

	int vencedorRound;
	
	int tabuleiro[3][3];

	Tabuleiro();

	void limpaTabuleiro();

	void competir(Individuo& a, Individuo& b);

	int* codigoParaXY(int jogada);

	bool isJogadaValida(int jogada);

	bool terminou();
	
	int vencedorDaLinha(int a, int b, int c);

	void premiar();

};

