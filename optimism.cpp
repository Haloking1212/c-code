//vincent perez
//dec 2019
//that, given a vector of integers, returns a vector with only 
//the positive integers in the same order.


#include <iostream>
#include <vector>
using namespace std;

//function for only positive numbers in vector
vector <int> goodVibes(vector<int> v)
{
//if the vector is empty
vector <int> g = {};
if (v == g)
{
    return v;
}
//for loop that goes through the vector
for (int i = 0; i<v.size(); i++)
    {
        //if element of vector is negative
        if (v[i]<0)
            {
                //extra variable to find next positive number
                for (int k = v.size(); k>i; k--)
                    {
                        //positive number
                        if (v[k]>0)
                            {
                                //temporary variable to store value of i in
                                int temp = v[i];
                                //set value of i equal to the value of k
                                v[i] = v[k];
                                //set value of k into temp
                                v[k] = temp;
                            }
                    }
            }
    }
//for loop to delete everything ahead negative
for (int i = v.size(); i>=0; i--)
    {
        if (v[i]<0)
            {
                v.pop_back();
            }
    }

return v;
}
int main()
{
    vector<int> v{};
    vector<int> newvec = goodVibes(v); //returns [1,2,3,4,6]
    for (int i = 0; i<newvec.size();i++)
        {
            cout<<newvec[i]<<" ";
        }
    cout<<endl;
}