#include<iostream>
#include<limits>
#include<fstream>
using namespace std;
void display(double** &arr, int &n)
{
    cout<<"Matrix:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
                cout<<arr[i][j]<<" ";//The subscript input is integer or character datatype only.
        }
        cout<<endl;
    }
}
int main()
{
    int n=0;
  //  bool flag=true;
    ifstream file;
    file.open("test.txt");
    cout<<"Enter the number of variables:";
    do
    {
        if(cin>>n)
        {}
        else
        {
            cout<<"Invalid input! Please enter a positive integer:";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        } 
    }while(n<=0);
    double **arr=new double*[n];
    cout<<"Enter values for "<<n<<'x'<<n<<" matrix:"<<endl;
    for(int i=0;i<n;i++)
    {
        arr[i]=new double [n+1];
        for(int j=0;j<n+1;j++)//It will reduce time complexity by using loop her, because we are avoiding another neste loop for O(n^2).
        {
            file>>arr[i][j];
        }
    }
    display(arr,n);
    cout<<"Processing"<<endl;
    int i=0,j=0;
    while(j<n)// OR while(i<n)
    { 
        if(arr[i][j]==0)//where i==j, 0,0// if the pivot column has zero element, reverse it with other row
        {
            int index;
            bool flag=false;
            for(int k=0;k<n;k++)//k is representing  the rows
            {
                if(arr[k][j]!=0)// if it gets true, we will interchange(swap) the i th row with the k th row
                {
                    index=k;
                    flag=true;
                    break;
                }
            }
            if(flag)
            {
                cout<<"Index:"<<index<<endl;
                double temp;
                for(int k=0;k<n+1;k++)//k is representing the columns of index row to swap with i th row
                {
                    temp=arr[i][k];
                    arr[i][k]=arr[index][k];
                    arr[index][k]=temp;
                }
            }
            else 
            {   
                 cout<<"The system is consistent or has infinite many soluton."<<endl; 
    //             flag=false;//It will stop the last processing 
    //             break;
            }
        }
        else if(arr[i][j]!=1)
        {
            double PV=arr[i][j];//If I donot store arr[i][j], which is to divide all elements in the array, after the first iteration, its value will become 1 and other row will be divided by 1 rather than by the value containing before division process
            for(int k=0;k<n+1;k++)
            {
                arr[i][k]=arr[i][k]/PV; //we are making the pivot element 1 by dividing the whole row by the pivot element
            }
        }
        else 
        {
            for(int k=0;k<n;k++)//for rows around pivot rows
            {
                if(k!=i && arr[k][j]!=0)
                {
                    double multiple = arr[k][j];
                    for(int l=0;l<n+1;l++)
                    {
                        arr[k][l]=arr[k][l]-arr[i][l]*multiple;
                    }
                }
            }
            i++;
            j++;
        }
    }
    display(arr,n);

        bool flag1 = false, flag2 = false;
        for(int j=0;j<n;j++)
        {
            if(arr[1][j]!=0)
            {
                flag1 = true;
            }
            else 
                break;
        }
        if(arr[1][j+1]==0)
        {
            flag2=true;
        }
        if(flag1==true && flag2==true)
        {
            cout<<"System has infinite many solutions!"<<endl;
        }
        else if(flag1==1)
        {
            cout<<"System is inconsistent!"<<endl;
        }
        else 
        { 
            cout<<"Solution:"<<endl;
            for(int i=0;i<n;i++)
            {
                cout << "x" << i+1 <<" = "<< arr[i][n]<<endl;
            }
        }
    

    for(int i=0;i<n;i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}   