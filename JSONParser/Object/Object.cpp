#include <typeinfo>
#include <iostream>

#include "Object.hpp"

void JSON::Object::add(const std::string& Key, const JSON::Core::Stream& stream)
{
    Object Obj;
    Values.insert({Key, Obj});
}

const int JSON::Object::CastToInt(JSON::Object& Obj)
{
    return *static_cast< int* >(Obj.Value);
}

const float JSON::Object::CastToFloat(JSON::Object& Obj)
{
    return *static_cast< float* >(Obj.Value);
}

const bool JSON::Object::CastToBool(JSON::Object& Obj)
{
    return *static_cast< bool* >(Obj.Value);
}

const std::string& JSON::Object::CastToString(JSON::Object& Obj)
{
    return *static_cast< std::string* >(Obj.Value);
}

const JSON::Object& JSON::Object::CastToObject(JSON::Object& Obj)
{
    return *static_cast< Object* >(Obj.Value);
}

std::nullptr_t JSON::Object::CastToNull(JSON::Object& Obj)
{
    return *static_cast< std::nullptr_t* >(Obj.Value);
}

template< typename Value >
std::vector< Value >& JSON::Object::CastToArray(JSON::Object& Obj)
{
    return *static_cast< std::vector< Value >* >(Obj.Value);
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