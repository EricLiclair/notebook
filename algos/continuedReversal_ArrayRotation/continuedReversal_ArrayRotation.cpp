#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        arr[start] = arr[start] ^ arr[end];
        arr[end] = arr[start] ^ arr[end];
        arr[start] = arr[start] ^ arr[end];
    }
}
void rotateLeft(int arr[], int n, int k)
{
    if (k == 0)
        return;
    k %= n;

    reverseArray(arr, 0, k - 1);
    reverseArray(arr, k, n - 1);
    reverseArray(arr, 0, n - 1);
}

int main()
{
    cout << "Continure Reversal Method - Algorithm for Array Rotation\n"
         << "Time Complexity - O(n)\n"
         << "Space Complexity - O(1)\n"
         << "Ref Link - https://www.geeksforgeeks.org/program-for-array-rotation-continued-reversal-algorithm/\n";
    return 0;
}
