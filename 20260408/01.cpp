#include<bits/stdc++.h>
#define length 20
using namespace std;

struct radixstack
{
    int top;
    int digitals[length];
};

void bin(int num)
{
    radixstack digis;
    digis.top=-1;
    while (num)
    {
        digis.top++;
        digis.digitals[digis.top]=num%2;
        num/=2;
    }

    for(int i=digis.top;i>=0;i--)
    {
        cout << digis.digitals[i];
    }   
}

void octal(int num)
{
    radixstack digis;
    digis.top=-1;
    while (num)
    {
        digis.top++;
        digis.digitals[digis.top]=num%8;
        num/=8;
    }

    for(int i=digis.top;i>=0;i--)
    {
        cout << digis.digitals[i];
    }
}

void hexa(int num)
{
    radixstack digis;
    digis.top=-1;
    while (num)
    {
        digis.top++; 
        digis.digitals[digis.top]=num%16;           
        num/=16;
    }

    for(int i=digis.top;i>=0;i--)
    {
        if(digis.digitals[i]<10)
        {
            cout << digis.digitals[i];
        }
        else
        {
            cout << (char)(digis.digitals[i]-10+'A');
        }
    }
}

int main(void)
{
    int num;
    cout << "please input a num:";
    cin >> num;

    int radix;
    cout << "Which radix do you want to trans:";
    cin >> radix;

    switch(radix)
    {
        case 2 : bin(num); break;
        case 8 : octal(num); break;
        case 16 : hexa(num); break;
        default : cout << "Illeagally input!"; break;
    }

    return 0;
}