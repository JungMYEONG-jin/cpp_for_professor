class Overload{
    protected:
        int total;
    public:
        Overload(int n)
          :total(n) {}
  
        Overload operator()(int x){
            return Overload(x+total);
        }
  
        bool operator==(int n) {return n==total;}  
      
        int operator+(int n) {return total+n;}
        int operator-(int n) {return total-n;}
  
        friend bool operator==(int n, const Overload& o) {return n==o.total;}
        
  
};
auto add(int n){
    return Overload(n);
}
