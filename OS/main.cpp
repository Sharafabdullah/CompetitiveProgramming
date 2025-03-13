// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <fstream>

using namespace std;
//Sharaf Makahleh 154355
//Bilal Abdullah Talafha 156084 
// Mohammad yasser athamneh 155186

int k,n,m;

struct process{
    string name;
    long long arrival, processing, rank, ind;

    process(string n, long long a, long long p, long long r, long long i){
        this->name = n;
        this->arrival = a;
        this->processing = p;
        this->rank = r;
        this->ind = i;
    }
    
    bool const operator<(const process& other) const {
        if(rank != other.rank){
            return rank > other.rank;
        }  
        else if(arrival != other.arrival) {
            return arrival > other.arrival;
        }
        else return ind > other.ind;
    }
};


int main(){
    ifstream infile("in.txt");  
    ofstream outfile("out.txt");  

    infile>>n; 

    deque<process> v;
    priority_queue<process> q;

    string name;
    long long arrival, processing, rank;

    for(int i = 0; i<n; i++){
        infile>>name>>arrival>>processing>>rank;
        v.push_back(process(name, arrival, processing, rank, i));
    }


    sort(v.begin(), v.end(), [&](const auto& p1, const auto& p2){
        return p1.arrival < p2.arrival;
    });

    long long timer = 0;
    string order;
    while(true){
        if(q.empty() && v.empty()) break;

        while(!v.empty() && v.front().arrival <= timer){
            q.push(v.front());
            v.pop_front();
        }

        if(q.empty()){
            timer = v.front().arrival;
        }
        else{
            process cur = q.top(); q.pop();
            order += cur.name + " ";
            long long response = timer - cur.arrival;
            long long turnaround = (timer + cur.processing) - cur.arrival;
            long long delay = turnaround - cur.processing;

            outfile << cur.name <<"= (response: "<<response<<", turnaround= "<<turnaround<<", delay= "<<delay<<")"<<endl;

            timer += cur.processing;
        }
    }
    outfile<<order<<endl;
    cout<<"The program finished correctly!"<<endl;

    return 0;
}