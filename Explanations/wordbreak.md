## LC Wordbreak

Given a string s, check if it can be segmented into space separated sequence.
For example 
```
    s = "leetcode" and word_dict = ["leet","code"]
    return true
```
Thinking should be this way if we find a substring which is part of the dict, we go into recursion to check the rest of the string.
For example we found out "leet" to be part of the dict, but we still have rest of the string to go. So go into recursion.
The code would make it more clearer:

```c++
    
    bool solve(string s,int i, set<string>&worddict) {
            if(i == s.size()) {
                return true; //End of the string
            }
        string temp;
        for(int j = i;j<s.size();j++) {
                temp += s[j];
                if(worddict.count(temp) && solve(s,j+1,worddict)) //We keep on building the string until we get our answer WHen we get it, we go into recursion for the next one until our string exhausts/
                 {
                    return true;
                }
        }
        return false;
        }

```
The above function will TLE. The complexity of the code is O(2^n) where n is the size of the string.
We can use top-down dp to cache the repeated results of all the possibilites.