/*
    All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". 
    When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

    Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

    For example,

    Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

    Return:
    ["AAAAACCCCC", "CCCCCAAAAA"].
*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> r_set_strings;
        if(s.size() < 10)
            return r_set_strings;

        int codebook[26];
        codebook['A' - 'A'] = 0;
        codebook['C' - 'A'] = 1;
        codebook['G' - 'A'] = 2;
        codebook['T' - 'A'] = 3;

        bool hash_substr[1024 * 1024];
        memset(hash_substr, false, 1024 * 1024);

        int size = s.size();
        int int_substr = 0;
        const int mask = (1<<20) - 1;
        for(int i = 0; i < size; ++i) {
            int_substr <<= 2;
            int_substr = (int_substr & mask) | codebook[s[i] - 'A'];
            if(i < 9)
                continue;

            if(!hash_substr[int_substr])
                hash_substr[int_substr] = true;
            else if(find(r_set_strings.begin(), r_set_strings.end(), s.substr(i - 9, 10)) == r_set_strings.end())
                r_set_strings.push_back(s.substr(i - 9, 10));
        }

        return r_set_strings;
    }
};
