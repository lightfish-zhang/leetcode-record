#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result(2);
        map<int, int> M;
        for(int i=0; i<numbers.size(); i++){
            int anthor = target - numbers[i];
            if(M.find(anthor) != M.end()){
                result[0] = M[anthor];
                result[1] = i;
            }
            M[numbers[i]] = i;
        }
        return result;
    }
};


#ifdef DEBUG

#include <iostream>

int
main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(11);
    nums.push_back(15);
    vector<int> result = s.twoSum(nums, 17);

    cout << result[0] << " " << result[1] << endl;

    return 0;
}

#endif