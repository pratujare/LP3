#include <iostream>
using namespace std;

// Recursive function to find nth Fibonacci number
int fibonacciRecursive(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Iterative function to print Fibonacci series
void fibonacciIterative(int n) {
    int a = 0, b = 1, next;
    cout << "Iterative Fibonacci Series: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        next = a + b;
        a = b;
        b = next;
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;

    cout << "Recursive Fibonacci Series: ";
    for (int i = 0; i < n; i++)
        cout << fibonacciRecursive(i) << " ";
    cout << endl;

    fibonacciIterative(n);

    return 0;
}
