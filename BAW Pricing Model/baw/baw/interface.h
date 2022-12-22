//
// Created by Gavin on 2022/12/22.
//

#ifndef BAW_INTERFACE_H
#define BAW_INTERFACE_H

double option_price_european_call_payout(const double &S, const double &K, const double &r,
                                         const double &b, const double &sigma, const double &time);
double option_price_european_put_payout(const double &S, const double &K, const double &r,
                                        const double &b, const double &sigma, const double &time);

double option_price_american_call_approximated_baw(const double &S, const double &K,
                                                   const double &r, const double &b,
                                                   const double &sigma, const double &time);
double option_price_american_put_approximated_baw(const double &S, const double &K,
                                                  const double &r, const double &b,
                                                  const double &sigma, const double &time);

#endif//BAW_INTERFACE_H
