#include <vector>
#include <map>
#include <iostream>

using std::vector;
using std::map;
using std::cout;
using std::endl;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        vector<int> result;

        vector<int>::size_type size = nums.size();
        for(vector<int>::size_type i=0; i<size; i++){
            int anthorNum = target - nums[i];
            if(hash.find(anthorNum) != hash.end()){
                result.push_back(hash[anthorNum]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

// test

int
main()
{
    Solution st;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    vector<int> result = st.twoSum(nums, 9);

    vector<int>::size_type size = result.size();
    for (vector<int>::size_type ix = 0; ix != size; ++ix)
        cout << result[ix] << '\n';
    cout << endl;

}