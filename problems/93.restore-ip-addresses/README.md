# `（中等）`  [93.restore-ip-addresses 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)

### 题目描述
<p>给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> "25525511135"
<strong>输出:</strong> <code>["255.255.11.135", "255.255.111.35"]</code></pre>


---
### 思路
```
```

[发布的题解](https://leetcode-cn.com/problems/restore-ip-addresses/solution/93-by-ikaruga/)

### 答题
``` C++
vector<string> restoreIpAddresses(string &s, int id, int iBegin)
{
	int len = s.length();
	vector<string> ret;
	for (int i = iBegin; i < iBegin + 3; i++)
	{
		if (id == 0 && i != len - 1) continue;
		if ((len - i - 1) > (id * 3)) continue;
		if ((len - i - 1) < (id * 1)) continue;
		
		string sub = s.substr(iBegin, i - iBegin + 1);
		int ip = stoi(sub);
		if (ip < 0 || ip > 255) continue;
		if (to_string(ip) != sub) break;

		if (id == 0)
		{
			ret.push_back(sub);
		}
		vector<string> vs = restoreIpAddresses(s, id - 1, i + 1);
		for (auto &v : vs)
		{
			ret.push_back(sub + "." + v);
		}
	}
	return ret;
}

vector<string> restoreIpAddresses(string s)
{
	return restoreIpAddresses(s, 3, 0);
}
```

### 其它
``` C++
```

