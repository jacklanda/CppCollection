class Solution {
public:
    // main
    int calculate(string s) { return parse_expr(s, 0); }

    // helper - parse recursively remained string from the beginning of i
    int parse_expr(const string& s, int i) {
        char op = '+';
        long left = 0, right = 0;
        while (i < s.size()) {
            if (s[i] != ' ') {
                long num = parse_num(s, i);
                switch (op) {
                    case '+':
                        left += right;
                        right = num;
                        break;
                    case '-':
                        left += right;
                        right = -num;
                        break;
                    case '*':
                        right *= num;
                        break;
                    case '/':
                        right /= num;
                        break;
                }
                if (i < s.size()) op = s[i];
            }
            ++i;
        }
        return left + right;
    }

    // helper - parse the int from the beginning of i
    long parse_num(const string& s, int i) {
        long num = 0;
        while (i < s.size() && std::isdigit(s[i])) num = 10 * num + (s[i++] - '0');
        return num;
    }
};
