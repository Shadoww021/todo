/*
Mohammad rajabali
40211360024*/




#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TodoItem {
    string description;
    bool isDone;
};

class TodoList {
private:
    vector<TodoItem> items;

public:
    void addItem(const string& description) {
     system("cls");
     cout<<"______<<To do List>>______\n";
        TodoItem newItem{description, false};
        items.push_back(newItem);
    }

    void displayList() {
     system("cls");
       cout<<"______<<To do List>>______\n";
        for (size_t i = 0; i < items.size(); ++i) {
         cout << i + 1 << ". " << (items[i].isDone ? "[X] " : "[ ] ") << items[i].description << "\n";
        }
    }

    void markAsDone(size_t index) {
     system("cls");
     cout<<"______<<To do List>>______\n";
        if (index > 0 && index <= items.size()) {
            items[index - 1].isDone = true;
        }else{
         cout<<"Invalid choice!!\n";
        }
    }

    void editItem(size_t index, const string& newDescription) {
     system("cls");
     cout<<"______<<To do List>>______\n";
        if (index > 0 && index <= items.size()) {
     items[index - 1].description = newDescription;
        }else{
         cout<<"Invalid choice!!\n";
  }
    
    }

    void deleteItem(size_t index) {
     system("cls");
     cout<<"______<<To do List>>______\n";
        if (index > 0 && index <= items.size()) {
            items.erase(items.begin() + index - 1);
        }else{
         cout<<"Invalid choice!!\n";
  }
    }
};

int main() {
    TodoList myTodoList;
    char choice;

    do {
        cout << "\n1. Add Todo Item\n";
        cout << "2. Display Todo List\n";
        cout << "3. Mark Item as Done\n";
        cout << "4. Edit Todo Item\n";
        cout << "5. Delete Todo Item\n";
        cout << "6. Exit\n";
        cout << "Enter your choice; ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1': {
                string newTodo;
                string Date;
                cout << "Enter the new Todo item: ";
                getline(cin, newTodo);
                cout << "Enter the endline date: ";
                getline(cin, Date);
                newTodo = newTodo + " " + Date;
                myTodoList.addItem(newTodo);
                break;
            }
            case '2':
                myTodoList.displayList();
                break;
            case '3': {
                size_t number;
                cout << "Enter the number of the index to mark as done: ";
                cin >> number;
                myTodoList.markAsDone(number);
                break;
            }
            case '4': {
                size_t index;
                string newDescription;
                string Date;
                cout << "Enter the index of the item to edit: ";
                cin >> index;
                cin.ignore(); // Ignore the newline character left in the input stream
                cout << "Enter the new description: ";
                getline(cin, newDescription);
                cout << "Enter the endline date: ";
                getline(cin, Date);
                newDescription = newDescription + " " + Date;
                myTodoList.editItem(index, newDescription);
                break;
            }
            case '5': {
                size_t index;
                cout << "Enter the index of the item to delete: ";
             cin >> index;
                myTodoList.deleteItem(index);
                break;
            }
            case '6':
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice!\n";
                cout<<"Please trying again*\n";
        }
    } while (choice != '6');

    return 0;
}