#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
	int X = r_q;
	int Y = c_q;

	int E = n - Y;
	int W = Y - 1;
	int N = n - X;
	int S = X - 1;
	int NE = std::min(N, E);
	int NW = std::min(N, W);
	int SE = std::min(S, E);
	int SW = std::min(S, W);

	for (vector<int> OB : obstacles)
	{
		if (OB[0] == X)
		{
			if (OB[1] > Y   &&   OB[1] - Y - 1 < E)
				E = OB[1] - Y - 1;
			else if (OB[1] < Y   &&   Y - OB[1] - 1 < W)
				W = Y - OB[1] - 1;
		}
		else if (OB[1] == Y)
		{
			if (OB[0] > X   &&   OB[0] - X - 1 < N)
				N = OB[0] - X - 1;
			else if (OB[0] < X   &&   X - OB[0] - 1 < S)
				S = X - OB[0] - 1;
		}
		else if (OB[0] - X == OB[1] - Y   &&   OB[0] - X > 0   &&   OB[0] - X - 1 < NE)
		{
			NE = OB[0] - X - 1;
		}
		else if (X - OB[0] == Y - OB[1]   &&   X - OB[0] > 0   &&   X - OB[0] - 1 < SW)
		{
			SW = X - OB[0] - 1;
		}
		else if (OB[0] - X == -(OB[1] - Y)   &&   OB[0] - X > 0   &&   OB[0] - X - 1 < NW)
		{
			NW = OB[0] - X - 1;
		}
		else if (X - OB[0] == -(Y - OB[1])   &&   X - OB[0] > 0   &&   X - OB[0] - 1 < SE)
		{
			SE = X - OB[0] - 1;
		}
	}

	return (N + S + W + E + NE + NW + SE + SW);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string second_multiple_input_temp;
    getline(cin, second_multiple_input_temp);

    vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

    int r_q = stoi(second_multiple_input[0]);

    int c_q = stoi(second_multiple_input[1]);

    vector<vector<int>> obstacles(k);

    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        string obstacles_row_temp_temp;
        getline(cin, obstacles_row_temp_temp);

        vector<string> obstacles_row_temp = split(rtrim(obstacles_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int obstacles_row_item = stoi(obstacles_row_temp[j]);

            obstacles[i][j] = obstacles_row_item;
        }
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}
