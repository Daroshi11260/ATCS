#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct roomAssignment {
    string number;
    string teacher;
};

vector <roomAssignment> assignments;

void loadRooms();
int getChoice();
void searchByRoom();
void searchByTeacher();

int main() {
    cout << "WELCOME TO CAMPBELLROOMS!!!" << endl;
    loadRooms();
    while (true){
        int choice = getChoice();
        if (choice == 1){
            searchByRoom();
        } else if(choice == 2){
            searchByTeacher();
        } else {
            break;
        }
    }
    cout<< endl << "goodbye." << endl;

    return 0;
}

void loadRooms(){
    ifstream f("rooms.txt");
    while (!f.eof()) {
        roomAssignment r;
        string teacher;
        f >> r.number;
        getline(f, teacher);
        r.teacher = teacher.substr(1);
        assignments.push_back(r);
    }
    f.close();
}

int getChoice(){
    cout << endl <<
    "1. Search by rooms" << endl <<
    "2. Search by teachers" << endl <<
    "3. Quit" << endl;

    while (true){
        cout << "your choice:";
        int num;
        cin >> num;
        if (num >= 1 && num <= 3){
            return num;
        }
    }


}

void searchByRoom(){
    cout << "enter room number:";
    string room;
    cin.ignore();
    cin >> room;
    for (int i = 0; i < assignments.size(); i++){
        if (assignments[i].number == room){
            cout << "room " << room << " is assigned to " << assignments[i].teacher << endl;
        }
    }
}

void searchByTeacher(){
    cout << "enter teacher name:";
    string teacher;
    cin.ignore();
    getline(cin, teacher);
    for (int i = 0; i < assignments.size(); i++){
        if (assignments[i].teacher == teacher){
            cout << "room " << assignments[i].number << " is assigned to " << teacher << endl;
        }
    }
}




