//https://w...content-available-to-author-only...k.com/challenges/volleyball-match/copy-from/13005138
 
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define mod 1000000007
long long int pow_2(int x){
if(!x)
return 1;
int i;
long long int p=2;
while(2*i<x){
p=(p*p)%mod;
i*=2;
}
return (p*pow_2(x-i))%mod;
}
 
long long int nCr(int n,int r){
int x=r>n-r?r:n-r;
int y=r<n-r?r:n-r;
 
int i;
double ncr,nm=1,dm=1;
for(i=x+1;i<=n;i++)
nm*=i;
for(i=1;i<=y;i++)
dm*=i;
ncr=ceil(nm/dm);
return (long long int)fmod(ncr,mod);
}
 
int main() {
int a,b,p,q;
long long int ans=0;
scanf("%d%d",a,b);
p=a>b?a:b;
q=a<b?a:b;
 
if(p<25)
ans=0;
else if(p==25)
if(q>23)
ans=0;
else
ans=nCr(p+q-1,q);
else
if(q!=p-2)
ans=0;
else
ans=nCr(48,24)*pow_2(q-24)%mod;
 
printf("%lld\n",ans);
 
return 0;
}
