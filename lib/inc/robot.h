// #pragma once
#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "rapidjson/document.h"
#include "point.h"

class Robot
{
public:
    Robot(/* args */);
    ~Robot();
    bool parse(const char *data);

private:
    int m_errorCode;
    std::string m_error;
    std::vector<Point> m_points;
    std::shared_ptr<Point> m_robot_pos;
    void handleJson(rapidjson::Document &doc);
};
