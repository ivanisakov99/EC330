#include "Problems.hpp"
#include <assert.h>

using namespace std;

int main()
{
    string s = "", ans = Problem1("TextFile2.txt");
    assert(s.compare(ans));

    return 0;
}