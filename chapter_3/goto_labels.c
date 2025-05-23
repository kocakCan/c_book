/***
 * - C provides the infinitely-abusable goto statement, and labels to branch
 *   to. Formally, the goto statement is never necessary, and in practice it is
 *   almost always easy to write code without it.
 *
 * - Nevertheless, there are few situations where gotos may find a place. The
 *   most common is to abondon processing in some deeply nested structure, such
 *   as breaking out of two or more loops at once. The break statement cannot
 *   be used directly since it only exits from the innermost loop. Thus:
 *
 *   for (...)
 *   	for (...) {
 *   		...
 *   		if (disaster)
 *   			goto error;
 *   	}	
 *   ...
 *
 *   error:
 *   	// clean up the mess
 *
 * - This organization is handy if the error-handling code is non-trivial, and
 *   if errors can occur in several places.
 *
 * - A label has the same form as a variable name, and is followed by a colon.
 *   It can be attached to any statement in the same function as the goto. The
 *   scope of a label is the entire function.
 *
 * - As another example, consider the problem of determining whether two arrays
 *   a and b have an element in common. One possibility is
 *
 *   	for (i = 0; i < n; i++)
 *   		for (j = 0; j < m; j++)
 *   			if (a[i] == b[j])
 *   				goto found;
 *   	// didn't find any common element
 *
 *   	found:
 *   		// got one: a[i] == b[j]
 *   	...
 *
 * - Code involving a goto can always be written without one, though perhaps at
 *   the price of some repeated tests or an extra variable. For example, the
 *   array search becomes
 *
 *   found = 0;
 *   for (i = 0; i < n && !found; i++)
 *   	for (j = 0; j < m && !found; j++)
 *   		if (a[i] == b[j])
 *   			found = 1;
 *
 *   if (found)
 *   	// got one: a[i] == b[j]
 *   	...
 *
 *   else
 *   	// didn't find any common element
 *	...
 *
 * - With a few exceptions like those cited here, code that relies on goto
 *   statements is generally harder to understand and to maintain than code
 *   without gotos.
 */
