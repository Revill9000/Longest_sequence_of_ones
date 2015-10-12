#include <iostream>
#include <fstream>
#include <string>
//#include <sstream>


using namespace std;
//std::istringstream sstr;

void search_longest_sequence()
{
	int max_length = 0;
	int current_length = 0;
	char c;
	ifstream fin;
	ofstream fout;
	fin.open("INPUT.TXT");
	fout.open("OUTPUT.TXT");
	while (fin >> c)
	{
		if (c == '0')
		{
			if (current_length > max_length)
			{
				max_length = current_length;
			}
			current_length = 0;
		}
		if (c == '1')
		{
			current_length++;
		}
	}
	fout << max_length;
	fout << flush;
	fout.close();
	fin.close();


}

string get_all_divisors(int number)
{
	string result;




	int i = 2;
	while (i <= sqrt(number))
	{
		if (number % i == 0) {
			result += to_string(i) + ' ';
			if (i != (number / i)) {
				result += to_string(number / i) + ' ';
			}
		}

		i++;
	}
	return result;
}


int main()
{
	search_longest_sequence();

	cout << get_all_divisors(100);
	return 0;
}