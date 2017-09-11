#include <vector>
using namespace std;

class Solution{
public:
    bool hammingWeight(int n){
        int ret = 0;
        while(n){
            ret ++;
            n &= (n-1);
        }
        return ret;
    }
};