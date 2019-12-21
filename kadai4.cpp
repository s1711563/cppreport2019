#include <iostream>
using namespace std;

class person{
public:
  string address;
  string name;
};

class addressbook{
  person friends[100]{friends = new person[maximumFriends]};
  int numberOfFriends;
public:
  addressbook();
  void listFriends();
  void addFriend(string n, string a);
  person find(string query);
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
      cout << friends[i].name << ":" << friends[i].address << "\n";
  }
}

person addressbook::find(string query){
  for(int i = 0; i < numberOfFriends; i++){
    if(friends[i].name == query){
      return friends[i];
    }
  }
  person no_one;
  return no_one;
}

int main()
{
  addressbook abook;
  string name;
  string address;
  string query;
  person found;

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

  cout << "検索したい人物の名前を入力して下さい：";
  cin >> query;
  found = abook.find(query);
  cout << found.name << ":" << found.address << "\n";
}
