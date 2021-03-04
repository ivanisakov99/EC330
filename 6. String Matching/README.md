### <ins>Problem: Big Data</ins>
This problem involves finding information in a very large data file, BigData.txt, similar to what you might find from the dump of a hard drive.

Within this file, determine:
1. The number of BU-IDs in the file whose digits add to a number between 31 and 68 (including 31 and 68). A BU ID is defined as anything starting with a U and
followed by exactly eight digits and then a non-digit.
2. The number of English words (from the dictionary.txt file) that appear in the file
that do not begin with the same letter of the alphabet as your first name (for example, if your first name begins with the letter ‘t’, then you should exclude dictionary words that begin with ‘t’). Note that case matters (e.g. ‘Ab’ is a dictionary word, and it is not considered the same as ‘ab’). The words do not need to be delimited by spaces (or other punctuation) in the file and may overlap. The words must be contiguous e.g: door$knob or door knob will not find doorknob, but will still find door, knob, or, etc. Duplicates do count. For example, the word “a”, which is a dictionary word, appears in the data more than once, and should be counted accordingly.
3. The longest palindrome (i.e. a string that equals its reverse) you can find within the text. When finding palindromes, consider ALL characters (spaces should count).

Provide your solutions (i.e. your output to each of the sections, along with a brief explanation of each of your solutions), in a file named Problem5.txt. Submit this file, along with your solution code. Your code must be submitted in a single file named Problem5.cpp. Your code should include three functions, fourA, fourB, and fourC, that when run with no arguments in the same directory as BigData.txt print out the results that you report. In order to receive full credit, your solution needs to be efficient.
