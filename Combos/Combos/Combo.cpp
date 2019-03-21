#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <chrono>
#include <thread>
#include <functional>
#include <string>
#include <cstdlib>
#include <map>

using namespace std;
std::vector<string> comboMoves1;
std::vector<string> comboMoves2;
std::vector<string> comboMoves3;
std::vector<string> comboMoves4;
vector<vector<string>> movelist;

map<thread::id, bool> boolMap;


void SetMoves() 
{
	comboMoves1.push_back("fistAttack1");
	comboMoves1.push_back("fistAttack2");
	comboMoves1.push_back("kickAttack2");
	comboMoves1.push_back("kickAttack2");
	movelist.push_back(comboMoves1);

	comboMoves2.push_back("fistAttack1");
	comboMoves2.push_back("fistAttack2");
	comboMoves2.push_back("fistAttack1");
	comboMoves2.push_back("fistAttack2");
	movelist.push_back(comboMoves2);

	comboMoves3.push_back("kickAttack2");
	comboMoves3.push_back("kickAttack2");
	comboMoves3.push_back("kickAttack2");
	comboMoves3.push_back("kickAttack2");
	movelist.push_back(comboMoves3);

	comboMoves4.push_back("kickAttack2");
	comboMoves4.push_back("fistAttack1");
	comboMoves4.push_back("fistAttack2");
	comboMoves4.push_back("kickAttack1");
	movelist.push_back(comboMoves4);
}






void Combo_Key_Run(string a)
{
	boolMap.clear();
	int moveNumber = 0;
	vector<vector<string>> potentialMove; // vector for storing list of moves available in the current run
	for (unsigned int i = 0; i < movelist.size(); i++)
	{
		if (movelist[i][moveNumber] == a)
		{
			potentialMove.push_back(movelist[i]);// pushes in the moves from movelist whose first moves match the current moves;
		}
	}

	if (potentialMove.size() > 0)// checks if any moves did match
	{
		moveNumber++;// increases the move index for combo
		bool comboRunning = true;// signals that it is currently checking for more moves for the combo
		
		while (comboRunning) 
		{
			string x;
	
			getline(cin, x);//checks for the next input
	//		if (boolMap[currentID]) {
			int t = 0;
			for (unsigned int i = 0; i < potentialMove.size() + t; i++)
			{
				//cout << potentialMove.size() << "\n";
				if (potentialMove[i - t][moveNumber] != x)
				{
					//cout << potentialMove[i-t][moveNumber] << " -> move removed\n";
					potentialMove.erase(potentialMove.begin() + i - t);//removes the moveWhich doesnt match anymore
					t++;
				}
			}
			cout << potentialMove.size() << "\n";
			if (potentialMove.size() > 0) //checks if there is a move left in the vector
			{
				moveNumber++;
				if (potentialMove.size() == 1)// 
				{
					if (potentialMove[0].size() == moveNumber)
					{
						cout << "Combo Successfully Executed" << endl;
						comboRunning = false;
					}
				}
			}
			else
			{
				comboRunning = false;
				cout << "combo failed" << endl;
			}
		}
	}
	else 
	{
		cout << "no combo move executed\n";
	}
}


int main() 
{
	SetMoves();
	string str;
	getline(cin, str);
	Combo_Key_Run(str);
	
	getchar();
	return 0;
}