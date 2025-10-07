#pragma once

enum class LogType
{
    MESSAGE,
    WARNING,
    FATAL_ERROR
};

void log_data(const char* message, LogType lt);
