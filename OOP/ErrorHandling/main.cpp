#include <iostream>
#include <RepeatedIn.h>
#include <IndexError.h>
#include <DblArr.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;

void tst(int n)throw(IndexError){
    RepeatedIn ccin;
    DblArr x(n);
    int N;
    for(int i=0;i<n;i++)
    {
        x[i]=5.*rand()/RAND_MAX;
    }

    cout<<x<<endl;
    for(int i=0;i<5;i++){
        try{
            cout<<"index:";ccin>>N;
            cout<<"x["<<N<<"]="<<x[N]<<endl;
        }
        catch ( IndexError &e ){
            throw e;
       }catch(...){
            cerr<<"exception in tst() at line "<<__LINE__<<endl;
            throw;
        }
    }
}

int main( )
{
    int b;
    unsigned u;
    bool res = false;

    RepeatedIn ccin;
    do{
       try {
          cout<<"Enter unsigned:";
          ccin>>u;
          cout<<"Accepted: "<<u<<endl;
          b=__LINE__;
          tst(u);
       }
       catch ( IndexError &e ){
         e.rep(cerr);
          cerr<<"Exception in main() at line "<<b<<
                " invoking tst("<<u<<")." <<endl;
          cerr << e.what( ) << " by "<< typeid( e ).name( ) << endl;
          res=true;
       }
       cout<<endl;
       if(res){res=!res;cout<<"Resumption:\n";}
    }while(1);
    return 0;
}
