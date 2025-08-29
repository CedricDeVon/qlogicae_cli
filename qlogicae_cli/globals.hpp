#pragma once

#include "pch.hpp"

namespace QLogicaeCLI
{
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
        qlogicae_cli_folder_path;

    static std::string private_qlogicae_cli_folder_path =
        private_qlogicae_folder_path +
        qlogicae_cli_folder_path;

    static std::string public_qlogicae_configurations_folder_path =
        public_qlogicae_cli_folder_path +
        configurations_folder_name_string;

    static std::string public_qlogicae_assets_folder_path =
        public_qlogicae_folder_path +
        "\\" + assets_folder_name_string;

    static std::string public_qlogicae_scripts_folder_path =
        public_qlogicae_folder_path +
        "\\" + scripts_folder_name_string;

    static std::string public_qlogicae_templates_folder_path =
        public_qlogicae_folder_path +
        "\\" + templates_folder_name_string;

    static std::string public_qlogicae_configurations_public_file_path =
        public_qlogicae_folder_path +
        "\\" + configurations_folder_name_string +
        "\\" + public_file_name_string;

    static std::string qlogicae_private_file_path =
        private_qlogicae_folder_path +
        "\\" + configurations_folder_name_string +
        "\\" + private_file_name_string;

    static std::string qlogicae_license_file_path =
        license_file_name_string;

    static std::string public_qlogicae_scripts_inno_run_file_path =
        public_qlogicae_folder_path +
        "\\" + scripts_folder_name_string +
        "\\" + inno_run_file_name_string;

    static std::string public_qlogicae_scripts_inno_setup_file_path =
        public_qlogicae_folder_path +
        "\\" + scripts_folder_name_string +
        "\\" + inno_setup_file_name_string;

    static std::string public_qlogicae_scripts_inno_target_file_path =
        public_qlogicae_folder_path +
        "\\" + scripts_folder_name_string +
        "\\" + inno_setup_target_file_name_string;

    static std::string public_qlogicae_assets_icon_file_path =
        public_qlogicae_folder_path +
        "\\" + assets_folder_name_string +
        "\\" + icon_file_name_string;

    static std::string private_file_path =
        "\\" + private_file_name_string;

    static std::string license_file_path =
        "\\" + license_file_name_string;

    static std::string gitignore_file_path =
        "\\" + gitignore_file_name_string;

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

    static QLogicaeCore::JsonFileIO application_private_file(
        application_directory_name_string + "\\" +
        qlogicae_private_file_path
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

    static std::string utilities_environment_selected =
        application_private_file.get_string({ "environment", "selected" });

    static std::vector<std::string> utilities_environment_types
        { "development", "debug", "test", "release" };

    static std::vector<std::string> utilities_environment_types_options
        { "development", "debug", "test", "release", "all"};

    static std::vector<std::string> utilities_setup_template_types
        { "default", "custom" };

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

}
