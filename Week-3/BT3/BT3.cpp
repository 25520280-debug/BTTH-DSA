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
void InsertHead(LIST& l, NODE* newNode) {
    if (newNode == nullptr) return;
    newNode->pNext = l.pHead;
    l.pHead = newNode;
}

void DeleteHead(LIST& l) {
    if (l.pHead == nullptr) return;
    else {
        NODE* temp = l.pHead;
        l.pHead = l.pHead->pNext;
        delete temp;
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
        InsertHead(L, CreateNode(x));
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++)
        DeleteHead(L);
    PrintList(L);
    return 0;
}