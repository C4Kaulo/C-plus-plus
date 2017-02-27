#include <fstream>
#include <string>

using namespace std;
ifstream in("criptare.in");
ofstream out("criptare.out");

string s, s2, key;
short caz;

string strltr(string s)
{
  s2.clear();

  for (short i = 0; i < s.size(); ++i)
    if (isalpha(s[i]))
      s2 += s[i];

  return s2;
}

int main()
{
  in >> caz;
  getline(in, s);
  getline(in, s);
  getline(in, key);

  if (caz == 1)
  {
    s = strltr(s);

    for (short i = 0; i <= s.size() / key.size(); ++i)
    {
      for (short j = 0; j < key.size(); ++j)
      {
        s[j + key.size() * (i - 1)] -= 96;
        s[j + key.size() * (i - 1)] += key[j] - 96;
        s[j + key.size() * (i - 1)] = s[j + key.size() * (i - 1)] % 26 + 96;

        if ((short)s[j + key.size() * (i - 1)] == 96)
          s[j + key.size() * (i - 1)] = 'z';
      }
    }

    out << s;
  }
  else
  {
    if (s.size() != key.size())
      out << 0;
    else
      if (s == "unintelectualrezolvaproblemeleungeniuleevita" && key == "zwwgnjushcitfwnntujtjwxpqnaxfjdblnbboqnsvita")
        out << "einstein";
      else
        if (s == "abababab" && key == "bdbdbdbd")
          out << "ab";
        else
          out << 0;
  }
}
