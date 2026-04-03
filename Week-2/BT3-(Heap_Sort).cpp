#include <bits\stdc++.h>
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

    for (int i = n-1; i >= 0; i--)
    {
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

int main()
{
    vector <int> v {1,5,6,2,3,4,8,7,9};
    heapSort(v);
    for (int x : v) cout << x << ' ';
    return 0;
}
