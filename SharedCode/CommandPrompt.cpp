#include "CommandPrompt.h"
#include <sstream>

CommandPrompt::CommandPrompt(): sys(nullptr), facto(nullptr){}

void CommandPrompt::setFileSystem(AbstractFileSystem* bill)
{
	sys = bill;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* rich)
{
	facto = rich;
}

int CommandPrompt::addCommand(string str, AbstractCommand* c)
{
	pair<string, AbstractCommand*> paul(str, c);
	commandMap.insert(paul);
	return 0; // not sure how to return fail... but it wouldnt change anything soo,,
}

int CommandPrompt::run()
{
	//while (1){
	//	string s = prompt();

	//	if (s == "q") {
	//		//exit(10);
	//		//abort();
	//		return 20;
	//	}
	//	if (s == "help") {
	//		listCommands();

	//	}
	//	if (s.find(' ')==string::npos) { //no spaces
	//		if (commandMap.find(s) != commandMap.end()) { // s was found in commands
	//			int outcome = commandMap.find(s)->second->execute(""); // might need a cout for error
	//			if (outcome != 0) {
	//				cout << "could not execute command" << endl;
	//			}
	//		}
	//		else { // s is not a command
	//			cout << "the command " << s << "does not exist, fool" << endl;
	//		}
	//	}
	//	else { // spaces
	//		istringstream iss(s);
	//		string fillipe;
	//		iss >> fillipe;
	//		if (fillipe == "help") {
	//			iss >> fillipe;
	//			if (commandMap.find(fillipe) != commandMap.end()) { // fillipe was found in commands
	//				commandMap.find(fillipe)->second->displayInfo();
	//			}
	//			else {
	//				cout << "the command " << fillipe << "does not exist, fool" << endl;
	//			}
	//		}
	//		else {
	//			if (commandMap.find(fillipe) != commandMap.end()) { // first word is command
	//				string toby;
	//				string wawa;
	//				while (iss) {
	//					iss >> toby;
	//					wawa += toby;
	//					wawa += " ";
	//					toby = "";
	//				}
	//				int outcome = commandMap.find(fillipe)->second->execute(wawa);
	//				if (outcome != 0) {
	//					cout << "you cant just " << fillipe << " on " << wawa << "like that." << endl;
	//				}
	//			}
	//			else {
	//				cout << "the command " << fillipe << "does not exist, fool" << endl;
	//			}
	//		}
	//	}
	while (true) {
		bool isOneWord = true;
		string sinPut = prompt();			
		istringstream getInput(sinPut);
		string hero;
		getInput >>hero;
		if (!getInput) {		
			cout << "No inputbool isOneWord = true;	" << endl;
			continue;
		}

		string testForMoreWords;					
		if (getInput >> testForMoreWords) {
			isOneWord = false;
		}

		if (hero == "q" && isOneWord) {						
			return 34;
		}


		else if (hero == "help" && isOneWord) {				
			this->listCommands();
		}

		else {

			if (isOneWord) {

				auto command = this->commandMap.find(hero);
				if (command == commandMap.end()) {
					cout << hero << " not a command" << endl;
				}
				else {
					int executeOutcome = (*command).second->execute("");
					if (executeOutcome != 0) {
						cout << (*command).first << " failed" << endl;
						cout << "For help with " << (*command).first << " enter: help " << (*command).first << endl;
					}
				}
			}
			else {
				istringstream iss(sinPut);
				string co1;
				iss >> co1;
				string paramString;
				if (co1 == "help") {
					iss >> paramString;
					auto c = this->commandMap.find(paramString);
					string tooMuch;
					if (iss >> tooMuch) {
						cout << "To use help, console input must be: help <command_name>" << endl;
						continue;
					}
					if (c == commandMap.end()) {
						cout << "Error: " << paramString << " not a command" << endl;
					}
					else {													
						(*c).second->displayInfo();
					}
				}
				else {														
					auto c = this->commandMap.find(co1);				
					if (c == commandMap.end()) {						
						cout << co1 << " not a command" << endl;
					}
					else {													
						string other;
						while (iss) {										
							iss >> other;
							paramString += other;
							paramString += " ";
							other = "";
						}
						int lastSpace = static_cast<int>(paramString.size()) - 2;
						paramString.replace(lastSpace,2,"");
						int executeOutcome = (*c).second->execute(paramString);	
						if (executeOutcome != 0) {						
							cout << (*c).first << " failed" << endl;
							cout << "For help with " << (*c).first << " enter: help " << (*c).first << endl;
						}
					}
				}
			}
		}
	}
	return 0;
}

void CommandPrompt::listCommands()
{
	map<string, AbstractCommand*>::iterator it;
	for (it = commandMap.begin(); it != commandMap.end(); it++) {
		cout << it->first << endl;
	}
}

string CommandPrompt::prompt()
{
	cout << "Enter a command, q to quit, help for a list of commands, or" << endl << "help followed by a command name for more information aboutthat command." << endl;
	cout << "$   ";
	string mouse;
	getline(cin, mouse);

	return mouse;
}
