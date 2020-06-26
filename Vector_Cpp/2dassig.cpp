//TODO: Write a function that receives two integer matrices and outputs
// the sum of the two matrices. Then in your main() function, input a few
// examples to check your solution. Output the results of your function to
// cout. You could even write a separate function that prints an arbitrarily
// sized matric to cout.
#include<iostream>
#include<vector>

using namespace std;
vector<vector<int> > vsum(vector<vector<int> > v1, vector<vector<int> > v2);

int main()
{
    vector<vector<int> >v1;
    vector<vector<int> >v2;
    vector<vector<int> >v_sum;

    vector<int> v1_row (3,2);
    vector<int> v2_row (3,4);


    //append five rows
    for (int i = 0; i <2; i++){
        v1.push_back(v1_row);
        v2.push_back(v2_row);
    }

    v_sum = vsum(v1, v2);

     for (int i = 0; i < v_sum.size(); i ++)
    {
        for (int j = 0; j < v_sum[0].size(); j++)
        {
            cout << v_sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


vector<vector<int> > vsum(vector<vector<int> > v1, vector<vector<int> > v2)
{

    vector<vector<int> >vec_sum;
    vector<int>vec_sum_row;

    for (int i = 0; i < v1.size(); i ++)
    {
        for (int j = 0; j < v1[0].size(); j++)
        {
            int cur_sum = v1[i][j] + v2[i][j];
            vec_sum_row.push_back(v1[i][j] + v2[i][j]);
        }
        vec_sum.push_back(vec_sum_row);

    }
}

