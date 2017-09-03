template <typename T>
class Solution{
    public:
        int removeDuplicates(T * A, int n);
};

template <typename T>
int Solution<T>::removeDuplicates(T * A, int n){
    if(n <= 0)
        return n;
    int j=0;
    for(int i=1; i<n; i++){
        if(A[i] != A[j]){
            A[++j] = A[i];
        }
    }
    return j+1;
}


#ifdef DEBUG
#include <iostream>
int
main()
{
    Solution<int> s;
    int n = 5;
    int a[5] = {0, 2, 2, 2, 4};
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
    n =s.removeDuplicates(a, n);
    std::cout << "before:"<<std::endl;
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
}
#endif