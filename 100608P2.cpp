#include <fstream>
#include <algorithm>
#include <queue>

using namespace std;
ifstream in("retea.in");
ofstream out("retea.out");

struct dot
{
  short i, j;
};

struct matrix
{
  short net, lee;
};

dot p, e, crr, temp, d[4];
matrix a[101][101];
short n, m, caz, netcnt, netmax, nettemp;
queue <dot> que;

bool isin(dot p)
{
  return (p.i >= 1 && p.i <= n && p.j >= 1 && p.j <= m);
}

bool sqr(dot p, dot e)
{
  return (a[p.i][p.j].net != a[e.i][e.j].net);
}

void lee()
{
  a[p.i][p.j].lee = 0;
  que.push(p);

  while (!que.empty())
  {
    crr = que.front();
    que.pop();

    for (short i = 0; i <= 3; ++i)
    {
      temp.i = crr.i + d[i].i;
      temp.j = crr.j + d[i].j;

      if (isin(temp) && a[temp.i][temp.j].lee > a[crr.i][crr.j].lee + sqr(temp, crr))
      {
        a[temp.i][temp.j].lee = a[crr.i][crr.j].lee + sqr(temp, crr);
        que.push(temp);
      }
    }
  }
}

void fiil(dot p)
{
  a[p.i][p.j].lee = netcnt;
  que.push(p);

  while (!que.empty())
  {
    crr = que.front();
    que.pop();

    for (short i = 0; i <= 3; ++i)
    {
      temp.i = crr.i + d[i].i;
      temp.j = crr.j + d[i].j;

      if (isin(temp) && a[temp.i][temp.j].lee == 0 && a[temp.i][temp.j].net == a[crr.i][crr.j].net)
      {
        a[temp.i][temp.j].lee = netcnt;
        ++nettemp;
        que.push(temp);
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

  in >> caz >> n >> m >> p.i >> p.j >> e.i >> e.j;

  if (caz == 1)
  {
    for (short i = 1; i <= n; ++i)
      for (short j = 1; j <= m; ++j)
        in >> a[i][j].net;

    for (short i = 1; i <= n; ++i)
      for (short j = 1; j <= m; ++j)
        if (a[i][j].lee == 0)
          {
            ++netcnt;
            netmax = max(netmax, nettemp);
            nettemp = 1;

            p.i = i;
            p.j = j;
            fiil(p);
          }

    netmax = max(netmax, nettemp);
    out << netcnt << ' ' << netmax;
  }
  else
  {
    for (short i = 1; i <= n; ++i)
      for (short j = 1; j <= m; ++j)
      {
        in >> a[i][j].net;
        a[i][j].lee = 0x3f3f3f3f;
      }

    lee();
    out << a[e.i][e.j].lee;
  }
}
