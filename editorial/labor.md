# TOI11 Labor Editorial  
By : JO

สมมติ example case 1 ที่ M = 2, N = 5, t = [7, 12]
คือมีคนสองคน ใช้เวลา 7 และ 12 นาทีในการขนของ 1 ชิ้้นตามลำดับ

สมมติว่าเราให้เวลา 15 นาที และเนื่องจากคนแรกใช้เวลา 7 นาทีในการขนของ 1 ชิ้นดังนั้นคนแรกจะขนของได้ทั้งหมด $\lfloor\frac{15}{7}\rfloor = 2$ ชิ้น และคนที่สองจะขนได้ $\lfloor \frac{15}{12} \rfloor= 1$ ชิ้น


ทำให้เราเห็นว่าหากเราให้เวลา $T$ นาที คนแรกจะขนของได้
$\lfloor \frac{T}{t_{1}} \rfloor$ ชิ้น คนที่สองก้จะขนของได้ $\lfloor \frac{T}{t_{2}} \rfloor$ ชิ้นนั่นเอง

```cpp
long long countCrate(long long T) {
    long long movedBox = 0;
    for (int i = 1; i <= M; i++) {
        movedBox += t[i];
    }
    return movedBox;
}
```


หากเราทำการ binary search บนคำตอบ (เวลาที่น้อยที่สุดที่ทำให้จำนวนของที่ขนได้มากกว่าเท่ากับ N)
observation 1 : หากเราให้เวลา T นาทีในการขนของแล้วจำนวนของที่เราขนได้มันมากกว่าหรือเท่ากับจำนวนที่เราต้องการ(ค่า N) แสดงว่าเราไม่จำเป็นต้องสนใจเวลาที่มากกว่า T
observation 2 : แต่หากเราให้เวลา T นาทีแต่จำนวนของที่เราขนได้มันน้อยกว่าค่า N แสดงว่าเราไม่จำเป็นต้องสนใจเวลาที่น้อยกว่า T 
จาก 2 observation นี้ทำให้เราเห็นว่าเราสามารถทำ binary search กับข้อนี้ได้


คำถามต่อมาคือช่วงของคำตอบที่เป็นไปได้คือช่วงไหนบ้าง (ค่า l, r) ซึ่งเราจะ bound ไปที่ worst case กล่าวคือมีคนน้อยที่สุด (1 คน) โดยที่คนคนนี้ขนของช้ามาก (ใช้เวลา t1 = $10^6$ นาทีในการขนของ 1 ชิ้น)แต่มีจำนวนของมากที่สุด ($10^{12}$ ชิ้น) จะได้ว่ามีของ $10^{12}$ ชิ้นและใช้เวลา $10^6$ นาทีในการขนของหนึ่งชิ้น ทำให้ รับประกันได้ว่าจะใช้เวลามากที่สุดไม่เกิน $10^{18}$ นาทีนั่นเอง และใช้เวลาที่สุดไม่น้อยกว่า $1$ นาทีนั่นเอง


```cpp
#include <bits/stdc++.h>
using namespace std;

const int MXN = 1e6+10;
using ll = long long;

int M, t[MXN];
long long N;


long long countCrate(long long T) {
    long long movedBox = 0;
    for (int i = 1; i <= M; i++) {
        movedBox += T/t[i];
    }
    return movedBox;
}


bool chk(long long givenTime) {
    return (countCrate(givenTime) >= N);
}


int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> M >> N;
    for(int i = 1; i <= M; i++){
        cin >> t[i];
    }    

    ll l = 1, r = 1e18, ans = -1;
    while(l <= r){
        ll mid = (l+r)>>1, tmp = 0;
        if (chk(mid)) {
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << ans << "\n";
    return 0;   
}
```
