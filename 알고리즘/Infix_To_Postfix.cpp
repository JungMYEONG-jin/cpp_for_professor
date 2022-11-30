#include <string>
#include <stack>
using namespace std;

int op(char ch)
{
  if(ch=='^')
    return 3;
  else if(ch=='*' || ch=='/')
    return 2;
  else if(ch=='+' || ch=='-')
    return 1;
  else
    return -1;
}




std::string to_postfix(std::string infix) {
  string res;
  stack<char> temp;
  
  int len = infix.size();
  for(int i=0;i<len;i++)
  {
    if(isdigit(infix[i]))
      res+=infix[i];
    else if(infix[i]=='(')
      temp.push(infix[i]);
    else if(infix[i]==')')
    {
      
      while(!temp.empty() && temp.top()!='(')
      {
        char c = temp.top();
        temp.pop();
        res+=c;
      }
      if(temp.top()=='(')
      {
        char c = temp.top();
        temp.pop();
      }
      
      
    }else
      {
      
      // 연산자라면
      while(!temp.empty() && op(infix[i])<=op(temp.top()))
      {
        if(infix[i]=='^' && infix[i]==temp.top())
          break;
        char c = temp.top();
        temp.pop();
        res+=c;
      }
      temp.push(infix[i]);
      
      
    }
  }
  
  while(!temp.empty())
  {
    char c= temp.top();
    temp.pop();
    res+=c;
  }
  
  return res;
  
}

/* BEST SELECTED



include <stack>
#include <string>
using namespace std;

bool isOperand(char c)
{
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int getPrecedence(char op)
{
    switch (op)
    {
    case '-':
    case '+':
        return 0;
    case '*':
    case '/':
        return 1;
    case '^':
        return 2;
    default:
        return -1;
    }
}

std::string to_postfix(std::string infix) {

    infix = '(' + infix + ')';

    string result;
    stack<char> operatorStack;

    for(char c : infix)
    {
        if (c == '(')
        {
            operatorStack.push(c);
        }
        else if (c == ')')
        {
            while (operatorStack.top() != '(')
            {
                result += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (isOperand(c))
            result += c;
        else
        {
            while (getPrecedence(operatorStack.top()) >= getPrecedence(c))
            {
                result += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    return result;
}



*/
