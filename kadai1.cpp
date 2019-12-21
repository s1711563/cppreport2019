#include <iostream>
using namespace std;

class person{
public:
  string name;
  string email;
};

int main()
{
  person friends[3];
  person emails[3];

  for(int i=0; i<3; i++){
    cout << i + 1 << "番目の名前を書いてください";
    cin >> friends[i].name;
    cout << i + 1 << "番目のメールアドレスを書いてください";
    cin >> emails[i].email;
  }

  cout << "\n名前とメールアドレスリスト:\n";
  for(int i=0; i<3; i++){
    cout << friends[i].name << ":" << emails[i].email << "\n";
  }
}
