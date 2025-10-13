#include "cpp_sample/logger.hpp"

#include <quill/Logger.h>
#include "quill/Backend.h"
#include "quill/Frontend.h"
#include "quill/LogMacros.h"
#include "quill/sinks/ConsoleSink.h"


auto get_logger() -> const quill::Logger*
{
    static auto *const logger = [] ()-> quill::Logger *
    {
        quill::Backend::start();
        quill::Logger* l = quill::Frontend::create_or_get_logger(
            "root",
            quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1")
        );
        
        LOG_INFO(l, "Logger initialized once.");
        return l;
    }();
    return logger;
}