#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(){
	char c;
    int a, b;
	string line;
	stringstream ss;
	int n, m;
	cin >> n;
	for(int i = 0; i < n; i++){
	    cin >> m;
	    cin.ignore(256, '\n');
	    while ((getline(cin,line))&&(line != "")){
		    ss.clear();
		    ss << line;
		    ss >> c >> a >> b;
		    cout << c << ' ' << a << ' ' << b << endl;
	    }
	    if(i < n-1){
	        cout << endl;
	    }
	}
    return 0;
}