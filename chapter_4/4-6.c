/* Add commands for handling variables. (It's easy to provide twenty-six
 * variables with single-latter names.) Add a variable for the most recently
 * printed value. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define VARSET '_'
#define VARGET 'a'
#define VARNUM 26
char var = '0';

enum boolean { FALSE, TRUE };

int getop(char[]);
int isempty(void);
void push(double);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);

int main() {
  int type;
  double op2;
  char s[MAXOP];

  int varindex = 0;
  double var_buff[VARNUM];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      double op1 = pop();
      if ((int)op2 != 0)
        push((int)op1 % (int)op2);
      else
        printf("error: zero divisor for modulus\n");
      break;
    case '\n':
      if (!isempty())
        printf("\t%.8g\n", pop());
      break;
    case 'p':
      peek();
      break;
    case 'd':
      duplicate();
      break;
    case 's':
      swap();
      break;
    case 'c':
      clear();
      break;
    case VARSET:
      var_buff[varindex++] = pop();
      printf("variable %c: %.3f\n", 'a' + varindex - 1, var_buff[varindex - 1]);
      break;
    case VARGET:
      // Check if the variable has been assigned previously
      if (var - 'a' <= (varindex - 1))
        push(var_buff[var - 'a']);
      else
        printf("error: undefined variable\n");
      break;
    case '$':
      push(sin(pop()));
      break;
    case '&':
      push(exp(pop()));
      break;
    case '^':
      op2 = pop();
      push(pow(pop(), op2));
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty from pop()\n");
    return 0.0;
  }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i = 0, c, next;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.' && c != '-')
    return c;
  if (c == '-') {
    next = getch();
    if (!isdigit(next) && next != '.') {
      ungetch(next); // not a negative number
      return c;      // return '-' operator
    }
    s[++i] = c = next;
  }
  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  if (c == '.') {
    while (isdigit(s[++i] = c = getch()))
      ;
  }
  s[i] = '\0';
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}

void peek(void) {
  if (sp) {
    printf("top of the stack: %g\n", val[--sp]);
  } else {
    printf("error: stack empty yo!\n");
  }
}

void duplicate(void) {
  double temp = pop();
  push(temp);
  push(temp);
}

void swap(void) {
  double temp1 = pop();
  double temp2 = pop();

  push(temp1);
  push(temp2);
}

void clear(void) {
  while (sp > 0)
    val[--sp] = 0.0;
}

int isempty(void) { return (sp > 0) ? FALSE : TRUE; }
