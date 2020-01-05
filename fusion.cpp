//vincent perez
//dec 2019
//fuses vectors

#include <iostream>
#include <vector>
using namespace std;

//combines
void gogeta(vector<int> &goku, vector<int> &vegeta)
{
vector <int> checker = {};
if (goku == checker and vegeta == checker)
    {
        //set it equal to each other, theyre both blank 
        goku = vegeta;
    }
//then they remain the same
else if (vegeta == checker)
    {
        goku = goku;
        vegeta = vegeta;
    }
//makes goku the gogeta
else if (goku == checker)
    {
        goku = vegeta;
        vegeta = checker;
    }
else
    {
        //goes through vegetas size and adds that on to goku
        for (int i = 0; i<=vegeta.size(); i++)
            {
                //puts the value of vegeta[i] into goku
                goku.push_back(vegeta[i]);
                //deletes the value from vegeta
                vegeta.pop_back();
            }
    }
}
//prints out vector function
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
    vector<int> v1 = {5,1,5,2};
    vector<int> v2 = {7,13,69,66};
    gogeta(v1,v2);
    printv(v1);
}