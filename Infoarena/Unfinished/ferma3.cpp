#include <fstream>
#include <queue>
#include <vector>

using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
/*ifstream in("ferma3.in");
ofstream out("ferma3.out");*/

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

  bool operator ==(dot b)
  {
    return (this->i == b.i && this->j == b.j);
  }
};

struct matrix
{
  short clr;
  int lee;
};

dot p, e, crr, temp, d[4], sol;
queue<dot> que;
matrix a[401][401];
vector<int> aoe;
char c;
short caz, n, m;
int aoemax, aoecnt, aoetemp;

bool isin(dot p)
{
  return (p.i >= 1 && p.i <= n && p.j >= 1 && p.j <= m);
}

void flood_fill()
{
  a[p.i][p.j].lee = aoecnt;
  que.push(p);

  while (!que.empty())
  {
    crr = que.front();
    que.pop();

    for (short i = 0; i <= 3; ++i)
    {
      temp = crr + d[i];

      if (isin(temp) && a[temp.i][temp.j].lee == 0 && a[temp.i][temp.j].clr == a[crr.i][crr.j].clr)
      {
        a[temp.i][temp.j].lee = aoecnt;
        ++aoetemp;
        que.push(temp);
      }
    }
  }
}

bool isntsame(dot p, dot crr, dot temp)
{
  if (!(p == crr || p == temp || crr == temp))
    if (a[crr.i][crr.j].clr == a[temp.i][temp.j].clr)
      if (a[p.i][p.j].clr != a[crr.i][crr.j].clr)
        if (a[p.i][p.j].clr != a[temp.i][temp.j].clr)
          return 1;

  return 0;
}

int main()
{
  d[0].i = -1;
  d[1].j = 1;
  d[2].i = 1;
  d[3].j = -1;

  in >> caz >> n >> m;

  for (short i = 1; i <= n; ++i)
    for (short j = 1; j <= m; ++j)
      in >> c, a[i][j].clr = c - '96';

  aoe.push_back(0);

  for (short i = 1; i <= n; ++i)
    for (short j = 1; j <= m; ++j)
      if (a[i][j].lee == 0)
      {
        ++aoecnt;

        aoemax = max(aoemax, aoetemp);
        aoetemp = 1;

        p.i = i;
        p.j = j;

        flood_fill();

        aoe.push_back(aoetemp);
      }

  if (caz == 1)
    out << aoemax;
  else
  {
    aoetemp = 0;
    aoemax = 0;

    for (short i = 1; i <= n; ++i)
      for (short j = 1; j <= m; ++j)
        for (short k = 0; k <= 3; ++k)
          for (short l = k; l <= 3; ++l)
            if (k != l)
            {
              p.i = i, p.j = j;
              crr = p + d[k];
              temp = p + d[l];

              if (isntsame(p, crr, temp))
              {
                aoetemp = 1 + aoe[a[crr.i][crr.j].lee] + aoe[a[temp.i][temp.j].lee];

                if (aoetemp >= aoemax)
                {
                  sol = p;
                  aoemax = aoetemp;
                }
              }
            }

    out << sol.i << ' ' << sol.j;
  }
}