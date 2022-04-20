//Mini-Projet C++: Application chat

/* Boost: https://www.boost.org/users/history/version_1_78_0.html */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include "User.h"
#include "Message.h"

//File manipulation
std::ofstream userLog("User Log.txt", std::ios::app);
std::ofstream messageLog("Message Log.txt", std::ios::app);

//Facilitating the use of cin/cout.
using std::cout;
using std::cin;

//Declaring user-related variables.
User userList[10];
int userIndex = 0;
int userIndexFOUND = 0;

//Declaring message-related variables.
std::vector<Message>::size_type messageIndex = 0;
std::vector<Message> messageList;

Message messageBuffer;

//Sends messages: requires a user to send to and the message content.
void sendMessage() {

	std::string SENTTO;
	std::string MESSAGE;

	bool messageSent = false;

retrySendMessage:
	cout << "Who do you want to leave the message for? ";
	cin >> SENTTO;
	for (int i = 0; i < userIndex; i++) {
		if (SENTTO == userList[userIndexFOUND].getPseudo()) {
			cout << "\nYou can't send a message to yourself!\n";
			system("pause");
			system("cls");
			goto retrySendMessage;
		}
		while (messageList.size() <= messageIndex) {
			if (SENTTO == userList[i].getPseudo()) {
				cin.ignore();
				cout << "\nWrite your message: ";
				getline(cin, MESSAGE);
				messageBuffer.setMessage(MESSAGE);
				messageBuffer.setSentTo(userList[i]);
				messageBuffer.setSentBy(userList[userIndexFOUND]);
				messageList.push_back(messageBuffer);
				system("cls");

				//Export messageList entry to messageLog:
				std::ofstream messageLog;
				messageLog.open("Message Log.txt", std::ios::app);
				messageLog << messageList[messageIndex].getSentTo().getPseudo() << "\t" << messageList[messageIndex].getSentBy().getPseudo() << "\t" << messageList[messageIndex].getMessage() << "\n";
				messageLog.close();

				cout << "=============================================================\n\n";
				cout << "Message sent successfuly!\n\n";
				cout << "=============================================================\n\n";
				system("pause");
				system("cls");
				messageSent = true;
				messageIndex++;
				break;
			}
			break;
		}
	}
	if (messageSent == false) {
		cout << "\nUser not found. Try again.\n";
		system("pause");
		system("cls");
		goto retrySendMessage;
	}
}

//Displays messages: requires user input to navigate.
void displayConversation() {
	int choice = 0;
	int j = 0;

	do {
		bool conversationInitiated = false;
		bool check = false;

		cout << "=============================================================\n\n";
		cout << "      <0> Go back to the previous menu.\n\n";
		for (int i = 0; i < userIndex; i++) {
			j = i;
			if (i != userIndexFOUND)
				cout << "      <" << j + 1 << "> " << userList[i].getPseudo() << "\n\n";
		}
		if (j == 0)
			cout << "      No other users are signed up...\n\n";
		cout << "=============================================================\n\n";
		cout << "Input option: ";
		cin >> choice;
		cout << "\n";
		switch (choice) {
			case 0:
				system("cls");
				break;
			case 1:
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 2:
				if (j < 1) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 3:
				if (j < 2) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 4:
				if (j < 3) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 5:
				if (j < 4) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 6:
				if (j < 5) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 7:
				if (j < 6) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 8:
				if (j < 7) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 9:
				if (j < 8) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			case 10:
				if (j < 9) {
					cout << "This user slot isn't used yet!\n";
					system("pause");
					system("cls");
					break;
				}
				if (choice == userIndexFOUND + 1) {
					cout << "Don't pick your own index!\n";
					system("pause");
					system("cls");
					check = true;
				}
				system("cls");
				for (int k = 0; k < messageList.size(); k++) {
					if (
						(messageList[k].getSentTo().getPseudo() == userList[userIndexFOUND].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[choice - 1].getPseudo())
						||
						(messageList[k].getSentTo().getPseudo() == userList[choice - 1].getPseudo() && messageList[k].getSentBy().getPseudo() == userList[userIndexFOUND].getPseudo())
						)
					{
						cout << messageList[k].getSentBy().getPseudo() << ": " << messageList[k].getMessage() << "\n\n";
						conversationInitiated = true;
					}
				}
				if (check == false) {
					if (conversationInitiated == false) {
						cout << "This conversation hasn't been initiated.\n";
						system("pause");
						system("cls");
					}
					else {
						cout << "Tap a key to go back.\n";
						system("pause");
						system("cls");
					}
				}
				break;
			default:
				cout << "There can only be 10 user slots!\n";
				system("pause");
				system("cls");
		}
	} while (choice != 0);
}

//Messenger menu.
void messengerMenu(int USERINDEX) {
	int choice = 0;

loggedInMainMenu:
	do {
		cout << "You're currently signed in as: " << userList[userIndexFOUND].getPseudo() << "\n\n";
		//cout << "You have " << userList[userIndexFOUND].getNewMessageCount() << " new messages.\n\n";
		cout << "=============================================================\n\n";
		cout << "      <1> Leave a message------------------------------------\n";
		cout << "      <2> View messages--------------------------------------\n";
		cout << "      <3> Sign out-------------------------------------------\n\n";
		cout << "=============================================================\n\n";
		cout << "Input option: ";
		cin >> choice;
		cout << "\n";
		if (userIndex == 1 && choice == 1) {
			cout << "There's no one to leave a message for. At least one more user\nis required to start a conversation.\n";
			system("pause");
			system("cls");
			goto loggedInMainMenu;
		}
		else
			switch (choice) {
			case 1:
				system("cls");
				sendMessage();
				break;
			case 2:
				system("cls");
				displayConversation();
				break;
			case 3:
				system("cls");
				cout << "=============================================================\n\n";
				cout << "Signed out successfuly!\n\n";
				cout << "=============================================================\n\n";
				system("pause");
				system("cls");
				break;
			default:
				cout << "Invalid input!\n";
				system("pause");
				system("cls");
			}
	} while (choice != 3);
}

//Sign up menu.
void signUp() {
	std::string PSEUDO;
	std::string PASSWORD;
	std::string PASSWORDcheck;

	bool passwordCheckFailed = false;
	bool pseudoCheckFailed = false;

	cout << "=============================================================\n\n";
	cout << "************************ ChatterMate ************************\n\n";
	cout << "=============================================================\n\n";
retryPseudoSignUp:
	if (pseudoCheckFailed == true) {
		cout << "=============================================================\n\n";
		cout << "************************ ChatterMate ************************\n\n";
		cout << "=============================================================\n\n";
	}
	cout << "       Pseudo: ";
	cin >> PSEUDO;
	cout << "\n";
	for (int i = 0; i < userIndex; i++)
		if (userList[i].getPseudo() == PSEUDO) {
			cout << "User already exists. Try again.\n";
			system("pause");
			system("cls");
			pseudoCheckFailed = true;
			goto retryPseudoSignUp;
		}
	userList[userIndex].setPseudo(PSEUDO);
	cout << "       Password: ";
	cin >> PASSWORD;
	cout << "\n";
	userList[userIndex].setPassword(PASSWORD);
retryPasswordSignUp:
	if (passwordCheckFailed == true) {
		cout << "=============================================================\n\n";
		cout << "************************ ChatterMate ************************\n\n";
		cout << "=============================================================\n\n";
	}
	cout << "       Confirm password: ";
	cin >> PASSWORDcheck;
	cout << "\n";
	if (userList[userIndex].getPassword() != PASSWORDcheck) {
		cout << "Passwords don't match. Try again.\n";
		system("pause");
		system("cls");
		passwordCheckFailed = true;
		goto retryPasswordSignUp;
	}

	//Export userList entry in userLog:
	std::ofstream userLog;
	userLog.open("User Log.txt", std::ios::app);
	userLog << userList[userIndex].getPseudo() << "\t" << userList[userIndex].getPassword() << "\n";
	userLog.close();

	cout << "=============================================================\n\n";
	cout << "User account created successfuly!\n";
	system("pause");
	system("cls");
	userIndex++;
}

//Log in menu.
void logIn() {
	std::string PSEUDO;
	std::string PASSWORD;

	bool passwordCheckFailed = false;
	bool pseudoCheckFailed = false;
	bool pseudoFound = false;

	cout << "=============================================================\n\n";
	cout << "************************ ChatterMate ************************\n\n";
	cout << "=============================================================\n\n";
retryPseudoLogIn:
	if (pseudoCheckFailed == true) {
		cout << "=============================================================\n\n";
		cout << "************************ ChatterMate ************************\n\n";
		cout << "=============================================================\n\n";
	}
	cout << "       Pseudo: ";
	cin >> PSEUDO;
	cout << "\n";
	for (int i = 0; i < userIndex; i++)
		if (userList[i].getPseudo() == PSEUDO) {
			userIndexFOUND = i;
			pseudoFound = true;
		}
	if (pseudoFound == false) {
		cout << "Invalid pseudo. Try again.\n";
		system("pause");
		system("cls");
		pseudoCheckFailed = true;
		goto retryPseudoLogIn;
	}
retryPasswordLogIn:
	if (passwordCheckFailed == true) {
		cout << "=============================================================\n\n";
		cout << "************************ ChatterMate ************************\n\n";
		cout << "=============================================================\n\n";
	}
	cout << "       Password: ";
	cin >> PASSWORD;
	cout << "\n";
	if (userList[userIndexFOUND].getPassword() == PASSWORD) {
		User validUser = userList[userIndexFOUND];
		cout << "=============================================================\n\n";
		cout << "Logged in successfuly!.\n";
		system("pause");
		system("cls");
		messengerMenu(userIndexFOUND);
	}
	else {
		cout << "Invalid password. Try again.\n";
		system("pause");
		system("cls");
		passwordCheckFailed = true;
		goto retryPasswordLogIn;
	}
}

//Function for quitting the program.
void quit() {
	system("cls");
	cout << "=============================================================\n\n";
	cout << "************** Thank you for using ChatterMate **************\n\n";
	cout << "=============================================================\n\n";
	system("pause");
}

//Main function.
int main() {
	int choice = 0;
	int i = 0;

	//Buffers: hold the user or message data before passing it on to be treated.
	std::vector<std::string> userLogBuffer;
	std::vector<std::string> messageLogBuffer;
	Message messageListBuffer;

	//Log strings: hold the data to be treated.
	std::string userLogString;
	std::string messageLogString;

	//Fill userList from userLog:
	std::ifstream userLog;
	userLog.open("User Log.txt", std::ios::in);

	while (getline(userLog, userLogString)) {
		boost::split(userLogBuffer, userLogString, boost::is_any_of("\t"));
		userList[userIndex].setPseudo(userLogBuffer[0]);
		userList[userIndex].setPassword(userLogBuffer[1]);
		userLogBuffer.clear();
		userIndex++;
	}

	//Fill messageList from messageLog.
	std::ifstream messageLog;
	messageLog.open("Message Log.txt", std::ios::in);

	while (getline(messageLog, messageLogString)) {
		boost::split(messageLogBuffer, messageLogString, boost::is_any_of("\t"));
		for (i = 0; i < userIndex; i++)
			if (userList[i].getPseudo() == messageLogBuffer[0])
				messageListBuffer.setSentTo(userList[i]);
		for (i = 0; i < userIndex; i++)
			if (userList[i].getPseudo() == messageLogBuffer[1])
				messageListBuffer.setSentBy(userList[i]);
		messageListBuffer.setMessage(messageLogBuffer[2]);
		messageList.push_back(messageListBuffer);
		messageLogBuffer.clear();
		messageIndex++;
	}

	//Closing the log files.
	userLog.close();
	messageLog.close();

mainMenu:
	do {
		cout << "=============================================================\n\n";
		cout << "************************ ChatterMate ************************\n\n";
		cout << "=============================================================\n\n";
		cout << "      <1> Log in---------------------------------------------\n";
		cout << "      <2> Sign up--------------------------------------------\n";
		cout << "      <3> Quit-----------------------------------------------\n\n";
		cout << "=============================================================\n\n";
		cout << "Input option: ";
		cin >> choice;
		cout << "\n";
		if (userIndex == 0 && choice == 1) {
			cout << "There are currently no users signed up. Sign up and try again.\n";
			system("pause");
			system("cls");
			goto mainMenu;
		}
		else
			switch (choice) {
			case 1:
				system("cls");
				logIn();
				break;
			case 2:
				if (userIndex == 10) {
					cout << "Cannot create more than 10 users!\n";
					system("pause");
					system("cls");
				}
				else {
					system("cls");
					signUp();
					break;
				}
				break;
			case 3:
				system("cls");
				quit();
				break;
			default:
				cout << "Invalid input!\n";
				system("pause");
				system("cls");
			}
	} while (choice != 3);
	return 0;
}

//Commenting on the warnings given by Visual Studio 2022:
//C26812 - Inconsistency in the Boost library.
//C26495 - Inconsistency in the Boost library.