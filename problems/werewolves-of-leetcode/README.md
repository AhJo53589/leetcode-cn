# `（简单）` [100269.werewolves-of-leetcode 狼人杀模拟器](https://leetcode-cn.com/problems/werewolves-of-leetcode/)

[contest](https://leetcode-cn.com/contest/sf-2020/problems/werewolves-of-leetcode/)

### 题目描述
<p>小李的同事们很喜欢玩狼人杀，每次都找他当法官。小李觉得很累，决定写一个程序来跑出狼人杀的结果。</p>
<p>狼人杀是一个桌游。常见局由 12 名玩家和 1 名法官组成。12 名玩家坐成一个圈。每个玩家在游戏开始时随机抽取一张角色卡牌，只能知道自己的身份。 玩家分为两个阵营，狼人和村民。</p>
<ul>
	<li>狼人的胜利条件是 狼人阵营的玩家数 &gt;= 村民阵营的玩家数</li>
	<li>村民的胜利条件是 所有狼人出局</li>
</ul>

<p><strong>游戏过程</strong></p>
<p>游戏分为夜晚和白天。</p>
<ol>
	<li>(夜晚) 拿到狼人身份的玩家睁眼，其他人闭眼。狼人们商量后选择一名玩家击杀；</li>
	<li>(白天) 所有人睁眼；</li>
	<li>法官宣布昨晚出局的玩家，以及熊是否咆哮了；</li>
	<li>出局的玩家离开游戏，发动技能（如果有）；</li>
	<li>法官检查胜利条件，如果任何一个满足则结束游戏；</li>
	<li>在场玩家进行一轮发言，并票选最可疑的玩家出局；</li>
	<li>被选中的玩家离开游戏，发动技能（如果有）；</li>
	<li>法官检查胜利条件，如果任何一个满足则结束游戏；</li>
	<li>重复 1；</li>
</ol>

<p><strong>游戏角色</strong></p>
<p>【村民阵营】x8</p>
<ul>
	<li>村民(villager, 下称<code>"vil"</code>) x5：没有特殊技能</li>
	<li>猎人(<code>"hunter"</code>) x1：技能是在出局时（被投票或被狼人击杀）可以向所有人亮出底牌选择带走一名玩家</li>
	<li>白痴(<code>"idiot"</code>) x1：技能是在白天<strong>被投票出局</strong>后自动亮出底牌并且不出局</li>
	<li>驯熊人(bear tamer, 下称<code>"bear"</code>) x1：（简称熊）每天夜里，如果<strong>相邻</strong>两名存活玩家有任何一个是狼人，熊会发出咆哮。如果驯熊人已经死亡，则这一局熊不再咆哮。驯熊人如果当晚被杀，熊也不会咆哮。（相邻指向左找第一名存活玩家和向右找第一名存活玩家，当晚被杀的玩家也视为死亡）</li>
</ul>

<p>【狼人阵营】x4</p>
<ul>
	<li>狼人(werewolf, 下称<code>"ww"</code>) x4：可以知道同伴，但不知道好人的具体角色。</li>
</ul>

<p>对于所有人：</p>
<ul>
	<li>白天可以投票</li>
	<li>除了发言的环节，玩家不能发言或者交换信息</li>
</ul>

<p><strong>模拟器设定</strong></p>
<ul>
	<li>我们用 <em><strong>c</strong></em> 来模拟每名玩家在游戏开始时在他人眼中的可信度。0 &lt; <em><strong>c</strong></em> &lt; 100 。越小则越像狼人</li>
	<li>狼人只击杀非狼人，并且在场玩家知晓这点</li>
	<li>在投票环节，<em><strong>c </strong></em>最低的玩家出局。如果有多个目标，则座位号小号出局。</li>
	<li>狼人优先击杀熊，其他时候击杀 <em><strong>c</strong></em> 最高的好人（村民阵营），如果有多个目标，则击杀座位号小号。</li>
	<li>玩家的 <em><strong>c </strong></em>变成 0 或者 100 表示已知身份： 铁狼 或者 铁好人</li>
	<li>玩家的 <em><strong>c </strong></em>会根据<strong>大家获取到的信息</strong>发生改变，<strong>所有人看到的可信度 c 一起更新。</strong><em>注意，改变的时机需要遵守游戏过程</em>：
	<ol>
		<li>猎人出局或白痴被投票出局时一定发动技能，使 ta 的&nbsp;<em><strong>c</strong></em> 变为 100；猎人会射杀 <em><strong>c</strong></em> 最低的玩家，如果有多个目标，则射杀座位号小号</li>
		<li>第一天发言时，如果驯熊人依然存活，驯熊人会公布身份，使 ta 的 <em><strong>c</strong></em> 变为 100（在模拟器中狼不会假装自己是熊）
		<ol>
			<li>如果熊咆哮了，人们开始怀疑其左右的未知身份玩家，这使他们的 <em><strong>c</strong></em> 变为原来的一半 (向下取整, 如果原来是 1 则不变 )</li>
			<li>如果熊咆哮了且左右的在局一方为铁好人，则另一方成为铁狼；如果其中一方后来被发现是铁好人，人们也会更新另一方的 <em><strong>c</strong></em>&nbsp;</li>
			<li>如果熊在场且没有咆哮，则左右的在场玩家成为铁好人</li>
		</ol>
		</li>
		<li>如果驯熊人在第一次发言前死亡，则场上玩家不知道其位置，也无法利用熊的咆哮信息</li>
		<li>如果玩家在夜间死亡，则该离场的玩家也被认为是铁好人</li>
	</ol>
	</li>
</ul>

<p><strong>输入：</strong></p>
<p><code>players</code>：一个长度为 12 的 string 数组，坐标代表座位，字符串代表底牌, 有以下可能：<code>"vil"</code>,&nbsp;<code>"hunter"</code>,&nbsp;<code>"idiot"</code>,&nbsp;<code>"bear"</code>&nbsp;和&nbsp;<code>"ww"</code>。 其中&nbsp;<code>"vil"</code>&nbsp;会出现 5 次，&nbsp;<code>"ww"</code>会出现 4 次， 其他每个都是 1 次。 坐标&nbsp;<code>0</code>&nbsp;和&nbsp;<code>11</code>&nbsp;也视为相邻。</p>
<p><code>credibility</code>：一个长度为 12 的 int 数组，坐标代表座位，int 代表玩家初始的可信度</p>
<p><strong>输出：</strong></p>
<p>根据模拟器的设定，村民阵营是否能赢</p>
<p><strong>示例 1：</strong></p>
<pre><strong>Input: </strong>players = ["bear","vil","vil","ww","vil","vil","idiot","ww","hunter","ww","ww","vil"], credibility = [9,55,62,74,43,70,13,23,15,78,61,66]
<strong>Output: </strong>false</pre>

<p><strong>解释：</strong></p>
<p>第一天夜晚，狼人击杀玩家&nbsp;<strong>5</strong>，熊没有咆哮。</p>
<p>第二天白天，玩家&nbsp;<strong>0</strong>&nbsp;公布自己熊的身份。玩家&nbsp;<strong>1</strong>&nbsp;和玩家&nbsp;<strong>11</strong>&nbsp;成为 铁好人。看上去最可疑的玩家<strong>&nbsp;6</strong>&nbsp;被投出，但是因为是 白痴 身份，并没有出局。玩家&nbsp;<strong>6</strong>&nbsp;成为 铁好人。</p>
<p>第二天夜晚，狼人击杀玩家&nbsp;<strong>0</strong>&nbsp;驯熊人。熊没有咆哮。</p>
<p>第三天白天，身份最低的玩家&nbsp;<strong>8</strong>&nbsp;猎人被投票出局。猎人选择带走场上可信度最低的玩家&nbsp;<strong>7</strong>。</p>
<p>第三天夜晚，狼人击杀身份最高的玩家&nbsp;<strong>1 </strong>村民。</p>
<p>第四天白天，身份最低的玩家&nbsp;<strong>4 </strong>村民被投票出局。</p>
<p>第四天夜晚，狼人击杀玩家&nbsp;<strong>6 </strong>白痴, 此时场上狼人数量等于好人数量，狼人胜利。</p>
<p>&nbsp;</p>
<p><strong>示例 2：</strong></p>
<pre><strong>Input: </strong>players = ["vil", "vil", "vil", "ww", "vil", "ww", "ww", "vil", "ww", "bear", "hunter", "idiot"], credibility = [81, 71, 88, 31, 34, 40, 70, 94, 73, 79, 98, 48]
<strong>Output: </strong>true</pre>

<p><strong>解释：</strong></p>
<p>第一回合猎人出局，熊咆哮了，但由于熊没有跳身份，对于猎人是无效信息，不能更新 c ，猎人击杀 3 号位玩家狼人。本回合投票投出 11 号白痴，白痴亮出身份牌， c 变为 100 。</p>
<p>&nbsp;</p>
<p><strong>示例 3：</strong></p>
<pre><strong>Input: </strong>players = ["vil","ww","bear","hunter","ww","idiot","vil","vil","ww","vil","ww","vil"], credibility = [45,67,32,25,1,27,99,85,3,54,3,25]
<strong>Output: </strong>true</pre>

<p><strong>解释：</strong></p>
<p>最后一轮投票，猎人被投出，发动技能。由于此时猎人已经是铁好人，通过第一轮熊咆哮可以得出 1 号位是铁狼，所以本轮猎人击杀 1 号位狼人，游戏结束，村民胜利。</p>
<p>&nbsp;</p>
<p>&nbsp;</p>

---
### 思路
```

```



### 答题
``` C++
class Solution {
public:
	void printPlayerStatus()
	{
		cout << "\t";
		for (int n = 0; n < players.size(); n++)
		{
			cout << "[" << setiosflags(ios::right) << setw(2) << n << "]";
		}
		cout << endl;
		cout << "[P] = \t";
		for (int n = 0; n < players.size(); n++)
		{
			if (isAlive[n])
			{
				cout << setiosflags(ios::right) << setw(3) << players[n][0] << " ";
			}
			else
			{
				cout << "    ";
			}
		}
		cout << endl;
		cout << "[C] = \t";
		for (int n = 0; n < players.size(); n++)
		{
			cout << setiosflags(ios::right) << setw(3) << credibility[n] << " ";
		}
		cout << endl;
	}

	int getWerewolfTarget()
	{
		printPlayerStatus();
		if (bearId[1] != -1 && isAlive[bearId[0]]) return bearId[0];

		int target = -1;
		int c = 0;
		for (auto n : teamV)
		{
			if (!isAlive[n]) continue;
			if (c >= credibility[n]) continue;
			target = n;
			c = credibility[n];
		}
		return target;
	}

	int getVillagerTarget()
	{
		printPlayerStatus();

		int target = -1;
		int c = 100;
		for (int n = 0; n < players.size(); n++)
		{
			if (!isAlive[n]) continue;
			if (c <= credibility[n]) continue;
			target = n;
			c = credibility[n];
		}
		return target;
	}

	bool checkGameOver()
	{
		if (cntW >= cntV)
		{
			winner = false;
			return true;
		}
		if (cntW == 0)
		{
			winner = true;
			return true;
		}
		return false;
	}

	void updateOpposite(int n, int c)
	{
		credibility[n] = c;
		if (c != 100) return;
		int rc = 0;

		for (auto& p : opposite[n])
		{
			if (credibility[p] == rc) continue;
			updateOpposite(p, rc);
		}
	}

	vector<int> getBeside(int n, int killId)
	{
		vector<int> dd = { 1, 11 };
		vector<int> ret;
		for (auto d : dd)
		{
			int nxt = n;
			do
			{
				nxt = (nxt + d) % players.size();
			} while (!isAlive[nxt] || nxt == killId);
			ret.push_back(nxt);
		}
		return ret;
	}

	bool actBearRoar(int killId, vector<int>& nxt)
	{
		int n = bearId[0];
		if (killId == bearId[0]) return false;
		if (!isAlive[n]) return false;

		nxt = getBeside(n, killId);
		for (auto p : teamW)
		{
			if (nxt[0] != p && nxt[1] != p) continue;
			return true;
		}
		return false;
	}

	void actBearTalk(bool bearRoar, vector<int>& nxt)
	{
		int n = bearId[0];
		if (daynum == 2)
		{
			cout << "\t\t\t\tBear talk" << endl;
			bearId[1] = n;
			updateOpposite(n, 100);
		}

		if (!bearRoar)
		{
			updateOpposite(nxt[0], 100);
			updateOpposite(nxt[1], 100);
			return;
		}

		for (int i = 0; i < nxt.size(); i++)
		{
			int p1 = (i == 0) ? nxt[0] : nxt[1];
			int p2 = (i != 0) ? nxt[0] : nxt[1];
			opposite[p1].push_back(p2);

			int c = -1;
			c = (credibility[p1] == 100) ? credibility[p1] : c;
			if (c == -1)
			{
				credibility[p1] = (credibility[p1] == 1) ? 1 : credibility[p1] / 2;
			}
			else
			{
				int rc = 0;
				updateOpposite(p2, rc);
			}
		}
	}

	void actHunter(int n)
	{
		updateOpposite(n, 100);

		int hunterKillId = getVillagerTarget();
		cout << "\t\t\t\tHunter kill = " << hunterKillId << endl;
		onDead(hunterKillId);
	}

	void actIdiot(int n)
	{
		updateOpposite(n, 100);
		cout << "\t\t\t\tIdiot will not be voted out" << endl;
	}

	void onDead(int n)
	{
		cout << "\t\t\t\tPlayer[" << n << "] dead" << endl;
		isAlive[n] = 0;
		for (auto p : teamV) cntV -= (p == n);
		for (auto p : teamW) cntW -= (p == n);
	}

	void onKilled(int n)
	{
		onDead(n);

		if (players[n] == "hunter")
		{
			actHunter(n);
		}
		else
		{
			updateOpposite(n, 100);
		}
	}

	void onVoted(int n)
	{
		if (players[n] == "idiot")
		{
			actIdiot(n);
		}
		else
		{
			onDead(n);
		}

		if (players[n] == "hunter")
		{
			actHunter(n);
		}
	}

	bool canVillagersWin(vector<string>& p, vector<int>& c)
	{
		players = p;
		credibility = c;
		cntV = 8;
		cntW = 4;
		daynum = 1;
		isAlive = vector<int>(players.size(), 1);
		bearId = vector<int>(2, -1);
		opposite = vector<vector<int>>(players.size(), vector<int>());

		for (int i = 0; i < players.size(); i++)
		{
			if (players[i] == "vil" || players[i] == "hunter" || players[i] == "idiot" || players[i] == "bear")
			{
				teamV.push_back(i);
				bearId[0] = (players[i] == "bear") ? i : bearId[0];
			}
			else if (players[i] == "ww")
			{
				teamW.push_back(i);
			}
		}

		bool gameOver = false;
		while (!gameOver)
		{
			cout << endl << "=== Night " + to_string(daynum) << " ===" << endl;

			int killId = getWerewolfTarget();
			vector<int> beside;
			bool bearRoar = actBearRoar(killId, beside);
			cout << "1. Close Eyes \t\t\tKill = " << killId << endl;

			daynum++;
			cout << endl << "=== Day " + to_string(daynum) << " ===" << endl;
			cout << "2. Open Eyes" << endl;

			cout << "3. Announce \t\t\tBear roar: " << boolalpha << bearRoar << endl;

			cout << "4. Kill";
			onKilled(killId);

			gameOver = checkGameOver();
			cout << "5. Check \t\t\tGame over: " << boolalpha << gameOver << endl;
			if (gameOver) break;

			cout << "6. Talk \t\t\tBear roar effect: " << boolalpha << (bool)isAlive[bearId[0]] << endl;
			if (isAlive[bearId[0]])
			{
				actBearTalk(bearRoar, beside);
			}

			int voteId = getVillagerTarget();
			cout << "7. Vote \t\t\tVote = " << voteId << endl;
			onVoted(voteId);

			gameOver = checkGameOver();
			cout << "8. Check \t\t\tGame over: " << boolalpha << gameOver << endl;
			if (gameOver) break;
		}
		return winner;
	}

private:
	vector<string> players;
	vector<int> credibility;
	vector<int> isAlive;
	vector<vector<int>> opposite;
	vector<int> teamV;
	vector<int> teamW;
	vector<int> bearId;
	int cntV;
	int cntW;
	int daynum;
	bool winner;
};
```




