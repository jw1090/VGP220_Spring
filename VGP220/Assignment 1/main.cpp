#include <iostream>
#include <assert.h>

//Name: Joseph Walden
//StudentId: 2042506
//Grade: 92/100

int RecursiveMultiplication(int a, int b);
int NonRecursiveFibonacci(int n);
int PrintFibonacciLessThan15(int n);
int printRecursiveFactorialLessThan50(int n);
int DynamicProgrammingFunc(int n);

int main(int argc, char* argv[])
{
	//Tests:
	std::cout << RecursiveMultiplication(2, 5) << std::endl; // Expected result: 10

	std::cout << NonRecursiveFibonacci(8) << std::endl; //Expected result: 5

	PrintFibonacciLessThan15(14); //Expected result: 0 1 1 2 3 5 8 13

	std::cout << std::endl;// ->Adding an extra line

	printRecursiveFactorialLessThan50(49);//Expected result: 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1

	return 0;
}

//ERROR: -8. You don't have to assert that a and b are positive or non zero. 
//Multiplications by zero or by negative numbers they exist and should be considered.
//You also have to treat when b is negative.
//A good answer for this question is:
//int RecursiveMultiplication(int a, int b)
//{
//	if (b == 0) 
//	{
//		return 0;
//	}
//	if (b > 0) 
//	{
//		return a + RecursiveMultiplication(a, b - 1);
//	}
//	if (b < 0) 
//	{
//		return -RecursiveMultiplication(a, -b);
//	}
//}

int RecursiveMultiplication(int a, int b)
{
	//TODO: Write a recursive function to multiply two positive integers
	//without using the operator *
	//You can use addition(+), subtraction(-) and bitShifting(<< or >>), but you
	//should minimize the number of those operations.

	//assert(a >= 0 && b >= 0);

	if (a == 0 || b == 0) {
		return 0;
	}

	if (b > 1) {
		return a + RecursiveMultiplication(a, b - 1);
	}

	return a;
}

//COMMENT: PERFECT!
int NonRecursiveFibonacci(int n)
{
	//TODO: Convert the recursive fibonacci that we did in class
	//to a non recursive method, using a bottom-up approach.

	assert(n >= 0);

	if (n < 2)
	{
		return n;
	}

	int a = 0;
	int b = 1;
	int result = 0;

	for (int i = 1; i < n; i++)
	{
		result = a + b;

		if (i % 2) {
			a = result;
		}
		else {
			b = result;
		}
	}

	return result;
}

//COMMENT: GOOD!
int PrintFibonacciLessThan15(int n)
{
	//TODO: Create a method that will print all the fibonacci sequence
	//less than 15. The way that you should print is:
	//PrintFibonacciLessThan15(7) -> "0 1 1 2 3 5 8 13". You just need to print what is between "".
	//Don't forget that is less than 15, so use assert if the method is being used outside the
	//boundaries of the function.

	assert(n >= 0 && n < 15);

	int a = 0;
	int b = 1;
	std::cout << a;

	if (n > 0) {
		std::cout << " " << b;
	}

	if (n < 2)
	{
		return n;
	}

	int result = 0;

	for (int i = 1; i < n; i++)
	{
		result = a + b;

		std::cout << " " << result;

		if (i % 2) {
			a = result;
		}
		else {
			b = result;
		}
	}

	return result;
}
//COMMENT: GOOD!
int printRecursiveFactorialLessThan50(int n)
{
	//TODO: Create a method that will print recursive
	//the factorial multiplication format of a number that is less than 50.
	//ASSERT that this function will be used in a correct way.
	//As an example:
	//printRecursiveFactorialLessThan50(10) -> "10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1"
	//The function just prints what is between "".

	assert(n >= 0 && n < 50);

	if (n > 1) {
		std::cout << n << " * ";

		return n * printRecursiveFactorialLessThan50(n - 1);
	}

	std::cout << n;

	return 1;
}

//TODO: Show with dynamic programming, the results and calls for DynamicProgrammingFunc(10)
//Identify repeated calls. This question you can do in a piece of paper drawing the calls
//and results and saving an image on your git repo.
int DynamicProgrammingFunc(int n)
{
	if (n < 5)
	{
		return n - 2;
	}

	return DynamicProgrammingFunc(n - 3) - (DynamicProgrammingFunc(n - 1) * DynamicProgrammingFunc(n - 2));
}