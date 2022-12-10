#include "loja.hpp"

Loja::Loja()
{
}

void Loja::set_Rolos(int P)
{
    // 1) coloca-lo na prateleira pelo lado direito e empurra-lo ate encostar nos rolos ja existentes
    // 2) coloca-lo na prateleira pelo lado esquerdo e empurr´a-lo at´e encostar nos rolos j´a existentes,
    // 3) simplesmente n˜ao coloc´a-lo na prateleira.

    // vector<int> old_rolos = rolos;
    if (rolos.size() == 0)
    {
        rolos.push_back(P);
        // cout << "P: " << P << endl;
        // print_Rolos();
    }
    // else if (P > rolos[0])
    // {
    //     rolos.insert(rolos.begin(), 1, P);
    //     // cout << "P: " << P << endl;
    //     // print_Rolos();
    // }
    // else if (P < rolos[rolos.size() - 1])
    // {
    //     rolos.push_back(P);
    //     // cout << "P: " << P << endl;
    //     // print_Rolos();
    // }
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
            // rolos.insert(rolos.begin(), 1, P);
            rolos.push_back(P);
            //     rolos = old_rolos;
        }
        else if (lds_begin > lds_old && lds_begin > lds_end)
        {
            // rolos = begin_rolos;

            rolos.insert(rolos.begin(), 1, P);
        }
        else if (lds_end > lds_old && lds_end > lds_begin)
        {
            // rolos = end_rolos;
            rolos.push_back(P);
        }
        else
        {
            // rolos = old_rolos;
            rolos.push_back(P);
        }

        int diff_sup = abs(P - rolos[0]);
        int diff_inf = abs(P - rolos[rolos.size()]);

        // cout << "diff_sup " << diff_sup << endl;
        // cout << "diff_inf " << diff_inf << endl;
        // cout << "P: " << P << endl;

        if (diff_sup < rolos[rolos.size() - 1])
        {
            // cout << "diff_sup " << diff_sup << endl;
            // cout << "rolos[rolos.size() - 1] " << rolos[rolos.size() - 1] << endl;
            rolos.insert(rolos.begin(), 1, P);
            // cout << "P: " << P << endl;
            // print_Rolos();
            // cout << "inicio" << endl;
        }
        else if (diff_inf < rolos[0])
        {
            // cout << "diff_inf " << diff_inf << endl;
            // cout << "rolos[0] " << rolos[0] << endl;
            rolos.push_back(P);
            // cout << "P: " << P << endl;
            // print_Rolos();
            // cout << "fim" << endl;
        }

        // // rolos.push_back(P);
        // // rolos.insert(rolos.begin(), 1, P);
        // cout << endl;
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
/*
int Loja::test(int n)
{
    int dp1[n], dp2[n];

    for (int i = 0; i < n; i++)
        dp1[i] = dp2[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (rolos[i] > rolos[j])
                dp1[i] = max(dp1[i], dp1[j] + 1);
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (rolos[i] > rolos[j])
                dp2[i] = max(dp2[i], dp2[j] + 1);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
        ans = max(ans, dp1[i] + dp2[i] - 1);

    // cout << endl;
    cout << ans;
    // cout << endl;
}
*/

int Loja::test2(int n)
{
    int i, j;

    /* Allocate memory for LIS[] and initialize LIS values as 1 for
        all indexes */
    int *lis = new int[n];
    for (i = 0; i < n; i++)
        lis[i] = 1;

    /* Compute LIS values from left to right */
    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if (rolos[i] > rolos[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    /* Allocate memory for lds and initialize LDS values for
        all indexes */
    int *lds = new int[n];
    for (i = 0; i < n; i++)
        lds[i] = 1;

    /* Compute LDS values from right to left */
    for (i = n - 2; i >= 0; i--)
        for (j = n - 1; j > i; j--)
            if (rolos[i] > rolos[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;

    /* Return the maximum value of lis[i] + lds[i] - 1*/
    int max = lis[0] + lds[0];
    for (i = 1; i < n; i++)
        if (lis[i] + lds[i] > max)
        {
            max = lis[i] + lds[i];
        }

    // print lds array
    // cout << "lds: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << lds[i] << " ";
    // }
    // cout << endl;
    // cout << "lis: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << lis[i] << " ";
    // }

    return max;
}

int Loja::test(int n)
{
    // Initialize dynamic programming arrays
    int front[n];
    int back[n];
    int x = 0, y = 0;

    // Set all elements of the arrays to 1
    for (int i = 0; i < n; i++)
    {
        front[i] = 1;
        back[i] = 1;
    }

    // Iterate over the rolos array from left to right
    for (int i = 1; i < n; i++)
    {
        // If the current element is smaller than the element at the front of the sequence,
        // append it to the front of the sequence by updating front[i]
        if (rolos[i] < rolos[front[i - 1] - 1])
        {
            front[i] = front[i - 1] + 1;
            x++;
        }

        // If the current element is greater than the element at the back of the sequence,
        // append it to the back of the sequence by updating back[i]
        if (rolos[i] > rolos[back[i - 1] + 1])
        {
            back[i] = back[i - 1] + 1;
            y++;
        }
    }

    // pritn front and back arrays
    // cout << "front: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << front[i] << " ";
    // }
    // cout << endl;
    // cout << "back: " << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << back[i] << " ";
    // }
    // cout << endl;

    // cout << "front: " << front[n - 1] << " back: " << back[n - 1] << endl;

    // Return the maximum of front[n-1] and back[n-1]
    return std::max(front[n - 1], back[n - 1]);
    // return std::max(x, y);
    // return std::max(x, y);
}