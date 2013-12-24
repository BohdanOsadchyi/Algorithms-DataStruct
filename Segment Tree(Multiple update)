#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>

typedef __int64 ll;
typedef unsigned __int64 ull;

using namespace std;

const int N = 100100;

struct Node
{
  ll sum, add;
} t[4 * N];

void build(int v, int tl, int tr)
{
  if (tl == tr)
  {
    t[v].sum = 0;
    t[v].add = 0;
    return;
  }
  int tm = (tl + tr) / 2;
  build (v * 2, tl, tm);
  build (v * 2 + 1, tm + 1, tr);
  t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
  t[v].add = 0;
}

void Push(int v, int tl, int tm, int tr)
{
  if (t[v].add)
  {
    t[v * 2].add += t[v].add;
    t[v * 2].sum += ll((tm - tl + 1) * t[v].add);
    t[v * 2 + 1].add += t[v].add;
    t[v * 2 + 1].sum += ll((tr - tm) * t[v].add);
    t[v].add = 0;
  }
}

void AddValue(int v, int tl, int tr, int l, int r, ll val)
{
  if (l > r)
    return;
  if (l == tl && r == tr)
  {
    t[v].add += val;
    t[v].sum += ll( (r - l + 1) * val );
    return;
  }
  int tm = (tl + tr) / 2;
  Push(v, tl, tm, tr);
  AddValue (v * 2, tl, tm, l, min(tm, r), val);
  AddValue (v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
  t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
}

ll Summa (int v, int tl, int tr, int l, int r)
{
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v].sum;
  int tm = (tl + tr) / 2;
  Push (v, tl, tm, tr);
  return Summa (v * 2, tl, tm, l, min (tm, r)) +
         Summa (v * 2 + 1, tm + 1, tr, max (tm + 1, l), r);
}

int main(){
  int t;
  scanf ("%d", &t);
  while (t--)
  {
    int n, q;
    scanf ("%d%d", &n, &q);
    int c;
    int l, r;
    ll x;

    build (1, 0, n - 1);
    while (q--)
    {
      scanf ("%d%d%d", &c, &l, &r);
      //printf ("%c %d %d", c, l, r);
      if (c == 0)
      {
        scanf ("%I64d", &x);
        //printf (" %d", x);
        AddValue (1, 0, n - 1, l - 1, r - 1, x);
      }
      else
      {
        printf ("%I64d\n", Summa (1, 0, n - 1, l - 1, r - 1));
      }
      //printf ("\n");
    }

  }
  return 0;
}
