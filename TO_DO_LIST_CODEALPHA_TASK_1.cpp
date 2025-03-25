// February 2025 Code_Alpha Batch
// Name: Muhammad Toseef Shareef
// Student ID: CA/FM3/2713

#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

// Class to represent a single task
class Task {
private:
    string description;  // Stores the task description
    bool completed;      // Stores whether the task is completed or not

public:
    // Constructor to initialize a task
    Task(const string& desc) : description(desc), completed(false) {}

    // Function to mark the task as completed
    void markCompleted() {
        completed = true;
    }

    // Function to get the task description
    string getDescription() const {
        return description;
    }

    // Function to check if the task is completed
    bool isCompleted() const {
        return completed;
    }
};

// Class to manage the to-do list
class ToDoList {
private:
    vector<Task*> tasks; // Vector to store multiple Task pointers

public:
    // Destructor to free allocated memory
    ~ToDoList() {
        for (Task* task : tasks) {
            delete task;
        }
    }

    // Function to add a new task to the list
    void addTask(const string& desc) {
        if (desc.empty()) {
            cout << "Task description cannot be empty!\n";
            return;
        }
        tasks.push_back(new Task(desc));
        cout << "Task added successfully!\n";
    }

    // Function to mark a task as completed
    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            if (tasks[index]->isCompleted()) {
                cout << "Task is already completed!\n";
            } else {
                tasks[index]->markCompleted();
                cout << "Task marked as completed!\n";
            }
        } else {
            cout << "Invalid task number! Please enter a valid number.\n";
        }
    }

    // Function to display all tasks
    void showTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available!\n";
            return;
        }

        cout << "\nYour To-Do List:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i]->getDescription()
                 << " - " << (tasks[i]->isCompleted() ? "Completed" : "Not Completed") << endl;
        }
    }
};

// Main function
int main() {
    ToDoList myList;
    int choice;

    do {
        // Display menu options
        cout << "\nTO-DO LIST APPLICATION\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. Show Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) { // Handle invalid input (non-integer)
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

        switch (choice) {
            case 1: {
                string desc;
                cout << "Enter task description: ";
                getline(cin, desc);
                myList.addTask(desc);
                break;
            }
            case 2: {
                int taskNumber;
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                if (cin.fail() || taskNumber < 1) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Enter a valid task number.\n";
                } else {
                    myList.completeTask(taskNumber - 1);
                }
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after reading number
                break;
            }
            case 3:
                myList.showTasks();
                break;
            case 4:
                cout << "Exiting application. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
