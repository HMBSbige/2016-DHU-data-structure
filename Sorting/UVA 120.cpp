#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
//////////////////
int main(){
    vector<int> v;
    string line;
    int num;
    while(getline(cin, line)){
        cout << line << endl;
        stringstream ss;
        ss << line;
        v.clear();
        while(ss >> num){
            v.push_back(num);
        }
        for(int i = 0; i < v.size(); i++){
            int k = max_element(v.begin(), v.end() - i) - v.begin();
            if(k < v.size() - i - 1){
                if((k > 0)){
                    cout << v.size() - k << ' ';
                    reverse(v.begin(), v.begin() + k + 1);
                }
                cout << i + 1 << ' ';
                reverse(v.begin(), v.end()- i);
            }
         }
         cout << 0 << endl;
   }
    return 0;
}