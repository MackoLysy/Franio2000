#include "robot.h"
#include "utils/utils.h"
using namespace rapidjson;

Robot::Robot() : m_errorCode(0), m_error(""), m_rotation(0), m_target(0, 0)
{
    m_robot_pos = std::make_shared<Point>();
    m_pathHandler = std::make_shared<PathHandler>(m_robot_pos);
    m_pathHandler->setTarget(m_target);
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
        if (angle == 0)
        {
            m_pathHandler->clear();
        }
        point.calculatePoint(angle, distance);
        m_points.push_back(point);
        m_pathHandler->addPoint(point, angle);
        if (angle == 180)
        {
            m_pathHandler->calculatePath();
        }
        return;
    }
    m_errorCode = 2;
    m_error = "unknow command";
}