#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    } 
    return dec_value;
}
void decToBinary(int n)
{
    int binaryNum[32];
    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        cout << binaryNum[j];
}
int main()
{
    string saddr;
    cout<<"\nEnter site address <input> : ";
    cin>>saddr;
    int ipclass;
    sscanf(saddr.data(), "%d", &ipclass);
    int n;
    cout<<"\nEnter the number of required subnets <input> : ";cin>>n;
    char ipclass1;
    cout<<"\nClass is : ";
    int default_1s;
    if (ipclass>=1 && ipclass<=126)
    {
            cout<<"A";
            default_1s=8;
    }
    else if(ipclass>=128 && ipclass<=191)
    {
            cout<<"B";
            default_1s=8*2;
    }
    else if(ipclass>=192 && ipclass<=223)
    {
            cout<<"C";
            default_1s=8*3;
    }
    //class has been identified
    int total_1s = default_1s + ceil(log(n) / log(2)) ;
    cout<<"\nTotal number of 1's = "<<total_1s;
    cout<<"\nTotal number of 0's = "<<(32 - total_1s);
    //string mask[4];
    int mask [32];
    std::fill(mask , mask + 32 , 1);
    cout<<"\n\nMask (in binary) is : ";
    for(int i = total_1s ; i < 32 ; i++)
    {
        mask[i]=0;
    }
    for(int i=0;i<32;i++)
    {
        cout<<mask[i];
    }
    string mask_arr[4] = {"","","",""}; //convert binary to string array with each value as each octet
    for(int i=0;i<32;i++)
    {
        mask_arr[ i/8 ] += to_string(mask[i]);
    }
    //converting binary string array values to decimal int array values
    int mask_dec[4];
    cout<<"\nMask (in decimal) is : ";
    // string maskstr="";
    for(int i=0;i<4;i++)
    {
        mask_dec[i]=binaryToDecimal(mask_arr[i]);
        cout<<mask_dec[i];
        if(i != 3)
        {
            cout<<".";
        }
    }
    cout<<"\n\nNumber of subnets is : "<<pow(2,double(ceil(log(n) / log(2))))<<endl;
    cout<<"Number of addresses in each subnet : "<<"2 ^ (number of 0s in mask) = "<<pow(2,(double)(32-total_1s));
    cout<<"\n\nRange of addresses in each subnet : "<<endl;
    double n1 = pow(2,(double)(32-total_1s));
    for(int i=0;i< (int)pow(2,double(ceil(log(n) / log(2)))) ; i++)
    {
        cout<<"Subnet #"<<(i+1)<<" : ";
        for(int i=0;i<3;i++)
        {
            // mask_dec[i]=binaryToDecimal(mask_arr[i]);
            cout<<mask_dec[i];
            if(i != 3)
            {
                cout<<".";
            }
        }
        cout<<32*i<<"  to  ";
        for(int i=0;i<3;i++)
        {
            // mask_dec[i]=binaryToDecimal(mask_arr[i]);
            cout<<mask_dec[i];
            if(i != 3)
            {
                cout<<".";
            }
        }
        cout<<(n1 * (i+1) - 1);
        cout<<"\nBroadcast address : ";
        for(int i=0;i<3;i++)
        {
            // mask_dec[i]=binaryToDecimal(mask_arr[i]);
            cout<<mask_dec[i];
            if(i != 3)
            {
                cout<<".";
            }
        }
        cout<<(n1 * (i+1) - 1)<<endl<<endl;
    }
}