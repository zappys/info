using namespace std;
#ifdef EZ
   #include "./ez/ez.h"
   const string FILE_NAME = "test";
#else
   #include <bits/stdc++.h>
   const string FILE_NAME = "unificare";
#endif
#define mp make_pair
#define mt make_tuple
#define ll long long
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define cin fin
#define cout fout
ifstream fin (FILE_NAME + ".in");
ofstream fout (FILE_NAME + ".out");

const int nMAX = 100e3;

int c, n, k;
int v[nMAX + 1];
vector<int> fv[nMAX + 1];

int main()
{
   cin >> c >> n >> k;
   for (int i = 1; i <= n; ++i)
   {
      cin >> v[i];

      fv[i].resize(10);
      int x = v[i];
      do {
         fv[i][x%10] = 1;
         x /= 10;
      } while (x);
   }
   
   if (c == 1)
   {
      int ans = 0;
      for (int i = 1; i <= n; ++i)
         if (1 + (int) log10(v[i]) == k)
            ans = max(ans, v[i]);
      
      cout << ans;
   }

   else if (c == 2)
   {
      ll ansmax = 0;

      for (int i = 2; i <= n; ++i)
      {
         if (v[i-1] == 0 && v[i] == 0)
            continue;
         
         ll ans = 0;
         for (int j = 9; j >= 0; --j)
         {
            if (fv[i-1][j])
               ans = ans*10 + j;
            if (fv[i][j])
               ans = ans*10 + j;
         }

         ansmax = max(ansmax, ans);
      }

      cout << ansmax;
   }

   else if (c == 3)
   {
      vector<int> fvv(10), fvvmax(10);

      for (int i = 1; i < k; ++i)
         for (int j = 0; j < 10; ++j)
            fvv[9-j] += fv[i][j];
      
      for (int i = k; i <= n; ++i)
      {
         for (int j = 0; j < 10; ++j)
            fvv[9-j] += fv[i][j];
         
         if (fvv > fvvmax)
            fvvmax = fvv;

         for (int j = 0; j < 10; ++j)
            fvv[9-j] -= fv[i-k+1][j];
      }

      if (accumulate(fvv.begin(), fvv.end()-1, 0) == 0)
         cout << '0';
      else
      {
         for (int i = 9; i >= 0; --i)
            for (int j = 0; j < fvvmax[9-i]; ++j)
               cout << i;
      }
   }
}