#ifndef STRING_VIEW_SPLIT_H
#define STRING_VIEW_SPLIT_H

#include <stddef.h>
#include <string>
#include <string_view>
#include <vector>

/**
 * Splits the given string_view into sub string_views using the given delimiter
 * @param strv std::string_view to split into parts
 * @param delim Delimiter
 * @return On success a vector of string_views is returned, otherwise an empty vector
 */
inline std::vector<std::string_view> string_view_split(const std::string_view& strv, const std::string& delim)
{
    std::vector<std::string_view> result;
    std::string_view strv_cpy(strv);
    size_t pos = strv_cpy.find(delim);
    while( pos != std::string_view::npos )
    {
        if( pos > 0)
        { result.emplace_back(strv_cpy.substr(0, pos)); }
        strv_cpy = strv_cpy.substr(pos + 1);
        pos = strv_cpy.find(delim);
    }
    
    if( !strv_cpy.empty() )
    { result.emplace_back(strv_cpy); }
    
    return result;
}

#endif // STRING_VIEW_SPLIT_H
