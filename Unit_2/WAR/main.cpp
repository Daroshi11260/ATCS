#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void handleWar(queue<int> &handA, queue<int> &handB, int frontA, int frontB);

int main() {
    cout << "Lets Play War!" << endl;

    srand(time(0));

    vector<int> allCards;

    for(int i = 0; i < 52; i++){
        allCards.push_back(i);
    }

    queue<int> handA;
    queue<int> handB;

    while (!allCards.empty()){
        int index = rand() % allCards.size();
        handA.push(allCards[index]);
        allCards.erase(allCards.begin() + index);

        index = rand() % allCards.size();
        handB.push(allCards[index]);
        allCards.erase(allCards.begin() + index);
    }

    while (!handA.empty() && !handB.empty()) {
        cout << handA.size() << " " << handB.size() << endl;
        int frontA = handA.front();
        int frontB = handB.front();
        handA.pop();
        handB.pop();

        if (frontA % 13 > frontB % 13) {
            handA.push(frontA);
            handA.push(frontB);
        } else if (frontA % 13 < frontB % 13) {
            handB.push(frontB);
            handB.push(frontA);
        } else {
            handleWar(handA, handB, frontA, frontB);
        }
        string dummy;
        getline(cin, dummy);
    }





    if (handA.empty()){
        cout << "Player B wins!" << endl;
    } else {
        cout << "Player A wins!" << endl;
    }
    return 0;
}

void handleWar(queue<int> &handA, queue<int> &handB, int frontA, int frontB){
    cout << "=== WAR ===" << endl;

    stack<int> stackA;
    stack<int> stackB;

    stackA.push(frontA);
    stackB.push(frontB);

    while (true){
        if (handA.empty() || handB.empty()){
            return;
        }

        int num = 4;

        if (handA.size() < 4){
            num = handA.size();
        }

        if (handB.size() < 4){
            num = handB.size();
        }

        //fill the wAr stacks

        for (int i = 0; i < num; i++){
            int cardA = handA.front();
            int cardB = handB.front();
            handA.pop();
            handB.pop();
            stackA.push(cardA);
            stackB.push(cardB);
        }

        if (stackA.top() %13 > stackB.top() % 13){
            while (!stackA.empty()){
                handA.push(stackA.top());
                stackA.pop();
            }
            while (!stackB.empty()){
                handA.push(stackB.top());
                stackB.pop();
            }
            return;
        } else if (stackA.top() %13 < stackB.top() % 13){
            while (!stackA.empty()){
                handB.push(stackA.top());
                stackA.pop();
            }
            while (!stackB.empty()){
                handB.push(stackB.top());
                stackB.pop();
            }
            return;
        }

    }
}
