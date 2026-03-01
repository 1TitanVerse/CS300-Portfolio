#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

string Trim(const string& s) {
    size_t start = s.find_first_not_of(" \t\r\n");
    if (start == string::npos) return "";
    size_t end = s.find_last_not_of(" \t\r\n");
    return s.substr(start, end - start + 1);
}

vector<string> SplitCSVLine(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(Trim(token));
    }
    return tokens;
}

bool LoadCourses(const string& fileName, map<string, Course>& courses) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error, could not open file: " << fileName << endl;
        return false;
    }

    courses.clear();

    string line;
    int lineNumber = 0;

    while (getline(file, line)) {
        lineNumber++;

        line = Trim(line);
        if (line.empty()) {
            continue;
        }

        vector<string> tokens = SplitCSVLine(line);

        if (tokens.size() < 2) {
            cout << "Formatting error on line " << lineNumber << ", needs at least courseNumber and title" << endl;
            continue;
        }

        Course c;
        c.courseNumber = tokens[0];
        c.title = tokens[1];

        for (size_t i = 2; i < tokens.size(); i++) {
            if (!tokens[i].empty()) {
                c.prerequisites.push_back(tokens[i]);
            }
        }

        if (c.courseNumber.empty()) {
            cout << "Formatting error on line " << lineNumber << ", missing course number" << endl;
            continue;
        }

        if (courses.find(c.courseNumber) != courses.end()) {
            cout << "Duplicate course number on line " << lineNumber << ", skipping: " << c.courseNumber << endl;
            continue;
        }

        courses[c.courseNumber] = c;
    }

    file.close();
    return true;
}

void PrintCourseList(const map<string, Course>& courses) {
    if (courses.empty()) {
        cout << "No courses loaded." << endl;
        return;
    }

    cout << "Course List" << endl;
    for (const auto& pair : courses) {
        cout << pair.second.courseNumber << ", " << pair.second.title << endl;
    }
}

void PrintCourse(const map<string, Course>& courses, const string& courseNumberInput) {
    if (courses.empty()) {
        cout << "No courses loaded." << endl;
        return;
    }

    string key = Trim(courseNumberInput);
    if (key.empty()) {
        cout << "Invalid course number." << endl;
        return;
    }

    auto it = courses.find(key);
    if (it == courses.end()) {
        cout << "Course not found: " << key << endl;
        return;
    }

    const Course& c = it->second;

    cout << c.courseNumber << ", " << c.title << endl;

    if (c.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
        return;
    }

    cout << "Prerequisites:" << endl;
    for (const string& prereqNum : c.prerequisites) {
        auto pit = courses.find(prereqNum);
        if (pit != courses.end()) {
            cout << prereqNum << ", " << pit->second.title << endl;
        } else {
            cout << prereqNum << ", " << "Title not found" << endl;
        }
    }
}

int ReadMenuChoice() {
    string input;
    getline(cin, input);
    input = Trim(input);

    if (input.empty()) return -1;

    for (char ch : input) {
        if (!isdigit(static_cast<unsigned char>(ch))) return -1;
    }

    return stoi(input);
}

int main() {
    map<string, Course> courses;
    bool loaded = false;

    cout << "ABCU Advising Assistance Program" << endl;

    while (true) {
        cout << endl;
        cout << "1. Load Data Structure" << endl;
        cout << "2. Print Course List" << endl;
        cout << "3. Print Course" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";

        int choice = ReadMenuChoice();

        if (choice == 1) {
            cout << "Enter the file name: ";
            string fileName;
            getline(cin, fileName);
            fileName = Trim(fileName);

            loaded = LoadCourses(fileName, courses);
            if (loaded) {
                cout << "Courses loaded successfully." << endl;
            }
        } else if (choice == 2) {
            if (!loaded) {
                cout << "Load courses first using option 1." << endl;
            } else {
                PrintCourseList(courses);
            }
        } else if (choice == 3) {
            if (!loaded) {
                cout << "Load courses first using option 1." << endl;
            } else {
                cout << "Enter a course number: ";
                string courseNumber;
                getline(cin, courseNumber);
                PrintCourse(courses, courseNumber);
            }
        } else if (choice == 9) {
            cout << "Goodbye." << endl;
            break;
        } else {
            cout << "Invalid option. Please enter 1, 2, 3, or 9." << endl;
        }
    }

    return 0;
}