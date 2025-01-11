#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class indices {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; 
            
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            numMap[nums[i]] = i;
        }
        
        
        return {};
    }
};


int main() {
     
    indices indices;
//ex-1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = indices.twoSum(nums1, target1);
    cout << "example - 1: [" << result1[0] << ", " << result1[1] << "]" <<endl;
//ex-2
    vector<int> nums2 = {3,2,4};
    int target2 = 6;
    vector<int> result2= indices.twoSum(nums2, target2);
    cout << "example - 2: [" << result1[0] << ", " << result2[1] << "]" <<endl;


//ex-3
    vector<int> nums3 = {3,3};
    int target3 = 6;
    vector<int> result3 = indices.twoSum(nums3, target3);
    cout << "example - 3: [" << result1[0] << ", " << result3[1] << "]" <<endl;

    return 0;
}
