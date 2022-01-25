#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int den)
{
	if (numerator == 0) return "0";

	string res;
	res += ((numerator < 0) ^ (den < 0)) ? "-" : "";
	long num = abs(numerator);
	den = abs(den);
	res += to_string(num / den);
	num %= den;
	if (num)
	{
		res += '.';
		unordered_map<long, int> decimal;
		while (num)
		{
			if (decimal.count(num))
			{
				res.insert(decimal[num], "(");
				res += ")";
				break;
			}
			decimal[num] = res.length();
			num *= 10;
			res += to_string(num / den);
			num %= den;
		}
	}
	return res;
}

int main(void)
{

	return 0;
}