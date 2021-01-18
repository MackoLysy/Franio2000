#include <string>
#include "rapidjson/document.h"
using namespace rapidjson;

std::string getStringValue(Document &doc, const char *key);
int getIntValue(Document &doc, const char *key);
constexpr unsigned int str2int(const char *str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}