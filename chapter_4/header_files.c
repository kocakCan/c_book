/***
 * 4.5 Header Files
 *
 * Let us now consider dividing the calculator program into several source
 * files, as it might be each of the components were substantially bigger. The
 * main function would go in one file, which we will call main.c; push, pop, and
 * their variables go into a second file, stack.c; getop goes into a third,
 * getop.c. Finally, getch and ungetch go into a fourth file, getch.c; we
 * seperate them from the others because they would come from a
 * seperately-compiled library in a realistic program.
 *
 * There is one more thing to worry about - the definitions and declarations
 * shared among files. As much as possible, we want to centralize this, so that
 * there is only one copy to get and keep right as the program evolves.
 * Accordingly, we will place this common material in a header file, calc.h,
 * which will be included as necessary.
 *
 * There is a tradeoff between the desire that each file have access only to
 * the information it needs for its job and the practical reality that it is
 * harder to maintain more header files. Up to some moderate program size, it
 * is probably best to have one header file that contains everything that is to
 * be shared between any two parts of the program; that is the decision we made
 * here. For a much larger program, more organization and more headers would be
 * needed.
 */
 */
