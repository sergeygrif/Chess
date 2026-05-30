#include<chrono>
#include<vector>
#include<algorithm>
#include<fstream>
#include<windows.h>
using namespace std;
using namespace chrono;
struct T{
int g;
string p,m,b,h;
vector<int> e;
T* r;
vector<T*> n;
};
void K(char b1,char b2){
vector<INPUT> c;
c={{1,b1},{1,toupper(b2)},{1,toupper(b2),2},{1,b1,2}};
SendInput(4,c.data(),40);
}
void K(char b){
vector<INPUT> c;
c={{1,toupper(b)},{1,toupper(b),2}};
SendInput(2,c.data(),40);
}
void Q(){
K('q');
K('4');
K('0');
K(13);
Sleep(1000);
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
vector<int> S(){return S(1946,2400,613,2202);}
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
string P(){
string c;
c=C('p');
return P(c);
}
string F(string& m){
int i;
string f;
for(i=0;i<m.size();i++)if(m[i]<='0'||m[i]>='B')f+=m[i];else f+=105-m[i];
return f;
}
string M(){
int i;
string c,m;
c=C('m');
for(i=c.size()-7;c[i]!=' ';i--)if(c[i]!='x'&&c[i]!='+')m=c[i]+m;
if(c[i-1]=='.')return F(m);
return m;
}
int G(int h,vector<vector<int>>& s){
int g,p,w,b,x,y;
vector<int> d;
d={145,77,112,111,126,110,144,93,157,141};
g=0;
p=1;
for(w=0;w<7;w++){
b=0;
for(x=0;x<15;x++)for(y=0;y<21;y++)b+=s[s.size()-1][6223+19565*h-16*w+x+455*y]!=-1;
if(b==0)continue;
g+=p*(find(d.begin(),d.end(),b)-d.begin());
p*=10;
}
return g;
}
int G(vector<vector<int>>& s){
int g,i;
if(G(0,s)==0)return 1;
if(G(0,s)>=100)return 100;
g=0;
for(i=0;i<37;i++)g+=G(i,s);
return g;
}
vector<T*>::iterator P(T*& t,vector<T*>& h){return lower_bound(h.begin(),h.end(),t,[](T* a,T* b){return a->p<b->p;});}
int S(int x,int y){return S(x,x,y,y)[0];}
void I(int x,int y){
INPUT c;
c={0,0,0,0,6};
SetCursorPos(x,y);
SendInput(1,&c,40);
}
vector<int> N(vector<vector<int>>& s){
int c;
time_point<steady_clock> t;
vector<int> n;
t=steady_clock::now();
while(1){
n=S();
if(n!=s[s.size()-1]&&n[0]==-16746281&&n[455]==-1)return n;
if((steady_clock::now()-t).count()<10000000000||S(3404,2359)==-1)continue;
c=S(2008,503);
I(894,201);
Sleep(10000);
if(S(2008,503)>c)return S();
}
}
void R(vector<vector<int>>& s,T*& t){
vector<int> n;
K('r');
K('c');
n=N(s);
s.pop_back();
t=t->r;
if(s[s.size()-1]==n)return;
s[s.size()-1]=n;
t->n={};
}
int H(vector<vector<int>>& s,T*& t,vector<T*>& h){
int i;
i=P(t,h)-h.begin();
if(i==h.size()||h[i]->p!=t->p)return 0;
t->b=h[i]->b;
t->g=h[i]->g;
t->e=h[i]->e;
t->n=h[i]->n;
R(s,t);
return 1;
}
int D(vector<vector<int>>& s,T*& t){
T* h;
for(h=t->r;h&&h->p!=t->p;h=h->r);
if(h==0)return 0;
t->e={0,0,0};
R(s,t);
return 1;
}
string B(string& c){
int i;
string b;
for(i=find(find(c.begin(),c.end(),'}'),c.end(),'{')-c.begin()-2;c[i]!=' ';i--)if(c[i]!='x'&&c[i]!='+')b=c[i]+b;
if(c[i-1]=='.')return b;
return F(b);
}
int E(char c){return c=='-'||isdigit(c);}
int E(string& c){
int i;
string e;
for(i=c.size()-11;c[i]!='{';i--)if(c[i]!='.')if(E(c[i]))e=c[i]+e;else e="20000";
for(i-=2;c[i]!=' ';i--);
if(c[i-1]=='.')return stoi(e);
return -stoi(e);
}
string H(string& c){
string h;
h.insert(h.begin(),find(c.begin(),c.end(),'}')+2,find(find(c.begin(),c.end(),'}'),c.end(),'{')-1);
return "[Event \"\"]\n"+h;
}
void A(T*& t){
string c;
K('a');
while(S(3396,587)!=-16777216);
K('f');
c=C('m');
t->b=B(c);
t->e.push_back(E(c));
t->h=H(c);
}
void H(T*& t,vector<T*>& h){h.insert(P(t,h),t);}
int L(vector<vector<int>>& s,T*& t,vector<T*>& h){
if(G(0,s)>=100)return 0;
A(t);
t->e.push_back(t->e[0]);
t->e.push_back(t->e[0]);
H(t,h);
K('u');
R(s,t);
return 1;
}
void N(vector<vector<int>>& s,T*& t){
s.push_back(N(s));
t->n.push_back(new T);
t->n[t->n.size()-1]->r=t;
t=t->n[t->n.size()-1];
}
int M(vector<vector<int>>& s,T*& t){
if(G(t->n.size(),s)<100)return 0;
I(779,254.6+17.2*t->n.size());
N(s,t);
return 1;
}
int B(T*& t){
int i;
for(i=0;i<t->n.size();i++)if(F(t->n[i]->m)==t->b)return 1;
return 0;
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
int B(vector<vector<int>>& s,T*& t){
if(t->b.empty())A(t);
if(B(t))return 0;
C(t->h);
K('h');
K('l');
N(s,t);
return 1;
}
void F(vector<int>& e){
int l,r,s;
for(l=0,r=e.size()-1;l<=r;l++,r--){
s=e[l];
e[l]=-e[r];
e[r]=-s;
}
}
int E(int n,vector<int>& e){return e[(e.size()-1+n)/2];}
vector<int> E(int n,T*& t){
int i,m,b;
vector<int> e;
vector<vector<int>> v;
if(t->n.empty())for(i=0;i<t->g;i++)e.push_back(t->e[0]);else{
for(i=0;i<t->n.size();i++){
v.push_back(E(!n,t->n[i]));
F(v[i]);
}
if(n==0){
m=INT_MIN;
for(i=0;i<t->n.size();i++)if(E(0,v[i])>m){
b=i;
m=E(0,v[i]);
}
e=v[b];
}
else{
for(i=0;i<t->n.size();i++)e.insert(e.end(),v[i].begin(),v[i].end());
sort(e.begin(),e.end());
}
}
return e;
}
void R(vector<vector<int>>& s,T*& t,vector<T*>& h){
int i;
vector<int> e;
sort(t->n.begin(),t->n.end(),[](T* a,T* b){return a->e[0]<b->e[0]||a->e[0]==b->e[0]&&a->e[2]<b->e[2]||a->e[0]==b->e[0]&&a->e[2]==b->e[2]&&a->e[1]<b->e[1];});
t->e[0]=-t->n[0]->e[0];
for(i=0;i<2;i++){
e=E(i,t);
t->e.push_back(E(i,e));
}
H(t,h);
K('u');
if(t->r)R(s,t);
}
void O(vector<T*>& h){
int i,j;
ofstream d;
d.open("d.txt");
d<<"d=\"";
for(i=0;i<h.size();i++){
if(i)d<<'|';
d<<h[i]->p<<'_';
for(j=0;j<h[i]->n.size();j++){
if(j)d<<',';
d<<F(h[i]->n[j]->m);
}
if(h[i]->n.empty())d<<h[i]->b;
d<<'_';
for(j=0;j<3;j++){
if(j)d<<',';
d<<h[i]->e[j];
}
for(j=0;j<h[i]->n.size();j++)d<<';'<<-h[i]->n[j]->e[0]<<','<<-h[i]->n[j]->e[2]<<','<<-h[i]->n[j]->e[1];
}
d<<"\";";
}
int main(){
vector<vector<int>> s;
T* t;
vector<T*> h;
ShowWindow(GetConsoleWindow(),0);
K(18,27);
Q();
s.push_back(S());
t=new T;
t->r=0;
while(t->e.size()<=1){
if(t->p.empty())t->p=P();
if(t->r&&t->m.empty())t->m=M();
t->g=G(s);
if(H(s,t,h)==0&&D(s,t)==0&&L(s,t,h)==0&&M(s,t)==0&&B(s,t)==0)R(s,t,h);
}
O(h);
}
