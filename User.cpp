#include <string>
#include "User.h"

/*
User::User() {
	Pseudo = "";
	Password = "";
}
*/

/*
User::User(std::string PSEUDO, std::string PASSWORD) {
	Pseudo = PSEUDO;
	Password = PASSWORD;
}
*/

/*
User::User(const User& USER) {
	Pseudo = USER.Pseudo;
	Password = USER.Password;
}
*/

void User::setPseudo(std::string PSEUDO) { Pseudo = PSEUDO; }
void User::setPassword(std::string PASSWORD) { Password = PASSWORD; }

std::string User::getPseudo() { return Pseudo; }
std::string User::getPassword() { return Password; }