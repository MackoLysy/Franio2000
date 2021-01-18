// #pragma once
#include <string>
#include <iostream>
#include <vector>

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

    void handleJson(rapidjson::Document &doc);
};
