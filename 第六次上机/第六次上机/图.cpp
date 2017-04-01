#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<stack>
using namespace std;

class edge								//边
{
public:
	int start;							//边的起点，终点和权重
	int	end;
	int weight;
	edge(){}
	edge(int st, int en, int w)
	{
		start = st;
		end = en;
		weight = w;
	}
	bool operator>(edge oneedge)
	{
		if (this->weight > oneedge.weight)
			return true;
		else
			return false;
	}
	bool operator<(edge oneedge)
	{
		if (this->weight < oneedge.weight)
			return true;
		else
			return false;
	}
};

class MinHeap{
private:
	edge * heapArray;
	int CurrentSize;
	int MaxSize;
public:
	MinHeap(edge * Array, int num, int max);
	MinHeap(int max);
	void BuildHeap();
	void SiftDown(int father);
	bool Delete1(int n);//删除下标为n的结点
	bool Delete2(int n);//删除值为n的结点
	int CurrentS()
	{
		return CurrentSize;
	}
	bool insert(edge n);
	edge front()
	{
		return heapArray[0];
	}
	bool isempty()
	{
		if (CurrentSize <= 0)
			return true;
		else
			return false;
	}
};
MinHeap::MinHeap(int max){
	CurrentSize = 0;
	MaxSize = max;
	heapArray = new edge[MaxSize];
}
MinHeap::MinHeap(edge * Array, int num, int max){
	heapArray = Array;
	CurrentSize = num;
	MaxSize = max;
}
void MinHeap::BuildHeap(){
	for (int i = CurrentSize / 2 - 1; i >= 0; i--)
		SiftDown(i);
}
void MinHeap::SiftDown(int father){
	int i = father;
	int j = 2 * i + 1;
	edge temp;
	while (j < CurrentSize){
		if ((j < CurrentSize - 1) && (heapArray[j] > heapArray[j + 1]))
			j++;
		if (heapArray[i] > heapArray[j]){
			temp = heapArray[i];
			heapArray[i] = heapArray[j];
			heapArray[j] = temp;
			i = j;
			j = 2 * j + 1;
		}
		else break;
	}
}
bool MinHeap::Delete1(int n){
	heapArray[n] = heapArray[CurrentSize - 1];
	CurrentSize--;
	if (n == CurrentSize)
		return true;
	edge temp;
	int s = n;
	int f = (n - 1) / 2;
	while (f >= 0 && s != 0){
		if (heapArray[s] < heapArray[f])
		{
			temp = heapArray[s];
			heapArray[s] = heapArray[f];
			heapArray[f] = temp;
			s = f;
			f = (f - 1) / 2;
		}
		else break;
	}
	f = s;
	s = 2 * s + 1;
	while (s < CurrentSize){
		if ((s < CurrentSize - 1) && heapArray[s] > heapArray[s + 1])
			s++;
		if (heapArray[f] > heapArray[s]){
			temp = heapArray[s];
			heapArray[s] = heapArray[f];
			heapArray[f] = temp;
			f = s;
			s = 2 * s + 1;
		}
		else break;
	}
	return true;
}
bool MinHeap::insert(edge n){
	if (CurrentSize == MaxSize)
		return false;
	CurrentSize++;
	heapArray[CurrentSize - 1] = n;
	int s = CurrentSize - 1;
	int f = (s - 1) / 2;
	edge temp;
	while (s != 0){
		if (heapArray[s] < heapArray[f]){
			temp = heapArray[s];
			heapArray[s] = heapArray[f];
			heapArray[f] = temp;
			s = f;
			f = (f - 1) / 2;
		}
		else break;
	}
	return true;
}

class UFSets
{
public:

	int num;
	int * root;
	int * next;
	int * length;

	UFSets(int n);
	~UFSets(){}
	int Find(int v){ return root[v]; }
	void Union(int u, int v);
};

UFSets::UFSets(int n)
{
	int i;
	num = n;
	root = new int[num];
	next = new int[num];
	length = new int[num];
	for (i = 0; i<num; i++)
	{
		root[i] = i;
		next[i] = i;
		length[i] = 1;
	}
}

void UFSets::Union(int u, int v)
{
	int i, temp;
	if (root[u] == root[v])
		return;
	if (length[root[u]]<length[root[v]])
	{
		for (i = next[root[u]]; i != root[u]; i = next[i])
			root[i] = root[v];
		root[i] = root[v];
		temp = next[root[u]];
		next[root[u]] = next[root[v]];
		next[root[v]] = temp;
		length[root[v]] = length[root[v]] + length[root[u]];

	}
	else
	{
		for (i = next[root[v]]; i != root[v]; i = next[i])
			root[i] = root[u];
		root[i] = root[u];
		temp = next[root[u]];
		next[root[u]] = next[root[v]];
		next[root[v]] = temp;
		length[root[u]] = length[root[u]] + length[root[v]];
	}
}


class graph
{
public:
	int vertexnum;									//图的顶点数目
	int edgenum;									//图的边数目
	int *mark;										//标记某顶点是否被访问过
	graph(int verticesnum)							//构造函数
	{
		vertexnum = verticesnum;
		edgenum = 0;
		mark = new int[vertexnum];
		for (int i = 0; i < vertexnum; i++)			//标志位初始化为未被访问过，入度初始化为0；
			mark[i] = 0;
	}
	~graph()														//析构函数
	{
		delete[]mark;
	}
	virtual edge firstedge(int onevertex) = 0;							//返回与顶点onevertex
	virtual edge nextedge(edge oneedge) = 0;						//返回与边oneedge有相同起点的下一条边
	virtual void setedge(int start, int end, int weight) = 0;			//设置边（start,end），权重为weight
	virtual void deledge(int start, int end) = 0;					//删除边（start,end）
	int verticesnum()		//返回图的顶点数
	{
		return vertexnum;
	}
	int edgesnum()			//返回图的边数
	{
		return edgenum;
	}
	bool isedge(edge oneedge)									//如果oneedge是边则返回true，否则返回false
	{
		if (oneedge.weight > 0 && oneedge.weight < 1e10&&oneedge.end >= 0)
			return true;
		else
			return false;
	}
	int startvertex(edge oneedge)								//返回边oneedge的始点
	{
		return oneedge.start;
	}
	int endvertex(edge oneedge)				//返回边oneedge的终点
	{
		return oneedge.end;
	}
	int Weight(edge oneedge)				//返回边oneedge的权
	{
		return oneedge.weight;
	}
	void visit(int v)
	{
		edge e = firstedge(v);
		cout << e.start << ' ' << e.end << ' ' << e.weight << endl;
	}
	void visit_d(int v)
	{
		edge e = firstedge(v);
		cout << e.start  << endl;
	}
	void visit_o(int v)
	{
		edge e = firstedge(v);
		cout << e.start << '  ';
	}
	void DFS(int v)
	{
		mark[v] = 1;						//标记该节点已访问
		cout<<v<<endl;	//访问该顶点
			//visit(v);
		for (edge e = firstedge(v); isedge(e); e = nextedge(e))//对与该点关联的边进行深搜
		{

			if (mark[endvertex(e)] == 0)
			
				DFS(endvertex(e));
		}
	}
	void DFS_all()
	{
		for (int i = 0; i < verticesnum(); i++)
			mark[i] = 0;
		for (int i = 0; i < verticesnum(); i++)
		{
			if (mark[i] == 0)
				DFS(i);
		}
	}
	void BFS(int v)
	{
		
		queue<int> Q;
		mark[v] = 1;
		
		visit_d(v);
		
		Q.push(v);
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			for (edge e = firstedge(u); isedge(e); e = nextedge(e))
			{
				int u =endvertex(e);
				if (mark[u ]== 0)
				{
					
					visit_d(u);
					
					mark[u] = 1;
					Q.push(u);
				}
			}
		}
	}
	void BFS_all()
	{
		int i;
		for (i = 0; i < verticesnum(); i++)
			mark[i] = 0;
		for (i = 0; i < verticesnum(); i++)
		{
			if (mark[i] == 0)
				BFS(i);
		}
	}
};

class adjgragh :public graph
{
public:
	int **matrix;							//指向邻接矩阵的指针
public:
	adjgragh(int verticesnum) :graph(verticesnum)
	{
		int i, j;							//i，j为for循环中的计数器
		matrix = (int **)new int*[vertexnum];
		for (i = 0; i < vertexnum; i++)
			matrix[i] = new int[vertexnum];
		for (i = 0; i < vertexnum; i++)
		{
			for (j = 0; j < vertexnum; j++)
			{
				matrix[i][j] = 0;
			}
		}
	}
	~adjgragh()
	{
		for (int i = 0; i < vertexnum; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
	edge firstedge(int onevertex)
	{
		edge tmpedge;
		tmpedge.start = onevertex;
		for (int i = 0; i < vertexnum; i++)
		{
 			if (matrix[onevertex][i] != 0)					//矩阵该点权重不为0
			{
				tmpedge.end = i;							//将顶点i作为边tmpedge的终点
				tmpedge.weight = matrix[onevertex][i];		//该边置为起点为onevertex，终点为i，权重为该点值的边
				break;
			}
		}
		return tmpedge;
	}
	edge nextedge(edge oneedge)								//返回与oneedge有相同始点的下一条边
	{
		edge tmpedge;
		tmpedge.start = oneedge.start;
		for (int i = oneedge.end + 1; i < vertexnum; i++)
		{
			if (matrix[oneedge.start][i] != 0)
			{
				tmpedge.end = i;
				tmpedge.weight = matrix[oneedge.start][i];
				break;
			}
		}
		return tmpedge;
	}
	void setedge(int start, int end, int weight)		//设置边
	{
		if (matrix[start][end] == 0)					//如为空，新增一条边
		{
			edgenum++;
		}
		matrix[start][end] = weight;
	}
	edge *kruskal(int **a)
	{
		MinHeap h(100);
		int i, j;
		int k = 0;
		for (i = 0; i < vertexnum; i++)
			mark[i] = 0;
		for (i = 0; i < vertexnum - 1; i++)
		{
			for (j = 0; j < vertexnum; j++)
			{
				if (matrix[k][j]>0 && matrix[k][j] < 1000)
				{
					edge m(k, j, matrix[k][j]);
					h.insert(m);
				}
			}
			mark[k] = 1;
			edge n;
			while (1)
			{
				n = h.front();
				h.Delete1(0);
				k = n.end;
				if (mark[k] == 0)
					break;
			}
			a[n.start][n.end] = n.weight;
			a[n.end][n.start] = n.weight;
		}
		return NULL;
	}
	void deledge(int start, int end)					
	{
		if (matrix[start][end] != 0)
		{
			edgenum--;
		}
		matrix[start][end] = 0;
	}
	void build_d()
	{
		setedge(0, 1, 10);
		setedge(1, 0, 9);
		setedge(0, 2, 5);
		setedge(2, 0, 2);
		setedge(1, 2, 6);
		setedge(2, 1, 13);
		

		
	}
	void build()
	{
		setedge(0,2 ,1 );
		setedge(0,1 ,6 );
		setedge(0,3 ,5 );
		setedge(1,4 ,3 );
		setedge(1,2,5 );
		setedge(3,2 ,5 );
		setedge(2,5 ,4 );
		setedge(4,5 ,6 );
		setedge(3,5 ,2 );
		setedge(2,4 ,6 );

		setedge(2, 0, 1);
		setedge(1, 0, 6);
		setedge(3, 0, 5);
		setedge(4, 1, 3);
		setedge(2, 1, 5);
		setedge(2, 3, 5);
		setedge(5, 2, 4);
		setedge(5, 4, 6);
		setedge(5, 3, 2);
		setedge(4, 2, 6);


		/*int w;
		for (int i = 0; i < vertexnum; i++)
		{
			for (int j = 0; j < vertexnum; j++)
			{
				cin >> w;
				this->setedge(i, j, w);
			}
		}*/
	}
	void build_o()
	{
		setedge(0,1, 1);
		setedge(0, 2, 1);
		setedge(1, 3, 1);

		setedge(2, 4, 1);
		setedge(4, 5, 1);
		setedge(5, 0, 1);
	
	}
	/*void Prim(int node)
	{
	int i, j, k;
	int minweight;
	int mindex;
	int mindexbefore = node;

	for (i = 1; i <= this->verticesnum(); i++){
	this->mark[i] = 1;
	}
	this->mark[node] = 0;
	reSetMarixLarge();
	showMarix();
	for (k = 1; k < this->verticesnum(); k++)
	{
	minweight = MAX;
	for (i = 1; i <= this->verticesnum(); i++){
	if (this->mark[i] == 0){ //此节点为最外层节点

	for (j = 1; j <= this->verticesnum(); j++){
	if ((this->matrix[i][j] < minweight) && (this->mark[j] == 1)){//如果与这个节点相连的节点在树外并且权值比当前权值小

	minweight = this->matrix[i][j];
	mindex = j;
	mindexbefore = i;
	}
	}
	}
	}

	this->matrixTree[mindexbefore][mindex] = this->matrix[mindexbefore][mindex];
	this->matrixTree[mindex][mindexbefore] = this->matrix[mindexbefore][mindex];
	this->matrix[mindexbefore][mindex] = MAX;
	this->matrix[mindex][mindexbefore] = MAX;
	this->mark[mindex] = 0;
	}
	showMarixTree();
	}*/
	edge*prim_book(int s)
	{
		int i, j;
		edge *MST;
		int *nearest;				//生成树中节点到i点的最小边权值
		int *neighbor;				//生成树与i点最近的点编号，-1表示i点已在生成树集合中
		int n = verticesnum();	//图的顶点数目
		nearest = new int[n];
		neighbor = new int[n];
		MST = new edge[n - 1];
		for (i = 0; i < n; i++)
		{
			neighbor[i] = s;
			nearest[i] = 1000;
		}
		for (edge e = firstedge(s); isedge(e); e = nextedge(e))
		{
			neighbor[i] = e.weight;
		}
		neighbor[s] = -1;
		for (i = 1; i < n; i++)
		{
			int min = 1000;
			int v = -1;
			for (j = 0; j < n; j++)
			{
				if (nearest[j]<min&&neighbor[j]>-1)
				{
					min = nearest[j];
					v = j;
				}
			}
			if (v >= 0)
			{
				neighbor[v] = -1;
				edge tmp(neighbor[v], v, nearest[v]);
				MST[i] = tmp;

				for (edge e = firstedge(v); isedge(e); nextedge(e))
				{
					int u = e.end;
					if (neighbor[u] != -1 && nearest[u] > e.weight)
					{
						neighbor[u] = v;
						nearest[u] = e.weight;
					}
				}
			}
		}
		//delete[]neighbor;
		//delete[]nearest;
		for (i = 0; i < n; i++)
		{
			cout << MST[i].start << ' ' << MST[i].end << ' ' << MST[i].weight<<endl;
		}
		return MST;
	}//书上代码

	void prim(int **a)
	{
		MinHeap h(100);
		int i, j;
		int k = 0;
		for (i = 0; i < vertexnum; i++)
			mark[i] = 0;
		for (i = 0; i < vertexnum - 1; i++)
		{
			for (j = 0; j < vertexnum; j++)
			{
				if (matrix[k][j]>0 && matrix[k][j] < 1000)
				{
					edge m(k, j, matrix[k][j]);
					h.insert(m);
				}
			}
			mark[k] = 1;
			edge n;
			while (1)
			{
				n = h.front();
				h.Delete1(0);
				k = n.end;
				if (mark[k] == 0)
					break;
			}
			a[n.start][n.end] = n.weight;
			a[n.end][n.start] = n.weight;
		}
	}

	edge *Kruskal(int **matrix)
	{
		int n = verticesnum();
		UFSets set(n);
		edge *MST = new edge[n - 1];
		MinHeap H(edgesnum());
		edge e;
		for (int i = 0; i < verticesnum(); i++)
		{
			for (e = firstedge(i); isedge(e); e = nextedge(e))
			{
				if (startvertex(e) < endvertex(e))
					H.insert(e);
			}
		}
		int edgenum = 0;
		while (edgenum < n - 1)
		{
			if (!H.isempty())
			{
				e = H.front();
				int v = e.start;
				int u = e.end;
				if (set.Find(v) != set.Find(u))
				{
					set.Union(v, u);
					MST[edgenum++] = e;
				}
			}
			else
			{
				cout << "不存在最小生成树" << endl;
				return NULL;
			}
			for (int k = 0; k < edgenum; k++)
			{
				for (int i = 0; i < verticesnum(); i++)
				{
					for (int j = 0; j < verticesnum(); j++)
					{
						if (i == MST[k].start&&j == MST[k].end)
							matrix[i][j] = MST[k].weight;
					}
				}
			}
		}
		return MST;
	}
	void dijkstra(int s)
	{
		int i, j;
		int n = vertexnum;
		int  *D;
		int *Path;
		D = new int[n];
		Path = new int[n];
		for (i = 0; i < vertexnum; i++){
			mark[i] = 0;
			D[i] = matrix[s][i];					//D[i]存入以s开头的节点列的值
			Path[i] = s;							//路径先置为s
		}
		mark[s] = 1;								//代表访问过s
		for (i = 0; i < vertexnum - 1; i++){
			int min = 1000;
			int k = 0;
			for (j = 0; j < vertexnum; j++){
				if (mark[j] == 0 && min>D[j]){		//如果未访问过且min>D[j]现有的
					min = D[j];
					k = j;
				}
			}
			mark[k] = 1;
			for (j = 0; j < vertexnum; j++)
			{
				if (mark[j] == 0 && D[j]>D[k] + matrix[k][j])
				{
					D[j] = D[k] + matrix[k][j];
					Path[j] = k;
				}
			}
		}
		for (i = 0; i < vertexnum; i++){
			cout << D[i] << ' ';
		}
		cout << endl;
		for (i = 0; i < vertexnum; i++){
			cout << Path[i] << ' ';
		}
		cout << endl;
	}
	void floyd()
	{
		int i, j, v;
		int **Adj;
		int **Path;
		Adj = new int*[vertexnum];
		for (i = 0; i < vertexnum; i++)
			Adj[i] = new int[vertexnum];
		Path = new int*[vertexnum];
		for (i = 0; i < vertexnum; i++)
			Path[i] = new int[vertexnum];
		for (i = 0; i < vertexnum; i++)
		{
			for (j = 0; j < vertexnum; j++)
			{
				Adj[i][j] = matrix[i][j];
				Path[i][j] = i;
			}
		}
		for (v = 0; v < vertexnum; v++)
		{
			for (i = 0; i < vertexnum; i++)
			{
				for (j = 0; j < vertexnum; j++)
				{
					if (Adj[i][j]>Adj[i][v] + Adj[v][j])
					{
						Adj[i][j] = Adj[i][v] + Adj[v][j];
						Path[i][j] = v;
					}
				}
			}
		}
		for (i = 0; i < vertexnum; i++){
			for (j = 0; j < vertexnum; j++)
				cout << Adj[i][j] << ' ';
			cout << endl;
		}
		cout << endl;
		for (i = 0; i < vertexnum; i++){
			for (j = 0; j < vertexnum; j++)
				cout << Path[i][j]<<' ';
			cout << endl;
		}
		cout << endl;
	}
	void judge_2(int v,int *p)
	{
		mark[v] = 1;						//标记该节点已访问
		*p = v;
		p++;
		for (edge e = firstedge(v); isedge(e); e = nextedge(e))//对与该点关联的边进行深搜
		{
				if(mark[endvertex(e)] == 1)
				{
					*p=endvertex(e);
					cout << "存在环    "<<endl;
					p++;
				}
				if (mark[endvertex(e)] == 0)
				{
					
					judge_2(endvertex(e),p);
				}
			
		}
	}
	void judge_all()
	{
		
		for (int i = 0; i < verticesnum(); i++)
			mark[i] = 0;
		for (int i = 0; i < verticesnum(); i++)
		{
			int*p = new int[10];
			for (int i = 0; i < 10; i++)
			{
				p[i] = -1;

			}
			if (mark[i] == 0)
				judge_2(i,p);
			for (int i = 0; p[i] != -1; i++)
			{
				cout << p[i] << ' ';
			}
			cout << endl;
			delete[]p;
		}
	}
	/*void judge_1(int s,int**a)
	{

		for (int i = s; i < vertexnum; i++)
		{
			for (int j = 0; j < vertexnum; j++)
			{
				if (matrix[i][j] != 0)
				{
					a[i][j] = i;
					judge(j,a);
					
				}
			}
		}
	}*/
	void circle(int v, int**a){
		int *Path;
		Path = new int[vertexnum + 1];
		for (int i = 0; i < vertexnum; i++){
			mark[i] = 0;
		}
		circle1(Path, 0, v, v, a);
	}
	void circle1(int Path[], int i, int v, int c, int**a){
		if (i < vertexnum){
			int c1 = c;
			int i1 = i;
			int * path;
			path = new int[vertexnum];
			for (int o = 0; o < i1; o++)
				path[o] = Path[o];
			path[i1] = c1;
			mark[c1]++;
			for (int j = 0; j < vertexnum; j++){
				if (a[c1][j]>0 && a[c1][j] < 1000){
					if (j == v&&i1>1){
						path[++i1] = j;
						int x = 0;
						int y = 1;
						int max = a[path[0]][path[1]];
						for (int k = 0; k <i1; k++){
							if (max <= a[path[k]][path[k + 1]]){
								max = a[path[k]][path[k + 1]];
								x = k; y = k + 1;
							}
						}
						a[path[x]][path[y]] = -1;
						a[path[y]][path[x]] = -1;
					}
					if (j != v&&mark[j] == 0)
						circle1(path, i1 + 1, v, j, a);
				}
			}
		}
	}
	void BreakCircle(){
		int **a;
		int i, j;
		a = new int*[vertexnum];
		for (i = 0; i < vertexnum; i++){
			a[i] = new int[vertexnum];
		}
		for (i = 0; i < vertexnum; i++){
			for (j = 0; j < vertexnum; j++)
				a[i][j] = matrix[i][j];
		}
		for (i = 0; i < vertexnum; i++)
			circle(i, a);
		for (i = 0; i < vertexnum; i++){
			for (j = 0; j < vertexnum; j++)
				cout << a[i][j] << ' ';
			cout<< endl;
		}
	}
};

int main()
{
	adjgragh a(6);
	adjgragh b(6);
	adjgragh c(3);
	adjgragh d(6);

	d.build_o();


	a.build();
	c.build_d();
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << a.matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "BFS:" << endl;
	d.BFS_all();
	cout << "DFS:" << endl;
	d.DFS_all();
	cout << "prim:" << endl;
	
	a.prim(b.matrix);
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << b.matrix[i][j] << ' ';
		}
		cout << endl;
	}

	a.kruskal(b.matrix);
	cout << "kruskal:" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << b.matrix[i][j] << ' ';
		}
		cout << endl;
	}
	cout << "dijkstra" << endl;
	c.dijkstra(0);
	cout << "floyd" << endl;
	c.floyd();
	cout << "第九题：是否存在环？" << endl;
	d.build_o();
	d.judge_all();
	cout << "第十题：破圈法" << endl;
	b.BreakCircle();
	/*int *p;
	p = new int[20];
	int *q;
	q = new int[20];
	d.judge_all(p);
	for (int i = 0; i < d.vertexnum; i++)
	{
	cout << p[i];
	}
	cout << endl;
	for (int i = 0; i < d.vertexnum; i++)
	{
	q[i] = p[i];
	if (q[0] = p[i])
	{
	for (int j = 0; j < i; j++)
	{
	cout << q[j] << '  ';
	}
	}

	}*/
	/*int **p;
	p = (int **)new int*[a.vertexnum];
	for (int i = 0; i < a.vertexnum; i++)
		p[i] = new int[a.vertexnum];
	for (int i = 0; i < a.vertexnum; i++)
	{
		for (int j = 0; j < a.vertexnum; j++)
		{
			p[i][j] = -1;
		}
	}
	cout << "第九题：是否存在环？" << endl;
	int j = 0;
	for (int i = 0; i < a.vertexnum; i = j)
	{
		int
	}
	a.judge(0, p);*/
	return 0;
}
