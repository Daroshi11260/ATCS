#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

int sum(Node* head);
int length(Node* head);
void print(Node* head);
void removeLast(Node* &head);

int main() {
    cout << "Hello, LinkedList!" << endl;

    Node* head = nullptr;
    /*
    head = new Node;
    head->value = 4;
    head->next = new Node;
    head->next->value = 8;
    head->next->next = new Node;
    head->next->next->value = 9;
    head->next->next->next = nullptr;
    */

    cout << "enter numbers, negative or 0 to quit" << endl;
    int num;
    cin >> num;
    while (num > 0) {
        Node* temp = head;
        head = new Node;
        head->value = num;
        head->next = temp;
        cin >> num;
    }

    cout << sum(head) << endl;

    cout << length(head) << endl;

    print(head);

    removeLast(head);

    print(head);


    return 0;
}

int sum(Node* head) {
    int sum = 0;
    Node* current = head;
    while (current != nullptr) {
        sum += current->value;
        current = current->next;
    }
    return sum;
}

int length(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

void print (Node* head){
    Node* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void removeLast(Node* &head) {
    if (head == nullptr) {
        return;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node *current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;

    }
}
