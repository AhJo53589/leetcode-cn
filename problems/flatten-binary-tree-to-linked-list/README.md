# `（中等）` [114.flatten-binary-tree-to-linked-list 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

### 题目描述
<p>给定一个二叉树，<a href="https://baike.baidu.com/item/%E5%8E%9F%E5%9C%B0%E7%AE%97%E6%B3%95/8010757">原地</a>将它展开为链表。</p>

<p>例如，给定二叉树</p>

<pre>    1
   / \
  2   5
 / \   \
3   4   6</pre>

<p>将其展开为：</p>

<pre>1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6</pre>


---
### 思路
```
```



### 答题
``` C++
void flatten(TreeNode* root) 
{
    stack<TreeNode*> st;
    TreeNode* curr = root;
    while (curr != nullptr)
    {
        if (curr->right != nullptr)
        {
            st.push(curr->right);
            curr->right = nullptr;
        }
        if (curr->left != nullptr)
        {
            curr->right = curr->left;
            curr->left = nullptr;
        }
        if (curr->right == nullptr && !st.empty())
        {
            curr->right = st.top();
            st.pop();
        }
        curr = curr->right;
    }
}
```


### 其它
``` C++
void flatten(TreeNode* root)
{
    if (root == nullptr) return;
    flatten(root->left);
    flatten(root->right);

    TreeNode* temp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right != nullptr) 
    {
        root = root->right;
    }
    root->right = temp;
}
```


