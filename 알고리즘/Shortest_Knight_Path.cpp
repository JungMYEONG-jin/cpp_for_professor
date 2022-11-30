#include <string>
#include <vector>
#include <set>
#include <queue>


using namespace std;



bool valid(int x, int y)
{
  if(x<0 || y<0 || x>7 || y>7)
    return false;
  return true;
}


struct Node
{
  int x;
  int y;
  int dist;
  
  Node(int x, int y, int dist=0)
    :x(x), y(y), dist(dist)
      {
      
    }
  bool operator<(const Node& o) const
    {
    return x<o.x || (x==o.x && y<o.y);
  }
  
  
};


int BPS(Node src, Node dest)
{
  int row[] = {2,2,-2,-2,1,1,-1,-1};
  int col[] ={-1,1,1,-1,2,-2,2,-2};
  
  set<Node> visited;
  queue<Node> que;
  que.push(src);
  
  
  while(!que.empty())
  {
    auto node = que.front();
    que.pop();
    
    int x = node.x;
    int y = node.y;
    int dist = node.dist;
    
    
    if(x==dest.x && y==dest.y)
      return dist;
    
    
    if(!visited.count(node))
    {
      
      visited.insert(node);
      
      for(int i=0;i<8;i++)
      {
        int x1=x+row[i];
        int y1=y+col[i];
        
        if(valid(x1, y1))
          que.push({x1, y1, dist+1});
      }
      
      
      
    }
    
    
    
    
    
  }
  
  return 0;
  
  
}





int knight(std::string start, std::string finish) {
  

  if(start.size()!=2 || finish.size()!=2)
    return 0;
  
  
  
  int x = start[0]-97;
  int y = start[1]-'0';
  
  int x1 = finish[0]-97;
  int y1 = finish[1]-'0';
  cout<<start<<" "<<finish<<endl;
  return BPS(Node(x,y-1), Node(x1, y1-1));
  

}
