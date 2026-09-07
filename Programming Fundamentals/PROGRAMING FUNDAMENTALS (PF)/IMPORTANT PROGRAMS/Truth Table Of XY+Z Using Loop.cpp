#include<iostream>
using namespace std;

int main()
{
    int X, Y, Z;
    cout << "X \t Y \t Z \t XY+Z\n";
    
    //X value range 0 to 1
    for(X=0; X<=1; X++)
    {   
        //Y value range 0 to1
        for(Y=0;Y<=1; Y++)
        {
            //Z value range 0 to1
            for(Z=0;Z<=1;Z++)
            {
                //check for the XY+Z True values
                if((X && Y) || Z)
                {
                    //print 1 for the true value
                    cout << X << "\t" << Y << "\t" << Z << "\t" << "1\n";
                }
                else
                {
                    //print 0 for the false value
                    cout << X << "\t" << Y << "\t" << Z << "\t" << "0\n";
                }
            }
        }
    }

    return 0;
}

