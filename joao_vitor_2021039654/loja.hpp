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

class Loja
{
public:
    int N, R, P;
    vector<int> rolos;

    Loja(); // Construtor da classe

    void set_Rolos(int P);              // Insere os rolos no vector de rolos
    int LongestDecreasingSubsequence(); // Algoritimo Longest Decreasing Subsequence
};
