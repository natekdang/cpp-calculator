#ifndef __MENU_CLASS__
#define __MENU_CLASS__

#include <iostream>
#include <vector>
#include "command.h"

using namespace std;

class Menu {
	private:
		int history_index;
		vector<Command*> history;

	public:
		Menu() {
			//Base constructor to set up all necessary members
			history_index = -1;
		};
		~Menu() {
			//cout << history.size() << "\n"; 
			while (history.size() > 0)
			{
				delete (history.end() - 1); //this causes issues 
				//history.pop_back(); 
				cout << history.size() << "\n";  
			}
			
		}
		
		void execute() {
			//Prints the current commands value (based on history_index), if no commands exist
			//print 0 by default
			if(history.size() == 0) {
			    cout << "0" << endl; 
			}
			else {
			    cout << history.at(history_index)->execute() << endl;
			}
		};
		bool initialized() {
			//Return true if the history has been primed with a single op instruction
			//This is necessary because that is the base of a calculation
			if(history.empty() ) {
			    return false;
			}
			
			return true;
		};
		void add_command(Command* cmd) {
			//Adds a command to history in the appropriate posiiton (based on history_index)
			if(history_index != int(history.size() - 1) ) {
			    while(history_index != int(history.size() - 1) ) {
			        history.pop_back();
			    }
			}
			history.push_back(cmd);
			history_index++;
		};
		Command* get_command() {
			//Returns the command in history we are currently referring to (based on history_index)
			return history.at(history_index);
		};
		void undo() {
			//Moves to the last command in history (if possible)
			if(history_index > 0) {
			    history_index--;
			}
		};
		void redo() {
			//Moves to the next command in history (if possible)
			if(history_index < int(history.size() - 1) ) {
			    history_index++;
			}
		};
};

#endif //__MENU_CLASS__