#include <stdio.h>

/**
* Stein's Algorithm .
* @author Andrei Ciobanu
* @date DEC 12, 2010
*/

int b_gcd(int num1, int num2)
{
	int pof2, tmp;
	if (!num1 || !num2) {
		return (num1 | num2);
	}

	// pof2 is the greatest power of 2 deviding both numbers .
	// We will use pof2 to multiply the returning number .
	pof2 = 0;
	while(!(num1 & 1) && !(num2 & 1)) {
		// gcd(even1, even1) = pof2 * gcd(even1/pof2, even2/pof2)
		num1 >>=1;
		num2 >>=1;
		pof2++;
	}

	do {
		while (!(num1 & 1)) {
			num1 >>=1;
		}
		while (!(num2 & 1)) {
			num2 >>=1;
		}
		// At this point we know for sure that
		// num1 and num2 are odd
		if (num1 >= num2) {
			num1 = (num1 - num2) >> 1;
		}
		else {
			tmp = num1;
			num1 = (num2 - num1) >> 1;
			num2 = tmp;
		}
	} while (!(num1 == num2 || num1 == 0));

	return (num2 << pof2);
}

int main(int argc, char *argv[])
{
	printf("%d", b_gcd(9 * 16, 3 * 32));
	return (0);
}
