/* KMP algo to get lps[] */
void KMP(string &s, vector<int>&lps)
{
    int n = s.size(), j;
    lps[0] = 0;
    for(int i = 1; i < n; i++)
    {
        j = lps[i-1];
        while(j > 0 && s[j] != s[i]) 
        j = lps[j-1];
        if(s[i] == s[j])
        j++;
        lps[i] = j;
    }
}
