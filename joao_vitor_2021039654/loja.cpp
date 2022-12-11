#include "loja.hpp"

Loja::Loja()
{
}

void Loja::set_Rolos(int P)
/*
    O algoritmo realiza 3 passos:
    1. Verifica se o vetor de rolos está vazio
    2. Se estiver vazio, insere o valor P no vetor de rolos
    3. Se não estiver vazio, insere o valor P no vetor de rolos
    e insere o valor P no inicio do vetor de rolos
*/
{
    if (rolos.size() == 0)
    {
        rolos.push_back(P);
    }
    else
    {
        rolos.push_back(P);
        rolos.insert(rolos.begin(), 1, P);
    }
}

// Algortihm Longest Decreasing Subsequence
int Loja::LongestDecreasingSubsequence()
/*
    O algoritmos realiza 11 passos:

    Inicialmente define as variaveis:
    qtd_rolos-> Quantidade de rolos
    lds-> Vetor de tamanho qtd_rolos

    Para o primeiro loop:
    1. Itera sobre o vetor de rolos
    2. Inicializa o vetor lds com 1
    3. Itera sobre o vetor de rolos novamente
    4. Se o valor de rolos[i] for menor que rolos[j] e lds[i] for menor que o valor de lds[j] + 1
    5. Define o valor atual do vetor lds como o valor anterior do vetor lds + 1

    Para o segundo loop:
    1. define o maior valor como o primeiro valor do vetor lds
    2. Itera sobre o vetor lds
    3. Se o maior valor for menor que o valor atual do vetor
    4. Define o maior valor como o valor atual do vetor

    Por fim, retorna o maior valor
*/
{
    int qtd_rolos = rolos.size();
    int lds[qtd_rolos];

    lds[0] = 1;

    for (int i = 1; i < qtd_rolos; i++)
    {
        lds[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (rolos[i] < rolos[j] && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int maior_valor = lds[0];

    for (int i = 1; i < qtd_rolos; i++)
    {
        if (maior_valor < lds[i])
        {
            maior_valor = lds[i];
        }
    }

    return maior_valor;
}
