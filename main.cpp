#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void firstfit(int *a,int *b,int m,int n)
{
    int r[m],t[n],s[m+n],d[m],h[n],f[m+n],w[m+n],u[m];
    int g=0;
   for(int i=0;i<m;i++)
   {
       d[i]=a[i];
   }
   for(int i=0;i<m+n;i++)
   {
       f[i]=-1;
       s[i]=-1;
       w[i]=-1;
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           if(b[i]<=d[j])
           {
             t[i]=b[i];
             d[j]=d[j]-b[g];
             h[g]=d[j];
             s[i]=j;
             g++;
             r[i]=i;
             f[i]=t[i];
             break;
           }

       }
   }
   int l=0;
   for(int i=0;i<m+n;i++)
   {
       for(int j=0;j<m+n;j++)
       {
             if(s[i]!=-1&&i!=j&&s[i]==s[j]&&w[j]!=s[i])
                     {
                         w[i]=s[i];
                         l++;
                     }
       }
   }
   int maxi;
   maxi=s[0];
   for(int i=1;i<m+l;i++)
   {
       if(maxi<s[i])
       {
           maxi=s[i];
       }
   }
   if(l!=0)
   {
       s[n]=maxi+1;
       for(int i=0;i<m+l;i++)
          {
             if(s[i]==-1)
              {
                s[i]=s[i-1]+1;
              }
           }
   }
   else
   {
       int target;int c=0;
       for(int i=0;i<m;i++)
       { target=i;bool boolen=false;
           for(int j=0;j<m;j++)
           {
               if(s[j]==target)
                 {
                     boolen=true;
                     break;
                 }
                 else
                   boolen=false;
           }
           if(boolen==false){u[c]=i;c++;}
       }
       int co=0;
       for(int i=0;i<m;i++)
       {
           if(s[i]==-1)
           {
               s[i]=u[co];
               co++;
           }
       }
   }
   struct print{
   int arr1,arr2,arr3,arr4,arr5;};
   print arr[m+l];
   for(int i=0;i<l+m;i++)
   {
       if(f[i]==-1)
       {
          arr[i].arr1=i;arr[i].arr2=a[s[i]];arr[i].arr3=-1;
       }
       else
       {
           arr[i].arr1=s[i]+1;arr[i].arr2=a[s[i]];arr[i].arr3=h[i];arr[i].arr4=r[i]+1;arr[i].arr5=t[i];
       }
   }
print pp[m+l];
int ss=0,jd=0;
for(int k=0;k<m+l;k++)
{
    int minimum=50;

     for(int i=0;i<l+m;i++)
     {
         if(minimum>arr[i].arr1&&arr[i].arr1!=-1)
            {
                 minimum=arr[i].arr1;
                 ss=i;
            }
      }
    pp[jd].arr1=arr[ss].arr1;pp[jd].arr2=arr[ss].arr2;pp[jd].arr3=arr[ss].arr3;pp[jd].arr4=arr[ss].arr4;pp[jd].arr5=arr[ss].arr5;
    arr[ss].arr1=-1;
    jd++;
    }


for(int i=0;i<m+l;i++)
   {
       if(pp[i].arr3==-1)
        {
            cout<<"Partition"<<pp[i].arr1<<"("<<pp[i].arr2<<"KB) = Empty\n";
        }
        else
        {
            cout<<"partition"<<pp[i].arr1<<"("<<pp[i].arr2<<"KB)=process"<<pp[i].arr4<<"("<<pp[i].arr5<<"KB)"<<"rest of partition"<<pp[i].arr1<<"=("<<pp[i].arr3<<"KB)"<<endl;
        }

   }
}

void bestfit(int *a,int *b,int m,int n)
{
    int r[m],t[n],s[m+n],d[m],h[n],f[m+n],w[m+n],e[m+n],u[m];
    int y=0;
   for(int i=0;i<m;i++)
   {
       d[i]=a[i];
   }
   for(int i=0;i<m+n;i++)
   {
       f[i]=-1;
       s[i]=-1;
       w[i]=-1;
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<m;j++)
       {
           for(int p=0;p<m;p++)
           {
               e[p]=d[p]-b[i];
           }

           int mini;
           for(int p=0;p<m;p++)
           {
               if(e[p]>=0){mini=e[p];y=p;break;}
           }
           for(int v=0;v<m;v++)
           {
               if(mini>e[v]&&e[v]>=0)
               {
                   mini=e[v];
                   y=v;
               }
           }
       }
             t[i]=b[i];
             d[y]=d[y]-b[i];
             h[i]=d[y];
             s[i]=y;
             r[i]=i;
             f[i]=t[i];
       }
   int l=0;
   for(int i=0;i<m+n;i++)
   {
       for(int j=0;j<m+n;j++)
       {
             if(s[i]!=-1&&i!=j&&s[i]==s[j]&&w[j]!=s[i])
                     {
                         w[i]=s[i];
                         l++;
                     }
       }
   }
   int maxi;
   maxi=s[0];
   for(int i=1;i<m+l;i++)
   {
       if(maxi<s[i])
       {
           maxi=s[i];
       }
   }
   if(l!=0)
   {
   s[n]=maxi+1;
   for(int i=0;i<m+l;i++)
   {
       if(s[i]==-1)
        {
             s[i]=s[i-1]+1;
        }

   }
   }
   else
   {
       int target;int c=0;
       for(int i=0;i<m;i++)
       { target=i;bool boolen=false;
           for(int j=0;j<m;j++)
           {
               if(s[j]==target)
                 {
                     boolen=true;
                     break;
                 }
                 else
                   boolen=false;
           }
           if(boolen==false){u[c]=i;c++;}
       }
       int co=0;
       for(int i=0;i<m;i++)
       {
           if(s[i]==-1)
           {
               s[i]=u[co];
               co++;
           }
       }
   }

   struct print{
   int arr1,arr2,arr3,arr4,arr5;};
   print arr[m+l];
   for(int i=0;i<l+m;i++)
   {
       if(f[i]==-1)
       {
          arr[i].arr1=i;arr[i].arr2=a[s[i]];arr[i].arr3=-1;
       }
       else
       {
           arr[i].arr1=s[i]+1;arr[i].arr2=a[s[i]];arr[i].arr3=h[i];arr[i].arr4=r[i]+1;arr[i].arr5=t[i];
       }
   }
print pp[m+l];
int ss=0,jd=0;
for(int k=0;k<m+l;k++)
{
    int minimum=50;

     for(int i=0;i<l+m;i++)
     {
         if(minimum>arr[i].arr1&&arr[i].arr1!=-1)
            {
                 minimum=arr[i].arr1;
                 ss=i;
            }
      }
    pp[jd].arr1=arr[ss].arr1;pp[jd].arr2=arr[ss].arr2;pp[jd].arr3=arr[ss].arr3;pp[jd].arr4=arr[ss].arr4;pp[jd].arr5=arr[ss].arr5;
    arr[ss].arr1=-1;
    jd++;
    }


for(int i=0;i<m+l;i++)
   {
       if(pp[i].arr3==-1)
        {
            cout<<"Partition"<<pp[i].arr1<<"("<<pp[i].arr2<<"KB) = Empty\n";
        }
        else
        {
            cout<<"partition"<<pp[i].arr1<<"("<<pp[i].arr2<<"KB)=process"<<pp[i].arr4<<"("<<pp[i].arr5<<"KB)"<<"rest of partition"<<pp[i].arr1<<"=("<<pp[i].arr3<<"KB)"<<endl;
        }

   }
}

void worstfit(int *a,int *b,int m,int n)
{
    int r[m],t[n],s[m+n],d[m],h[n],f[m+n],w[m+n],e[m+n],u[m];
   for(int i=0;i<m;i++)
   {
       d[i]=a[i];
   }
   for(int i=0;i<m+n;i++)
   {
       f[i]=-1;
       s[i]=-1;
       w[i]=-1;
   }
   for(int i=0;i<n;i++)
   {  int y=0;
       for(int j=0;j<m;j++)
       {
           for(int p=0;p<m;p++)
           {
               e[p]=d[p]-b[i];
           }

           int maximum=e[0];
           for(int v=1;v<m;v++)
           {
               if(maximum<e[v])
               {
                   maximum=e[v];
                   y=v;
               }
           }
       }
             t[i]=b[i];
             d[y]=d[y]-b[i];
             h[i]=d[y];
             s[i]=y;
             r[i]=i;
             f[i]=t[i];
       }

   int l=0;
   for(int i=0;i<m+n;i++)
   {
       for(int j=0;j<m+n;j++)
       {
             if(s[i]!=-1&&i!=j&&s[i]==s[j]&&w[j]!=s[i])
                     {
                         w[i]=s[i];
                         l++;
                     }
       }
   }

   int maxi;
   maxi=s[0];
   for(int i=1;i<m+l;i++)
   {
       if(maxi<s[i])
       {
           maxi=s[i];
       }
   }
   if(l!=0)
   {
   s[n]=maxi+1;
   for(int i=0;i<m+l;i++)
   {
       if(s[i]==-1)
        {
             s[i]=s[i-1]+1;
        }

   }
   }
   else
   {
       int target;int c=0;
       for(int i=0;i<m;i++)
       { target=i;bool boolen=false;
           for(int j=0;j<m;j++)
           {
               if(s[j]==target)
                 {
                     boolen=true;
                     break;
                 }
                 else
                   boolen=false;
           }
           if(boolen==false){u[c]=i;c++;}
       }
       int co=0;
       for(int i=0;i<m;i++)
       {
           if(s[i]==-1)
           {
               s[i]=u[co];
               co++;
           }
       }
   }
   struct print{
   int arr1,arr2,arr3,arr4,arr5;};
   print arr[m+l];
   for(int i=0;i<l+m;i++)
   {
       if(f[i]==-1)
       {
          arr[i].arr1=i;arr[i].arr2=a[s[i]];arr[i].arr3=-1;
       }
       else
       {
           arr[i].arr1=s[i]+1;arr[i].arr2=a[s[i]];arr[i].arr3=h[i];arr[i].arr4=r[i]+1;arr[i].arr5=t[i];
       }
   }
print pp[m+l];
int ss=0,jd=0;
for(int k=0;k<m+l;k++)
{
    int minimum=50;

     for(int i=0;i<l+m;i++)
     {
         if(minimum>arr[i].arr1&&arr[i].arr1!=-1)
            {
                 minimum=arr[i].arr1;
                 ss=i;
            }
      }
    pp[jd].arr1=arr[ss].arr1;pp[jd].arr2=arr[ss].arr2;pp[jd].arr3=arr[ss].arr3;pp[jd].arr4=arr[ss].arr4;pp[jd].arr5=arr[ss].arr5;
    arr[ss].arr1=-1;
    jd++;
    }


for(int i=0;i<m+l;i++)
   {
       if(pp[i].arr3==-1)
        {
            cout<<"Partition"<<pp[i].arr1<<"("<<pp[i].arr2<<"KB) = Empty\n";
        }
        else
        {
            cout<<"partition"<<pp[i].arr1<<"("<<pp[i].arr2<<"KB)=process"<<pp[i].arr4<<"("<<pp[i].arr5<<"KB)"<<"rest of partition"<<pp[i].arr1<<"=("<<pp[i].arr3<<"KB)"<<endl;
        }

   }
}
int main()
{
    int m;
    cout<<"enter the number of partitions\n";
    cin>>m;
    int z[m];
    cout<<"enter size of each partition\n";
    for(int i=0;i<m;i++)
    {
        cout<<"Partition"<<i+1<<" size:";
        cin>>z[i];
    }
    int n;
    cout<<"enter the number of processes\n";
    cin>>n;
    int x[n];
    cout<<"enter size of each process\n";

    for(int k=0;k<n;k++)
    {
        cout<<"Process"<<k+1<<" size:";
        cin>>x[k];
    }
    int c;
    cout<<"choose the policy that you want\n"<<"1)first fit\n"<<"2)worst fit\n"<<"3)best fit\n";
    cin>>c;
    switch(c)
    {
        case 1:firstfit(z,x,m,n);
        break;
        case 2:worstfit(z,x,m,n);
        break;
        case 3:bestfit(z,x,m,n);
        break;
    }





    return 0;
}
