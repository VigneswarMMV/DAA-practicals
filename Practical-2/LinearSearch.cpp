#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 1000, 8900, 15, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 1000;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1;
            return 0;
        }
    }

    cout << "Element not found";

    return 0;
}  
