#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <fstream>

using namespace std;
int next_id = 0;
int count = 0;
struct Node
{   Node *suff;
    Node *next[256];
    vector<int> pats;
    vector<char> out;
    int id; /* for debugging only */

    Node()
    {   id = next_id++;
        suff = 0;
        for(int i = 0; i < 256; i++)
        {   next[i] = 0;
        }
    }
};

class AhoCorasick
{   Node *trie;

    Node *suffix(Node *x, char c)
    {   while(x->next[c] == 0)
        {   x = x->suff;
        }
        return x->next[c];
    }

    void insert(Node *x, string s, int id)
    {   for(int i = 0; i < s.size(); i++)
        {   if(x->next[s[i]] == 0)
            {   x->next[s[i]] = new Node;
                x->out.push_back(s[i]);
            }
            x = x->next[s[i]];
        }
        x->pats.push_back(id);
    }

    public:
    AhoCorasick(vector<string> &p){   
        trie = new Node;

        for(int i = 0; i < p.size(); i++){   
            insert(trie, p[i], i);
        }

        queue<Node *> q;
        for(int i = 0; i < 256; i++)
        {   if(trie->next[i])
            {   trie->next[i]->suff = trie;
                q.push(trie->next[i]);
            }
            else
            {   trie->next[i] = trie;
            }
        }

        while(q.empty() == 0)
        {   Node *x = q.front(); q.pop();
            for(int i = 0; i < x->out.size(); i++)
            {   Node *y = x->next[x->out[i]];
                y->suff = suffix(x->suff, x->out[i]);
                y->pats.insert(y->pats.end(), y->suff->pats.begin(), y->suff->pats.end());
                q.push(y);
            }
        }
    }

    void match(string s)
    {   Node *x = trie;
        int cnt = 0;
        for(int i = 0; i < s.size(); i++)
        {   x = suffix(x, s[i]);
            //x->pats contains id's of matched patterns
            cout << x->id <<endl;
        }
    }
};

int main(void)
{
    string file1 = "dictionary.txt";
    ifstream dictionary(file1);
    string word;   
    vector<string> patterns;
    while(getline(dictionary, word)){
        if(word[0] != 'i' || word[0] != 'I'){
            patterns.push_back(word);
        }
    }

    AhoCorasick ac(patterns);

    dictionary.close();

    string file2 = "TinyData.txt";
    ifstream data(file2);

    while (getline(data, word)){
        ac.match(word);
    }

    return 0;
}
