std::vector<std::vector<int>> create_spiral(int n) {
    if (n<1) {return {};}
    std::vector<std::vector<int>> spiral(n, std::vector<int>(n));
    
    int i=0, j=0, di=0, dj=1;
    for (int x=1; x<=n*n; x++) {
        spiral[i][j] = x;
        if (i+di<0 || i+di>=n || j+dj<0 || j+dj>=n || spiral[i+di][j+dj]!=0) {
            if      (di== 0 && dj== 1) {di= 1; dj= 0;}
            else if (di== 1 && dj== 0) {di= 0; dj=-1;}
            else if (di== 0 && dj==-1) {di=-1; dj= 0;}
            else if (di==-1 && dj== 0) {di= 0; dj= 1;}
        }
        i+=di; j+=dj;
    }
    return spiral;
}
