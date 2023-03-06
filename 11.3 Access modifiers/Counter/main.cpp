#include <iostream>
class Counter{

public:

    Counter(): c(0), initial(0){

    }

    Counter(double ic): c(ic),initial(ic){

    }
    void inc(){
        c++;
    }
    int get_count() const {
        return c;
    }
    void reset(){
        c=initial;
    }

private:
    int c;
    int initial;

};

int main(){

    Counter c1;
    Counter c2( 73);

    std::cout << c1.get_count() << std::endl;
    std::cout << c2.get_count() << std::endl;

    c1.inc();
    c2.inc();

    // ok because member function inc() is public

    std::cout << c1.get_count() << std::endl;
    std::cout << c2.get_count() << std::endl;


    // this would not compile because the c member data is private
    c1.reset();
    c2.reset();

    std::cout << c1.get_count() << std::endl;
    std::cout << c2.get_count() << std::endl;
}
