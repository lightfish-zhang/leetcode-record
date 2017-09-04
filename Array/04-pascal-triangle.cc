#include <vector>

using namespace std;

class Solution{
    public:
        vector<vector <int> > generate(int numRows) {
            vector<vector <int> > result(numRows);
            for(int i=0; i<numRows; i++){
                result[i].resize(i+1);
                for(int j=0; j<=i; j++){
                    if(i == 0 && j ==0){
                        result[i][j] = 1;
                    }else{
                        result[i][j] = result[i-1][j-1] + result[i-1][j];
                    }
                }
                
            }
            return result;
        }
};


#ifdef DEBUG
#include <iostream>

int
main()
{
    Solution s;
    vector<vector <int> > result = s.generate(5);
    for(int i=0; i<5; i++){
        cout << "row " << i << endl;
        for(int j=0; j<=i; j++){
            cout << result[i][j] << endl;
        }
    }
    return 0;
}


#endif