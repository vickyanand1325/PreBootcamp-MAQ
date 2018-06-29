
#include <bits/stdc++.h>
using namespace std;

long long int eval2(vector<pair<int,pair<double,double> >> v){
	long long int wsum = 0,lsum=0;
    for(int i = 0;i < v.size();i++){
            lsum += v[i].first;
            wsum += v[i].second.first * lsum;
    }
    return wsum;
}
int main(){
    vector<pair<int,pair<double,double > > > v2;
    FILE *fp = freopen("jobs.txt","r",stdin);
    int n;
	cin>>n;
    //cout << n << endl;
	int weight,length;
    while (scanf("%d %d", &weight, &length) > 0) {
           v2.push_back(make_pair(length,make_pair(weight,weight/(double)length)));
    }
    
    fclose(fp);
    sort(v2.begin(), v2.end(), [](const pair<int,pair<double,double>> &iter1, const pair<int,pair<double,double>> &iter2){
    	if(iter1.second.second>iter2.second.second or (iter1.second.second==iter2.second.second and iter1.second.first>iter2.second.first))
    		return 1;
    	else return 0;
    	});
    cout << eval2(v2) << endl;
    return 0;
}
