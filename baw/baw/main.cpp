#include "baw/interface.h"
#include <iostream>

//double option_price_american_call_approximated_baw(const double& S, const double& K,
//                                                   const double& r, const double& b,
//                                                   const double& sigma, const double& time);
//double option_price_american_put_approximated_baw(const double& S, const double& K,
//                                                  const double& r, const double& b,
//                                                  const double& sigma, const double& time);


int main() {
    std::cout << "Hello, World!" << std::endl;

    const double S = 100;
    const double X = 101;
    const double T = 0.5;
    const double b = -0.03;
    const double r = 0.03;
    const double sigma = 0.4;

    const double call = option_price_american_call_approximated_baw(S, X, r, b, sigma, T);
    const double put = option_price_american_put_approximated_baw(S, X, r, b, sigma, T);

    std::cout << "call: " << call << std::endl;
    std::cout << "put: " << put << std::endl;

    return 0;
}
