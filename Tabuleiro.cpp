#include "Tabuleiro.h"
#include <iostream>
#ifdef _WIN32
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#endif


Tabuleiro::Tabuleiro(){

	this->vencedorRound = -1;

	this->vitoriasPrimeiro = 0;
	this->vitoriasSegundo = 0;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tabuleiro[i][j] = 0;
		}
	}
}

void Tabuleiro::limpaTabuleiro()
{
	vitoriasPrimeiro = 0;
	vitoriasSegundo = 0;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			tabuleiro[i][j] = 0;
		}
	}
}

void Tabuleiro::competir(Individuo& a, Individuo& b) 
{
	this->vencedorRound = -1;
	
	int genesA = 0;
	int genesB = 0;
	
	int jogadaA = -1;
	int jogadaB = -1;

	array<int, 2> move;
	while (genesA < a.genes && genesB < b.genes) {
		
		while (!isJogadaValida(jogadaA) && genesA < a.genes) {
			jogadaA = a.dnaX[genesA];
			genesA++;
		}
		
		move = codigoParaXY(jogadaA);
		tabuleiro[move[0]][move[1]] = 1;

		if (terminou()) {
			break;
		}

		while (!isJogadaValida(jogadaB) && genesB < b.genes) {
			jogadaB = b.dnaY[genesB];
			genesB++;
		}
	
		move = codigoParaXY(jogadaB);
		tabuleiro[move[0]][move[1]] = 2;

		if (terminou()) {
			break;
		}

	}

	premiar(a, b);
	limpaTabuleiro();
}

array<int, 2> Tabuleiro::codigoParaXY(int jogada) {
	int x = 0;
	int y = 0;

	switch (jogada) {
	case 0:
		x = 0;
		y = 0;
		break;
	case 1:
		x = 0;
		y = 1;
		break;
	case 2:
		x = 0;
		y = 2;
		break;
	case 3:
		x = 1;
		y = 0;
		break;
	case 4:
		x = 1;
		y = 1;
		break;
	case 5:
		x = 1;
		y = 2;
		break;
	case 6:
		x = 2;
		y = 0;
		break;
	case 7:
		x = 2;
		y = 1;
		break;
	case 8:
		x = 2;
		y = 2;
		break;
	default:
		// Faz o L!!!!!
		break;
	}


	return {x, y};
}

bool Tabuleiro::isJogadaValida(int jogada) {
	int x = 0;
	int y = 0;

	switch (jogada) {
		case 0:
			x = 0;
			y = 0;
			break;
		case 1:
			x = 0;
			y = 1;
			break;
		case 2:
			x = 0;
			y = 2;
			break;
		case 3:
			x = 1;
			y = 0;
			break;
		case 4:
			x = 1;
			y = 1;
			break;
		case 5:
			x = 1;
			y = 2;
			break;
		case 6:
			x = 2;
			y = 0;
			break;
		case 7:
			x = 2;
			y = 1;
			break;
		case 8: 
			x = 2;
			y = 2;
			break;
		default:
			// Faz o L!!!!!
			return false;
			break;
	}

	if (tabuleiro[x][y] == 0) {
		return true;
	}

	return false;
}

bool Tabuleiro::terminou() {
	//DeuVelha
	int preenchidos = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tabuleiro[i][j] != 0) {
				preenchidos++;
			}
		}
	}
	if (preenchidos >= 9) {
		this->vencedorRound = 0;
	}

	int vencedor = 0;

	for (int i = 0; i < 3; i++) {
		// Caso de vitória em uma linha
		vencedor = vencedorDaLinha(tabuleiro[0][i], tabuleiro[1][i], tabuleiro[2][i]);
		if(vencedor != 0) {
			this->vencedorRound = vencedor;
			return true;
		}

		// Caso de vitória em uma coluna
		vencedor = vencedorDaLinha(tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
		if (vencedor != 0) {
			this->vencedorRound = vencedor;
			return true;
		}
	}

	// Caso de vitória em diagonal
	vencedor = vencedorDaLinha(tabuleiro[0][0], tabuleiro[1][1], tabuleiro[2][2]);
	if (vencedor != 0) {
		this->vencedorRound = vencedor;
		return true;
	}

	// Caso de vitória em diagonal inversa
	vencedor = vencedorDaLinha(tabuleiro[0][2], tabuleiro[1][1], tabuleiro[2][0]);
	if (vencedor != 0) {
		this->vencedorRound = vencedor;
		return true;
	}

	return false;
}

int Tabuleiro::vencedorDaLinha(int a, int b, int c) {
	if (a == 1 && b == 1 && c == 1) {
		return 1;
	}
	else if(a == 2 && b == 2 && c == 2){
		return 2;
	}

	return 0;
}

void Tabuleiro::premiar(Individuo& a, Individuo& b){
	if (vencedorRound == 1) {
		a.premiarVitoria();
		b.premiarDerrota();
	}
	else if(vencedorRound == 2) {
		a.premiarDerrota();
		b.premiarVitoria();
	}
	else if(vencedorRound ==0){
		a.premiarEmpate();
		b.premiarEmpate();
	}
	else {
		a.contarJogada();
		b.contarJogada();
	}
}