### 📚 DRILL

---


Below are 25 code fragments. Each is meant to be inserted into this “scaffolding”:

```c
#include "PPP.h"

int main()
try{
         <<your code here>>
         return 0;
}
catch (exception& e){
         cerr << "error: " << e.what() << '\n';
         return 1;
}
catch (...) {
         cerr << "Oops: unknown exception!\n";
         return 2;
}
```

Each has zero or more errors. Your task is to find and remove all errors in each program. When you have removed those bugs, the resulting program will compile, run, and write “Success!” Even if you think you have spotted an error, you still need to enter the (original, unimproved) program fragment and test it; you may have guessed wrong about what the error is, or there may be more errors in a fragment than you spotted. Also, one purpose of this drill is to give you a feel for how your compiler reacts to different kinds of errors. Do not enter the scaffolding 25 times – that’s a job for cut and paste or some similar “mechanical” technique. Do not fix problems by simply deleting a statement; repair them by changing, adding, or deleting a few characters.


__[1]__ ```cout << "Success!\n";```
__[2]__ ```cout << "Success!\n;```
__[3]__ ```cout << "Success" << !\n"```
__[4]__ ```cout << success << ’\n’;```
__[5]__ ```string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";```
__[6]__ ```vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";```
__[7]__ ```if (cond) cout << "Success!\n"; else cout << "Fail!\n";```
__[8]__ ```bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";```
__[9]__ ```string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";```
__[10]__ ```string s = "ape"; if (s=="fool") cout << "Success!\n";```
__[11]__ ```string s = "ape"; if (s=="fool") cout < "Success!\n";```
__[12]__ ```string s = "ape"; if (s+"fool") cout < "Success!\n";```
__[13]__ ```vector<char> v(5); for (int i = 0; 0<v.size(); ++i) ; cout << "Success!\n";```
__[14]__ ```vector<char> v(5); for (int i = 0; i<=v.size(); ++i) ; cout << "Success!\n";```
__[15]__ ```string s = "Success!\n"; for (int i = 0; i<6; ++i) cout << s[i];```
__[16]__ ```if (true) then cout << "Success!\n"; else cout << "Fail!\n";```
__[17]__ ```int x = 2000; char c = x; if (c==2000) cout << "Success!\n";```
__[18]__ ```string s = "Success!\n"; for (int i = 0; i<10; ++i) cout << s[i];```
__[19]__ ```vector v(5); for (int i = 0; i<=v.size(); ++i) ; cout << "Success!\n";```
__[20]__ ```int i = 0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";```
__[21]__ ```int x = 2; double d = 5/(x−2); if (d==2*x+0.5) cout << "Success!\n";```
__[22]__ ```string<char> s = "Success!\n"; for (int i = 0; i<=10; ++i) cout << s[i];```
__[23]__ ```int i = 0; while (i<10) ++j; if (j<i) cout << "Success!\n";```
__[24]__ ```int x = 4; double d = 5/(x−2); if (d=2*x+0.5) cout << "Success!\n";```
__[25]__ ```cin << "Success!\n";```