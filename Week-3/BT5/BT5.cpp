#include <iostream>
using namespace std;

class NODE {
public:
    int info;
    NODE* pNext;
    NODE(int x): info(x), pNext(nullptr) {}
};

NODE* CreateNode(int x) { return new NODE(x); }

class LIST {
public:
    NODE* pHead;
    LIST() : pHead(nullptr) {}
    LIST(const LIST& other) {
        pHead = other.pHead;
    }
    ~LIST() {
        pHead = nullptr;
    }
};

void CreateEmptyList(LIST& L) { L.pHead = nullptr; }

void InsertTail(LIST& l, NODE* newNode) {
    if (newNode == nullptr) return;
    if (l.pHead == nullptr){
        l.pHead = newNode;
        return;
    }
    NODE* temp = l.pHead;
    while (temp->pNext != nullptr) temp = temp->pNext;
    temp->pNext = newNode;
}

int DemSoLuongPhanTuTrongL(LIST l) {
    if (l.pHead == nullptr) return 0;
    if (l.pHead->pNext == nullptr) return 1;
    int res = 0;
    while (l.pHead != nullptr) {
        res++;
        l.pHead = l.pHead->pNext;
    }
    return res;
}

void InsertTail(LIST &, NODE *);
int DemSoLuongPhanTuTrongL(LIST);

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
    int k = DemSoLuongPhanTuTrongL(L);
    cout << k;
    return 0;
}
