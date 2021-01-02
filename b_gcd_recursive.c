/**
* Stein's Algorithm .
* @author Andrei Ciobanu
* @date DEC 12, 2010
*/

#include <stdio.h>

int b_gcd(int num1, int num2)
{
	if (num1 == num2) {
		return (num1);
	}
	if (!num1 && !num2) {
		/* Convention: GCD(0, 0) = 0 */
		return (0);
	}
	if (!num1 || !num2) {
		// GCD(0, num2) = num2
		// GCD(num1, 0) = num1
		return (num1 | num2);
	}
	if ( !(num1 & 1) && !(num2 & 1)) {
		// num1 and num2 are even,
		// then gcd(num1, num2) = 2 * gcd(num1/2, num2/2)
		return (b_gcd(num1 >> 1, num2 >> 1) << 1);
	}
	if ( !(num1 & 1) && (num2 & 1)) {
		// num1 is even, and num2 is odd
		// then gcd(num1, num2) = gcd(num1/2, num2)
		return b_gcd(num1 >> 1, num2);
	}
	if ( (num1 & 1) && !(num2 & 1)) {
		// num1 is odd, and num2 is even
		// then gcd(num1, num2) = gcd(num1, num2/2)
		return b_gcd(num1, num2 >> 1);
	}
	if ( (num1 & 1) && (num2 & 1)) {
		// num1 and num2 are odd
		if(num1 >= num2) {
			return b_gcd((num1 - num2) >> 1, num1);
		}
		else {
			return b_gcd((num2 - num1) >> 1, num1);
		}
	}
	return (0);
}

int main(int argc, char *argv[])
{
	printf("%dn", b_gcd(9 * 16, 3 * 32));
	return (0);
}
