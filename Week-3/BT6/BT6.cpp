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

int TimKiem(LIST l, int x) {
    if (l.pHead == nullptr) return -1;
    int idx = 0;
    while (l.pHead != nullptr) {
        if (l.pHead->info == x) return idx;
        l.pHead = l.pHead->pNext; idx++;
    }
    return -1;
}

int TimKiem(LIST, int);

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
    cout << TimKiem(L, k);
    return 0;
}