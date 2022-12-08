#include "loja.hpp"

Loja::Loja()
{
}

void Loja::set_Rolos(int P)
{
    // 1) coloca-lo na prateleira pelo lado direito e empurra-lo ate encostar nos rolos ja existentes
    // 2) coloca-lo na prateleira pelo lado esquerdo e empurr´a-lo at´e encostar nos rolos j´a existentes,
    // 3) simplesmente n˜ao coloc´a-lo na prateleira.

    // isere o rolo no inicio do vetor se o valor dele é maior que o priemir
    //  caso nao seja
    // se ele for menor que o ultimo valor do vetor insere no final
    //  caso nao seja
    //  nao insere
    if (rolos.size() == 0)
    {
        rolos.push_back(P);
    }
    else if (P > rolos[0])
    {
        rolos.insert(rolos.begin(), P);
    }
    else // if (P < rolos[rolos.size() - 1])
    {
        rolos.push_back(P);
    }

    // if (rolos.size() == 0)
    // {
    //     rolos.push_back(P);
    // }
    // else
    // {
    int size = rolos.size() - 1;
    if (P > rolos[0])
    {
        // printf("p: %d, v[size]: %d, i: %d\n", p, v[size], i);
        rolos.insert(rolos.begin(), 1, P);
    }
    else if (P < rolos[size] && P < rolos[0])
        rolos.push_back(P);
    else
    {
        int diff_sup = abs(P - rolos[0]);
        int diff_inf = abs(P - rolos[size]);
        if (diff_sup < rolos[size])
            rolos.insert(rolos.begin(), 1, P);
        else
            rolos.push_back(P);
    }
    // }
}

void Loja::print_Rolos()
{
    for (long unsigned int i = 0; i < rolos.size(); i++)
    {
        std::cout << rolos[i] << " ";
    }
}

void Loja::print_N(int N)
{
    cout << "N: " << N << endl;
}

void Loja::print_P(int P)
{
    std::cout << "P: " << P << std::endl;
}

void Loja::print_R(int R)
{
    std::cout << "R: " << R << std::endl;
}

void Loja::lis()
{
    int n = rolos.size();
    int lis[n];

    lis[0] = 1;

    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (rolos[i] > rolos[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int maior = lis[0];
    for (int i = 1; i < n; i++)
    {
        if (maior < lis[i])
        {
            maior = lis[i];
        }
    }

    cout << maior;
}

// longest decreasing subsequence adding in the beginning of the vector
void Loja::lds()
{
    int n = rolos.size();
    int lds[n];

    lds[0] = 1;

    // interate over the vector and find the longest decreasing subsequence
    for (int i = 1; i < n; i++)
    {
        // initialize the lds with 1
        lds[i] = 1;

        // iterate over the vector again
        for (int j = 0; j < i; j++)
        {
            // if the current value is greater than the previous value
            if (rolos[i] < rolos[j] && lds[i] < lds[j] + 1)
            {
                // add 1 to the lds
                lds[i] = lds[j] + 1;
                // cout << lds[i] << endl;
            }
            // cout << lds[i] << endl;
        }
    }
    // cout << endl;
    // find the maximum value of the lds
    int maior = lds[0];
    // iterate over the lds vector
    for (int i = 1; i < n; i++)
    {
        // if the current value is greater than the previous value
        if (maior < lds[i])
        {
            // set the current value as the maximum value
            maior = lds[i];
        }
    }

    cout << maior;
}
