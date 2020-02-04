# `（中等）` [93.restore-ip-addresses 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)

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
vector<string> restoreIpAddresses(string& s, int remaining, int iBegin)
{
	int len = s.length();
	vector<string> ret;
	for (int i = iBegin; i < iBegin + 3; i++)
	{
		if (remaining == 0 && i != len - 1) continue;	// 如果是最后一位，必须匹配到字符串结尾
		if ((len - i - 1) > (remaining * 3)) continue;	// 根据是第几位，确定在字符串中的可能位置
		if ((len - i - 1) < (remaining * 1)) continue;

		string sub = s.substr(iBegin, i - iBegin + 1);
		int ip = stoi(sub);
		if (ip < 0 || ip > 255) continue;	// 不符合 ip 格式
		if (to_string(ip) != sub) break;	// 处理 stoi(“01”) => 1 的特殊情况

		if (remaining == 0)
		{
			// 最后一位得到合法数字，返回答案
			ret.push_back(sub);
		}
		else
		{
			// 按照当前状态，进一步寻找下一位数字
			vector<string> vs = restoreIpAddresses(s, remaining - 1, i + 1);
			for (auto& v : vs)
			{
				// 只有后续数字合法，vs 不为空，此处的 sub 才能加入答案
				// 因此过滤了不符合的答案
				ret.push_back(sub + "." + v);
			}
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

