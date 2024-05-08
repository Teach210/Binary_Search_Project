// Binary_Search_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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
    // Seed the mt19937 engine with a random device
    std::random_device rd;
    std::mt19937 rng(rd());

    // Define a distribution for random integers in the range [1, 100]
    std::uniform_int_distribution<int> distribution(1, 100);

    // Fill the vector with random numbers
    vector<int> data;
    for (int i = 0; i < 10; ++i) {
        int randomNumber = distribution(rng); // Generate a random number between 1 and 100
        data.push_back(randomNumber);
    }

    // Generate a random target value
    int target = distribution(rng); // Generate a random target value between 1 and 100

    // Sorting the vector
    sort(data.begin(), data.end());

    // Recursive Binary Search
    int index = recursiveBinarySearch(data, 0, data.size() - 1, target);
    cout << "Contents of vector: ";
    for (int num : data)
        cout << num << " ";
    cout << endl;
    if (index != -1)
        cout << "Target " << target << " found at location " << index << endl;
    else
        cout << "Target " << target << " was not found." << endl;

    // Iterative Binary Search
    index = iterativeBinarySearch(data, target);
    if (index != -1)
        cout << "Target " << target << " found at location " << index << endl;
    else
        cout << "Target " << target << " was not found." << endl;

    // Sequential Search
    index = sequentialSearch(data, target);
    if (index != -1)
        cout << "Target " << target << " found at location " << index << endl;
    else
        cout << "Target " << target << " was not found." << endl;

    return 0;
}




