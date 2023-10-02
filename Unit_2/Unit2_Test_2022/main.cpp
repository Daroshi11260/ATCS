#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

void removeEvens(stack<int>& numstack);

void assignTask(queue<string>& taskQueue, set<string>& currentTasks);

int main() {
    cout << "Hello, World!" << endl;

    stack<int> zero;
    for (int i = 5; i <= 15; i++){
        zero.push(i);
    }
    removeEvens(zero);
    while(!zero.empty()){
        cout << zero.top() << endl;
        zero.pop();
    }

    queue<string> tasks;
    tasks.push("A");
    tasks.push("B");
    tasks.push("C");
    tasks.push("D");

    set<string> currentTasks;
    currentTasks.insert("A");
    currentTasks.insert("Y");
    currentTasks.insert("X");
    currentTasks.insert("B");

    assignTask(tasks, currentTasks);

    while(!tasks.empty()){
        cout << tasks.front() << endl;
        tasks.pop();
    }

    return 0;
}

void removeEvens(stack<int>& numstack){
    stack<int> temp;
    while(!numstack.empty()){
        if(numstack.top()%2 == 1){
            temp.push(numstack.top());
        }
        numstack.pop();
    }

    while(!temp.empty()){
        numstack.push(temp.top());
        temp.pop();
    }
}

void assignTask(queue<string>& taskQueue, set<string>& currentTasks){
    queue<string> temp;
    while(!taskQueue.empty()){
        string task = taskQueue.front();
        if(currentTasks.count(task) == 0){
            currentTasks.insert(task);
            taskQueue.pop();
            while(!temp.empty()){
                taskQueue.push(temp.front());
                temp.pop();
            }
            return;
        } else {
            temp.push(task);
            taskQueue.pop();
        }
    }
    taskQueue = temp;
}

map<string, set<string>> getCorrectClubMap (map<string, set<string>>& origmap){
    map<string, set<string>> newmap;
    for(auto iter = origmap.begin(); iter != origmap.end(); iter++){
        string club = iter->first;
        set<string> members = iter->second;
        for(string student :members){
            string member = student;
            newmap[member].insert(club);
        }
    }
    return newmap;
}
