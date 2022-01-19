#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> ones = { "One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
vector<string> tens = { "Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
vector<string> powers = { "Thousand","Million","Billion" };

string numberToWords(int num) {
    if (num == 0) return "Zero";
    if (!(num / 20)) return ones.at(num - 1);
    string result("");
    for (int i = 0; num > 0;) {
        if (num % 1000) {
            if (i / 3 && num) result = powers.at(i / 3 - 1) + ((result.empty()) ? "" : " " + result);
            int j = 3;
            while (j-- && num) {
                int n = num % 10;
                if (n) {
                    if (i % 3 == 1)
                        result = tens.at(n - 1) + ((result.empty()) ? "" : " " + result);
                    else if (i % 3 == 2 && n) result = ones.at(n - 1) + " Hundred" + ((result.empty()) ? "" : " " + result);
                    else {
                        if (num % 100 < 20) {
                            result = ones.at((num % 100) - 1) + ((result.empty()) ? "" : " " + result);
                            num /= 10, i++, j--;
                        }
                        else
                            result = ones.at(n - 1) + ((result.empty()) ? "" : " " + result);
                    }
                }
                num /= 10, i++;
            }
        }
        else
            num /= 1000, i += 3;
    }
    return result;
}

int main() {
    int n;
    while (cin >> n) {
        cout << numberToWords(n) << "\n\n";
    }

    return 0;
}
