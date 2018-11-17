/******************
 *                *
 *  ¿®∫≈∆•≈‰Œ Ã‚  *
 *                *
 ******************/
#include <iostream>
using namespace std;

int isMatched(char left, char right);
int isParenthesesBalanced(char exp[]);

const int maxSize = 1000;

int main()
{
	char exp[maxSize];
	cin >> exp;
	if (isParenthesesBalanced(exp))
		cout << "isMatched" << endl;
	else
		cout << "isNOTMatched" << endl;
	return 0;
}

int isMatched(char left, char right)
{
	if (left == '('&&right == ')')
		return 1;
	else if (left == '['&&right == ']')
		return 1;
	else if (left == '{'&&right == '}')
		return 1;
	else
		return 0;
}

int isParenthesesBalanced(char exp[])
{
	char s[maxSize];
	int top = -1;
	for (int i = 0;exp[i] != '\0';i++)
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s[++top] = exp[i];
		if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if (top == -1)
				return 0;
			char left = s[top--];
			if (!isMatched(left, exp[i]))
				return 0;
		}
	}
	if (top > -1)
		return 0;
	return 1;
}