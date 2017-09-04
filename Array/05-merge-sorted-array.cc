class Solution{
    public:
        void merge(int A[], int m, int B[], int n){
            m--;
            n--;
            for(int i=m + n + 1; i>=0; i--){
                if(A[m] > B[n] && m >=0){
                    A[i] = A[m--];
                }else{
                    A[i] = B[n--];
                }
            }
        }
};


#ifdef DEBUG

#include<iostream>

using namespace std;

int
main()
{
    Solution s;
    int A[10] = {1,3,5,7,9};
    int B[5] = {0,2,4,6,8};
    s.merge(A, 5, B, 5);
    for(int i=0; i<10; i++){
        cout << A[i] << endl;
    }
    return 0;
}

#endif