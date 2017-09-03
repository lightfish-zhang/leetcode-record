#include <vector>

using namespace std;

class Solution{
    public:
        vector<int> plusOne(vector<int> &digits);
};

vector<int> Solution::plusOne(vector<int> &digits){
    vector<int> res(digits.size(), 0);
    int sum = 0;
    int one = 1;
    for(int i = digits.size() - 1; i>=0; i--){
        sum = one + digits[i];
        one = sum / 10;
        res[i] = sum % 10;
    }
    if(one > 0){
        res.insert(res.begin(), one);
    }
    return res;
}


#ifdef DEBUG
#include <iostream>

int
main()
{
    Solution s;
    vector<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(9);
    vector<int> b = s.plusOne(a);
    for(int i = 0; i < b.size(); i++){
        std::cout << b[i] << std::endl;
    }
}

#endif