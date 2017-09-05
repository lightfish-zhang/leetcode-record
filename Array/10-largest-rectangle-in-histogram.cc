#include <vector>
using namespace std;

/* 简单的实现, 时间复杂度 O(N*N)
class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int result = 0;

    for(int i = 0; i<height.size(); i++){
      int tmp = height[i];
      for(int j = i-1; j>=0; j--){
        if(height[j] < height[i]){
          break;
        }
        tmp += height[i];
      }

      for(int j = i+1; j<height.size(); j++){
        if(height[j] < height[i]){
          break;
        }
        tmp += height[i];
      }
      result = max(result, tmp);
    }
    return result;
  }
};
*/

/*
复杂度实际为2N, 近似为O(N)
[解法](http://www.cnblogs.com/lichen782/p/leetcode_Largest_Rectangle_in_Histogram.html)
*/

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    vector<int> index;
    // 0作为最后的触发条件
    height.push_back(0);
    int area = 0;
    int i = 0;
    while (i < height.size()) {
      if (index.empty() || height[i] > height[index.back()]) {
        // index 是存放递增的柱的坐标
        index.push_back(i);
        i++;
      } else {
        int t = index.back();
        index.pop_back();
        // 如果index 退栈之后为空了，也就证明刚退栈的坐标的柱是最小的，此时i也为height.size()，计算包含最小的柱的矩形面积
        area = max(area, height[t] * (index.empty() ? i : i - index.back() - 1));
      }
    }
    height.pop_back();
    return area;
  }
};

#ifdef DEBUG

#include <iostream>

int main() {
  Solution s;
  vector<int> nums;
  int data[] = {2, 1, 5, 0, 4, 2, 3};
  for (int i = 0; i < 7; i++) {
    nums.push_back(data[i]);
  }

  int result = s.largestRectangleArea(nums);
  cout << result << endl;
  return 0;
}

#endif
