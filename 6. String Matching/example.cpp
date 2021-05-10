#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#include "aho_corasick.h"

int main(int argc, const char * argv[])
{
    string file1 = "dictionary.txt";
    
    ifstream dictionary(file1);
    string word;

    
    // create instance
    AhoCorasick<std::string> automation;
    // add patterns to search for
    //automation.addPattern("quick");
    while(getline(dictionary, word)){
      if(word[0] != 'i' || word[0] != 'I'){
        automation.addPattern(word);
      }
      else{
        continue;
      }
    }

    dictionary.close();
    
    std::string string{"quick red fox jumps over lazy brown dog that owns brown house"};

    

    // get matcher object
    auto matcher = automation.matcher();
    
    // run search
    auto begin = std::begin(word);
    matcher.match([&begin](const std::string& pattern, decltype(begin) iterator)
    {
        // std::cout << "Matched \"" << pattern << "\" on position "
        // << std::distance(begin, iterator) << std::endl;
        
      return false;
  }, std::begin(word), std::end(word));
  
  std::cout << std::endl;
  
  // search can be performed on type different from pattern type
  std::vector<int> not_a_string;
  std::copy(std::begin(string), std::end(string), std::back_inserter(not_a_string));
  auto begin2 = std::begin(not_a_string);
  matcher.match([&begin2](const std::string& pattern, decltype(begin2) iterator)
  {
    std::cout << "Matched \"" << pattern << "\" on position "
      << std::distance(begin2, iterator) << std::endl;
      return false;
  }, std::begin(not_a_string), std::end(not_a_string));
}