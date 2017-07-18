#include<iostream>
#include<queue>
using namespace std;
struct card{
    int val;
    int r;
    card* next;
    card(int x): val(x),r(-1),next(NULL){}
};

class deck{
public:
    deck():head(NULL),tail(NULL){}
    void push(card* t){
        check = false;
        if(head==NULL){
            head=t;
            tail=t;
        }
        else{
            tail->next = t;
            tail = tail->next;
        }
    }
    void push_front(card* t){
        check = false;
        if(head==NULL){
            head=t;
            tail=t;
        }
        else{
            t->next = head;
            head = t;
        }
    }
    card* pop(){
        check = false;
        if(head==NULL) return NULL;
        else{
            card* res = head;
            head = head->next;
            if(head==NULL) tail = NULL;
            res->next = NULL;
            return res;
        }
    }
    bool empty(){ return head==NULL;}
    void docheck(int cnt){ 
        card* temp = head;
        int ind = 0;
        allperiod = true;
        ordered = true;
        while(temp!=NULL){
            if(temp->val==ind){ 
                if(temp->r==-1)
                    temp->r = cnt;
            }
            else {
                ordered = false;
            }
            if(temp->r==-1) allperiod=false;
            temp = temp->next;
            ind ++;
        }
        check = true;
    }
    bool isAllperiod(int cnt){
        if(!check) docheck(cnt);
        return allperiod; 
    }
    bool isOrdered(int cnt){
        if(!check) docheck(cnt);
        return ordered;
    }
    int getallLCM(){
        if(head==NULL||!allperiod) return 0;
        card* temp = head;
        int res = 1;
        while(temp){
            res = lcm(res,temp->r);
            temp = temp->next;
        }
        return res;
    }
    void print(){
        card* temp = head;
        while(temp!=NULL){
            cout<<"("<<temp->val<<","<<temp->r<<"),";
            temp = temp->next;
        }
        cout<<endl;
    }
private:
    int lcm(int a, int b){
        return a*(b/gcd(a,b));
    }
    
    int gcd(int a,int b){
        if(a<b) return gcd(b,a);
        while(b){
            int r = a%b;
            a = b;
            b = r;
        }
        return a;
    }

    bool check;
    bool allperiod;
    bool ordered;
    card* head;
    card* tail;
};


class Simulator{
public:
Simulator(int x):n(x),cnt(0){
    if(n<=0) return;
    A = new deck();
    for(int i=0;i<n;i++){
        card* t = new card(i);
        A->push(t);
    }
}

void shuffle(){
    deck* B = new deck();
    while(!A->empty()){
        B->push_front(A->pop());
        if(A->empty()) break;
        A->push(A->pop());

    }
    delete A;
    A = B;
    cnt ++;
    A->docheck(cnt);
}

int solve(){
    do{
        shuffle();
      //  print();
    }while(!A->isOrdered(cnt)&&!A->isAllperiod(cnt));
    if(A->isOrdered(cnt)) return cnt;
    return A->getallLCM(); 
}

void print(){
    A->print();
}

private:
    int n;
    int cnt;
    deck* A;
};

int main(){
    int n;
    cin>>n;
    Simulator game = Simulator(n);
    cout<<game.solve()<<endl;
    return 0;
}



