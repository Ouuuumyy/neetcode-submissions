class TrieNode {
    public: 
    TrieNode* children[26];
    bool isEnd;

    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }

    ~TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++)
            delete children[i];
    }
};

class WordDictionary {
private:
    TrieNode *dictionary;
public:
    WordDictionary() {
        dictionary = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode *curr = dictionary;
        for(char c : word)
        {
            if(!curr->children[c - 'a'])
                curr->children[c - 'a'] = new TrieNode();
            curr = curr->children[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool subSearch(string word, int i, TrieNode *curr)
    {
        if(i == word.length())
            return curr->isEnd;
        char c = word[i];
        if(c == '.')
        {
            for(int j = 0; j < 26; j++)
            {
                if(curr->children[j] && subSearch(word, i + 1, curr->children[j]))
                    return true;
            }
            return false;
        }
        else if(!curr->children[c - 'a'])
            return false;

        curr = curr->children[c - 'a'];
        
        return subSearch(word, i + 1, curr);

    }
    bool search(string word) {
        TrieNode *curr = dictionary;
        return subSearch(word, 0, curr);
    }
};
