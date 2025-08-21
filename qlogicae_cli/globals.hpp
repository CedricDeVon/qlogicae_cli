#pragma once

#include "pch.hpp"

namespace QLogicaeCLI
{
    static QLogicaeCore::Logger timestamp_logger;
    static QLogicaeCore::TextFileIO text_file_io;
    static QLogicaeCore::AES256CipherCryptographer cryptographer_2;
    static QLogicaeCore::Argon2idHashCryptographer cryptographer_3;
    static QLogicaeCore::AES256SignatureCryptographer cryptographer_4;
    static QLogicaeCore::XChaCha20Poly1305CipherCryptographer cryptographer_1;
    
    static std::filesystem::path application_directory =
        QLogicaeCore::SYSTEM_ACCESS.get_executable_dir();
    static std::filesystem::path public_file_name =
        "qlogicae.public.json";
    static std::filesystem::path gitignore_file_name =
        "qlogicae.gitignore";
    static std::filesystem::path private_file_name =
        "qlogicae.private.json";
    static std::filesystem::path utilities_file_name =
        "qlogicae.utilities.json";
    static std::filesystem::path license_file_name =
        "LICENSE.txt";
    static std::filesystem::path icon_file_name =
        "qlogicae.application.ico";
    static std::filesystem::path inno_run_file_name =
        "qlogicae.inno_run.ps1";
    static std::filesystem::path inno_setup_file_name =
        "qlogicae.inno_setup.iss";
    static std::filesystem::path inno_run_target_file_name =
        "qlogicae.inno_run.target.ps1";
    static std::filesystem::path inno_setup_target_file_name =
        "qlogicae.inno_setup.target.iss";

    static std::filesystem::path assets_folder_name =
        "assets";
    static std::filesystem::path templates_folder_name =
        "templates";
    static std::filesystem::path temporary_folder_name =
        "temporary";
    static std::filesystem::path scripts_folder_name =
        "scripts";
    static std::filesystem::path configurations_folder_name =
        "configurations";

    static std::string public_file_name_string =
        "qlogicae.public.json";
    static std::string gitignore_file_name_string =
        "qlogicae.gitignore";
    static std::string private_file_name_string =
        "qlogicae.private.json";
    static std::string utilities_file_name_string =
        "qlogicae.utilities.json";
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
    static std::string scripts_folder_name_string =
        "scripts";
    static std::string configurations_folder_name_string =
        "configurations";

    static std::string assets_folder_path =
        "/" + assets_folder_name_string;
    static std::string scripts_folder_path =
        "/" + scripts_folder_name_string;
    static std::string configurations_folder_path =
        "/" + configurations_folder_name_string;
    static std::string assets_icon_file_path =
        "/" + assets_folder_name_string +
        "/" + icon_file_name_string;
    static std::string scripts_inno_run_file_path =
        "/" + scripts_folder_name_string +
        "/" + inno_run_file_name_string;
    static std::string scripts_inno_setup_file_path =
        "/" + scripts_folder_name_string +
        "/" + inno_setup_file_name_string;
    static std::string configurations_public_file_path =
        "/" + configurations_folder_name_string +
        "/" + public_file_name_string;
    static std::string configurations_utilities_file_path =
        "/" + configurations_folder_name_string +
        "/" + utilities_file_name_string;
    static std::string private_file_path =
        "/" + private_file_name_string;
    static std::string license_file_path =
        "/" + license_file_name_string;
    static std::string gitignore_file_path =
        "/" + gitignore_file_name_string;


    static std::filesystem::path application_public_file_path =
        application_directory /
        configurations_folder_name /
        public_file_name;
    static std::filesystem::path application_utilities_file_path =
        application_directory /
        configurations_folder_name /
        utilities_file_name;
    static QLogicaeCore::TextFileIO client_inno_run_file;
    static QLogicaeCore::TextFileIO client_inno_setup_file;
    static QLogicaeCore::TextFileIO client_inno_run_target_file;
    static QLogicaeCore::TextFileIO client_inno_setup_target_file;

    static QLogicaeCore::JsonFileIO client_public_file;
    static QLogicaeCore::JsonFileIO client_private_file;
    static QLogicaeCore::JsonFileIO client_utilities_file;
    static QLogicaeCore::JsonFileIO application_public_file(
        application_public_file_path.string()
    );
    static QLogicaeCore::JsonFileIO application_utilities_file(
        application_utilities_file_path.string()
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

    static std::string utilities_environment_selected =
        application_utilities_file.get_string({ "environment", "selected" });
    static std::vector<std::string> utilities_environment_types
        { "development", "debug", "test", "release" };
    static std::vector<std::string> utilities_environment_types_options
        { "development", "debug", "test", "release", "all"};
    static std::vector<std::string> utilities_setup_template_types
        { "default", "custom" };

    static std::string application_full_name =
        application_name + " " + "(" + application_version + ")";
}
