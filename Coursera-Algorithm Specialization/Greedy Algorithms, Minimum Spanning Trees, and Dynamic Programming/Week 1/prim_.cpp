#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <sstream>
#define INF 999999
#include<limits.h>

int totalcost = 0;
map<int,vector< pair <int,int> > > graph;
map<int,int> visited;
map<int,int> distt;
void prim(){
	//cout<<"efeq";
    for(int i = 1;i <=graph.size();i++){
    	int mini = INT_MAX;
    	int index = -1;
    	//cout<<"dfd";
    	for(auto it = distt.begin();it != distt.end();it++){
		    if (it->second < mini && visited[it->first] == 0){
		            index = it->first;
		            mini = it->second;
		    }
  	  	}   	
        int get_min = index;	
        totalcost += distt[get_min];
        visited[get_min] = 1;
        for(int j = 0; j < graph[get_min].size();j++){
            if(visited[graph[get_min][j].first] == 0 && graph[get_min][j].second < distt[graph[get_min][j].first])
                distt[graph[get_min][j].first] = graph[get_min][j].second ;
        }
    }
}
void init(){
    FILE *fp = freopen("edges.txt","r",stdin);
    int source,dest,cost;
    int nodes,edges;
    cin>>nodes>>edges;
	while (scanf("%d %d %d", &source, &dest,&cost) > 0) {
           graph[source].push_back(make_pair(dest,cost));
           graph[dest].push_back(make_pair(source,cost));
           visited[source] = visited[dest]=0;
           distt[source] = distt[dest] = INF;       
    }
    fclose(fp);
    //cout<<"qq";
}
int main(){
    init();
    distt[1] = 0;
    prim();
    cout << totalcost << endl;
    return 0;
}

