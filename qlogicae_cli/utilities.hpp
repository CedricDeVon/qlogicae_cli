#pragma once

namespace QLogicaeCLI
{
    class Utilities
    {
    public:        
        QLogicaeCore::XChaCha20Poly1305CipherCryptographer CRYPTOGRAPHER_1;
        
        QLogicaeCore::Argon2idHashCryptographer CRYPTOGRAPHER_3;

        QLogicaeCore::AES256CipherCryptographer CRYPTOGRAPHER_2;
        
        QLogicaeCore::SHA256HashCryptographer CRYPTOGRAPHER_4;
        
        QLogicaeCore::TextFileIO TEXT_FILE_IO;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_RUN_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_RUN_TARGET_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_TARGET_FILE;

        QLogicaeCore::JsonFileIO CLIENT_JSON_IO;

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

        const std::string RELATIVE_CLI_FOLDER_PATH =
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

        const std::string RELATIVE_BUILD_FOLDER_PATH =
            "build";
        
        const std::string RELATIVE_SETUP_FOLDER_PATH =
            "setup";

        const std::string RELATIVE_VS2022_FOLDER_PATH =
            "vs2022";

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

        const std::string RELATIVE_BUILD_QLOGICAE_FOLDER_PATH =
            RELATIVE_BUILD_FOLDER_PATH +
            "\\" + RELATIVE_QLOGICAE_FOLDER_PATH;

        const std::string RELATIVE_BUILD_QLOGICAE_APPLICATION_FOLDER_PATH =
            RELATIVE_BUILD_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_APPLICATION_FOLDER_PATH;

        const std::string RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH =
            RELATIVE_BUILD_QLOGICAE_APPLICATION_FOLDER_PATH +
            "\\" + RELATIVE_CONFIGURATIONS_FOLDER_PATH;

        const std::string RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_QLOGICAE_FILE_PATH =
            RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH +
            "\\" + RELATIVE_QLOGICAE_FILE_PATH;

        const std::string RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_ENVIRONMENT_FILE_PATH =
            RELATIVE_BUILD_QLOGICAE_APPLICATION_CONFIGURATIONS_FOLDER_PATH +
            "\\" + RELATIVE_ENVIRONMENT_FILE_PATH;

        const std::string RELATIVE_QLOGICAE_DOT_QLOGICAE_CLI_FOLDER_PATH =
            RELATIVE_QLOGICAE_DOT_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_CLI_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_CLI_FOLDER_PATH =
            RELATIVE_QLOGICAE_FOLDER_PATH +
            "\\" + RELATIVE_CLI_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_CLI_SETUP_FOLDER_PATH =
            RELATIVE_QLOGICAE_CLI_FOLDER_PATH +
            "\\" + RELATIVE_SETUP_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_CLI_SETUP_VS2022_FOLDER_PATH =
            RELATIVE_QLOGICAE_CLI_SETUP_FOLDER_PATH +
            "\\" + RELATIVE_VS2022_FOLDER_PATH;

        const std::string RELATIVE_QLOGICAE_CLI_SETUP_VS2022_APPLICATION_FOLDER_PATH =
            RELATIVE_QLOGICAE_CLI_SETUP_VS2022_FOLDER_PATH +
            "\\" + RELATIVE_APPLICATION_FOLDER_PATH;

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

        const std::vector<std::string> WINDOWS_REGISTRY_ROOT_PATH =
        {
            "hkcu", "hklm"
        };

        const std::vector<std::string> ENVIRONMENT_VARIABLE_TYPES =
        {
            "user", "system"
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

        void setup();

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

/*



*/
