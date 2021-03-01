#ifndef BCLASS_H_
#define BCLASS_H_
#include "Personnel.h"
class BClass :
    public Personnel
{
public:
    BClass(const string& ID, const string& name, const string& password)
        :Personnel(ID, name, Level::A, password)
    {}
    virtual void change_name(const string& new_name) { name = new_name; }
    virtual void change_password(const string& new_password) { password = new_password; }
};

#endif//!BCLASS_H_A