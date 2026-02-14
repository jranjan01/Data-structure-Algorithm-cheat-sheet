#include <iostream>
using namespace std;
// https://www.geeksforgeeks.org/dsa/maximum-product-subarray/
// https://leetcode.com/problems/maximum-product-subarray

int maxproduct( vector<int> &arr , int n){
    // Time: O(n^2), Space: O(1)
    int ans = arr[0];
    for(int i = 0; i < n; i++){
        int mul = 1 ;
        for(int j = i ; j < n ; j++){
            mul *= arr[j];
            ans = max(ans, mul);
        }
       
    }
    return ans;
}

int maxProduct(vector<int> &arr , int n){
    /**
     * Traverses from both left-to-right and right-to-left to handle negative numbers.
     * Resets leftToRight / rightToLeft to 1 when encountering zero.
     * 
     * Time: O(n), Space: O(1)
     */
    int max_prod = INT_MIN;
    int leftToRight = 1; // to store product from left to Right
    int rightToLeft = 1; // to store product from right to left

    for(int i = 0; i < n ; i++){
        if(leftToRight == 0){ 
            leftToRight = 1;
        }
        if(rightToLeft == 0){
            rightToLeft = 1;
        }
        leftToRight *= arr[i];
        rightToLeft *= arr[n-i-1];
        max_prod = max(max_prod, max(leftToRight, rightToLeft));
    }
    return max_prod;
}


int main(){
    vector<int> arr = { -1, 2, -2, 0, 8};
    int n = arr.size();
    // int ans = maxproduct(arr,n);
    int ans = maxProduct(arr, n); // BEST APPROACH
    cout << ans << endl;
}