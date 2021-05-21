# <ins>Problem: Big Data</ins>
This problem involves finding information in a very large data file, BigData.txt, similar to what you might find from the dump of a hard drive.

Within this file, determine:
1. The number of BU-IDs in the file whose digits add to a number between 31 and 68 (including 31 and 68). A BU ID is defined as anything starting with a U and
followed by exactly eight digits and then a non-digit.
2. The number of English words (from the dictionary.txt file) that appear in the file
that do not begin with the same letter of the alphabet as your first name (for example, if your first name begins with the letter ‘t’, then you should exclude dictionary words that begin with ‘t’). Note that case matters (e.g. ‘Ab’ is a dictionary word, and it is not considered the same as ‘ab’). The words do not need to be delimited by spaces (or other punctuation) in the file and may overlap. The words must be contiguous e.g: door$knob or door knob will not find doorknob, but will still find door, knob, or, etc. Duplicates do count. For example, the word “a”, which is a dictionary word, appears in the data more than once, and should be counted accordingly.
3. The longest palindrome (i.e. a string that equals its reverse) you can find within the text. When finding palindromes, consider ALL characters (spaces should count).

### <ins>Expected Outputs:</ins>

For TinyData.txt:

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

For SmallData.txt:

    a. 8619

    b.
    A: 84869399
    B: 85228464
    C: 85329107
    D: 85278605
    E: 85097546
    F: 85255875
    G: 85227231
    H: 85242564
    I: 85194025
    J: 85311391
    K: 85306078
    L: 85230293
    M: 85160974
    N: 85258448
    O: 85051705
    P: 85276527
    Q: 85394099
    R: 85300258
    S: 85221247
    T: 85200662
    U: 85083006
    V: 85358305
    W: 85209342
    X: 85368356
    Y: 85237303
    Z: 85339565

    c. "  BRpmpRB  " or "Z R XMX R Z"

For BigData.txt:

    a. 44961

    b.
    A: 441273126
    B: 443133358
    C: 443647194
    D: 443381965
    E: 442460508
    F: 443272096
    G: 443129907
    H: 443175477
    I: 442955114
    J: 443569446
    K: 443531790
    L: 443130664
    M: 442789654
    N: 443292836
    O: 442208258
    P: 443362134
    Q: 443982959
    R: 443491704
    S: 443088589
    T: 442982840
    U: 442370361
    V: 443804847
    W: 443032962
    X: 443846641
    Y: 443181202
    Z: 443701868

    c. "  BRpmpRB  " or "lj   h   jl"
