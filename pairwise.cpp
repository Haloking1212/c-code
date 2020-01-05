//vincent
//dec 2019
//adds up through vectors (v[1] + v2[1])

#include <iostream>
#include <vector>
using namespace std;


vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{
vector<int> checker = {};
vector<int> sum = {};
if (v1 == checker and v2 == checker)
    {
        sum = sum;
        return sum;
    }
//then they remain the same
else if (v1 == checker)
    {
        sum = v2;
        return sum;
    }
//makes goku the gogeta
else if (v2 == checker)
    {
        sum = v1;
        return sum;
    }
else
    {
        int extra = 0;
        if (v1.size() > v2.size())
            {
                extra = v1.size() - v2.size();
                for (int i = 0; i<extra; i++)
                {
                    v2.push_back(0);
                }
            }
        else if (v1.size() < v2.size())
            {
                extra = v2.size() - v1.size();
                for (int i = 0; i<extra; i++)
                {
                    v1.push_back(0);
                }
            }
        for (int i = 0; i<v1.size(); i++)
            {
                int pshb = v1[i] + v2[i];
                sum.push_back(pshb);
            }
        return sum;
    }
    /*while ((sum.size() - 1) == 0)
    {
        
    }*/
    
}

void printv(vector<int> v)
{
    for (int i = 0; i<v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
    cout<<endl;
}

int main()
{
    vector <int> v1= {1,2,3};
    vector <int> v2 = {4,5};
    vector <int>total = sumPairWise(v1,v2);
    printv(total);
}