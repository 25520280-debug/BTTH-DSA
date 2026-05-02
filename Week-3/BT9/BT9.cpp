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

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pHead = L.pTail = p;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

NODE* TimKiem(LIST L, int x) {
    NODE* p = L.pHead;
    while (p != nullptr) {
        if (p->info == x) return p;
        p = p->pNext;
    }
    return nullptr;
}

void DeleteNode(LIST& l, NODE* target) {
    if (l.pHead == nullptr || target == nullptr) return;

    if (l.pHead == target) {
        NODE* temp = l.pHead;
        l.pHead = l.pHead->pNext;
        if (l.pHead == nullptr) l.pTail = nullptr; // Nếu xóa xong list rỗng
        delete temp;
        return;
    }

    NODE* prev = l.pHead;
    while (prev->pNext != nullptr && prev->pNext != target) {
        prev = prev->pNext;
    }

    if (prev->pNext == target) {
        prev->pNext = target->pNext;
        if (target == l.pTail) l.pTail = prev;
        delete target;
    }
}

void TimKiemVaXoa(LIST& l, int x) {
    NODE* target = TimKiem(l, x);
    if (target == nullptr) {
        cout << -1;
    } else {
        DeleteNode(l, target);
        NODE* temp = l.pHead;
        while (temp != nullptr) {
            cout << temp->info << ' ';
            temp = temp->pNext;
        }
    }
}

NODE* TimKiem(LIST, int);
void DeleteNode(LIST &, NODE*);
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