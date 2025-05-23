// The statements
//   if (a > b)
//     z = a;
//   else
//     z = b;
// compute in z the maximum of a and b. The conditional expression. written with
// the ternary operator "?:", provides an alternate way to write this and
// similar constructions. In the expression
//   expr1 ? expr2 : expr3
// the expression expr1 is evaluated first. If it is non-zero (true), then the
// expression expr2 is evaluated, and that is the value of the conditional
// expression. Otherwise expr3 is evaluated, and that is the value. Only one of
// expr2 and expr3 is evaluated.
//   z = (a > b) ? a : b;  /* z = max(a, b) */
// It should be noted that the conditional expression is indeed an expression,
// and that it can be used wherever any other expression can be. If expr2 and
// expr3 are of different types, the type of the result is determined by the
// conversion rules. For example, if f is a float and n an int, then the
// expression
//   (n > 0) ? f : n
// is of type float regardless of whether n is positive.
//
// Parantheses are not necessary around the first expression of a conditional
// expression, since the precedence of ?: is very low, just above assignment.
// They are advisable anyway, however, since they make the condition part of the
// expression easier to see.
#include <stdio.h>

int main() {
  int arr[100];
  const int n = 100;
  for (int i = 0; i < 100; ++i) {
    arr[i] = i;
  }

  // A newline is printed after every tenth element, and after the n-th. All
  // other elements are followed by one blank. This might look tricky, but it's
  // more compact than equivalent if-else.
  for (int i = 0; i < n; i++) {
    printf("%6d%c", arr[i], (i % 10 == 9 || i == n - 1) ? '\n' : ' ');
  }

  // Another good example is
  printf("You have %d item%s.\n", n, n == 1 ? "" : "s");

  return 0;
}
