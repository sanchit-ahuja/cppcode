#!/usr/bin/env python
# -*- coding: utf-8 -*-
# @Date    : 2020-09-12 15:09:19
# @Author  : Sanchit Ahuja (you@example.org)
# @Link    : link
# @Version : 1.0.0

import os

def isub(s, t) : 
    t = iter(t)
    return all(c in t for c in s)

def solve(wordtosyn, wordtoant) : 
    cnt = 0
    syn_set = set()
    ant_set = set()
    for word in wordtosyn: 
        temp_li = word.split(':')
        temp_words = temp_li[1].split(',')
        for syn in temp_words: 
            if isub(syn, temp_li[0]) :
                if syn not in syn_set: 
                    cnt += 1
                    syn_set.add(syn)
    
    for word in wordtoant: 
        temp_li = word.split(':')
        temp_words = temp_li[1].split(',')
        print(temp_li[0],temp_words)
        for syn in temp_words: 
            if isub(syn, temp_li[0]) :
                if syn not in ant_set :
                    cnt+=1
                    ant_set.add(syn)
    return cnt



if __name__ == "__main__":
    wordtosyn = ["encourage:urge,boost,inspire","container:tin,bag,can,bottle","lighted:lit","illuminated:lit"]
    word2ant = ["encourage:discourage","animosity:amity,like","lighted:dark"]
    print(solve(wordtosyn,word2ant))
    pass