#include <iostream>
using namespace std;

class person{
protected:
  string name;
public:
  void setName(string n){name =n;}
  string getName(){return name;}
};

class ticket{
public:
  int id;
  person* user;
  ticket(){user = new person;}
};

class transTicket : public ticket {
public:
string origin;
string destination;
transTicket(): ticket(){};
};

class planeTicket : public transTicket {
public:
  int departureDate;
  planeTicket(): transTicket(){};
};
int main()
{
int ticketNum;
string name;
cout << "チケットの購入枚数は？ ";
cin >> ticketNum;
cout << "\n";
transTicket* tickets = new transTicket [ticketNum];
for(int i = 0; i < ticketNum; i++){
tickets[i].id = i+1;
cout << i+1 << "人目の利用者の名前を入力してください: ";
cin >> name;
tickets[i].user->setName(name);
cout << " 出発地を入力してください: ";
cin >> tickets[i].origin;
cout << " 到着地を入力してください: ";
cin >> tickets[i].destination;
}
cout << "\n チケット利用者一覧:\n";
for(int i = 0; i < ticketNum; i++){
transTicket t = tickets[i];
cout << " " << t.id << " : " << t.user->getName() << " : " << t.origin << "=> " << t.destination << "\n";
}
cout << "\n";
}
