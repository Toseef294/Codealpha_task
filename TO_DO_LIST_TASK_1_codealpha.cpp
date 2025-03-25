// February 2025 Code_Aplpha Batch 
// 𝗡𝗮𝗺𝗲: Muhammad Toseef Shareef
// 𝗦𝘁𝘂𝗱𝗲𝗻𝘁 𝗜𝗗: CA/FM3/2713



#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a single task
class Task {
private:
    string description;  // Stores the task description
    bool completed;      // Stores whether the task is completed or not


public:
    // Constructor to initialize a taskoij
    Task(string desc) {
        description = desc;
        completed = false; // Default is incomplete considereing the task is not completed
    }

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
    vector<Task> tasks; // Vector to store multiple Task objects

public:
    // Function to add a new task to the list
    void addTask(string desc) {
        tasks.push_back(Task(desc)); // Create a Task object and add it to the vector
        cout << "Task added successfully!\n";
    }

    // Function to mark a task as completed
    void completeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
            cout << "Task marked as completed!\n";
        } else {
            cout << "Invalid task number!\n";
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
            cout << i + 1 << ". " << tasks[i].getDescription() 
                 << " - " << (tasks[i].isCompleted() ? "Completed" : "Not Completed") << endl;
        }
    }
};

// Main function
int main() {
    ToDoList myList; // Create an object of the ToDoList class
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

        cin.ignore(); // Ignore the newline character after number input

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
