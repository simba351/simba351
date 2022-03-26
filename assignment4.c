#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "assignment4.h"

/* Question 1 */

int queue_move(queue_t* destination, queue_t* source) 
{
    int cnt=0;
    while(!queue_is_empty(source))
    {
        cnt++;
        enqueue(destination,dequeue(source));
    }
    return cnt;
}

int queue_size(queue_t* q)
{
    int cnt=0;
    node_t* cur = q->obfuscate[q->what];
    while (cur) 
    {
        cnt++;
        cur=cur->next;
    }
    return cnt;
}
bool queue_equal(queue_t* q1, queue_t* q2)
{
    bool flag=true;
    if(queue_size(q1)!=queue_size(q2)) return false;
    node_t* cur1 = q1->obfuscate[q1->what];
    node_t* cur2 = q2->obfuscate[q2->what];
    while (cur1) 
    {
        if(cur1->data!=cur2->data) flag=false;
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return flag;
}

/* Question 2 */

float eval_arithmetic_expression(BTnode_t* root)
{
    if(root->value!=PLUS&&root->value!=MINUS&&root->value!=MULT&&root->value!=DIV) return root->value; 
    if(root->value==PLUS)
        return 1.0*eval_arithmetic_expression(root->left)+eval_arithmetic_expression(root->right);
    if(root->value==MINUS)
        return 1.0*eval_arithmetic_expression(root->left)-eval_arithmetic_expression(root->right);
    if(root->value==MULT)
        return 1.0*eval_arithmetic_expression(root->left)*eval_arithmetic_expression(root->right);
    if(root->value==DIV)
        return 1.0*eval_arithmetic_expression(root->left)/eval_arithmetic_expression(root->right);
}


/* Question 3 */

BTnode_t* find(BTnode_t* root, bool (*pred)(int))
{
    if(root->left!=NULL)
    {
        BTnode_t* ans=find(root->left,*pred);
        if(ans!=NULL) return ans;
    }
    if(pred(root->value)) return root;
    if(root->right!=NULL)
    {
        BTnode_t* ans=find(root->right,*pred);
        if(ans!=NULL) return ans;
    }
    return NULL;
}
BTnode_t* create_mirror_tree(BTnode_t* root)
{
    if(root==NULL) return NULL;
    create_mirror_tree(root->left);
    create_mirror_tree(root->right);
    BTnode_t* temp=root->left;
    root->left=root->right;
    root->right=temp;
    return root;
}

