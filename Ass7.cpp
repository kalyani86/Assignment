#include <iostream>
using namespace std;
#include <queue>
#define Max 10
#define infinity 99999
class graph
{
    int adj[Max][Max];
    int ver;
    string *cities;
public:
    graph()
    {
        cout << "\nEnter number of cities:";
        cin >> ver;
        cities=new string[ver];
        for(int i=0;i<ver;i++)
        {
            cout<<"\nEnter the city name at"<<i<<":";
            cin>>cities[i];
        }
    }

    void create()
    {
        for (int i = 0; i < ver; i++)
        {
            for (int j = 0; j < ver; j++)
            {
               cout<<"\nEnter the cost from "<<cities[i]<<" to "<<cities[j]<<" : ";
               cin>>adj[i][j];
            }
        }
    }

    void display()
    {
        for(int i=0;i<ver;i++)
        {
           cout<<"  "<<cities[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < ver; i++)
        {
            cout<<cities[i]<<" ";
            for (int j = 0; j < ver; j++)
            {
                cout << adj[i][j] << "   ";
            }
            cout << endl;
        }
    }

    int prims(int spanning[Max][Max])
    {
        int distance[Max];
        int visited[Max];
        int from[Max];
        int cost[Max][Max];

        for (int i = 0; i < ver; i++)
        {
            for (int j = 0; j < ver; j++)
            {
                if (adj[i][j] == 0)
                {
                    cost[i][j] = infinity;
                }
                else
                {
                    cost[i][j] = adj[i][j];
                }
                spanning[i][j] = 0;
            }
        }

        distance[0] = 0;
        visited[0] = 1;

        for (int i = 1; i < ver; i++)
        {
            visited[i] = 0;
            from[i] = 0;
            distance[i] = cost[0][i];
        }
        int edge = ver - 1;
        int min_cost = 0;
        int v, u;
        while (edge > 0)
        {
            int min_distance = infinity;
            for (int i = 1; i < ver; i++)
            {
                if (visited[i] == 0 && distance[i] < min_distance)
                {
                    min_distance = distance[i];
                    v = i;
                }
            }

            u = from[v];
            spanning[u][v] = distance[v];
            spanning[v][u] = distance[v];

            visited[v] = 1;

            for (int i = 1; i < ver; i++)
            {
                if (!visited[i] && distance[i] > cost[i][v])
                {
                    distance[i] = cost[i][v];
                    from[i] = v;
                }
            }
            min_cost = min_cost + cost[u][v];
            edge--;
        }
        return min_cost;
    }

   
};
int main()
{

    graph g;
    g.create();
    g.display();

    int spanning[Max][Max];
       int cost=g.prims(spanning);
       cout<<cost;

 
    return 0;
}