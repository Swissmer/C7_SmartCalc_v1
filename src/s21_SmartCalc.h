#ifndef SRC_S21_SMART_CALC_1_0_H_
#define SRC_S21_SMART_CALC_1_0_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 256

typedef struct {
  char *arr;
  int top;
} stack;

typedef struct {
  double *arr;
  int top;
} res;

int calculator(char *expression, char *value_of_x_str, double *output);
void validation(char *str, char *result);
void infToPol(char *str, char *result);
int priority(char a);
double calculate(char *str, double num_x);
void mathExpression(char *str, int i, res *result);

stack *init();
void clean(stack *tack);
void push(char c, stack *tack);
char find(stack *tack);
char pop(stack *tack);

res *initRes();
void cleanRes(res *tack);
void pushRes(double c, res *tack);
double popRes(res *tack);

#endif  //  SRC_S21_SMART_CALC_1_0_H_