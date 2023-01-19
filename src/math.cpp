#include <stdlib.h>
#include <vector>

/** We implement a bernoulli function.
@param: p is the probability of sucess
@return: true if sucess OR false if fail
**/    
bool bernoulli(float p) {
    if (p == 0) {return false;}
    // uniform generation of a float between 0 and 1
    float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    return random <= p;
}

/** implementation of binomial law
@param: N the number of identical Bernoulli experiments
        p the probability of sucess
@return: a N-dimension vector containing the results, true if sucess OR false if fail
**/
std::vector<bool> binomial(int N, float p) {
    std::vector<bool> results;
    for (int i = 0; i < N; i++) 
        results.push_back(bernoulli(p));
    return results;
}