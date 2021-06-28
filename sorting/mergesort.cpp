// Mergesort O(nlogn)
// Reference: https://www.geeksforgeeks.org/merge-sort/
#include "../macros.h"

vector<int> v;

void mergesort(int lo, int hi) {
    if (lo >= hi) return;

    int mid = lo + (hi - lo) / 2;

    // split the array in two sub-arrays
    mergesort(lo, mid);
    mergesort(mid + 1, hi);

    vi tmp(hi - lo + 1);
    int i = lo, j = mid + 1, k = 0;

    // merge two sub-arrays [lo, mid] & [mid + 1, hi]
    while (i <= mid && j <= hi) {
        if (v[i] <= v[j]) tmp[k++] = v[i++];
        else tmp[k++] = v[j++];
    }
    while (i <= mid) tmp[k++] = v[i++];
    while (j <= hi) tmp[k++] = v[j++];

    // update original array
    for (int x = lo; x <= hi; ++x) {
        v[x] = tmp[x - lo];
    }
}
