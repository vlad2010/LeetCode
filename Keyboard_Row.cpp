/*

500. Keyboard Row


Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]


    You may use one character in the keyboard more than once.
    You may assume the input string will only contain letters of alphabet.


*/



class Solution {
public:
    
    set<char> getWordMap(string w)
    {
        set<char> umap;   
        for(char s : w)
        {
            umap.insert(tolower(s));
        }
        return umap;
    }
    
    
    bool checkWord(vector<set<char>> &rows, set<char> &word )
    {
        bool res = false;
        for(auto nextset : rows)
        {
            set<char> intersect;
            set_intersection(nextset.begin(), nextset.end(), word.begin(),word.end(),
                  std::inserter(intersect,intersect.begin()));

            if(intersect == word)            
            {
                res = true;
                break;
            }
        }
        
        return res; 
    }
    
    vector<string> findWords(vector<string>& words) {
       
        set<char> st1 = getWordMap("qwertyuiop");
        set<char> st2 = getWordMap("asdfghjkl");
        set<char> st3 = getWordMap("zxcvbnm");
        
        vector<set<char>> keyboard;
        keyboard.push_back(st1);
        keyboard.push_back(st2);
        keyboard.push_back(st3);
           
       vector<string> answer; 
       for (string x : words) 
       {
           set<char> wordMap = getWordMap(x);
           if(checkWord(keyboard, wordMap))
               answer.push_back(x);           
       }
        
       return answer; 
    }
};