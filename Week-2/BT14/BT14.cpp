#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.first < b.first) return true;
    if (a.first == b.first && a.second > b.second) return true;
    return false;
}

void QuickSortChuan(vector<pair<int,int>> &v, int l, int r) {
    if (l >= r) return;
    pair<int,int> pivot = v[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (compare(v[i], pivot)) i++;
        while (compare(pivot, v[j])) j--;
        if (i <= j) {
            swap(v[i], v[j]);
            i++; j--;
        }
    }
    QuickSortChuan(v, l, j);
    QuickSortChuan(v, i, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
    vector <pair<int,int>> v (n);
    for (pair<int,int> &x : v) cin >> x.first >> x.second;
    QuickSortChuan(v,0,n-1);
    for (pair<int,int> x : v) cout << x.first << ' ' << x.second << '\n';
    return 0;
}