#include <iostream>
#include <vector>
using namespace std;

void heapify(vector <int> &v, int n, int i)
{
    int largest = i;
    int left = 2*i + 1, right = 2*i + 2;

    if (left < n && v[left] > v[largest]) largest = left;
    if (right < n && v[right] > v[largest]) largest = right;

    if (largest != i)
    {
        swap(v[i],v[largest]);
        heapify(v, n, largest);
    }
}

void heapSort(vector <int> &v)
{
    int n = v.size();
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(v,n,i);
    cout << "Mang sau khi BuildHeap: ";
    for (int x : v) cout << x << ' ';

    for (int i = n-1; i > 0; i--)
    {
        cout << "\nSwap " << v[0] << " va " << v[i] << "\n\n";
        swap(v[0],v[i]);
        heapify(v,i,0);
        cout << "Mang sau khi heapify voi n = " << i << ": ";
        for (int j = 0; j < v.size(); j++)
        {
            cout << v[j] << ' ';
            if (j == i-1) cout << "| ";
        }
    }
}

int main()
{
    int n; cin >> n;
    vector <int> v(n);
    for (int &x : v) cin >> x;
    cout << "Mang truoc khi sap xep:\n";
    for (int x : v) cout << x << ' ';
    cout << "\n\nSap xep:\n";
    heapSort(v);
    cout << "\nMang sau khi sap xep:\n";
    for (int x : v) cout << x << ' ';
    return 0;
}
