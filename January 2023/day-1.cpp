/*
290. Word Pattern
https://leetcode.com/problems/word-pattern/
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Input: pattern = "abba", s = "dog cat cat fish"
Output: false
*/


class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        stringstream ss(s);
        string word;
        
        vector<string> words;
        
        while(ss >> word){
            words.push_back(word);
        }
        
        if(words.size() !=pattern.size()){
            return false;
        }
        
        unordered_map<char, string>m;
        
        set<string>used;
        
        for(int i=0; i<words.size(); i++){
            
            if(m.count(pattern[i])){
                if(m[pattern[i]] != words[i]){
                    return false;
                }
            }
            else{
                if(used.find(words[i]) != used.end()){
                    return false;
                }
            }
            m[pattern[i]]=words[i];
            used.insert(words[i]);
        }
        
        return true;
    }
};