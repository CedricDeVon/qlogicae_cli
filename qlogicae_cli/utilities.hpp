#pragma once

#include "qlogicae_core.hpp"

namespace QLogicaeCLI
{
    class Utilities
    {
    public:        
        const QLogicaeCore::Logger TIMESTAMP_LOGGER;

        const QLogicaeCore::XChaCha20Poly1305CipherCryptographer CRYPTOGRAPHER_1;
        
        const QLogicaeCore::Argon2idHashCryptographer CRYPTOGRAPHER_3;

        const QLogicaeCore::AES256CipherCryptographer CRYPTOGRAPHER_2;
        
        const QLogicaeCore::SHA256HashCryptographer CRYPTOGRAPHER_4;
        
        QLogicaeCore::TextFileIO TEXT_FILE_IO;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_RUN_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_RUN_TARGET_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_TARGET_FILE;

        QLogicaeCore::JsonFileIO CLIENT_QLOGICAE_FILE;

        QLogicaeCore::JsonFileIO CLIENT_DOT_QLOGICAE_APPLICATION_CONFIGURATION_FILE;

        const std::string QLOGICAE_APPLICATION_FOLDER_PATH =
            QLogicaeCore::SYSTEM_ACCESS.get_executable_dir();

        const std::string RELATIVE_DOT_QLOGICAE_FOLDER_PATH =
            ".qlogicae";

        const std::string RELATIVE_QLOGICAE_FOLDER_PATH =
            "qlogicae";

        const std::string RELATIVE_APPLICATION_FOLDER_PATH =
            "application";

        const std::string RELATIVE_CONFIGURATIONS_FOLDER_PATH =
            "configurations";

        const std::string RELATIVE_ENVIRONMENT_VARIABLES_FOLDER_PATH =
            "environment_variables";

        const std::string RELATIVE_SYSTEM_FOLDER_PATH =
            "system";

        const std::string RELATIVE_USER_FOLDER_PATH =
            "user";

        const std::string RELATIVE_INNO_SETUP_FOLDER_PATH =
            "inno_setup";

        const std::string RELATIVE_SCRIPTS_FOLDER_PATH =
            "scripts";

        const std::string RELATIVE_TEMPLATES_FOLDER_PATH =
            "templates";

        const std::string RELATIVE_VISUAL_STUDIO_2022_PATH =
            "visual_studio_2022";

        const std::string RELATIVE_WINDOWS_REGISTRY_FOLDER_PATH =
            "windows_registry";
        
        const std::string RELATIVE_HKCU_FOLDER_PATH =
            "hkcu";

        const std::string RELATIVE_HKLM_FOLDER_PATH =
            "hklm";

        const std::string RELATIVE_QLOGICAE_CLI_FOLDER_PATH =
            "cli";

        const std::string RELATIVE_ASSETS_FOLDER_PATH =
            "assets";

        const std::string RELATIVE_DEFAULT_FOLDER_PATH =
            "default";

        const std::string RELATIVE_DEVELOPMENT_FOLDER_PATH =
            "development";

        const std::string RELATIVE_DEBUG_FOLDER_PATH =
            "debug";

        const std::string RELATIVE_TEST_FOLDER_PATH =
            "test";

        const std::string RELATIVE_RELEASE_FOLDER_PATH =
            "release";

        const std::string RELATIVE_QLOGICAE_FILE_PATH =
            "qlogicae.json";

        const std::string RELATIVE_ENVIRONMENT_FILE_PATH =
            "environment.json";

        const std::string RELATIVE_LICENSE_FILE_PATH =
            "LICENSE.txt";

        const std::string RELATIVE_APPLICATION_ICON_FILE_PATH =
            "application.ico";

        const std::string RELATIVE_INNO_SETUP_RUN_POWERSHELL_FILE_PATH =
            "run.ps1";

        const std::string RELATIVE_INNO_SETUP_FILE_PATH =
            "setup.iss";

        const std::string RELATIVE_INNO_SETUP_TARGET_POWERSHELL_FILE_PATH =
            "target.ps1";

        const std::string RELATIVE_INNO_SETUP_TARGET_FILE_PATH =
            "target.iss";

        const std::string RELATIVE_DEFAULT_OUTPUT_FILE_PATH =
            "output.txt";



        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_FOLDER_PATH =
            RELATIVE_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_DOT_QLOGICAE_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_APPLICATION_FOLDER_PATH;



        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_CONFIGURATIONS_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH +
            "\\" + RELATIVE_QLOGICAE_FILE_PATH;



        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_ENVIRONMENT_VARIABLES_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_ENVIRONMENT_VARIABLES_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_ENVIRONMENT_VARIABLES_SYSTEM_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_ENVIRONMENT_VARIABLES_FOLDER_PATH +
            "\\" + RELATIVE_SYSTEM_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_ENVIRONMENT_VARIABLES_USER_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_ENVIRONMENT_VARIABLES_FOLDER_PATH +
            "\\" + RELATIVE_USER_FOLDER_PATH;



        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_INNO_SETUP_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_INNO_SETUP_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_SCRIPTS_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_SCRIPTS_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_TEMPLATES_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_TEMPLATES_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_VISUAL_STUDIO_2022_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_VISUAL_STUDIO_2022_PATH;



        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_WINDOWS_REGISTRY_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_WINDOWS_REGISTRY_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_WINDOWS_REGISTRY_HKCU_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_HKCU_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_WINDOWS_REGISTRY_HKLM_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_HKLM_FOLDER_PATH;



        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_QLOGICAE_CLI_FOLDER_PATH;







        const std::string RELATIVE_QLOGICAE_APPLICATION_FOLDER_PATH =
            RELATIVE_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_APPLICATION_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_APPLICATION_ASSET_FOLDER_PATH =
            RELATIVE_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_ASSETS_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_APPLICATION_ASSET_APPLICATION_ICON_PATH =
            RELATIVE_QLOGICAE_APPLICATION_ASSET_FOLDER_PATH +
            "\\" + RELATIVE_APPLICATION_ICON_FILE_PATH;



        const std::string RELATIVE_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH =
            RELATIVE_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_CONFIGURATIONS_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH =
            RELATIVE_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH +
            "\\" + RELATIVE_QLOGICAE_FILE_PATH;

        const std::string RELATIVE_QLOGICAE_APPLICATION_CONFIGURATION_ENVIRONMENT_FILE_PATH =
            RELATIVE_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH +
            "\\" + RELATIVE_ENVIRONMENT_FILE_PATH;



        const std::string RELATIVE_DOT_QLOGICAE_APPLICATION_FOLDER_PATH =
            RELATIVE_DOT_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_APPLICATION_FOLDER_PATH;



        QLogicaeCore::JsonFileIO APPLICATION_QLOGICAE_FILE
        {
            QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH
        };

        const std::vector<std::string> VISUAL_STUDIO_2022_BUILD_ARCHITECTURE_TYPES =
        {
            "x64", "x86"
        };

        const std::vector<std::string> VISUAL_STUDIO_2022_BUILD_TYPES =
        {
            "Release", "Debug"
        };

        const std::vector<std::string> IDE_TYPES =
        {
            "vs2022"
        };

        const std::vector<std::string> INSTALLER_TYPES =
        {
            "inno-setup"
        };

        std::string get_application_full_name();

        std::string get_application_about_details();

        bool is_file_or_folder_path_found(const std::string& path);

        bool replace_file_if_found(
            const std::string& folder_path,
            const std::string& file_path
        );

        bool copy_file_or_folder(
            const std::string& from_path,
            const std::string& to_path
        );

        bool remove_file_or_folder_if_found(
            const std::string& path
        );

        bool create_folder_path(
            const std::string& path,
            const bool& is_enabled = true
        );

        std::string setup_result_output_file(
            const std::string& path,
            const std::string& extended_folder_path,
            const std::string& default_file_name,
            const bool& is_enabled = true
        );

        void log_running_timestamp(const bool& is_enabled = true);

        void log_complete_timestamp(const bool& is_enabled = true);

        void log_info_timestamp(
            const std::string& text, const bool& is_enabled = true);

        void log_success_timestamp(
            const std::string& text, const bool& is_enabled = true);

        void log_warning_timestamp(
            const std::string& text, const bool& is_enabled = true);

        void log_exception_timestamp(
            const std::string& text, const bool& is_enabled = true);

        void log_running_timestamp_async(const bool& is_enabled = true);

        void log_complete_timestamp_async(const bool& is_enabled = true);

        void log_info_timestamp_async(
            const std::string& text, const bool& is_enabled = true);

        void log_success_timestamp_async(
            const std::string& text, const bool& is_enabled = true);

        void log_warning_timestamp_async(
            const std::string& text, const bool& is_enabled = true);

        void log_exception_timestamp_async(
            const std::string& text, const bool& is_enabled = true);

        std::string transform_log_running_timestamp(
            const bool& is_enabled = true);

        std::string transform_log_complete_timestamp(
            const bool& is_enabled = true);

        std::string transform_log_info_timestamp(
            const std::string& text = "", const bool& is_enabled = true);

        std::string transform_log_success_timestamp(
            const std::string& text = "", const bool& is_enabled = true);

        std::string transform_log_warning_timestamp(
            const std::string& text = "", const bool& is_enabled = true);

        std::string transform_log_exception_timestamp(
            const std::string& text = "", const bool& is_enabled = true);

        bool is_qlogicae_project_found();

        static Utilities& get_instance();

    protected:
        Utilities();
        ~Utilities() = default;
        Utilities(const Utilities&) = default;
        Utilities(Utilities&&) noexcept = delete;
        Utilities& operator = (Utilities&&) = delete;
        Utilities& operator = (const Utilities&) = delete;

        std::mutex _mutex;
    };

    inline static Utilities& UTILITIES =
        Utilities::get_instance();
}
