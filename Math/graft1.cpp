#include <iostream>

using namespace std;

int depth(string::iterator& i, string data){
   int height = 0, depth = 0, tempdepth = 0;
   i = data.begin();
   while(i != data.end()){
      if(*i == 'd'){
      if(depth >= tempdepth){
         height++;
         tempdepth++;
      }
         i++;
         depth++;
      }
      else if(*i == 'u'){
         i++;
         depth--;
      }
   }
   return height;
};

int main(){
   int num(0);
   string input;
   string::iterator it;
   while(cin >> input && input != "#"){
      depth(it, input);
      cout << "Tree " << ++num << ": " << depth(it, input) << endl;
   }
   return 0;
}
