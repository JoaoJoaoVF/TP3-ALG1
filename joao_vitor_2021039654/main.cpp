#include "./loja.hpp"
#include "./msgassert.hpp"
using namespace std;

int main()
/*
    O algoritmo realiza 8 passos:
    1. Leitura da quantidade de casos de teste
    2. Leitura da quantidade de rolos
    3. Leitura do valor do i-ésimo rolo
    4. Insere o valor do i-ésimo rolo no vetor de rolos
    5. Chama a função LongestDecreasingSubsequence
    7. Imprime o resultado
    8. Limpa o vetor de rolos
*/
{
  Loja FP_Tecidinhos;
  /*
    N-> Quantidade de casos de teste
    R-> Quantidade de rolos
    P-> Valor do i-´esimo rolo
  */
  int N, R, P;

  cin >> N;

  erroAssert(N >= 1, "É necessário pelo menos um caso de teste");
  erroAssert(N <= 10, "O número de casos de teste não pode ser maior que 10");

  for (int i = 0; i < N; i++)
  {

    cin >> R;
    erroAssert(R >= 1, "É necessário pelo menos um rolo");
    erroAssert(R <= 20000, "A quantidade de rolos não pode ser maior que 20000");

    for (int j = 0; j < R; j++)
    {
      cin >> P;

      erroAssert(P >= 1, "O valor do rolo não pode ser menor que 1");
      erroAssert(P <= 1000000, "O valor do rolo não pode ser maior que 1000000");

      FP_Tecidinhos.set_Rolos(P);
    }

    int resposta = FP_Tecidinhos.LongestDecreasingSubsequence();

    cout << resposta << endl;

    FP_Tecidinhos.rolos.clear();
  }

  return (0);
}
