#include <bits/stdc++.h>
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

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
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

void TimKiemVaXoa(LIST &l, int k) {
    if (l.pHead == nullptr) {
        cout << -1;
        return;
    }

    bool found = false;

    while (l.pHead != nullptr && l.pHead->info == k) {
        NODE* temp = l.pHead;
        l.pHead = l.pHead->pNext;
        if (l.pHead == nullptr) l.pTail = nullptr;
        delete temp;
        found = true;
    }

    if (l.pHead == nullptr) return;
    
    NODE* prev = l.pHead;
    NODE* curr = l.pHead->pNext;

    while (curr != nullptr) {
        if (curr->info == k) {

            NODE* temp = curr;
            prev->pNext = curr->pNext;

            if (curr == l.pTail) l.pTail = prev;
            curr = curr->pNext;
            delete temp;
            found = true;
        }
        else {
            prev = curr;
            curr = curr->pNext;
        }
    }
    if (!found) cout << -1;
    else PrintList(l);
}

void TimKiemVaXoa(LIST &, int);


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
    TimKiemVaXoa(L, k);
    return 0;
}
