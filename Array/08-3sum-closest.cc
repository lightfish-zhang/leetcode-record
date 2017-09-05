#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
      if(nums.size() < 3){
          return 0;
      }
      int result = 0;
      sort(nums.begin(), nums.end());
      for(int i=0; i<nums.size(); i++){
          int other = target - nums[i];
          int front = i+1;
          int back = nums.size() - 1;
          while(front < back){
            int sum = nums[front] + nums[back];
            result = sum + nums[i];
            if(sum < other){
                front ++;
            }else if(sum > other){
                back --;
            }else{
                return target;
            }
          }
          while(i<nums.size() && nums[i] == nums[i+1]){
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

    int result = s.threeSumClosest(nums, -5);
    cout << result << endl;
    return 0;
}

#endif