/**
 * \file lcfit_select.h
 * \brief Point selection
 */
#ifndef LCFIT_SELECT_H
#define LCFIT_SELECT_H
#include <stdlib.h>

/** \brief A branch length, log-likelihood pair */
typedef struct
{
    /** \brief Branch length */
    double t;
    /** \brief Log-likelihood */
    double ll;
} point_t;

/** Log-likelihood function */
typedef double (*log_like_function_t)(double, void*);

typedef enum {
  /* Monotonicity unknown */
  MONO_UNKNOWN = 0,
  /* Monotonically increasing */
  MONO_INC,
  /* Monotonically decreasing */
  MONO_DEC,
  /* Non-monotonic (points enclose an extremum) */
  NON_MONOTONIC
} monotonicity_t;

/** Classify a set of points, *already sorted by increasing x* */
monotonicity_t
monotonicity(const point_t[], const size_t);

/** Choose points to enclose an extremum */
point_t*
select_points(log_like_function_t log_like, const double* starting_pts,
              /* IN/OUT */size_t *num_pts, size_t max_pts, void* args);

/** \brief Sort by increasing x-value */
void
sort_by_x(point_t points[], const size_t n);

/** \brief Sort by decreasing log-likelihood */
void
sort_by_like(point_t points[], const size_t n);

#endif
