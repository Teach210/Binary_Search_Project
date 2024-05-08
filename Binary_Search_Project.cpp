// Binary_Search_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Recursive Binary Search
int recursiveBinarySearch(const vector<int>& arr, int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] > target)
            return recursiveBinarySearch(arr, left, mid - 1, target);

        return recursiveBinarySearch(arr, mid + 1, right, target);
    }
    return -1;
}

// Iterative Binary Search
int iterativeBinarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Sequential Search
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    vector<int> data = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20 };
    int target1 = 10; // target that exists in the list
    int target2 = 5;  // target that does not exist in the list

    // Sorting the vector
    sort(data.begin(), data.end());

    // Recursive Binary Search
    int index = recursiveBinarySearch(data, 0, data.size() - 1, target1);
    cout << "Contents of vector: ";
    for (int num : data)
        cout << num << " ";
    cout << endl;
    if (index != -1)
        cout << "Target " << target1 << " found at location " << index << endl;
    else
        cout << "Target " << target1 << " was not found." << endl;

    index = recursiveBinarySearch(data, 0, data.size() - 1, target2);
    if (index != -1)
        cout << "Target " << target2 << " found at location " << index << endl;
    else
        cout << "Target " << target2 << " was not found." << endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(data, target1);
    if (index != -1)
        cout << "Target " << target1 << " found at location " << index << endl;
    else
        cout << "Target " << target1 << " was not found." << endl;

    index = iterativeBinarySearch(data, target2);
    if (index != -1)
        cout << "Target " << target2 << " found at location " << index << endl;
    else
        cout << "Target " << target2 << " was not found." << endl;

    // Sequential Search
    index = sequentialSearch(data, target1);
    if (index != -1)
        cout << "Target " << target1 << " found at location " << index << endl;
    else
        cout << "Target " << target1 << " was not found." << endl;

    index = sequentialSearch(data, target2);
    if (index != -1)
        cout << "Target " << target2 << " found at location " << index << endl;
    else
        cout << "Target " << target2 << " was not found." << endl;

    return 0;
}




