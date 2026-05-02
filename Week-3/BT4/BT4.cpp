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

void DeleteTail(LIST& l) {
    if (l.pHead == nullptr) return;
    if (l.pHead->pNext == nullptr) {
        delete l.pHead;
        l.pHead = nullptr;
    }
    else {
        NODE* temp1 = l.pHead;
        NODE* temp2 = l.pHead->pNext;
        while (temp2->pNext != nullptr){
            temp1 = temp1->pNext;
            temp2 = temp2->pNext;
        }
        temp1->pNext = nullptr;
        delete temp2;
    }
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
    for (int i = 0; i < k; i++)
        DeleteTail(L);
    PrintList(L);
    return 0;
}
