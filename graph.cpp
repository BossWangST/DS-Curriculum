#include "graph.h"
template<typename T>
graph<T>::graph(ifstream& file)
{
	int n, e;
	string line;
	getline(file, line);
	file >> n >> e;
	vexnum = n;
	edgenum = e;
	vex.resize(vexnum);
	edge.resize(vexnum);

	int line_i = 0;
	vector<T> v;
	int numflag = 0;
	while(line_i<line.length())
	{
		int linetemp = line_i;
		while (line_i < line.length()&&line[line_i] != ' ')
			line_i++;
		stringstream ss;
		string numtemp = line.substr(linetemp, line_i);
		ss << numtemp;
		T realnum;
		ss >> realnum;
		v.push_back(realnum);
		line_i++;
	}
	for (int i = 0; i < n; ++i)
	{
		vex[i] = v[i];
		edge[i].resize(vexnum);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			edge[i][k] = 0;
		}
	}
	T va, vb;
	int vai, vbi;
	int weight;
	bool flag1 = false, flag2 = false;

	Pathdata = new pathdata[edgenum];
	int pathdata_flag = 0;
	for (int i = 0; i < e; ++i)
	{
		flag1 = flag2 = false;
		file >> va >> vb >> weight;
		for (int k = 0; k < vexnum; ++k)
		{
			if (v[k] == va)
			{
				vai = k;
				flag1 = true;
			}
			if (v[k] == vb)
			{
				vbi = k;
				flag2 = true;
			}
			if (flag1 && flag2)
				break;
		}

		Pathdata[pathdata_flag].first = va;
		Pathdata[pathdata_flag].second = vb;
		Pathdata[pathdata_flag].weight = weight;
		pathdata_flag++;
		if (weight == -1)
			continue;
		edge[vai][vbi] = edge[vbi][vai] = weight;
	}
	cout << "邻接矩阵如下:" << endl;
	cout << "  ";
	cout << endl;
	for (int i = 0; i < vexnum; ++i)
	{
		for (int j = 0; j < vexnum; ++j)
			if (edge[i][j] != 0 || i == j)
				cout << setw(3) << edge[i][j] << ' ';
			else
				cout << setw(3) << " ∞ ";
		cout << endl;
	}


}


template<typename T>
struct edgeele
{
	T dest;
	int lowcost;
};

template<typename T>
T graph<T>::getvalue(int v)
{
	for (int i = 0; i < vexnum; ++i)
		if (i == v)
			return vex[i];
}


template<typename T>
path* graph<T>::prim(int v)
{//最小生成树
	edgeele<T>* miniedge = new edgeele<T>[vexnum];
	//生成miniedge数组，结构体数组，包含数据及到这个点的最小权值
	path* Path = new path[vexnum];
	int treeflag = 0;
	for (int i = 0; i < vexnum; ++i)
	{
		miniedge[i].dest = getvalue(v);//依据下标获取节点内容，让每个节点的目标都是下标是v（集合目前只有v）的，以求权值
		miniedge[i].lowcost = edge[v][i];
		if (miniedge[i].lowcost == 0 && i != v)
			miniedge[i].lowcost = 100005;//获取每个节点与v之间的边的权值
	}
	miniedge[v].lowcost = 0;//自己到自己权值为0
	int min;
	int pathflag = 0;
	for (int i = 0; i < vexnum - 1; ++i)
	{
		min = MiniNum(miniedge, vexnum);//核心函数，获取集合到其他节点的最小权值
		qDebug() << miniedge[min].dest << "-->" << getvalue(min) << endl;
		Path[pathflag].first = miniedge[min].dest;
		Path[pathflag++].second = getvalue(min);
		miniedge[min].lowcost = 0;
		miniedge[min].dest = getvalue(min);
		for (int j = 0; j < vexnum; ++j)//更新集合到其他节点的最小权值（就是看新入集合的节点，能否让到其他节点的权值比原先集合中的更小，小就更新）
		{
			if (edge[min][j] < miniedge[j].lowcost && edge[min][j] != 0)
			{
				miniedge[j].dest = getvalue(min);
				miniedge[j].lowcost = edge[min][j];
			}
		}
	}
	return Path;
}

template<typename T>
int MiniNum(edgeele<T>* arr, size_t size)
{//此函数用以找到目前已选集合中，更新集合到每个节点的最小权值
	int min = 100005;
	int res = 0;
	for (size_t i = 1; i < size; ++i)
	{
		if (arr[i].lowcost < min && arr[i].lowcost != 0)//防止已经加入集合的节点被选中
		{
			min = arr[i].lowcost;
			res = i;
		}
	}//本质选最小值，但是返回下标
	return res;
}

template<typename T>
int graph<T>::getvexnum()
{
	return vexnum;
}

template<typename T>
int graph<T>::getedgenum()
{
	return edgenum;
}

template<typename T>
void graph<T>::dfs(int v, bool* visited)//单次dfs
{
	//cout << vex[v];
	visited[v] = true;
	for (int i = 0; i < vexnum; ++i)
	{
		if (edge[v][i] != 0 && !visited[i])
			dfs(i, visited);
	}
}
template<typename T>
bool graph<T>::dfstraverse()
{
	bool* visited = new bool[vexnum];
	for (int i = 0; i < vexnum; ++i)
		visited[i] = false;
	int count = 0;
	for (int i = 0; i < vexnum; ++i)
		if (!visited[i])
		{
			dfs(i, visited);//如果是连通图，则就是一次dfs结束，否则就会多次dfs
			count++;
		}
	delete[]visited;
	if (count == 1)
		return true;//连通图
	else
		return false;
}
