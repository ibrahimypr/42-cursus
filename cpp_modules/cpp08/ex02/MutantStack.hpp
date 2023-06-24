#pragma once
#include <stack>
#include <deque>

// kapsayıcının herhangi bir yineleyicisini ortaya çıkarır.
template <typename T>
class MutantStack : public std::stack<T, std::deque<T> > {
    public:
        MutantStack() {};
        MutantStack(MutantStack const & other):std::stack<T>(other) {};
        ~MutantStack() {
            this->c.clear();
        };

        typedef typename std::stack<T>::container_type::iterator iterator;

        iterator begin() { return this->c.begin(); }
        iterator end() { return this->c.end(); }
};

/*
The std::stack'
kapsayıcı nesnesi (korunan) veri üyesine karşılık gelir c
Deque, elemanların ortasına, sonuna ve başlangıcına eklenmesine ve silinmesine izin veren bir veri yapısı türüdür. 
Vektör, sonun ortasındaki yöntemi kullanarak Veri yapısı içindeki öğelerin eklenmesine ve silinmesine izin veren bir veri yapısı türüdür.
*/