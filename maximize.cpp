
/*Given two positive integers A and B. Let’s define D such that B AND D = D. The task is to maximize the expression A XOR D.
Examples: 
 

Input: A = 11 B = 4
Output: 15
Take D = 4 as (B AND D) = (4 AND 4) = 4.
Also, (A XOR D) = (11 XOR 4) = 15 which is the 
maximum according to the given condition.

Input: A = 9 and B = 13
Output: 13 */

#include <iostream>
using namespace std;

#define MAX 32

// Function to return the value of
// the maximized expression
int maximizeExpression(int a, int b)
{
	int result = a;

	// int can have 32 bits
	for (int bit = MAX - 1; bit >= 0; bit--) {

		// Consider the ith bit of D to be 1
		int bitOfD = 1 << bit;

		// Calculate the value of (B AND bitOfD)
		int x = b & bitOfD;

		// Check if bitOfD satisfies (B AND D = D)
		if (x == bitOfD) {

			// Check if bitOfD can maximize (A XOR D)
			int y = result & bitOfD;
			if (y == 0) {
				result = result ^ bitOfD;
			}
		}

		// Note that we do not need to consider ith bit of D
		// to be 0 because if above condition are not satisfied
		// then value of result will not change
		// which is similar to considering bitOfD = 0
		// as result XOR 0 = result
	}

	return result;
}

// Driver code
int main()
{
	int a = 11, b = 14;

	cout << maximizeExpression(a, b);

	return 0;
}
