# DFS 알고리즘에는 스택 버전과 재귀버전이 있다.

우선은 스택을 이용한 버전을 구현하겠다.

1. stack에 시작 노드를 넣는다.
2. 해당 노드를 시작으로 주변에 인접 노드가 있다면 stack에 집어 넣는다
3. 없다면 pop하고 현재 top 노드의 인접 노드를 찾는다.
4. 단 이전에 방문한적이 없는 노드여야 한다.
5. backtracking을 이용하여 동작한다고 생각하면 된다.


![dfs0](https://www.tutorialspoint.com/data_structures_algorithms/images/dfs_one.jpg)


![dfs](https://www.tutorialspoint.com/data_structures_algorithms/images/dfs_two.jpg)


![dfs2](https://www.tutorialspoint.com/data_structures_algorithms/images/dfs_three.jpg)


![dfs4](https://www.tutorialspoint.com/data_structures_algorithms/images/dfs_four.jpg)


![dfs5](https://www.tutorialspoint.com/data_structures_algorithms/images/dfs_five.jpg)


![dfs6](https://www.tutorialspoint.com/data_structures_algorithms/images/dfs_six.jpg)


![dfs11](https://www.tutorialspoint.com/data_structures_algorithms/images/dfs_seven.jpg)


```c++
void dfs(int s)
	{
		vector<bool> visited(V, false);

		stack<int> st;

		st.push(s);

		while (!st.empty())
		{
			s = st.top();
			st.pop();


			if (!visited[s]) // 방문되지 않은 노드라면
			{
				cout << s << " ";
				visited[s] = true;

			}

			for(auto j : adj[s])
				if (!visited[j])
				{
					st.push(j);
				}
		}


	}


```
