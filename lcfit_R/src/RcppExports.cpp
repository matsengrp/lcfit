// This file was generated by Rcpp::compileAttributes
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// rcpp_bsm_scale_factor
double rcpp_bsm_scale_factor(const double t, const double l, const List model);
RcppExport SEXP lcfit_rcpp_bsm_scale_factor(SEXP tSEXP, SEXP lSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< const double >::type t(tSEXP);
    Rcpp::traits::input_parameter< const double >::type l(lSEXP);
    Rcpp::traits::input_parameter< const List >::type model(modelSEXP);
    __result = Rcpp::wrap(rcpp_bsm_scale_factor(t, l, model));
    return __result;
END_RCPP
}
// rcpp_bsm_rescale
NumericVector rcpp_bsm_rescale(const double bl, const double ll, List model);
RcppExport SEXP lcfit_rcpp_bsm_rescale(SEXP blSEXP, SEXP llSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< const double >::type bl(blSEXP);
    Rcpp::traits::input_parameter< const double >::type ll(llSEXP);
    Rcpp::traits::input_parameter< List >::type model(modelSEXP);
    __result = Rcpp::wrap(rcpp_bsm_rescale(bl, ll, model));
    return __result;
END_RCPP
}
// rcpp_fit_bsm
NumericVector rcpp_fit_bsm(NumericVector bl, NumericVector ll, NumericVector w, List model, int max_iter);
RcppExport SEXP lcfit_rcpp_fit_bsm(SEXP blSEXP, SEXP llSEXP, SEXP wSEXP, SEXP modelSEXP, SEXP max_iterSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< NumericVector >::type bl(blSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type ll(llSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type w(wSEXP);
    Rcpp::traits::input_parameter< List >::type model(modelSEXP);
    Rcpp::traits::input_parameter< int >::type max_iter(max_iterSEXP);
    __result = Rcpp::wrap(rcpp_fit_bsm(bl, ll, w, model, max_iter));
    return __result;
END_RCPP
}
// rcpp_fit_bsm_iter
NumericVector rcpp_fit_bsm_iter(Function fn, NumericVector bl, double tolerance, List model);
RcppExport SEXP lcfit_rcpp_fit_bsm_iter(SEXP fnSEXP, SEXP blSEXP, SEXP toleranceSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject __result;
    Rcpp::RNGScope __rngScope;
    Rcpp::traits::input_parameter< Function >::type fn(fnSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type bl(blSEXP);
    Rcpp::traits::input_parameter< double >::type tolerance(toleranceSEXP);
    Rcpp::traits::input_parameter< List >::type model(modelSEXP);
    __result = Rcpp::wrap(rcpp_fit_bsm_iter(fn, bl, tolerance, model));
    return __result;
END_RCPP
}
