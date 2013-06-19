/**
 * \file lcfit_select.h
 * \brief Point selection
 */
#ifndef LCFIT_SELECT_H
#define LCFIT_SELECT_H
#include <stdlib.h>
#include <stdbool.h>

#include "lcfit.h"

#ifdef __cplusplus
extern "C" {
#endif

/** \brief A branch length, log-likelihood pair */
typedef struct
{
    /** \brief Branch length */
    double t;
    /** \brief Log-likelihood */
    double ll;
} point_t;

/** \brief Log-likelihood function */
typedef struct
{
    /** \brief Log likelihood for a given branch-length */
    double (*fn)(double, void*);
    /** \brief Additional arguments to pass to \c fn */
    void *args;

} log_like_function_t;

typedef enum {
  /* Monotonicity unknown */
  CRV_UNKNOWN = 0,
  /* Monotonically increasing */
  CRV_MONO_INC = 1,
  /* Monotonically decreasing */
  CRV_MONO_DEC = 2,
  /* Encloses a minimum */
  CRV_ENC_MINIMA = 3,
  /* Encloses a maximum */
  CRV_ENC_MAXIMA = 4
} curve_type_t;

/** Classify a set of points, *already sorted by increasing x* */
curve_type_t
classify_curve(const point_t[], const size_t);

/**
 * \brief Select points to use in fitting the BSM
 *
 * \param log_like Log-likelihood function
 * \param starting_pts Initial branch lengths to use - *ordered*
 * \param num_pts **IN/OUT** Number of points in \c starting_points. The number of points
 * returned is stored here.
 * \param max_pts Maximum number of points to add
 * \return Points enclosing a maximum, or \c NULL if enclosing the maximum failed.
 */
point_t*
select_points(log_like_function_t *log_like, const point_t starting_pts[],
              /* IN/OUT */size_t *num_pts, size_t max_pts);

/** \brief Sort by increasing x-value */
void
sort_by_x(point_t points[], const size_t n);

/** \brief Sort by decreasing log-likelihood */
void
sort_by_like(point_t points[], const size_t n);

/**
 * \brief Estimate ML branch length using lcfit
 *
 * \param log_like Log-likelihood function
 * \param t **IN/OUT** Points at which to evaluate ll. The final top \c n_pts
 *          used in fitting are stored here.
 * \param n_pts length of \c ts
 * \param tolerance Fit tolerance
 * \param model Initial model for fitting
 */
double
estimate_ml_t(log_like_function_t *log_like, double t[],
              const size_t n_pts, const double tolerance, bsm_t* model,
              bool* success);

/**
 * \brief Choose the top \c k points by log-likelihood while maintaining monotonicity.
 *
 * Choose the point with maximum log-likelihood, as well as the point on either side.
 * Then choose the \f$k - 3\f$ additional points with maximum log-likelihood.
 *
 * Exposed for testing.
 *
 * \param p Points, ordered by t
 * \param n Number of points in #p
 * \param k Number of points to retain.
 */
void
subset_points(point_t p[], const size_t n, const size_t k);

#ifdef LCFIT_DEBUG
void
lcfit_select_initialize(void);
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif
