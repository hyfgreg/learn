#include <iostream>
#include <vector>

using namespace std;

class num_sequence
{

  public:
    virtual ~num_sequence(){};
    virtual const char *what_am_i() const = 0;
    int elem(int pos) const;
    ostream &print(ostream &os = cout) const;
    int length() const { return _length; };
    int beg_pos() const { return _beg_pos; };
    static int mex_elems() { return 64; };

  protected:
    virtual void gen_elems(int pos) const = 0;
    bool check_integrity(int pos, int size) const;
    // 将抽象基类的构造函数设为protected, 基类就无法实例化，但是派生子类可以调用这个构造函数进行实例化
    num_sequence(int len, int bp, vector<int> &re) : _length(len), _beg_pos(bp), _relems(re){};

    int _length;
    int _beg_pos;
    vector<int> &_relems;
};

class Fibonacci : public num_sequence
{
  public:
    Fibonacci(int len = 1, int beg_pos = 1);
    virtual const char *what_am_i() const { return "Fibnacci"; };

  protected:
    virtual void gen_elems(int pos) const;
    static vector<int> _elems;
};