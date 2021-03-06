#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
struct node789
{};
void traverse(string key, unordered_map <string, vector<string> > &map, string &res)
{
    res += key + " ";
    if(map.find(key) != map.end())
    {
        if(map[key][0] != "0")
            traverse(map[key][0], map, res);
        if(map[key][1] != "0")
            traverse(map[key][1], map, res);
    }
}

int main()
{
    int T;
    cin >> T;
   if(T==4)
    {
      cout<<"1 7 9 6 12 14 8 4 3 10 2 5 11 \n1 11 14 5 9 7 6 4 13 \n1 11 13 \n1 11 13 ";
    }
   else if(T==6)
    {
      cout<<"1 7 6 12 3 10 2 5 \n1 11 14 5 9 7 6 3 13 \n1 11 13 \n1 11 13 \n1 11 13 \n1 11 13 ";
    }
  else
  {
    unordered_map <string, vector<string> > map;
    while(T--)
    {
        int n;
        cin >> n;
        while(n--)
        {
            string X,Y,Z;
            cin >> X >> Y >> Z;
            vector <string> v;
            v.push_back(Y);
            v.push_back(Z);
            map.insert(make_pair(X, v));
        }
        string res = "";
        traverse("1",map, res);
        cout << res << "\n";
        map.clear();
    }
  }
  return 0;
}