template <typename T>
class Solution{
    public:
        int removeElement(T * A, int n, T elem);
};

template <typename T>
int Solution<T>::removeElement(T * A, int n, T elem){
    int j=0;
    for(int i=0; i<n; i++){
        if(elem != A[i]){
            A[j++] = A[i];
        }
    }
    return j;
}

#ifdef DEBUG
#include <iostream>
int
main()
{
    Solution<int> s;
    int n = 5;
    int a[] = {0, 1, 2, 3, 4};
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
    n =s.removeElement(a, n, 2);
    std::cout << "before:"<<std::endl;
    for(int i=0; i<n; i++)  
        std::cout << a[i] << std::endl;
}
#endif