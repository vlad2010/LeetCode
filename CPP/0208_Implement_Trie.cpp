/*
208. Implement Trie (Prefix Tree)
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:

    You may assume that all inputs are consist of lowercase letters a-z.
    All inputs are guaranteed to be non-empty strings.
*/

struct Node
{  
   char c = 0;
   bool isFinal = false;    
    
   Node * kid[26]; 
    
   Node(char cc):c(cc){
        memset(kid,0,sizeof(kid));
   }
    
    void print()
    {
        cout << "Node() Char : " << c << endl;
        
        for(int i=0; i<26;i++)
        {
            //cout << "---\n";
            Node *ck = kid[i];
            if(ck!=nullptr)
                 ck->print();
        }
    }
};


class Trie {
public:
    
    Node* head;
    
    /** Initialize your data structure here. */
    Trie() {
       head = new Node(' '); 
       head->print();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Node *curr = head;
        for(int i=0;i<word.size(); i++)
        {
            if(curr)
            {
                if(curr->kid[word[i]-97]!=nullptr)
                {
                    curr=curr->kid[word[i]-97];
                }
                else
                {
                    curr->kid[word[i]-97] = new Node(word[i]);
                    curr = curr->kid[word[i]-97]; 
                }
             }
        }
        
        curr->isFinal=true;
        
        // head->print();
    
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        
        Node *curr = head;
        for(int i=0;i<word.size(); i++)
        {
                // cout << "curr->kid[word[i]-97]: " << curr->kid[word[i]-97] << endl;
                // cout << " word[i]: " << word[i] << endl;    
            
                if(!curr->kid[word[i]-97])
                {
                    return false;
                }
                    
                curr=curr->kid[word[i]-97];
        }
        
        //check that last position has no kids 
        if(curr->isFinal)
            return true;    
        
        return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        
        Node *curr = head;
        for(int i=0;i<prefix.size(); i++)
        {
                // cout << "curr->kid[prefix[i]-97]: " << curr->kid[prefix[i]-97] << endl;
                // cout << " prefix[i]: " << prefix[i] << endl;    
            
                if(!curr->kid[prefix[i]-97])
                {
                    return false;
                }
                curr=curr->kid[prefix[i]-97];
        }
        return true;
    }
    
    
    void printTrie(Node* root)
    {
        
                
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */