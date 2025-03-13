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

void generateTestCase(int fileIndex, int maxT, int maxN, int maxK, int maxQ) {
    // Open the output file
    ofstream outFile("out" + to_string(fileIndex) + ".txt");

    // Generate the number of test cases (t)
    int t = randInt(1, maxT);
    outFile << t << endl;

    for (int i = 1; i <= t; i++) {
        // Generate n, k, and q
        int n = randInt(1, maxN);
        int k = randInt(1, maxK);
        // int q = randInt(1, maxQ);
        int q = maxQ;
        
        // Output n, k, and q for this test case
        outFile << n << " " << k << " " << q << endl;

        // Generate q queries
        for (int j = 0; j < q; j++) {
            // Generate n1, n2, k1, k2
            int n1 = randInt(1, n);
            int n2 = randInt(n1, n); // Ensure n1 ≤ n2
            int k1 = randInt(1, k);
            int k2 = randInt(k1, k); // Ensure k1 ≤ k2

            // Output the query
            outFile << n1 << " " << k1 << " " << n2 << " " << k2 << endl;
        }

    }

    outFile.close();
}

int main() {
    srand(time(0)); // Seed for randomness

    int numFiles = 2;      // Number of output files
    int maxT = 1;      // Maximum number of test cases per file (t)
    int maxN = 1000;       // Maximum value of n
    int maxK = 1000;       // Maximum value of k
    int maxQ = 300000;     

    for (int i = 0; i <= numFiles; i++) {
        generateTestCase(i,maxT , maxN, maxK, maxQ);
    }

    return 0;
}
