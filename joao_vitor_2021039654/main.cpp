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

    // multiplicar todos os elemntos do vetor por -1
    for (int i = 0; i < minha_loja.rolos.size(); i++)
    {
      minha_loja.rolos[i] = minha_loja.rolos[i] * -1;
    }

    int resp = minha_loja.lds();
    cout << resp << endl;

    minha_loja.rolos.clear();
  }

  return (0);
}
