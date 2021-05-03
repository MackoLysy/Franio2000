#include "robot.h"
#include "utils/utils.h"
using namespace rapidjson;

Robot::Robot() : m_errorCode(0), m_error("")
{
    m_robot_pos = std::make_shared<Point>();
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
    if (cmd == "distance")
    {
        int angle = getIntValue(doc, "angle");
        int distance = getIntValue(doc, "distance");
        Point point(m_robot_pos->getX(), m_robot_pos->getY());
        m_points.push_back(point);
        return;
    }
    m_errorCode = 2;
    m_error = "unknow command";
}