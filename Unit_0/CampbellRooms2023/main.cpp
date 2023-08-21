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

int main() {
    cout << "WELCOME TO CAMPBELLROOMS!!!" << endl;
    loadRooms();
    return 0;
}

void loadRooms(){

    ifstream f("rooms.txt");

}




