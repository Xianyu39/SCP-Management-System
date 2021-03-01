#ifndef ACLASS_H_
#define ACLASS_H_
#include "Personnel.h"
class AClass :
    public Personnel
{
public:
    AClass(const string& ID, const string& name, const string& password)
        :Personnel(ID,name,Level::A,password)
    {}
    virtual void change_name(const string& new_name) { name = new_name; }
    virtual void change_password(const string& new_password) { password = new_password; }
};

#endif//!ACLASS_H_