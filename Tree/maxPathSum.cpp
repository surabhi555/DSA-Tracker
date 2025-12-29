class Solution {
public:
    int solve(TreeNode* root,int &maxSum){
        if(root == NULL){
            return 0;
        }
        int leftGain = solve(root->left,maxSum);
        int rightGain = solve(root->right,maxSum);

        int pathThroughNode =leftGain+rightGain+root->val;

        int bestChildOnly =max(leftGain,rightGain)+root->val;

        int nodeOnly = root->val;

        maxSum =max({maxSum,pathThroughNode,bestChildOnly,nodeOnly});

        return max(bestChildOnly,nodeOnly);

    }
    int maxPathSum(TreeNode* root) {
        int maxSum =INT_MIN;
        solve(root,maxSum);
        return maxSum;
    }
};