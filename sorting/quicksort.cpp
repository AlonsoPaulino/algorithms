// Quicksort O(nlogn)
// Reference: Introduction to Algorithms 3rd Edition
#include "../macros.h"

vector<int> v;

void quicksort(int lo, int hi) {
    if (lo >= hi) return;
    
    // Different criterias, we are using the one at the right
    int pivot = v[hi];

    // k: index of last element lower than pivot
    int k = lo - 1;
    for (int i = lo; i <= hi; ++i) {
        if (v[i] < pivot) {
            swap(v[++k], v[i]);
        }
    }
    swap(v[++k], v[hi]);

    quicksort(lo, k - 1);
    quicksort(k + 1, hi);
}
