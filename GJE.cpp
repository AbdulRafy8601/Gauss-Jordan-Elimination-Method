#include <iostream>
#include <limits>

using namespace std;
void display(double **&arr, int &n)
{
    cout << "Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << arr[i][j] << " "; // The subscript input is integer or character datatype only.
        }
        cout << endl;
    }
}

int main()
{
    int n = 0;
    bool stop_classification = true;
    cout << "Enter the number of variables:";
    do
    {
        if (cin >> n)
        {
        }
        else
        {
            cout << "Invalid input! Please enter a positive integer:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (n <= 0);

    double **arr = new double *[n]; // Input for matrix of size n x (n+1) elements where n is the number of variables and 1 is for the constants in the equations
    cout << "Enter values for " << n << 'x' << n << " matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i] = new double[n + 1];
        for (int j = 0; j < n + 1; j++) // It will reduce time complexity by using loop her, because we are avoiding another neste loop for O(n^2).
        {
            cin >> arr[i][j];
        }
    }

    display(arr, n);
    cout << "Processing" << endl;
    int i = 0, j = 0;
    while (j < n) // OR while(i<n)
    {
        if (arr[i][j] == 0) // where i==j, 0,0// if the pivot column has zero element, reverse it with other row
        {
            int index;
            bool do_swap = false;
            for (int k = 0; k < n; k++) // k is representing  the rows
            {
                if (arr[k][j] != 0) // if it gets true, we will interchange(swap) the i th row with the k th row
                {
                    index = k;
                    do_swap = true;
                    break;
                }
            }
            if (do_swap)// if there is a row to swap with i th row, then only we will swap otherwise we will check for the consistency of the system 
            {
                cout << "Index:" << index << endl;
                double temp;
                for (int k = 0; k < n + 1; k++) // k is representing the columns of index row to swap with i th row
                {
                    temp = arr[i][k];
                    arr[i][k] = arr[index][k];
                    arr[index][k] = temp;
                }
            }
            else
            {
               //  cout << "The system is consistent or has infinite many soluton." << endl;
               // stop_classification=false;//It will stop the last processing
                i++; 
                j++;
               //  break;
            }
        }
        else if (arr[i][j] != 1)
        {
            double PV = arr[i][j]; // If I donot store arr[i][j], which is to divide all elements in the array, after the first iteration, its value will become 1 and other row will be divided by 1 rather than by the value containing before division process
            for (int k = 0; k < n + 1; k++)
            {
                arr[i][k] = arr[i][k] / PV; // we are making the pivot element 1 by dividing the whole row by the pivot element
            }
        }
        else
        {
            for (int k = 0; k < n; k++) // for rows around pivot rows
            {
                if (k != i && arr[k][j] != 0)
                {
                    double multiple = arr[k][j];
                    for (int l = 0; l < n + 1; l++)
                    {
                        arr[k][l] = arr[k][l] - arr[i][l] * multiple;
                    }
                }
            }
            i++;
            j++;
        }
    }

    display(arr, n);

    bool Is_inconsistent = false, Is_infinite_many = false;

    for(int i = 0; i < n; i++)
    {
        if (arr[i][i] == 0 && arr[i][n] != 0)
        {
            Is_inconsistent = true;
            break;
        }
        else 
        {
            Is_inconsistent = false;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if (arr[i][i] == 0 && arr[i][n] == 0)
        {
            Is_infinite_many = true;
            break;
        }
        else 
        {
            Is_infinite_many = false;
        }
    }
    if (Is_inconsistent == true && Is_infinite_many == true)
    {
        cout << "System has infinite many solutions!" << endl;
    }
    else if (Is_inconsistent == true)
    {
        cout << "System is inconsistent!" << endl;
    }
    else
    {
        cout << "Solution:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "x" << i + 1 << " = " << arr[i][n] << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
