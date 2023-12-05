#include <bits/stdc++.h>

#define L(x) ((x) * 2 + 1)
#define R(x) ((x) * 2 + 2)
#define PAR(x) (((x) - 1) / 2)

void down(std::vector<int>&, int, int);

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; --i) {
        down(arr, n, i);
    }

    for (int i = n - 1; i >= 0; --i) {
        std::swap(arr[0], arr[i]);
        down(arr, i, 0);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " \n"[i == n - 1];
    }

    return 0;
}

void down(std::vector<int>& arr, int n, int x) {
    while (L(x) < n) {
        int ci = L(x);   // child index, left child
        if (ci + 1 < n && arr[ci + 1] > arr[ci]) {    // select the minimum
            ++ci;
        }
        if (arr[ci] <= arr[x]) {
            break;
        }
        std::swap(arr[ci], arr[x]);
        x = ci;
    }
}
