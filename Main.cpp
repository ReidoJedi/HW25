#include <iostream>
#include "mysql.h"
#include <string> 

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	MYSQL mysql;
	MYSQL_RES* res;
	MYSQL_ROW row;
	int i = 0;

	mysql_init(&mysql);

	if (&mysql == NULL) {
		cout << "Error: can't create MySQL-descriptor" << endl;
	}

	if (!mysql_real_connect(&mysql, "localhost", "root", "root", "Console_chat", 0, NULL, 0)) {
		cout << "Error: can't connect" << mysql_error(&mysql) << endl;
	}
	else {
		cout << "Database connection" << endl;
	}
	string Login;
	string Password;
	string Name;
	string Email;
	string textmessage;
	string recipientID;
	string senderID;
	
	int choice;
	bool open = true;
	cout << "Welcome to the Chat" << endl;
	cout << "Choose:" << endl;
	cout << "========================================================" << endl;
	cout << "1) Registration" << endl;
	cout << "2) Sign in" << endl;
	cout << "0) Exit the program" << endl;
	
	cin >> choice; 
	if (choice == 1) 
	{
		cout << "========================================================" << endl;
		cout << "Enter your login:" << endl;
		cin >> Login;
		
		cout << "Enter your password:" << endl;
		cin >> Password;
				
		cout << "Enter your name:" << endl;
		cin >> Name;
		
		cout << "Enter your email:" << endl;
		cin >> Email;
		cout << "========================================================" << endl;
		cout << "Information:" << endl;
		cout << Login << endl;
		cout << Password << endl;
		cout << Name << endl;
		cout << Email << endl;
		
		string requestregister = "SELECT login_user INTO user WHERE login_user =  " + Login  + ")";
		const char* newrequestregister = requestregister.c_str();
		mysql_query(&mysql, newrequestregister);
		if (!mysql_query(&mysql, newrequestregister)) {
			cout << "Error, this user already have account. Please restart the program" << endl;
			return 0;
		}
		else
		{

			string sqlString = "INSERT INTO user(id_user, login_user, password_user, name_user, email_user) VALUES(default, ' " + Login + " ' " + "," + " ' " + Password + " ' " + "," + " ' " + Name + " ' " + "," + " ' " + Email + " ' " + ")";
			const char* newString = sqlString.c_str();
			mysql_query(&mysql, newString);
			
			string messagelist = " select j1.name_user Sender, j2.name_user Recipient, text_message from message join user j1 on message.sender = j1.id_user join user j2 on message.recipient = j2.id_user;";
			const char* showmessagelist = messagelist.c_str();

			string sendmessage = "INSERT INTO message(id_message, sender, recipient, text_message, time_message) VALUES(default, " + senderID + "," + recipientID + " ' " + "," + textmessage + " ' " + "," + "NOW()" + ")";
			const char* sendmessageofcourse = sendmessage.c_str();

			cout << "========================================================" << endl;
			
			while (open) 
			{
				cout << "Welcome user " << Login << endl;
				cout << "Choose one of  options to use chat: " << endl;
				cout << "1) Show message list" << endl;
				cout << "2) Write a message" << endl;
				cout << "0) Exit the program" << endl;
				int userChoice; 
				cin >> userChoice;
				
			
				switch (userChoice)
				{
				case 1:
					cout << "========================================================" << endl;
					cout << "Message list: " << endl;
					cout << "Sender ||  Recipient || Text Message " << endl;
					mysql_query(&mysql, showmessagelist);
					if (res = mysql_store_result(&mysql)) {
						while (row = mysql_fetch_row(res)) {
							for (i = 0; i < mysql_num_fields(res); i++) {
								cout << row[i] << "  ";
							}
							cout << endl;
						}
					}
					else
						cout << "MySql error " << mysql_error(&mysql) << endl;;

					cout << endl;

					break;

				case 2:
					cout << "========================================================" << endl;
					cout << "Write a message" << endl;
					cout << "Select your index from list" << endl;
					cin >> senderID;

					cout << "Select  recipient: " << endl;
					cin >> recipientID;


					cout << "Text message: " << endl;
					do
					{
						getline(cin, textmessage);
					} while (!textmessage.length() == 0);
					getline(cin, textmessage);
					mysql_query(&mysql, sendmessageofcourse);
					cout << "========================================================" << endl;
					cout << "You wrote a message from user " << recipientID << endl;
					cout << "You wrote a message to user " << recipientID << endl;
					cout << "Your message text : " << textmessage << endl;
					cout << "========================================================" << endl;

					break;
				case 0:
					open = false;
					break;
				default:
					cout << "========================================================" << endl;
					cout << "Error, please enter the number 1, 2 or 0" << endl;
					cout << "========================================================" << endl;
					break;
				}
			}

		}
	}
	if (choice == 2) {
		cout << "Enter your login to connect to server: " << endl;
		cin >> Login;
		cout << "Enter your passoword to connect to server: " << endl;
		cin >> Password;
		string requestlogin = "SELECT login_user INTO user WHERE login_user = "  + Login  + ")";
		const char* newrequestlogin = requestlogin.c_str();
		mysql_query(&mysql, newrequestlogin);
		if (!mysql_query(&mysql, newrequestlogin)) {
			cout << "Error, this user already have account. Please restart the program" << endl;
			return 0;
		}
		else
		{
			while (open) {

			
		cout << "Welcome user " << Login << endl;
		cout << "Choose one of  options to use chat: " << endl;
		cout << "1) Show message list" << endl;
		cout << "2)  Write a message" << endl;
		cout << "0) Exit the program" << endl;
		int userChoice;
		cin >> userChoice;
		string messagelist = " select j1.name_user Sender, j2.name_user Recipient, text_message from message join user j1 on message.sender = j1.id_user join user j2 on message.recipient = j2.id_user;";
		const char* showmessagelist = messagelist.c_str();

		string sendmessage = "INSERT INTO message(id_message, sender, recipient, text_message, time_message) VALUES(default, " + senderID + "," + recipientID + " ' " + "," + textmessage + " ' " + "," + "NOW()" + ")";
		const char* sendmessageofcourse = sendmessage.c_str();
		switch (userChoice)
		{
		case 1:
			cout << "========================================================" << endl;
			cout << "Message list: " << endl;
			cout << "Sender || Recipient || Text Message " << endl;
			mysql_query(&mysql, showmessagelist);
			if (res = mysql_store_result(&mysql)) {
				while (row = mysql_fetch_row(res)) {
					for (i = 0; i < mysql_num_fields(res); i++) {
						cout << row[i] << "  ";
					}
					cout << endl;
				}
			}
			else
				cout << "MySql error " << mysql_error(&mysql) << endl;;

			cout << endl;

			break;

		case 2:
			cout << "========================================================" << endl;
			cout << "Write a message" << endl;
			cout << "Select your index from list" << endl;
			cin >> senderID;

			cout << "Select  recipient: " << endl;
			cin >> recipientID;


			cout << "Text message: " << endl;
			do
			{
				getline(cin, textmessage);
			} while (!textmessage.length() == 0);
			getline(cin, textmessage);
			mysql_query(&mysql, sendmessageofcourse);

			cout << "========================================================" << endl;
			cout << "You wrote a message from user " << recipientID << endl;
			cout << "You wrote a message to  user " << recipientID << endl;
			cout << "Your  message text : " << textmessage << endl;
			cout << "========================================================" << endl;

			break;
		case 0:
			open = false;
			break;
		default:
			cout << "========================================================" << endl;
			cout << "Error, please enter the number 1, 2 or 0" << endl;
			cout << "========================================================" << endl;
			break;
		    }
	        }
		}
	}
	if (choice == 0)
	{
		mysql_close(&mysql);
		return 0;
	}
	
	mysql_close(&mysql);

	system("Pause");
	return 0;
}
