#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void studentManageSystem();

void addFunction();

void showStudent();

void deleteStudent();

void searchStudent();

void editStudent();

void getHighestStudentInfo();

void getLowestStudentInfo();

void pause();

struct {
    int number{};
    vector<vector<vector<string> > > studentData;
} dataStore;

class DummyData {
public:
    DummyData() {
        dataStore.studentData.push_back({{"1", "P1", "18", "A1", "8", "7.5", "5.5", "8.4", "10"}});
        dataStore.studentData[0].push_back({"2", "P2", "18", "A1", "8.8", "9.5", "4.5", "6.6", "10"});
        dataStore.studentData[0].push_back({"3", "P3", "18", "A1", "8.5", "3.5", "8.5", "6.8", "10"});
        dataStore.studentData[0].push_back({"4", "P4", "18", "A1", "6.8", "9.5", "9.5", "7.5", "10"});
        dataStore.studentData[0].push_back({"5", "P5", "18", "A1", "6.8", "9.5", "9.5", "7.5", "10"});
        dataStore.studentData.push_back({{"1", "R1", "18", "A2", "6.5", "6.5", "2.5", "10", "8"}});
        dataStore.studentData[1].push_back({"2", "R2", "18", "A2", "9.5", "7.5", "9.5", "9", "5.5"});
        dataStore.studentData[1].push_back({"3", "R3", "18", "A2", "2.5", "5.5", "8.5", "4.5", "6.5"});
        dataStore.studentData[1].push_back({"4", "R4", "18", "A2", "6.5", "9.5", "10", "7.5", "10"});
    }
};

int main() {
    DummyData();
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
        cout << "\t\t\t| 4. SEARCH STUDENT                                |\t\t\t" << endl;
        cout << "\t\t\t| 5. EDIT STUDENT                                  |\t\t\t" << endl;
        cout << "\t\t\t| 6. GET HIGHEST STUDENT INFO                      |\t\t\t" << endl;
        cout << "\t\t\t| 7. GET HIGHEST STUDENT INFO                      |\t\t\t" << endl;
        cout << "\t\t\t| 8. EXIT                                          |\t\t\t" << endl;
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
            case 4:
                searchStudent();
                break;
            case 5:
                editStudent();
                break;
            case 6:
                getHighestStudentInfo();
                break;
            case 7:
                getLowestStudentInfo();
                break;
            case 8:
                return;
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

void output(vector<string> &data, string outputData, int num) {
    cout << "Changing " << data[num] << " to:";
    cin >> outputData;
    data[num] = outputData;
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
    int indexLength[] = {5, 41, 5, 9, 13, 8};
    cout << "Input to use:";
    cin >> dataStore.number;
    cout << endl;

    if (dataStore.number > 0 && dataStore.number <= dataStore.studentData.size()) {
        cout << "+";
        for (auto &i: indexLength) {
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
            for (auto &j: indexLength) {
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
        for (auto &i: indexLength) {
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
            int indexLength1[] = {5, 41, 13, 13, 13, 13, 9};
            cout << "+";
            for (auto &i: indexLength1) {
                cout << setfill('-') << setw(i) << "" << "+";
            }

            cout << endl;

            printf("| %-4s| %-40s| %-12s| %-12s| %-12s| %-12s| %-8s|", "IDs", "Name", "Math", "English", "Physics",
                   "Literature", "History");
            cout << endl;

            for (auto &i: dataStore.studentData[dataStore.number - 1]) {
                cout << "+";
                for (auto j: indexLength1) {
                    cout << setfill('-') << setw(j) << "" << "+";
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
            for (auto &i: indexLength1) {
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

    int indexLength[] = {5, 41, 5, 9, 13, 8};
    cout << "Input to use:";
    cin >> dataStore.number;

    if (dataStore.number > 0 && dataStore.number <= dataStore.studentData.size()) {
        cout << "+";
        for (auto &i: indexLength) {
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
            for (auto &j: indexLength) {
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
        for (auto &i: indexLength) {
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

void searchStudent() {
    if (dataStore.studentData.empty()) {
        cout << "There are no data currently" << endl;
        return;
    }

    string checkClass;
    int check = -1;

    cout << "Input class to search:";
    cin >> checkClass;

    for (int i = 0; i < dataStore.studentData.size(); i++) {
        if (dataStore.studentData[i][0][3] == checkClass) {
            check = i;
        }
    }

    if (check == -1) {
        cout << "There are no " << checkClass << " class in data" << endl;
        return;
    }

    cout << endl;
    cout << "\t\t\t+---------- Option ----------+\t\t\t" << endl;
    cout << "\t\t\t| 1. SEARCH BY IDs           |\t\t\t" << endl;
    cout << "\t\t\t| 2. SEARCH BY NAME          |\t\t\t" << endl;
    cout << "\t\t\t| 3. EXIT                    |\t\t\t" << endl;
    cout << "\t\t\t+----------------------------+\t\t\t" << endl;

    cout << "Input to use:";
    cin >> dataStore.number;

    string status = "Passed";
    int totalGrade;
    int indexLength[] = {5, 41, 5, 9, 13, 8};

    string name;

    switch (dataStore.number) {
        case 1:
            cout << "Input IDs to search:";
            cin >> dataStore.number;

            if (dataStore.number <= 0 || dataStore.number >= dataStore.studentData.size()) {
                cout << "There are no " << dataStore.number << " IDs in class " << checkClass << endl;
                return;
            }

            cout << endl;
            cout << "+";
            for (auto &i: indexLength) {
                cout << setfill('-') << setw(i) << "" << "+";
            }

            cout << endl;
            printf("| %-4s| %-40s| %-4s| %-8s| %-12s| %-7s|", "IDs", "Name", "Age", "Class", "Total Grade", "Status");
            cout << endl;

            totalGrade = (stoi(dataStore.studentData[check][dataStore.number - 1][4]) +
                          stoi(dataStore.studentData[check][dataStore.number - 1][5]) +
                          stoi(dataStore.studentData[check][dataStore.number - 1][6]) +
                          stoi(dataStore.studentData[check][dataStore.number - 1][7]) +
                          stoi(dataStore.studentData[check][dataStore.number - 1][8])) / 5;

            status = "Passed";
            if (totalGrade < 5) {
                status = "Failed";
            }

            cout << "+";
            for (auto &j: indexLength) {
                cout << setfill('-') << setw(j) << "" << "+";
            }

            cout << endl;
            cout << '|' << ' ' << setfill(' ') << setw(4) << left
                 << dataStore.studentData[check][dataStore.number - 1][0];
            cout << '|' << ' ' << setfill(' ') << setw(40) << left
                 << dataStore.studentData[check][dataStore.number - 1][1];
            cout << '|' << ' ' << setfill(' ') << setw(4) << left
                 << dataStore.studentData[check][dataStore.number - 1][2];
            cout << '|' << ' ' << setfill(' ') << setw(8) << left
                 << dataStore.studentData[check][dataStore.number - 1][3];
            cout << '|' << ' ' << setfill(' ') << setw(12) << left << totalGrade;
            cout << '|' << ' ' << setfill(' ') << setw(7) << left << status << '|' << endl;
            cout << "+";
            for (auto &i: indexLength) {
                cout << setfill('-') << setw(i) << "" << "+";
            }
            cout << endl;
            pause();
            break;
        case 2:
            cout << "Input Name to search:";
            cin >> name;

            for (auto &i: dataStore.studentData[check]) {
                if (i[1] == name) {
                    cout << endl;
                    cout << "+";
                    for (auto &j: indexLength) {
                        cout << setfill('-') << setw(j) << "" << "+";
                    }

                    cout << endl;
                    printf("| %-4s| %-40s| %-4s| %-8s| %-12s| %-7s|", "IDs", "Name", "Age", "Class", "Total Grade",
                           "Status");
                    cout << endl;

                    totalGrade = (stoi(i[4]) +
                                  stoi(i[5]) +
                                  stoi(i[6]) +
                                  stoi(i[7]) +
                                  stoi(i[8])) / 5;

                    status = "Passed";
                    if (totalGrade < 5) {
                        status = "Failed";
                    }

                    cout << "+";
                    for (auto &j: indexLength) {
                        cout << setfill('-') << setw(j) << "" << "+";
                    }

                    cout << endl;
                    cout << '|' << ' ' << setfill(' ') << setw(4) << left
                         << i[0];
                    cout << '|' << ' ' << setfill(' ') << setw(40) << left
                         << i[1];
                    cout << '|' << ' ' << setfill(' ') << setw(4) << left
                         << i[2];
                    cout << '|' << ' ' << setfill(' ') << setw(8) << left
                         << i[3];
                    cout << '|' << ' ' << setfill(' ') << setw(12) << left << totalGrade;
                    cout << '|' << ' ' << setfill(' ') << setw(7) << left << status << '|' << endl;
                    cout << "+";
                    for (auto &j: indexLength) {
                        cout << setfill('-') << setw(j) << "" << "+";
                    }
                    cout << endl;
                    pause();
                    break;
                }
            }
        default:
            break;
    }
}

void editStudent() {
    if (dataStore.studentData.empty()) {
        cout << "There are no data currently" << endl;
        return;
    }

    string checkClass;
    int check = -1;

    cout << "Input student's class to locate:";
    cin >> checkClass;

    for (int i = 0; i < dataStore.studentData.size(); i++) {
        if (dataStore.studentData[i][0][3] == checkClass) {
            check = i;
        }
    }

    if (check == -1) {
        cout << "There are no " << checkClass << " class in data" << endl;
        return;
    }

    cout << "Input student's IDs to edit:";
    cin >> dataStore.number;

    if (dataStore.number <= 0 || dataStore.number >= dataStore.studentData.size()) {
        cout << "There are no " << dataStore.number << " IDs in class " << checkClass << endl;
        return;
    }
    cout << endl;
    while (true) {
        cout << "\t\t\t+---------- Option ----------+\t\t\t" << endl;
        cout << "\t\t\t| 1. EDIT NAME               |\t\t\t" << endl;
        cout << "\t\t\t| 2. EDIT AGE                |\t\t\t" << endl;
        cout << "\t\t\t| 3. EDIT CLASS              |\t\t\t" << endl;
        cout << "\t\t\t| 4. EDIT MATH GRADE         |\t\t\t" << endl;
        cout << "\t\t\t| 5. EDIT ENGLISH GRADE      |\t\t\t" << endl;
        cout << "\t\t\t| 6. EDIT PHYSICS GRADE      |\t\t\t" << endl;
        cout << "\t\t\t| 7. EDIT LITERATURE GRADE   |\t\t\t" << endl;
        cout << "\t\t\t| 8. EDIT HISTORY GRADE      |\t\t\t" << endl;
        cout << "\t\t\t| 9. EXIT                    |\t\t\t" << endl;
        cout << "\t\t\t+----------------------------+\t\t\t" << endl;

        int option;
        string editTo;
        string id;
        cout << "Input to use:";
        cin >> option;

        switch (option) {
            case 1:
                output(dataStore.studentData[check][dataStore.number - 1], editTo, 1);
                break;
            case 2:
                output(dataStore.studentData[check][dataStore.number - 1], editTo, 2);
                break;
            case 3:
                cout << "Changing " << dataStore.studentData[check][dataStore.number - 1][3] << " to:";
                cin >> editTo;

                for (auto &i: dataStore.studentData) {
                    if (i[0][3] == editTo) {
                        id = to_string(i.size() + 1);
                        i.push_back(
                                {id, dataStore.studentData[check][dataStore.number - 1][1],
                                 dataStore.studentData[check][dataStore.number - 1][2],
                                 editTo,
                                 dataStore.studentData[check][dataStore.number - 1][4],
                                 dataStore.studentData[check][dataStore.number - 1][5],
                                 dataStore.studentData[check][dataStore.number - 1][6],
                                 dataStore.studentData[check][dataStore.number - 1][7],
                                 dataStore.studentData[check][dataStore.number - 1][8]});

                        cout << endl;
                        return;
                    }
                }

                dataStore.studentData.push_back(
                        {{"1", dataStore.studentData[check][dataStore.number - 1][1],
                          dataStore.studentData[check][dataStore.number - 1][2],
                          editTo,
                          dataStore.studentData[check][dataStore.number - 1][4],
                          dataStore.studentData[check][dataStore.number - 1][5],
                          dataStore.studentData[check][dataStore.number - 1][6],
                          dataStore.studentData[check][dataStore.number - 1][7],
                          dataStore.studentData[check][dataStore.number - 1][8]}});

                dataStore.studentData[check].erase(
                        dataStore.studentData[check].begin() + dataStore.number - 1);
                if (dataStore.studentData[check].empty()) {
                    dataStore.studentData.erase(dataStore.studentData.begin() + dataStore.number - 1);
                }

                for (int j = 0; j < dataStore.studentData[check].size(); j++) {
                    dataStore.studentData[dataStore.number - 1][j][0] = to_string(j + 1);
                }

                cout << endl;
                return;
            case 4:
                output(dataStore.studentData[check][dataStore.number - 1], editTo, 4);
                break;
            case 5:
                output(dataStore.studentData[check][dataStore.number - 1], editTo, 5);
                break;
            case 6:
                output(dataStore.studentData[check][dataStore.number - 1], editTo, 6);
                break;
            case 7:
                output(dataStore.studentData[check][dataStore.number - 1], editTo, 7);
                break;
            case 8:
                output(dataStore.studentData[check][dataStore.number - 1], editTo, 8);
                break;
            default:
                cout << endl;
                return;
        }
        cout << endl;
    }
}

void getHighestStudentInfo() {
    if (dataStore.studentData.empty()) {
        cout << "There are no data currently" << endl;
        return;
    }

    for (auto &i: dataStore.studentData) {
        cout << "--> " << i[0][3] << endl;
    }

    int indexLength[] = {5, 41, 5, 9, 13, 8};
    cout << "Input to use:";
    cin >> dataStore.number;
    cout << endl;

    int max = (stoi(dataStore.studentData[dataStore.number - 1][0][4]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][5]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][6]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][7]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][8])) / 5;

    vector<vector<string>> track;

    if (dataStore.number > 0 && dataStore.number <= dataStore.studentData.size()) {
        for (auto &i: dataStore.studentData[dataStore.number - 1]) {
            int totalGrade = (stoi(i[4]) + stoi(i[5]) + stoi(i[6]) + stoi(i[7]) + stoi(i[8])) / 5;

            if (totalGrade > max) {
                max = totalGrade;
                track.clear();
                track.push_back(i);
            } else if (totalGrade == max) {
                track.push_back(i);
            }
        }
    }

    cout << "+";
    for (auto &i: indexLength) {
        cout << setfill('-') << setw(i) << "" << "+";
    }

    cout << endl;
    printf("| %-4s| %-40s| %-4s| %-8s| %-12s| %-7s|", "IDs", "Name", "Age", "Class", "Total Grade", "Status");
    cout << endl;

    for (auto &i: track) {
        string status = "Passed";
        if (max < 5) {
            status = "Failed";
        }

        cout << "+";
        for (auto &j: indexLength) {
            cout << setfill('-') << setw(j) << "" << "+";
        }

        cout << endl;
        cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[0];
        cout << '|' << ' ' << setfill(' ') << setw(40) << left << i[1];
        cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[2];
        cout << '|' << ' ' << setfill(' ') << setw(8) << left << i[3];
        cout << '|' << ' ' << setfill(' ') << setw(12) << left << max;
        cout << '|' << ' ' << setfill(' ') << setw(7) << left << status << '|' << endl;
    }

    cout << "+";
    for (auto &i: indexLength) {
        cout << setfill('-') << setw(i) << "" << "+";
    }

    cout << endl;
    pause();
}

void getLowestStudentInfo() {
    if (dataStore.studentData.empty()) {
        cout << "There are no data currently" << endl;
        return;
    }

    for (auto &i: dataStore.studentData) {
        cout << "--> " << i[0][3] << endl;
    }

    int indexLength[] = {5, 41, 5, 9, 13, 8};
    cout << "Input to use:";
    cin >> dataStore.number;
    cout << endl;

    int max = (stoi(dataStore.studentData[dataStore.number - 1][0][4]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][5]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][6]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][7]) +
               stoi(dataStore.studentData[dataStore.number - 1][0][8])) / 5;

    vector<vector<string>> track;

    if (dataStore.number > 0 && dataStore.number <= dataStore.studentData.size()) {
        for (auto &i: dataStore.studentData[dataStore.number - 1]) {
            int totalGrade = (stoi(i[4]) + stoi(i[5]) + stoi(i[6]) + stoi(i[7]) + stoi(i[8])) / 5;

            if (totalGrade < max) {
                max = totalGrade;
                track.clear();
                track.push_back(i);
            } else if (totalGrade == max) {
                track.push_back(i);
            }
        }
    }

    cout << "+";
    for (auto &i: indexLength) {
        cout << setfill('-') << setw(i) << "" << "+";
    }

    cout << endl;
    printf("| %-4s| %-40s| %-4s| %-8s| %-12s| %-7s|", "IDs", "Name", "Age", "Class", "Total Grade", "Status");
    cout << endl;

    for (auto &i: track) {
        string status = "Passed";
        if (max < 5) {
            status = "Failed";
        }

        cout << "+";
        for (auto &j: indexLength) {
            cout << setfill('-') << setw(j) << "" << "+";
        }

        cout << endl;
        cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[0];
        cout << '|' << ' ' << setfill(' ') << setw(40) << left << i[1];
        cout << '|' << ' ' << setfill(' ') << setw(4) << left << i[2];
        cout << '|' << ' ' << setfill(' ') << setw(8) << left << i[3];
        cout << '|' << ' ' << setfill(' ') << setw(12) << left << max;
        cout << '|' << ' ' << setfill(' ') << setw(7) << left << status << '|' << endl;
    }

    cout << "+";
    for (auto &i: indexLength) {
        cout << setfill('-') << setw(i) << "" << "+";
    }

    cout << endl;
    pause();
}

