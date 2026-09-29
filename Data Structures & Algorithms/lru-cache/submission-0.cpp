
struct Node{
    pair<int, int> pairs;
    Node *next;
    Node *prev;
    Node(int key, int val): pairs({key, val}), next(nullptr), prev(nullptr){};
};

class LRUCache {
private:
    unordered_map<int, Node *> cache;
    int cache_size = 0;
    Node *head;
    Node *tail;
public:
    LRUCache(int capacity) {
        cache_size = capacity;
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache(){
        while(head)
        {
            Node *tmp = head->next;
            delete(head);
            head = tmp;
        }
    }
    
    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertNode(Node *node)
    {
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {
        if(cache.find(key) == cache.end())
            return -1;
        Node *node = cache[key];
        removeNode(node);
        insertNode(node);
        return node->pairs.second;
    }
    
    void put(int key, int value) {

            if(cache.find(key) != cache.end())
            {
                Node *n = cache[key];
                n->pairs.second = value;
                removeNode(n);
                insertNode(n);
                return;
            }

            if(cache.size() == cache_size)
            {
                Node *lru = head->next;
                removeNode(head->next);
                cache.erase(lru->pairs.first);
                delete(lru);
            }

            Node *n = new Node(key, value);
            cache[key] = n;
            insertNode(n);

    }
};

