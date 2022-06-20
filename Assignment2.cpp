#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;
void studentManageSystem();
void addFunction();
void showStudent();

struct DataStore {
    vector < vector < vector <string> > > studentData;
} dataStore;

int main() {
    studentManageSystem();
    return 0;
}

void studentManageSystem() {
    int number;
    while(true) {
        cout << "------------ Student Management System ------------" << endl;
        cout << "** 1. ADD STUDENT                                **" << endl;
        cout << "** 2. DELETE STUDENT                             **" << endl;
        cout << "** 3. SHOW STUDENT                               **" << endl;
        cout << "** 4. EXIT                                       **" << endl;
        cout << "---------------------------------------------------" << endl;
        cout << "Input to use:";
        cin >> number;
        switch (number) {
            case 1:
                addFunction();
                break;
            case 2:
                break;
            case 3:
                showStudent();
                break;
            default:
                cout << "Invalid number";
                return;
        }
    }
}

void pause() {
    if(cin.get())
        cin.ignore(0xFFFFFFFF,'\n');
}

void addFunction() {
    string name, age, mathGrade, englishGrade, physicsGrade, id, classes;
    id = "1";
    cout << "Input student's name:";
    cin >> name;
    cout << "Input student's age:";
    cin >> age;
    cout << "Input student's class:";
    cin >> classes;
    cout << "Input student's math grade:";
    cin >> mathGrade;
    cout << "Input student's english grade:";
    cin >> englishGrade;
    cout << "Input student's physics grade:";
    cin >> physicsGrade;

    for (int i = 0; i < dataStore.studentData.size(); i++) {
        for (auto & j : dataStore.studentData[i]) {
            if (j[3] == classes) {
                id = to_string(dataStore.studentData[i].size() + 1);
                dataStore.studentData[i].push_back({id, name, age, classes, mathGrade, englishGrade, physicsGrade});
                return;
            }
            break;
        }
    }

    dataStore.studentData.push_back({{id, name, age, classes, mathGrade, englishGrade, physicsGrade}});
}

void showStudent() {
    int number;
    for (int i = 0; i < dataStore.studentData.size(); i++) {
        cout << "-->" << dataStore.studentData[i][0][3] << endl;
    }
    cout << "Input to use:";
    cin >> number;

    if (number > 0 && number <= dataStore.studentData.size()) {
        cout << setfill('-') << setw(110) << left << "" << endl;
        cout << '|' << ' ' << setfill(' ') << setw(4) << left << "IDs";
        cout << '|' << ' ' << setfill(' ') << setw(40) << left << "Name";
        cout << '|' << ' ' << setfill(' ') << setw(4) << left << "Age";
        cout << '|' << ' ' << setfill(' ') << setw(8) << left << "Class";
        cout << '|' << ' ' << setfill(' ') << setw(11) << left << "Math Grade";
        cout << '|' << ' ' << setfill(' ') << setw(14) << left << "English Grade";
        cout << '|' << ' ' << setfill(' ') << setw(14) << left << "Physics Grade |" << endl;
        cout << setfill('-') << setw(110) << left << "" << endl;

        for (auto & i : dataStore.studentData[number - 1]) {
            cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[0];
            cout << '|' << ' ' << setfill(' ') << setw(40) << left << i[1];
            cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[2];
            cout << '|' << ' ' << setfill(' ') << setw(8) << left << i[3];
            cout << '|' << ' ' << setfill(' ') << setw(11) << left << i[4];
            cout << '|' << ' ' << setfill(' ') << setw(14) << left << i[5];
            cout << '|' << ' ' << setfill(' ') << setw(14) << left << i[6] << '|' << endl;
            cout << setfill('-') << setw(110) << left << "" << endl;
        }
    } else {
        cout << "Invalid number";
    }
}

void deleteStudent() {

}
