/***
 *   Chapter 4 - Functions and Program Structure
 *
 * - Functions break large computing tasks into smaller ones, and enable people
 *   to build on what others have done instead of starting over from scratch.
 *   Appropriate functions hide details of operation from parts of the program
 *   that don't need to know about them, thus clarifying the whole, and easing
 *   the pain of making changes.
 *
 * - C has been designed to make functions efficient and easy to be used; C
 *   programs generally consist of many small functions rather than a few big
 *   ones. A program may reside in one or more source files. Source files may
 *   be compiled seperately and loaded together, along with previously compiled
 *   functions from libraries.
 */

/***
 * 4.1 Basics of Functions
 *
 * - To begin with, let us design a program to print each line of its input
 *   that contains a particular "pattern" or string of characters (This is a
 *   special case of the UNIX program grep.) For example, searching for the
 *   pattern of letters "ould" in the set of lines
 *
 *	 Ah Love! could you and I with Fate conspire
 *	 To grasp this sorry Scheme of Things entire,
 *	 Would not we shatter it to bits -- and then
 *	 Re-mould it nearer to the Heart's Desire!
 *
 *   will produce the output
 *
 *   	Ah Love! could you and I with Fate conspire
 *   	Would not we shatter it to bits -- and then
 *   	Re-mould it nearer to the Heart's Desire!
 *
 *   The job falls neatly into three pieces:
 *
 *   while (there's another line)
 *   	if (the line contains the pattern)
 *   		print it
 *
 * - Although it's certainly possible to put the code for all of this in main,
 *   a better way is to use the structure to advantage by making each part a
 *   seperate function. Three small pieces are better to deal with than one big
 *   one, because irrelevant details can be buried in the functions, and the
 *   chance of unwanted interactions is minimized. And the pieces may even be
 *   useful in other programs.
 *
 * - "While there's another line", the getline() function, and "print it" is
 *   printf, which someone has already provided for us. This means we need only
 *   write a routine to decide whether the line contains an occurrence of the
 *   pattern.
 *
 * - We can solve that problem by writing a function strindex(s, t) that
 *   returns the position or index in the string s where the string t begins,
 *   or -1 if s does not contain t. Because C arrays begin at position zero,
 *   indexes will be zero or positive, and so a negative value like -1 is
 *   convenient for signaling failure. When we later need more sophisticated
 *   pattern matching, we only have to replace strindex; the rest of the code
 *   can remain the same. (The standard library provides a function strstr that
 *   is similar to strindex, except that it returns a pointer instead of an
 *   index.)
 *
 * - Given this much design, filling in the details of the program is
 *   straightforward. Here is the whole thing, so you can see how the pieces
 *   fit together. For now, the pattern to be searched for is a literal string.
 *   There is also slightly different version of getline; you might find it
 *   instructive to compare it to the previous one.
 */
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline_(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /*pattern to search for */

/* find all lines matching pattern */
int main() {
  char line[MAXLINE];
  int found = 0;

  while (getline_(line, MAXLINE) > 0) {
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }
    return found;
  }
}

// Here int lim is used intead of int max, which is the second parameter for
// getline_. It is completely legal as the parameter names are optional in a
// function prototype.

/* getline_: get line into s, return length */
int getline_(char s[], int lim) {
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;

  if (c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
  int i, j, k;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }

  return -1;
}

/***
 * - Each function definition has the form
 *
 *   return-type function-name(argument declarations)
 *   {
 *   	declarations and statements
 *   }
 *
 *   Various part may be absent, a minimal function is
 *   	dummy() { }
 *
 *   which does nothing and returns nothing. A do-nothing function like this is
 *   sometimes useful as a placeholder during program development. If the
 *   return type is omitted, int is assumed.
 *
 * - A program is just a set of definitions of variables and functions.
 *   Communication between the function is by arguments and values returned by
 *   the functions, and through external variables. The functions can occur in
 *   any order in the source file, and the source program can be split into
 *   multiple files, so long as no function is split.
 *
 * - The return statement is the mechanism for returning a value from the
 *   called function to its caller. Any expression can follow return:
 *
 *   	return expression;
 *
 *   The expression will be converted to the return type if necessary.
 *   Parantheses are often used around the expression, but they are optional.
 *
 * - The calling function is free to ignore the returned value. Furthermore,
 *   there need to be no expression after return; in that case, no value is
 *   returned to the caller. Control also returns to the caller with no value
 *   when execution "falls off the end" of the function by reaching the closing
 *   right brace. It is not illegal, but probably a sign of trouble, if a
 *   function returns a value from one place and no value from another. In any
 *   case, if a function fails to return a value, its "value" is certain to be
 *   garbage.
 *
 * - The pattern-searching program returns a status from main, the number of
 *   matches found. This value is available for use by the environment that
 *   called the program.
 */
