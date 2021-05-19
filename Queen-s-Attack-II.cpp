int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles)
{
	int X = r_q;
	int Y = c_q;

	int E = n - c_q;
	int W = c_q - 1;
	int N = n - r_q;
	int S = r_q - 1;
	int NE = std::min(N, E);
	int NW = std::min(N, W);
	int SE = std::min(S, E);
	int SW = std::min(S, W);

	for (vector<int> OB : obstacles)
	{
		if (OB[0] == X)
		{
			if (OB[1] > Y  &&  OB[1] - Y - 1 < E)
				E = OB[1] - Y - 1;
			else if (OB[1] < Y && Y - OB[1] - 1 < W)
				W = Y - OB[1] - 1;
		}
		else if (OB[1] == Y)
		{
			if (OB[0] > X && OB[0] - X - 1 < N)
				N = OB[0] - X - 1;
			else if (OB[0] < X && X - OB[0] - 1 < S)
				S = X - OB[0] - 1;
		}
		else if (OB[0] - X == OB[1] - Y && OB[0] - X > 0 && OB[0] - X - 1 < NE)
		{
			NE = OB[0] - X - 1;
		}
		else if (X - OB[0] == Y - OB[1] && X - OB[0] > 0 && X - OB[0] - 1 < SW)
		{
			SW = X - OB[0] - 1;
		}
		else if (OB[0] - X == -(OB[1] - Y) && OB[0] - X > 0 && OB[0] - X - 1 < NW)
		{
			NW = OB[0] - X - 1;
		}
		else if (X - OB[0] == -(Y - OB[1]) && X - OB[0] > 0 && X - OB[0] - 1 < SE)
		{
			SE = X - OB[0] - 1;
		}
	}

	return (N + S + W + E + NE + NW + SE + SW);
}

