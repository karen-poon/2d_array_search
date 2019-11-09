#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;

const int infinite = 99999999;
bool search_ans, faster_search_ans = false; //check if I am able to find the number
int global_A[3][3] = {{infinite, infinite, infinite},   //a global array to store memory
                        {infinite, infinite, infinite},
                        {infinite, infinite, infinite}};

// a binary way of searching
void search(int i, int j, int v, int A[3][3]) {
    if (i >= 3 || j >= 3)
        return;
    if (A[i][j] == v) {
        search_ans = v;
        cout << "found " << A[i][j] << "!" << endl;
        return;
    }
    if (A[i][j] < v) {
        //cout << A[i][j] << endl;
        search (i, j+1, v, A);
        search (i+1, j, v, A);
    }
    return;
}

// a faster way of searching by memorizing
void faster_search(int i, int j, int v, int A[3][3]) {
    if (i >= 3 || j >= 3)
        return;
    if (global_A[i][j] != infinite) 
        return;
    global_A[i][j] = A[i][j]; //memorize

    if (A[i][j] == v) {
        faster_search_ans = v;
        cout << "found " << A[i][j] << "!" << endl;
        return;
    }
    if (A[i][j] < v) {
        //cout << A[i][j] << endl;
        faster_search (i, j+1, v, A);
        faster_search (i+1, j, v, A);
    }
    return;
}

int main() {
    int A[3][3] = {{2,5,10},{3,7,12},{9,11,15}}; //initialize data
    int v = 11; //the number you wanna search for

    //normal binary search
    cout << "**Normal Binary Search Begins!**" << endl;
    auto search_start = high_resolution_clock::now();
    search (0, 0, v, A);
    auto search_stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(search_stop - search_start);
    cout << "search ans: " << search_ans << endl;
    cout << "search time: " << duration.count() << " microseconds" << endl;

    //a faster way of searching
    cout << endl << "**A Faster Way of Searching Begins!**" << endl;
    auto faster_search_start = high_resolution_clock::now();
    faster_search (0, 0, v, A);
    auto faster_search_stop = high_resolution_clock::now(); 
    auto faster_search_duration = duration_cast<microseconds>(faster_search_stop - faster_search_start);
    cout << "faster_search ans: " << faster_search_ans << endl;
    cout << "faster_search time: " << faster_search_duration.count() << " microseconds" << endl; 
}

