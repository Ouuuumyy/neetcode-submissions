class TrieNode {
    public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false){
        for(int i = 0; i < 26 ; i++)
            children[i] = nullptr;
    }

    ~TrieNode(){
        for(int i = 0; i < 26 ; i++)
            delete children[i];
    }
};


class PrefixTree {
private: 
    TrieNode *root;
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(char c : word)
        {
            if(!curr->children[c - 'a'])
            {
                curr->children[c - 'a'] = new TrieNode();
            }
            curr = curr->children[c - 'a'];
        }
        curr->isEndOfWord = true;
        
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char c : word)
        {
            if(curr->children[c - 'a'])
                curr = curr->children[c - 'a'];
            else
                return false;
        }
        return (curr != nullptr && curr->isEndOfWord);
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char c : prefix)
        {
            if(curr->children[c - 'a'])
                curr = curr->children[c - 'a'];
            else
                return false;
        }
        return (curr != nullptr);
    }
};
