#include <iostream>
#include <vector>

using namespace std;

// Recursive function to calculate Fibonacci numbers
int fibonacciRecursive(int n) {
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

/*
Time Complexity: O(2^n)
The recursive method recalculates Fibonacci numbers multiple times due to overlapping subproblems.
This results in an exponential time complexity of O(2^n).

Space Complexity: O(n)
This complexity arises from the recursion stack. For each call to fibonacciRecursive,
a new stack frame is created until the base case is reached, giving a space complexity of O(n)
for the maximum depth of recursion.
*/

// Non-recursive (iterative) function to calculate Fibonacci numbers
int fibonacciIterative(int n) {
    if (n <= 1)
        return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

/*
Time Complexity: O(n)
The iterative approach uses a simple loop that runs from 2 to n,
resulting in a time complexity of O(n).

Space Complexity: O(1)
The space complexity is constant since only a few variables (a, b, and c) are used,
independent of the size of n.
*/

int main() {
    int n;
    cout << "Enter a number to calculate its Fibonacci: ";
    cin >> n;

    // Recursive method
    cout << "Fibonacci (Recursive) of " << n << " is: " << fibonacciRecursive(n) << endl;

    // Iterative method
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacciIterative(n) << endl;

    return 0;
}
