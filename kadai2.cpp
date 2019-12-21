#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name;
};

class addressbook{
  person friends[100];
  int numberOfFriends;
public:
  addressbook();
  void listFriends();
  void addFriend(string n, string a);
};

// constructor
addressbook::addressbook(){
  numberOfFriends = 0;
}

void addressbook::addFriend(string n, string a){
  friends[numberOfFriends].name = n;
  friends[numberOfFriends].address = a;
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << "\n";
    cout << friends[i].address << "\n";
  }
}

int main()
{
  addressbook abook;
  string name;
  string address;

  while(1){
    cout << "住所録に登録する名前を入力してください（終了するにはquitと入力してください）: ";
    cin >> name;
    if(name == "quit"){break;}
    cout << "住所録に登録する住所を入力してください（終了するにはquitと入力してください）: ";
    cin >> address;
    //   cout << "name.length() = " << name.length() << "\n";
    if(address == "quit"){break;}
    abook.addFriend(name, address);
  }

  cout << "\n住所録リスト:\n";
  abook.listFriends();
}
