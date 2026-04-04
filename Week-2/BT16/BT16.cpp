#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void QuickSort(vector <string> &a, int l, int r) 
{
    if (l >= r) return;
    string pivot = a[l + (r - l) / 2];
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
    int n; cin >> n;
    cin.ignore();
    vector <string> v(n);
    for (string &x : v) getline(cin,x);
    QuickSort(v,0,n-1);
    v.erase(unique(v.begin(),v.end()),v.end());
    cout << v.size();
    return 0;
}