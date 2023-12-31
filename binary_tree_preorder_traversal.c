
// # LEETCODE : URL https://leetcode.com/problems/binary-tree-preorder-traversal/
//PREVOUSLY DONE USING RECURSSIVE METHOD > ...But it's Iterative method. 

#if 0
gcc -o $0.out $0 && ./$0.out $@
rm  $0.out >/dev/null
exit
#endif



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


// // Definition for a binary tree node.
struct TreeNode {
     int val;
     struct TreeNode *left; 
     struct TreeNode *right;
 };



int* preorderTraversal(struct TreeNode* root, int* returnSize){ 
    // creating the stack of TreeNode can be done by 
    struct TreeNode* stack[101];
    int i=0,j=0;
    stack[i++]=NULL;
    stack[i]=root;
    int * returner=(int*)malloc(sizeof(int)*100);
    while(stack[i]!=NULL){
        struct TreeNode *temp=stack[i];
        returner[j++]=stack[i]->val; 
        int s=1;
        if(temp->right!=NULL) {
            stack[i++]=temp->right;
            s=0;
}
        if(temp->left!=NULL){
        stack[i]=temp->left;            
        s=2;
        } 
        if(s==0  || s==1)  i--;
            // printf("\n\n the latest on going value of i is %d\n\n with stack -> val being : %d ",i,stack[i]->val);
        
    }
   *returnSize=j;
    return returner; 
} 




int main(){
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));  // if we don't use malloc, it will be a pointer to NULL 
    root->val = 1;
    root->left = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->val = 2;
    root->right->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->left->val = 3;
    root->right->right=NULL;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    int returnSize = 0;
    int* returner = preorderTraversal(root, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", returner[i]);
    }
    return 0;
}

