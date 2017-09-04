#include <vector>
using namespace std;
class Solution{
    public:
        void plusOne(vector<int> &A){
            int one = 1;
            int sum;
            for(int i=A.size() -1 ; i>=0; i--){
                sum = A[i] + one;
                A[i] = sum % 10;
                one = sum / 10;
            }
            if(one > 0){
                A.insert(A.begin(), one);
            }
        }
};

#ifdef DEBUG
#include <iostream>

int
main()
{
    Solution s;
    vector<int> a;
    a.push_back(9);
    a.push_back(9);
    a.push_back(9);
    s.plusOne(a);
    for(int i = 0; i < a.size(); i++){
        std::cout << a[i] << std::endl;
    }
}

#endif