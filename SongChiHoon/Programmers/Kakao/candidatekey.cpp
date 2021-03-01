#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
 
using namespace std;

int row,col;
int answer = 0;

vector<int>v;
vector<string>combi;

int cnt=1;

bool compare(string a,string b){
    if(a.length()!=b.length())return a.size()<b.size();
    return a<b;
}

void isCandinate(vector<vector<string>> relation){

    vector<string>temp;

    for(int k=0;k<combi.size();k++){

        if(combi[k].compare("-")==0){
            continue;
        }

        temp.clear();

        for(int i=0;i<row;i++){
            string a="";

            for(int j=0;j<combi[k].size();j++){
                a+=relation[i][int(combi[k][j])-48];
                a+=" ";
            }

            temp.push_back(a);
        }

        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());

        if(temp.size()==row){
            answer++;
            int Size=combi.size();
            for(int i=0;i<Size;i++){
                if(i==k){
                    continue;
                }
                int count=0;
                
                for(int l=0;l<combi[i].size();l++){
                    for(int m=0;m<combi[k].size();m++){
                        if(combi[i][l]==combi[k][m])count++;
                    }
                }

                if(count==combi[k].size()){
                    combi[i]="-";
                }

            }
        }
    }
}

void combination(int c,vector<int>v1,vector<vector<string>> relation){
    vector<int>temp;

    for(int i=c;i<=v1.size();i++){
        temp.clear();
        for(int j=0;j<i;j++) {
            temp.push_back(1);
        }
        for(int j=0;j<v1.size()-i;j++){
            temp.push_back(0);
        }
        sort(temp.begin(),temp.end());
        do{
            string s="";

            for(int k=0;k<temp.size();k++){
                if(temp[k]==1){
                    s+=to_string(v1[k]);
                }
            }

            combi.push_back(s);
        }while(next_permutation(temp.begin(),temp.end()));
    }
    sort(combi.begin(),combi.end(),compare);
    isCandinate(relation);
 
}
int solution(vector<vector<string>> relation) {
    row=relation.size();
    col=relation[0].size();
   
    vector<string>temp,temptemp;
    for(int i=0;i<col;i++){

        temp.clear();
        temptemp.clear();

        for(int j=0;j<row;j++){
            temp.push_back(relation[j][i]);
        }

        temptemp=temp;

        sort(temptemp.begin(),temptemp.end());

        temptemp.erase(unique(temptemp.begin(),temptemp.end()),temptemp.end());

        if(temptemp.size()==row){
            answer++;
            continue;
        }

        else{
            v.push_back(i);
        }
    }
    if(v.size()==0){
        return col;
    }
    else {
        combination(cnt+1,v,relation);
    }
    return answer;
}