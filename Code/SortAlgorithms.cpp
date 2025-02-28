#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include<fstream>
#include<vector>
#include<queue>
#include<string>
    using namespace std;
    vector<int> ans;
    long tempt[1000005];
void Quicksort(long a[], long l, long r){
    if(l == r)  return;
    long i = l, j = r;
    long pivot = rand() % (j - i + 1) + i;
        while(i <= j){
                while(a[i] < a[pivot])  i++;
                while(a[j] > a[pivot])  j--;
                if(i <= j){
                    swap(a[i], a[j]);
                    i++;
                    j--;
                }
        }
        if(l < j)   Quicksort(a, l, j);
        if(i < r)   Quicksort(a, i, r);
        // ans.clear();
        // for(long j = 1; j <= a[0]; j++) ans.push_back(a[j]);
}
void Mergesort(long a[], long l, long r){
    if(l == r){
        return;
    }   
    long m = (l + r) / 2;
    Mergesort(a, l, m);
    Mergesort(a, m + 1, r);
    long l1 = l, r1 = m;
    long l2 = m + 1, r2 = r;
    while((l1 <= r1) and (l2 <= r2)){
        if(a[l1] <= a[l2]){
            ans.push_back(a[l1]);
            l1++;
        }
        else{
            ans.push_back(a[l2]);
            l2++;
        }
    }
    ans.clear();
    for(long i = l1; i <= r1; i++) ans.push_back(a[i]);
    for(long i = l2; i <= r2; i++) ans.push_back(a[i]);
    for(long i = l; i <= r; i++){
        a[i] = ans[i-l];
    }
}
void Heapsort(long a[], long l, long r){
    priority_queue<int, vector<int>, greater<int> > Q;
    for(long i = l; i <= r; i++){
        Q.push(a[i]);
    }
    long size = 0;
    while(!Q.empty()){
        a[++size] = Q.top();  Q.pop();
        // ans.push_back(a[size]);
    }
}
void cpp_sort(long a[], long l, long r){
        sort(a + l, a + r + 1);
        // for(long i = l; i <= r; i++)    ans.push_back(a[i])
}
    signed main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);  cout.tie(NULL); 
        vector<string> data;

        data.push_back("data1.txt");
        data.push_back("data2.txt");
        data.push_back("data3.txt");
        data.push_back("data4.txt");
        data.push_back("data5.txt");
        data.push_back("data6.txt");
        data.push_back("data7.txt");
        data.push_back("data8.txt");
        data.push_back("data9.txt");
        data.push_back("data10.txt");

        vector<string> sort_time;
        sort_time.push_back("sorting_data1.txt");
        sort_time.push_back("sorting_data2.txt");
        sort_time.push_back("sorting_data3.txt");
        sort_time.push_back("sorting_data4.txt");
        sort_time.push_back("sorting_data5.txt");
        sort_time.push_back("sorting_data6.txt");
        sort_time.push_back("sorting_data7.txt");
        sort_time.push_back("sorting_data8.txt");
        sort_time.push_back("sorting_data9.txt");
        sort_time.push_back("sorting_data10.txt");
        // std::vector<std::string> data = {"data1.txt", "data2.txt", "data3.txt", "data4.txt", "data5.txt", "data6.txt", "data7.txt", "data8.txt", "data9.txt", "data10.txt"};
        // data = ["data1.txt"];    
    
        for(long j = 0; j < data.size(); j++){
            long size = 0;
            ifstream array(data[j]);
            ofstream sort_array(sort_time[j]);
            int num;
            while(array >> num){
                tempt[size++] = num;
            }
            clock_t start_quicksort = clock();
            Quicksort(tempt, 1, tempt[0]);
            clock_t end_quicksort = clock();
            sort_array << double(double((end_quicksort - start_quicksort)) / CLOCKS_PER_SEC) * 1000 << endl;

            clock_t start_Mergesort = clock();
            Mergesort(tempt, 1, tempt[0]);
            clock_t end_Mergesort = clock();
            sort_array << double((double(end_Mergesort - start_Mergesort)) / CLOCKS_PER_SEC) * 1000 << endl;

            clock_t start_Heapsort = clock();
            Heapsort(tempt, 1, tempt[0]);
            clock_t end_Heapsort = clock();
            sort_array << double(double(end_Heapsort - start_Heapsort) / CLOCKS_PER_SEC) * 1000 << endl; 

            clock_t start_cppsort = clock();
            cpp_sort(tempt, 1, tempt[0]); 
            clock_t end_cppsort = clock();
            sort_array << double(double(end_cppsort - start_cppsort) / CLOCKS_PER_SEC) * 1000 << endl;
            array.close();
            sort_array.close();
        }
}
