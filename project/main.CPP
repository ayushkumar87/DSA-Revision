#include <iostream>
using namespace std;

const int MAX = 100;

void inputMarks(int marks[], int &n) {
    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter marks for " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

void displayMarks(const int marks[], int n) {
    cout << "Student Marks: ";
    for (int i = 0; i < n; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
}

float calculateAverage(const int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += marks[i];
    return (float)sum / n;
}

int findMaximum(const int marks[], int n) {
    int max = marks[0];
    for (int i = 1; i < n; i++)
        if (marks[i] > max)
            max = marks[i];
    return max;
}

int findMinimum(const int marks[], int n) {
    int min = marks[0];
    for (int i = 1; i < n; i++)
        if (marks[i] < min)
            min = marks[i];
    return min;
}

void bubbleSort(int marks[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((ascending && marks[j] > marks[j + 1]) || (!ascending && marks[j] < marks[j + 1]))
                swap(marks[j], marks[j + 1]);
}

void selectionSort(int marks[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((ascending && marks[j] < marks[idx]) || (!ascending && marks[j] > marks[idx]))
                idx = j;
        }
        swap(marks[i], marks[idx]);
    }
}

int linearSearch(const int marks[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (marks[i] == target)
            return i;
    return -1;
}

int binarySearch(const int marks[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (marks[mid] == target)
            return mid;
        else if (marks[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int marks[MAX], n, choice, target;
    inputMarks(marks, n);

    do {
        cout << "\n--- Student Marks Analyzer Menu ---\n";
        cout << "1. Display Marks\n";
        cout << "2. Average Marks\n";
        cout << "3. Maximum Marks\n";
        cout << "4. Minimum Marks\n";
        cout << "5. Sort (Bubble Ascending)\n";
        cout << "6. Sort (Selection Descending)\n";
        cout << "7. Search (Linear)\n";
        cout << "8. Search (Binary - needs sorted list)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayMarks(marks, n);
            break;
        case 2:
            cout << "Average Marks: " << calculateAverage(marks, n) << endl;
            break;
        case 3:
            cout << "Maximum Marks: " << findMaximum(marks, n) << endl;
            break;
        case 4:
            cout << "Minimum Marks: " << findMinimum(marks, n) << endl;
            break;
        case 5:
            bubbleSort(marks, n, true);
            cout << "Marks sorted in ascending order using Bubble Sort.\n";
            break;
        case 6:
            selectionSort(marks, n, false);
            cout << "Marks sorted in descending order using Selection Sort.\n";
            break;
        case 7:
            cout << "Enter marks to search: ";
            cin >> target;
            {
                int index = linearSearch(marks, n, target);
                if (index != -1)
                    cout << "Found at position " << index + 1 << endl;
                else
                    cout << "Not found.\n";
            }
            break;
        case 8:
            cout << "Enter marks to search: ";
            cin >> target;
            {
                int index = binarySearch(marks, n, target);
                if (index != -1)
                    cout << "Found at position " << index + 1 << endl;
                else
                    cout << "Not found.\n";
            }
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
