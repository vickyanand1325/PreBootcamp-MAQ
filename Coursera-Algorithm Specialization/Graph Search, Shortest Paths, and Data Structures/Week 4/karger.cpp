#include <bits/stdc++.h>
using namespace std;
#include <string>
#include <sstream>
#define ITERATIONS 20
int sstoi(string s){
    int x=0;
    stringstream convert(s);
    convert>>x;
    return x;

}
int countgraph(map<int,vector<int> > mymap){
    for (auto it=mymap.begin(),int c = 0; it!=mymap.end(); ++it){
            for(int j = 0;j < (it->second).size();c++,j++);
    }
    return (c/2);
}

int minimum_cut(map<int,vector<int> > graph){
    while(graph.size() > 2){
        auto it = graph.begin();
        advance(it, rand() % graph.size());
        vector<int> temp = graph[it->first];
        int sizeofirst = temp.size();
        int last = rand()%sizeofirst;
        int elementlast = graph[it->first][last];

        for(int i = 0;i < graph[elementlast].size(); i++){
            if(graph[elementlast][i] != it->first)
                graph[it->first].push_back(graph[elementlast][i]);
        }
        for(int i = 0;i < graph[elementlast].size(); i++){
			int iter1=graph[elementlast][0];
			int elem=graph[elementlast][i];
			int size=graph[elem].size();
            for(int j = 0;j<size;j++){
                if(graph[elem][j] == elementlast){
                    graph[elem].erase(graph[elem].begin() + j);
                    break;
                }
            }
            if(elem != it->first)
                graph[elem].push_back(it->first);
        }
        graph.erase(elementlast);
    }

    int x = countgraph(graph);
    return x;
}
int util_function(auto graph){
	int mini = 10000;
	int iter=0;
    while(iter<ITERATIONS){
            int cut = minimum_cut(graph);
            mini=(cut < mini  and cut > 1)?cut:mini;
            iter++;
    }
}
int main(){
    map<int,vector<int> > graph;
    FILE *fp = fopen("kargerMinCut.txt","r");
    string line;
    int c = fgetc(fp);
    string source = "";
    string destination = "";
    int flag = 0;
    while(c != EOF){
            source = destination="";
            flag = 0;
            while(1){
                if (isdigit(c) and !flag)
					source = source + (char)c;
                if(isdigit(c) and flag)
                    destination = destination + (char)c;
                if(isspace(c) and !flag)
                    flag = 1;
                if(isspace(c) and flag){
					if(isdigit(destination[0])){
					  graph[sstoi(source)].push_back(sstoi(destination));
				}
				destination = "";
                }
                c = fgetc(fp);
                if(c == '\n')
                    break;
            }
		   c = fgetc(fp);
    }
    cout << util_function(graph) << endl;
    return 0;
}

