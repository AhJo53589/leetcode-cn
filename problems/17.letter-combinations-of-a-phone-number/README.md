# `（中等）`  [17.letter-combinations-of-a-phone-number 电话号码的字母组合](https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/)

### 题目描述
<p>给定一个仅包含数字&nbsp;<code>2-9</code>&nbsp;的字符串，返回所有它能表示的字母组合。</p>

<p>给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。</p>

<p><img style="width: 200px;" src="https://assets.leetcode-cn.com/aliyun-lc-upload/original_images/17_telephone_keypad.png"></p>

<p><strong>示例:</strong></p>

<pre><strong>输入：</strong>"23"
<strong>输出：</strong>["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
</pre>

<p><strong>说明:</strong><br>
尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。</p>


---
### 思路
```
每次都是用上一次叠加过的结果再次叠加。
```

### 答题
``` C++
vector<string> letterCombinations(string digits)
{
	if (digits.empty()) return {};
	vector<string> data{ "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> res;
	res.push_back("");

	for (int i = 0; i < digits.size(); i++)
	{
		int d = digits[i] - '2';
		int len = res.size();
		for (int j = 0; j < len; j++)
		{
			for (auto m : data[d])
			{
				res.push_back(res[j] + m);
			}
		}
		res.erase(res.begin(), res.begin() + len);
	}
	return res;
}
```

