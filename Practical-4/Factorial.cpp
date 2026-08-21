#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

long long iterativeFactorial(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }

    return fact;
}

long long recursiveFactorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    return n * recursiveFactorial(n - 1);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    auto start1 = high_resolution_clock::now();
    long long iterativeResult = iterativeFactorial(n);
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    long long recursiveResult = recursiveFactorial(n);
    auto end2 = high_resolution_clock::now();

    auto iterativeTime =
        duration_cast<nanoseconds>(end1 - start1);

    auto recursiveTime =
        duration_cast<nanoseconds>(end2 - start2);

    cout << "\nIterative Factorial: " << iterativeResult << endl;
    cout << "Iterative Time: "
         << iterativeTime.count()
         << " nanoseconds" << endl;

    cout << "\nRecursive Factorial: " << recursiveResult << endl;
    cout << "Recursive Time: "
         << recursiveTime.count()
         << " nanoseconds" << endl;

    return 0;
}
