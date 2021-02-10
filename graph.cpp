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
	cout << "�ڽӾ�������:" << endl;
	cout << "  ";
	cout << endl;
	for (int i = 0; i < vexnum; ++i)
	{
		for (int j = 0; j < vexnum; ++j)
			if (edge[i][j] != 0 || i == j)
				cout << setw(3) << edge[i][j] << ' ';
			else
				cout << setw(3) << " �� ";
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
{//��С������
	edgeele<T>* miniedge = new edgeele<T>[vexnum];
	//����miniedge���飬�ṹ�����飬�������ݼ�����������СȨֵ
	path* Path = new path[vexnum];
	int treeflag = 0;
	for (int i = 0; i < vexnum; ++i)
	{
		miniedge[i].dest = getvalue(v);//�����±��ȡ�ڵ����ݣ���ÿ���ڵ��Ŀ�궼���±���v������Ŀǰֻ��v���ģ�����Ȩֵ
		miniedge[i].lowcost = edge[v][i];
		if (miniedge[i].lowcost == 0 && i != v)
			miniedge[i].lowcost = 100005;//��ȡÿ���ڵ���v֮��ıߵ�Ȩֵ
	}
	miniedge[v].lowcost = 0;//�Լ����Լ�ȨֵΪ0
	int min;
	int pathflag = 0;
	for (int i = 0; i < vexnum - 1; ++i)
	{
		min = MiniNum(miniedge, vexnum);//���ĺ�������ȡ���ϵ������ڵ����СȨֵ
		qDebug() << miniedge[min].dest << "-->" << getvalue(min) << endl;
		Path[pathflag].first = miniedge[min].dest;
		Path[pathflag++].second = getvalue(min);
		miniedge[min].lowcost = 0;
		miniedge[min].dest = getvalue(min);
		for (int j = 0; j < vexnum; ++j)//���¼��ϵ������ڵ����СȨֵ�����ǿ����뼯�ϵĽڵ㣬�ܷ��õ������ڵ��Ȩֵ��ԭ�ȼ����еĸ�С��С�͸��£�
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
{//�˺��������ҵ�Ŀǰ��ѡ�����У����¼��ϵ�ÿ���ڵ����СȨֵ
	int min = 100005;
	int res = 0;
	for (size_t i = 1; i < size; ++i)
	{
		if (arr[i].lowcost < min && arr[i].lowcost != 0)//��ֹ�Ѿ����뼯�ϵĽڵ㱻ѡ��
		{
			min = arr[i].lowcost;
			res = i;
		}
	}//����ѡ��Сֵ�����Ƿ����±�
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
void graph<T>::dfs(int v, bool* visited)//����dfs
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
			dfs(i, visited);//�������ͨͼ�������һ��dfs����������ͻ���dfs
			count++;
		}
	delete[]visited;
	if (count == 1)
		return true;//��ͨͼ
	else
		return false;
}
