#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// The code used to construct the trie data structure was taken from a website
// http://www.sourcetricks.com/2011/06/c-tries.html#.VvyRi7wX6hc
// However, the provided trie data structure was taking too long so I had to make some modifications to decrease the time. 
// Given any jumble of texts, you have to iterate through the whole string to check if words exist in it. However, you know that once 
// you have reached a NULL, there is no point of continuing on because hitting the NULL means further texts will not provide words. When 
// this happens, you have to move on to the next element in the text string. 

using namespace std;

class Node {
public:
    Node() { mContent = ' '; mMarker = false; }
    ~Node() {}
    char content() { return mContent; }
    void setContent(char c) { mContent = c; }
    bool wordMarker() { return mMarker; }
    void setWordMarker() { mMarker = true; }
    Node* findChild(char c);
    void appendChild(Node* child) { mChildren.push_back(child); }
    vector<Node*> children() { return mChildren; }

private:
    char mContent;
    bool mMarker;
    vector<Node*> mChildren;
};

class Trie {
public:
    Trie();
    ~Trie();
    void addWord(string s);
    int searchWord(string s);
    void deleteWord(string s);
private:
    Node* root;
};

Node* Node::findChild(char c)
{
    for ( int i = 0; i < mChildren.size(); i++ ){
        Node* tmp = mChildren.at(i);
        if (tmp->content() == c){
            return tmp;
        }
    }
    return NULL;
}

Trie::Trie(){
    root = new Node();
}

Trie::~Trie(){
    // Free memory
}

void Trie::addWord(string s)
{
    Node* current = root;

    if ( s.length() == 0 )
    {
        current->setWordMarker(); // an empty word
        return;
    }

    for ( int i = 0; i < s.length(); i++ )
    {        
        Node* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 )
            current->setWordMarker();
    }
}


int Trie::searchWord(string s)
{
    Node* current = root;

    while (current != NULL){
        for ( int i = 0; i < s.length(); i++ ){
            Node* tmp = current->findChild(s[i]);
            if (tmp == NULL){
                return 1;
            }
            current = tmp;
        }

        if (current->wordMarker()){
            return 2;
        }
        else{
            return 0;
        }
    }

    return 1;
}


// Test program
int main()
{
    // Once you make the trie data structure, you insert all the words from the dictionary.txt to populate the trie.
	clock_t t1, t2;
	t1 = clock();
    Trie* trie = new Trie();
    string line = "";
    ifstream dictionary("dictionary.txt");
    while(!dictionary.eof())
    {
        getline(dictionary, line);
        trie->addWord(line);
    }
    dictionary.close();

    char firstcharUpper = 'I';
    char firstcharLower = 'i';

	// Open up the BigData text file and get the string text for each time there is a space
    int counter = 0;
    int counter_y = 0;
    ifstream BigData("TinyData.txt");
    while (!BigData.eof())
    {
        getline(BigData, line, ' ');
	// starting from the start of your string text, you iterate through to find any word
        for (int i = 0; i < line.length(); i++)
        {
		// this for loop allows you to make substrings 
            for (int j = 1; j < line.length() - i + 1; j++)
            {
                string testing = line.substr(i,j);

                int number = trie->searchWord(testing);
		// number equals 2 when 
                if (number == 2){
		            counter++;
                    if (testing[0] != firstcharUpper || testing[0] != firstcharLower){	
			            counter_y++;
		            } 
                } 
                else if (number == 1){
                    break;
                }
            }
        }
    }
    cout << "Number of words: "<< counter << endl;
    cout << "Number of words not starting with " << firstcharUpper << ": " << "or " << firstcharLower << ": " << counter_y << endl;
    delete trie;

	return 0;
}