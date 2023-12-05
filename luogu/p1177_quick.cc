// tags: 快速排序 快排
#include <bits/stdc++.h>
using i64 = long long;

void __quick_sort_aux(std::vector<int>&, int, int);
void quick_sort(std::vector<int>&);

int main()
{
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i)
        std::cin >> arr[i];

    quick_sort(arr);

    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " \n"[i == n - 1];

    // assert(std::ranges::is_sorted(arr));

    return 0;
}

void quick_sort(std::vector<int>& arr) {
    __quick_sort_aux(arr, 0, arr.size() - 1);
}


void __quick_sort_aux(std::vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int sentinel = arr[r];
    int left = l, right = r - 1;
    while (left < right) {
        while (arr[left] < sentinel && left < right) {
            ++left;
        }
        while (arr[right] >= sentinel && left < right) {
            --right;
        }
        // std::cout << left << ' ' << right << std::endl;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[r]) {
        std::swap(arr[left], arr[r]);
    } else {
        left = r;
    }

    // for (int a : arr) {
    //     std::cout << a << ' ';
    // }
    // endl(std::cout);

    __quick_sort_aux(arr, l, left - 1);
    __quick_sort_aux(arr, left + 1, r);
}
