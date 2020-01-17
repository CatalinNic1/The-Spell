#pragma once

#include <unordered_map>
#include <vector>

namespace JSON
{
    class Object
    {
    private:
        //
        const std::string Type;
        //
        void* Value;
        //
        std::unordered_map< const std::string&, Object > Values;
        ///
        ///
        ///
        const int CastToInt(Object& Obj);
        ///
        ///
        ///
        const float CastToFloat(Object& Obj);
        ///
        ///
        ///
        const bool CastToBool(Object& Obj);
        ///
        ///
        ///
        const std::string& CastToString(Object& Obj);
        ///
        ///
        ///
        const Object& CastToObject(Object& Obj);
        ///
        ///
        ///
        std::nullptr_t CastToNull(Object& Obj);
        ///
        ///
        ///
        template< typename Value >
        std::vector< Value >& CastToArray(Object& Obj);
    public:
        ///
        ///
        ///
        template< typename Value >
        const Value& operator[](const std::string& Key);
        ///
        ///
        ///
        template< typename T >
        void add(const std::string& Key, T&& Value);
    };
}
