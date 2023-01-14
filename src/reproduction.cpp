#include <vector>
#include "math.h"

/** Calculation of the allele frequences after random mating
@param: N the population size
        p the frequency of allele A
@return: a three dimensional vector containing three floats. They correspond to the genotypics frequencies. AA, Aa and aa in that order.
**/

// Rapport : justifier le choix des deux vecteurs / deux binomiales
std::vector<float> reproduction(int N, float p) {
    // Generating of genotypes for the next generation
    // for each genotypes we get two allele.
    // - Possible genotypes:
    // -- {true, true} = AA
    // -- {true, false} = Aa
    // -- {false, true} = Aa
    // -- {false, false} = aa
    std::vector<std::vector<bool>> genotypes = {binomial(N, p), binomial(N, p)};
    
    // Calculating the frequencies of each genotype
    // - First we sum each genotype
    std::vector<float> freq_geno = {0, 0, 0};
    for (int i = 0; i < N; i++)
        freq_geno[int(!genotypes[0][i]) + int(!genotypes[1][i])]++;

    // - Then we determine the frequency by dividing each sum by the population size
    for (int i = 0; i < freq_geno.size(); i++)
        freq_geno[i] /= N;
    
    return freq_geno;
}