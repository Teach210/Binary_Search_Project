// Binary_Search_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;


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
    const int N = 10000000;
    double SumRBS = 0.0, SumIBS = 0.0, SumSeqS = 0.0;

    // Seed the mt19937 engine with a random device
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> distribution(1, 100);

    for (int k = 0; k < 10; ++k) {
        // Generate a vector with N random numbers
        vector<int> data;
        for (int i = 0; i < N; ++i) {
            int randomNumber = distribution(rng); // Generate a random number between 1 and 100
            data.push_back(randomNumber);
        }

        // Generate a random target value
        int target = distribution(rng); // Generate a random target value between 1 and 100

        // Timing code for Recursive Binary Search
        auto start = high_resolution_clock::now();
        recursiveBinarySearch(data, 0, data.size() - 1, target);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        SumRBS += static_cast<double>(duration.count());

        // Timing code for Iterative Binary Search
        start = high_resolution_clock::now();
        iterativeBinarySearch(data, target);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        SumIBS += static_cast<double>(duration.count());

        // Timing code for Sequential Search
        start = high_resolution_clock::now();
        sequentialSearch(data, target);
        end = high_resolution_clock::now();
        duration = duration_cast<microseconds>(end - start);
        SumSeqS += static_cast<double>(duration.count());
    }

    // Output average running times
    cout << "Average Running Time for Recursive Binary Search in microseconds is " << SumRBS / 10.0 << endl;
    cout << "Average Running Time for Iterative Binary Search in microseconds is " << SumIBS / 10.0 << endl;
    cout << "Average Running Time for Sequential Search in microseconds is " << SumSeqS / 10.0 << endl;

    return 0;
}



