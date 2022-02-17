class Solution {
    public int solution(int n) {
        int answer = 0;
        String result="";
        while(n!=0)
        {
            int div = n/3;
            result+=String.valueOf(n%3);
            n = div;
        }
        int len = result.length();
        len-=1;
        int real_len = len;
        int sum = 0;
        for(int i = 0;i<result.length();i++)
        {
            sum+=(Math.pow(3, len--)*(result.charAt(i)-'0'));


        }
        answer = sum;
        return answer;
    }
}
