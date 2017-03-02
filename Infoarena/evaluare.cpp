#include "stdafx.h"
#include <fstream>
#include <string>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int ind;
string expr;

int get_expr_val();

int get_term();

int get_factor();

int get_number();

int main()
{
  getline(in, expr, '\0');
  out << get_expr_val();
}

int get_expr_val()
{
  int sol = get_term();

  while (expr[ind] == '+' || expr[ind] == '-')
  {
    ++ind;

    if (expr[ind - 1] == '+')
      sol += get_term();
    else
      sol -= get_term();
  }

  return sol;
}

int get_term()
{
  int sol = get_factor();

  while (expr[ind] == '*' || expr[ind] == '/')
  {
    ++ind;

    if (expr[ind - 1] == '*')
      sol *= get_factor();
    else
      if (expr[ind - 1] == '/')
        sol /= get_factor();

  }

  return sol;
}

int get_factor()
{
  int sol;

  if (expr[ind] != '(')
  {
    sol = get_number();
  }
  else
  {
    ++ind;

    sol = get_expr_val();
    ++ind;
  }

  return sol;
}

int get_number()
{
  int sol = 0;

  while ('0' <= expr[ind] && expr[ind] <= '9')
  {
    sol = sol * 10 + expr[ind] - '0';

    ++ind;
  }

  return sol;
}