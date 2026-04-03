#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, q; cin >> n >> q;
    vector <int> v (n), V (q); 
    for (int &x : v) cin >> x;
    sort(v.begin(),v.end());

    for (int &x : V) cin >> x;
    for (int &x : V)
    {
        int left = 0, right = v.size()-1, min_v = 1e9;
        bool flag = true;
        while (left <= right)
        {
            int mid = left + (right - left)/2;  
            if (x > v[mid]) left = mid+1;
            else if (x < v[mid]) 
            {
                flag = false;
                min_v = min(v[mid],min_v);
                right = mid-1;
            }
            else if (x == v[mid])
            {
                flag = false;
                min_v = v[mid];
                break;
            }
        }
        x = min_v; if (flag) x= -1;
    }
    for (int x : V) cout << x << '\n';
    return 0;
}