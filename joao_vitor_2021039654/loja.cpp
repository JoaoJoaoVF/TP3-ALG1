#include "loja.hpp"

void test()
{

    std::cout << "Funciona!";
}

Loja::Loja()
{
    N = 0;
    R = 0;
    P = 0;
    soma = 0;
    media = 0;
    menor = 0;
}

void Loja::set_Rolos(int P)
{
    rolos.push_back(P);
}

void Loja::set_Soma(int P)
{
    soma += P;
}

void Loja::set_Media()
{
    media = soma / R;
}

void Loja::set_Menor()
{
    menor = *min_element(rolos.begin(), rolos.end());
}

// int Loja::get_Soma()
// {
//     return soma;
// }

// int Loja::get_Media()
// {
//     return media;
// }

// int Loja::get_Menor()
// {
//     return menor;
// }

vector<int> Loja::getRolos()
{
    return rolos;
}

void Loja::printRolos()
{
    for (long unsigned int i = 0; i < rolos.size(); i++)
    {
        std::cout << rolos[i] << " ";
    }
}
