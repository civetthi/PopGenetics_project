#include <vector>
#include "math.h"

/** Calculation of the allele frequences after random mating
@param: p the frequency of allele A
@return: a three dimensional vector containing three floats. They correspond to the genotypics frequencies. AA, Aa and aa in that order.
**/

std::vector<float> deterministic_repro(float p){ 
    // Calculating the frequencies of each genotype for the next generation
    // for each genotypes we get two allele.
    // We used the Hardy Weinberg proportion
    std::vector<float> freq_geno = {0, 0, 0};
    freq_geno[0] = p*p;                   //Geno descendants AA avec freq de l'allele A chez le parent = p 
    freq_geno[1] = 2*p*(1-p);             //Geno descendants Aa 
    freq_geno[2] = (1-p)*(1-p);           //Geno descendants aa 
    
    return freq_geno;
}
