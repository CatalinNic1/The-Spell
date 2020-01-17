#include <typeinfo>
#include <iostream>

#include "Object.hpp"

template< typename T >
void JSON::Object::add(const std::string& Key, T&& Value)
{
    Object Obj;
    
    Obj.Value = static_cast< void* >(&Value);
    Obj.Type = typeid(T).name;
    
    Values.insert({Key, Obj});
}

const int JSON::Object::CastToInt(Object& Obj)
{
    return *static_cast< int* >(Obj.Value);
}

const float JSON::Object::CastToFloat(Object& Obj)
{
    return *static_cast< float* >(Obj.Value);
}

const bool JSON::Object::CastToBool(Object& Obj)
{
    return *static_cast< bool* >(Obj.Value);
}

template< typename Value >
const Value& JSON::Object::operator[](const std::string& Key)
{
    Object Obj = Values[Key];

    if(Obj.Type == "float")
        return CastToFloat(Obj);
    else if(Obj.Type == "int")
        return CastToInt(Obj);
    else if(Obj.Type == "string")
        return CastToString(Obj);
    else if(Obj.Type == "bool")
        return CastToBool(Obj);
    else if(Obj.Type == "null")
        return CastToNull(Obj);
    else if(Obj.Type == "array")
        return CastToArray(Obj);
    else if(Obj.Type == "Object")
        return CastToObject(Obj);
}