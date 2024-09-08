#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct Task {
    string description;
    bool complete;
     Task(const string& desc):description(desc), complete(false) {}
};
class ToDoList {
private:
    vector<Task> tasks;

public:
 
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks to display.\n";
            return;
        }

        cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            cout << (tasks[i].complete? "[Completed] " : "[Pending] ");
            cout << tasks[i].description << endl;
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].complete = true;
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed successfully.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList todo;

    int choice;
    string description;
    size_t index;
    cout<<"WELCOME TO THE TODO LIST MANAGER FROM CODSOFT"<<endl;
    while (true) {
        cout << "\nToDo List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore(); 
                getline(cin, description);
                todo.addTask(description);
                break;
            case 2:
                todo.viewTasks();
                break;
            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markAsCompleted(index);
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> index;
                todo.removeTask(index);
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}