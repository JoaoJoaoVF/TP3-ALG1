#include "loja.hpp"

Loja::Loja()
{
}

void Loja::set_Rolos(int P)
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

// longest decreasing subsequence adding in the beginning of the vector
int Loja::lds()
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
            }
        }
    }
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

    return maior;
}
