#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

void studentManageSystem();

void addFunction();

void showStudent();

void deleteStudent();

struct DataStore {
    int number{};
    vector<vector<vector<string> > > studentData;
} dataStore;

int main() {
    studentManageSystem();
    return 0;
}

void studentManageSystem() {
    int number;
    while (true) {
        cout << "\t\t\t+----------- Student Management System ------------+\t\t\t" << endl;
        cout << "\t\t\t| 1. ADD STUDENT                                   |\t\t\t" << endl;
        cout << "\t\t\t| 2. DELETE STUDENT                                |\t\t\t" << endl;
        cout << "\t\t\t| 3. SHOW STUDENT                                  |\t\t\t" << endl;
        cout << "\t\t\t| 4. EXIT                                          |\t\t\t" << endl;
        cout << "\t\t\t+--------------------------------------------------+\t\t\t" << endl;
        cout << "Input to use:";
        cin >> number;
        switch (number) {
            case 1:
                addFunction();
                break;
            case 2:
                deleteStudent();
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
    if (cin.get())
        cin.ignore(0xFFFFFFFF, '\n');
}

void addFunction() {
    string name, age, id, classes, mathGrade, englishGrade, physicsGrade, literatureGrade, historyGrade;
    id = "1";
    cout << "Input student's name:";
    cin >> name;
    cout << endl;
    cout << "Input student's age:";
    cin >> age;
    cout << endl;
    cout << "Input student's class:";
    cin >> classes;
    cout << endl;
    cout << "Input student's math grade:";
    cin >> mathGrade;
    cout << endl;
    cout << "Input student's english grade:";
    cin >> englishGrade;
    cout << endl;
    cout << "Input student's physics grade:";
    cin >> physicsGrade;
    cout << endl;
    cout << "Input student's literature grade:";
    cin >> literatureGrade;
    cout << endl;
    cout << "Input student's history grade:";
    cin >> historyGrade;
    cout << endl;

    for (auto &i: dataStore.studentData) {
        for (auto &j: i) {
            if (j[3] == classes) {
                id = to_string(i.size() + 1);
                i.push_back(
                        {id, name, age, classes, mathGrade, englishGrade, physicsGrade, literatureGrade, historyGrade});
                return;
            }
            break;
        }
    }

    dataStore.studentData.push_back(
            {{id, name, age, classes, mathGrade, englishGrade, physicsGrade, literatureGrade, historyGrade}});
}

void showStudent() {
    if (dataStore.studentData.empty()) {
        cout << "There are no data currently" << endl;
        return;
    }

    for (auto &i: dataStore.studentData) {
        cout << "--> " << i[0][3] << endl;
    }
    int indexLength[] = {5,41,5,9,13,8};
    cout << "Input to use:";
    cin >> dataStore.number;
    cout << endl;

    if (dataStore.number > 0 && dataStore.number <= dataStore.studentData.size()) {
        cout << "+";
        for (auto &i : indexLength) {
            cout << setfill('-') << setw(i) << "" << "+";
        }

        cout << endl;
        printf("| %-4s| %-40s| %-4s| %-8s| %-12s| %-7s|", "IDs", "Name", "Age", "Class", "Total Grade", "Status");
        cout << endl;

        for (auto &i: dataStore.studentData[dataStore.number - 1]) {
            int totalGrade = (stoi(i[4]) + stoi(i[5]) + stoi(i[6]) + stoi(i[7]) + stoi(i[8])) / 5;

            string status = "Passed";
            if (totalGrade < 5) {
                status = "Failed";
            }

            cout << "+";
            for (auto &j : indexLength) {
                cout << setfill('-') << setw(j) << "" << "+";
            }

            cout << endl;
            cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[0];
            cout << '|' << ' ' << setfill(' ') << setw(40) << left << i[1];
            cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[2];
            cout << '|' << ' ' << setfill(' ') << setw(8) << left << i[3];
            cout << '|' << ' ' << setfill(' ') << setw(12) << left << totalGrade;
            cout << '|' << ' ' << setfill(' ') << setw(7) << left << status << '|' << endl;
        }
        cout << "+";
        for (auto &i : indexLength) {
            cout << setfill('-') << setw(i) << "" << "+";
        }

        cout << endl;

        int number;
        cout << endl;
        cout << "\t\t\t+---------- Option ----------+\t\t\t" << endl;
        cout << "\t\t\t| 1. VIEW DETAIL             |\t\t\t" << endl;
        cout << "\t\t\t| 2. EXIT                    |\t\t\t" << endl;
        cout << "\t\t\t+----------------------------+\t\t\t" << endl;
        cout << "Input to use: ";
        cin >> number;
        cout << endl;

        if (number == 1) {
            int indexLength1[] = {5,41,13,13,13,13,9};
            cout << "+";
            for (auto &i : indexLength1) {
                cout << setfill('-') << setw(i) << "" << "+";
            }

            cout << endl;

            printf("| %-4s| %-40s| %-12s| %-12s| %-12s| %-12s| %-8s|", "IDs", "Name", "Math", "English", "Physics",
                   "Literature", "History");
            cout << endl;

            for (auto &i: dataStore.studentData[dataStore.number - 1]) {
                double totalGrade = (stod(i[4]) + stod(i[5]) + stod(i[6]) + stod(i[7]) + stod(i[8])) / 5;

                string status = "Passed";
                if (totalGrade < 5) {
                    status = "Failed";
                }

                cout << "+";
                for (auto &i : indexLength1) {
                    cout << setfill('-') << setw(i) << "" << "+";
                }

                cout << endl;
                cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[0];
                cout << '|' << ' ' << setfill(' ') << setw(40) << left << i[1];
                cout << '|' << ' ' << setfill(' ') << setw(12) << left << i[4];
                cout << '|' << ' ' << setfill(' ') << setw(12) << left << i[5];
                cout << '|' << ' ' << setfill(' ') << setw(12) << left << i[6];
                cout << '|' << ' ' << setfill(' ') << setw(12) << left << i[7];
                cout << '|' << ' ' << setfill(' ') << setw(8) << left << i[8] << '|' << endl;
            }
            cout << "+";
            for (auto &i : indexLength1) {
                cout << setfill('-') << setw(i) << "" << "+";
            }

            cout << endl;
            pause();
        } else if (number == 2) {
            return;
        }
    } else {
        cout << "Invalid number" << endl;
        return;
    }
}

void deleteStudent() {
    if (dataStore.studentData.empty()) {
        cout << "There are no data currently" << endl;
        return;
    }

    for (auto &i: dataStore.studentData) {
        cout << "--> " << i[0][3] << endl;
    }

    int indexLength[] = {5,41,5,9,13,8};
    cout << "Input to use:";
    cin >> dataStore.number;

    if (dataStore.number > 0 && dataStore.number <= dataStore.studentData.size()) {
        cout << "+";
        for (auto &i : indexLength) {
            cout << setfill('-') << setw(i) << "" << "+";
        }

        cout << endl;
        printf("| %-4s| %-40s| %-4s| %-8s| %-12s| %-7s|", "IDs", "Name", "Age", "Class", "Total Grade", "Status");
        cout << endl;

        for (auto &i: dataStore.studentData[dataStore.number - 1]) {
            int totalGrade = (stoi(i[4]) + stoi(i[5]) + stoi(i[6]) + stoi(i[7]) + stoi(i[8])) / 5;

            string status = "Passed";
            if (totalGrade < 5) {
                status = "Failed";
            }

            cout << "+";
            for (auto &i : indexLength) {
                cout << setfill('-') << setw(i) << "" << "+";
            }

            cout << endl;
            cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[0];
            cout << '|' << ' ' << setfill(' ') << setw(40) << left << i[1];
            cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[2];
            cout << '|' << ' ' << setfill(' ') << setw(8) << left << i[3];
            cout << '|' << ' ' << setfill(' ') << setw(12) << left << totalGrade;
            cout << '|' << ' ' << setfill(' ') << setw(7) << left << status << '|' << endl;
        }
        cout << "+";
        for (auto &i : indexLength) {
            cout << setfill('-') << setw(i) << "" << "+";
        }

        cout << endl;
    }

    int number;
    cout << "Input to use:";
    cin >> number;
    if (number > 0 && number <= dataStore.studentData[dataStore.number - 1].size()) {
        dataStore.studentData[dataStore.number - 1].erase(
                dataStore.studentData[dataStore.number - 1].begin() + number - 1);
        if (dataStore.studentData[dataStore.number - 1].empty()) {
            dataStore.studentData.erase(dataStore.studentData.begin() + dataStore.number - 1);
        }

        for (int i = 0; i < dataStore.studentData[dataStore.number - 1].size(); i++) {
            dataStore.studentData[dataStore.number - 1][i][0] = to_string(i + 1);
        }
        cout << endl;
    } else {
        cout << "Invalid number" << endl;
        return;
    }
}