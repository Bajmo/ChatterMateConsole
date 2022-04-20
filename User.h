#pragma once
#include <string>

class User {
	std::string Pseudo;
	std::string Password;

public:
	//User(); Default constructor.
	//User(std::string PSEUDO, std::string PASSWORD); Parametrized constructor.
	//User(const User& USER); Copy constructor.

	void setPseudo(std::string PSEUDO);
	void setPassword(std::string PASSWORD);

	std::string getPseudo();
	std::string getPassword();
};