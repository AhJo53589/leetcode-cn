# `（中等）` [341.flatten-nested-list-iterator 扁平化嵌套列表迭代器](https://leetcode-cn.com/problems/flatten-nested-list-iterator/)

### 题目描述
<p>给你一个嵌套的整型列表。请你设计一个迭代器，使其能够遍历这个整型列表中的所有整数。</p>

<p>列表中的每一项或者为一个整数，或者是另一个列表。</p>

<p>&nbsp;</p>

<p><strong>示例 1:</strong></p>

<pre><strong>输入: </strong>[[1,1],2,[1,1]]
<strong>输出: </strong>[1,1,2,1,1]
<strong>解释: </strong>通过重复调用&nbsp;<em>next </em>直到&nbsp;<em>hasNex</em>t 返回 false，<em>next&nbsp;</em>返回的元素的顺序应该是: <code>[1,1,2,1,1]</code>。</pre>

<p><strong>示例 2:</strong></p>

<pre><strong>输入: </strong>[1,[4,[6]]]
<strong>输出: </strong>[1,4,6]
<strong>解释: </strong>通过重复调用&nbsp;<em>next&nbsp;</em>直到&nbsp;<em>hasNex</em>t 返回 false，<em>next&nbsp;</em>返回的元素的顺序应该是: <code>[1,4,6]</code>。
</pre>


---
### 思路
```
```



### 答题
``` C++
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger>& nestedList) : pool(vector<int>()), i(0) {
        for (auto& n : nestedList)
        {
            parse(n);
        }
    }

    void parse(NestedInteger& item)
    {
        if (item.isInteger())
        {
            pool.push_back(item.getInteger());
        }
        else
        {
            auto v = item.getList();
            for (auto it = v.begin(); it != v.end(); it++)
            {
                parse(*it);
            }
        }
    }

    int next() {
        return pool[i++];
    }

    bool hasNext() {
        return i < pool.size();
    }

private:
    vector<int> pool;
    int i;
};
```




