class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n == 0) {
            return 0;
        }

        int j = 0;
        for(int i = 1; i < n; i++) {
            if(A[j] != A[i]) {
                A[++j] = A[i];
            }
        }
        return j + 1;
    }
};


#ifdef DEBUG
#include <iostream>
int
main()
{
    Solution s;
    int n = 5;
    int a[5] = {0, 2, 2, 2, 4};
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
    n =s.removeDuplicates(a, n);
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
}
#endif