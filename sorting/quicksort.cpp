// Quicksort O(nlogn)
// Reference: Introduction to Algorithms 3rd Edition
#include "../macros.h"

vector<int> v;

void quicksort(int lo, int hi) {
    if (lo >= hi) return;

    // different criterias, we are using the one at the right
    int pivot = v[hi];

    // k: index of the first elemnt not lower than pivot
    // k: is initialized with the first index
    int k = lo;
    for (int i = lo; i < hi; ++i) {
        if (v[i] < pivot) {
            // if we find a value lower than pivot, we move k to the right
            swap(v[k++], v[i]);
        }
    }
    swap(v[k], v[hi]);

    quicksort(lo, k - 1);
    quicksort(k + 1, hi);
}
