#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

struct candidate
{
	string lastName;
	int votes;
};

void displayVotes(const candidate person[], const int& numCand);

int main()
{
	candidate* personPtr;
	int numCandidates;

	//personPtr = new candidate[12];
	cout << "Anthony Cantu\t" << "L4-4\t" << "L4-4.exe" << endl;

	cout << "\tEnter the number of candidates in the election: ";
	cin >> numCandidates;
	while(!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "ERROR: Please enter a numeric value." << endl
			<< "\tEnter the number of candidates in the election: ";
		cin >> numCandidates;
	}

	personPtr = new candidate[numCandidates];

	cout << "\tEnter the candidate's name and votes they received" << endl
		<< "\tfor the " << numCandidates << " candidates." << endl;

	for (int i = 1; i <= numCandidates; i++)
	{
		cout << i << ": ";
		cin >> personPtr[i - 1].lastName >> personPtr[i - 1].votes;
		while(!cin)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "ERROR: Invalid entry for votes." << endl
				<< "Please enter a positive numeric value for votes received by " << personPtr[i - 1].lastName << ": ";
			cin >> personPtr[i - 1].votes;
			if (cin)
			{
				for(int x = 1; x <= i; x++)
					cout << x << ": " << personPtr[x - 1].lastName << " " << personPtr[x - 1].votes << endl;
			}
		}
	}

	cout << endl;

	displayVotes(personPtr, numCandidates);

	cout << endl; //Line Break

	cout << "candidate* personPtr;" 
		<< "\tValue: " << &personPtr 
		<< "\tValue : " << personPtr << endl;

	char q;
	cout << "Press any key to Exit.";
	cin.ignore(2, '\n');
	cin.get(q);

	return 0;
}

void displayVotes(const candidate person[], const int& numCand)
{
	int totalVotes = 0;
	int largestIndex = 0;
	int winnerIndex;

	for (int i = 0; i < numCand; i++)
		totalVotes += person[i].votes;

	cout << setfill(' ') << setprecision(2) << fixed;
	cout << left << setw(10) << " ";
	cout << left << setw(15) << "Candidate";
	cout << left << setw(20) << "Votes Received";
	cout << left << "% of Total Votes" << endl;

	for (int i = 0; i < numCand; i++)
	{
		cout << left << setw(10) << " ";
		cout << left << setw(15) << person[i].lastName;
		cout << right << setw(8) << person[i].votes;
		cout << right << setw(21) << (person[i].votes / static_cast<double>(totalVotes)) * 100 << endl;

		if (largestIndex < person[i].votes)
		{
			largestIndex = person[i].votes;
			winnerIndex = i;
		}
	}

	cout << left << setw(10) << " ";
	cout << left << setw(20) << "Total";
	cout << right << totalVotes << endl;

	cout << endl; //Line Break

	cout << left << setw(10) << " ";
	cout << left << "The Winner of the Election is " << person[winnerIndex].lastName << "." << endl;
}


