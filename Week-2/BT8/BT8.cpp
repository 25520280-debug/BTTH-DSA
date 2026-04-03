#include <iostream>
using namespace std;

void Output(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void SelectionSort(int a[], int n){
     int idx;
     for (int i = 0; i < n - 1; i++){
        cout << "i = "<< i << "\nMang truoc khi swap: ";
        Output(a,n);
        idx = i;
        for (int j = i + 1; j < n; j++){
            if (a[j] > a[idx])
                idx = j;
        }
        cout << "Phan tu lon nhat trong doan [" << i+1 << ", " << n-1 <<"]: " << a[idx] 
        << "\nSwap " << a[i] << " va " << a[idx] << "\nMang sau khi swap: ";
        swap(a[i], a[idx]);
        Output(a,n); cout << '\n';
     }
}

int main() {
    int n; cin >> n;
    int A[n]; 
    for (int &x : A) cin >> x;
    
    cout << "Mang truoc khi sap xep:\n";
    Output(A, n);
    cout << "\nSap xep:\n";
    SelectionSort(A, n);

    cout << "Mang sau khi sap xep:\n";
    Output(A, n);
    
    return 0;
}