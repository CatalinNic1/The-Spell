#pragma once

#include <unordered_map>
#include <vector>

#include "../Core/Core.hpp"

namespace JSON
{
    class Object
    {
    private:
        //
        std::string Type = "none";
        //
        void* Value = nullptr;
        //
        std::unordered_map< std::string, Object > Values;
        ///
        ///
        ///
        const int CastToInt(JSON::Object& Obj);
        ///
        ///
        ///
        const float CastToFloat(JSON::Object& Obj);
        ///
        ///
        ///
        const bool CastToBool(JSON::Object& Obj);
        ///
        ///
        ///
        const std::string& CastToString(JSON::Object& Obj);
        ///
        ///
        ///
        const JSON::Object& CastToObject(JSON::Object& Obj);
        ///
        ///
        ///
        std::nullptr_t CastToNull(JSON::Object& Obj);
        ///
        ///
        ///
        template< typename Value >
        std::vector< Value >& CastToArray(JSON::Object& Obj);
    public:
        ///
        ///
        ///
        template< typename Value >
        const Value& operator[](const std::string& Key);
        ///
        ///
        ///
        void add(const std::string& Key, const JSON::Core::Stream& Stream);
        ///
        ///
        ///
    };
}
