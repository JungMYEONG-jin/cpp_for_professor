 string longestPalindrome(string s) {
        int len = s.size();
        int longestBegin = 0;
        int maxlen = 1;
        vector<bool> table(len*len, false);

        // own self check
        for(int i=0;i<len;i++)
            table[i*len+i] = true;

        for(int i=0;i<len-1;i++){
            if(s[i]==s[i+1]){
                table[i*len+i+1] = true;
                if(maxlen<2){
                    maxlen = 2;
                    longestBegin = i;
                }
            }
        }

        for(int k=3;k<=len;k++){
            for(int i=0;i<len-k+1;i++){
                int j = i+k-1;
                if(s[i]==s[j] && table[(i+1)*len+j-1]){
                    table[i*len+j] = true;
                    if(maxlen<k){
                        longestBegin = i;
                        maxlen = k;
                    }
                }
            }
        }
        return s.substr(longestBegin, maxlen);

    }
