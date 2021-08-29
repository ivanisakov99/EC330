#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cctype>
#include <vector>

using namespace std;

/*****************************************  Part A  *****************************************/
void fourA(string file){
    char character;
	int len = 0;
	int TotalSum = 0;
	int BUID = 0;
	bool done = false;
	ifstream input;
	input.open(file);
	
	while(!input.eof()){
        // Get each character
		input.get(character);

		if(character == 'U'){
            // Are next 8 characters integers?
			while(len < 8 && !done){
				input.get(character);

				if(isdigit(character)){ // Valid character
					TotalSum += character - '0';
					len++;
				}
				else if(character == 'U'){  // Restart
					len = 0;
					TotalSum = 0;
				}
				else{
                    done = true;
                }
			}

            // 8 digits and between 31 and 68
			if(len == 8 && TotalSum >= 31 && TotalSum <= 68){
				input.get(character);{
					if(!isdigit(character)){
						BUID++; // Meets all of the criteria
					}
				}
			}

            // Reset
			TotalSum = 0;
			len = 0; 
			done = false;
		}
	}
	cout << BUID << endl;
}

/*****************************************  Part B  *****************************************/

class Node {
public:
    Node() { 
        mContent = ' '; 
        mMarker = false; 
    }
    ~Node();
    char content(){ 
        return mContent; 
    }
    void setContent(char c) { 
        mContent = c; 
    }
    bool wordMarker() { 
        return mMarker; 
    }
    void setWordMarker() {
        mMarker = true; 
    }
    Node* findChild(char c);
    void appendChild(Node* child) { 
        mChildren.push_back(child); 
    }
    vector<Node*> children() {
        return mChildren; 
    }

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
    for(int i = 0; i < mChildren.size(); i++){
        Node* tmp = mChildren.at(i);
        if(tmp->content() == c){
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

void Trie::addWord(string s){
    Node* current = root;

    if(s.length() == 0){
        current->setWordMarker(); // an empty word
        return;
    }

    for(int i = 0; i < s.length(); i++){        
        Node* child = current->findChild(s[i]);
        if(child != NULL){
            current = child;
        }
        else{
            Node* tmp = new Node();
            tmp->setContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
        }
        if ( i == s.length() - 1 ){
            current->setWordMarker();
        }
    }
}


int Trie::searchWord(string s){
    Node* current = root;

    while(current != NULL){
        for(int i = 0; i < s.length(); i++){
            Node* tmp = current->findChild(s[i]);
            if (tmp == NULL){
                return 1;
            }
            current = tmp;
        }

        if(current->wordMarker()){
            return 2;
        }
        else{
            return 0;
        }
    }
    return 1;
}

void fourB(string file){
    // Once you make the trie data structure, you insert all the words from the dictionary.txt to populate the trie.
    Trie* trie = new Trie();
    string line = "";

    char first_name_letter = 'I';
    string dictionary_file = "dictionary.txt";

    ifstream dictionary(dictionary_file);
    int countW = 0;
    while(getline(dictionary, line)){
        if(line[0] == first_name_letter || line[0] == (first_name_letter + 32)){
            continue;
        }
        else{
            trie->addWord(line);   
            countW++;
        }
    }
    dictionary.close();
    

	// Open up the data text file and get the string text for each time there is a space
    int num_of_words = 0;
    ifstream data(file);
    while(getline(data, line, ' ')){
        
	// starting from the start of your string text, you iterate through to find any word
        for(int i = 0; i < line.length(); i++){
		    // this for loop allows you to make substrings 
            for(int j = 1; j < line.length() - i + 1; j++){
                string testing = line.substr(i,j);

                int number = trie->searchWord(testing);
		        // number equals 2 when 
                if(number == 2){
		            num_of_words++;  
                } 
                else if(number == 1){
                    break;
                }
            }
        }
    }
    cout << "Number of words: "<< num_of_words << endl;
    delete trie;
}

/*****************************************  Part C  *****************************************/

int LongestPalindrome(char* str){ 
    // The result (length of LPS) 
    int maxLength = 1; 
  
    int start = 0; 
    int len = strlen(str); 
  
    int low, high; 
  
    // One by one consider every 
    // character as center point of 
    // even and length palindromes 
    for(int i = 1; i < len; ++i) { 
        // Find the longest even length palindrome 
        // with center points as i-1 and i. 
        low = i - 1; 
        high = i; 
        while(low >= 0 && high < len && str[low] == str[high]){ 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
  
        // Find the longest odd length 
        // palindrome with center point as i 
        low = i - 1; 
        high = i + 1; 
        while(low >= 0 && high < len && str[low] == str[high]) { 
            if(high - low + 1 > maxLength){ 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
    } 
  
    cout << "The longest palindrome is: "; 
   
    for(int i = start; i <= (start + maxLength - 1); ++i){ 
        if(str[i] == ' '){
            cout << "_";
        }
        else{
            cout << str[i]; 
        }
    }
    
    return maxLength; 
} 

void fourC(string file){
    std::ifstream is (file, std::ifstream::binary);
    if (is) {
        is.seekg (0, is.end);
        int length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];
        is.read (buffer,length);
        is.close();

        int len = LongestPalindrome(buffer);
        cout << "\nLength = " << len << endl; 
        
        delete[] buffer;
    }
}
