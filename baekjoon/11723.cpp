#include <iostream>
using namespace std;
#define FOR(i,n) for(auto i=0; i<(n); ++i)
int M;
class Solution
{
    public:
        Solution() : S{0} {}

        void add(int x){ S |= (1<<x); }
        void remove(int x) { S &= ~(1<<x); }
        int check(int x){
            return (S & (1<<x))!=0;
        }
        void toggle(int x){
            S ^= (1<<x);
        }
        void all(void){
            S = (1<<20)-1;
        }
        void empty(void){
            S = 0;
        }
    private:
        unsigned S;
};

class UI
{
    public:
        UI(Solution& s) : solution{s} {}
        void run(int m){
            FOR(i, m){
                int x;
                string op;
                cin >> op;
                if(op=="add"){
                    cin >> x;
                    solution.add(x);
                } 
                else if(op=="remove"){
                    cin >> x;
                    solution.remove(x);
                }
                else if(op=="check"){
                    cin >> x;
                    cout << solution.check(x) << '\n';
                }
                else if(op=="toggle"){
                    cin >> x;
                    solution.toggle(x);
                }
                else if(op=="all"){
                    solution.all();
                }
                else if(op=="empty"){
                    solution.empty();
                }
                else
                    ;
            }
        }
    private:
        Solution& solution;
};
int main(void){
    cin >> M;
    Solution solution;
    UI ui(solution);
    ui.run(M);
}
