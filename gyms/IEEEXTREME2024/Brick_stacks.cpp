#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Stack {
    vector<int> bricks;
};

// Comparator for the priority queue to always access the stack with the smallest top brick
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> A(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Step 1: Sort the bricks by length
    sort(A.begin(), A.end());

    // Priority queue to hold the smallest top brick of each stack
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    // Array of stacks
    vector<Stack> stacks;

    // Step 2: Place each brick into a stack
    for (int i = 0; i < N; ++i) {
        int brick = A[i];

        // Check if we can place the brick on an existing stack
        if (!pq.empty() && pq.top().first + x <= brick) {
            // Use the stack with the smallest top brick that meets the condition
            int stackIndex = pq.top().second;
            pq.pop();
            stacks[stackIndex].bricks.push_back(brick);
            pq.push({brick, stackIndex});
        } else {
            // Create a new stack
            Stack newStack;
            newStack.bricks.push_back(brick);
            stacks.push_back(newStack);
            pq.push({brick, stacks.size() - 1});
        }
    }

    // Output the number of stacks
    cout << stacks.size() << endl;
    for (const auto& stack : stacks) {
        cout << stack.bricks.size();
        for (auto it = stack.bricks.rbegin(); it != stack.bricks.rend(); ++it) {
            cout << " " << *it;
        }
        cout << endl;
    }

    return 0;
}
