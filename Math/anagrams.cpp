#include <iostream>
#include <cstdio>

using namespace std;

string start, goal;
void solve(string goal, string i, string s, string o, string moves){
   if(o == goal) {
      cout << moves << endl;
   }
   // push
   if(i.length() > 0)
      solve(goal, i.substr(1, i.length()-1), s + i[0], o, moves + "+");
   // pop
   if(s.length() > 0)
      solve(goal, i, s.substr(0, s.length() - 1), o + s[s.length() -1], moves + "-");
};

int main() {
   int n;
   cin >> n;
   for(int i = 0; i < n; i ++){
      cin >> start >> goal;
      cout << "Output for " << start << " " << goal << endl;
      cout << "[" << endl;
      if(start.length() == goal.length())
         solve(goal, start, "", "", "");
      cout << "]" << endl;
   }
}
