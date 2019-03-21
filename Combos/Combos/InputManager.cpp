#include "InputManager.h"
#include <iostream>

std::map<const char*, int> InputManager::FightKeyMap;
std::map<const char*, int> InputManager::MenuKeyMap;
std::map<const char*, int> InputManager::MenuMouseMap;

std::vector<std::vector<const char*>> InputManager::ComboMovesList;
std::vector<std::vector<const char*>> InputManager::PotentialMovesList;
std::vector<std::map<const char*, int>> InputManager::MapArray1, InputManager::MapArray2;

int InputManager::contextState;
int InputManager::moveIndex;
std::chrono::duration<float> InputManager::lastMoveTime;

InputManager::InputManager()
{
	Init();
}

void InputManager::Init() 
{
	FightKeyMap["MoveLeft"]	   = GLFW_KEY_A;
	FightKeyMap["MoveRight"]   = GLFW_KEY_D;
	FightKeyMap["Jump"]		   = GLFW_KEY_SPACE;
	FightKeyMap["FistAttack1"] = GLFW_KEY_LEFT_SHIFT;
	FightKeyMap["FistAttack2"] = GLFW_KEY_V;
	FightKeyMap["KickAttack1"] = GLFW_KEY_LEFT_CONTROL;
	FightKeyMap["KickAttack2"] = GLFW_KEY_C;
	MapArray1.push_back(FightKeyMap);

	MenuKeyMap["MoveDown"]   = GLFW_KEY_DOWN;
	MenuKeyMap["MoveUp"]	 = GLFW_KEY_UP;
	MenuKeyMap["SlideLeft"]  = GLFW_KEY_LEFT;
	MenuKeyMap["SlideRight"] = GLFW_KEY_RIGHT;
	MenuKeyMap["Access"]	 = GLFW_KEY_ENTER;
	MapArray1.push_back(MenuKeyMap);

	MenuMouseMap["LeftClick"]   = GLFW_MOUSE_BUTTON_LEFT;
	MenuMouseMap["RightClick"]  = GLFW_MOUSE_BUTTON_RIGHT;
	MenuMouseMap["MiddleClick"] = GLFW_MOUSE_BUTTON_MIDDLE;
	MapArray1.push_back(MenuMouseMap);

	ComboMovesList.push_back({"FistAttack1","FistAttack2","KickAttack1","KickAttack2"});
	ComboMovesList.push_back({"KickAttack1","KickAttack1","KickAttack2","KickAttack2"});
	ComboMovesList.push_back({"FistAttack1","KickAttack1","FistAtttack2","KickAttack2" });
	ComboMovesList.push_back({"KickAttack1","FistAttack1","FistAttack1","KickAttack1"});
}

void InputManager::ConfigureToDefaults() 
{
	MapArray1[0]["MoveLeft"]    = GLFW_KEY_A;
	MapArray1[0]["MoveRight"]   = GLFW_KEY_D;
	MapArray1[0]["Jump"]		= GLFW_KEY_SPACE;
	MapArray1[0]["FistAttack1"] = GLFW_KEY_LEFT_SHIFT;
	MapArray1[0]["FistAttack2"] = GLFW_KEY_V;
	MapArray1[0]["KickAttack1"] = GLFW_KEY_LEFT_CONTROL;
	MapArray1[0]["KickAttack2"] = GLFW_KEY_C;
}

void InputManager::ValidateKeyInput(int x)
{
	using namespace std;
	for (map<const char*, int>::iterator it = MapArray1[0].begin(); it!=MapArray1[0].end();it++) 
	{
		if(x==it->second)
		{
			cout << it->first << endl;
			if (moveIndex == 0) 
			{
				CheckForCombo(it->first);
			}
			else 
			{
				ContinueCombo(it->first);
			}
		}
	}
}

void InputManager::ValidateMouseInput(int x)
{
	using namespace std;
	for (map<const char*, int>::iterator it = MapArray1[2].begin(); it != MapArray1[2].end(); it++)
	{
		if (x == it->second)
		{
			cout << it->first << endl;
		}
	}
}

void InputManager::CheckForCombo(const char* x) 
{
	PotentialMovesList.clear();
	for (int i = 0; i<ComboMovesList.size();i++) 
	{
		if (x == ComboMovesList[i][0]) 
		{
			PotentialMovesList.push_back(ComboMovesList[i]);
		}
	}
	if (PotentialMovesList.size() > 0) 
	{
		moveIndex = 1;
	}
	
}

void InputManager::ContinueCombo(const char* x) 
{
	int t = 0;
	for (int i = 0; i < PotentialMovesList.size() + t; i++) 
	{
		if (x != PotentialMovesList[i-t][moveIndex]) 
		{
			PotentialMovesList.erase(PotentialMovesList.begin() + i - t);
			t++;
		}
	}

	if (PotentialMovesList.size()>0) 
	{
		if ((PotentialMovesList.size() == 1)&& PotentialMovesList[0].size()==moveIndex) 
		{
			std::cout << "Combo Executed!!\n";
			moveIndex = 0;
			//TODO-EXECUTE THE METHOD WHICH TAKES IN A COMBO ID AND EXECUTES IT TO THE MAPPED COMBO
		}
		else 
		{
			moveIndex++;
		}
	}
	else 
	{
		std::cout << "Combo Failed!\n";
		moveIndex = 0;
		CheckForCombo(x);
	}
}