#include "MultiSet.h"

MultiSet::MultiSet():n(0), val(NULL){

}

MultiSet::MultiSet(int n):n(n), val(new int[n]){

}

MultiSet::MultiSet(const MultiSet & r){
	n = r.n;
	val = new int[n];
	for(int i=0; i<n; i++){
		val[i] = r.val[i];
	}
}

MultiSet::~MultiSet(){
	if(n) delete[] val;
}

void MultiSet::add_elem(int e){
	n++;
	int * t = new int[n];
	for(int i=0; i<n-1; i++){
		t[i] = val[i];
	}
	t[n-1] = e;
	if(n != 1) delete[] val;
	val = t;
}

void MultiSet::del_elem(int e){
	int cnt = 0;
	for(int i=0; i<n; i++){
		if(val[i] != e) cnt++;
	}
	int * t = new int[cnt];
	int j=0;
	for(int i=0; i<n; i++){
		if(val[i] != e)
			t[j++] = val[i];
	}
	if(n != 0) delete[] val;
	n = cnt;
	val = t;
}

int MultiSet::length() const{
	return n;
}

MultiSet MultiSet::operator/(const MultiSet & r)const{
	MultiSet result;
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<r.n; j++){
            if(val[i]==r.val[j]){
				cnt++; break;
			}
        }
    }
    int * t = new int[cnt];
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<r.n; j++){
            if(val[i]==r.val[j]){
                t[k++] = val[i];
				break;
            }
        }
    }
    result.n = cnt;
    result.val = t;
	return result;
}

MultiSet MultiSet::operator+(const MultiSet & r)const{
	int * sec = new int[n+r.n];
	int ind = 0;
	for(int i=0; i<n; i++){
		sec[ind++] = val[i];
	}
	for(int j=0; j<r.n; j++){
		sec[ind++] = r.val[j];
	}
	MultiSet answer(n+r.n);
	for(int i=0; i<n+r.n; i++){
		answer.val[i] = sec[i];
	}
	delete[] sec;
	return answer;
}

MultiSet MultiSet::operator-(const MultiSet & r)const{
	MultiSet result;
    int cnt = 0;
    bool f = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<r.n; j++){
            if(val[i]==r.val[j]){
                f = true;
                break;
            }
        }
        if(!f) cnt++;
        f = false;
    }
    int * t = new int[cnt];
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<r.n; j++){
            if(val[i]==r.val[j]){
                f = true;
                break;
            }
        }
        if(!f) t[k++] = val[i];
        f = false;
    }
    result.n = cnt;
    result.val = t;

    return result;
}

void MultiSet::set_n(int num){
    n = num;
}

void MultiSet::set_val(int * arr, int size){

}

int* MultiSet::get_val()const{
    return val;
}
std::ostream& operator<<(std::ostream& out, const MultiSet & r){
	out << "{";
    for(int i=0; i<r.n; i++) {
        if(i!=0 && i<r.n)
            out << "\t";
        out << r.val[i];
    }
    out << "}";
	return out;
}
