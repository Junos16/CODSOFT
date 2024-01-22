#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Tasks:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". ";
                std::cout << (tasks[i].completed ? "[X] " : "[ ] ");
                std::cout << tasks[i].description << std::endl;
            }
        }
    }

    void markAsCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].completed = true;
            std::cout << "Task marked as completed: " << tasks[index - 1].description << std::endl;
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            std::cout << "Task removed: " << tasks[index - 1].description << std::endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            std::cout << "Invalid task index." << std::endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "\n===== TO-DO LIST MANAGER =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore(); // Ignore the newline character in the buffer
                std::getline(std::cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }

            case 2:
                toDoList.viewTasks();
                break;

            case 3: {
                toDoList.viewTasks();
                std::cout << "Enter the task index to mark as completed: ";
                size_t index;
                std::cin >> index;
                toDoList.markAsCompleted(index);
                break;
            }

            case 4: {
                toDoList.viewTasks();
                std::cout << "Enter the task index to remove: ";
                size_t index;
                std::cin >> index;
                toDoList.removeTask(index);
                break;
            }

            case 5:
                std::cout << "Exiting the program. Goodbye!\n";
                return 0;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
