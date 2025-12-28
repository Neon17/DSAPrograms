#include <iostream>
#include <vector>
using namespace std;

// we can solve regex matching using backtracking
// we are considering only '.' and '*' special characters here

// leverage is "true" when . hit and "a" if a* hit
void matchPattern(string s, string p, bool &match, int sindex = 0, int pindex = 0, string leverage = "")
{
    if (match)
        return;
    if (pindex >= p.size() && leverage == "true")
    {
        match = true;
        return;
    }
    if ((pindex + 1 >= p.size()) && (sindex + 1 >= s.size()))
    {
        // * means 0 or unlimited times previous term if abc* then it can be abc or abcabc or abcc, abcb
        if ((p[pindex] == '.') || (p[pindex] == s[sindex]) || (leverage == "true") || (p[pindex] == '*'))
            match = true;
        return;
    }
    else if ((sindex > s.size()))
    {
        match = false;
        return;
    }
    if (pindex < p.size() && p[pindex] == '.')
    {
        if (p[pindex + 1] == '*')
        {
            int ptest = -1;
            for (int i = pindex + 2; i < p.size(); i++)
            {
                if (p[i] != '*')
                {
                    ptest = i;
                    break;
                }
            }
            if (ptest == -1)
                ptest = p.size();
            if (sindex + 1 >= s.size())
            {
                matchPattern(s, p, match, sindex, ptest, "true");
                return;
            }
            for (int i = sindex; i < s.size(); i++)
            {
                matchPattern(s, p, match, i, ptest, "true");
            }
        }
        else
        {
            if (sindex + 1 >= s.size())
            {
                return;
            }
            matchPattern(s, p, match, sindex + 1, pindex + 1, "");
        }
    }
    else if (pindex < p.size() && p[pindex] == '*')
    {
        string leve = "";
        leve += s[sindex];
        if ((leverage == leve) || (p[pindex - 1] == s[sindex]))
        {
            string temp = leverage;
            if ((leverage == "true") || (leverage == ""))
                temp = p[pindex - 1] + "";
            else
                temp = leverage;
            matchPattern(s, p, match, sindex + 1, pindex + 1, temp);
        }
        matchPattern(s, p, match, sindex, pindex + 1, leverage);
    }
    else if ((pindex < p.size()) && (p[pindex] == s[sindex]) && ((pindex + 1) >= p.size()) || (p[pindex + 1] != '*'))
    {
        matchPattern(s, p, match, sindex + 1, pindex + 1, "");
    }
    else if ((p[pindex] == s[sindex]) && (p[pindex + 1] == '*'))
    {
        string leve = "";
        leve += s[sindex];
        // find up to where s and p[pindex] match
        int ptest = sindex;
        for (int i = sindex; i < s.size(); i++)
        {
            if (s[i] == p[pindex])
                ptest = i;
            else
                break;
        } // pindex size can go beyond p.size()
        for (int i = sindex; i <= ptest + 1; i++)
        {
            matchPattern(s, p, match, i, pindex + 2, leve);
        }
    }
    else if ((sindex < s.size()) && (leverage == string(1, s[sindex])))
    {
        matchPattern(s, p, match, sindex + 1, pindex, leverage);
        matchPattern(s, p, match, sindex, pindex + 1, leverage);
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
    // p = "mis*is*ip*i"; // should return true
    // s = "abc";
    // p = "a*.*b*.*c*.*"; // should return true
    // s = "aaaa";
    // p = "a*a"; // should return true
    // s = "ab"; p = ".*c"; // should return false
    // s = "a"; p = ".*..a*"; // should return false

    // s = "aaaaaaaaaaaaaaaaaaaa"; // 20 a's
    // p = "a*a*a*a*a*a*a*a*a*a*"; // should return true

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
    // p = ".*abc.*abc.*abc.*abc"; // should return true => fail

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

    matchPattern(s, p, match);
    cout << "Match = " << match << endl;
    return 0;
}
