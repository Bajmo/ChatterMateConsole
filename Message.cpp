#include <string>
#include "Message.h"

//User x;
//User y;

/*
Message::Message() {
	SentTo = x;
	SentBy = y;
	Msg = "";
}
*/

/*
Message::Message(User& SENTTO, User& SENTBY, std::string MESSAGE) {
	SentTo = SENTTO;
	SentBy = SENTBY;
	Msg = MESSAGE;
}
*/

/*
Message::Message(const Message& MESSAGE) {
	SentTo = MESSAGE.SentTo;
	SentBy = MESSAGE.SentBy;
	Msg = MESSAGE.Msg;
}
*/

void Message::setSentTo(User& USER) { SentTo = USER; }
void Message::setSentBy(User& USER) { SentBy = USER; }
void Message::setMessage(std::string& MESSAGE) { Msg = MESSAGE; }

User Message::getSentTo() { return SentTo; }
User Message::getSentBy() { return SentBy; }
std::string Message::getMessage() { return Msg; }