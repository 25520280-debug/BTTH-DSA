#include <iostream>
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
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

NODE* TimKiem(LIST l, int k) {
    NODE* p = l.pHead;
    while (p != nullptr) {
        if (p->info == k) return p;
        p = p->pNext;
    }
    return nullptr;
}

void InsertNode(LIST &l, NODE* x) {
    NODE* newNode = CreateNode(1999);
    
    if (l.pHead == nullptr || x == nullptr) {
        InsertTail(l, newNode);
    }
    else {
        newNode->pNext = x->pNext;
        x->pNext = newNode;
        
        if (x == l.pTail) {
            l.pTail = newNode;
        }
    }
}

void TimKiemVaThem(LIST &l, int x) {
    NODE* found = TimKiem(l, x);
    InsertNode(l, found);
    PrintList(l);
}

NODE* TimKiem(LIST, int);
void InsertNode(LIST &, NODE*);
void TimKiemVaThem(LIST &, int);

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
    TimKiemVaThem(L, k);
    return 0;
}