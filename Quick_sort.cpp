#include <bits/stdc++.h>
using namespace std;

int Partition(int a[], int l, int r) {
    int pv = a[l];
    int p = l + 1;
    int q = r;
    while (p <= q) {
        while (a[p] <= pv && p <= r)
            p++;
        while (a[q] > pv)
            q--;
        if (p < q)
            swap(a[p], a[q]);
    }
    swap(a[l], a[q]);
    return q;
}

void quick_sort(int a[], int l, int r) {
    if (l < r) {
        int j = Partition(a, l, r);
        quick_sort(a, l, j - 1);
        quick_sort(a, j + 1, r);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}