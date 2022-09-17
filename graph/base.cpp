void edge(vector<int>adj[],int u,int v){
  adj[u].push_back(v);
}
//function for bfs traversal
void bfs(int s,vector<int>adj[],bool visit[]){
  queue<int>q;//queue in STL
  q.push(s);
  visit[s]=true;
  while(!q.empty()){
    int u=q.front();
    cout<<u<<" ";
    q.pop();
//loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        q.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}
//function for dfs traversal
void dfs(int s,vector<int>adj[],bool visit[]){
  stack<int>stk;//stack in STL
  stk.push(s);
  visit[s]=true;
  while(!stk.empty()){
    int u=stk.top();
    cout<<u<<" ";
    stk.pop();
//loop for traverse
    for(int i=0;i<adj[u].size();i++){
      if(!visit[adj[u][i]]){
        stk.push(adj[u][i]);
        visit[adj[u][i]]=true;
      }
    }
  }
}