#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

#define N 101

long long dp[N][N];

int main(void)
{
	int n;
	long long ans = 0;

	scanf("%d", &n);
	for (int i = 1; i <= 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][8];
			else
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
			dp[i][j] %= 1000000000;
		}
	}

	for (int i = 0; i < 10; i++)
		ans += dp[n][i];
	ans %= 1000000000;
	printf("%llu\n", ans);
	return 0;
}