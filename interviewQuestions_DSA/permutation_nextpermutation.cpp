#include <iostream>
using namespace std;

void nextPermutation(vector<int> &arr){
    
    int n = arr.size();

    int idx = -1 ; // idx = largest value index
     // find the largest value index, start from end
    for(int i = n -2 ; i >= 0 ; i--){
        if(arr[i] < arr[i+1]){
            idx = i;
            break;
        }
    }

    // Edge case , if idx still -1, then the array sort in decreasing order , in this case just reverse the array and return.
    if(idx == -1){
        reverse(arr.begin(), arr.end());
        return;
    }

    // find the just slightly largest value(first largest number) of arr[idx]

    for(int i = n -1 ; i > 0 ; i--){
        if(arr[i] > arr[idx]){
            swap(arr[i], arr[idx]);
            break;
        }
    }

    // now we have the largest value index so will reverse the array from (idx + 1 to n - 1 ), so that will have a smallest value
    reverse(arr.begin() + idx + 1, arr.end());
    
}

void permutation(vector<int> nums,vector<vector<int>> &ans, int index){
    // base case
    if(index >= nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index; i < nums.size() ; i++){
        swap(nums[i], nums[index]);
        // recursive call
        permutation(nums, ans, index+1);
        // back tracking
        swap(nums[i], nums[index]); // while going back to top swap back to the original form,
    }
}


int main(){

    // vector<int> arr = {2,1,5,4,3,0,0}; // o/p - [2 3 0 0 1 4 5 ]
    // vector<int> arr = {1,5,3,2}; // o/p - [2 1 3 5 ]
    vector<int> arr = {1,2,3,4}; // o/p - [1 2 4 3 ]
    // vector<int> arr = {4,3,2,1};  // o/p- [1 2 3 4 ]
    // vector<int> arr = {5,1}; // o/p- [1 5]
    nextPermutation(arr);

    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << "---> next Permutation " << endl;
    cout << "-------" << endl;

    // next Permutation :- Time - O(N) and Space - O(1),

    // ---------------------------

    // find all the Permulation
    vector<int> nums = {1,2,3,4}; 
    vector<vector<int>> ans;
    int index = 0;

    permutation(nums, ans, index);
    
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size() ; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    // T/C -  O(N! × N)
    // S/C - O(N)
    /*
    Output- 

    [1 3 2]
    [1 2 3]
    [3 1 2]
    [3 2 1]
    [2 3 1]
    [2 1 3]
    */
}