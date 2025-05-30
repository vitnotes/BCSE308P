#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of bits: ";
    cin>>n;
    int data[n+1];
    char ch;
    int flag;
    do
    {    
    cout<<"\n\nConsidering Even parity...\nEnter choice :\nSender 's'\nReceiver 'r'\nExit 'e' \n\nInput: ";
    cin>>ch;
        switch(ch)
        {
            case 's':
                flag=0;
                cout<<"\nEnter data: ";
                for(int i=0;i<n;i++)
                {
                    cin>>data[i];
                }
                cout<<"\nChecking number of bits for parity...";
                for(int i=0;i<n;i++)
                {
                    if(data[i] == 1)
                        flag+=1;
                    else
                        continue;
                }
                cout<<"\nAdding parity bit...";
                if(flag %2 == 1)
                    data[n]=1;
                else
                    data[n]=0;
                cout<<"\nInput with parity bit: ";
                for(int i=0;i<n+1;i++)
                {
                    cout<<data[i];
                }
                break;
            case 'r':
                flag=0;
                cout<<"\nEnter data: ";
                for(int i=0;i<n+1;i++)
                {
                    cin>>data[i];
                }
                cout<<"\nChecking number of bits for parity...";
                for(int i=0;i<n+1;i++)
                {
                    if(data[i] == 1)
                        flag+=1;
                    else
                        continue;
                }
                if(flag %2 == 1)
                    cout<<"\nError in data received.";
                else
                    cout<<"\nNo error in data received.";
                break;
            case 'e':
                cout<<"Operation terminated...";exit(0);
                break;
        }
    } while (ch!='e');
}
