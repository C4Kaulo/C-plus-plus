#include <fstream>
#include <queue>

using namespace std;
ifstream in("alee.in"); ofstream out("alee.out");

struct dot
{
  int i, j;
};

struct matrix
{
  int tree, lee;
};

dot x, p, e, temp, rec, ways[5];
queue <dot> que;

matrix a[176][176];
int n, m;

bool ok(dot p)
{
  return (p.i >= 1 && p.i <= n && p.j >= 1 && p.j <= n && a[p.i][p.j].tree == 0);
}

void find_path()
{
  a[p.i][p.j].lee = 1;
  que.push(p);

  while (que.empty() == 0 && a[e.i][e.j].lee == 0)
  {
    p = que.front();
    rec = p;
    que.pop();

    for (int way = 1; way <= 4; ++way)
    {
      temp.i = rec.i + ways[way].i;
      temp.j = rec.j + ways[way].j;

      if (ok(temp) == 1 && a[temp.i][temp.j].lee == 0)
      {
        a[temp.i][temp.j].lee = a[rec.i][rec.j].lee + 1;
        p = temp;
        que.push(p);
      }
    }
  }
}

int main()
{
  ways[1].i = -1;
  ways[2].j = 1;
  ways[3].i = 1;
  ways[4].j = -1;

  in >> n >> m;

  for (int i = 1; i <= m; ++i)
    in >> x.i >> x.j, a[x.i][x.j].tree = 1;

  in >> p.i >> p.j >> e.i >> e.j;

  find_path();

  out << a[e.i][e.j].lee;
}
