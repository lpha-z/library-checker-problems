#include "../params.h"
#include "random.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

int main(int, char* argv[])
{
    long long seed = std::atoll(argv[1]);
    auto gen = Random(seed);
    const int n = N_MAX;
    std::cout << n << '\n';
    auto p = gen.perm<int>(n);
    for (int i = 0; i < n; ++i) {
        if (i)
            std::cout << " ";
        std::cout << p[i];
    }
    std::cout << '\n';
}
