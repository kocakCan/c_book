/***
 * 4.10 Recursion
 *
 * C functions may be used recursively; that is, a function may call itself
 * either directly or indirectly. Consider printing a number as a character
 * string. The digits are generated in the wrong order: low-order digits are
 * available before high-order digits, but they have to be printed the other
 * way around.
 *
 * There are two solutions to this problem. One is to store the digits in an
 * array as they are generated, then print them in the reverse order. The
 * alternative is a recursive solution, in which printd calls itself to cope
 * with any leading digits, then prints the trailing digit. Again, this version
 * can fail on the largest negative number.
 */
#include <stdio.h>

/* printd: print n in decimal */
void printd(int n) {
	if (n < 0) {
		putchar('-');
		n = -n;
	}
	if (n / 10) 
		printd(n / 10);
	putchar(n % 10 + '0');
}

/***
 * When a function calls itself recursively, each invocation gets a fresh set
 * of all the automatic variables, independent of the previous set. This in
 * printd(123) the first printd receives the argument n = 123. It passes 12 to
 * a second printd, which in turn passes 1 to a third. The third-level printd
 * prints 1, then returns to second level. That printd prints 2, then returns
 * to the first level. That one prints 3 and terminates.
 *
 * Another good example of recursion is quicksort, a sorting algorithm
 * developed by C.A.R Hoare in 1962. Given an array, one element is chosen and
 * the others are partitioned in two subsets - those less than the partition
 * element and those greater than or equal to it. The same process is then
 * applied recursively to the two subnets. When a subset has fewer than two
 * elements, it doesn't need any sorting; this stops the recursion.
 */

// Here's an example of this quicksort using middle element of each subarray for partitioning

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right)			/* do nothing if array contains */
		return;				/* fewer than two elements */
	swap(v, left, (left + right) / 2);	/* move partition elem */
	last = left;
						/* to v[0] */
	for (i = left + 1; i <= right; i++)	/* partition */
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);			/* restore partition elem */
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}

/***
 * Swapping operation was moved to a seperate function swap because it occurs
 * three times in qsort.
 */

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
	int temp;

	temp = v[i], v[i] = v[j], v[j] = temp;
}

/***
 * Recursion may provide no saving in storage, since somewhere a stack of
 * the values being processed must be maintained. Nor will it be faster. But
 * recursive code is more compact, and often much easier to write and
 * understand than the non-recursive equivalent. Recursion is especially
 * convenient for recursively defined data structures like trees.
 */

int main(void) {
	int nums[] = {1, -5, 3, 11, -32, 40, 21};

	qsort(nums, 2, 5);

	for (int i = 0; i < 7; i++)
		printf("%d\n", nums[i]);

	return 0;
}
