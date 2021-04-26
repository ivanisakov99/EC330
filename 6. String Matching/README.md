# <ins>Problem: Big Data</ins>
This problem involves finding information in a very large data file, BigData.txt, similar to what you might find from the dump of a hard drive.

Within this file, determine:
1. The number of BU-IDs in the file whose digits add to a number between 31 and 68 (including 31 and 68). A BU ID is defined as anything starting with a U and
followed by exactly eight digits and then a non-digit.
2. The number of English words (from the dictionary.txt file) that appear in the file
that do not begin with the same letter of the alphabet as your first name (for example, if your first name begins with the letter ‘t’, then you should exclude dictionary words that begin with ‘t’). Note that case matters (e.g. ‘Ab’ is a dictionary word, and it is not considered the same as ‘ab’). The words do not need to be delimited by spaces (or other punctuation) in the file and may overlap. The words must be contiguous e.g: door$knob or door knob will not find doorknob, but will still find door, knob, or, etc. Duplicates do count. For example, the word “a”, which is a dictionary word, appears in the data more than once, and should be counted accordingly.
3. The longest palindrome (i.e. a string that equals its reverse) you can find within the text. When finding palindromes, consider ALL characters (spaces should count).

### <ins>Expected Outputs:</ins>

    Part A) 3

    Part B)
    A: 549425
    B: 551219
    C: 551672
    D: 551060
    E: 550572
    F: 551371
    G: 551468
    H: 551223
    I: 551180
    J: 551440
    K: 551722
    L: 551386
    M: 550929
    N: 551060
    O: 550432
    P: 551553
    Q: 552399
    R: 551615
    S: 551228
    T: 551101
    U: 550952
    V: 551820
    W: 551230
    X: 552041
    Y: 551154
    Z: 551648

    Part C) "bLEQELb"

