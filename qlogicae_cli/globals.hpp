#pragma once

#include "pch.hpp"

namespace QLogicaeCLI
{
    static std::filesystem::path application_directory = QLogicaeCore::SystemAccess::get_instance().get_executable_dir();
    static std::filesystem::path public_file_name = "qlogicae.public.json";
    static std::filesystem::path gitignore_file_name = "qlogicae.gitignore";
    static std::filesystem::path private_file_name = "qlogicae.private.json";
    static std::filesystem::path utilities_file_name = "qlogicae.utilities.json";
    static std::filesystem::path license_file_name = "LICENSE.txt";
    static std::filesystem::path icon_file_name = "icon.ico";
    static std::filesystem::path inno_run_file_name = "qlogicae.inno_run.ps1";
    static std::filesystem::path inno_setup_file_name = "qlogicae.inno_setup.iss";
    static std::filesystem::path inno_run_target_file_name = "qlogicae.inno_run.target.ps1";
    static std::filesystem::path inno_setup_target_file_name = "qlogicae.inno_setup.target.iss";

    static std::filesystem::path assets_folder_name = "assets";
    static std::filesystem::path templates_folder_name = "templates";
    static std::filesystem::path temporary_folder_name = "temporary";
    static std::filesystem::path scripts_folder_name = "scripts";
    static std::filesystem::path configurations_folder_name = "configurations";

    static std::filesystem::path application_public_file_path = QLogicaeCLI::application_directory / QLogicaeCLI::configurations_folder_name / QLogicaeCLI::public_file_name;
    static std::filesystem::path application_utilities_file_path = QLogicaeCLI::application_directory / QLogicaeCLI::configurations_folder_name / QLogicaeCLI::utilities_file_name;

    static QLogicaeCore::XChaCha20Poly1305CipherCryptographer cryptographer_1;
    static QLogicaeCore::AES256CipherCryptographer cryptographer_2;
    static QLogicaeCore::Argon2idHashCryptographer cryptographer_3;
    static QLogicaeCore::AES256SignatureCryptographer cryptographer_4;

    static QLogicaeCore::Logger timestamp_logger;
    static QLogicaeCore::CliIO& raw_logger = QLogicaeCore::CliIO::get_instance();
    static QLogicaeCore::Generator& generator = QLogicaeCore::Generator::get_instance();

    static QLogicaeCore::TextFileIO client_inno_run_file;
    static QLogicaeCore::TextFileIO client_inno_setup_file;
    static QLogicaeCore::TextFileIO client_inno_run_target_file;
    static QLogicaeCore::TextFileIO client_inno_setup_target_file;

    static QLogicaeCore::JsonFileIO client_public_file;
    static QLogicaeCore::JsonFileIO client_private_file;
    static QLogicaeCore::JsonFileIO client_utilities_file;
    static QLogicaeCore::JsonFileIO application_public_file(QLogicaeCLI::application_public_file_path.string());
    static QLogicaeCore::JsonFileIO application_utilities_file(QLogicaeCLI::application_utilities_file_path.string());

    static std::string application_id = QLogicaeCLI::application_public_file.get_string({ "application", "id" });
    static std::string application_name = QLogicaeCLI::application_public_file.get_string({ "application", "name" });
    static std::string application_version = QLogicaeCLI::application_public_file.get_string({ "application", "version" });
    static std::string application_company = QLogicaeCLI::application_public_file.get_string({ "application", "company" });
    static std::string application_authors = QLogicaeCLI::application_public_file.get_string({ "application", "authors" });
    static std::string application_description = QLogicaeCLI::application_public_file.get_string({ "application", "description" });

    static std::string utilities_environment_selected = QLogicaeCLI::application_utilities_file.get_string({ "environment", "selected" });
    static std::vector<std::string> utilities_environment_types { "development", "debug", "test", "release" };
    static std::vector<std::string> utilities_environment_types_options { "development", "debug", "test", "release", "all"};
    static std::vector<std::string> utilities_setup_template_types { "default", "custom" };

    static std::string application_full_name = fmt::format("{} ({})",
        application_name, application_version
    );
}
