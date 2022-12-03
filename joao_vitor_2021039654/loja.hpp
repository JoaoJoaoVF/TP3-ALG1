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
private:
    int N, R, P;
    vector<int> rolos;
    int soma;
    int media;
    int menor;

public:
    Loja();
    void Set_N(int N) { N = N; } // seta o numero de casos de teste
    void Set_R(int R) { R = R; } // seta o numero de rolos
    void Set_P(int R) { P = P; } // seta o valor do i-esimo rolo
    void set_Rolos(int P);       // Insere os rolos no vector de rolos
    void set_Soma(int P);        // Seta o valor da soma
    void set_Media();            // Seta o valor do rolo na posicao media
    void set_Menor();            // Seta o valor do menor rolo

    const int &Get_N() { return N; } // retorna o numero de casos de teste
    const int &Get_R() { return R; } // retorna o numero de rolos
    const int &Get_P() { return P; } // retorna o valor do i-esimo rolo

    const int &get_Soma() { return soma; }   // retorna o valor da soma
    const int &get_Media() { return media; } // retorna o valor da media
    const int &get_Menor() { return menor; } // retorna o valor do m vector<int> getRolos(); vector<int> getRolos();

    vector<int> getRolos();

    void printRolos();
};
