#include <iostream>
#include <vector>
#include "reproduction.h"
#include "selection.h"
#include "math.h"
using namespace std;

int main() {
    // Global variables

    // - Size of population 
    int N = 1000;

    // - Frequency of allele A
    float p = 0.22;

    // - Number of generations
    int T = 20;

    // - Selective values for genotypes: AA, Aa and aa
    float wAA = 0, wAa = 0.2, waa = 0.5;

    // ---


    // Test
    auto test1 = reproduction(100000, p);

    cout << test1[0] << endl;

    auto test2 = selection(test1, {wAA, wAa, waa});

    cout << test2[0] << endl;


    return 0;
}