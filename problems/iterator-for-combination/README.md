# `（中等）` [5123.iterator-for-combination 字母排列迭代器](https://leetcode-cn.com/problems/iterator-for-combination/)

[contest](https://leetcode-cn.com/contest/biweekly-contest-15/problems/iterator-for-combination/)

### 题目描述
<p>请你设计一个迭代器类，包括以下内容：</p>

<ul>
	<li>一个构造函数，输入参数包括：一个&nbsp;<strong>有序且字符唯一&nbsp;</strong>的字符串&nbsp;<code>characters</code>（该字符串只包含小写英文字母）和一个数字&nbsp;<code>combinationLength</code>&nbsp;。</li>
	<li>函数&nbsp;<em>next()&nbsp;</em>，按&nbsp;<strong>字典序&nbsp;</strong>返回长度为&nbsp;<code>combinationLength</code> 的下一个字母排列。</li>
	<li>函数&nbsp;<em>hasNext()&nbsp;</em>，只有存在长度为&nbsp;<code>combinationLength</code> 的下一个字母排列时，才返回&nbsp;<code>True</code>；否则，返回 <code>False</code>。</li>
</ul>

<p>&nbsp;</p>

<p><strong>示例：</strong></p>

<pre>CombinationIterator iterator = new CombinationIterator("abc", 2); // 创建迭代器 iterator

iterator.next(); // 返回 "ab"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "ac"
iterator.hasNext(); // 返回 true
iterator.next(); // 返回 "bc"
iterator.hasNext(); // 返回 false
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= combinationLength &lt;=&nbsp;characters.length &lt;= 15</code></li>
	<li>每组测试数据最多包含&nbsp;<code>10^4</code>&nbsp;次函数调用。</li>
	<li>题目保证每次调用函数&nbsp;<code>next</code>&nbsp;时都存在下一个字母排列。</li>
</ul>

            

---
### 思路
```
```



### 答题
``` C++
class CombinationIterator 
{
public:
    CombinationIterator(string characters, int combinationLength) 
        : chs(characters), len(combinationLength)
    {
        for (size_t i = 0; i < chs.size(); i++)
        {
            um[chs[i]] = i;
        }

		for (size_t i = 0; i < len; i++)
		{
			strNext.push_back(chs[i]);
		}
    }

    string next()
    {
        string ret = strNext;

        for (size_t i = strNext.size() - 1; i < strNext.size(); i--)
        {
            auto di = um[strNext[i]] + 1;
            if (di + len - i - 1 < chs.size())
            {
                strNext[i] = chs[di];
                while ((++i) < strNext.size())
                {
					strNext[i] = chs[++di];
                }
                return ret;
            }
        }
		strNext = "";

		return ret;
    }

    bool hasNext() 
    {
        return strNext != "";
	}

private:
    string chs;
	string strNext;
    int len;

    unordered_map<char, size_t> um;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```




