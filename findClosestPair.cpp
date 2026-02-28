/*Find the closest pair from two arrays
Difficulty: EasyAccuracy: 18.01%Submissions: 77K+Points: 2
Given two sorted arrays arr1[] and arr2[] of size n and m and a number x, find the pair whose sum is closest to x and the pair has an element from each array. In the case of multiple closest pairs return any one of them.

Note : In the driver code, the absolute difference between the sum of the closest pair and x is printed.

Examples:

Input : arr1[] = [1, 4, 5, 7], arr2[] = [10, 20, 30, 40], x = 32
Output : [1, 30]
Explanation:The closest pair whose sum is closest to 32 is [1, 30] = 31.
Input : arr1[] = [1, 4, 5, 7], arr2[] = [10, 20, 30, 40], x = 50 
Output : [7, 40] 
Explanation: The closest pair whose sum is closest to 50 is [7, 40] = 47.
Constraints:
1 ≤ arr1.size(), arr2.size() ≤ 105
1 ≤ arr1[i], arr2[i] ≤ 109
1 ≤ x ≤ 109*/



#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> findClosestPair(vector<int>& arr1, vector<int>& arr2, int x) {
    int left = 0;
    int right = arr2.size() - 1;
    vector<int> closestPair = {arr1[0], arr2[0]};
    int minDiff = abs(arr1[0] + arr2[0] - x);
    
    while (left < arr1.size() && right >= 0) {
        int currentSum = arr1[left] + arr2[right];
        int currentDiff = abs(currentSum - x);
        
        if (currentDiff < minDiff) {
            minDiff = currentDiff;
            closestPair = {arr1[left], arr2[right]};
        }
        
        if (currentSum < x) {
            left++;
        } else {
            right--;
        }
    }
    
    return closestPair;
}

int main() {
    vector<int> arr1_1 = {1, 4, 5, 7};
    vector<int> arr2_1 = {10, 20, 30, 40};
    vector<int> result1 = findClosestPair(arr1_1, arr2_1, 32);
    cout << "[" << result1[0] << ", " << result1[1] << "]" << endl;
    
    vector<int> result2 = findClosestPair(arr1_1, arr2_1, 50);
    cout << "[" << result2[0] << ", " << result2[1] << "]" << endl;
    
    return 0;
}