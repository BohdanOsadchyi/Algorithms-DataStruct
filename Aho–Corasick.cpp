#define ALPHABET 95
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

class CTrie;

class item{
 protected :
   int p;
   int pch;
   int link;
   int next[ALPHABET];
   int go[ALPHABET];
   bool leaf;
   int terminal;
 public :
   item(){
     p = link = terminal = -1;
     memset (next, -1, sizeof (next));
     memset (go, -1, sizeof (go));
     leaf = false;
   }
   friend class CTrie;
};

class CTrie : protected item{
   protected :
     vector <item> trie;
   public :

     CTrie(){
       item temp;
       trie.push_back (temp);
     }

      void add_string (string &s){
       int v = 0, c;
       for (int i = 0;i < (int)s.length();i++){
         c = s[i] - ' ';
         if (trie[v].next[c] == -1){
           item temp;
           trie[v].next[c] = (int)trie.size();
           temp.p = v;
           temp.pch = c;
           trie.push_back (temp);
         }
         v = trie[v].next[c];
       }
       trie[v].leaf = true;
       trie[v].terminal = 1;
     }

     int go (int v, int c);

     int get_link (int v){
       if (trie[v].link == -1)
         if (v == 0 || trie[v].p == 0)
           trie[v].link = 0;
         else
           trie[v].link = go (get_link (trie[v].p), trie[v].pch);
       return trie[v].link;
     }

     bool f (string &s){
      int v = 0, c;
       for (int i = 0;i < (int)s.length();i++){
         c = s[i] - ' ';
        if (trie[v].next[c] == -1)
           v = go (v, c);
         else
           v = trie[v].next[c];
        if (IsTerminal (v))
           return true;

       }
       return false;
     }

    int IsTerminal (int v){
      if (v <= 0)
        return 0;
      if (trie[v].terminal != -1)
        return trie[v].terminal;
      return trie[v].terminal = IsTerminal (get_link (v));
    }
};

int CTrie :: go (int v, int c){
 if (trie[v].go[c] == -1)
   if (trie[v].next[c] != -1)
     trie[v].go[c] = trie[v].next[c];
   else
     trie[v].go[c] = (v == 0) ? 0 : go (get_link(v), c);
 return trie[v].go[c];
}

int main(){
 CTrie trie;
 int n;
 string s;
 char *c = (char *)malloc (256);
 scanf ("%d\n", &n);
 while (n--){
   gets (c);
   s = c;
   trie.add_string (s);
 }
 while (gets (c)){
   s = c;
   if (trie.f (s))
     printf ("%s\n", s.c_str());
 }
 return 0;
}
