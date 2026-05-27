#include <iostream>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string lab5(string text) {
	vector<string> egnoreList = { " ", "\n", "\t", "\r" };

	string str1, str2, result;
	bool isStr1 = true;

	for (int i = 0; i < text.size(); i++) {
		if (find(egnoreList.begin(), egnoreList.end(), string(1, text[i])) == egnoreList.end()) {
			if (isStr1)
				str1 += text[i];
			else
				str2 += text[i];
		}
		else {
			if (isStr1) {
				str1.insert(0, string(1, text[i]));
			}
			else {
				result += str2;
				result += str1;
				result += string(1, text[i]);
				str2 = "";
				str1 = "";
			}
			isStr1 = !isStr1;
		}
	}
	result += str2;
	result += str1;

	return result;
}


int main()
{
	ifstream file("file.txt");

	stringstream buf;
	buf << file.rdbuf();

	cout << lab5(buf.str());
}
