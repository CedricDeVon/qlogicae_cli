#pragma once

#include "qlogicae_core/includes/result.hpp"
#include "qlogicae_core/includes/logger.hpp"
#include "qlogicae_core/includes/transformer.hpp"
#include "qlogicae_core/includes/text_file_io.hpp"
#include "qlogicae_core/includes/json_file_io.hpp"
#include "qlogicae_core/includes/application_utilities.hpp"
#include "qlogicae_core/includes/sha256_hash_cryptographer.hpp"
#include "qlogicae_core/includes/aes256_cipher_cryptographer.hpp"
#include "qlogicae_core/includes/argon2id_hash_cryptographer.hpp"
#include "qlogicae_core/includes/xchacha20_poly1305_cipher_cryptographer.hpp"

#include <CLI/CLI.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>
#include <absl/strings/str_replace.h>

namespace QLogicaeCLI
{
    class Utilities
    {
    public:                       
        std::string RELATIVE_CLI_FOLDER_PATH;

        std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH;

        std::string RELATIVE_QLOGICAE_CLI_SETUP_VS2022_APPLICATION_FOLDER_PATH;

        std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH;

        std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH;

        std::string RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH;

        std::string RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH;

        QLogicaeCore::JsonFileIO APPLICATION_QLOGICAE_FILE;

        CLI::App CLI_APPLICATION;

        std::unordered_map<std::string, std::pair<CLI::App*, std::function<bool()>>> CLI_APPLICATION_COMMANDS;
        
        std::string get_application_full_name();

        std::string get_application_about_details();

        bool setup();

        std::future<bool> setup_async();

        void setup_async(
            QLogicaeCore::Result<std::future<void>>& result
        );

        void setup(
            QLogicaeCore::Result<void>& result
        );

        std::future<bool> setup_async(
            const std::function<void(const bool& result)>& callback
        );

        void setup_async(
            const std::function<void(QLogicaeCore::Result<void>& result)>& callback
        );

        bool terminate();

        std::future<bool> terminate_async();

        void terminate_async(
            QLogicaeCore::Result<std::future<void>>& result
        );

        void terminate(
            QLogicaeCore::Result<void>& result
        );

        std::future<bool> terminate_async(
            const std::function<void(const bool& result)>& callback
        );

        void terminate_async(
            const std::function<void(QLogicaeCore::Result<void>& result)>& callback
        );

        static Utilities& get_instance();

        static void get_instance(
            QLogicaeCore::Result<Utilities*>& result
        );

    protected:
        Utilities();

        ~Utilities();

        Utilities(
            const Utilities& instance
        ) = default;

        Utilities(
            Utilities&& instance
        ) noexcept = delete;

        Utilities& operator = (
            Utilities&& instance
        ) = delete;

        Utilities& operator = (
            const Utilities& instance
        ) = delete;

        std::mutex _mutex;
    };

    inline static Utilities& UTILITIES =
        Utilities::get_instance();
}
