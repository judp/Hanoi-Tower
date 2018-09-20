#include<stdio.h>
#include<vector>
using namespace std;

void HanoiTower(int n);
void recursion(int n,vector<int>& q,vector<int>& s,vector<int>& d);
void print(void);
void printc(int n,char c);

vector<int> s[3];
int n;

int main()
{
    printf("Please enter the number of towers.\nEnter any character to quit.\n");
    while(scanf("%d",&n)==1)
    {
        s[0].clear();
        s[1].clear();
        s[2].clear();
        printc(20,'*');
        HanoiTower(n);
    }
    return 0;
}

void HanoiTower(int n)
{
    for(int i=n;i>0;i--)
        s[0].push_back(i);

    recursion(n,s[0],s[1],s[2]);
}

void recursion(int n,vector<int>& q,vector<int>& s,vector<int>& d)
{
    int i=n;
    while(i)
    {
       recursion(--i,q,d,s);
       d.push_back(q.back());
       q.pop_back();
       if(i>0)
       {
           recursion(--i,s,d,q);
           d.push_back(s.back());
           s.pop_back();
       }
    }
    print();
}

void print(void)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<3;j++)
        {
            if((int)s[j].size()>i)
                printf("%d\t",s[j][i]);
            else
            {
                printf("  \t");
            }
        }
        putchar('\n');
    }
    printc(20,'*');
}
void printc(int n,char c)
{
    for(int i=0;i<n;i++)
        putchar(c);
    putchar('\n');
}




