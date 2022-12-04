#include "loja.hpp"

Loja::Loja()
{
}

void Loja::set_Rolos(int P)
{
    rolos.push_back(P);
}

void Loja::print_Rolos()
{
    for (long unsigned int i = 0; i < rolos.size(); i++)
    {
        std::cout << rolos[i] << " ";
    }
}

void Loja::print_N(int N)
{
    cout << "N: " << N << endl;
}

void Loja::print_P(int P)
{
    std::cout << "P: " << P << std::endl;
}

void Loja::print_R(int R)
{
    std::cout << "R: " << R << std::endl;
}
