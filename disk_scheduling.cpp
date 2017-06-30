#include<iostream>
#include<vector>
#include<algorithm>
#include<time.h>
using namespace std;
int min_pos(int arr[][2],int n)
{
    int mini,index;

    for(int j=1;j<=n;j++)
    {
        if(arr[j][1]==0)
        {
            mini=arr[j][0];
            index=j;
            break;
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(arr[i][1]==0 && mini>arr[i][0])
        {
            index=i;
            mini=arr[i][0];
        }
    }

    return index;
}
void sstf()
{


        int q[20],q1[20][2],seek=0,head,n;
        double avg_seek,time;

        cout<<"\t\t\t\tEnter no. of processes:";
        cin>>n;

        cout<<"\n\t\t\t\tEnter data in the queue array:\n";
        for(int i=1;i<=n;i++)
        {
          cout<<"\t\t\t\t";
          cin>>q[i];
        }

        cout<<"\t\t\t\tEnter position of head:";
        cin>>head;
        clock_t tstart=clock();
        for(int i=1;i<=n;i++)
        {
          q1[i][1]=0;
        }


        cout<<"\n\t\t\t\t--------------------------------------";
        cout<<"\n\t\t\t\tHead Position\t||\tDistance moved";
        cout<<"\n\t\t\t\t--------------------------------------";
        cout<<"\n\t\t\t\t"<<head<<"\t\t||\t\t"<<"0";
        for(int i=1;i<=n;i++)
        {

          for(int j=1;j<=n;j++)
           {

            q1[j][0]=(q[j]-head);

            if(q1[j][0]<0)
            {
                q1[j][0]=-1*q1[j][0];
            }

           }

          int pos=min_pos(q1,n);

          seek=seek+q1[pos][0];
          q1[pos][1]=1;

          head=q[pos];

          cout<<"\n\t\t\t\t--------------------------------------";
          cout<<"\n\t\t\t\t"<<head<<"\t\t||\t\t"<<q1[pos][0];
       }

       avg_seek=(double)seek/n ;
       time=(double)(clock()-tstart)/CLOCKS_PER_SEC;
       cout<<"\n\t\t\t\t--------------------------------------";
       cout<<"\n\t\t\t\tTotal Seek Time="<<seek;
       cout<<"\n\t\t\t\tAverage Seek Time="<<avg_seek;
       cout<<"\n\t\t\t\t"<<"Total Running Time:"<<time<<"s"<<endl<<endl;
}
void scan()
{
   int n,head,seek=0,index=0,pos;
   double avg_seek,time;
   vector<int> q;

   cout<<"\t\t\t\tEnter no. of elements in queue:";
   cin>>n;

   q.resize(n+1);

   cout<<"\n\t\t\t\tEnter value of initial head position:";
   cin>>head;
   q[0]=head;

   cout<<"\n\t\t\t\tEnter Elements:"<<endl;
   for(int i=1;i<=n;i++)
   {
       cout<<"\t\t\t\t";
       cin>>q[i];
   }

   clock_t tstart=clock();
   sort(q.begin(),q.end());

   for(int i=0;i<=n;i++)
   {
       if(q[i]==head)
       {
           index=i;
           pos=index;
           break;
       }
   }



   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\tHead Position\t||\tDistance moved";
   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\t"<<head<<"\t\t||\t\t"<<"0";
   for(int i=index-1;i>=0;i--)
   {
        seek=seek+q[index]-q[i];
        cout<<"\n\t\t\t\t--------------------------------------";
        cout<<"\n\t\t\t\t"<<q[i]<<"\t\t||\t\t"<<q[index]-q[i];
        index=i;

   }

   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\t"<<"0"<<"\t\t||\t\t"<<q[0];
   seek=seek+q[0];
   q[index]=0;

   for(int i=pos+1;i<=n;i++)
   {
       seek=seek+q[i]-q[index];
       cout<<"\n\t\t\t\t--------------------------------------";

       cout<<"\n\t\t\t\t"<<q[i]<<"\t\t||\t\t"<<q[i]-q[index];
       index=i;

   }
   avg_seek=(double)seek/n;
   time=(double)(clock()-tstart)/CLOCKS_PER_SEC;
   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\tTotal Seek Time:"<<seek;
   cout<<"\n\t\t\t\tAverage Seek Time:"<<avg_seek;
   cout<<"\n\t\t\t\tTotal Running Time:"<<time<<"s"<<endl<<endl;

}
void c_scan()
{
   int n,head,tail,seek=0,index=0,pos;
   double avg_seek,time;
   vector<int> q;

   cout<<"\t\t\t\tEnter no. of elements in queue:";
   cin>>n;

   q.resize(n+2);

   cout<<"\n\t\t\t\tEnter value of initial head position:";
   cin>>head;
   q[0]=head;

   cout<<"\n\t\t\t\tEnter the position of tail track:";
   cin>>tail;

   q[n+1]=tail;

   cout<<"\n\t\t\t\tEnter Elements:"<<endl;
   for(int i=1;i<=n;i++)
   {
       cout<<"\t\t\t\t";
       cin>>q[i];
   }


   clock_t tstart=clock();
   sort(q.begin(),q.end());

   for(int i=0;i<=n;i++)
   {
       if(q[i]==head)
       {
           index=i;
           pos=index;
           break;
       }
   }



   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\tHead Position\t||\tDistance moved";
   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\t"<<head<<"\t\t||\t\t"<<"0";

   for(int i=index+1;i<=n+1;i++)
   {

           seek=seek+q[i]-q[index];
           cout<<"\n\t\t\t\t--------------------------------------";
           cout<<"\n\t\t\t\t"<<q[i]<<"\t\t||\t\t"<<q[i]-q[index];
           index=i;

   }

   q[index]=0;
   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\t"<<"0"<<"\t\t||\t\t"<<"0";
   for(int i=0;i<=pos-1;i++)
   {
       seek=seek+q[i]-q[index];
       cout<<"\n\t\t\t\t--------------------------------------";
       cout<<"\n\t\t\t\t"<<q[i]<<"\t\t||\t\t"<<q[i]-q[index];
       index=i;
   }
   avg_seek=(double)seek/n;

   time=(double)(clock()-tstart)/CLOCKS_PER_SEC;
   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\tTotal Seek Time:"<<seek;
   cout<<"\n\t\t\t\tAverage Seek Time:"<<avg_seek;
   cout<<"\n\t\t\t\tTotal Running Time:"<<time<<"s"<<endl<<endl;


}
void c_look()
{
   int n,head,seek=0,index=0,pos;
   double avg_seek,time;
   vector<int> q;

   cout<<"\t\t\t\tEnter no. of elements in queue:";
   cin>>n;

   q.resize(n+1);

   cout<<"\n\t\t\t\tEnter value of initial head position:";
   cin>>head;
   q[0]=head;

   cout<<"\n\t\t\t\tEnter Elements:\n";
   for(int i=1;i<=n;i++)
   {
       cout<<"\t\t\t\t";
       cin>>q[i];
   }


   clock_t tstart=clock();
   sort(q.begin(),q.end());

   for(int i=0;i<=n;i++)
   {
       if(q[i]==head)
       {
           pos=i;
           break;
       }
   }

   index=0;


   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\tHead Position\t||\tDistance moved";
   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\t"<<head<<"\t\t||\t\t"<<"0";

   index=pos;
   for(int i=pos+1;i<n+1;i++)
   {
       seek=seek+q[i]-q[index];
       cout<<"\n\t\t\t\t--------------------------------------";
       cout<<"\n\t\t\t\t"<<q[i]<<"\t\t||\t\t"<<q[i]-q[index];
       index=i;
   }

   cout<<"\n\t\t\t\t--------------------------------------";
   cout<<"\n\t\t\t\t"<<q[0]<<"\t\t||\t\t"<<"0";
   index=0;
   for(int i=1;i<pos;i++)
   {

           seek=seek+q[i]-q[index];
           cout<<"\n\t\t\t\t--------------------------------------";
           cout<<"\n\t\t\t\t"<<q[i]<<"\t\t||\t\t"<<q[i]-q[index];
           index=i;

   }

   avg_seek=(double)seek/n;
   time=(double)(clock()-tstart)/CLOCKS_PER_SEC;
   cout<<"\n\t\t\t\tTotal Seek Time="<<seek;
   cout<<"\n\t\t\t\tAverage Seek Time:"<<avg_seek;
   cout<<"\n\t\t\t\tTotal Running Time:"<<time<<"s"<<endl<<endl;

}

int main()
{
    int ch;

    while(1)
    {
      cout<<"\t\t\t\tDISK SCHEDULING ALGORITHMS";
      cout<<"\n\t\t\t-----------------------------------------"<<endl;
      cout<<"\t\t\t\t<1>Shortest Seek Time First(SSTF)";
      cout<<"\n\t\t\t\t<2>Elevator(SCAN)";
      cout<<"\n\t\t\t\t<3>Circular SCAN(C-SCAN)";
      cout<<"\n\t\t\t\t<4>C-LOOK";
      cout<<"\n\t\t\t\t<5>Exit";
      cout<<"\n\t\t\t-----------------------------------------"<<endl;

      cout<<"\t\t\t\tEnter Choice:";
      cin>>ch;

      switch(ch)
       {
        case 1:
            sstf();
            break;
        case 2:
            scan();
            break;
        case 3:
            c_scan();
            break;
        case 4:
            c_look();
            break;
        case 5:
            exit(0);
       }
    }


    return 0;
}
