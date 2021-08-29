#include "Problems.hpp"
#include <assert.h>

using namespace std;

int main()
{
    string s = "This line should be printed", ans = Problem1("TextFile1.txt");
    assert(s.compare(ans));

    return 0;
}