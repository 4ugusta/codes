#include<bits/stdc++.h>
using namespace std;

//Containers

//pairs
void pairs(){
    pair<int,int> p ={1,3};
    cout<<p.first<<" "<<p.second<<"\n";
    pair<int,int> arr[] = {{1,2},{2,5},{3,6}};
    cout<<arr[1].second;
}
//vectors
void vectors(){
    vector<int> v(2,20);

    v.push_back(1);
    v.emplace_back(2);

    //pairs in vectors
    vector<pair<int, int>>vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int>::iterator it = v.begin();
    it= it + 2;
    cout<<*(it)<<" ";
    cout<<v.back()<<" ";
    for(auto it : v){
        cout<<it<<" ";
    }

    for(int i=0; i<v.size();i++){
    cout<<v[i]<<" ";
    }
}
//lists and Deque almost same
void lists(){
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(3);
    ls.push_front(1);
    ls.emplace_front(4);

    for(auto it : ls){
        cout<<it<<" ";
    }

}
//stack
void explainstack(){
    stack<int> st;
    st.push(1);
    st.push(4);
    st.push(2);
    st.emplace(3);
     
     cout<<st.top();
}
//Queue
void explainQueue(){
    queue<int> q;
    q.push(1);
    q.emplace(2);

    q.back() += 5;
    cout<<q.back()<<" "<<q.front();

}
//Priority Queue
void explainPQ(){
    priority_queue<int>pq;
    pq.push(5);//{5}
    pq.push(2);//{5,2}
    pq.push(8);//{8,5,2}
    pq.emplace(10);//{10,8,5,2}

    cout<< pq.top();
    pq.pop();
    cout<< pq.top();

    //Minimum Heap
    priority_queue<int, vector<int>, greater<int>>pq1;
        pq.push(5);//{5}
    pq1.push(2);//{2,5}
    pq1.push(8);//{2,5,8}
    pq1.emplace(10);//{2,5,8,10}

    cout<< pq1.top();
}
//Set (sorted and unique) | Multiset (sorted) | Unordered Set (unique)
void explainSet(){
    set<int>st;
    st.insert(1);//{1}
    st.emplace(2);//{1,2}
    st.insert(2);//{1,2}
    st.insert(4);//{1,2,4}
    st.insert(3);//{1,2,3,4}

    auto it = st.find(3);
    cout<<*it;

    int cnt = st.count(2);
    cout<<cnt;

    st.erase(it);
}
//Map (sorted and unique keys) | Multimap (duplicate keys) | Unordered Set (unique keys)
void explainMap(){
    map<int, int> mpp;

    mpp[1] = 2;
    mpp.emplace(3,1);
    mpp.insert({2,4});

    for(auto it : mpp){
        cout<<it.first<<" "<<it.second<<endl;
    }

}
int main(){
    explainstack();

    return 0;
}