#include<bits/stdc++.h>
 
#define FAST std::ios::sync_with_stdio(false);std::cin.tie(0);std::cout.tie(0);

#define LOOP(i,n) for(ull i=0;i<n;i++)


#define MOD 1000000007;
 
typedef unsigned long long ull;

class FiboCalculator {
    public:
        // Inner class for matrix exponentiation
        class Matrix{
            public:
                std::vector<std::vector<ull>> A;
            public:
                Matrix(){
                    A.resize(2,std::vector<ull>(2,0));
                }

                /*
                * Multiply the matrix instance by another matrix M
                * Time complexity: O(1), because size of the matrix=2
                * Space complexity: O(1), because size of the matrix=2
                */
                void multiply (Matrix* M) {
                    Matrix* product=new Matrix();
                    LOOP(i,2)LOOP(j,2)LOOP(k,2) {
                        product->A[i][j]=(product->A[i][j]+A[i][k]*M->A[k][j])%MOD;
                    }
                    this->A=product->A;
                }

                /*
                * Raise the matrix instance by k
                * Time complexity: O(log k),
                * Space complexity: O(1), because size of the matrix=2
                */
                void power(ull k) {
                    Matrix* res=new Matrix();
                    LOOP(i,2) res->A[i][i]=1;
                    while(k > 0) {
                        if(k&1) {
                            res->multiply(this);
                        }
                        this->multiply(this);
                        k>>=1;
                    }
                    this->A=res->A;
                }
        };

    public:
        ull f0;
        ull f1;
        std::unordered_map<ull,ull> memo;
        Matrix* mat;

    public:
        FiboCalculator(){
            f0=0;
            f1=1;
            mat=new Matrix();
        }

        /*
        * Time complexity: O(n)
        * Space complexity: O(1)
        */
        ull fibo_iter(ull n){
            ull f0=0,f1=1;
            ull f=1;
            for(ull i=1;i<n;++i){
                f=(f0+f1)%MOD;
                f0=f1%MOD;
                f1=f%MOD;
            }
            return f%MOD;
        }

        /*
        * Time complexity: O(2^n)
        * Space complexity: O(1)
        */
        ull fibo_rec(ull n){
            if (n<=1) return n;
            return (fibo_rec(n-2)+fibo_rec(n-1))%MOD;
        }

        /*
        * Time complexity: O(n)
        * Space complexity: O(n)
        */
        ull fibo_rec_memo(ull n){
            if (n<=1) return memo[n]=n;
            if(memo.find(n) != memo.end()) return memo[n];
            return memo[n]=(fibo_rec_memo(n-2)+fibo_rec_memo(n-1))%MOD;
        }
};




int main(){
    FAST;
    
    ull n;
    std::cin>>n;
    
    if(n==0) {
        std::cout<<0<<'\n';
        return 0;
    };

    FiboCalculator* F=new FiboCalculator();

    // std::cout<<F->fibo_iter(n)<<'\n';

    // std::cout<<F->fibo_rec(n)<<'\n';

    // std::cout<<F->fibo_rec_memo(n)<<'\n';

    F->mat->A[0][0]=1;
    F->mat->A[0][1]=1;
    F->mat->A[1][0]=1;
    F->mat->A[1][1]=0;

    F->mat->power(n);

    std::cout << F->mat->A[0][1] << '\n';

    return 0;
}