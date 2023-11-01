#include <iostream>
#include "AlgoritmoGenetico.h"

int main()
{
    int genes = 30;
    int numIndividuos = 100;
    float removerPercent = 50;
    float mutacaoPercent = 20;
    
    AlgoritmoGenetico ag = AlgoritmoGenetico(genes, numIndividuos, removerPercent, mutacaoPercent);

    ag.selecao();
}