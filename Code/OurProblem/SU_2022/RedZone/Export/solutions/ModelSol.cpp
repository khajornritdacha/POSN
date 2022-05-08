#include <bits/stdc++.h>
#define DEBUG 1
#define st first
#define nd second
#define ll long long
#define mp make_pair
#define pi pair<int,int>
using namespace std;
typedef double db;
const int SZ=1e5+3;
const int MX=1e9+7;
const int MOD=1e9+7;

int house[SZ],val[SZ]; // ประกาศ array ที่จะนำมาใช้

struct Sweep_Line { // สร้าง struct เพื่อเก็บข้อมูล 3 อย่างคือ ตำแหน่ง, ความเสียหาย, เลขลำดับของระเบิด
    int pos,dam,id;
    bool operator<(const Sweep_Line &sox) const {
        return pos>sox.pos; // Sorting
    }
};
vector <Sweep_Line> line; // สร้าง vector ไว้เก็บข้อมูลและทำ sweep line

void process(void) {
    int N,M,L,D;
    cin >> N >> M >> L >> D; // รับค่า
    for(int i=1;i<=N;i++) cin >> house[i];
    for(int i=1;i<=M;i++) {
        int bomb;
        cin >> bomb; // bomb คือบ้านที่จะถูกระเบิดลูกที่ i ยิงใส่
        int l=max(1,bomb-L); // ป้องกันกรณีณีที่ระยะเลยบ้านหลังซ้ายสุด
        int r=min(N,bomb+L); // ป้องกันกรณีณีที่ระยะเลยบ้านหลังขวาสุด
        line.push_back({l,-D,i}); // เก็บข้อมูลเข้า line
        line.push_back({r+1,D,i});
    }
    sort(line.begin(),line.end()); // เรียงข้อมูลใหม่ตาม algo ของ sweep line
    bool check_house=false; // ต้องการเช็คกรณีที่ตอบ -1 โดยสร้างตัวแปร check_house เพื่อตรวจสอบว่ามีบ้านหลงเหลือจากการยิงระเบิดทุกลูกไหม
    int sum=0; // เก็บค่าความเสียหายรวม ณ ตำแหน่งปัจจุบัน
    for(auto v:line) val[v.pos]+=v.dam; // นำค่าจาก sweep line ไปใส่ array เพื่อง่ายต่อการนำไปใช้
    for(int i=1;i<=N;i++) {
        sum+=val[i]; // เก็บค่าความเสียหายที่เกิดขึ้นไปเรื่อยๆ
        if(house[i]+sum>0) check_house=true; // ถ้าค่าความแข็งแรงของบ้านมากกว่าศูนย์ แปลว่าภารกิจไม่สำเร็จและต้องตอบ -1
    }
    if(check_house) { // ตรวจสอบเงื่อนไข
        cout << -1;
        return ;
    }
    int l=1,r=M+1; // กำหนดขอบเขตของระเบิด M ลูก
    while(l^r) { // Binary Search หาระเบิดลูกสุดท้ายที่ทำให้บ้านทุกหลังพัง
        int mid=(l+r)>>1,sum=0; // mid คือระเบิดลูกสุดท้าย
        bool all_done=true; // เริ่มต้นให้ all_done คือบ้านทุกหลังพังหมด เป็นจริงก่อน
        for(int i=1;i<=N+1;i++) val[i]=0; // initial ให้ค่าเริ่มต้นเป็น 0
        for(auto v:line) {
            if(v.id<=mid) {  // ถ้าเลขลำดับของลูกระเบิดที่ดูอยู่น้อยกว่าเลขลำดับของระเบิดลูกสุดท้าย (mid) 
                val[v.pos]+=v.dam; // ก็ให้เก็บค่าความเสียหายเข้าไป
            }
        }
        for(int i=1;i<=N;i++) {
            sum+=val[i]; // เก็บค่าความเสียหายที่เกิดขึ้นไปเรื่อยๆ (เหมือนตอนเช็ค -1)
            if(house[i]+sum>0) all_done=false;// ถ้าค่าความแข็งแรงของบ้านมากกว่าศูนย์ แปลว่ายังเหลือบ้านที่ยังไม่พัง all_done จึงเป็น false
        }
        if(all_done) r=mid; // ถ้ายิงถึงระเบิดลูกที่ mid แล้วทำให้บ้านทุกหลังพังหมด ก็ให้ลอง search mid ที่น้อยกว่าเดิม
        else l=mid+1; // ตรงกันข้าม ถ้ายังมีบ้านเหลือรอดก็ลองเพิ่ม mid ไปเพื่อเช็คต่อ
    }
    cout << l; // ตอบเลขลำดับระเบิดที่ได้มา
    return ;
}

int main() {
    cin.tie(nullptr)->ios::sync_with_stdio(false);
    int t(1);
    while(t--) process();
}