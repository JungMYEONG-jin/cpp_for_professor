// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int dir(Point2D& cur, Point2D& prev, Point2D& next){
    double vx = cur.x - prev.x;
    double vy = cur.y - prev.y;

    double wx = next.x - prev.x;
    double wy = next.y - prev.y;

    double determinant = vx*wy - vy*wx;

    int res = 0;

    if(determinant<0){
        res = -1;
    }else if(determinant>0){
        res = 1;
    }
    return res;
}


int solution(vector<Point2D> &A) {
    // Implement your solution here
    int len = A.size();
    if(len<4)
        return -1;

    int start = 0;
    int low = A[start].x;
    for(int i=1;i<len;i++){
        if(A[i].x<low){
            low = A[i].x;
            start = i;
        }
    }

    int last_dir = 0;
    for(int i=start, counter = 0; counter<len;counter++){
        int prev = (i+len-1)%len;
        int next = (i+1)%len;

        int curDir = dir(A[i], A[prev], A[next]);

        if(curDir!=0){
            if(last_dir!=0){
                if(last_dir!=curDir)
                    return i;
            }else{
                last_dir = curDir;
            }
        }

        i = (i+1)%len;
    }

    return -1;
}
