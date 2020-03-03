#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<char> read_stdin();
void print_reverse(vector<char>& names);

int main(){
	vector<char> names = read_stdin();
	print_reverse(names);
	return 0;
}

vector<char> read_stdin() {
	char c;
	vector<char> _vec;
	string line;
	getline(cin, line);
	istringstream iss(line);
	while (iss >> c) {
		_vec.push_back(c);
	}
	return _vec;
}

void print_reverse(vector<char>& names) {
	vector<char> result;
	bool is_first = true;
	for (int i = names.size() - 1; i >= 0; --i) {
		if (names[i] != ',') {
			result.push_back(names[i]);
		}
		if (names[i] == ',' || i == 0) {
			reverse(result.begin(), result.end());
			if (!is_first) {
				cout << ',';
			}
			else
			{
				is_first = false;
			}
			for (auto x : result) {
				cout << x;
			}
			result.clear();
		}
	}
}