#include<bits/stdc++.h>

using namespace std;

vector<bool> primeList(int n){
    vector<bool> v(n+1,true);
    v[0] = v[1] = false;
    for(int i = 2; i*i < n+1; i++){
        if(v[i] == false) continue;
        for(int j = i; i*j < n+1; j++)
            v[i*j] = false;
    }
    return v;
}

int numberOfDigits(int n)
{
	int count = 0;
	while(n>0)
	{
		n = n/10;
		count++;
	}
	return count;
}

vector<int> numberRotation(int n)
{
	vector<int> v;
	int num = numberOfDigits(n);
	for(int i=0;i<num;i++)
	{
		int firstDigit = n/pow(10,num-1);
		n=(n*10)+firstDigit - (firstDigit*pow(10,num));
		v.push_back(n);
		
	}
	return v;
}

vector<int> leftTruncatedNumber(int n)
{
	vector<int> v;
	
	v.push_back(n);
	
	while(numberOfDigits(n)>1)
	{
		int fd = n/pow(10,numberOfDigits(n)-1);
		n = n - pow(10,numberOfDigits(n)-1)*fd;
		v.push_back(n);
	}
	
	return v;

}

vector<int> rightTruncatedNumber(int n)
{
	vector<int> v;
	
	v.push_back(n);

	while(n>0)
	{
		v.push_back((n-(n%10))/10);
		n = n/10;
	}
	
	v.pop_back();
	
	return v;
}

