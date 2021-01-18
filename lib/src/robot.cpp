#include "robot.h"
#include "utils/utils.h"
using namespace rapidjson;

Robot::Robot(/* args */) : m_errorCode(0), m_error("")
{
    Point point(0, 0);
    m_points.push_back(point);
}

Robot::~Robot()
{
}

bool Robot::parse(const char *data)
{
    Document doc;
    if (!doc.Parse(data).HasParseError())
    {
        handleJson(doc);
        return true;
    }
    else
    {
        m_errorCode = 1;
        m_error = "Parse Error!";
        return false;
    }
}

void Robot::handleJson(Document &doc)
{
    auto cmd = getStringValue(doc, "cmd");
    switch (str2int(cmd.c_str()))
    {
    case str2int("distance"):
    {
        int angle = getIntValue(doc, "angle");
        int distance = getIntValue(doc, "distance");
        break;
    }
    default:
        m_errorCode = 2;
        m_error = "unknow command";
        break;
    }
}