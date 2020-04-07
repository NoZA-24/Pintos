#ifndef THREADS_FIXED_POINT_H
#define THREADS_FIXED_POINT_H

#define f (1<<14)
#define INT_MAX ((1<<31)-1)
#define INT_MIN (-(1<<31))

/* Convert n to fixed point */
int int_to_fp(int n)
{
  return n*f;
}

/* Convert x to integer (rounding toward zero) */
int fp_to_int(int x)
{
  return x/f;
}

/* Convert x to integer (rounding to nearest) */
int fp_to_int_round(int x)
{
  return (x>=0)?(x+f/2)/f : (x-f/2)/f;
}

/* Add x and y */
int add_fp(int x, int y)
{
  return x+y;
}

/* Add x and n */
int add_mixed(int x, int n)
{
  return x+n*f;
}

/* Subtract y from x */
int sub_fp(int x, int y)
{
  return x-y;
}

/* Subtract n from x */
int sub_mixed(int x, int n)
{
  return x-n*f;
}

/* Multiply x by y */
int mult_fp(int x, int y)
{
  return ((int64_t)x)*y/f;
}

/* Multiply x by n */
int mult_mixed(int x, int n)
{
  return x*n;
}

/* Divide x by y */
int div_fp(int x, int y)
{
  return ((int64_t)x)*f/y;
}

/* Divide x by n */
int div_mixed(int x, int n)
{
  return x/n;
}

#endif /* threads/fixed_point.h */
