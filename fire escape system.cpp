#include <bits/stdc++.h>
#include<conio.h>
#define INFINITY 999
using namespace std;
int l=64;
class fire_escape
{
 private:
 int graph[30][30];
 int graph2[30][30];
 int predecessor[30],dist[30];
 int predecessor2[30],dist2[30];
 bool mark[30];
 int Floor;
 int source,source2;
 int vertices,vertices2;
public:
 void input();
 void input2();
 void initialize();
 int search_min_node();
 int search_min_node2();
 void calculate_dist();
 void calculate_dist2();
 void output();
 void output2();
 void display_path(int);
 void display_path2(int);
};
void fire_escape::input()
{
cout<<"Enter the total number of Floors in the building:\t";
cin>>Floor;
cout<<endl;
cout<<"Enter the total number of rooms in the Floor:\t";
cin>>vertices;
cout<<endl;
while(Floor<=0)
{
while(vertices <= 0)
{
cout<<"Enter the total number of Floors in the building:\t";
cin>>Floor;
cout<<endl;
cout<<"Enter the total number of rooms in the Floor:\t";
cin>>vertices;
cout<<endl;
}
}
cout<<"Enter the adjacency matrix for the Floor\t"<<"\n========================================\n";
cout<<"To enter the location of fire type: "<<INFINITY<<endl;
for(int i=1;i<=vertices;i++)
{
 cout<<"\n";
cout<<"Enter the distance from room\t"<<i<<":\t"<<endl;
for(int j=1;j<=vertices;j++)
{
cin>>graph[i][j];
while(graph[i][j]<0) {
cout<<"Distance should be positive. Enter the distance again\n";
cin>>graph[i][j];
 }
}
}
cout<<"Enter your location(starting point):\t\n";
cin>>source;
while((source<0) && (source>vertices-1))
 {
cout<<"Your location should be between 0 and"<<vertices-1<<endl;
cout<<"Enter the location again\n";
cin>>source;
 }
}
void fire_escape::input2()
{
cout<<"Enter the total number of Floors in the building:\t";
cin>>Floor;
cout<<endl;
cout<<"Enter the total number of rooms in the Floor:\t";
cin>>vertices2;
cout<<endl;
while(Floor<=0)
{
while(vertices2 <= 0)
{
cout<<"Enter the total number of Floors in the building:\t";
cin>>Floor;
cout<<endl;
cout<<"Enter the total number of rooms in the Floor:\t";
cin>>vertices2;
cout<<endl;
}
}
cout<<"Enter the adjacency matrix for the Floor\t"<<"\n========================================\n";
cout<<"To enter the location of fire type: "<<INFINITY<<endl;
for(int i=1;i<=vertices2;i++)
{
 cout<<"\n";
cout<<"Enter the distance from room\t"<<i<<":\t"<<endl;
for(int j=1;j<=vertices2;j++)
{
cin>>graph2[i][j];
while(graph2[i][j]<0) {
cout<<"Distance should be positive. Enter the distance again\n";
cin>>graph2[i][j];
 }
}
}
cout<<"Enter your location(starting point):\t\n";
cin>>source2;
while((source2<0) && (source2>vertices2-1))
 {
cout<<"Your location should be between 0 and"<<vertices2-1<<endl;
cout<<"Enter the location again\n";
cin>>source2;
 }
}
void fire_escape::initialize()
{
for(int k=1;k<=Floor;k++)
{
for(int i=1;i<=vertices;i++)
 {
 mark[i] = false;
 dist[i] = INFINITY ;
 dist2[i] = INFINITY ;
 predecessor[i] = -1;
 predecessor2[i] = -1;
 }
}
dist[source]= 0;
 dist2[source]= 0;
 }
int fire_escape::search_min_node()
{
 int min_dist = INFINITY;
 int closestUnmarkedNode;
 for(int k=1;k<=Floor;k++)
{
 for(int i=1;i<=vertices;i++)
 {
 if((!mark[i]) && ( min_dist >= dist[i]))
 {
 min_dist = dist[i];
 closestUnmarkedNode = i;
}
}
}
 return closestUnmarkedNode;
}
int fire_escape::search_min_node2()
{
 int min_dist = INFINITY;
 int closestUnmarkedNode;
 for(int k=1;k<=Floor;k++)
{
 for(int i=1;i<=vertices;i++)
 {
 if((!mark[i]) && ( min_dist >= dist2[i]))
 {
 min_dist = dist2[i];
 closestUnmarkedNode = i;
}
}
}
 return closestUnmarkedNode;
} void fire_escape::calculate_dist()
{
initialize();
int minDistance = INFINITY;
int closestUnmarkedNode;
int count = 0;
while(count<vertices)
{
closestUnmarkedNode = search_min_node();
mark[closestUnmarkedNode] = true;
for(int k=1;k<=Floor;k++)
{
for(int i=1;i<=vertices;i++)
 {
 if((!mark[i]) && (graph[closestUnmarkedNode][i]>0) )
 {
 if(dist[closestUnmarkedNode]+graph[closestUnmarkedNode][i]<dist[i] )
 {
dist[i] = dist[closestUnmarkedNode]+graph[closestUnmarkedNode][i];
predecessor[i] = closestUnmarkedNode;
 }
}
 }
}
count++;
}
}
void fire_escape::calculate_dist2()
{
initialize();
int minDistance = INFINITY;
int closestUnmarkedNode;
int count = 0;
while(count<vertices2)
 {
closestUnmarkedNode = search_min_node2();
mark[closestUnmarkedNode] = true;
for(int k=1;k<=Floor;k++)
{
for(int i=1;i<=vertices2;i++)
 {
 if((!mark[i]) && (graph2[closestUnmarkedNode][i]>0) )
 {
 if(dist2[closestUnmarkedNode]+graph2[closestUnmarkedNode][i]<dist2[i] )
 {
dist2[i] = dist2[closestUnmarkedNode]+graph2[closestUnmarkedNode][i];
predecessor2[i] = closestUnmarkedNode;
 }
}
 }
}
count++;
}
}
void fire_escape::display_path(int node)
{
if(node == source)
{
cout<<(char)(node + l)<<"..";
}
else if(predecessor[node] == -1)
cout<<"No path from “source” to "<<(char)(node + 96)<<endl;
else
{
display_path(predecessor[node]);
cout<<(char) (node + l)<<"..";
 }
getch();
}
void fire_escape::display_path2(int node)
{
if(node == source2)
{
cout<<(char)(node + l)<<"..";
}
else if(predecessor2[node] == -1)
cout<<"No path from “source”to "<<(char)(node + 96)<<endl;
else
{
display_path2(predecessor2[node]);
cout<<(char) (node + l)<<"..";
 }
getch();
}
void fire_escape::output()
{
 cout<<endl;
cout<<"Shortest distance for Floor\t"<<1<<":\t"<<endl;
for(int i=1;i<=vertices;i++)
{
if(i == source)
{
cout<<(char)(source+l)<<".."<<source;
else
display_path(i);
cout<<"--->"<<"\tShortest Distance:\t"<<dist[i]<<endl;
}
getch();
}
void fire_escape::output2()
{
 cout<<endl;
cout<<"Shortest distance for Floor\t"<<2<<":\t"<<endl;
for(int i=1;i<=vertices2;i++)
{
if(i == source2)
{
cout<<(char)(source2+l)<<".."<<source;
}
else
display_path2(i);
cout<<"--->"<<"\tShortest Distance:\t"<<dist2[i]<<endl;
}
getch();
}
void drill()
{
 cout << "\n\t\t\t SITUATION\n ";
 cout<< "==============================================";
 cout << "\n\t\tPress 1 if it is "
 << "an Emergency\n";
 cout << "\t\tPress 2 if it is "
 << " a drill\n";
 cout << "\t\tPress 3 to exit";
}
void menu()
{
 cout << "\n\t\t Fire Escape System \n ";
 cout<< "=========================================";
 cout << "\n\t\tPress 1 to enter the "
 << "Path constraints for floor 1\n";
 cout << "\n\t\tPress 2 to enter the "
 << "Path constraints for floor 2\n";
 cout << "\n\t\tPress 3 to get the"
 << " shortest path for floor 1\n";
 cout << "\n\t\tPress 4 to get the"
 << " shortest path for floor 2\n";
 cout << "\n\t\tPress 5 to exit";
}
int main()
{
 string s1("Jaypee2022");
 string s2;
 int choice,ch,c;
fire_escape a;
do {
 cout << "\n";
 drill();
 cout<<"\n------------------------------------------------------";
 cout << "\n\n\t\tEnter your "
 << "choice:\t ";
 cin >> ch;
 cout<<"\n------------------------------------------------------";
 cout<<endl;
 switch (ch) {
 case 1:
 cout<<"Enter Device Password:\t";
 cin>>s2;
 if((s2.compare(s1)) == 0)
 {
 cout<<"\n\t\tEmergency services have been contacted"<<endl;
 cout <<"\n\t\tWelcome to Fire Escape System\t"<<endl;
 }
 else if((s2.compare(s1))!= 0)
 {
 cout <<"\n\tpassword didn't match , Please Enter again\n ";
 break;
 drill();
 }
 do{
 menu();
 cout<<"\n------------------------------------------------------";
 cout << "\n\n\t\tEnter your "
 << "choice:\t ";
 cin >> choice;
 cout<<"\n------------------------------------------------------";
 cout<<endl;
 switch (choice) {
 case 1:
 {
 a.input();
 a.calculate_dist();
 break;
 }
 case 2:
 {
 a.input2();
 a.calculate_dist2();
 break;
 }
 case 3:
 a.output();
 break;
 case 4:
 a.output2();
 break;
 case 5:
 exit(0);
 break;
 default:
 cout<<"Invalid Choice Please try again\n";
 }
}
while(choice!=5);
break;
 case 2:
 cout<<"\n\t\tProceed to the drill"<<endl;
 do
 {
 menu();
 cout<<"\n------------------------------------------------------";
 cout << "\n\n\t\tEnter your"<< "choice:\t ";
 cin >> choice;
 cout<<"\n------------------------------------------------------";
 cout<<endl;
 switch (choice) {
 case 1:
{
 a.input();
a.calculate_dist();
break;
 }
 case 2:
{
a.input2();
a.calculate_dist2();
break;
 }
 case 3:
a.output();
break;
 case 4:
a.output2();
break;
 case 5:
 exit(0);
 break;
 default:
 cout<<"Invalid Choice Please try again\n";
 }
 }
while(choice!=5);
 break;
 case 3:
 exit(0);
 break;
 default:
 cout<<"Invalid Choice Please try again\n";
 }
 }
while(choice!=3);
return 0;
}
