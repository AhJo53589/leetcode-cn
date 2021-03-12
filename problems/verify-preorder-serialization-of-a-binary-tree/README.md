# `（中等）` [331.verify-preorder-serialization-of-a-binary-tree 验证二叉树的前序序列化](https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/)

### 题目描述
<p>序列化二叉树的一种方法是使用前序遍历。当我们遇到一个非空节点时，我们可以记录下这个节点的值。如果它是一个空节点，我们可以使用一个标记值记录，例如 <code>#</code>。</p>

<pre>     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
</pre>

<p>例如，上面的二叉树可以被序列化为字符串 <code>"9,3,4,#,#,1,#,#,2,#,6,#,#"</code>，其中 <code>#</code> 代表一个空节点。</p>

<p>给定一串以逗号分隔的序列，验证它是否是正确的二叉树的前序序列化。编写一个在不重构树的条件下的可行算法。</p>

<p>每个以逗号分隔的字符或为一个整数或为一个表示 <code>null</code> 指针的 <code>'#'</code> 。</p>

<p>你可以认为输入格式总是有效的，例如它永远不会包含两个连续的逗号，比如&nbsp;<code>"1,,3"</code> 。</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong><code>"9,3,4,#,#,1,#,#,2,#,6,#,#"</code>
<strong>输出: </strong><code>true</code></pre>

<p><strong>示例&nbsp;2:</strong></p>

<pre><strong>输入: </strong><code>"1,#"</code>
<strong>输出: </strong><code>false</code>
</pre>

<p><strong>示例 3:</strong></p>

<pre><strong>输入: </strong><code>"9,#,#,1"</code>
<strong>输出: </strong><code>false</code></pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/solution/verify-preorder-by-ikaruga-ssjg/)

### 答题
``` C++
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> st;
        st.push(0);

        stringstream ss(preorder);
        string temp;
        while (!st.empty() && getline(ss, temp, ',')) {
            st.top() += 1;
            if (temp != "#") {
                st.push(0);
            }
            while (!st.empty() && st.top() == 2) {
                st.pop();
            }
        }
        return st.size() == 1;
    }
};
```




