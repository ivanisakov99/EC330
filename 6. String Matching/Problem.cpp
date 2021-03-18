#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <cctype>
#include <map> 

using namespace std;

int BUIDSearch(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int c = 0;
    string num;
    int sum = 0, osum = 0;
  
    int i = 0; // index for txt[] 
    int j = 0; // index for pat[] 
    while (i < N) { 
        
        if ( pat[j] == 'U' && pat[j] == txt[i] ) { 
            j++; 
            i++;
            
        }else if( pat[j] == '?' ){
            if(isdigit(txt[i])){
                num = txt[i];
                sum = sum + stoi(num);
                
                j++; 
                i++; 
            }else{
                i++;
                j = 0;
            }
        }else if( pat[j] == 'x' ){
            if(!isdigit(txt[i])){
                osum = sum;
                j++;
                i++;
            }else{
                i++;
                j = 0;
            }
        }else{
            i++;
            j = 0;
            sum = 0;
        }

        if (j == M) { 
            if(osum > 30 && osum < 69){
                c++;
            }
            osum = 0;
            sum = 0;
            j = 0;
            i++;
        } 
    } 
    return c;
} 

void fourA(){
    string file = "TinyData.txt";
    //string file = "BigData.txt";
    std::ifstream is (file, std::ifstream::binary);
    if (is) {
        // get length of file:
        is.seekg (0, is.end);
        int length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];

        std::cout << "Reading " << length << " characters... \n";
        // read data as a block:
        is.read (buffer,length);

        if (is)
        std::cout << "all characters read successfully.\n";
        else
        std::cout << "error: only " << is.gcount() << " could be read\n";
        is.close();


        char BUID[] = "U????????x";
        int num = 0;
        num = BUIDSearch(BUID, buffer);
        cout << "The number of BU IDs in the file " << file << " is: " << num << endl;
    

        delete[] buffer;
    }
}

# define NO_OF_CHARS 256  
  
// The preprocessing function for Boyer Moore's  
// bad character heuristic  
void badCharHeuristic( char* str, int size, int badchar[NO_OF_CHARS])  
{  
    int i;  
  
    
    for (i = 0; i < NO_OF_CHARS; i++) {
        badchar[i] = -1;  
    }
  
   
    for (i = 0; i < size; i++) {
        badchar[(int) str[i]] = i;  
    }
}  
  
/* A pattern searching function that uses Bad  
Character Heuristic of Boyer Moore Algorithm */
int search(char *pat, char *txt)  
{  
    int c = 0;
    int m = strlen(pat);  
    int n = strlen(txt);  
  
    int badchar[NO_OF_CHARS];  
  
    /* Fill the bad character array by calling  
    the preprocessing function badCharHeuristic()  
    for given pattern */
    badCharHeuristic(pat, m, badchar);  
  
    int s = 0; 
    while(s <= (n - m))  
    {  
        int j = m - 1;  
  
       
        while(j >= 0 && pat[j] == txt[s + j])  
            j--;  
  
        
        if (j < 0)  
        {  
            c++;
            
            s += (s + m < n)? m-badchar[txt[s + m]] : 1;  
  
        }  
  
        else
            
            s += max(1, j - badchar[txt[s + j]]);  
    }  
    return c;
} 




void fourB(){
    string file1 = "dictionary.txt";
    map<string, unsigned int> wordsCount;
    ifstream dictionary(file1);
    string word;
    while (getline(dictionary, word))
    {
        if(word[0] == 'I' || word[0] == 'i'){
            continue;
        }else{
            if (wordsCount.find(word) == wordsCount.end()){ // Then we've encountered the word for a first time.
                wordsCount[word] = 0; // Initialize it to 0.
            }
            else{ // Then we've already seen it before..
                wordsCount[word]++;// Just increment it.
            } 
        }
    }
    dictionary.close();
    
    //string file2 = "SmallData.txt";
    string file2 = "TinyData.txt";
    //string file2 = "BigData.txt";
    std::ifstream is (file2, std::ifstream::binary);
    if (is) {
        // get length of file:
        is.seekg (0, is.end);
        int length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];

        std::cout << "Reading " << length << " characters... \n";
        // read data as a block:
        is.read (buffer,length);

        if (is)
        std::cout << "all characters read successfully.\n";
        else
        std::cout << "error: only " << is.gcount() << " could be read\n";
        is.close();

        int count = 0, num = 0;
            
        for (std::map<string, unsigned int>::iterator p = wordsCount.begin(); p != wordsCount.end(); p++){
            int m = (p->first).length();
            char pat[m+1];
            strcpy(pat, (p->first).c_str());
            num = search(pat, buffer);
            (p->second) = num;
            count = count + num;
        }
        
        cout << "The number of English words found in " << file2 << " is " << count << endl;

        delete[] buffer;
       
    }
}

int LongestPalindrome(char* str) 
{ 
    // The result (length of LPS) 
    int maxLength = 1; 
  
    int start = 0; 
    int len = strlen(str); 
  
    int low, high; 
  
    // One by one consider every 
    // character as center point of 
    // even and length palindromes 
    for (int i = 1; i < len; ++i) { 
        // Find the longest even length palindrome 
        // with center points as i-1 and i. 
        low = i - 1; 
        high = i; 
        while (low >= 0 && high < len && str[low] == str[high]) { 
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
        while (low >= 0 && high < len 
               && str[low] == str[high]) { 
            if (high - low + 1 > maxLength) { 
                start = low; 
                maxLength = high - low + 1; 
            } 
            --low; 
            ++high; 
        } 
    } 
  
    cout << "The longest palindrome is: "; 
   
    for (int i = start; i <= (start + maxLength - 1); ++i){ 
        if(str[i] == ' '){
            cout << "_";
        }
        else{
            cout << str[i]; 
        }
    }
    
    return maxLength; 
} 

void fourC(){
    //string file = "TinyData.txt";
    string file = "BigData.txt";
    std::ifstream is (file, std::ifstream::binary);
    if (is) {
        // get length of file:
        is.seekg (0, is.end);
        int length = is.tellg();
        is.seekg (0, is.beg);

        char * buffer = new char [length];

        std::cout << "Reading " << length << " characters... \n";
        // read data as a block:
        is.read (buffer,length);

        if (is)
        std::cout << "all characters read successfully.\n";
        else
        std::cout << "error: only " << is.gcount() << " could be read\n";
        is.close();


        int len = LongestPalindrome(buffer);
   
        cout << "\nLength = " << len << endl; 
        
        delete[] buffer;
    }
}

int main(int argc, char** argv){
    cout << "\n\n---------------Problem 5a---------------\n\n" << endl;
    //fourA();
    cout << "\n\n---------------Problem 5b---------------\n\n" << endl;
    fourB();
    cout << "\n\n---------------Problem 5c---------------\n\n" << endl;
    //fourC();
    

	return 0;
}