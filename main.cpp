/*
  Author: Wade Owojori
  Date: 6/8/2023
  Purpose: This program is a graph made with nodes and edges which are in adjacency matrix and are printed out in an adjacency matrix
  Websites that helped me:
  1. https://www.tutorialspoint.com/cplusplus-program-to-implement-adjacency-matrix
  2. https://www.programiz.com/dsa/graph-adjacency-matrix
  Note: I didn't do the Dijkstra's algorithm
*/
#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void addEdge(int table[][20], vector<char*> vert, char *v1, char *v2, int weight);
void removeEdge(int table[][20], vector<char*> vert, char *v1, char *v2);
void print(int table[][20], vector<char*> vert);
vector<char*> removeVert(vector<char*> vert, char *vertex);

int main(){

  int graph[20][20]; //maximum amount will be 20
  vector<char*> vertices;
  char* vertex = new char[1];
  char* userInput = new char[20];
  int weight =0;

  //I have to initialize the matrix to zero
  for(int i=0; i<20; i++){
    for(int j=0; j<20; j++){
      graph[i][j] = 0;
    }
  }
  
  
  do{
    cout<<endl;
    cout<<"Commands for Graph Creator"<<endl;
  cout<<endl;
  cout<<"type 'add vertex' to add a vertex"<<endl;
  cout<<endl;
  cout<<"type 'remove vertex' to remove a vertex"<<endl;
  cout<<endl;
  cout<<"type 'add edge' to add an edge"<<endl;
  cout<<endl;
  cout<<"type 'remove edge' to remove a vertex"<<endl;
  cout<<endl;
  cout<<"type 'print' to print the adjaceny table"<<endl;
  cout<<endl;
  cout<<"type 'quit' to quit the program"<<endl;

  cout<<endl;
  cout<<"What do you want to do?: "<<endl;
  cin.get(userInput, 20);
  cin.get();
    if(strcmp(userInput, "add vertex")==0){
      cout<<"vertex label: "<<endl;
      cin>>vertex;
      cin.get();
      vertices.push_back(vertex);//storing the vertex
      vertex= new char[1];
      cout<<"Done!"<<endl;
    }
    else if(strcmp(userInput, "remove vertex")==0){
      cout<<"enter label of vertex that will be deleted: "<<endl;
      cin>>vertex;
      cin.get();
      vertices = removeVert(vertices, vertex);
      vertex =new char[1];//need to reset the vertex 
    }
    else if(strcmp(userInput, "add edge")==0){//get all the information needed for the edge then call the add edge function.
      char *v1 =new char[1];
      char *v2 =new char[1];
      cout<<"First vertex label: "<<endl;
      cin>>v1;
      cin.get();
      cout<<"Second vertex label: "<<endl;
      cin>>v2;
      cin.get();
      cout<<"Weight of edge: "<<endl;
      cin>>weight;
      cin.get();
      addEdge(graph, vertices, v1, v2, weight);

    }
    else if(strcmp(userInput, "remove edge")==0){//similar to add but calling delete function instead
      char *v1 =new char[1];
      char *v2 =new char[1];
      cout<<"First vertex label: "<<endl;
      cin>>v1;
      cin.get();
      cout<<"Second vertex label: "<<endl;
      cin>>v2;
      cin.get();
      cout<<"Weight of edge: "<<endl;
      cin>>weight;
      cin.get();
      removeEdge(graph, vertices, v1, v2);
    }
    else if(strcmp(userInput, "print")==0){//run print function
      print(graph, vertices);
    }
    else if(strcmp(userInput, "quit")==0){
      cout<<endl;
      //program is over
    }
    else{
      cout<<"Type a vaild input please"<<endl;
    }

  }while(strcmp(userInput, "quit")!=0);


    return 0;
}

void addEdge(int table[][20], vector<char*> vert, char *v1, char *v2, int weight){
  int row = 0;
  int column = 0;
  int count = 0;

  vector<char*>::iterator it;//for cycling through the vector
  for(it = vert.begin(); it<vert.end(); it++){
    if(strcmp(*it, v1)==0){
      column= count;
    }
    if(strcmp(*it, v1)==0){
      row = count;
    }
    count++;
  }
  table[row][column]=weight;
}

void removeEdge(int table[][20], vector<char*> vert, char *v1, char *v2){//removing the edge
  int row = 0;
  int column = 0;
  int count = 0;

  vector<char*>::iterator it;//for cycling through the vector
  for(it = vert.begin(); it<vert.end(); it++){
    if(strcmp(*it, v1)==0){
      column= count;
    }
    if(strcmp(*it, v1)==0){
      row = count;
    }
    count++;
  }
  table[row][column]=0;
}

void print(int table[][20], vector<char*> vert){//this website helped: https://www.geeksforgeeks.org/graph-representations-using-set-hash/
  for(int i=0;i<vert.size();i++){
    cout<<"    "<<vert.at(i);
  }
  for(int r=0;r<vert.size();r++){
    cout<<vert.at(r);
    for(int c=0; c<vert.size();c++){
      cout<<"    "<<table[r][c];
    }
  }
}

vector<char*> removeVert(vector<char*> vert, char *vertex){
  vector<char*>::iterator it;//for cycling through the vector
  for(it = vert.begin(); it<vert.end(); it++){
    if(strcmp(*it, vertex)==0){
      vert.erase(it);//when you find the vertex in the vertices, delete it.
      cout<<"Vertex deleted"<<endl;
      break;//leaving the loop because i've found the vertex and have deleted it
    }
    
  }
  return vert;//returning the list of vertex's
}
