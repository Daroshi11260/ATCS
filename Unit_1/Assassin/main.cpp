#include <iostream>

using namespace std;

struct DNode {
    string name;
    int numKills;
    DNode* next;
    DNode* prev;
};

DNode* findPlayer(DNode* head, string player);

int main() {
    cout << "welcome to assassin" << endl;
    cout << "enter names of players, one per line, blank line to stop" << endl;
    string player;
    getline(cin, player);
    DNode* head;
    DNode* tail = new DNode;
    tail->name = player;
    tail->numKills = 0;
    tail->next = nullptr;
    tail->prev = nullptr;
    getline(cin, player);
    while (player.length()>0){
        head = new DNode;
        head->name = player;
        head->numKills = 0;
        head->next = tail;
        tail-> prev = head;
        head->prev = nullptr;
        tail = head;
        getline(cin, player);
    }
    //loop the list
    while (tail->next != nullptr){
        tail = tail-> next;
    }
    tail->next = head;
    head->prev = tail;
    //list completed!

    while (head->next != head){
        cout << "who died? ";
        getline(cin, player);
        DNode* deadPlayer = findPlayer(head, player);
        if (deadPlayer == nullptr){
            cout << "theres no living player with that name" << endl;
        } else {
            deadPlayer->prev->numKills++;
            cout << deadPlayer->name << "(" << deadPlayer->numKills << " kills) was killed by " << deadPlayer->prev->name << "(" << deadPlayer->prev->numKills << " kills)." << endl;
            deadPlayer->prev->next = deadPlayer->next;
            deadPlayer->next->prev = deadPlayer->prev;
            if(deadPlayer == head){
                head = head-> next;
            }
            delete deadPlayer;
        }
    }
    cout << head->name << " is the winner!" << endl;

    return 0;
}

DNode* findPlayer(DNode* head, string player){
    if(head->name == player){
        return head;
    }
    DNode* temp = head->next;
    while (temp != head){
        if (temp->name == player) {
            return temp;
        } else {
            temp = temp->next;
        }
    }
    return nullptr;
}


