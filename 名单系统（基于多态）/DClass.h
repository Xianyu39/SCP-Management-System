#ifndef DCLASS_H_
#define DCALSS_H_
#include "Personnel.h"
class DClass :
    public Personnel
{
public:
    DClass(const string& ID, const string& name, const string& password)
        :Personnel(ID, name, Level::A, password)
    {}
    virtual void change_name(const string& new_name) { name = new_name; }
    virtual void change_password(const string& new_password) { password = new_password; }
};

#endif//!DCLASS_H_