#include <iostream>
using namespace std;
// https://www.geeksforgeeks.org/dsa/trapping-rain-water/
// https://leetcode.com/problems/trapping-rain-water/description/

int maxWater(vector<int>& arr) {
    // Time complexity = O(N^2), Space complexity = O(1)
    int res = 0;
    // For every element of the array
    for (int i = 1; i < arr.size() - 1; i++) {

        // Find the maximum element on its left
        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        // Find the maximum element on its right
        int right = arr[i];
        for (int j = i + 1; j < arr.size(); j++)
            right = max(right, arr[j]);

        // Update the maximum water
        res += (min(left, right) - arr[i]);
    }

    return res;
}

int maxWater1(vector<int>& arr){
    // Time complexity - O(N) , Space complexity - O(N)
    /*
        Maintain two array(left , right) & left[i] contains highest bar on the left,
        and right[i] contains highest bar on the right,
    */
    int n = arr.size();
    int ans = 0;
    vector<int> left(n), right(n);  // S/C - O(N)

    // fill the left array
    left[0] = arr[0];
    for(int i = 1; i < n ; i++){
        left[i] = max(arr[i], left[i-1]);
    }

    // fill the right array
    right[n-1] = arr[n-1];
    for(int i = n - 2 ; i >= 0 ; i--){
        right[i] = max(right[i+1], arr[i]);
    }

    // now iterate the array and check " min(left[i], right[i]) - arr[i] "

    for(int j = 0 ; j < n ; j++){
        ans += (min(left[j], right[j]) - arr[j]);
    }
    return ans;
}

int maxWaterUsing2Pointer(vector<int>& height){
    // Time complexity - O(N) , Space complexity - O(1)

    int n = height.size();
    int left = 0 , right = n - 1;
    int leftMax = 0, rightMax = 0;
    int ans = 0;
    
    while(left < right){
        // get the max of left and right bar
        leftMax = max(leftMax , height[left]);
        rightMax = max(rightMax , height[right]);

        // check if leftMax < rightMax , then do left++ , else right-- and update the answer
        if(leftMax < rightMax){
            ans += leftMax - height[left];
            left++;
        }
        else{
            ans += rightMax - height[right];
            right--;
        }

    }
    return ans;
}

int main(){
    vector<int> arr = { 2, 1, 5, 3, 1, 0, 4 };
    cout << maxWater(arr) << endl; // o/p = 9
    cout << maxWater1(arr) << endl; // o/p = 9

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Using two pointer - " << maxWaterUsing2Pointer(height) << endl; // (BEST APPROACH) // o/p = 6
    /*
        Two pointer step:
            Initialize two pointers at both ends of the array
                - left starts at index 0
                - right starts at index n-1
            Track maximum heights seen so far from both sides
                - leftMax = highest bar from left
                - rightMax = highest bar from right

            Update leftMax = max(leftMax, arr[left])
            Update rightMax = max(rightMax, arr[right])

            If leftMax < rightMax:
                We already know there's a taller bar on the right
                so calculate answer and Move left++
            Else:
                We already know there's a taller bar on the left
                so calculate answer and Move right--
    */
}