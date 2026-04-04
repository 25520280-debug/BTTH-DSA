#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; cin >> n;
    vector <pair<int,int>> v (n);
    for (pair<int,int> &x : v) cin >> x.first >> x.second;
    sort(v.begin(),v.end(), [] (pair<int,int> x, pair<int,int> y) 
        {
            if (x.first == y.first) return x.second > y.second;
            else return x.first < y.first;
        });
    for (pair<int,int> x : v) cout << x.first << ' ' << x.second << '\n';
    return 0;
}