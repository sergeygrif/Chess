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
struct V{
int e;
long long n;
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
c={0,65536*(0.5+x)/GetSystemMetrics(0),65536*(0.5+y)/GetSystemMetrics(1),0,32775};
SendInput(1,&c,40);
}
vector<int> N(vector<vector<int>>& s){
int cp,c;
time_point<steady_clock> ts,tc,ta,tb,t;
vector<int> n;
tb=ta=tc=ts=steady_clock::now();
cp=S(2008,503);
while(1){
t=steady_clock::now();
c=S(2008,503);
n=S();
if(cp==-7368818&&c==-5513984)tc=t;
if((t-tc).count()>=60000000000)ta=t;
cp=c;
if(tb==ts&&n!=s[s.size()-1]&&n[0]==-16746281&&n[455]==-1)return n;
if(tc==t&&(ta==ts||(t-ta).count()>=10800000000000)){
Sleep(10000);
if(S(2008,503)==-5513984)return S();
}
if((t-tb).count()>=10000000000&&S(3406,2353)==-14935012){
I(894,201);
tb=t;
}
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
t->e={t->e[0],t->e[0],t->e[0]};
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
void F(vector<V>& e){
int l,r;
V s;
for(l=0,r=e.size()-1;r>=l;l++,r--){
s={-e[l].e,e[l].n};
e[l]={-e[r].e,e[r].n};
e[r]=s;
}
}
vector<V> E(vector<vector<V>>& v){
int i,j;
vector<V> e;
for(i=0;i<v.size();i++)for(j=0;j<v[i].size();j++)e.push_back(v[i][j]);
sort(e.begin(),e.end(),[](const V& a,const V& b){return a.e<b.e;});
for(i=1;i<e.size();)if(e[i].e>e[i-1].e)i++;else{
e[i-1].n+=e[i].n;
e.erase(e.begin()+i);
}
return e;
}
long long G(vector<V>& e){
int i;
long long g;
g=0;
for(i=0;i<e.size();i++)g+=e[i].n;
return g;
}
int E(int b,long long g,vector<V>& e){
int i;
long long l;
l=0;
for(i=0;l<=(g-b)/2;i++)l+=e[i].n;
return e[i-1].e;
}
vector<V> E(long long s,long long g,vector<V>& b){
int i;
long long n1,l1,l2,n2;
vector<V> e;
n1=s%g;
if(n1==0)l1=g;else l1=(g-1)/2-(n1-1)/2-((n1-1)%2&&g%2);
l2=0;
for(i=0;i<b.size();i++){
n2=b[i].n;
e.push_back({b[i].e,s/g*n2+max(min(l1+n1-1,l2+n2-1)-max(l1,l2)+1,0LL)});
l2+=n2;
}
return e;
}
vector<V> E(int b,T*& t){
int i,eb,e,ib;
long long s,g,gb;
vector<vector<V>> v;
if(t->n.empty())return {{t->e[0],t->g}};
for(i=0;i<t->n.size();i++){
v.push_back(E(!b,t->n[i]));
F(v[i]);
}
if(b==0)return E(v);
s=0;
eb=INT_MIN;
for(i=0;i<v.size();i++){
g=G(v[i]);
e=E(1,g,v[i]);
s+=g;
if(e>eb){
ib=i;
gb=g;
eb=e;
}
}
return E(s,gb,v[ib]);
}
void R(vector<vector<int>>& s,T*& t,vector<T*>& h){
int i;
vector<V> e;
sort(t->n.begin(),t->n.end(),[](T* a,T* b){return a->e[0]<b->e[0]||a->e[0]==b->e[0]&&a->e[2]<b->e[2]||a->e[0]==b->e[0]&&a->e[2]==b->e[2]&&a->e[1]<b->e[1];});
t->e[0]=-t->n[0]->e[0];
for(i=0;i<2;i++){
e=E(!i,t);
t->e.push_back(E(!i,G(e),e));
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
