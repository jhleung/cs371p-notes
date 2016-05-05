class A;
class B {
    public: 
        B(){};
        void fn(A& a){
            //...
        };
};

class A{
    B b;
    public:
        A(){};
        void test(){
            b.fn(*this);
        };
};


int main() {
    A a;
    a.test();
};
