#include "utils.h"
std::string getStringValue(Document &doc, const char *key)
{
    if (doc.HasMember(key) && doc[key].IsString())
    {
        return doc[key].GetString();
    }
    return "";
}

int getIntValue(Document &doc, const char *key)
{
    if (doc.HasMember(key) && doc[key].IsInt())
    {
        return doc[key].GetInt();
    }
    return 0;
}
