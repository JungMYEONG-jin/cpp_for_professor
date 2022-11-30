bool isPerfectSquare(long double x)
{
  long double sr = sqrt(x);
  return ((sr - floor(sr)) == 0);
}

std::vector<int> res;
std::set<int> graph[1005];
std::set<int> graph_copy[1005];

bool dfs(std::vector<std::pair<int,int> > opt, int curr, int obj){
  if(curr == obj) return true;

  sort(opt.begin(),opt.end());

  int sz = opt.size();
  for(int i=0;i<sz;i++){
    int neigh = opt[i].second;

    res.push_back(neigh);
    for(int v: graph[neigh]) graph_copy[v].erase(neigh);

    std::vector<std::pair<int,int> > optx;
    for(int v: graph_copy[neigh]) optx.push_back(std::make_pair(graph_copy[v].size(),v));
    if(dfs(optx,curr+1,obj)) return true;

    for(int v: graph[neigh]) graph_copy[v].insert(neigh);
    res.pop_back();
  }

  return false;
}

std::vector<int> square_sums_row(int n)
{
  res = std::vector<int>();
  for(int i=0;i<1005;i++){
    graph[i] = std::set<int>();
    graph_copy[i] = std::set<int>();
  }


  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      if(isPerfectSquare(i+j)){
        graph[i].insert(j); graph_copy[i].insert(j);
        graph[j].insert(i); graph_copy[j].insert(i);
      }
    }
  }

  std::vector<std::pair<int,int> > optx;
  for(int v=1;v<=n;v++) optx.push_back(std::make_pair(graph_copy[v].size(),v));
  dfs(optx,0,n);

  return res;
}
