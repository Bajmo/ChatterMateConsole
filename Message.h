#pragma once
#include <string>
#include "User.h"

class Message {
	User SentTo;
	User SentBy;
	std::string Msg;

public:
	//Message(); Default constructor.
	//Message(User& SENTTO, User& SENTBY, std::string MESSAGE); Parametrized constructor.
	//Message(const Message& MESSAGE); Copy constructor.

	User getSentTo();
	User getSentBy(); 
	std::string getMessage();

	void setSentTo(User& USER);
	void setSentBy(User& USER);
	void setMessage(std::string& MESSAGE);
};