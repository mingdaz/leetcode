#include<iostream>
using namespace std;

//create card struct 
struct card{
    int val; //origin index
    int r;   //period when the card first go back to its place
    card* next;  // pointer to next card
    card(int x): val(x),r(-1),next(NULL){}
};

//create a deck struct basically it is a queue
class deck{
public:
    deck():head(NULL),tail(NULL){}
    
    /* add card to the end */
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


    /* add card to the front */
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

    /* pop the front card */
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

    /* check if the deck is empty or not*/
    bool empty(){ return head==NULL;}

    /* check if the deck is in origin order or each card has period 
     * the parameter cnt is the current shuffle times.
     * set allperiod and ordered flag
     * */
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

    /* return allperiod flag */
    bool isAllperiod(int cnt){
        if(!check) docheck(cnt);
        return allperiod; 
    }

    /* return is order flag */
    bool isOrdered(int cnt){
        if(!check) docheck(cnt);
        return ordered;
    }

    /* return lowest common multuply */
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

    /* print alll card in deck */
    void print(){
        card* temp = head;
        while(temp!=NULL){
            cout<<"("<<temp->val<<","<<temp->r<<"),";
            temp = temp->next;
        }
        cout<<endl;
    }
private:
    /* calculate lowest common multiply of two number */
    int lcm(int a, int b){
        return a*(b/gcd(a,b));
    }
    
    /* calculate greatest common dividor */
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

/* simulate the game */
class Simulator{
public:
    /* create deck */
Simulator(int x):n(x),cnt(0){
    if(n<=0) return;
    A = new deck();
    for(int i=0;i<n;i++){
        card* t = new card(i);
        A->push(t);
    }
}

/* do one time shuffle */
void shuffle(){
    deck* B = new deck();
    while(!A->empty()){
        /* based on my understanding, after all the cards are on the table
         * I will collection those card from bottom to front.
         * hince each time I push card to the front of new deck.
         * */
        B->push_front(A->pop());
        if(A->empty()) break;
        A->push(A->pop());
    }
    delete A;
    A = B;
    cnt ++;
    A->docheck(cnt);
}

/* solve problem */
int solve(){
    do{
        shuffle();
      //  print();
    }while(!A->isOrdered(cnt)&&!A->isAllperiod(cnt));
    /* if already ordered return cnt */
    if(A->isOrdered(cnt)) return cnt;
    /* if all have period return lcm */
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
    int n=0;
    while(n<=0){
    cout<<"please enter n(>0):";
    cin>>n;
    }
    Simulator game = Simulator(n);
    cout<<"number of shuffle times:"<<game.solve()<<endl;
    return 0;
}



