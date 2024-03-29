#include "leetcodeIO.h"
class Solution {
public:
    int findMax(vector<int>& nums,int left,int right){
        int pos=left;
        for(int i=left;i<=right;++i){
            if(nums[pos]<nums[i]) pos=i;
        }
        return pos;
    }

    TreeNode* buildTree(vector<int> &nums,int left,int right){
        if(left<right) return nullptr;
        int newLoc=findMax(nums,left,right);
        TreeNode *root=new TreeNode(nums[newLoc]);
        root->left=buildTree(nums,left,newLoc-1);
        root->right=buildTree(nums,newLoc+1,right);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }
};

int main(){
    vector<int> temp;
    int num;
    while(cin>>num){
        temp.push_back(num);
    }
    Solution s;
    s.constructMaximumBinaryTree(temp);

    system("pause");
}
