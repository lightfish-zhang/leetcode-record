class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = 0;
        for(i = 0; i < n; i++) {
            if(A[i] == elem) {
                continue;
            }

            A[j] = A[i];
            j++;
        }

        return j;
    }
};

#ifdef DEBUG
#include <iostream>
int
main()
{
    Solution s;
    int a[] = {0, 1, 2, 3, 4};
    std::cout << a[2] << std::endl;     
    s.removeElement(a, 5, 2);
    std::cout << a[2] << std::endl; 
}
#endif