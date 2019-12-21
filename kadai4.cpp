#include <iostream>
using namespace std;

class person{
public:
  string address;
  string id;
  string name;
};

class addressbook{
  person* friends;
  int numberOfFriends;
public:
  addressbook();
  ~addressbook();
  void listFriends();
  void addFriend(string name,string address);
  person find(string query);
};

addressbook::addressbook(){
  numberOfFriends = 0;
  friends = new person [100];
}

addressbook::~addressbook(){
  delete[] friends;
}

void addressbook::addFriend(string name,string address){
  friends[numberOfFriends].name = name;
  friends[numberOfFriends].address = address;
  numberOfFriends++;
}

void addressbook::listFriends(){
  for(int i = 0; i < numberOfFriends; i++){
    cout << friends[i].name << ":"<<friends[i].address<<"\n";
  }
}

person addressbook::find(string query){
  for(int i = 0; i < numberOfFriends; i++){
    if(friends[i].name == query){
      return friends[i];
    }
  }
  person noone;
  noone.name = "";
  return noone;
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
    cout << "住所録に登録する住所を入力してください(終了するに􏰀 quit と入力してください):";
    cin >> address;
    abook.addFriend(name,address);
  }

  cout << "\n名前リスト:\n";
  abook.listFriends();

  cout << "検索：";
  cin >> query;
  person res = abook.find(query);
  found = abook.find(query);
  if(found.name == ""){
  cout << "見つかりませんでした。\n"; }else{
  cout << "検索結果"<<found.name << ":" << found.address<<"\n";}
}
