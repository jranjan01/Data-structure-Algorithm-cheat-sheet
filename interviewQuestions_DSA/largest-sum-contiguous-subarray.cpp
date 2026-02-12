#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/dsa/largest-sum-contiguous-subarray/
int main(){
    // Kadane's Algorithm - Maximum Subarray Sum
    vector<int> arr = { 2, 3, -8, 7, -1, 2, 3};
    
    // Step 1: Initialize variables
    // ans: stores the maximum sum found so far
    // maxWindow: stores the maximum sum ending at current position
    int ans = arr[0];
    int maxWindow = arr[0];
    
    // Step 2: Iterate through array starting from index 1
    for(int i = 1; i < arr.size(); i++){
        // Step 3: For each element, decide whether to:
        // - Start a new subarray from current element (arr[i])
        // - Extend the existing subarray (maxWindow + arr[i])
        maxWindow = max(arr[i], maxWindow + arr[i]);
        
        // Step 4: Update the global maximum if current window is larger
        ans = max(ans, maxWindow);
    }

    cout << "Maximum Subarray Sum: " << ans << endl; // o/p = 11
}