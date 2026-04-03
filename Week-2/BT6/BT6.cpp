#include <iostream>
using namespace std;

void Output(int *a, int n){
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}

void Merge(int A[], int B[], int C[], int nB, int nC, int k) {
    int p, pb, pc, ib, ic;
    p = pb = pc = pb = ib = ic = 0;
    int kb = min(k, nB), kc = min(k, nC);
    while ((nB > 0) && (nC > 0)) {
        if (B[pb + ib] >= C[pc + ic]) {
            A[p++] = B[pb+ib];
            ib++;
            if (ib == kb) {
                for (; ic < kc; ic++)
                    A[p++] = C[pc+ic];
                pb += kb; pc += kc; ib = ic = 0; nB -= kb; nC -= kc;
                kb = min(k, nB); kc = min(k, nC);
            }
        }
        else {
            A[p++] = C[pc + ic]; ic++;
            if (ic == kc) {
                for (; ib < kb; ib++)
                    A[p++] = B[pb + ib];
                pb += kb; pc += kc; ib = ic = 0; nB -= kb; nC -= kc;
                kb = min(k, nB);
                kc = min(k, nC);
            }
        }
    }
}


void MergeSort(int A[], int n) {
    int p, pb, pc, i, k = 1;
    while (k < n) {
        cout << "k = " << k << "\nMang A (truoc khi chia): "; Output(A,n);
        p = pb = pc = 0;
        int *B = new int [n];
        int *C = new int [n];
        while (p < n) {
            for (i = 0; (p < n) && (i < k); i++)
                B[pb++] = A[p++];
            for (i = 0; (p < n) && (i < k); i++)
                C[pc++] = A[p++];
        }
        cout << "Mang B: "; Output(B,pb);
        cout << "Mang C: "; Output(C,pc);
        Merge(A, B, C, pb, pc, k);
        cout << "Mang A (sau khi gop): "; Output(A,n);
        cout << '\n';
        k *= 2;
    }
}

int main() {
    int n; cin >> n;
    int A[n];
    for (int &x : A) cin >> x;

    cout << "Mang truoc khi sap xep:\n";
    Output(A, n);
    cout << "\nSap xep:\n";

    MergeSort(A, n);

    cout << "Mang sau khi sap xep:\n";
    Output(A, n);

    return 0;
}