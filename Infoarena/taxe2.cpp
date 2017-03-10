#include <fstream>
#include <queue>

using namespace std;

ifstream in("taxe2.in");
ofstream out("taxe2.out");

struct dot
{
  short i, j;

  dot operator +(dot b)
  {
    dot a;

    a.i = this->i + b.i;
    a.j = this->j + b.j;

    return a;
  }

  static dot make(short i, short j)
  {
    dot a;

    a.i = i;
    a.j = j;

    return a;
  }
};

struct matrix
{
  short tax, lee;
};

dot d[4];
matrix a[101][101];
short s, n;

bool isin(dot p)
{
  return (p.i >= 1 && p.i <= n && p.j >= 1 && p.j <= n);
}

void lee()
{
  queue<dot> que;
  dot crr, temp;

  que.push(dot::make(1, 1));

  while (!que.empty())
  {
    crr = que.front();
    que.pop();

    for (short i = 0; i <= 3; ++i)
    {
      temp = crr + d[i];

      if (isin(temp) && a[temp.i][temp.j].lee > a[crr.i][crr.j].lee + a[temp.i][temp.j].tax)
      {
        a[temp.i][temp.j].lee = a[crr.i][crr.j].lee + a[temp.i][temp.j].tax;

        que.push(temp);
      }
    }
  }
}

int main()
{
  d[0].i = -1;
  d[1].j = -1;
  d[2].i = 1;
  d[3].j = 1;

  in >> s >> n;

  for (short i = 1; i <= n; ++i)
    for (short j = 1; j <= n; ++j)
      in >> a[i][j].tax, a[i][j].lee = 32767;

  a[1][1].lee = a[1][1].tax;
  lee();

  if (a[n][n].lee > s)
    out << -1;
  else
    out << s - a[n][n].lee;
}
