#include <iostream>
#include <vector>
using namespace std;

// we can solve regex matching using backtracking
// we are considering only '.' and '*' special characters here
// leetcode 10. Regular Expression Matching (Hard Problem)

void matchPattern(string s, string p, bool &match, int sindex = 0,
                  int pindex = 0)
{
    if (match)
        return;

    if (sindex == s.size() && pindex == p.size())
    {
        match = true;
        return;
    }

    else if (sindex > s.size())
        return;
    else if (pindex > p.size())
        return;

    int stest = -1, ptest = -1;

    if (pindex + 1 < p.size() && p[pindex + 1] == '*')
    {
        ptest = pindex + 1;
        for (int i = ptest; i < p.size(); i++)
        {
            if (p[i] != '*')
            {
                ptest = i;
                break;
            }
        }
        if (ptest == pindex + 1)
            ptest = p.size();
        if (p[pindex] == s[sindex])
        {

            stest = sindex;
            for (int i = sindex; i <= s.size(); i++)
            {
                if (s[i] != s[sindex])
                {
                    stest = i;
                    break;
                }
            }
            if (stest == sindex)
                stest = s.size();

            for (int i = sindex; i <= stest; i++)
            {
                matchPattern(s, p, match, i, ptest);
            }
        }
        else if (p[pindex] == '.')
        {
            for (int i = sindex; i <= s.size(); i++)
            {
                matchPattern(s, p, match, i, ptest);
            }
        }
        else
        {
            matchPattern(s, p, match, sindex, ptest);
        }
    }
    else
    {
        if (p[pindex] == s[sindex] || p[pindex] == '.')
        {
            matchPattern(s, p, match, sindex + 1, pindex + 1);
        }
    }
}

int main()
{
    string s, p;
    bool match = false;
    // s = "xyzabc123";
    // p = ".*a.*2.*3"; // should return true
    // s = "";
    // p = "a*b*c*.*"; // should return true
    // s = "aaab";
    // p = "a*a*c"; // should return false
    // s = "aaabbbccc";
    // p = "a*b*c*.*"; // should return true
    // s = "mississippi";
    // p = "mis*is*ip*."; // should return true
    // s = "abc";
    // p = "a*.*b*.*c*.*"; // should return true
    // s = "aaaa";
    // p = "a*a"; // should return true
    // s = "ab"; p = ".*c"; // should return false
    // s = "a"; p = ".*..a*"; // should return false

    s = "aaaaaaaaaaaaaaaaaaab"; // 20 a's
    p = "a*a*a*a*a*a*a*a*a*a*"; // should return true

    // s = "abcdeabcdeabcdeabcde";
    // p = ".*abc.*de.*"; // should return true

    // s = "aaaaaaaaaaaaaaaaaaaa";
    // p = "a*aa*aaa*aaaa*aaaaa*"; // should return true

    // s = "mississippimississip";
    // p = "mis*is*ip*mi*s*i*s*ip*"; // should return true => fail

    // s = "abababababababababab";
    // p = "(ab)*.*"; // should return false - pattern invalid (has '(')
    // Actually, let's use valid pattern:
    // p = "ab*ab*ab*ab*ab*ab*ab*ab*ab*ab*"; // should return true

    // s = "aaaabbbbccccddddeeee";
    // p = "a*b*c*d*e*.*"; // should return true

    // s = "xyzxyzxyzxyzxyzxyzxy";
    // p = ".*xyz.*xyz.*xyz.*xyz"; // should return true

    // s = "aaaaaaaaaaaaaaaabbbb";
    // p = "a*.*b*.*c*"; // should return true (c* can match zero) => fail

    // s = "abcdabcdabcdabcdabcd";
    // p = ".*a.*b.*c.*d.*"; // should return true

    // s = "aaaaaaaaaaaaaaaaaaab";
    // p = "a*a*a*a*a*a*a*a*a*a*b"; // should return true

    // s = "abcdefghijklmnopqrst";
    // p = "a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*"; // should return true

    // s = "aaaaaabbbbbbbccccccc";
    // p = "a*..*b*..*c*..*"; // should return true

    // s = "abcabcabcabcabcabcab";
    // p = ".*abc.*abc.*abc.*abc"; // should return false

    // s = "mmmmiiiiissssssssspp";
    // p = "m*i*s*p*.*"; // should return true

    // Tricky zero-match cases:
    // s = "";
    // p = "a*b*c*d*e*f*g*h*i*j*"; // should return true

    // s = "x";
    // p = ".*********"; // should return true (all stars match zero, dot matches 'x')

    // s = "hellohellohellohello";
    // p = ".*h.*e.*l.*l.*o.*"; // should return true

    // s = "aaaaaaaaaaaaaaaaaaaa";
    // p = ".*a.*a.*a.*a.*a.*a.*a.*a.*a.*a"; // should return true

    // s = "abababababababababab";
    // p = "a.*b.*a.*b.*a.*b.*a.*b.*a.*b"; // should return true

    // s = "12345678901234567890";
    // p = ".*1.*2.*3.*4.*5.*6.*7.*8.*9.*0"; // should return true

    // s = "aaaaaaaaaaaaaaaaaaaa";
    // p = "a.*a.*a.*a.*a.*a.*a.*a.*a.*a"; // should return true

    // s = "abcabcabcabcabcabcab";
    // p = "abc*abc*abc*abc*abc*"; // should return true => fail

    // s = "zzzzzzzzzzzzzzzzzzzz";
    // p = "z*z*z*z*z*z*z*z*z*z*"; // should return true

    // s = "aab";
    // p = "c*a*b"; // should return true

    // s = "ab";
    // p = ".*c"; // should return false

    // s = "a";
    // p = "ab*"; // should return true

    // s = "ab";
    // p = ".*..c*"; // should return true

    // s = "ab";
    // p = ".*...c*"; // should return false

    // s = "a";
    // p = ".*.."; // should return false

    matchPattern(s, p, match);
    cout << "Match = " << match << endl;
    return 0;
}
