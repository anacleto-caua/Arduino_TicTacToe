#pragma once
#include <vector>
#include <array>
#include "Individuo.h"

class Tabuleiro
{
public:

	int vitoriasPrimeiro;
	int vitoriasSegundo;

	int vencedorRound;
	
	int tabuleiro[3][3];

	Tabuleiro();

	void limpaTabuleiro();

	void competir(Individuo& a, Individuo& b);

	array<int, 2> codigoParaXY(int jogada);

	bool isJogadaValida(int jogada);

	bool terminou();
	
	int vencedorDaLinha(int a, int b, int c);

	void premiar(Individuo& a, Individuo& b);

};

