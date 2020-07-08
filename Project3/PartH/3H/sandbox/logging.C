#include <logging.h>
#include <string.h>

FILE * Logger::logger = fopen("logger", "wb");

void Logger::LogEvent(const char *event)
{
    fwrite(event, 1, strlen(event), logger);
    fwrite("\n", 1, 1, logger);
}

void Logger::Finalize()
{
    fclose(logger);
}

DataFlowException::DataFlowException(const char *type, const char *error)
{
    sprintf(msg, "Throwing exception: (%s): %s", type, error);
    Logger::LogEvent(msg);
}
