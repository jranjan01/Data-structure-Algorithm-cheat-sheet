#include <iostream>
using namespace std;


// https://www.geeksforgeeks.org/dsa/find-all-array-elements-occurring-more-than-floor-of-n-divided-by-3-times/

vector<int> majorityElement1(vector<int> &arr){
    //  O(n^2) Time and O(1) Space

    int n = arr.size();
    vector<int> ans;

    for(int i = 0 ; i < n ; i++){
        int count = 0;
        for(int j  = i ; j < n ; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n / 3){
            if(ans.size() == 0 || ans[0] != arr[i]){
                ans.push_back(arr[i]);
            };
        }
        // if size is 2 then stop the loop we got our answer, because at max will get 2 majority element 
        if(ans.size() == 2){
            if(ans[0] > ans[1]){
                swap(ans[0], ans[1]);
            }
            break;
        }
    }
    return ans;
}


vector<int> majorityElement1UsingHashing(vector<int> &arr){
    /*
      T/C = O(N) ---> O(1) + O(N) = O(N) 
      S/C = O(N) ---> because of Hash map
    */
    int n = arr.size();
    unordered_map<int, int> countMap; // hash map Time complexity(T/C) - O(1) and S/C - O(N)
    vector<int> ans;

    for(auto val : arr){
        // find frequency of each number
        countMap[val]++;
        // check if the "val" count is greater than floor(n/3) 
        if(countMap[val] > n /3){
            // Add the element to the answer array
            ans.push_back(val);
            // check if answer array size is 2 then stop the loop we got our answer;
            if(ans.size() == 2){
                // The returned array of majority elements should be sorted.
                if(ans[0] > ans[1]){
                    swap(ans[0], ans[1]);
                }
                break;
            }
        }
    }
    return ans;

}

vector<int> majorityElement1UsingMooresVoting(vector<int> &arr){
    // T/C = O(N) , S/C = O(1)

    /*
        We track two candidates (element1 & element2) because at most 2 majority elements can exist
        when the threshold is n/3. More than 2 is mathematically impossible.

        Example:- In an array of length 10, floor(10/3) = 3, so we need elements appearing > 3 times.
        If the first element appears 4 times, we have 6 remaining slots (10 - 4 = 6).
        For a second element to also be a majority, it needs at least 4 occurrences.
        With only 6 slots remaining, at most one more element can qualify.
        Therefore, the maximum possible majority elements is 2.
    */
   
    int element1 = -1, element2 = -1;
    int count1 = 0 , count2 = 0;

    int n = arr.size();
    vector<int> ans;

    for(auto val : arr){
        // Increment count for element 1
        if(element1 == val){
            count1++;
        }
        // Increment count for element 2
        else if(element2 == val){
            count2++;
        }
        // New element 1 if count is zero, assing new value and increase count
        else if(count1 == 0){
            element1 = val;
            count1++;
        }
        // New element 2 if count is zero, assing new value and increase count
        else if(count2 == 0){
            element2 = val;
            count2++;
        }
        else{
            // Decrease counts if neither element
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for(auto num : arr){
        if(num == element1){
            count1++;
        }
        else if(num == element2){
            count2++;
        }
    }

    // Add to result if they are majority elements
    if(count1 > n/3){
        ans.push_back(element1);
    }
    if(count2 > n/3 && ans[0] != element2){
        // check if ans[0] != element2(to avoid duplicate)
        ans.push_back(element2);
    }

    // check the length of answer array if it's 2 then sort the array if it's not
    if(ans.size() == 2 && ans[0] > ans[1]){
        swap(ans[0], ans[1]);
    }
    return ans;
}

int main() {

    // Using Hashing
    vector<int> arr = {2, 2, 3, 1, 3};
    vector<int> res = majorityElement1UsingHashing(arr); // o/p = [2,3]

    // Using Nested Loops
    vector<int> arr1 = {2, 2, 3, 1, 3, 1, 1};
    vector<int> ans = majorityElement1(arr1); // o/p = [1]

    // Boyer-Moore’s Voting Algorithm (BEST APPROACH)
    vector<int> arr2 = {2, 2, 3, 1, 3, 2, 1, 1}; 
    vector<int> ans1 = majorityElement1UsingMooresVoting(arr2); // o/p = [1,2]

    /*
    Steps (Boyer-Moore’s Voting Algorithm ):
        - Initialize two variables ele1 = -1 and ele2 = -1, for elements and two variables cnt1 = 0 and cnt2 = 0, for counting.
        In each iteration,
        - If an element is equal to any element, update that element's count.
        - If count of a element reaches zero then replace that element with current element.
        - If neither element matches and both counts are non zero, decrement the counts.
        After this, 
        - in second pass we check if the chosen elements appear more than n/3 times in the array. If they do then include them in result array.
        - last return answer array of majority elements with sorted order.
    */

    for(auto val : ans1){
        cout << val << " ";
    }
    cout << endl;
}