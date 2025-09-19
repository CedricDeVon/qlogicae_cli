#pragma once

#include "qlogicae_core.hpp"

namespace QLogicaeCLI
{
    class Utilities
    {
    public:        
        const QLogicaeCore::Logger TIMESTAMP_LOGGER;

        const QLogicaeCore::AES256CipherCryptographer CRYPTOGRAPHER_2;

        const QLogicaeCore::Argon2idHashCryptographer CRYPTOGRAPHER_3;

        const QLogicaeCore::AES256SignatureCryptographer CRYPTOGRAPHER_4;

        const QLogicaeCore::XChaCha20Poly1305CipherCryptographer CRYPTOGRAPHER_1;
        
        QLogicaeCore::TextFileIO TEXT_FILE_IO;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_RUN_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_RUN_TARGET_FILE;

        QLogicaeCore::TextFileIO CLIENT_INNO_SETUP_TARGET_FILE;

        QLogicaeCore::JsonFileIO CLIENT_QLOGICAE_FILE;

        QLogicaeCore::JsonFileIO CLIENT_DOT_QLOGICAE_FILE;

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

    /*

    static QLogicaeCore::Constants constants;

    static QLogicaeCore::Logger timestamp_logger;
    
    static QLogicaeCore::TextFileIO text_file_io;
    
    static QLogicaeCore::AES256CipherCryptographer cryptographer_2;

    static QLogicaeCore::Argon2idHashCryptographer cryptographer_3;
    
    static QLogicaeCore::AES256SignatureCryptographer cryptographer_4;
    
    static QLogicaeCore::XChaCha20Poly1305CipherCryptographer cryptographer_1;    

    static std::string application_directory_name_string =
        QLogicaeCore::SYSTEM_ACCESS.get_executable_dir();

    static std::string private_qlogicae_folder_path =
        ".qlogicae";

    static std::string public_qlogicae_folder_path =
        "qlogicae";
    
    static std::string qlogicae_cli_folder_path =
        "\\cli";

    static std::string vs2022_application_name_string =
        "vs2022_application";

    static std::string vs2022_application_path =
        "\\" + vs2022_application_name_string + "\\";

    static std::string public_file_name_string =
        "qlogicae.public.json";

    static std::string gitignore_file_name_string =
        "qlogicae.gitignore";

    static std::string private_file_name_string =
        "qlogicae.private.json";

    static std::string license_file_name_string =
        "LICENSE.txt";

    static std::string icon_file_name_string =
        "qlogicae.application.ico";

    static std::string inno_run_file_name_string =
        "qlogicae.inno_run.ps1";

    static std::string inno_setup_file_name_string =
        "qlogicae.inno_setup.iss";

    static std::string inno_run_target_file_name_string =
        "qlogicae.inno_run.target.ps1";

    static std::string inno_setup_target_file_name_string =
        "qlogicae.inno_setup.target.iss";

    static std::string assets_folder_name_string =
        "assets";

    static std::string templates_folder_name_string =
        "templates";

    static std::string temporary_folder_name_string =
        "temporary";

    static std::string vs2022_folder_name_string =
        "vs2022";

    static std::string application_folder_name_string =
        "application";

    static std::string scripts_folder_name_string =
        "scripts";

    static std::string configurations_folder_name_string =
        "configurations";

    static std::string public_qlogicae_cli_folder_path =
        public_qlogicae_folder_path +
        "\\" + qlogicae_cli_folder_path;

    static std::string private_qlogicae_cli_folder_path =
        private_qlogicae_folder_path +
        "\\" + qlogicae_cli_folder_path;

    static std::string public_qlogicae_configurations_folder_path =
        public_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + configurations_folder_name_string;

    static std::string public_qlogicae_assets_folder_path =
        public_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + assets_folder_name_string;

    static std::string public_qlogicae_scripts_folder_path =
        private_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + scripts_folder_name_string;

    static std::string public_qlogicae_templates_folder_path =
        public_qlogicae_cli_folder_path +
        "\\" + templates_folder_name_string;

    static std::string public_qlogicae_configurations_public_file_path =
        public_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + configurations_folder_name_string +
        "\\" + public_file_name_string;

    static std::string qlogicae_private_file_path =
        private_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + configurations_folder_name_string +
        "\\" + private_file_name_string;

    static std::string qlogicae_license_file_path =
        license_file_name_string;

    static std::string public_qlogicae_scripts_inno_run_file_path =
        private_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + scripts_folder_name_string +
        "\\" + inno_run_file_name_string;

    static std::string public_qlogicae_scripts_inno_setup_file_path =
        private_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + scripts_folder_name_string +
        "\\" + inno_setup_file_name_string;

    static std::string public_qlogicae_scripts_inno_target_file_path =
        private_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + scripts_folder_name_string +
        "\\" + inno_setup_target_file_name_string;

    static std::string public_qlogicae_assets_icon_file_path =
        public_qlogicae_folder_path +
        "\\" + application_folder_name_string +
        "\\" + assets_folder_name_string +
        "\\" + icon_file_name_string;

    static std::string private_file_path =
        "\\" + private_file_name_string;

    static std::string license_file_path =
        "\\" + license_file_name_string;

    static QLogicaeCore::TextFileIO client_inno_run_file;
    
    static QLogicaeCore::TextFileIO client_inno_setup_file;
    
    static QLogicaeCore::TextFileIO client_inno_run_target_file;
    
    static QLogicaeCore::TextFileIO client_inno_setup_target_file;
    
    static QLogicaeCore::JsonFileIO client_public_file;
    
    static QLogicaeCore::JsonFileIO client_private_file;
    
    static QLogicaeCore::JsonFileIO application_public_file(
        application_directory_name_string + "\\" +
        public_qlogicae_configurations_public_file_path
    );
    
    static std::string application_id =
        application_public_file.get_string({ "application", "id" });

    static std::string application_name =
        application_public_file.get_string({ "application", "name" });

    static std::string application_version =
        application_public_file.get_string({ "application", "version" });

    static std::string application_company =
        application_public_file.get_string({ "application", "company" });

    static std::string application_authors =
        application_public_file.get_string({ "application", "authors" });

    static std::string application_description =
        application_public_file.get_string({ "application", "description" });
    
    static std::string application_url =
        application_public_file.get_string({ "application", "url" });

    static std::string application_architecture =
        application_public_file.get_string({ "application", "architecture" });

    static std::vector<std::string> application_environment_types
        { "development", "debug", "test", "release" };

    static std::vector<std::string> application_environment_type_options
        { "development", "debug", "test", "release", "all"};

    static std::string execute_inno_run_command =
        "powershell -ExecutionPolicy Bypass -File \".\\";

    static std::string application_full_name =
        application_name + " " + "(" + application_version + ")";

    static std::string about_details =
        application_full_name + "\n\n" +
        "Description:\n" + application_description + "\n\n" +
        "Authors:\n" + application_authors + "\n\n" +
        "Repository:\n" + application_url;
    
    static std::string hklm_registry_path_setup_command =
        "\n[Registry]\nRoot: HKLM; Subkey: \"SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment\"; ValueType: expandsz; ValueName: \"Path\"; ValueData: \"{olddata};{app}\"\n";

    static std::string inno_setup_command =
        execute_inno_run_command +
        public_qlogicae_scripts_inno_run_file_path + "\"";
    */
}

/*


const std::string DOT_QLOGICAE_APPLICATION_FOLDER_PATH =
    DOT_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH;

const std::string DOT_QLOGICAE_APPLICATION_CONFIGURATION_FOLDER_PATH =
    DOT_QLOGICAE_APPLICATION_FOLDER_PATH +
    "\\" + CONFIGURATIONS_FOLDER_PATH;

const std::string PUBLIC_QLOGICAE_CLI_FOLDER_PATH =
    PUBLIC_QLOGICAE_FOLDER_PATH +
    "\\" + QLOGICAE_CLI_FOLDER_PATH;

const std::string PRIVATE_QLOGICAE_CLI_FOLDER_PATH =
    PRIVATE_QLOGICAE_FOLDER_PATH +
    "\\" + QLOGICAE_CLI_FOLDER_PATH;
const std::string PUBLIC_QLOGICAE_CLI_FOLDER_PATH =
    PUBLIC_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + CONFIGURATIONS_FOLDER_PATH;

const std::string public_qlogicae_assets_folder_path =
    PUBLIC_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + ASSETS_FOLDER_PATH;

const std::string public_qlogicae_scripts_folder_path =
    PRIVATE_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + SCRIPTS_FOLDER_PATH;

const std::string public_qlogicae_templates_folder_path =
    public_qlogicae_cli_folder_path +
    "\\" + templates_folder_name_string;

const std::string public_qlogicae_configurations_public_file_path =
    PUBLIC_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + CONFIGURATIONS_FOLDER_PATH +
    "\\" + PUBLIC_QLOGICAE_FILE_PATH;

const std::string qlogicae_private_file_path =
    PRIVATE_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + CONFIGURATIONS_FOLDER_PATH +
    "\\" + PRIVATE_QLOGICAE_FILE_PATH;

const std::string qlogicae_license_file_path =
    license_file_name_string;

const std::string public_qlogicae_scripts_inno_run_file_path =
    PRIVATE_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + SCRIPTS_FOLDER_PATH +
    "\\" + inno_run_file_name_string;

const std::string public_qlogicae_scripts_inno_setup_file_path =
    PRIVATE_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + SCRIPTS_FOLDER_PATH +
    "\\" + inno_setup_file_name_string;

const std::string public_qlogicae_scripts_inno_target_file_path =
    PRIVATE_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + SCRIPTS_FOLDER_PATH +
    "\\" + inno_setup_target_file_name_string;

const std::string public_qlogicae_assets_icon_file_path =
    PUBLIC_QLOGICAE_FOLDER_PATH +
    "\\" + APPLICATION_FOLDER_PATH +
    "\\" + assets_folder_name_string +
    "\\" + icon_file_name_string;

const std::string private_file_path =
    "\\" + private_file_name_string;

const std::string license_file_path =
    "\\" + license_file_name_string;
*/
