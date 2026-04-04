#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MaHang
{
    public:
    string Ma;
    int SoLuong;
    MaHang(string s, int sl) : Ma(s), SoLuong(sl) {}

    friend ostream& operator << (ostream& out, MaHang x)
    {
        out << x.Ma << ' ' << x.SoLuong << '\n';
        return out;
    }
};

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

bool compare(MaHang a, MaHang b)
{
    if (a.SoLuong != b.SoLuong) 
        return a.SoLuong > b.SoLuong;
    else if (a.Ma.size() != b.Ma.size())
        return a.Ma.size() < b.Ma.size();
    else return a.Ma < b.Ma;
}

void myQuickSort(vector <MaHang> &a, int l, int r) 
{
    if (l >= r) return;
    MaHang pivot = a[l + (r - l) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (compare(a[i],pivot)) i++;
        while (compare(pivot,a[j])) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    }
    myQuickSort(a, l, j);
    myQuickSort(a, i, r);
}

int main()
{
    int n; cin >> n;
    cin.ignore();
    vector <string> v(n);
    for (string &x : v) getline(cin,x);
    QuickSort(v,0,n-1);
    vector <MaHang> a;
    int i = 0;
    while (i < n) 
    {
        int j = i + 1;
        while (j < n && v[j] == v[i]) j++;
        a.push_back(MaHang(v[i], j - i));
        i = j;
    }
    myQuickSort(a,0,a.size()-1);
    for (MaHang x : a) cout << x;
    return 0;
}