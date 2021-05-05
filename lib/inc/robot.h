// #pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "rapidjson/document.h"
#include "pathHandler.h"
#include "point.h"

class Robot
{
public:
    Robot();
    ~Robot();
    bool parse(const char *data);

private:
    int m_errorCode;
    std::string m_error;
    std::vector<Point> m_points;
    std::shared_ptr<Point> m_robot_pos;
    Point m_target;
    std::shared_ptr<PathHandler> m_pathHandler;

    int m_rotation;
    void handleJson(rapidjson::Document &doc);
};
