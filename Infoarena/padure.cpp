#include <fstream>
#include <deque>
#include <climits>

using namespace std;
ifstream in("padure.in");
ofstream out("padure.out");

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
};

struct matrix
{
  short tax;
  int lee;
};

dot p, e, crr, temp, d[8];
deque<dot> que;
matrix a[1001][1001];
short n, m;

bool isin(dot p)
{
  return (p.i >= 1 && p.i <= n && p.j >= 1 && p.j <= m);
}

int cost(dot p, dot e)
{
  return (a[p.i][p.j].tax != a[e.i][e.j].tax);
}

void lee()
{
  a[p.i][p.j].lee = 0;
  que.push_front(p);

  while (!que.empty())
  {
    crr = que.front();
    que.pop_front();

    for (short i = 0; i <= 3; ++i)
    {
      temp = crr + d[i];

      if (isin(temp) && a[temp.i][temp.j].lee > a[crr.i][crr.j].lee + cost(crr, temp))
      {
        a[temp.i][temp.j].lee = a[crr.i][crr.j].lee + cost(crr, temp);

        if (cost(crr, temp) == 0)
          que.push_front(temp);
        else
          que.push_back(temp);
      }
    }
  }
}

int main()
{
  d[0].i = -1;
  d[1].j = 1;
  d[2].i = 1;
  d[3].j = -1;

  in >> n >> m >> p.i >> p.j >> e.i >> e.j;

  for (short i = 1; i <= n; ++i)
    for (short j = 1; j <= m; ++j)
      in >> a[i][j].tax, a[i][j].lee = INT_MAX;

  lee();
  out << a[e.i][e.j].lee;
}