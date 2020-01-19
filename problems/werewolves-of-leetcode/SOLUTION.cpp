
class Solution2 {
public:
	vector<int> die;
	vector<string> a;
	vector<int> w;
	int get(string s) {
		if (s[0] == 'v') return 0;
		if (s[0] == 'h') return 1;
		if (s[0] == 'i') return 2;
		if (s[0] == 'b') return 3;
		if (s[0] == 'w') return 4;
		return -1;
	}
	int check() {
		int b = 0, g = 0;
		for (int i = 0; i < 12; ++i) {
			if (die[i]) continue;
			if (get(a[i]) == 4) b++;
			else g++;
		}
		if (b == 0) return 2;
		if (b >= g) return 1;
		return 0;
	}
	int wolf_find() {
		int cur = -1, mx = -1;
		for (int i = 0; i < 12; ++i) {
			if (die[i]) continue;
			if (get(a[i]) == 4) continue;
			if (w[i] > mx) mx = w[i], cur = i;
		}
		return cur;
	}
	int hunter_find() {
		int cur = -1, mx = 101;
		for (int i = 0; i < 12; ++i) {
			if (die[i]) continue;
			if (get(a[i]) == 1) continue;
			if (w[i] < mx) mx = w[i], cur = i;
		}
		return cur;
	}
	int vote_find() {
		int cur = -1, mx = 101;
		for (int i = 0; i < 12; ++i) {
			if (die[i]) continue;
			if (w[i] < mx) mx = w[i], cur = i;
		}
		return cur;
	}
	int get_left(int x) {
		while (1) {
			x = (x + 11) % 12;
			if (!die[x]) return x;
		}
		return -1;
	}
	int get_right(int x) {
		while (1) {
			x = (x + 1) % 12;
			if (!die[x]) return x;
		}
		return -1;
	}
	int l = -1, r = -1, aoao = 0;
	void magic() {
		if (!aoao || l == -1) return;
		if (w[l] == 100) w[r] = 0;
		if (w[r] == 100) w[l] = 0;
	}
	int bear_alive = 1, bear_pos = 0;
	bool know_b = 0;
	int hunter_pos;
	// int hunter_die = 0;
	bool canVillagersWin(vector<string>& players, vector<int>& cred)
	{
		die.resize(12);
		a = players;
		w = cred;
		for (int i = 0; i < 12; ++i) if (get(a[i]) == 3) bear_pos = i;
		for (int ca = 1;; ++ca)
		{
			cout << "case : " << ca << endl;
			if (bear_alive && ca != 1) {
				int killed = bear_pos;
				die[bear_pos] = 1;
				bear_alive = 0;
				w[bear_pos] = 100;
				cout << "killed by wolf : " << bear_pos << endl;
			}
			else {
				int killed = wolf_find();
				if (killed == bear_pos) bear_alive = 0;
				die[killed] = 1;
				w[killed] = 100;
				magic();
				cout << "killed by wolf : " << killed << endl;
				if (l == -1) {
					l = get_left(bear_pos);
					r = get_right(bear_pos);
				}
				if (get(a[killed]) == 1) {
					int tmp = hunter_find();
					die[tmp] = 1;
					if (tmp == bear_pos) bear_alive = 0;
					cout << "killed by hunter : " << tmp << endl;
				}
			}
			magic();
			if (check()) return check() == 2;

			if (bear_alive) {
				cout << "bear!!" << endl;
				know_b = 1;
				w[bear_pos] = 100;
				magic();

				if (get(a[l]) == 4 || get(a[r]) == 4) aoao = 1;
				if (get(a[l]) < 4 && get(a[r]) < 4) w[l] = w[r] = 100;
				else if (w[l] == 100) w[r] = 0;
				else if (w[r] == 100) w[l] = 0;
				else {
					if (w[l] == 1) w[l] = 1;
					else w[l] /= 2;
					if (w[r] == 1) w[r] = 1;
					else w[r] /= 2;
				}
			}
			magic();
			for (int i = 0; i < 12; ++i) cout << die[i] << " "; cout << endl;
			for (int i = 0; i < 12; ++i) cout << w[i] << " "; cout << endl;
			int tmp = vote_find();
			cout << "vote :" << tmp << endl;
			if (get(a[tmp]) == 2) w[tmp] = 100;
			else die[tmp] = 1;
			if (tmp == bear_pos) bear_alive = 0;
			magic();
			if (get(a[tmp]) == 1) {
				w[tmp] = 100;
				magic();
				int tmp2 = hunter_find();
				die[tmp2] = 1;
				if (tmp2 == bear_pos) bear_alive = 0;
				cout << "killed by hunter : " << tmp2 << endl;
			}
			for (int i = 0; i < 12; ++i) cout << die[i] << " "; cout << endl;
			if (check()) return check() == 2;
		}
		return 1;
	}
};

//////////////////////////////////////////////////////////////////////////
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

	vector<int> getBeside(int n)
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

	bool actBearRoar(int killId, vector<int>& nxt)
	{
		int n = bearId[0];
		if (killId == bearId[0]) return false;
		if (!isAlive[n]) return false;

		nxt = getBeside(n);
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

