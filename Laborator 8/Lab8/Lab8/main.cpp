#include <string>
#include <set>
#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <queue>
#include <vector>

using namespace std;


struct Compare {
	bool operator()(const pair<string, int>& fp, const pair<string, int>& sp)
	{
		if (fp.second < sp.second)
			return true;
		else if (fp.second == sp.second)
			return (fp.first > sp.first);
		else return false;
	}
};

int main()
{
	// -------- 1

	string sentence;

	ifstream file;
	file.open("text.txt");
	if (file.is_open())
	{
		getline(file, sentence);
		file.close();
	}
	else
		cout << "Could not open file." << endl;

	// -------- 2
	
	string word = "";
	vector<string> words;
	//string words[50];
	//set<char> sep = { ' ', '.', ',', '!', '?' };

	for (auto c : sentence)
	{
		if (c != ' ' && c != '.' && c != ',' && c != '!' && c != '?')
		{
			word.push_back(tolower(c));
		}
		else
		{
			words.push_back(word);
			word = "";
		}
	}

	for (int j = 0; j < words.size(); j++)
	{
			cout << words[j] << ' ';
	}
	cout << endl << endl;

	// --------- 3


	map<string, int> count_frequency;

	for (int j = 0; j < words.size(); j++)
	{
		if (count_frequency.count(words[j]) == 0)
		{ 
			count_frequency[words[j]] = 1;
		}
		else
			count_frequency[words[j]]++;
	}

	for (auto it = count_frequency.cbegin(); it != count_frequency.cend(); ++it)
	{
		cout << it->first << " : " << it->second << "\n";
	}
	cout << endl;

	// -------- 4

	priority_queue<pair<string, int>, vector<pair<string, int>>, Compare> pq;

	for (auto it = count_frequency.begin(); it != count_frequency.end(); ++it)
	{
		pair<string, int> pairs(it->first, it->second);
		pq.push(pairs);
	}

	while (pq.empty() == false)
	{
		cout << pq.top().first << " => " << pq.top().second << endl;
		pq.pop();
	}

	int n;
	cin >> n;
}