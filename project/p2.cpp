#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Event {
public:
    string title;
    string description;
    string date;
    bool isCompleted;

    Event(string t, string d, string dt) {
        title = t;
        description = d;
        date = dt;
        isCompleted = false;
    }
};

class Reminder {
    vector<Event> events;

public:
    void addEvent() {
        string title, desc, date;
        cin.ignore(); // clear buffer
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter description: ";
        getline(cin, desc);
        cout << "Enter date (yyyy-mm-dd): ";
        cin >> date;

        cout << "Event added successfully!\n";
    }

    void viewEvents() {
        if (events.empty()) {
            cout << "No events available.\n";
            return;
        }
        for (int i = 0; i < events.size(); i++) {
            cout << i + 1 << ". " << events[i].title << "\n";
            cout << "   Description: " << events[i].description << "\n";
            cout << "   Date: " << events[i].date << "\n";
            cout << "   Status: " << (events[i].isCompleted ? "Completed" : "Pending") << "\n";
            cout << "--------------------------\n";
        }
    }

    void removeEvent() {
        viewEvents();
        if (events.empty()) return;

        int index;
        cout << "Enter event number to remove: ";
        cin >> index;

        if (index > 0 && index <= events.size()) {
            events.erase(events.begin() + index - 1);
            cout << "Event removed successfully!\n";
        } else {
            cout << "Invalid event number!\n";
        }
    }

    void markAsDone() {
        viewEvents();
        if (events.empty()) return;

        int index;
        cout << "Enter event number to mark as done: ";
        cin >> index;

        if (index > 0 && index <= events.size()) {
            events[index - 1].isCompleted = true;
            cout << "Event marked as completed!\n";
        } else {
            cout << "Invalid event number!\n";
        }
    }

    void viewCompleted() {
        bool found = false;
        for (int i = 0; i < events.size(); i++) {
            if (events[i].isCompleted) {
                cout << i + 1 << ". " << events[i].title << " (Done)\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No completed events.\n";
        }
    }
};

int main() {
    Reminder rm;
    int choice;

    while (true) {
        cout << "\n** Event Reminder System **\n";
        cout << "1. Add Event\n";
        cout << "2. View Events\n";
        cout << "3. Remove Event\n";
        cout << "4. Mark Event as Done\n";
        cout << "5. View Completed Events\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: rm.addEvent(); break;
            case 2: rm.viewEvents(); break;
            case 3: rm.removeEvent(); break;
            case 4: rm.markAsDone(); break;
            case 5: rm.viewCompleted(); break;
            case 6: cout << "Exiting program.\n"; return 0;
            default: cout << "Invalid choice! Try again.\n";
        }
    }
}