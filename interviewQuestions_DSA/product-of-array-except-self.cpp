#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/dsa/a-product-array-puzzle/
// https://leetcode.com/problems/product-of-array-except-self/

vector<int> productExceptSelf(vector<int> &arr){
     // O(n^2) Time and O(n) Space
    int n = arr.size();
    vector<int> res(n, 1);
    for(int i = 0 ; i < n; i++){

       for(int j = 0 ; j < n ; j++){
         if (i != j) 
                res[i] *= arr[j];
       }
    }
    return res;
}
vector<int> productExceptSelf1(vector<int> &arr){
    // O(n) Time and O(n) Space
    int n = arr.size();
    vector<int> res(n), prefix(n), suffix(n);

    prefix[0] = 1;
    suffix[n-1] = 1;
    for(int i = 1; i < n ; i++){
        prefix[i] = prefix[i - 1] * arr[i - 1];
    }
    for(int j = n - 2 ; j >= 0 ; j--){
        suffix[j] = suffix[j + 1] * arr[j + 1];
    }

    for(int i  = 0 ; i < n ; i++){
        res[i] = prefix[i] * suffix[i];
    }
    return res;
}

vector<int> productExceptSelf2(vector<int> &arr){
    // O(n) Time and O(1) Space (excluding output array)
    int n = arr.size();
    vector<int> res(n, 1);

    // Calculate prefix products and store in result array
    // res[i] will contain product of all elements before index i
    for(int i = 1; i < n ; i++){
        res[i] = res[i - 1] * arr[i - 1];
    }

    // Calculate suffix products and multiply with prefix products
    int suffix = 1; // Track running product from right
    for(int j = n - 2 ; j >= 0 ; j--){
        suffix *= arr[j+1]; // Update suffix with right element
        res[j] *= suffix;   // Multiply prefix with suffix
    }
    return res;
}

int main(){
    vector<int> arr = {10, 3, 5, 6, 2};
    vector<int> res = productExceptSelf2(arr); // best approach
    for (int val : res) 
        cout << val << " ";
    cout << endl; // o/p - [180 600 360 300 900]
}