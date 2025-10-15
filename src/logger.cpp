#include "project/logger.hpp"

#include <quill/Logger.h>
#include <quill/Backend.h>
#include <quill/Frontend.h>
#include <quill/LogMacros.h>
#include <quill/sinks/ConsoleSink.h>
#include <quill/sinks/FileSink.h>

#include <filesystem>

auto get_logger() -> const quill::Logger*
{
    static auto* const logger = []() -> quill::Logger*
    {
        quill::Backend::start();
        auto console_sink = quill::Frontend::create_or_get_sink<quill::ConsoleSink>("sink_id_1");

        std::filesystem::create_directories("artifacts/logs");
        quill::FileSinkConfig cfg;
        cfg.set_open_mode('w');
        cfg.set_filename_append_option(quill::FilenameAppendOption::StartDateTime);
        auto file_sink = quill::Frontend::create_or_get_sink<quill::FileSink>(
            "artifacts/logs/app.log", cfg, quill::FileEventNotifier{});

        quill::PatternFormatterOptions formater{
            "%(time) [%(thread_id)] %(short_source_location:<28) LOG_%(log_level:<9) %(logger:<12) %(message)",
            "%H:%M:%S.%Qns", quill::Timezone::GmtTime
        };

        quill::Logger* l = quill::Frontend::create_or_get_logger(
            "root",
            {std::move(console_sink), std::move(file_sink)},
            formater);

        LOG_INFO(l, "Logger initialized once.");
        return l;
    }();
    return logger;
}