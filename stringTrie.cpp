/* String Trie */
class TrieNode
{
    public : 
    TrieNode* child[26];
    int cnt; // count of string which ends here
    int precnt; // count of string which has this string as prefix
    TrieNode()
    {
        for(int i = 0; i < 26; i++)
        child[i] = NULL;
        cnt = 0;
        precnt = 0;
    }
    ~TrieNode()
    {
        for(int i = 0; i < 26; i++)
        {
            if(child[i])
            delete child[i];
        }
    }
};
class StringTrie
{
    TrieNode* root;
    public : 
    StringTrie()
    {
        root = new TrieNode();
    }
    ~StringTrie()
    {
        delete root;
    }
    void insert(string &s)
    {
        TrieNode* curr = root;
        int n = s.size(), x;
        for(int i = 0; i < n; i++)
        {
            curr->precnt++;
            x = s[i] - 'a';
            if(curr->child[x] == NULL)
            curr->child[x] = new TrieNode();
            curr = curr->child[x];
        }
        curr->precnt++; curr->cnt++;
    }
    void Delete(string &s) // assuming s exists
    {
        TrieNode* curr = root;
        int n = s.size(), x;
        for(int i = 0; i < n; i++)
        {
            curr->precnt--;
            x = s[i] - 'a';
            curr = curr->child[x];
        }
        curr->precnt--; curr->cnt--;
    }
};
