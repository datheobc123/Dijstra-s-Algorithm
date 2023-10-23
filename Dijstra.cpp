// Cac Nguon Tham Khao Code va Ly Thuyet adjugate matrix 
// C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
// https://www.youtube.com/watch?v=a1Z1GmKzcPs&t=144s

#include<iostream>
using namespace std;
#define INF 999
int a[100][100], n;

int getMin(int KhoangCach[], bool marked[])
{
    int gt = 0 ; 
    int min = INT_MAX ; 
    for(int i=0;i < n ; i++){
        if(!marked[i] && KhoangCach[i]<min)
		{
            min = KhoangCach[i] ; 
            gt = i ; 
        }
    }
    return gt ; 
}

void xuat(int KhoangCach[] , int dinhke[] )
{
   for(int i =0 ;i < n ;i++)
   {
       int giatritamthoi = dinhke[i] ; 
       cout << "Ngan nhat di toi: " << i << endl;
       while(giatritamthoi!=-1)
           giatritamthoi = dinhke[giatritamthoi]; 
       cout<< "TongKhoangCachPhaiDi = " << KhoangCach[i] << endl; 
       cout<<endl; 
   } 
}


void dijkstra(int src )
{
    int dinhke[100], KhoangCach[100] ; 
    bool marked[100] = {0} ; 
    fill(KhoangCach, KhoangCach+n , INT_MAX ) ; 

    KhoangCach[src] = 0 ; 
    dinhke[src] = -1 ;
    
    for(int g = 0; g<=n ; g++)
	{
        int u = getMin( KhoangCach, marked )  ; 
        marked[u] = true ;
        for(int v =0 ; v< n ;v++)
		{
            if(!marked[v] && (KhoangCach[u]+ a[u][v]) <  KhoangCach[v] && a[u][v]!= INF)
            {
                dinhke[v] = u ; 
                KhoangCach[v] = KhoangCach[u] + a[u][v] ; 
            }
        }
    }
    
    xuat(KhoangCach , dinhke) ; 
    
}



int main()
{ 
    cout << "Nhap ma tran vuong co kich thuoc : " ; 
    cin >> n; 
    cout << "Nhap ma tran: " << endl; 
    for(int i = 0 ;i < n ; i++)
	{
        for(int j = 0 ; j< n ; j++)
		cin>>a[i][j]; 
    }
	cout << endl;
    int src; 
    cout<<"Chon Nguon : ";
	cin >> src;
	cout << endl;
    dijkstra (src) ; 
}

/*
 Ma tran:
n la 9 (9x9)
Nguon la A ( tuc la 0 )

0 4 999 999 8 999 999 999 999
4 0 8 999 11 999 999 999 999
999 8 0 7 999 999 999 999 2
999 999 7 0 999 999 14 9 999
8 11 999 999 0 1 999 999 7
999 999 999 999 1 0 2 999 6
999 999 4 14 999 999 0 10 999
999 999 999 9 999 999 10 0 999
999 999 2 999 7 6 999 999 0

*/ 
