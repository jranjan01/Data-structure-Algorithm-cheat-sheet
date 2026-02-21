#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/dsa/number-subarrays-product-less-k/
// https://leetcode.com/problems/subarray-product-less-than-k/

int countsubarray(vector<int>&arr, int n , int k){
    // T/C - O(N^2) , S/C - O(1)
    int count = 0;
    int product = 1;

    for(int i = 0 ; i < n ; i++){
        if(arr[i] < k){
            count++;
        }
        product = arr[i];
        for(int j = i + 1; j < n ; j++){
            product *= arr[j];
            if(product < k){
                count++;
            }
            else{
                break;
            }
       }
       
    }
    return count;
}

int countsubarrayUsingSlidingWindow(vector<int>&arr, int n , int k){
    // T/C - O(N) , S/C -  O(1)
    
    int start = 0; // Initialize start pointer of sliding window
    int end = 0; // Initialize end pointer of sliding window
    long long product = 1;  // product variable to store product of current window
    int count = 0;  // count to store number of subarrays with product < k

    // Iterate through array using end pointer
    while(end < n){
        product *= arr[end];  // Multiply current element to product

        // Shrink window from left while product is >= k
        while(product >= k){
            product /= arr[start];  // Divide product by start element to remove it from window
            start++;  // Move start pointer to right
        }

        count += (end - start + 1); // it will give number of sub array ending at j;
        end++;  // Move end pointer to right
        
    }
    // Return total count of subarrays with product < k
    return count;
}


int main(){
    vector<int> arr = {10, 5, 2, 6};
    int k = 100;
    int n = arr.size();

    cout << "subarray product count is : " << countsubarray(arr, n, k) << endl;

    cout << "subarray product count using sliding window: " <<  countsubarrayUsingSlidingWindow(arr , n , k) << endl; // BEST APPROACH
    // Output = 8 ==> 8 sub-arrays -->  [ {10} ,{10,5}, {5} , {5,2}, {2}, {5,2,6}, {2,6} , {6} ]

    // Complexities: Every element in the array is accessed at most two times, therefore, it is O(n) time
}