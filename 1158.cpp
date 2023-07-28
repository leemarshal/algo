#include <iostream>
#include <list>

using namespace std;

typedef struct Node {
    short v;
    struct Node* next;
} Node;

void insert(short value, Node* tail, Node* head) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    tail->next = newnode;
    newnode->v = value;
    newnode->next = head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    short n,k;
    cin >> n >> k;
    if(n == 1) {
        cout << "<1>";
        return 0;
    }
    else if (n == 2) {
        if(k == 1)
            cout << "<1, 2>";
        else
            cout << "<2, 1>";
        return 0;
    }
    else if (k == 1) {
        cout << "<1";
        for (int i = 2; i <= n; i++) {
            cout << ", " << i;
        }
        cout << ">";
        return 0;
    }
    Node* head = (Node*)malloc(sizeof(Node));
    Node* tail = head;
    head->next = head;
    head->v = 1;
    for(int i = 2; i <= n; i++) {
        insert(i, tail, head);
        tail = tail->next;
    }
    Node* cur = head;
    Node* prev = head;
    cout << "<";
    for(int i = 0; i < k-2; i++) {
        prev = prev->next;
    }
    cur = prev->next;
    prev->next = cur->next;
    cout << (cur->v);
    free(cur);
    cur = nullptr;
    while(prev != prev->next) {
        for(int i = 0; i < k-1; i++) {
            prev = prev->next;
        }
        cur = prev->next;
        prev->next = cur->next;
        cout << ", " << (cur->v);
        free(cur);
        cur = nullptr;
    }
    cout << ", " << (prev->v);
    free(prev);
    prev = nullptr;
    head = nullptr;
    cout << ">";
    return 0;
}
//
// Created by 규북 on 2023/07/28.
//
