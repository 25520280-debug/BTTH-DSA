#include <iostream>
#include <vector>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void TimKiem(LIST, int);

void TimKiem(LIST l, int k) {
    if (l.pHead == nullptr) {cout << -1; return; };
    vector <int> res; bool flag = true; int idx = 0;
    while (l.pHead != nullptr) {
        if (l.pHead->info == k) {
            res.push_back(idx);
            flag = false;
        }
        idx++; l.pHead = l.pHead->pNext;
    }
    if (flag) { cout << -1; return; };
    for (int x : res) cout << x << ' ';
}

int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    int k; cin >> k;
    TimKiem(L, k);
    return 0;
}