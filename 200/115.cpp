/*

*/

int numDistinct(string &S, string &T) 
{
      int ls = S.size();
      int lt = T.size();
      if(lt > ls)
        return 0;
        
      if(lt == 0)
        return 1;

      if(lt == ls)
        return S == T;

      vector<vector<int> > aux(lt + 1, vector<int>(ls + 1, 0));
      for(int i = 0; i < ls + 1; ++i)
        aux[0][i] = 1;

      for (int i = 1; i < lt + 1; ++i)
    	{
      	for (int j = i; j < ls + 1; ++j)
    		  aux[i][j] = aux[i][j - 1] + (T[i - 1] != S[j - 1] ? 0 : aux[i - 1][j - 1]);
    	}
        
      return aux[lt][ls];
}
