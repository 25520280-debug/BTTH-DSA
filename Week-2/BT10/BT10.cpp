#include <iostream>
using namespace std;

void Output(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void InsertionSort(int a[], int n){
     int k, x;
     for (int i = 1; i < n; i++){
        cout << "i = " << i << "\nMang truoc khi xu ly: ";
        Output(a,n);
        k = i - 1;
        x = a[i];
        cout << "Phan tu dang xet A[" << i << "] = " << x;
        for (; k >= 0 && a[k] < a[i]; k--);
        k++;
        for (int j = i; j > k; j--)
            a[j] = a[j - 1];
        cout << "\nChen " << x << " vao vi tri k = " << k;
        a[k] = x;
        cout << "\nMang sau khi xu ly: "; Output(a,n); cout << '\n';
     }
}

int main() {
    int n; cin >> n;
    int A[n]; 
    for (int &x : A) cin >> x;
    
    cout << "Mang truoc khi sap xep:\n";
    Output(A, n);
    cout << "\nSap xep:\n";
    InsertionSort(A, n);

    cout << "Mang sau khi sap xep:\n";
    Output(A, n);
    
    return 0;
}