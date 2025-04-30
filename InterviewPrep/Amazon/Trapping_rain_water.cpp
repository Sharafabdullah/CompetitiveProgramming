#include <iostream>
#include <vector>
#include <stack>
#include <algorithm> // for std::max

using namespace std;

class Solution {
public:
    // Approach 1: Using a Stack
    int trapStack(vector<int>& height) {
        int waterTrapped = 0;
        stack<int> st;
        
        for (int i = 0; i < height.size(); ++i) {
            // While current bar is higher than the bar at stack's top index
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                
                // If the stack is empty, no left boundary is available.
                if (st.empty()) break;
                
                // Calculate distance between current index and the new stack top index.
                int distance = i - st.top() - 1;
                // Find the bounded height
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                waterTrapped += distance * boundedHeight;
            }
            st.push(i);
        }
        return waterTrapped;
    }
    
    // Approach 2: Using Dynamic Programming
    int trapDP(vector<int>& height) {
        if (height.empty()) return 0;
        
        int n = height.size();
        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        
        // Fill leftMax array
        for (int i = 1; i < n; ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }
        
        // Fill rightMax array
        for (int i = n - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        
        // Calculate water trapped on each bar.
        int waterTrapped = 0;
        for (int i = 0; i < n; ++i) {
            waterTrapped += min(leftMax[i], rightMax[i]) - height[i];
        }
        return waterTrapped;
    }
};

int main() {
    // Test examples
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> height2 = {4,2,0,3,2,5};
    
    Solution solution;
    
    // Using the Stack Approach
    cout << "Using Stack Approach:" << endl;
    cout << "Water trapped for height1 is: " << solution.trapStack(height1) << " (Expected: 6)" << endl;
    cout << "Water trapped for height2 is: " << solution.trapStack(height2) << " (Expected: 9)" << endl;
    
    // Using the DP Approach
    cout << "\nUsing DP Approach:" << endl;
    cout << "Water trapped for height1 is: " << solution.trapDP(height1) << " (Expected: 6)" << endl;
    cout << "Water trapped for height2 is: " << solution.trapDP(height2) << " (Expected: 9)" << endl;
    
    return 0;
}
