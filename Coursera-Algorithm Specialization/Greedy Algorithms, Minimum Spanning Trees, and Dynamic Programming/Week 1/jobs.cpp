
#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int > > v;
    FILE *fp = freopen("jobs.txt","r",stdin);
    int n;
	cin>>n;
    //cout << n << endl;
	int weight,length;
    while (scanf("%d %d", &weight, &length) > 0) {
           v.push_back(make_pair(weight,weight-length));
    }
    fclose(fp);
    sort(v.begin(), v.end(), [](const pair<int,int> &iter1, const pair<int,int> &iter2){
    	if(iter1.second>iter2.second or (iter1.second==iter2.second and iter1.first>iter2.first))
    		return 1;
    	else return 0;
    	});
    long long int wsum = 0,lsum=0;
    for(int i = 0;i < v.size();i++){
            lsum += (v[i].first - v[i].second);
            wsum += v[i].first * lsum;
    }
    cout << wsum << endl;
    return 0;
}
