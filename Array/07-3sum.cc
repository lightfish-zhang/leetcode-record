#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > result;
        if(nums.size()<3){
            return result;
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            int target = - nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            if(target < 0)
                break;

            while(front < back){

                int sum = nums[front] + nums[back];

                if(sum < target){
                    front ++;
                }else if(sum > target){
                    back --;
                }else{
                    vector<int> tmp(3);
                    tmp[0] = nums[i];
                    tmp[1] = nums[front];
                    tmp[2] = nums[back];
                    result.push_back(tmp);

                    do{
                        front ++;
                    }while(
                        front < back
                        && nums[front] == tmp[1]
                    );

                    do{
                        back --;
                    }while(
                        front < back
                        && nums[back] == tmp[2]
                    );
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]){
                i++;
            }
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
    int data[] = {-1,0,1,2,-1,-4};
    for(int i=0; i<6; i++){
        nums.push_back(data[i]);
    }

    vector<vector<int> > result = s.threeSum(nums);

    for(int i=0; i<result.size(); i++){
        cout << "row " << i << endl;
        for(int j=0; j<result[i].size(); j++){
            cout << result[i][j] << endl;
        }
    }
    return 0;
}

#endif