#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

// Function to compute the left and right bounds for each height
void computeBounds(const vector<int>& heights, vector<int>& left, vector<int>& right) {
    int n = heights.size();
    stack<int> monoStack;
    // Calculate the left limits for each bar
    for (int i = 0; i < n; ++i) {
        while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
            monoStack.pop();
        }
        left[i] = (monoStack.empty()) ? 0 : monoStack.top() + 1;
        monoStack.push(i);
    }
    // Clear the stack for the next calculation
    while (!monoStack.empty()) monoStack.pop();
    // Calculate the right limits for each bar
    for (int i = n - 1; i >= 0; --i) {
        while (!monoStack.empty() && heights[monoStack.top()] >= heights[i]) {
            monoStack.pop();
        }
        right[i] = (monoStack.empty()) ? n - 1 : monoStack.top() - 1;
        monoStack.push(i);
    }
}

// Function to compute the largest rectangle area with the given bounds
int computeMaxArea(const vector<int>& heights, const vector<int>& left, const vector<int>& right) {
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i < n; ++i) {
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
    }
    return maxArea;
}

// Optimized solution for finding the maximum rectangle with at most one modification
int maxRectangleWithModification(vector<int>& heights, int X) {
    int n = heights.size();

    // Step 1: Compute the left and right bounds for the original array
    vector<int> left(n), right(n);
    computeBounds(heights, left, right);

    // Step 2: Calculate the max area without any modification
    int maxArea = computeMaxArea(heights, left, right);

    // Step 3: Try modifying each element to X and calculate the new max area
    int originalMaxArea = maxArea;
    for (int i = 0; i < n; ++i) {
        int originalHeight = heights[i];

        // Only modify if it increases the height
        if (X >= originalHeight) {
            heights[i] = X;

            // Compute bounds for the modified array in constant time by adjusting local limits
            int newLeft = i, newRight = i;
            while (newLeft > 0 && heights[newLeft - 1] >= heights[i]) {
                newLeft--;
            }
            while (newRight < n - 1 && heights[newRight + 1] >= heights[i]) {
                newRight++;
            }

            int newMaxArea = (newRight - newLeft + 1) * heights[i];
            maxArea = max(maxArea, newMaxArea);

            // Restore the original height
            heights[i] = originalHeight;
        }
    }

    return maxArea;
}

int main() {
    int N, X;
    cin >> N >> X;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    // Get the maximum rectangle area possible with one modification
    int result = maxRectangleWithModification(heights, X);
    cout << result << endl;
    return 0;
}
