/*#include<iostream>
using namespace std;
int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
	{
		return 1;
	}
	if (a > 20 || b > 20 || c > 20)
	{
		return w(20, 20, 20);
	}
	if (a < b&&b < c)
	{
		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
	cout << w(1, 1, 1) << endl;
	cout << w(2, 2, 2) << endl;
	cout << w(10, 4, 6) << endl;
	cout << w(50, 50, 50) << endl;
	cout << w(-1, 7, 18) << endl;
	cout << w(-1, -1, -1) << endl;
	system("pause");
}
*/




//
//#include<stdio.h> 
//#pragma warning(disable:4996)
//int main() {
//	int a, b, c, i, j, k, w[20][20][20];
//	for (i = 0; i < 20; i++)
//		for (j = 0; j < 20; j++)
//			for (k = 0; k < 20; k++)
//			{
//				if (i == 0 || j == 0 || k == 0)
//					w[i][j][k] = 1;
//				else if (i < j&&j < k)
//					w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
//				else 
//					w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
//			}
//	
//	while (scanf("%d%d%d", &a, &b, &c) != -1, a != -1 || b != -1 || c != -1)
//			{
//				if (a <= 0 || b <= 0 || c <= 0)
//					printf("w(%d, %d, %d) = 1\n", a, b, c);
//				else if (a >= 20 || b >= 20 || c >= 20) 
//					printf("w(%d, %d, %d) = 1048576\n", a, b, c); 
//				else 
//					printf("w(%d, %d, %d) = %d\n", a, b, c, w[a][b][c]);
//			} 
//	return 0;
//}


//
//#include <stdio.h> 
//#include <limits.h>  
//#include<iostream>
//using namespace std;
//#pragma warning(disable:4996)
//const int MAX_N = 21; 
//int W[MAX_N][MAX_N][MAX_N];  
//int getValue(int a, int b, int c)
//{  
//	if (a <= 0 || b <= 0 || c <= 0)
//		return W[0][0][0] = 1;  
//	if (a >= MAX_N || b >= MAX_N || c >= MAX_N)   
//		return getValue(MAX_N-1, MAX_N-1, MAX_N-1);   
//	if (W[a][b][c]) 
//		return W[a][b][c];   
//	if (a < b && b < c)  
//	{  
//		W[a][b-1][c-1] = getValue(a, b-1, c-1);  
//		W[a][b][c-1] = getValue(a, b, c-1);  
//		W[a][b-1][c] = getValue(a, b-1, c);   
//		return W[a][b][c] = W[a][b][c-1] + W[a][b-1][c-1] - W[a][b-1][c];  
//	}  
//	W[a-1][b-1][c-1] = getValue(a-1, b-1, c-1); 
//	W[a-1][b-1][c] = getValue(a-1, b-1, c);
//	W[a-1][b][c-1] = getValue(a-1, b, c-1);  
//	W[a-1][b][c] = getValue(a-1, b, c);  
//	return W[a][b][c] = W[a-1][b][c] + W[a-1][b-1][c]  + W[a-1][b][c-1] - W[a-1][b-1][c-1]; 
//} 
//int main()
//{ 
//	int a, b, c; 
//while (~scanf("%d %d %d", &a, &b, &c)&& !(a == -1 && b == -1 && c == -1))  
//{ 
//	printf("w(%d, %d, %d) = %d\n", a, b, c, getValue(a, b, c)); 
//} 
//system("pause");
//return 0; 
//}








#include <stdio.h> 
#include <limits.h>  
#include<iostream>
using namespace std;
const int MAX_N = 20;
#pragma warning(disable:4996)
int W[MAX_N][MAX_N][MAX_N];
int getValue(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return W[0][0][0] = 1;
	if (a >MAX_N || b > MAX_N || c > MAX_N)
		return getValue(MAX_N , MAX_N , MAX_N );
	if (W[a][b][c])
		return W[a][b][c];
	if (a < b && b < c)
	{
		W[a][b - 1][c - 1] = getValue(a, b - 1, c - 1);
		W[a][b][c - 1] = getValue(a, b, c - 1);
		W[a][b - 1][c] = getValue(a, b - 1, c);
		W[a][b][c] = W[a][b][c - 1] + W[a][b - 1][c - 1] - W[a][b - 1][c];
		return W[a][b][c];
	}
	W[a - 1][b - 1][c - 1] = getValue(a - 1, b - 1, c - 1);
	W[a - 1][b - 1][c] = getValue(a - 1, b - 1, c);
	W[a - 1][b][c - 1] = getValue(a - 1, b, c - 1);
	W[a - 1][b][c] = getValue(a - 1, b, c);
	W[a][b][c] = W[a - 1][b][c] + W[a - 1][b - 1][c] + W[a - 1][b][c - 1] - W[a - 1][b - 1][c - 1];
	return W[a][b][c];
}
int main()
{
	int a, b, c;
	while (~scanf("%d %d %d", &a, &b, &c) && !(a == -1 && b == -1 && c == -1))
	{
		printf("w(%d, %d, %d) = %d\n", a, b, c, getValue(a, b, c));
	}
	system("pause");
	return 0;
}

//
// 