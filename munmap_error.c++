class A;
class B {
    private:
        A a;
    public: 
        B(){};
        A fn(A& temp){
            a = temp;
            return a;
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
