#include <iostream>
#include "AlgoritmoGenetico.h"

int main()
{
    int genes = 50;
    int numIndividuos = 100;
    float removerPercent = 50;
    float mutacaoPercent = 20;
    float pontuacaoPercent = 0.7;
    
    AlgoritmoGenetico ag = AlgoritmoGenetico(genes, numIndividuos, removerPercent, mutacaoPercent, pontuacaoPercent);

    ag.selecao();
}