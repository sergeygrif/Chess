#include<chrono>
#include<vector>
#include<algorithm>
#include<iostream>
#include<windows.h>
using namespace std;
using namespace chrono;
int E(char c){return c=='-'||isdigit(c);}
void D(vector<string>& p,vector<vector<string>>& m,vector<vector<vector<int>>>& e){
int i,j;
string d,t;

i=-1;
while(i!=d.size()){
p.push_back({});
for(i++;d[i]!='_';i++)p[p.size()-1]+=d[i];
m.push_back({});
while(m[m.size()-1].empty()||d[i]==','){
m[m.size()-1].push_back({});
for(i++;d[i]!=','&&d[i]!='_';i++)m[m.size()-1][m[m.size()-1].size()-1]+=d[i];
}
e.push_back({});
while(i<d.size()&&d[i]!='|'){
e[e.size()-1].push_back({});
for(j=0;j<3;j++){
for(i++;i<d.size()&&E(d[i]);i++)t+=d[i];
e[e.size()-1][e[e.size()-1].size()-1].push_back(stoi(t));
t={};
}
}
}
}
void O(){
SetConsoleOutputCP(1251);
cout<<"Базовые принципы:"<<endl;
cout<<"1. Наиболее быстрое усиление"<<endl;
cout<<"2. Ходы, без которых не обойтись"<<endl;
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"Счет:"<<endl;
cout<<"1. Прибавление ходов"<<endl;
cout<<"2. Оценка позиции, устраивает нас или нет"<<endl;
cout<<"3. Если есть переход к предыдущей позиции неустраивающей стороны -> перемещение, иначе -> конец"<<endl;
cout<<"4. Если есть альтернативный ход -> пункт 1, иначе -> пункт 3"<<endl;
cout<<"-----------------------------------------------------------------------------------------------"<<endl;
cout<<"Дебют:"<<endl;
cout<<"1. Ходы от 100 партий и лучший по движку"<<endl;
cout<<"2. Stockfish "<<endl;
cout<<"3. Глубина 40"<<endl;
cout<<"4. Оценка=(Stockfish - Stockfish,Adaptive - 2300,2300 - Adaptive)"<<endl;
}
vector<int> S(int x1,int x2,int y1,int y2){
int w,h;
vector<int> s;
HDC d,m;
HBITMAP b;
BITMAPINFO p;
w=x2-x1+1;
h=y2-y1+1;
s.resize(w*h);
d=GetDC(0);
m=CreateCompatibleDC(d);
b=CreateCompatibleBitmap(d,w,h);
p={40,w,-h,1,32};
SelectObject(m,b);
BitBlt(m,0,0,w,h,d,x1,y1,13369376);
GetDIBits(d,b,0,h,s.data(),&p,0);
DeleteObject(b);
DeleteObject(m);
DeleteObject(d);
return s;
}
vector<int> S(){
vector<int> s;
DEVMODE m;
EnumDisplaySettings(0,-1,&m);
s=S(0,m.dmPelsWidth/2-1,0,m.dmPelsHeight-1);
s.push_back(m.dmPelsHeight);
return s;
}
vector<double> A(){
int w,h;
POINT a;
w=GetSystemMetrics(0);
h=GetSystemMetrics(1);
GetCursorPos(&a);
if(a.x<w/2)return {(0.5+a.x)/w,(0.5+a.y)/h};
return {};
}
void I(time_point<steady_clock>& t,vector<int>& s,vector<double>& a){
t=steady_clock::now();
s=S();
a=A();
}
int S(double y,vector<int>& s){return s[(s.size()-1)/s[s.size()-1]*int(y*s[s.size()-1])-1];}
void W(){
time_point<steady_clock> t1,t2;
vector<int> s,s1,s2;
vector<double> a1,a2;
s=S();
while(S()==s);
I(t1,s1,a1);
while(1){
I(t2,s2,a2);
if(s2==s1&&a2==a1)if((t2-t1).count()<1000000000||S(0.375,s2)==S(0.25,s2))continue;else return;
t1=t2;
s1=s2;
a1=a2;
}
}
void K(char b){
vector<INPUT> c;
c={{1,toupper(b)},{1,toupper(b),2}};
SendInput(2,c.data(),40);
}
string C(char b){
int c;
void* h;
time_point<steady_clock> t;
c=IsClipboardFormatAvailable(1);
while(1){
K(b);
t=steady_clock::now();
while((steady_clock::now()-t).count()<1000000000)if(IsClipboardFormatAvailable(1)!=c)while(1){
OpenClipboard(0);
h=GetClipboardData(1);
CloseClipboard();
if(h)return (char*)GlobalLock(h);
}
}
}
char F(char c){
if(isupper(c))return tolower(c);
return toupper(c);
}
string P(string& c){
int i,j;
string p,t;
if(find(c.begin(),c.end(),'w')<c.end())p.insert(p.begin(),c.begin(),find(c.begin(),c.end(),'0')-1);else{
i=-1;
for(j=0;j<8;j++){
if(j)p='/'+p;
for(i++;c[i]>='1';i++)t+=F(c[i]);
p=t+p;
t={};
}
p+=" w ";
for(i+=3;c[i]!=' ';i++)t+=F(c[i]);
sort(t.begin(),t.end());
p+=t+' ';
for(i++;c[i]!=' ';i++)if(c[i]!='3')p+=c[i];else p+='6';
}
return p;
}
string E(int s,vector<int>& e){return '('+to_string(s*e[0])+','+to_string(s*e[(3-s)/2])+','+to_string(s*e[(3+s)/2])+')';}
string F(string& m){
int i;
string f;
for(i=0;i<m.size();i++)if(m[i]<='0'||m[i]>='B')f+=m[i];else f+=105-m[i];
return f;
}
string M(int s,string& m){
if(s==1)return m;
return F(m);
}
int L(char c){
string a;
vector<int> l;
a=" (),-0123456789=BEKNQRabcdefghlv";
l={26,29,29,21,38,51,51,51,51,51,51,51,51,51,51,65,54,48,55,71,72,57,48,56,44,56,50,30,56,54,23,46};
return l[find(a.begin(),a.end(),c)-a.begin()];
}
int L(string& t){
int l,i;
l=0;
for(i=0;i<t.size();i++)l+=L(t[i]);
return l;
}
int L(vector<string>& t){
int l,i;
l=0;
for(i=0;i<t.size();i++)if(L(t[i])>l)l=L(t[i]);
return l;
}
string V(int c,vector<string>& m){
int l;
string v;
for(l=L(m)-L(m[c]);l>=26;l-=26)v+=' ';
return v;
}
string B(vector<string>& t){
int l;
string b;
for(l=L(t);l>=19;l-=38)b+='-';
return b;
}
void C(string& c){
void* h;
h=GlobalAlloc(0,c.size()+1);
memcpy(h,c.data(),c.size());
while(OpenClipboard(0)==0);
EmptyClipboard();
SetClipboardData(1,h);
CloseClipboard();
}
void C(vector<string>& t){
int i;
string c;
for(i=0;i<t.size();i++)c+='\n'+t[i];
c+="\n\n";
C(c);
}
void K(char b1,char b2){
vector<INPUT> c;
c={{1,b1},{1,toupper(b2)},{1,toupper(b2),2},{1,b1,2}};
SendInput(4,c.data(),40);
}
void T(){
K('d');
K('t');
K(17,'v');
K(9);
K(9);
K(13);
}
int main(){
int i,s,j;
string c,l;
vector<string> p,t;
vector<vector<string>> m;
vector<vector<vector<int>>> e;
D(p,m,e);
O();
while(1){
W();
c=C('p');
if(c==l)continue;
l=c;
i=lower_bound(p.begin(),p.end(),P(c))-p.begin();
if(i==p.size()||p[i]!=P(c))K('d');else{
if(find(c.begin(),c.end(),'w')<c.end())s=1;else s=-1;
t={"Eval="+E(s,e[i][0])};
if(e[i].size()==1)t.push_back(M(s,m[i][0]));else for(j=0;j<m[i].size();j++)t.push_back(M(s,m[i][j])+V(j,m[i])+'='+E(s,e[i][1+j]));
t.insert(t.begin()+1,B(t));
C(t);
T();
}
}
}
