# `（简单）` [824.goat-latin 山羊拉丁文](https://leetcode-cn.com/problems/goat-latin/)

### 题目描述
<p>给你一个由若干单词组成的句子&nbsp;<code>sentence</code> ，单词间由空格分隔。每个单词仅由大写和小写英文字母组成。</p>

<p>请你将句子转换为 <em>“</em>山羊拉丁文（<em>Goat Latin</em>）<em>”</em>（一种类似于 猪拉丁文&nbsp;- Pig Latin 的虚构语言）。山羊拉丁文的规则如下：</p>

<ul>
	<li>如果单词以元音开头（<code>'a'</code>, <code>'e'</code>, <code>'i'</code>, <code>'o'</code>, <code>'u'</code>），在单词后添加<code>"ma"</code>。

	<ul>
		<li>例如，单词 <code>"apple"</code> 变为 <code>"applema"</code> 。</li>
	</ul>
	</li>
	<li>如果单词以辅音字母开头（即，非元音字母），移除第一个字符并将它放到末尾，之后再添加<code>"ma"</code>。
	<ul>
		<li>例如，单词 <code>"goat"</code> 变为 <code>"oatgma"</code> 。</li>
	</ul>
	</li>
	<li>根据单词在句子中的索引，在单词最后添加与索引相同数量的字母<code>'a'</code>，索引从 <code>1</code> 开始。
	<ul>
		<li>例如，在第一个单词后添加 <code>"a"</code> ，在第二个单词后添加 <code>"aa"</code> ，以此类推。</li>
	</ul>
	</li>
</ul>

<p>返回将 <code>sentence</code> 转换为山羊拉丁文后的句子。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>sentence = "I speak Goat Latin"
<strong>输出：</strong>"Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>sentence = "The quick brown fox jumped over the lazy dog"
<strong>输出：</strong>"heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= sentence.length &lt;= 150</code></li>
	<li><code>sentence</code> 由英文字母和空格组成</li>
	<li><code>sentence</code> 不含前导或尾随空格</li>
	<li><code>sentence</code> 中的所有单词由单个空格分隔</li>
</ul>


---
### 思路
```
```



### 答题
``` C++
class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> v = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string ans;
        int cnt = 1;

        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            if (v.find(word[0]) == v.end()) {
                rotate(word.begin(), word.begin() + 1, word.end());
            }
            word += "ma" + string(cnt++, 'a');
            ans += word + " ";
        }

        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};
```




