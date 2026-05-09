class Solution {
public:

    string encode(vector<string>& strs) {
        string e("");
        for (string& s : strs) {
            e += std::to_string(s.length()) + "#" + s;
        }
        return e;
    }

    vector<string> decode(string s) {
        vector<string> vec;
        string len;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '#') {
                len.push_back(s[i]);
            } else {
                int l = std::stoi(len);
                vec.push_back(s.substr(i + 1, l));
                i += l;
                len = "";
            }
        }
        return vec;
    }
};