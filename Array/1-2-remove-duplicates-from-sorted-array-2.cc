template <typename T, int N>
class Solution {
public:
    int removeDuplicates(T A[], int n);
};

template <typename T, int N>
int Solution<T, N>::removeDuplicates(T A[], int n)
{
    if(n == 0) {
        return 0;
    }

    int j = 0;
    int num = 0;
    for(int i = 1; i < n; i++) {
        if(A[j] == A[i]) {
            num++;
            if(num < N) {
                A[++j] = A[i];
            }
        } else {
            A[++j] = A[i];
            num = 0;
        }
    }
    return j + 1;
}


#ifdef DEBUG
#include <iostream>
int
main()
{
    Solution <int, 2> s;
    int n = 5;
    int a[5] = {0, 2, 2, 2, 4};
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
    n = s.removeDuplicates(a, n);
    std::cout << "after:" << std::endl;
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
}
#endif