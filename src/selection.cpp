#include <vector>

/** Calculation of the allele frequences after selection
@param: freq_geno a three dimensional vector containing three floats. They correspond to the genotypics frequencies. AA, Aa and aa in that order.
        w a three dimensional vector containing three floats. They correspond to the selective values of each genotypes: AA, Aa and aa in that order.
@return: a two dimensional vector containing two floats. They correspond to the frequencies of allele A and a, in that order, after selection.
**/
std::vector<float> selection(std::vector<float> freq_geno, std::vector<float> w) {
    
    float wAvg = w[0] * freq_geno[0] + w[1] * freq_geno[1] + w[2] * freq_geno[2];
    std::vector<float> freq_all = {0, 0};

    freq_all[0] = (w[0] * freq_geno[0] + w[1] * freq_geno[1] * 0.5) / wAvg; 
    freq_all[1] = (0.5 * w[1] * freq_geno[1] + w[2] * freq_geno[2]) / wAvg;
    
    // Log error: cout<< 1 - freq_all[0] - freq_all[1] << endl;
    
    return freq_all;
}