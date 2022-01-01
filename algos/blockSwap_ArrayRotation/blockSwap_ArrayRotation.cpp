#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

void swapArr(int Arr[], int start, int end, int k)
{
    for (int i = 0; i < k; i++)
    {
        int temp = Arr[start + i];
        Arr[start + i] = Arr[end + i];
        Arr[end + i] = temp;
    }
}

void blockSwap(int Arr[], int n, int k)
{
    k %= n;
    if (k == n || k == 0)
        return;

    if (k == n - k)
    // n(X) = n(Y)
    {
        swapArr(Arr, 0, n - k, k);
        return;
    }

    if (k < n - k)
    // n(X) < n(Y)
    {
        swapArr(Arr, 0, n - k, k);
        blockSwap(Arr, n - k, k);
    }
    else
    {
        // k > n - k
        // n(X) > n(Y)
        swapArr(Arr, 0, k, n - k);
        blockSwap(Arr + n - k, k, 2 * k - n);
    }
}

int main()
{
    cout << "Block Swap Method - Algorithm for Array Rotation\n"
         << "Time Complexity - O(n)\n"
         << "Space Complexity - O(1)\n"
         << "Ref Link - https://www.geeksforgeeks.org/block-swap-algorithm-for-array-rotation/\n";
    return 0;
}
