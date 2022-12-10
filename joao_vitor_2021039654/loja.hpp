#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;

// create a class loja
class Loja
{
public:
    int N, R, P;
    vector<int> rolos;

    Loja();

    void set_Rolos(int P); // Insere os rolos no vector de rolos
    int lds();             // Longest Decreasing Subsequence
};
