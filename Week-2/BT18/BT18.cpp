#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector <int> &a, int l, int r) 
{
    if (l >= r) return;
    int pivot = a[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < pivot) i++;
        while (a[j] > pivot) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    QuickSort(a, l, j);
    QuickSort(a, i, r);
}

int main()
{
    int n,x; cin >> n >> x;
    vector <int> v(n);
    for (int &t : v) cin >> t;

    QuickSort(v,0,n-1);
    int l = 0, r = n-1, max_v = 0;
    while (l < r)
    {
        int curr = v[l] + v[r];
        if (curr <= x)
        {
            if (curr > max_v) max_v = curr;
            l++;
        }
        else r--;
    }
    cout << max_v;
    return 0;
}