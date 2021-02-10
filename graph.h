#ifndef GRAPH_H
#define GRAPH_H
#include<iostream>
#include<vector>
#include<fstream>
#include<qDebug>
#include<iomanip>
#include<sstream>
using namespace std;
struct edgeNode
{
	int dest;
	int value = 0;
	edgeNode* next;
};
template<typename T>
struct vexNode
{
	T data;
	edgeNode* first;
};

struct path
{
	int first;
	int second;
};
struct pathdata
{
	int first;
	int second;
	int weight;
};
template<typename T>
class graph
{
	int vexnum, edgenum;
	vector<vector<int>> edge;
	vector<T> vex;
	vector<vexNode<T>> list;
	void dfs(int v, bool* visited);

public:
	pathdata* Pathdata;
	graph(ifstream&);
	path* prim(int);
	T getvalue(int);
	int getvexnum();
	int getedgenum();
	bool dfstraverse();

};
#endif // !GRAPH_H
