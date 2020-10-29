class Decomp {
public:
    static string decompose(const string &nrStr, const string &drStr) {
        long long num = std::stol(nrStr), den = std::stol(drStr);
        vector<string> sequence;
        if (num > den) {
            sequence.push_back(to_string(num/den));
            num %= den;
        }
        
        for (int i = 2; ; i++) {
            if (den <= i * num) {
                sequence.push_back("1/" + to_string(i));
                num = num * i - den;
                den *= i;
            }
            if (num == 0) 
                break;
        }
        
        string result = "";
        for (auto frac : sequence) 
            result += frac + ", ";      
        return "[" + result.substr(0, result.length()-2) + "]";
    }
};
