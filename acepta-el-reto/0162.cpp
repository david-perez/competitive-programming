#include <iostream>

using namespace std;

void puntitos(int n);

int main(){
  int n = 0;
  char s;
  bool t;

  cin >> n >> s;
  while(n != 0){
    puntitos(n);
    for(int a = 0; a < 8 * n; a++){
      if((a / n) % 2 == 0)t = true;
      else t = false;
      cout << "|";
      for(int i = 0; i < 8 * n; i++){
        if(t){
          if((i / n) % 2 == 0){
            cout << " ";
          }
          else{
            cout << s;
          }
        }else{
          if((i / n) % 2 == 0){
            cout << s;
          }else{
            cout << " ";
          }
        }

      }
      cout << "|" << endl;
    }
    puntitos(n);
    cin >> n >> s;
  }



}
void puntitos(int n){
  cout << "|";
  for(int i = 0; i < 8 * n; i++){
    cout << "-";
  }
  cout << "|" << endl;
}
