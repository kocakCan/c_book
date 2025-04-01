/***
 *   while (expression)
 *     statement
 *
 * - In the while loop, the expression is evaluated. If it is non-zero,
 *   statement is executed and expression is re-evaluated. This cycle continues
 *   until expression becomes zero, at which point execution resumes after
 *   statement.
 *
 * - The for statement
 *
 *   for (expr1; expr2; expr3)
 *     statement
 *
 *   is equivalent to
 *
 *   expr1;
 *   while (expr2) {
 *     statement
 *     expr3;
 *   }
 *
 *   except for the behaviour of continue.
 *
 * - Grammatically, the three components of a for loop are expressions.
 * - Most commonly, expr1 and expr3 are assignments or function calls and expr2
 *   is a relational expression.
 * - Any of the three parts can be omitted, although the semicolons must remain.
 * - If expr1 or expr3 is omitted, it is simply dropped from the expansion.
 * - If the test, expr2, is not present, it is taken as permanently true, so
 *
 *   for (;;) {
 *     ...
 *   }
 *
 *   is an "infinite" loop, presumably to be broken by other means, such as
 *   break and return.
 *
 * - Whether to use while or for is largely a matter of personal preference. For
 *   example. in
 *
 *     while ((c = getchar()) == ' ' || c == '\n' || c == '\t')
 *       ; // skip white space characters
 *
 *   there is no initialization or re-initialization, so the while is most
 *   natural.
 *
 * - The for is preferable when there is a simple initialization and increment
 *   since it keeps the loop control statements close together and visible at
 *   the top of the loop. This is most obvious in
 *
 *     for (i = 0; i < n; i++)
 *
 *   which is the C idiom for processing the first n elements of an array.
 *
 * - Because the components of the for are arbitrary expressions, for loops are
 *   not restricted to arithmetic progressions. Nonetheless, it is a bad style
 *   to force unrelated computations into the initialization and increment of a
 *   for, which are better reserved for loop control operations.
 *
 * - As a larger example, here is another version of atoi for converting a
 *   string to its numeric equivalent.
 *
 * - The structure of the program reflects the form of the input
 *
 *   skip white space, if any
 *   get sign, if any
 *   get integer part and convert it
 *
 * - Each step does its part, and leaves thing in a clean state for the next.
 *   The whole process terminates on the first character that could not be part
 *   of a number.
 */
#include <ctype.h>
#include <stdio.h>

/* atoi: convert s to integer; version 2 */
int atoi_(char s[]) {
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++)	// skip white spaces
		;

	sign = (s[i] == '+') ? 1 : -1;	// get sign

	for (n = 0; isdigit(s[i]); i++)
		n = n * 10 + (s[i] - '0');

	return n * sign;
}

int main() {
	char s[] = "Can Kocak";

	printf("%d\n", atoi_(s));

	return 0;
}
