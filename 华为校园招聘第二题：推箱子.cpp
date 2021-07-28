#include "leetcodeIO.h"
int findMin(vector<int> nums,int begin,int end){
    int temp = nums[begin];
    for (int i = begin; i <= end;++i){
        temp = (nums[i] < temp) ? nums[i] : temp;
    }
    return temp;
}

vector<int> findZero(vector<int> nums){
    
}

int pushBox(vector<int> box){
    queue<vector<int> > q;
    do{
        
    } while (!q.empty());

}

