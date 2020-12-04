#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2020-10-03 16:22:40
# @Author  : Sanchit (sanchitahuja205@gmail.com)
# @Link    : link
# @Version : 1.0.0
from collections import defaultdict

# Declaring a trienode
class TrieNode:
    def __init__(self) :
        self.is_end = False
        self.children = defaultdict(TrieNode)

#declaring a class trie that will contain all the methods for trie (insert, search & startswith)

class Trie:
    def __init__(self):
        self.node = TrieNode()
    
    def insert(self, word):
        curr_ref = self.node #Save the current reference
        for letter in word :
            if not curr_ref.children[letter]:
                curr_ref.children = TrieNode()
            curr_ref = curr_ref.children[letter]
        curr_ref.is_end = True
    
    def search(self, word) :
        curr_ref = self.node
        if not curr_ref :
            return False
        for letter in word:
            if not curr_ref.children[letter]: # if the letter not present, then the word not present
                return False 
            curr_ref = curr_ref.children[letter] # Go ahead in the node
        return curr_ref.is_end


if __name__ == "__main__":
    TrieObj = Trie()
    TrieObj.insert("hello")
    TrieObj.insert("welcome")
    TrieObj.insert('work')
    print(TrieObj.search("bye"))

"