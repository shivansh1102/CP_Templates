/* Bit trie */
class TrieNode
{
    public : 
    TrieNode* child[2];
    int precnt;
    TrieNode()
    {
        for(int i = 0; i < 2; i++)
        child[i] = NULL;
        precnt = 0;
    }
    ~TrieNode()
    {
        for(int i = 0; i < 2; i++)
        delete child[i];
    }
};
class BitTrie
{
    TrieNode* root; int MB; // maximum bits - 31 or 63 or something else
    public : 
    BitTrie(int maxbit) :  MB(maxbit) 
    {
        root = new TrieNode();
    }
    void insert(int x)
    {
        TrieNode* curr = root; int bit;
        for(int i = MB-1; i >= 0; i--)
        {
            curr->precnt++;
            bit = (x>>i)&1;
            if(curr->child[bit] == NULL)
            curr->child[bit] = new TrieNode();
            curr = curr->child[bit];
        }
        curr->precnt++;
    }
    void Delete(int x)
    {
        TrieNode* curr = root; int bit;
        for(int i = MB-1; i >= 0; i--)
        {
            curr->precnt--;
            bit = (x>>i)&1;
            curr = curr->child[bit];
        }
        curr->precnt--;
    }
    ~BitTrie()
    {
        delete root;
    }
};
