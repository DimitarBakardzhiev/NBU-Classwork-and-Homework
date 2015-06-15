#include "BigInteger.h"

BigInteger::BigInteger():n(0), val(NULL), pos(false){   
}

BigInteger::BigInteger(std::string s){
    n = s.length();
    pos = (s[0]=='-')?false:true;
    if(!pos) n--;
    val = new int[n];
    for (int i = 0; i < n; i++)
    {
		if(s[i]!='-' || s[i]!='+'){
			if(pos) val[i] = s[i]-'0';
			else val[i] = s[i+1]-'0';
		}
    }
}

BigInteger::BigInteger(const BigInteger & r){
    n = r.n;
    val = new int[n];
    pos = r.pos;
    for (int i = 0; i < n; i++)
    {
        val[i] = r.val[i];
    }
}

BigInteger::~BigInteger(){
    if(n!=0) delete [] val;
}

BigInteger& BigInteger::operator=(const BigInteger & r){
    if(this!=&r){
        if(n!=0) delete [] val;
        n = r.n;
        val = new int[n];
        pos = r.pos;
        for (int i = 0; i < n; i++)
        {
            val[i] = r.val[i];
        }
    }
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger & r) const{
    if(pos == r.pos){
        int * t =  reverse();
        int * k = r.reverse();
		
        int length = (n>r.n)? n:r.n;
        int add_val = 0, curr1, curr2;
        int * ans = new int[length+1];
        for (int i = 0; i < length; i++)
        {
            curr1 = (i<n)?t[i]:0;
			curr2 = (i<r.n)?k[i]:0;
            ans[i] = (curr1+curr2+add_val)%10;
            add_val = (curr1+curr2+add_val)/10;
        }
        if(add_val) ans[length] = add_val;
		else ans[length] = 0;
		BigInteger answer;
		answer.pos = pos;
		
		int cnt;
		if(add_val){
			cnt = length+1;
		}
		else cnt = length;
		answer.n = cnt;
		answer.val = new int[cnt];
		for(int i=cnt-1, j=0; i>=0; i--,j++){
			answer.val[j] = ans[i];
		}
		delete [] ans;
		return answer;
    }
    else{
		int sub_val=0;
		BigInteger max = abs_max(r)?*this:r;
		BigInteger min = !abs_max(r)?*this:r;
		
		int * t = max.reverse();
		int * k = min.reverse();
		int length = max.n, curr1, curr2;
		int * ans = new int[length];
		for(int i=0; i<length; i++){
			curr1 = (i<n)?t[i]:0;
			curr1 -= sub_val;
			curr2 = (i<r.n)?k[i]:0;
			if(curr1 < curr2){
				 ans[i] = curr1+10-curr2;
				 sub_val = 1;
			}
			else{
				ans[i] = curr1-curr2;
				sub_val = 0;
			}
		}

		BigInteger answer;
		answer.pos = max.pos;
		int cnt=0;
		bool flag = true;
		for(int i=length-1; i>=0; i--){
			if(!(ans[i] == 0 && flag)){
				cnt++;
				flag = false;
			}
		}
		answer.n = cnt;
		answer.val = new int[cnt];
		for(int i=cnt-1, j=0; i>=0; i--,j++){
			answer.val[j] = ans[i];
		}
		delete [] ans;
		return answer;
	}

    return BigInteger(0);
}

BigInteger BigInteger::operator-(const BigInteger & r) const{
    if(pos == r.pos){
        int sub_val=0;
		BigInteger max = abs_max(r)?*this:r;
		BigInteger min = !abs_max(r)?*this:r;
		
		int * t = max.reverse();
		int * k = min.reverse();
		int length = max.n, curr1, curr2;
		int * ans = new int[length];
		for(int i=0; i<length; i++){
			curr1 = (i<n)?t[i]:0;
			curr1 -= sub_val;
			curr2 = (i<r.n)?k[i]:0;
			if(curr1 < curr2){
				 ans[i] = curr1+10-curr2;
				 sub_val = 1;
			}
			else{
				ans[i] = curr1-curr2;
				sub_val = 0;
			}
		}

		BigInteger answer;
		answer.pos = max.pos;
		int cnt=0;
		bool flag = true;
		for(int i=length-1; i>=0; i--){
			if(!(ans[i] == 0 && flag)){
				cnt++;
				flag = false;
			}
		}
		answer.n = cnt;
		answer.val = new int[cnt];
		for(int i=cnt-1, j=0; i>=0; i--,j++){
			answer.val[j] = ans[i];
		}
		delete [] ans;
		return answer;
    }
	else{
		int * t =  reverse();
        int * k = r.reverse();
		
        int length = (n>r.n)? n:r.n;
        int add_val = 0, curr1, curr2;
        int * ans = new int[length+1];
        for (int i = 0; i < length; i++)
        {
            curr1 = (i<n)?t[i]:0;
			curr2 = (i<r.n)?k[i]:0;
            ans[i] = (curr1+curr2+add_val)%10;
            add_val = (curr1+curr2+add_val)/10;
        }
        if(add_val) ans[length] = add_val;
		else ans[length] = 0;
		BigInteger answer;
		answer.pos = pos;
		
		int cnt;
		if(add_val){
			cnt = length+1;
		}
		else cnt = length;
		answer.n = cnt;
		answer.val = new int[cnt];
		for(int i=cnt-1, j=0; i>=0; i--,j++){
			answer.val[j] = ans[i];
		}
		delete [] ans;
		return answer;
	}

    return BigInteger(0);
}

bool BigInteger::operator >(const BigInteger & r)const{
    if(pos != r.pos){
         return pos;
    }
    else{
        if(n>r.n) return true;
        else if(n<r.n) return false;
        else{
            for (int i = 0; i < n; i++)
            {
                if(val[i]>r.val[i]) return true;
            }
        }
    }
    return false;
}

bool BigInteger::operator <(const BigInteger & r)const{
    return !(*this>r);
}

bool BigInteger::abs_max(const BigInteger & r)const{
	if(n>r.n) return true;
    else if(n<r.n) return false;
    else{
        for (int i = 0; i < n; i++)
        {
            if(val[i]>r.val[i]) return true;
        }
    }
	return false;
}

int BigInteger::getN()const{
    return n;
}

void BigInteger::setN(int length){
    n = length;
}

int * BigInteger::reverse() const{
    int * r = new int[n];
    int ind=0;
    for(int i=n-1; i>=0; i--){
        r[ind] = val[i];
        ind++;
    }
    return r;
}

std::ostream& operator << (std::ostream& out, const BigInteger & r){
    if(!r.pos) out << "-";
    for (int i = 0; i < r.n; i++)
    {
        out<<r.val[i];
    }
    return out;
}