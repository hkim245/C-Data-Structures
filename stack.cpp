//This is to demonstrate how to use stack STL
#include <iostream>
#include <stack>

using namespace std;

int main()
{
  std::stack<string> s;
  s.push("Hello");
  s.push("World");
  s.push("!");
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  cout << s.empty() << endl;
}
