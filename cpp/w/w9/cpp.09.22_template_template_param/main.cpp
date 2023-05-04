#include <iostream>
#include <vector>
#include <deque>

#include "stack_tt.h"
#include "stack.h"

int main()
{
  // using stack = stack<int, std::vector<int>>;
  // using stack = stack<int, std::deque<int>>;

  // using stack = tt::stack<int, std::vector>;
  // using stack = tt::stack<int, std::deque>;
  
  using stack = tt::stack<>;

  stack s;

  for(auto& i: {1,2,3,4,5,6,7,8,9})
    s.push(i);

  std::cout << "Stack top: " << s.top() << "\n";
  s.pop();
  std::cout << "Stack size: " << s.size() << "\n";

}
 