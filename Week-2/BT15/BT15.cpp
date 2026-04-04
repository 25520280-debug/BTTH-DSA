#include <iostream>
#include <vector>
using namespace std;

class c
{
    public :
    int x,y,z;
    friend istream& operator>>(istream& in, c &a)
    {
        in >> a.x >> a.y >> a.z;
        return in;
    }
    friend ostream& operator<<(ostream& out, c a)
    {
        out << a.x << ' ' << a.y << ' ' << a.z << '\n';
        return out;
    }
};

bool compare(const c a, const c b)
{
    if (a.x < b.x) return true;
    else if (a.x == b.x && a.y > b.y) return true;
    else if (a.x == b.x && a.y == b.y && a.z < b.z) return true;
    else return false;
}

void QuickSortChuan(vector <c> &a, int l, int r) 
{
    if (l >= r) return;
    c pivot = a[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (compare(a[i],pivot)) i++;
        while (compare(pivot, a[j])) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    QuickSortChuan(a, l, j);
    QuickSortChuan(a, i, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n; cin >> n;
    vector <c> v (n);
    for (c &a : v) cin >> a;
    QuickSortChuan(v,0,n-1);
    for (c a : v) cout << a;
    return 0;
}