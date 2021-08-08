#include<bits/stdc++.h>
using namespace std;
string Last(string p){
   int i,l=p.size();
   string k;
   for( i = 0 ; i < l ; i++ ){
       if(p[i] == ' ')
       k="";
       else
       k+=p[i];
   }
return k;
}
class LIST{
   list<string> List;
   public :
   void push(string name){
       (this->List).push_back(name);
   }
   int Size(){
       return (this->List).size();
   }
   void print(){
       list <string> :: iterator it;
           for(it = (this->List).begin(); it != (this->List).end(); ++it)
           cout <<*it<<" ";
   }  
   bool check(string name){
       list <string> :: iterator it;
           for(it = (this->List).begin(); it != (this->List).end(); ++it)
           if(name == *it)return true;
       return false;
   }
};
class ArrayListClass{
   LIST arr[27];
   public :
   ArrayListClass(){
       ifstream fin;
       fin.open("Names.txt");
       if(!fin){
           printf("Error in file opening\n");
       }else{
       printf("File is ready to read\n");
       while(fin){
           string name;
           getline(fin,name);
           if(name.size() > 0){
           //cout<<name<<endl;
           string s=Last(name);
           int n = (int)s[0];
           (this->arr[n-'A'+1]).push(name);
           }
       }
       fin.close();
           }
   }
   void printAll(){
       for( int i =1 ; i < 27 ; i++ ){
           printf("Names at index %d : ",i);
           (this->arr[i]).print();
           cout<<endl;
       }
   }
   void print(int n){
           printf("Names with %c : ",n+'A'-1);
           (this->arr[n]).print();
           cout<<endl;

   }
   bool check(string name,string s){
       int n = (int)s[0];
       return (this->arr[n-'A'+1]).check(name);  
   }
};
int main(){
   ofstream fout;
   fout.open("Names.txt");
   string s="";
   int i,j,m;
   if(!fout){
       printf("Error in creating file\n");
   }else{
   for( i = 0 ; i < 260 ; i++ ){
       s += 'A' + (i/10);
       for( m =1 ; m < 10 ; m++ ){
           j = rand()%26;
           s += 'A'+j;
       }
       fout<<s<<"\n";
       s="";
   }
   }
   printf("File is created\n");
   fout.close();
   ArrayListClass obj;
   printf("Enter name to search\n");
   getline(cin,s);
  
   if(obj.check(s,Last(s))){
       printf("Present\n");
   }
   else{
       printf("Not Present\n");
   }
   printf("Enter character to print name with that character\n");
   getline(cin,s);
   s=Last(s);
   obj.print(s[0]-'A'+1);
   obj.printAll();
   return 0;
}