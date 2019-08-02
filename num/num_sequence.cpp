#include <iostream>

using namespace std;

class num_sequence
{
public:
  virtual ~num_sequence(){};

  virtual int elem(int pos) const = 0;
  virtual const char *what_am_i() const;
  static int max_elems() { return _max_elems; };
  virtual ostream &print(ostream &os = cout) const = 0;

protected:
  virtual void gen_elems(int pos) const = 0;
  bool check_integrity(int pos) const;

  const static int _max_elems = 1024;
};

inline num_sequence::~num_sequence(){};

bool num_sequence::check_integrity(int pos) const
{
  if (pos <= 0 || pos > _max_elems)
  {
    cerr << "!! invalid position: " << pos << " Cannot honor request\n ";
    return false;
  }
  return true;
}

ostream &operator<<(ostream &os, const num_sequence &ns)
{
  return ns.print(os);
}

// class num_sequence
// {
//   public:
//     typedef void (num_sequence::*PtrType)(int);

//     void fibonacci(int);
//     void pell(int);

//     bool check_intergrity(int pos) const;

//     int elem(int pos)
//     {
//         if (!check_intergrity(pos))
//             return 0;

//         if (pos > _elem->size())
//         {
//             (this->*_pmf)(pos);
//         }

//         return (*_elem)[pos - 1];
//     }

//   private:
//     vector<int> *_elem;
//     PtrType _pmf;
//     static const int num_seq = 3;
//     static PtrType func_tbl[num_seq];
//     static vector<vector<int>> seq;
// };

// // const int num_sequence::num_seq;
// vector<vector<int>> num_sequence::seq(num_seq);

// num_sequence::PtrType num_sequence::func_tbl[num_seq] =
//     {
//         0,
//         &num_sequence::fibonacci,
//         &num_sequence::pell};