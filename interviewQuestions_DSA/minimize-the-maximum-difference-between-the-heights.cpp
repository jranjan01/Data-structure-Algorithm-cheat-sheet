#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/dsa/minimize-the-maximum-difference-between-the-heights/

int getMinDiff (vector<int> &arr, int k, int n){
    // Time - O(nlogn) , Space - O(1)

    // Sort the array (we have to sort, there is no other way to get the answer)
    sort(arr.begin(), arr.end());

    int ans = arr[n-1] - arr[0];
    
    for(int i = 1 ; i < n; i++){

        if(arr[i] - k < 0){ // heights can’t be negative
            continue;
        }
        // find the min height and max height
        int minH = min(arr[0] + k , arr[i] - k); // increase arr[0] by k and rest decrease by k
        int maxH = max(arr[n - 1] - k , arr[i - 1] + k); // decrease arr[n-1] by k and rest increase by k

        ans = min(ans, maxH - minH);
    }
    return ans;
}

int main (){
    int k = 3;
    vector<int> arr = {3, 9, 12, 16, 20};
    int ans = getMinDiff(arr, k, arr.size());
    cout << ans << endl;
}