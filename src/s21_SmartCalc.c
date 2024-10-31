#include "s21_SmartCalc.h"

int calculator(char *expression, char *value_of_x_str, double *output) {
  int error = 0;
  if (strlen(expression) < 256) {
    double x_value;
    if (strlen(value_of_x_str)) x_value = atof(value_of_x_str);
    if (strlen(expression) > 0) {
      char sortStr[NMAX] = {0};
      validation(expression, sortStr);
      char result[NMAX] = {0};
      infToPol(sortStr, result);
      *output = calculate(result, x_value);
    } else
      error = 1;
  } else
    error = 2;
  return error;
}

double calculate(char *str, double num_x) {
  double value = 0;
  res *result = initRes();
  if (result != NULL) {
    for (size_t i = 0; i < strlen(str); i++) {
      if (str[i] == 'x')
        pushRes(num_x, result);
      else if ((str[i] >= 48 && str[i] <= 57) || str[i] == 46) {
        while (str[i] != ' ') {
          char num[NMAX] = {0};
          int j = 0;
          while (str[i] != ' ') {
            num[j++] = str[i++];
          }
          pushRes(atof(num), result);
        }
      } else {
        mathExpression(str, i, result);
      }
    }
    value = popRes(result);
    cleanRes(result);
  }
  return value;
}

void mathExpression(char *str, int i, res *result) {
  if (str[i] == '+') pushRes(popRes(result) + popRes(result), result);
  if (str[i] == '-') {
    double value = popRes(result);
    pushRes(popRes(result) - value, result);
  }
  if (str[i] == '*') pushRes(popRes(result) * popRes(result), result);
  if (str[i] == '/') {
    double value = popRes(result);
    pushRes(popRes(result) / value, result);
  }
  if (str[i] == '^') {
    double value = popRes(result);
    pushRes(pow(popRes(result), value), result);
  }
  if (str[i] == 'c') pushRes(cos(popRes(result)), result);
  if (str[i] == 's') pushRes(sin(popRes(result)), result);
  if (str[i] == 't') pushRes(tan(popRes(result)), result);
  if (str[i] == 'o') pushRes(acos(popRes(result)), result);
  if (str[i] == 'i') pushRes(asin(popRes(result)), result);
  if (str[i] == 'a') pushRes(atan(popRes(result)), result);
  if (str[i] == 'q') pushRes(sqrt(popRes(result)), result);
  if (str[i] == 'l') pushRes(log(popRes(result)), result);
  if (str[i] == 'g') pushRes(log10(popRes(result)), result);
  if (str[i] == 'm') {
    double value = popRes(result);
    pushRes(fmodl(popRes(result), value), result);
  }
}

void validation(char *str, char *result) {
  int index = 0;
  for (size_t i = 0; i < strlen(str); i++) {
    if (str[i] == 'c' && str[i + 1] == 'o' && str[i + 2] == 's') {  // cos
      result[index++] = 'c';
      i += 2;
    } else if (str[i] == 's' && str[i + 1] == 'i' &&
               str[i + 2] == 'n') {  // sin
      result[index++] = 's';
      i += 2;
    } else if (str[i] == 't' && str[i + 1] == 'a' &&
               str[i + 2] == 'n') {  // tan
      result[index++] = 't';
      i += 2;
    } else if (str[i] == 'a' && str[i + 1] == 'c' && str[i + 2] == 'o' &&
               str[i + 3] == 's') {  // acos
      result[index++] = 'o';
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 's' && str[i + 2] == 'i' &&
               str[i + 3] == 'n') {  // asin
      result[index++] = 'i';
      i += 3;
    } else if (str[i] == 'a' && str[i + 1] == 't' && str[i + 2] == 'a' &&
               str[i + 3] == 'n') {  // atan
      result[index++] = 'a';
      i += 3;
    } else if (str[i] == 's' && str[i + 1] == 'q' && str[i + 2] == 'r' &&
               str[i + 3] == 't') {  // sqrt
      result[index++] = 'q';
      i += 3;
    } else if (str[i] == 'l' && str[i + 1] == 'n') {  // ln
      result[index++] = 'l';
      i += 1;
    } else if (str[i] == 'l' && str[i + 1] == 'o' &&
               str[i + 2] == 'g') {  // log
      result[index++] = 'g';
      i += 2;
    } else if (str[i] == 'm' && str[i + 1] == 'o' &&
               str[i + 2] == 'd') {  // mod
      result[index++] = 'm';
      i += 2;
    } else if (str[i] == '(' && str[i + 1] == '-') {
      result[index++] = '(';
      result[index++] = '0';
    } else if (str[i] == '.') {
      if (i == 0) {
        result[index++] = '0';
        result[index++] = '.';
      } else {
        if (!(str[i - 1] >= 48 && str[i - 1] <= 57)) {
          result[index++] = '0';
          result[index++] = '.';
        } else {
          result[index++] = '.';
        }
      }
    } else {
      result[index++] = str[i];
    }
  }
}

void infToPol(char *str, char *result) {
  stack *stackStr = init();
  int index = 0;
  if (stackStr != NULL) {
    for (size_t i = 0; i < strlen(str); i++) {
      if (priority(str[i]) == 0) {
        result[index++] = str[i];
        if (priority(str[i + 1]) != 0) result[index++] = ' ';
      } else if (1 < priority(str[i]) && priority(str[i]) <= 4) {
        if (priority(find(stackStr)) < priority(str[i]))
          push(str[i], stackStr);
        else if (priority(find(stackStr)) >= priority(str[i])) {
          while (priority(find(stackStr)) >= priority(str[i])) {
            result[index++] = pop(stackStr);
          }
          push(str[i], stackStr);
        }
      } else if (str[i] == 'x') {
        result[index++] = 'x';
      } else if (str[i] == '(') {
        push(str[i], stackStr);
      } else if (str[i] == ')') {
        while (find(stackStr) != '(') {
          result[index++] = pop(stackStr);
        }
        pop(stackStr);
      }
    }
    while (stackStr->top != 0) {
      result[index++] = pop(stackStr);
    }
    clean(stackStr);
  }
}

int priority(char a) {
  int res = 1;
  if ((a >= 48 && a <= 57) || a == 46) res = 0;
  if (a == '(' || a == ')') res = 1;
  if (a == '+' || a == '-') res = 2;
  if (a == '*' || a == '/' || a == 'm') res = 3;
  if (a == 'c' || a == 's' || a == 't' || a == 'g' || a == 'q' || a == 'l' ||
      a == '^' || a == 'a' || a == 'o' || a == 'n')
    res = 4;
  return res;
}

stack *init() {
  stack *tack = malloc(sizeof(stack));
  if (tack != NULL) {
    tack->arr = malloc(NMAX * sizeof(char));
    tack->top = 0;
  }
  return tack;
}

void clean(stack *tack) {
  if (tack != NULL) {
    if (tack->arr != NULL) {
      free(tack->arr);
      tack->top = 0;
    }
    free(tack);
  }
}

void push(char c, stack *tack) {
  tack->arr[tack->top] = c;
  tack->top++;
}

char pop(stack *tack) {
  char value = '0';
  if (tack->top != 0) {
    value = tack->arr[tack->top - 1];
    tack->top--;
  }
  return value;
}

char find(stack *tack) {
  char oper = '0';
  if (tack->top != 0) oper = tack->arr[tack->top - 1];
  return oper;
}

res *initRes() {
  res *tack = malloc(sizeof(res));
  if (tack != NULL) {
    tack->arr = malloc(NMAX * sizeof(double));
    tack->top = 0;
  }
  return tack;
}

void cleanRes(res *tack) {
  if (tack != NULL) {
    if (tack->arr != NULL) {
      free(tack->arr);
      tack->top = 0;
    }
    free(tack);
  }
}

void pushRes(double c, res *tack) {
  tack->arr[tack->top] = c;
  tack->top++;
}

double popRes(res *tack) {
  double value = 0.0;
  if (tack->top != 0) {
    value = tack->arr[tack->top - 1];
    tack->top--;
  }
  return value;
}