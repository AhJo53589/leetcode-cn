


//////////////////////////////////////////////////////////////////////////
#define _TEST_OUTPUT_ 1
class Solution {
public:
	int getWerewolfTarget()
	{
		if (bearId[1] != -1 && isAlive[bearId[0]]) return bearId[0];

		int target = -1;
		int tempC = 0;
		for (auto n : teamV)
		{
#if _TEST_OUTPUT_
			//cout << "���[" << n << "] = " << credibility[n] << endl;
#endif
			if (isAlive[n] && tempC < credibility[n])
			{
				target = n;
				tempC = credibility[n];
			}
		}
		return target;
	}

	int getVillagerTarget()
	{
		int c = 100;
		int target = -1;
		for (int i = 0; i < players.size(); i++)
		{
			if (!isAlive[i]) continue;
#if _TEST_OUTPUT_
			//cout << "���[" << i << "] = " << credibility[i] << endl;
#endif
			if (c > credibility[i])
			{
				c = credibility[i];
				target = i;
			}
		}
		return target;
	}

	void check()
	{
		if (cntW > cntV)
		{
			gameOver = true;
			winner = false;
		}
		if (cntW == 0)
		{
			gameOver = true;
			winner = true;
		}
	}

	void updateOpposite(int n)
	{
		int c = -1;
		if (credibility[n] == 100) c = 0;
		if (credibility[n] == 0) c = 100;
		if (c == -1) return;

		for (auto& p : opposite[n])
		{
			if (credibility[p] == c) continue;
			credibility[p] = c;
			updateOpposite(p);
		}
	}

	vector<int> getNextSeat(int n)
	{
		vector<int> dd = { 1, 11 };
		vector<int> ret;
		for (auto d : dd)
		{
			int nxt = n;
			do
			{
				nxt = (nxt + d) % players.size();
			} while (!isAlive[nxt]);
			ret.push_back(nxt);
		}
		return ret;
	}

	void actBear()
	{
		if (!isAlive[bearId[0]]) return;
#if _TEST_OUTPUT_
		cout << "Bear" << endl;
#endif

		credibility[bearId[0]] = 100;
		updateOpposite(bearId[0]);

		bool findW = false;
		auto nxt = getNextSeat(bearId[0]);
		for (auto n : teamW)
		{
			if (nxt[0] == n || nxt[1] == n)
			{
				findW = true;
				if (credibility[nxt[0]] == 100)
				{
					credibility[nxt[1]] = 0;
					updateOpposite(nxt[1]);
				}
				else if (credibility[nxt[1]] == 100)
				{
					credibility[nxt[0]] == 0;
					updateOpposite(nxt[0]);
				}
				else
				{
					credibility[nxt[0]] = (credibility[nxt[0]] == 1) ? 1 : credibility[nxt[0]] / 2;
					credibility[nxt[1]] = (credibility[nxt[1]] == 1) ? 1 : credibility[nxt[1]] / 2;
					opposite[nxt[0]].push_back(nxt[1]);
					opposite[nxt[1]].push_back(nxt[0]);
				}
			}
		}
		if (!findW)
		{
			credibility[nxt[0]] = 100;
			updateOpposite(nxt[0]);
			credibility[nxt[1]] = 100;
			updateOpposite(nxt[1]);
		}
	}

	void actHunter(int n, bool isDay)
	{
#if _TEST_OUTPUT_
		cout << "Hunter" << endl;
#endif
		credibility[n] = 100;
		updateOpposite(n);
		hunterKillId = getVillagerTarget();
	}

	void actDied(int n, bool isDay)
	{
#if _TEST_OUTPUT_
		string str = "�� " + to_string(daynum) + " �� ";
		str += (isDay) ? "����" : "����";
		cout << str << "\t����: " << n << endl;
#endif

		if (!(players[n] == "idiot" && isDay))
		{
			isAlive[n] = 0;
			for (auto p : teamV) cntV -= (p == n);
			for (auto p : teamW) cntW -= (p == n);
			check();
			if (gameOver) return;
		}
		else
		{
			cout << "Idiot" << endl;
		}

		if (players[n] == "hunter")
		{
			actHunter(n, isDay);
			return;
		}

		if (!isDay)	// night
		{
			credibility[n] = 100;
			updateOpposite(n);
		}
		else	// day
		{
			if (players[n] == "idiot")
			{
				credibility[n] = 100;
				updateOpposite(n);
			}
		}
	}

	void processDay()
	{
		actBear();
		if (hunterKillId != -1)
		{
			actDied(hunterKillId, false);
			hunterKillId = -1;
		}
		int dead = getVillagerTarget();
		actDied(dead, true);
		if (hunterKillId != -1)
		{
			actDied(hunterKillId, true);
			hunterKillId = -1;
		}
	}

	void processNight()
	{
		int dead = getWerewolfTarget();
		actDied(dead, false);
	}

	bool canVillagersWin(vector<string>& p, vector<int>& c)
	{
		players = p;
		credibility = c;
		hunterKillId = -1;
		cntV = 8;
		cntW = 4;
		daynum = 0;
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

		gameOver = false;
		while (!gameOver)
		{
			daynum++;
			processNight();
			if (gameOver) break;
			processDay();
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
	int hunterKillId;
	int cntV;
	int cntW;
	int daynum;
	bool winner;
	bool gameOver;
};


//////////////////////////////////////////////////////////////////////////
bool _solution_run(vector<string>& players, vector<int>& credibility)
{
	Solution sln;
	return sln.canVillagersWin(players,credibility);
}

//#define USE_SOLUTION_CUSTOM
//bool _solution_custom(TestCases &tc)
//{
//}

//////////////////////////////////////////////////////////////////////////
vector<string> _get_test_cases_string()
{
	return {};
}

#define USE_GET_TEST_CASES_FILESTREAM
string _get_test_cases_filestream()
{
	return "../../problems/werewolves-of-leetcode/tests.txt";
}

