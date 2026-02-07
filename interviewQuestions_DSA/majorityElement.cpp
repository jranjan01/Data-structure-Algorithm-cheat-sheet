#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/dsa/majority-element/

/*
Given an array arr[] of size n, find the element that appears more than ⌊n/2⌋ times. 
If no such element exists, return -1.
*/

int majorityElement(vector<int> &arr){
    // sort the array - T/C - O(nlogN)
    /*
        - Loop will take O(N) + sort will take O(nlogN) , so O(N) + O(nlogN) = O(nlogN) is higher then O(N), 
        so T/C will be O(nlogN)
        - Space = O(1)
    */

    sort(arr.begin(), arr.end());

    int n = arr.size();
    int majorityNum = arr[n/2];
    int count = 0;
    
    for(auto val : arr){
        if(val == majorityNum){
            count++;
        }
    }
    if(count > n/2){
        return majorityNum;
    }
    // If no majority element is found, return -1
    return -1;
}

int majorityElementUsingHashing(vector<int> &num1){
    /*
      T/C = O(N) ---> O(1) + O(N) = O(N) 
      S/C = O(N) ---> because of Hash map
    */
    int n = num1.size();
    unordered_map<int, int> countMap; // hash map Time complexity(T/C) - O(1) and S/C - O(N)

    for(int val : num1){ // using loop so T/C - (N) 
        countMap[val]++;
        if(countMap[val] > n / 2){
            return val;
        }
    }
    // If no majority element is found, return -1
    return -1;
}


int majorityElementUsingMooresVoting(vector<int> &num2){
    // T/C = O(N) , S/C = O(1)

    int n = num2.size();
    int element = -1;
    int count = 0;

    // Find a element
    for(int i = 0 ; i < n ; i++){
        if(count == 0){
            element = num2[i];
        }
        else if(element == num2[i]){
            count++;
        }
        else{
            count--;
        }
    }

    //  Validate the  element
    count = 0;
    for(auto val : num2){
        if(val == element){
            count++;
        }
    }
    // If count is greater than n / 2, return the element
    // otherwise, return -1
    if(count > n/2){
        return element;
    }
    return -1;
}

int main() {
    // Basic approach
    vector<int> arr = {1, 1, 2, 1, 3, 5, 1};
    cout << majorityElement(arr) << endl; // O/p = 1


    // Better approach-1 Using Hashing 
    vector<int> num = {4, 4, 2, 4, 3, 4}; 
    cout << majorityElementUsingHashing(num) << endl; // O/p = 4
    vector<int> num1 = {4, 4, 2, 1, 3}; 
    cout << majorityElementUsingHashing(num1) << endl; // O/p = -1 (no majority element)


    // Better approach-2 Using " Moore's Voting Algorithm " (BEST APPROACH)
    vector<int> num2 = {1, 1, 2, 1, 3, 5, 1}; 
    cout << majorityElementUsingMooresVoting(num2) << endl; // o/p = 1

    /*
    Step By Step Approach(Moore's Voting Algorithm):

        Initialize a element variable and a count variable.
            Traverse the array once:
                -> If count is zero, set the element to the current element and set count to one.
                -> If the current element equals the element, increment count.
                -> If the current element differs from the element, decrement count.
            Traverse the array again to count the occurrences of the element.
            If the element's count is greater than n / 2, return the element as the majority element.
        
    */


}