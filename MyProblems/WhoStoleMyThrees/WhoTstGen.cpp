#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<bits/stdc++.h>

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// #define getrand(l, r) uniform_int_distribution<long long>(l, r)(rng)

using namespace std;
const int N = 100000;

// Function to generate a random number between low and high inclusive
int randInt(int low, int high) {
    return low + rand() % (high - low + 1);
}

void generateTestCase(int fileIndex, int maxT) {
    // Open the output file
    ofstream outFile("out" + to_string(fileIndex) + ".txt");

    // Generate the number of test cases (t)
    int t = randInt(1, maxT);
    outFile << t << endl;

   
    outFile.close();
}

int main() {
    srand(time(0)); // Seed for randomness

    int numFiles = 5;      // Number of output files
    int maxT = 10;   

    for (int i = 0; i < numFiles; i++) {
        generateTestCase(i,maxT);
    }

    return 0;
}
