#include <iostream>
using namespace std;

class NODE {
public:
    int     info;
    NODE*   pNext;

    NODE(int x) :   info(x), pNext(nullptr) {}
};

NODE* CreateNode(int x) { return new NODE(x); }

class LIST {
public:
    NODE* pHead;
    LIST() : pHead(nullptr) {}

    LIST(const LIST& other) {
        if (other.pHead == nullptr) {
            pHead = nullptr;
            return;
        }
        pHead = new NODE(other.pHead->info);
        NODE* current = pHead;
        NODE* temp = other.pHead->pNext;
        while (temp != nullptr) {
            current->pNext = new NODE(temp->info);
            current = current->pNext;
            temp = temp->pNext;
        }
    }
    ~LIST() {
        while (pHead != nullptr) {
            NODE* temp = pHead;
            pHead = pHead->pNext;
            delete temp;
        }
    }
};

void InsertTail(LIST &L, NODE* newNode) {
    if (newNode == nullptr) return;
    if (L.pHead == nullptr) {
        L.pHead = newNode;
        return;
    }
    NODE* temp = L.pHead; 
    while (temp->pNext != nullptr) {
        temp = temp->pNext;
    }
    temp->pNext = newNode;
}

void CreateEmptyList(LIST &L) { L.pHead = nullptr; }

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
    PrintList(L);
    return 0;
}