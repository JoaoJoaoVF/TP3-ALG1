#include "loja.hpp"

Loja::Loja()
{
}

void Loja::set_Rolos(int P)
{
    // 1) coloca-lo na prateleira pelo lado direito e empurra-lo ate encostar nos rolos ja existentes
    // 2) coloca-lo na prateleira pelo lado esquerdo e empurr´a-lo at´e encostar nos rolos j´a existentes,
    // 3) simplesmente n˜ao coloc´a-lo na prateleira.

    if (rolos.size() == 0)
    {
        rolos.push_back(P);
    }
    else
    {
        vector<int> old_rolos = rolos;
        int lds_old = lds();

        vector<int> begin_rolos = rolos;
        begin_rolos.insert(begin_rolos.begin(), 1, P);
        int lds_begin = lds();

        vector<int> end_rolos = rolos;
        end_rolos.push_back(P);
        int lds_end = lds();

        if (lds_old > lds_begin && lds_old > lds_end)
        {
            rolos.push_back(P);
        }
        else if (lds_begin > lds_old && lds_begin > lds_end)
        {
            rolos.insert(rolos.begin(), 1, P);
        }
        else if (lds_end > lds_old && lds_end > lds_begin)
        {
            rolos.push_back(P);
        }
        else
        {
            rolos.push_back(P);
        }

        int diff_sup = abs(P - rolos[0]);
        int diff_inf = abs(P - rolos[rolos.size()]);

        if (diff_sup < rolos[rolos.size() - 1])
        {
            rolos.insert(rolos.begin(), 1, P);
        }
        else if (diff_inf < rolos[0])
        {
            rolos.push_back(P);
        }
    }
}

void Loja::print_Rolos()
{
    for (long unsigned int i = 0; i < rolos.size(); i++)
    {
        std::cout << rolos[i] << " ";
    }
    cout << endl;
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

    return maior;
}
