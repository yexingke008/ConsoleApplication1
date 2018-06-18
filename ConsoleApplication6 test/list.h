#pragma once
#define MaxVex 100
typedef  int  VertexType;
typedef  int     EdgeType;
typedef  struct  graph
{
	int vnum, ednum;
	VertexType vexs[MaxVex];
	EdgeType   edges[MaxVex][MaxVex];
} Mgraph;
