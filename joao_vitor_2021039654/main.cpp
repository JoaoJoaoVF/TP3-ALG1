#include "./loja.hpp"
#include "./msgassert.hpp"
using namespace std;

int main()
{
  Loja minha_loja;
  /*
    N-> Quantidade de casos de teste
    R-> Quantidade de rolos
    P-> Valor do i-´esimo rolo
  */
  int N, R, P;

  /*Leitura da quantiade de casos de teste*/
  cin >> N;

  erroAssert(N >= 1, "É necessário pelo menos um caso de teste");
  erroAssert(N <= 10, "O número de casos de teste não pode ser maior que 10");

  for (int i = 0; i < N; i++)
  {

    /*Leitura do numero de rolos*/
    cin >> R;

    erroAssert(R >= 1, "É necessário pelo menos um rolo");
    erroAssert(R <= 20000, "A quantidade de rolos não pode ser maior que 20000");

    for (int j = 0; j < R; j++)
    {
      cin >> P;

      minha_loja.set_Rolos(P);
    }

    // minha_loja.print_Rolos();

    // multiplicar o todos os elementos do vetor por -1
    // para que o algoritmo de LIS funcione
    // for (int i = 0; i < R; i++)
    // {
    //   minha_loja.rolos[i] = minha_loja.rolos[i] * -1;
    // }

    // longest decreasing subsequence
    minha_loja.lds();
    // cout << " ";
    // for (int i = 0; i < R; i++)
    // {
    //   minha_loja.rolos[i] = minha_loja.rolos[i] * -1;
    // }
    // minha_loja.lis();

    cout << endl;

    minha_loja.rolos.clear();
  }

  return (0);
}
