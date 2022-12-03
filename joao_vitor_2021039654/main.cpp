// #include "./loja.hpp"
// #include "./msgassert.hpp"
// using namespace std;

// int main()
// {
//   Loja *minha_loja;
//   /*
//     n-> Quantidade de casos de teste
//     r-> Quantidade de rolos
//     p-> Valor do i-´esimo rolo
//   */
//   int n, r, p;

//   /*Leitura da quantiade de casos de teste*/
//   cin >> n;

//   minha_loja->Set_N(n);

//   erroAssert(minha_loja->Get_N() >= 1, "É necessário pelo menos um caso de teste");
//   erroAssert(minha_loja->Get_N() <= 10, "O número de casos de teste não pode ser maior que 10");

//   for (int i = 0; i < minha_loja->Get_P(); i++)
//   {
//     /*
//     cin >> R;
//     vector<int> rolos;
//     for (int j = 0; j < R; j++)
//     {
//       cin >> P;
//       rolos.push_back(P);
//     }
//     sort(rolos.begin(), rolos.end());
//     int soma = 0;
//     for (int j = 0; j < R; j++)
//     {
//       soma += rolos[j];
//     }
//     int media = soma / R;
//     int menor = 0;
//     for (int j = 0; j < R; j++)
//     {
//       if (rolos[j] < media)
//       {
//         menor += media - rolos[j];
//       }
//     }
//     cout << menor << endl;
//     */

//     /*Leitura do numero de rolos*/
//     cin >> r;

//     minha_loja->Set_R(r);

//     erroAssert(minha_loja->Get_R() >= 1, "É necessário pelo menos um rolo");
//     erroAssert(minha_loja->Get_R() <= 20000, "A quantidade de rolos não pode ser maior que 20000");

//     for (int j = 0; j < minha_loja->Get_N(); j++)
//     {
//       cin >> p;
//       minha_loja->Set_P(p);
//     }
//   }

//   return (0);
// }

// Path: main.cpp
// Compare this snippet from main.cpp:
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
#include "loja.hpp"
using namespace std;

int main()
{
  int N, R, P;
  cin >> N;
  Loja loja;
  loja.Set_N(N);

  for (int i = 0; i < N; i++)
  {
    cin >> R;
    loja.Set_R(R);

    for (int j = 0; j < R; j++)
    {
      cin >> P;
      loja.Set_P(P);
      loja.set_Rolos(P);
      loja.set_Soma(P);
    }

    loja.set_Media();
    loja.set_Menor();

    // int soma = loja.get_Soma();
    int media = loja.get_Media();
    int menor = loja.get_Menor();

    vector<int> rolos = loja.getRolos();

    int somaFinal = 0;

    for (long unsigned int k = 0; k < rolos.size(); k++)
    {
      if (rolos[k] > media)
      {
        somaFinal += (rolos[k] - media);
      }
      else if (rolos[k] < menor)
      {
        somaFinal += (menor - rolos[k]);
      }
    }

    cout << somaFinal << endl;
  }

  return 0;
}