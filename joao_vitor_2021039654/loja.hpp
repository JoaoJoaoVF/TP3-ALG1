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

void test();

// create a class loja
class Loja
{
public:
    int N, R, P;
    vector<int> rolos;
    int soma;
    int media;
    int menor;

    Loja();

    void set_Rolos(int P); // Insere os rolos no vector de rolos

    void print_Rolos(); // Imprime os rolos

    int lds(); // Longest Decreasing Subsequence
};
