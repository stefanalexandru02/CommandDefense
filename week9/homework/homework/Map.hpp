#ifndef Map_hpp
#define Map_hpp
#include <stdio.h>

template <class K, class V>
class Map
{
    class Node;
private:
    static Node* searchNode;
    Node* firstNode;
    int index = 0;
    Node* createNode(const K& key)
    {
        if(firstNode == nullptr)
        {
            firstNode = new Node(key, NULL, index++);
            return firstNode;
        }
        else
        {
            Node *lastNode = firstNode;
            while(lastNode->nextNode != nullptr)
                lastNode = lastNode->nextNode;
            Node *newNode = new Node(key, NULL, index++);
            lastNode->nextNode = newNode;
            return newNode;
        }
    }
    Node* getNode(const K& key)
    {
        if(firstNode == NULL) return NULL;
        Node *currentNode = firstNode;
        do
        {
            if(currentNode->key == key)
            {
                return currentNode;
            }
            currentNode = currentNode -> nextNode;
        }
        while(currentNode != nullptr);
        return NULL;
    }
    
    class Node
    {
    public:
        Node* nextNode;
        K key;
        V value;
        int index;
        Node(K key, V value, int index)
        {
            this->key = key;
            this->value = value;
            this->nextNode = nullptr;
            this->index = index;
        }
        friend class Map;
    };
public:
    class Iterator;
    const Iterator begin() const
    {
        return Iterator(firstNode);
    }
     
    const Iterator end() const
    {
        return Iterator(nullptr);
    }
    
    class Iterator
    {
    public:
        struct NodePayload
        {
            K key;
            V value;
            int index;
        };
        
        Iterator() noexcept :
            m_pCurrentNode (searchNode) { }
     
        Iterator(const Node* pNode) noexcept :
            m_pCurrentNode (pNode) { }
     
            Iterator& operator=(Node* pNode)
            {
                this->m_pCurrentNode = pNode;
                return *this;
            }
    
            Iterator& operator++()
            {
                if (m_pCurrentNode)
                    m_pCurrentNode = m_pCurrentNode->nextNode;
                return *this;
            }
     
            Iterator operator++(int)
            {
                Iterator iterator = *this;
                ++*this;
                return iterator;
            }
     
            bool operator!=(const Iterator& iterator)
            {
                return m_pCurrentNode != iterator.m_pCurrentNode;
            }
     
            const NodePayload operator*()
            {
                return NodePayload{
                    m_pCurrentNode->key,
                    m_pCurrentNode->value,
                    m_pCurrentNode->index
                };
            }
     
        private:
            const Node* m_pCurrentNode;
    };
    
    Map() noexcept {
        this->firstNode = nullptr;
    }
    void Set(const K& key, V& value)
    {
        Node *newNode = createNode(key);
        newNode->value = value;
    }
    
    bool Get(const K& key, V& value)
    {
        Node *n = getNode(key);
        if(n == NULL)
            return false;
        else
        {
            value = n->value;
            return true;
        }
    }
    V & operator[] (K key)
    {
        Node *n = getNode(key);
        if(n != NULL)
        {
            return n->value;
        }
        else
        {
            Node *newNode = createNode(key);
            return newNode->value;
        }
    }
    
    friend bool operator==(const Map& first, const Map& second)
    {
        int len = first.Count();
        if(len != second.Count())
            return false;
        V *v = new V[len];
        K *k = new K[len];
        for (auto[key, value, index] : first)
        {
            v[index] = value;
            k[index] = key;
        }
        for (auto[key, value, index] : second)
        {
            if(v[index] != value)
                return false;
            if(k[index] != key)
                return false;
        }
        return true;
    }
    
    const int Count() const
    {
        return index;
    }
    const Node* GetByIndex(int index) const
    {
        int cnt = 0;
        Node* s = firstNode;
        while(s != nullptr)
        {
            if(cnt == index)
                return s;
            cnt++;
            s = firstNode->nextNode;
        }
        return nullptr;
    }
    void Clear(Node* node)
    {
        if(node->nextNode != NULL)
            Clear(node->nextNode);
        delete node;
    }
    void Clear()
    {
        Clear(firstNode);
    }
    bool Delete(const K& key)
    {
        if(firstNode->key == key)
        {
            Node *t = firstNode;
            firstNode = firstNode->nextNode;
            delete t;
            return true;
        }
        else
        {
            Node* s = firstNode;
            while(s->nextNode != NULL)
            {
                if(s->nextNode->key == key)
                {
                    Node *t = firstNode->nextNode;
                    s->nextNode = s->nextNode->nextNode;
                    delete t;
                    return true;
                }
            }
            return false;
        }
    }
    bool Includes(const Map<K,V>& map)
    {
        Map<K,V> tempMap;
        for (auto[key, value, index] : map)
        {
            Node* n = getNode(key);
            if(n != NULL)
            {
                tempMap[key] = n->value;
            }
        }
        return tempMap == map;
    }
};

template <class K, class V>
class Map<K,V>::Node* Map<K,V>::searchNode = nullptr;

#endif /* Map_hpp */
